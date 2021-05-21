# Imports

import numpy as np
import random
from . import aco_tsp
from . import utils
import time

from .utils import create_dic_dist
from .utils import create_dic_dist_from_graph
from .utils import init_ferom
from .utils import init_atrac
from .utils import atraccion_nodos
from .utils import read_data
from .utils import rand_dist_matrix
from .utils import plot_graph
from .utils import graph_optim_path

from .aco_tsp_oo import *


# Auxiliares
def revisar_simetria(matriz, rtol=1e-05, atol=1e-08):
    """Revisa si la matriz ingresada es simétrica o no

    Args:
        matriz ([numpy matrix]): Matriz a revisar.
        rtol ([float], optional): [Parámetro de tolerancia relativa]. Defaults to 1e-05.
        atol ([float], optional): [Parámetro de tolerancia absoluta]. Defaults to 1e-08.

    Returns:
        [boolean]: [si la matriz es simétrica, regresará True, de lo contrario False]
    """
    return np.allclose(matriz, matriz.T, rtol=rtol, atol=atol)

def revisar_ceros_diagonal(matriz):
    """Revisa si una matriz tiene ceros en la diagonal.

    Args:
        matriz ([numpy matrix]): [Matriz que se quiere revisar]

    Returns:
        [boolean]: [Si la matriz posee solo ceros en la diagonal, regresa True, de lo contrario False]
    """
    resultado = True
    rango_renglones = matriz.shape[1]
    rango_columnas = matriz.shape[0]
    
    for renglon in range(0,rango_renglones,1):
        for columna in range(0,rango_columnas,1):
            if renglon == columna:
                if matriz[renglon][columna] != 0:
                    resultado = False
    return resultado

def test_probar_matriz_cuadrada():
    """Prueba si la matriz que genera la función propia es cuadrada.
    """
    matriz = utils.rand_dist_matrix(10, graph=False, scale_factor=100, round_factor=0, 
                     seed=1950, int=True)
    assert revisar_simetria(matriz)
    
def test_diagonal_ceros():
    """Prueba si la matriz que genera la función "utils.rand_dist_matrix" tiene ceros en la diagonal.
    """
    matriz = utils.rand_dist_matrix(10, graph=False, scale_factor=100, round_factor=0, 
                     seed=1950, int=True)
    assert revisar_ceros_diagonal(matriz)
    
def test_creacion_llaves_de_diccionario():
    """Prueba si existe una llave para cada nodo.
    """
    result=False
    matriz = utils.rand_dist_matrix(10, graph=False, scale_factor=100, round_factor=0, 
                     seed=1950, int=True)
    dictionary = utils.create_dic_dist(matriz)
    if matriz.shape[0]==len(dictionary.keys()):
        result = True
    assert result
    
def test_feromonas_por_nodo():
    """Prueba si existe una feromona para cada nodo.
    """
    result=False
    G = utils.rand_dist_matrix(10, int=True, scale_factor=10, round_factor=4, seed=1950)
    tau = utils.init_ferom(G)
    if len(G.nodes)==len(tau.keys()):
        result = True
    assert result

def test_atracciones_por_nodo():
    """Revisa si existen n-1 atracciones para cada nodo, pues se quita el nodo actual.
    """
    result=True
    G = utils.rand_dist_matrix(10, int=True, scale_factor=10, round_factor=4, seed=1950)
    tau = utils.init_ferom(G)
    lenghts = utils.create_dic_dist_from_graph(G)
    eta = utils.init_atrac(G, lenghts)
    A = utils.atraccion_nodos(G, tau, eta, alpha=1, beta=5)
    for nodo in range(0,len(A.keys()),1):
        if (len(A[nodo]))!=(len(list(G.nodes))-1):
            result = False
    assert result
    
def test_hormiga_por_todo_nodo():
    """Prueba si la ruta de la hormiga cubre todos los nodos y regresa al nodo inicial.
    """
    result=True
    G = utils.rand_dist_matrix(10, int=True, scale_factor=10, round_factor=4, seed=1950)
    tau = utils.init_ferom(G)
    lenghts = utils.create_dic_dist_from_graph(G)
    eta = utils.init_atrac(G, lenghts)
    A = utils.atraccion_nodos(G, tau, eta, alpha=1, beta=5)
    route, dist = aco_tsp.hormiga_recorre(G,lenghts, A, tau, 1, x_best=[], y_best= float('inf'))
    if (len(route)-1) != len(list(G.nodes)):
        result = False
    assert result
    
def test_distancia_hormiga_dif_de_cero():
    """Revisa que la distancia de la hormiga sea distinta de cero.
    """
    result=True
    G = utils.rand_dist_matrix(10, int=True, scale_factor=10, round_factor=4, seed=1950)
    tau = utils.init_ferom(G)
    lenghts = utils.create_dic_dist_from_graph(G)
    eta = utils.init_atrac(G, lenghts)
    A = utils.atraccion_nodos(G, tau, eta, alpha=1, beta=5)
    route, dist = aco_tsp.hormiga_recorre(G,lenghts, A, tau, 1, x_best=[], y_best= float('inf'))
    if (dist == 0):
        result = False
    assert result
    
def test_ejemplo_completo():
    """Revisa el ejemplo completo para ver si la distancia es cero. Pasa la prueba si es distinto a cero.
    """
    result = False
    seed = 101934
    n_nodos = 10
    X = utils.rand_dist_matrix(n_nodos, int=True, scale_factor=100, round_factor=4, seed=seed)
    X_num = utils.rand_dist_matrix(n_nodos, graph=False, int=True, scale_factor=10, round_factor=4, seed=seed)
    # diccionario de distancias
    dic_dists = utils.create_dic_dist(X_num)
    # antcolony
    ruta, dist = aco_tsp.ant_colony(X, dic_dists, ants=3, max_iter=500, verbose=20)
    if (dist!=0):
        result = True
    assert result
    
    
def test_solve_distance():
    """Revisa el ejemplo para resolver el TSP para el dataset de distancias de 17 ciudades.
    """
    path = './datasets/gr17_d_city_distances.txt'
    G = read_data(path)
    
    colonia_2 = colony(G, 
                 init_node=4, 
                 n_ants=2, 
                 max_iter=10, 
                 rho=.5, 
                 alpha=3,
                 beta=3)
    
    colonia_2.solve_tsp()
    result = colonia_2.best_dist
    
    assert result < 5000


def test_colony_multiw():
    n_ants = 1000
    n_cities =100
    path_china = './datasets/ch71009.tsp'
    G = read_coord_data(path_china, n_cities=n_cities, seed=1999)
    colony_mw = colony_multiw(G, init_node=0,  n_ants= n_ants, n_workers=12)
    start_time = time.time()
    colony_mw.solve_tsp()
    end_time = time.time()
    secs = end_time-start_time
    print(secs)
    # Se toman en cuenta 130 segundos debido a las diferencias de procesamiento en la instancia vs los tests de github
    assert secs < 130


def test_compara_tiempos_colony_multiw_vs_colony():
    n_ants = 10
    n_cities =30
    path_china = './datasets/ch71009.tsp'
    G = read_coord_data(path_china, n_cities=n_cities, seed=1999)
    colony_mw = colony_multiw(G, init_node=0,  n_ants= n_ants, n_workers=4)
    start_time = time.time()
    colony_mw.solve_tsp()
    end_time = time.time()
    secs_colony_mw = end_time-start_time
    print(secs_colony_mw)
    
    # Comparamos contra la versión anterio de Colony para asegurarnos de que se redujo el tiempo de ejecución
    colony_old = colony(G, init_node=0,  n_ants= n_ants)
    start_time = time.time()
    colony_old.solve_tsp()
    end_time = time.time()
    
    secs_old = end_time-start_time
    
    assert secs_colony_mw < secs_old