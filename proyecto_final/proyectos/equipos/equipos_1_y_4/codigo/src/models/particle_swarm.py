import copy as cp
import dask
import random
import time
from operator import attrgetter
from collections import deque

class Particula():

    list_CaminoActual = []
    list_MejorCamino = []
    nbr_CostoCaminoActual = 0
    nbr_CostoMejorCamino = 0
    velocidad = []

    def __init__(self, par_camino, par_costo):

        self.list_CaminoActual = par_camino
        self.list_MejorCamino = par_camino
        self.nbr_CostoCaminoActual = par_costo
        self.nbr_CostoMejorCamino = par_costo
        self.velocidad = []

class Grafo():

    dict_Nodos = {}
    conj_Nodos = set()  # No hay repeticiones
    nbr_CantNodos = 0
    df_Grafo = None

    def __init__(self, par_df):
        self.dict_Nodos = {}
        self.conj_Nodos = set()  # No hay repeticiones
        self.df_Grafo = par_df
        self.GenerarGrafo()
        self.nbr_CantNodos = len(self.conj_Nodos)

    def GenerarGrafo(self):

        # Barremos las filas del data frame para generar el grafo
        for fila in self.df_Grafo:
            # Las distacias son las mismas en ambos sentidos
            self.AgregarNodoAGrafo(fila[0], fila[1], fila[2])
            self.AgregarNodoAGrafo(fila[1], fila[0], fila[2])

    def AgregarNodoAGrafo(self, par_Origen, par_Destino, par_Costo):

        if not self.ExisteNodo(par_Origen, par_Destino):
            self.dict_Nodos[(par_Origen, par_Destino)] = par_Costo
            self.conj_Nodos.add(par_Origen)
            self.conj_Nodos.add(par_Destino)

    def ExisteNodo(self, par_Origen, par_Destino):
        if (par_Origen, par_Destino) in self.dict_Nodos:
            return True
        else:
            return False

    def MostrarGrafo(self):
        print('Grafo:\n')
        for Nodo in self.dict_Nodos:
            print('%d conectado con: %d. Costo: %d' % (Nodo[0], Nodo[1], self.dict_Nodos[Nodo]))

    def CostoDelCamino(self, camino):

        nbr_CostoTotal = 0
        for i in range(self.nbr_CantNodos - 1):
            try:
                nbr_CostoTotal += self.dict_Nodos[(camino[i], camino[i+1])]
            except:
                print('--self.dict_Nodos: ', self.dict_Nodos)
                print('--camino: ', camino)
                print('--i: ', i)
                print('--camino[i]: ', camino[i])
                raise

        nbr_CostoTotal += self.dict_Nodos[(camino[self.nbr_CantNodos - 1], camino[0])]
        return nbr_CostoTotal

    def GenerarCaminosAleatorios(self, max_size):

        list_CaminosAleatorio, list_Nodos = [], list(self.conj_Nodos)

        initial_vertice = random.choice(list_Nodos)

        list_Nodos.remove(initial_vertice)
        list_Nodos.insert(0, initial_vertice)

        for i in range(max_size):
            list_temp = list_Nodos[1:]
            random.shuffle(list_temp)
            list_temp.insert(0, initial_vertice)

            if list_temp not in list_CaminosAleatorio:
                list_CaminosAleatorio.append(list_temp)

        return list_CaminosAleatorio


class ParticleSwarm():

    # Atributos generales para la ejecución
    df_Datos = ''
    str_TipoEjec = ''

    # Hiperparámetros del algoritmo
    nbr_Iteraciones = 0
    nbr_CantPartic = 0
    nbr_Alfa = 0
    nbr_Beta = 0

    # Atributos de resultados de la ejecución
    nbr_TiempoEjec = 0
    nbr_MejorCosto = 0
    lst_MejorCamino = []

    # Atributo auxiliar
    list_Particulas = []

    def __init__(self, par_Datos, par_HiperParam, par_TipoEjec='SEQ'):

        # Datos y tipo de ejecución
        self.df_Datos = par_Datos.values.tolist()
        self.str_TipoEjec = par_TipoEjec
        self.str_Clave = 'PS'

        # Hiperparámetros del algoritmo
        self.nbr_Iteraciones = par_HiperParam.get('Iteraciones')
        self.nbr_CantPartic = par_HiperParam.get('Particulas')
        self.nbr_Alfa = par_HiperParam.get('Alfa')
        self.nbr_Beta = par_HiperParam.get('Beta')

        #################
        self.list_Particulas = []
        self.Grafo = Grafo(self.df_Datos)
        list_CaminosAleatorios = self.Grafo.GenerarCaminosAleatorios(self.nbr_CantPartic)
        for list_CaminoAleatorio in list_CaminosAleatorios:
            particula = Particula(list_CaminoAleatorio, self.Grafo.CostoDelCamino(list_CaminoAleatorio))
            self.list_Particulas.append(particula)

        # updates "size_population"
        self.nbr_CantPartic = len(self.list_Particulas)

    def Ejecutar(self):

        # Tomamos la hora de inicio
        tm_inicio = time.time()

        # Se corre el algorimto secuencial o en paralelo según los parámetros
        if self.str_TipoEjec == 'SEQ':
            self.Secuencial()
        elif self.str_TipoEjec == 'PAR':
            self.Paralelo()

        self.lst_MejorCamino = self.obj_MejorParticula.list_MejorCamino
        self.nbr_MejorCosto = self.obj_MejorParticula.nbr_CostoMejorCamino

        # Re ordenamos los índices para que las rutas comiencen desde el nodo inicial
        nbr_NodoInicio = self.df_Datos[0][0]
        nbr_Index = self.lst_MejorCamino.index(nbr_NodoInicio)

        items = deque(self.lst_MejorCamino)
        items.rotate(-nbr_Index)
        self.lst_MejorCamino=list(items)

        # Se toma la hora de fin del algoritmo, y se almacena la duración
        tm_final = time.time()
        self.nbr_TiempoEjec = tm_final - tm_inicio

    def Secuencial(self):

        for t in range(self.nbr_Iteraciones):

            self.obj_MejorParticula = min(self.list_Particulas, key=attrgetter('nbr_CostoMejorCamino'))
            for particula in self.list_Particulas:

                particula = self.ProcesoXParticula(particula, self.obj_MejorParticula)

    def Paralelo(self):

        # Por ejemplo
        for t in range(self.nbr_Iteraciones):

            self.obj_MejorParticula = min(self.list_Particulas, key=attrgetter('nbr_CostoMejorCamino'))

            list_Particulas_Temp = []
            for particula in self.list_Particulas:

                dask_Particula = self.ProcesoXParticulaParalelo(particula, self.obj_MejorParticula)
                list_Particulas_Temp.append(dask_Particula)

            dask_Dummy1 = self.JuntarParticulas(list_Particulas_Temp)
            dask_Dummy2 = dask_Dummy1.compute()
            list_Final = dask_Dummy2[0]
            self.list_Particulas = list_Final

    @dask.delayed
    def JuntarParticulas(self, *argv):
        return argv

    @dask.delayed
    def ProcesoXParticulaParalelo(self, particle, par_gbest):
        return self.ProcesoXParticula(particle, par_gbest)

    def ProcesoXParticula(self, particula, par_gbest):

        # time.sleep(.01)
        del particula.velocidad[:]

        list_VelocidadTemp = []
        list_MejorCaminoGlob = cp.copy(self.obj_MejorParticula.list_MejorCamino)
        list_MejorCaminoPart = particula.list_MejorCamino[:]
        list_CaminoParticula = particula.list_CaminoActual[:]

        list_VelocidadTemp_p = self.Swap(list_CaminoParticula, list_MejorCaminoPart, self.nbr_Alfa)

        list_VelocidadTemp_g = self.Swap(list_CaminoParticula, list_MejorCaminoGlob, self.nbr_Beta)

        list_VelocidadTemp_t = self.JuntarListasSwaps(list_VelocidadTemp_p, list_VelocidadTemp_g)
        list_VelocidadTemp = list_VelocidadTemp_t

        particula.velocidad = list_VelocidadTemp

        # Generación de nuevo camino para la particula
        for tup_Swarm in list_VelocidadTemp:

            if random.random() <= tup_Swarm[2]:
                aux = list_CaminoParticula[tup_Swarm[0]]
                list_CaminoParticula[tup_Swarm[0]] = list_CaminoParticula[tup_Swarm[1]]
                list_CaminoParticula[tup_Swarm[1]] = aux

        particula.list_CaminoActual = list_CaminoParticula
        nbr_CostoCaminoActual = self.Grafo.CostoDelCamino(list_CaminoParticula)
        particula.nbr_CostoCaminoActual = nbr_CostoCaminoActual

        if nbr_CostoCaminoActual < particula.nbr_CostoMejorCamino:
            particula.list_MejorCamino = list_CaminoParticula
            particula.nbr_CostoMejorCamino = nbr_CostoCaminoActual

        return particula

    # @dask.delayed
    def Swap(self, par_CaminoParticula, par_MejorCamino, par_AlphaBeta):
        list_VelocidadTemp = []
        for i in range(self.Grafo.nbr_CantNodos):
            if par_CaminoParticula[i] != par_MejorCamino[i]:

                tup_Swarm = (i, par_MejorCamino.index(par_CaminoParticula[i]), par_AlphaBeta)
                list_VelocidadTemp.append(tup_Swarm)

                # Hacemos el intercambio
                aux = par_MejorCamino[tup_Swarm[0]]
                par_MejorCamino[tup_Swarm[0]] = par_MejorCamino[tup_Swarm[1]]
                par_MejorCamino[tup_Swarm[1]] = aux

        return list_VelocidadTemp

    # @dask.delayed
    def JuntarListasSwaps(self, list1, list2):
        total = list1 + list2
        return total
