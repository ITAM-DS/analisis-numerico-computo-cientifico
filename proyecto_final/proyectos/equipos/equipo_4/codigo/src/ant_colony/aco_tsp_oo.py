import random
import tsplib95
import numpy as np
import networkx as nx
import matplotlib.pyplot as plt
from .utils import *
from multiprocessing import Pool

class colony_multiw():
    """Clase que representa una colonia de hormigas que recorren
    el grafo asignado para resolver el problema TSP. A diferencia de la
    clase colony(), esta clase implementa multiprocesamiento para computar 
    la solución del problema utilizando un pool de workers.

    Args:
        G (networkx graph): Grafo con relaciones asociadas entre nodos
        init_node (int): Nodo inicial del recorrido.
        best_route (list, optional): Ruta con respecto a la cual se quiere mejorar.
        best_dist ([type], optional): Distancia total del recorrido x_best.
        n_ants (int, optional): Número de hormigas. Default es 2.
        max_iter (int, optional): [description]. Default es 100.
        alpha (int, optional): Factor de influencia de tau. Defaults to 1.
        beta (int, optional): Factor de influencia de eta. Defaults to 5.
        rho (float, optional): Tasa de evaporación de las feromonas. Defaults to .5.
        verbose (int, optional): Imprime progreso del algoritmo cada K iteraciones. Defaults to 10.
    """
    def __init__(self, G, init_node,
                 best_route = [],
                 best_dist = float('inf'),
                 n_ants=2,
                 max_iter=10, 
                 alpha=1, 
                 beta=5, 
                 rho=.5,
                 n_workers = 1,
                 verbose=False, 
                 k_verbose=10):
        self.graph = G
        self.A = None
        self.init_node = init_node
        self.best_route = best_route
        self.best_dist = best_dist
        self.lenghts = create_dic_dist_from_graph(self.graph)
        self.n_ants = n_ants
        self.max_iter = max_iter
        self.alpha = alpha
        self.beta = beta
        self.rho = rho
        self.n_workers = n_workers
        self.ants_per_worker = assign_ants_threats(self.n_ants, self.n_workers)
        self.tau = init_ferom(self.graph)
        self.eta = init_atrac(self.graph, self.lenghts)
        self.verbose = verbose
        self.k_verbose = k_verbose

    def _update_pheromone_levels(self, route, dist_route):
        """Actualiza el nivel de feromonas en las respectivas trayectorias
        del grafo.

        Args:
            route (lst): Lista que incluye un recorrido por el grafo.
            dist_route (float): Distancia de la ruta.
        """
        for i in range(1, len(route[:-1])):
            self.tau[i-1][i] += 1/dist_route
        self.tau[route[:-1][-1]][self.init_node]
        
    def _update_many_pheromone_levels(self, routes, distances):
        """Actualiza los niveles de feromonas para diferentes rutas
        recorridas por diferentes hormigas.

        Args:
            routes (lst of lst): Lista que contiene los recorridos 
            realziados por diferentes hormigas.
            distances (lst of floats): Lista con las distancias de
            las rutas.
        """
        if (len(distances) == len(self.graph.nodes)):
            for i in range(len(routes)):
                self._update_pheromone_levels(routes[i], distances[i])
                
    def _evaporates_pheromone(self):
        """Evapora los niveles de feromonas en todos los tramos del 
        grafo.
        """
        for e in self.tau:
            for v in self.tau:
                self.tau[e][v] = (1-self.rho)*v
                
    def _n_ants_walk(self, n_ants):
        """Metodo que define el recorrido de varias hormigas sobre un solo
        worker. 

        Args:
            n_ants (int): Número de hormigas que procesará el worker asignado.

        Returns:
            [lst]: Lista de tuplas con distancias y rutas encotnradas por las
            hormigas del worker.
        """
        ants_in_thread = [ant(self.graph) for i in range(n_ants)]
        # solution for each ant
        for a in ants_in_thread:
            a.walk_over_graph(self.init_node, self.best_dist, self.A)
        # tuple with sln for each ant
        slns = [(a.route, a.r_len) for a in ants_in_thread]
        return slns
    
    def _multiprocessing_bt(self, ants_per_threat, num_cpu):
        """Aplica multiprocesamiento en todos los workers seleccionados para que 
        todas las hormigas de la colonia recorran el grafo en una iteración.

        Args:
            ants_per_threat (lst): Lista con la asignación del número de hormigas
            de cada worker.
            num_cpu (int): Número de workers seleccionados.

        Returns:
            [lst]: lsita de tuplas con todas las distancias y recorridos encontrados
            por todas las hormigas del pool de workers.
        """
        with Pool(processes=num_cpu) as pool:
            results = pool.starmap(self._n_ants_walk, ants_per_threat)
        
        return flatten_list_of_list(results)
    
    def _colony_run(self, A):
        """La hormigas de la colonia realizan recorridos 
        independientes simultáneamente en cada wiorker asignado. 

        Args:
            A (dic): nivel de atracción de los nodos con respecto
            a sus vecinos.
        """
        # multiprocessing
        ants_journey = self._multiprocessing_bt(self.ants_per_worker, self.n_workers)
        
        # get paths and distances
        routes, distances = zip(*ants_journey)
        # updates pheromone levels
        self._update_many_pheromone_levels(routes, distances)
            
        # best route
        bst_idx = np.argmin(distances)
        min_dist = distances[bst_idx]
        bst_route = routes[bst_idx]
        
        # improves route if possible
        if min_dist < self.best_dist:
            self.best_dist = min_dist
            self.best_route = bst_route
            
    def solve_tsp(self):
        """Resuelve el problema TSP.
        """
        route = self.best_route
        dist = self.best_dist
        
        for k in range(self.max_iter):
            self.A = atraccion_nodos(self.graph,tau= self.tau, eta=self.eta, 
                                alpha=self.alpha, beta=self.beta)
            
            if k>1:
                self._evaporates_pheromone()
                
            # ants running across the graph
            self._colony_run(self.A)

            if self.verbose and (k%self.k_verbose==0):
                print(f'iter: {k} / {self.max_iter} - dist: {round(self.best_dist, 2)}')

        if self.verbose:
            print('\n')
            print("-"*30)
            print('Resumen:')
            print(f'\tNro. de hormigas: {self.n_ants}')  
            print(f'\tIteraciones: {self.max_iter}')  
            print(f'\tDistancia: {self.best_dist}') 
            print(f'\tNodo inicial: {self.init_node}')  
            print(f'\tRuta: {self.best_route}') 
            print("-"*30)

    def plot_route(self, plt_size=(12, 8)):
        """Grafica la trayectoria encontrada por la colonia en el grafo.

        Args:
            plt_size (tuple, optional): Tamaño del gŕafico (ancho x altura). Defaults es (12, 8).
        """
        graph_optim_path(self.graph, self.best_route, self.best_dist, plt_size)

class colony():
    """Clase que representa una colonia de hormigas que recorren
    el grafo asignado para resolver el problema TSP.

    Args:
        G (networkx graph): Grafo con relaciones asociadas entre nodos
        init_node (int): Nodo inicial del recorrido.
        best_route (list, optional): Ruta con respecto a la cual se quiere mejorar.
        best_dist ([type], optional): Distancia total del recorrido x_best.
        n_ants (int, optional): Número de hormigas. Default es 2.
        max_iter (int, optional): [description]. Default es 100.
        alpha (int, optional): Factor de influencia de tau. Defaults to 1.
        beta (int, optional): Factor de influencia de eta. Defaults to 5.
        rho (float, optional): Tasa de evaporación de las feromonas. Defaults to .5.
        verbose (int, optional): Imprime progreso del algoritmo cada K iteraciones. Defaults to 10.
    """
    def __init__(self, G, init_node,
                 best_route = [],
                 best_dist = float('inf'),
                 n_ants=2,
                 max_iter=100, 
                 alpha=1, 
                 beta=5, 
                 rho=.5, 
                 verbose=False, 
                 k_verbose=100):
        self.graph = G
        self.init_node = init_node
        self.best_route = best_route
        self.best_dist = best_dist
        self.lenghts = create_dic_dist_from_graph(self.graph)
        self.n_ants = n_ants
        self.ants = [ant(G) for i in range(self.n_ants)]
        self.max_iter = max_iter
        self.alpha = alpha
        self.beta = beta
        self.rho = rho
        self.tau = init_ferom(self.graph)
        self.eta = init_atrac(self.graph, self.lenghts)
        self.verbose = verbose
        self.k_verbose = k_verbose
        
    def _update_pheromone_levels(self, route, dist_route):
        """Actualiza el nivel de feromonas en las respectivas trayectorias
        del grafo.

        Args:
            route (lst): Lista que incluye un recorrido por el grafo.
            dist_route (float): Distancia de la ruta.
        """
        for i in range(1, len(route[:-1])):
            self.tau[i-1][i] += 1/dist_route
        self.tau[route[:-1][-1]][self.init_node]
        
    def _update_many_pheromone_levels(self, routes, distances):
        """Actualiza los niveles de feromonas para diferentes rutas
        recorridas por diferentes hormigas.

        Args:
            routes (lst of lst): Lista que contiene los recorridos 
            realziados por diferentes hormigas.
            distances (lst of floats): Lista con las distancias de
            las rutas.
        """
        if (len(distances) == len(self.graph.nodes)):
            for i in range(len(routes)):
                self._update_pheromone_levels(routes[i], distances[i])
            
    def _evaporates_pheromone(self):
        """Evapora los niveles de feromonas en todos los tramos del 
        grafo.
        """
        for e in self.tau:
            for v in self.tau:
                self.tau[e][v] = (1-self.rho)*v
            
    def _colony_run(self, A):
        """La hormigas de la colonia realizan recorridos 
        independientes simultáneamente.

        Args:
            A (dic): nivel de atracción de los nodos con respecto
            a sus vecinos.
        """
        distances = []
        routes = []
        for ant in self.ants:
            ant.walk_over_graph(init_node=self.init_node, 
                                dist = self.lenghts, 
                                atrac = A)
            
            routes.append(ant.route)
            distances.append(ant.r_len)
            
        # updates pheromone levels
        self._update_many_pheromone_levels(routes, distances)
            
        # best route
        min_dist = min(distances)
        bst_idx = distances.index(min_dist)
        bst_route = self.ants[bst_idx].route
        
        # improves route if possible
        if min_dist < self.best_dist:
            self.best_dist = min_dist
            self.best_route = bst_route
            
    def solve_tsp(self):
        """Resuelve el problema TSP.
        """
        route = self.best_route
        dist = self.best_dist
        
        for k in range(self.max_iter):
            A = atraccion_nodos(self.graph,tau= self.tau, eta=self.eta, 
                                alpha=self.alpha, beta=self.beta)
            
            if k>1:
                self._evaporates_pheromone()

            # ants running across the graph
            self._colony_run(A)

            if self.verbose and (k%self.k_verbose==0):
                print(f'iter: {k} / {self.max_iter} - dist: {round(self.best_dist, 2)}')

        if self.verbose:
            print('\n')
            print("-"*30)
            print('Resumen:')
            print(f'\tNro. de hormigas: {self.n_ants}')  
            print(f'\tIteraciones: {self.max_iter}')  
            print(f'\tDistancia: {self.best_dist}') 
            print(f'\tNodo inicial: {self.init_node}')  
            print(f'\tRuta: {self.best_route}') 
            print("-"*30)
                

    def plot_route(self, plt_size=(12, 8)):
        """Grafica la trayectoria encontrada por la colonia en el grafo.

        Args:
            plt_size (tuple, optional): Tamaño del gŕafico (ancho x altura). Defaults es (12, 8).
        """
        graph_optim_path(self.graph, self.best_route, self.best_dist, plt_size)

class ant():
    """Clase que representa una hormiga de la colonia y realizará
    recorridos por el grafo.

    Args:
        G (networkx graph): Grafo con relaciones asociadas entre nodos
    """
    def __init__(self, G, r_len = float('inf'), route = []):
        
        self.graph = G
        self.seed = 19512959
        self.route = route
        self.r_len = r_len
        self.atraction_mat = None
        
    def walk_over_graph(self, 
                      init_node,
                      dist, 
                      atrac):
        """La hormiga intenta recorrer el grafo y volver
        al origen sin repetir otros nodos.

        Args:
            init_node (int): Nodo inicial del recorrido.
            dist (dic): Diccionario de distancias de las trayectorias.
            atrac (dic): Diccionario de atracción de los nodos con 
            relación a sus vecinos.
        """
        
        x = [init_node]
        nodes = list(self.graph.nodes)
        lenghts = create_dic_dist_from_graph(self.graph)
        
        while len(x) < len(nodes):
            i = x[-1]
            neighbors = set(list(self.graph.neighbors(i))) - set(x)
            if len(neighbors) == 0:
                break
        
            a_s = [atrac[i][j] for j in neighbors]
            next_ = random.choices(list(neighbors), weights= a_s)
            x = x + next_

        # distancia total del recorrido (se adiciona retorno al origen)
        l = sum([lenghts[x[i]][x[i+1]] for i in range(0, len(x)-1)]) + lenghts[x[-1]][init_node] 

        # sumar regreso al origen
        self.route = x + [init_node]   
        self.r_len = l
            
    def plot_route(self, plt_size):
        """Grafica la trayectoria encontrada por la colonia en el grafo.

        Args:
            plt_size (tuple, optional): Tamaño del gŕafico (ancho x altura). Defaults es (12, 8).
        """
        graph_optim_path(self.graph, self.route, self.r_len, plt_size)


