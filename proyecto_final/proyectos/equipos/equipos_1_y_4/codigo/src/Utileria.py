from math import radians, cos, sin, asin, sqrt
from dynaconf import settings
from io import StringIO

import pandas as pd
import psycopg2
import psycopg2.extras

from pandas import DataFrame, merge
from scipy import stats


class Utileria():
    '''Clase donde se almacenarán las funciones genéricas para la implementación
    de los algoritmos Particle Swarn y Simulated Annealing
    '''

    def calcular_distancia_coord(self, nbr_LongA, nbr_LatA, nbr_LongB, nbr_LatB, str_unidad='km'):
        '''Función para calcular la distancia entre coordenadas en la tierra (esfera)

        Args:
            nbr_LongA: Longitud de las coordenadas del punto A
            nbr_LatA: Latitud de las coordenadas del punto A
            nbr_LongB: Longitud de las coordenadas del punto B
            nbr_LatB: Latitud de las coordenadas del punto B
            str_unidad: Determina las unidades en las que se realizará el cálculo,
                puede ser en kilometros 'km' o millas 'miles'

        Returns:
            nbr_resultado: Devuelve la distancia de acuerdo a la unidad especificada
                (por defecto km)
        '''
        # primero se convierte todo a radianes
        nbr_LongA = radians(nbr_LongA)
        nbr_LatA = radians(nbr_LatA)
        nbr_LongB = radians(nbr_LongB)
        nbr_LatB = radians(nbr_LatB)

        # Aplicamos la fórmula de Haversine
        nbr_delta_lon = nbr_LongB - nbr_LongA
        nbr_delta_lat = nbr_LatB - nbr_LatA
        nbr_a = sin(nbr_delta_lat / 2)**2 + cos(nbr_LatA) * cos(nbr_LatB) * sin(nbr_delta_lon / 2)**2

        nbr_c = 2 * asin(sqrt(nbr_a))

        # Dependiendo del tipo de unidad especificada, sera el valor que usaremos como radio
        # La tierra no es una esfera perfecta, asi que usaremos un radio entre el ecuatorial y el polar
        if str_unidad == 'km':
            nbr_r = 6371
        elif str_unidad == 'miles':
            nbr_r = 3956
        else:
            print('Se especificó una unidad de medición no válida. No es posible realizar el cálculo')
            return 0

        nbr_resultado = nbr_c * nbr_r

        return nbr_resultado



def CrearConexionRDS():
    """Función para crear la conexion con la RDS
    (Asegurate de actualizar el archivo settings.toml)

    Returns:
        conn: Conexión a la RDS
    """

    conn = psycopg2.connect(database=settings.get('dbname'),
                                user=settings.get('user'),
                                password=settings.get('password'),
                                host=settings.get('host'),
                                port='5432')
    return conn



def get_data(query):
    """Función para extraer la información de la base de datos RDS

    Args:
        query: Consulta a la base de datos RDS (Se escribe
        en lenguaje SQL entre comillas)

    Returns:
        df: Un dataframe con la información que se consultó.
    """

    try:
        connection = CrearConexionRDS()
        cursor = connection.cursor()

        cursor.execute(query)

        # print("Selecting rows from table using cursor.fetchall")
        records = cursor.fetchall()
        df = pd.DataFrame(records)
        col_names =  [i[0] for i in cursor.description]
        df.columns = col_names
        cursor.close()
        connection.close()
        # print("PostgreSQL connection is closed")
        return df

    except (Exception, psycopg2.Error) as error :
        print ("Error while fetching data from PostgreSQL", error)



def convert(ruta):
    """Función para convertir una lista a string con las posiciones de la ruta
    separadas por '-'

    Args:
        ruta: Una lista con las posiciones de la ruta

    Returns:
        ruta_c: Un string con las posiciones de la ruta separadas por '-'
    """

    s = [str(i) for i in ruta]
    ruta_c = "-".join(s)
    return(ruta_c)



def ruta(df, fv):
    """Función para obtener el dataframe de la fuerza de ventas para la que
    se calculará la ruta óptima

    Args:
        df: Un dataframe con la información de toda la fuerza de ventas
        fv: Valor único de la fuerza de ventas para la que se desea obtener
            la ruta óptima (Integer)

    Returns:
        df2: Un dataframe con la información de la fuerza de ventas que se
        especificó
    """

    df1 = df[(df.fza_ventas == fv)]
    dfo = df1.filter(['fza_ventas', 'id_origen', 'lat_origen', 'lon_origen'], axis=1).drop_duplicates()
    dfo = dfo.rename({'id_origen': 'id', 'lat_origen': 'lat', 'lon_origen': 'lon'}, axis=1)
    dfd = df1.filter(['fza_ventas', 'no_cliente', 'lat_destino','lon_destino'], axis=1)
    dfd = dfd.rename({'no_cliente': 'id', 'lat_destino': 'lat', 'lon_destino': 'lon'}, axis=1)
    df2 = pd.concat([dfo, dfd])
    df2['posicion'] = 0
    df2['posicion'] = df2.groupby(['posicion']).cumcount()+1
    return df2



def distance_matrix(df, fv):
    """Función para obtener la lista con las distancias de los puntos que tiene
    que recorrer una fuerza de ventas

    Args:
        df: Un dataframe con la información de toda la fuerza de ventas
        fv: Valor único de la fuerza de ventas para la que se desea obtener
            la ruta óptima (Integer)

    Returns:
        df2: Un dataframe con la información necesaria para calcular las
            distancias entre coordenadas
        dm: Una lista con las distancias
    """

    df2 = ruta(df, fv)
    dm = []
    ut = Utileria()
    for i in range(df2.shape[0]):
        for j in range(i+1, df2.shape[0]):
            d = ut.calcular_distancia_coord(df2.iloc[i, 3], df2.iloc[i, 2],  df2.iloc[j, 3], df2.iloc[j, 2])
            elemento = [df2.iloc[i,1], df2.iloc[j,1], d]
            dm.append(elemento)
    return dm, df2


def split_tolist(string):
    """Función para convertir una ruta con las posiciones separadas por
    '-' a lista

    Args:
        string: Un string con las posiciones de la ruta separadas por '-'

    Returns:
        li: Una lista con las posiciones de la ruta
    """

    li = list(string.split("-"))
    return li


def vis_mapa(df, mejor_ruta):
    """Función para preparar los datos para la creación del mapa

    Args:
        df: Un dataframe con la información de la fuerza de ventas para la
        que se calculó la ruta óptima
        mejor_ruta: Una lista con las posiciones de la ruta óptima

    Returns:
        mapi: Una mapa con al ruta óptima
    """

    import folium

    df=df.set_index('posicion')
    df=df.reindex(mejor_ruta)
    coordenadas = df[['lat', 'lon']].values.tolist()
    os = df.loc[[1], ['lat', 'lon']].values.tolist() #Definición de punto: Oficina de servicio
    cen_lon = df.lon.mean()
    cen_lat = df.lat.mean()
    mapi = folium.Map(location=[cen_lat,cen_lon],
                  zoom_start = 12,
                  tiles="cartodbpositron")
    folium.PolyLine(coordenadas + [coordenadas[0]],
                color='red',
                weight=1,
                opacity=0.8).add_to(mapi)
    folium.Marker(os[0],icon=folium.Icon(color='blue') ).add_to(mapi)

    return mapi


def InsertarEnRDSDesdeArchivo(conn, data_file, nombre_tabla):
    """Procedimiento para insertar datos a la RDS desde un archivo

    Args:
        conn: Conexión a la RDS
        data_file: Archivo con los datos que se insertarán a la RDS
        nombre_table: Nombre de la tabla a la que se insertarán los datos
    """

    cur = conn.cursor()

    # Load table from the file with header
    print("copy {} from STDIN CSV HEADER QUOTE '\"'".format(nombre_tabla))
    cur.copy_expert("copy {} from STDIN CSV HEADER QUOTE '\"'".format(nombre_tabla), data_file)
    cur.execute("commit;")

    print("Loaded data into {}".format(nombre_tabla))
    cur.close()



def EjecutarQuery(conn, query):
    """Función que devuelve la cantidad de filas afectadas por un query

    Args:
        conn: Conexión a la RDS
        query: Consulta a la base de datos RDS (Se escribe
            en lenguaje SQL entre comillas)

    Returns:
        rowcount: Cantidad de filas afectadas
    """

    try:
        with conn.cursor() as (cur):
            cur.execute(query)
            cur.execute("commit;")
            rowcount = cur.rowcount
        return rowcount
    except Exception:
        print('Excepcion en EjecutarQuery-cur.execute: ', query)
        raise


def GridSearch(par_Datos, par_ClaseAlgoritmo, par_Hiper, par_Iteraciones):
    """Función que ejecuta el GridSearch

    Args:
        par_Datos: Una lista con las distancias entre los puntos que visitará
            una fuerza de ventas
        par_ClaseAlgoritmo: Algoritmo que se desea utilizar para el calculo
            de ruta óptima (PSO o SA)
        par_Hiper: Un diccionario con los hiperparametros
        par_Iteraciones: Veces que se ejecutará el algoritmo

    Returns:
        df: Un dataframe de los hiperparametros con su mínimo, máximo y moda
    """

    # Dataframe inicial
    df0 = DataFrame({'key':[1]})

    # Dataframe sobre el cual iremos pegando las demás tablas
    df_Final = df0

    # Lista para ir acumulando las columnas del dataframe
    list_Columnas = ['key']

    # Proceso para generar dataframes de cada hiper-parámetro y que el grid search se construya mediante
    # el producto cartesiano de la combinación de los dataframes
    for elemento, values in par_Hiper.items():

        list_Columnas.append(elemento)

        df_tmp = pd.DataFrame.from_dict(par_Hiper.get(elemento))
        df_tmp.columns = [elemento]
        df_tmp['key'] = 1
        df_Final = merge(df_Final, df_tmp, on='key')[list_Columnas]

    # Eliminamos la columna que nos ayudó a hacer el merge
    del df_Final['key']

    # Creamos una lista que contiene todas las combinaciones de hiper-parámetros
    list_diccionarios = df_Final.to_dict(orient='records')

    list_Resultado = []
    for diccionario in list_diccionarios:
        # print('--diccionario: ', diccionario)

        lista_CostosMinimos = []
        for iteracion in range(0, par_Iteraciones):
            # print('-iteracion: ', iteracion)

            # Ejecutar Método
            obj_Algoritmo = par_ClaseAlgoritmo(par_Datos, diccionario)
            obj_Algoritmo.Ejecutar()
            lista_CostosMinimos.append(obj_Algoritmo.nbr_MejorCosto)

        # print('--resultados: ', lista_CostosMinimos)

        # Una vez que ya se ejecutó el algoritmo, podemos ir almacenando los resultados
        nbr_Min = min(lista_CostosMinimos)
        nbr_Max = max(lista_CostosMinimos)
        nbr_CantVecesMin = lista_CostosMinimos.count(nbr_Min)
        str_FrecRelDistMin = str(nbr_CantVecesMin) + '/' + str(par_Iteraciones)
        list_Resultado.append([diccionario, round(nbr_Min,3), round(nbr_Max,3), str_FrecRelDistMin])

        df = pd.DataFrame(list_Resultado, columns=['HiperParámetros', 'Distancia mínima (km)','Distancia máxima (km)','Frec. rel. dist. min.'])

    return df


def Crear_listas_elementos(lista_elementos, num_cores):
    '''
    Función que crea tantas listas como Cores se tengan disponibles y distribuye a las fuerzas de venta entre dichas listas.

    Args:
        lista_elementos(list): lista con los id's de todos los empleados (fuerzas de venta)
        num_cores(int): número de cores con los que cuenta el sistema
    Return:
        lista_total(list): lista formada a su vez por listas (igual al número de cores); tal que cada lista contiene un determinado número de empleados.
    '''
    num_elementos = len(lista_elementos)
    lista_total = []

    # Creación de tantas listas como número de cores y primer llenado de estas listas
    for core in range(0, num_cores):
        lista_total.append([lista_elementos[core]])

    # Acomodar en las listas el resto de empleados
    for elemento in range(num_cores, num_elementos):
        posicion_lista_total = elemento % num_cores
        lista_total[posicion_lista_total].append(lista_elementos[elemento])

    return lista_total
