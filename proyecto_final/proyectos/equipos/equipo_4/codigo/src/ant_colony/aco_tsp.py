
import random
import tsplib95
import numpy as np
import networkx as nx
import matplotlib.pyplot as plt
from .utils import *

def hormiga_recorre(G, lenghts, dic_attr, tau, init_point, x_best, y_best):
    """Calcula la ruta y distancia más cortas con respecto al benchmark provisto, 
    luego del recorrido (o su intento) de una hormiga por la red.

    Args:
        G (networkx graph): Grafo con relaciones asociadas entre nodos
        lenghts (dic): Diccionario de distancias
        dic_attr (dic): [description]
        tau (dic): Diccionario con niveles de feromonas de los vecinos de cada nodo
        init_point (int): Nodo inicial del recorrido
        x_best (list): Ruta con respecto a la cual se quiere mejorar
        y_best (float): Distancia total del recorrido x_best

    Returns:
        list, float: Mejor ruta, mejor distancia
    """
    random.seed(random.randint(0, 1000))
    A = dic_attr
    x = [init_point]
    nodos = list(G.nodes) 

    while len(x) < len(nodos):
        i = x[-1]
        neighbors = set(list(G.neighbors(i))) - set(x)
        if len(neighbors) == 0:
            return(x_best, y_best)
        
        a_s = [A[i][j] for j in neighbors]
        next_ = random.choices(list(neighbors), weights= a_s)
        x = x + next_

    # distancia total del recorrido (se adiciona retorno al origen)
    l = sum([lenghts[x[i]][x[i+1]] for i in range(0, len(x)-1)]) + lenghts[x[-1]][init_point]

    # aportación a los niveles de feromonas
    for i in range(1, len(x)):
        tau[i-1][i] += 1/l  
        
    tau[x[-1]][init_point] += 1/l # aportación a los niveles de feromonas

    # sumar regreso al origen
    x = x + [init_point]
    
    if l < y_best:
        return x, l
    else:
        return x_best, y_best  

def ant_colony(G, lenghts, init=0, graph=True, ants=200, max_iter=100,  alpha=1, beta=5, rho=.5, verbose=10):
    """Computa el algoritmo ant-colony para encontra la ruta con menor distancia en el problema
    TSP.


    Args:
        G (networkx graph): Grafo con relaciones asociadas entre nodos
        lenghts (dic): Diccionario de distancias
        init (int, optional): Nodo inicial del recorrido. Defaults to 0.
        graph (bool, optional): Grafica la mejor ruta encontrada. Default es True.
        ants (int, optional): Número de hormigas por iteracion. Defaults to 200.
        max_iter (int, optional): Número máximo de iteraciones. Defaults to 100.
        alpha (int, optional): Factor de influencia de tau. Defaults to 1.
        beta (int, optional): Factor de influencia de eta. Defaults to 5.
        rho (float, optional): Tasa de evaporación de las feromonas. Defaults to .5.
        verbose (int, optional): Imprime progreso del algoritmo cada K iteraciones. Defaults to 10.

    Returns:
        list, float: Mejor ruta, mejor distancia
    """

    # iniciales
    x_best=[]
    y_best= float('inf')
    
    tau = init_ferom(G)
    eta = init_atrac(G,lenghts)
    for k in range(1, max_iter + 1):
        A = atraccion_nodos(G, tau, eta, alpha=1, beta=5)
        for e in tau:
            for v in tau:
                tau[e][v] = (1-rho)*v
                
        for ant in range(1, ants + 1):
            x_best, y_best = hormiga_recorre(G,lenghts,  A, tau, init, x_best, y_best)
            
        if k%verbose == 0 or k==1:
            print(f'iter: {k} / {max_iter} - dist: {round(y_best, 2)}')

    if k%verbose == 0:
        print('\n')
        print("-"*30)
        print('Resumen:')
        print(f'\tNro. de hormigas: {ants}')  
        print(f'\tIteraciones: {max_iter}')  
        print(f'\tDistancia: {y_best}') 
        print(f'\tNodo inicial: {init}')  
        print(f'\tRuta: {x_best}') 
        print("-"*30)
        
    if graph:
        graph_optim_path(G, x_best, y_best)

    return x_best, y_best
