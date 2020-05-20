from __future__ import print_function
import random
from simanneal import Annealer
import time
import pandas as pd
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
        nodos = df_fv.id_origen.unique().tolist()
        for i in range(0,len(nodos)):
            nodos[i]=int(nodos[i])
        combinaciones = [[a, b] for a in nodos for b in nodos]
        df2 = pd.DataFrame(combinaciones,columns=['id_origen', 'id_destino'])
        df2['distancia'] = 0
        i=0
        for row in df2.values:
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
            df2.iloc[i]=row
            i+=1
        dic = {k : g.distancia.to_dict() for k, g in df2.set_index('id_origen').groupby('id_destino')}
        random.shuffle(nodos)
        #Se llama a la clase TSP, encargada de aplicar simulated annealing al problema del viajero
        self.tsp = TravellingSalesmanProblem(nodos, dic, dict_Hiper)
        self.str_Clave = 'SA'
        return

    def Ejecutar(self):
        """Funcion que ejecuta el algoritmo de SA para TSP"""
        tm_inicio = time.time()
        self.tsp.set_schedule(self.tsp.auto(minutes=0.2))
        self.tsp.copy_strategy = "slice"
        state, e = self.tsp.anneal()
        tm_final = time.time()
        self.nbr_MejorCosto = e
        self.lst_MejorCamino = state
        self.nbr_TiempoEjec = tm_final - tm_inicio
        return
