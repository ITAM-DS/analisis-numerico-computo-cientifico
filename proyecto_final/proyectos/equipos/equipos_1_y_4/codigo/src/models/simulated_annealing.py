from __future__ import print_function
import random
from simanneal import Annealer
import time
import pandas as pd
from collections import deque


class TravellingSalesmanProblem(Annealer):

    """
    Clase que aplica el algoritmo de simulated annealing para resolver el problema del viajero
    """
    # Hiperparámetros del algoritmo
    Tmax = 0
    Tmin = 0
    steps = 0
    updates = 0

    # Atributos de resultados de la ejecución
    TiempoEjec = 0
    MejorCosto = 0
    MejorCamino = []

    def __init__(self, state, distance_matrix,sim_HiperParam):
        self.distance_matrix = distance_matrix
        super(TravellingSalesmanProblem, self).__init__(state)  # important!
        self.Tmax = sim_HiperParam.get('Tmax')
        self.Tmin = sim_HiperParam.get('Tmin')
        self.steps = sim_HiperParam.get('steps')
        self.updates = sim_HiperParam.get('updates')

    def move(self):
        """Funcion que intercambia dos nodos en la ruta con la intención de probar otras rutas"""
        initial_energy = self.energy()

        a = random.randint(0, len(self.state) - 1)
        b = random.randint(0, len(self.state) - 1)
        self.state[a], self.state[b] = self.state[b], self.state[a]

        return self.energy() - initial_energy

    def energy(self):
        """Funcion que calcula la distancia total de la ruta."""
        e = 0
        for i in range(len(self.state)):
            e += self.distance_matrix[self.state[i-1]][self.state[i]]
        return e

class SimulatedAnnealing():

    def __init__(self, df_fv, dict_Hiper):
        """
    Constructor de la clase.Se genera un diccionario de distancias entre nodos, el cual alimenta al
    algoritmo del viajero.
    Args:
        df_fv (dataFrame): DataFrame con la base de datos
        dic_Hiper(diccionario): Diccionario con hiperparametros.
    Returns:
        dic(diccionario): Diccionario de distancias entre nodos.
    """
        self.nodos = pd.unique(df_fv[['id_origen', 'id_destino']].values.ravel('K')).tolist()
        for i in range(0,len(self.nodos)):
            self.nodos[i]=int(self.nodos[i])
        combinaciones = [[a, b] for a in self.nodos for b in self.nodos]
        self.df2 = pd.DataFrame(combinaciones,columns=['id_origen', 'id_destino'])
        self.df2['distancia'] = 0.0
        i=0
        for row in self.df2.values:
            if (row[0]==row[1]):
                row[2]= 0
            elif (row[0]!=row[1] and row[0]<row[1]):
                v= df_fv.query('id_origen == {} & id_destino == {}'.format(row[0],row[1]))
                v2=v['distancia'].tolist()
                row[2]= v2[0]
            elif (row[0]!=row[1] and row[0]>row[1]):
                v= df_fv.query('id_origen == {} & id_destino == {}'.format(row[1],row[0]))
                v2= v['distancia'].tolist()
                row[2]= v2[0]
            self.df2.iloc[i]=row
            i+=1
        dic = {k : g.distancia.to_dict() for k, g in self.df2.set_index('id_origen').groupby('id_destino')}
        #print(self.nodos)
        #print(dic)
        self.Nodo_Inicio = self.nodos[0]
        random.shuffle(self.nodos)
        #Se llama a la clase TSP, encargada de aplicar simulated annealing al problema del viajero
        self.tsp = TravellingSalesmanProblem(self.nodos, dic, dict_Hiper)
        self.str_Clave = 'SA'
        self.dict_HiperParam = dict_Hiper
        #print(self.Nodo_Inicio)

        return

    def Ejecutar(self):
        """Funcion que ejecuta el algoritmo de SA para TSP"""
        tm_inicio = time.time()
        if (len(self.nodos) > 2):
            self.tsp.set_schedule(self.dict_HiperParam)
            self.tsp.copy_strategy = "slice"
            state, e = self.tsp.anneal()
            tm_final = time.time()
            self.nbr_MejorCosto = e
            self.lst_MejorCamino = state
            self.nbr_TiempoEjec = tm_final - tm_inicio
        else:
            state = self.nodos
            e = 2*self.df2['distancia'].iloc[1]
            #e= 2
            tm_final = time.time()
            self.nbr_MejorCosto = e
            self.lst_MejorCamino = state
            self.nbr_TiempoEjec = tm_final - tm_inicio

        nbr_NodoInicio = self.Nodo_Inicio
        nbr_Index = self.lst_MejorCamino.index(nbr_NodoInicio)

        items = deque(self.lst_MejorCamino)
        items.rotate(-nbr_Index)
        self.lst_MejorCamino=list(items)

        return
