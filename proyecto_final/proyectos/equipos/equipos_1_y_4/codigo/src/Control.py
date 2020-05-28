import Utileria as ut
from data import load_data
from data import transformaciones
import dask
import multiprocessing


class Control():

    def __init__(self):
        # Definición de hiperparámetros de PS
        self.dict_Hiper_PS = {'Iteraciones': 10,
                              'Particulas': 10,
                              'Alfa': .9,
                              'Beta': 1
                              }

        # Definición de hiperparámetros de SA
        self.dict_Hiper_SA = {'Tmax': 25000.0,
                              'Tmin': 2.5,
                              'steps': 50000,
                              'updates': 100
                              }
        self.grafo_Ejecucion = None

        # Atributo para controlar qué tipo de ejecución queremos realizar
        self.str_TipoEjecucion = ''
        self.__nbr_CoresDisponibles = multiprocessing.cpu_count()
        self.__nbr_CoresParaUsar = multiprocessing.cpu_count()

    def setCoresUso(self, par_Valor):
        if par_Valor == 0:
            print('No se pueden especificar cero cores')
        elif par_Valor <= self.__nbr_CoresDisponibles:
            self.__nbr_CoresParaUsar = par_Valor
        else:
            print('No se pueden asignar más cores de los disponibles')

    def getCoresUso(self):
        return self.__nbr_CoresParaUsar

    def CargarBase(self):
        load_data.main(self.str_TipoEjecucion)
        return

    def Transform(self):
        str_query = "SELECT * FROM raw.fuerza_ventas order by no_cliente"
        df_Trabajo = ut.get_data(str_query)
        df_Grafos = transformaciones.generar_grafo(df_Trabajo)
        df_Grafos.to_csv('grafos_fza_ventas.csv', index=False, header=True)

        conn = ut.CrearConexionRDS()
        data_file = open('grafos_fza_ventas.csv', "r")
        ut.InsertarEnRDSDesdeArchivo(conn, data_file, 'trabajo.grafos')

        # Aquí hay que agregar un código para eliminar el csv temporal
        return

    def CalcularRutasXLista(self, lst_empleados, par_ClaseAlgoritmo, par_HiperParam):

        for fza_ventas in lst_empleados:
            fza_ventas = int(fza_ventas)
            # print('--fza_ventas: ', fza_ventas)
            df_Fza_Ventas = None
            str_Query = 'select id_origen, id_destino, distancia \
                         from trabajo.grafos where id_fza_ventas = {};'
            df_Fza_Ventas = ut.get_data(str_Query.format(fza_ventas))

            obj_Algoritmo = par_ClaseAlgoritmo(df_Fza_Ventas, par_HiperParam)
            obj_Algoritmo.Ejecutar()
            self.GuardarRuta(fza_ventas, obj_Algoritmo.str_Clave, obj_Algoritmo.lst_MejorCamino, obj_Algoritmo.nbr_MejorCosto)

        return 0

    def ObtenerListaFzaVentas(self):
        str_Query = 'select distinct(id_fza_ventas) as id_fza_ventas \
                     from trabajo.grafos'
        df_Fza_Ventas = ut.get_data(str_Query)

        lista_fza_ventas = df_Fza_Ventas.values.tolist()
        for i in range(0, len(lista_fza_ventas)):
            lista_fza_ventas[i] = int(lista_fza_ventas[i][0])

        return lista_fza_ventas

    def CalcularRutasSeq(self, par_ClaseAlgoritmo, par_HiperParam):

        lista_emp = self.ObtenerListaFzaVentas()

        self.CalcularRutasXLista(lista_emp, par_ClaseAlgoritmo, par_HiperParam)

        return

    def CalcularRutasPar(self, par_ClaseAlgoritmo, par_HiperParam):

        lista_emp = self.ObtenerListaFzaVentas()
        print(lista_emp[0])
        num_cores = self.__nbr_CoresParaUsar

        # Creación de listas de empleados dependiendo del número de Cores disponibles
        lista_empl = ut.Crear_listas_elementos(lista_emp, num_cores)

        # Definición de la lista en donde se almacenarán las funciones lazy que posteriormente serán ejecutadas en paralelo
        lista_ejecuciones = []

        # Llenado de lista_ejecuciones
        for empleados in lista_empl:
            dask_Ejecucion = self.ejecucion_paralelo(empleados, par_ClaseAlgoritmo, par_HiperParam)
            lista_ejecuciones.append(dask_Ejecucion)

        self.grafo_Ejecucion = self.juntar_ejecuciones(lista_ejecuciones)

        return

    @dask.delayed
    def ejecucion_paralelo(self, lst_empleados, par_ClaseAlgoritmo, par_HiperParam):
        '''
        Función que a su vez prepara funciones que posteriormente serán ejecutadas en paralelo;
        las convierte en funciones lazy, por lo que su resultado no será calculado inmediatamente,
        si no que será almacenado como una tarea dentro de un grafo, que posteriormente será
        ejecutado en paralelo.

        Args:
            lst_empleados(list): lista formada por uno o más empleados (fuerza de venta)
        Return:
            task(): ejecución del algoritmo particle swarm como función lazy, que después será ejecutada en paralelo
        '''
        task = self.CalcularRutasXLista(lst_empleados, par_ClaseAlgoritmo, par_HiperParam)
        return task

    @dask.delayed
    def juntar_ejecuciones(self, *arg):
        '''
        Función que permitirá ejecutar procesos en paralelo.
        Esta función también es considerada una función lazy

        Args:
            *arg(list): lista formada a su vez por listas, tal que cada lista representa un proceso a correr
        Return:
            arg(): función lazy que es almacenada como una tarea dentro de un grafo, la cual
                    posteriomente ejecutará en paralelo tantos procesos como sublistas haya
        '''

        return arg

    def GuardarRuta(self, par_fza_ventas, par_Algorirmo, par_Camino, par_Costo):

        str_Nodos = [str(nodo) for nodo in par_Camino]
        str_Nodos = ", ".join(str_Nodos)
        str_Insert = "insert into trabajo.resultados values \
                      ({},'{}','{}',{})".format(par_fza_ventas,
                                                par_Algorirmo,
                                                str_Nodos,
                                                par_Costo)
        conn = ut.CrearConexionRDS()
        ut.EjecutarQuery(conn, str_Insert)

        return
