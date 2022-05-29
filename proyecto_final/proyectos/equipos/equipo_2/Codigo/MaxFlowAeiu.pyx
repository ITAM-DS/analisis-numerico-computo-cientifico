import numpy as np
from cpython cimport array
import array


cdef class MaxFlowAeiu:
    '''
        Finds the paths in order to return the maximum flow in the
        network. This class implements the Ford Fulkerson method.
    '''
    cdef unsigned int N, source, sink, maximum_flow
    cdef int[:,:] graph

    def __init__(self,list graph):
        '''
        Initialices parts of the problem.
        Attributes:
            graph (array 2D): defines the graph from a matrix,
            N (bool): the number of the nodes in the graph,
            source (int): index the source node of the graph,
            sink (int): index the sink node of the graph.
            residualgraph(matrix):graph where the residual values 
                                  of the edges are updated after 
                                  each iteration.
        '''

        # se asigna dtype para numpy array
        DTYPE = np.intc
        

        self.graph = np.array(graph,dtype=DTYPE)
        self.N = len(self.graph)
        self.source = 0      
        self.sink= self.N-1
        self.maximum_flow =0
    
    def busq_anchura(self,unsigned int source,unsigned int sink,signed int[:] parent): 
        '''
        Defines queue of the visited nodes and the parents of them, and
        so long as the queue of the nodes that need to be visited is not empty, the algorithm goes on.
        
        Args:
            source (int): index the source node of the graph.
            sink (int): index the sink node of the graph.
            parent (array): vector for keeping track of the parents of visited nodes.
        Attributes:
            visit (array): vector for keeping track of visited nodes,
            queue (list): the queue of the nodes needed to be visited,
            parent (array): vector for keeping track of the parents of visited nodes.
        Returns:
            (bool): A True/False indicating the presence or absence of a path. 
            It also updates the parent list with the information necessary to reconstruct the path.
  
        '''
        # se inicia el vector de visit en 0 de acuerdo al nuemero de nodos
        cdef array.array v = array.array('i', [0]*(self.N))
        cdef signed int[:] visit  = v 
        
        # se inicia el vector queue vacio     
        queue=[]    
        # se agerga al vector queue el valor  de source y 
        # mediante source se asigna al primer espacio del vector visit en true 
        #para comenzar nuestra busqueda del path
        queue.append(source)              
        visit[source]=1               

        while queue:

            # se extrae siempre el primer valor del queue y se asigna a u
            u = queue.pop(0)
            
            # Se requiere tanto el index como el valor del nodo que sera padre
            for index, value in enumerate(self.graph[u]): 
                if visit[index]== 0 and value > 0:
                    queue.append(index)
                    visit[index] = 1
                    parent[index]=u

        # Se crea un check ternario para regresar True 
        # si el camino sido recorrido completamente False de lo contrario
        return True if visit[sink]==1 else False
  
    # metodo para ejecutar algoritmo de ford fulkerson
    def ford_fulkerson(self):
        '''
        Runs the Ford Fulkerson method, keeping and updating the residual graph 
        and running over the bfs function in all the nodes.
        Args:
            source (int): index the source node of the graph.
            sink (int): index the sink node of the graph.
        Attributes:
            graph (numpy array):matrix the residual graph,
            path_flow (float): we need to calculate the min flow of the selected path,
            parent (array): vector for keeping track of the parents of visited nodes.
        Returns:
            Print calculated maximum flow of the graph.
            
        '''

        # se inicia parent en -1 de acuerdo a la cantidad de nodos
        cdef array.array p = array.array('i', [-1]*(self.N))
        cdef signed int[:] parent = p

        cdef unsigned int v, j
        cdef signed int u
            
        while self.busq_anchura(self.source,self.sink,parent):
            # se inicia pathflow en inf float 
            # que contendra el minimo flujo del path seleccionado
            path_flow = float('inf')     
            j = self.sink                    
                
            while j != self.source:
                # se calcula el minimo de todo el path 
                path_flow=min(path_flow, self.graph[parent[j]][j])
                # se asigna el valor del nodo padre  
                j=parent[j]

            
            # se actualiza los valores residuales de los edges en self.residualgraph
            v = self.sink
            while v != self.source:
                u=parent[v]
                self.graph[u][v] -= path_flow                   
                self.graph[v][u] += path_flow
                v=parent[v]


            # se agrega el path_flow para calcular el maximo
            self.maximum_flow += path_flow  
            
        return print("maximun flow is",self.maximum_flow)
    
    def get_maximumflow(self):
        '''
        Get the Maximun flow of the graph, calculate tu algorithom
        Returns:
            maximum_flow (int): calculated maximum flow of the graph.
        '''
        return self.maximum_flow

    # metodo para obtener información del grafo
    def infoMF(self):
        '''
        Obtains the information of the graph, regarding to the number of nodes and arcs
        Args:
            grapf (matrix): defines the graph from a matrix.
        Returns:
            Printed info of the graph.
            
        '''
        # Función para contar nodos y ramas
        cdef unsigned int i=0, m=0, rama=0
        
        arreglo = self.graph
        for i in range(len(arreglo)):
            for m in range(len(arreglo[i])):
                if arreglo[i][m] == 0:
                    pass
                else:
                    rama = rama + 1
        print("nodos",len(arreglo))
        print("ramas",rama)
