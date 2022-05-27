from collections import defaultdict

class MaxFlowAeiu:
    '''
        Finds the paths in order to return the maximum flow in the
        network. This class implements the Ford Fulkerson method.
    '''

    def __init__(self,graph):
        '''
        Initialices parts of the problem.
        Attributes:
            graph (matrix): defines the graph from a matrix,
            N (bool): the number of the nodes in the graph,
            source (int): index the source node of the graph,
            sink (int): index the sink node of the graph.
            residualgraph(matrix):graph where the residual values 
                                  of the edges are updated after 
                                  each iteration.
        '''
        self.graph = graph
        self.N = len(graph)
        self.source = 0      
        self.sink= self.N-1
        self.residualgraph = self.graph
    
    def busq_anchura(self,source,sink,parent): 
        '''
        Defines queue of the visited nodes and the parents of them, and
        so long as the queue of the nodes that need to be visited is not empty, the algorithm goes on.
        
        Args:
            source (int): index the source node of the graph.
            sink (int): index the sink node of the graph.
            parent (list): vector for keeping track of the parents of visited nodes.
        Attributes:
            visit (list): vector for keeping track of visited nodes,
            queue (list): the queue of the nodes needed to be visited,
            parent (list): vector for keeping track of the parents of visited nodes.
        Returns:
            (bool): A True/False indicating the presence or absence of a path. 
            It also updates the parent list with the information necessary to reconstruct the path.
  
        '''
        # se inicia el vector de visit en False de acuerdo al nuemero de nodos 
        visit=[False]*(self.N)
        # se inicia el vector queue vacio     
        queue=[]    

        # se agerga al vector queue el valor  de source y 
        # mediante source se asigna al primer espacio del vector visit en true 
        #para comenzar nuestra busqueda del path
        queue.append(source)              
        visit[source]=True               

        while queue:

            # se extrae siempre el primer valor del queue y seb asigna a u
            u = queue.pop(0)
            
            # Se requiere tanto el index como el valor del nodo que sera padre
            for index, value in enumerate(self.graph[u]): 
                if visit[index]== False and value > 0:
                    queue.append(index)
                    visit[index] = True
                    parent[index]=u
        
        # Se crea un check ternario para regresar True 
        # si el camino sido recorrido completamente False de lo contrario
        return True if visit[sink] else False


    # metodo para ejecutar algoritmo de ford fulkerson
    def ford_fulkerson(self):
        '''
        Runs the Ford Fulkerson method, keeping and updating the residual graph 
        and running over the bfs function in all the nodes.
        Args:
            source (int): index the source node of the graph.
            sink (int): index the sink node of the graph.
        Attributes:
            residualgraph (matrix):matrix the residual graph,
            path_flow (float): we need to calculate the min flow of the selected path,
            parent: vector for keeping track of the parents of visited nodes.
        Returns:
            maximum_flow (float): calculated maximum flow of the graph.
            
        '''
        # se inicia parent en -1 de acuerdo a la cantidad de nodos
        parent=[-1]*(self.N)

        # se inicia maximun_flow en 0
        maximum_flow=0
            
        while self.busq_anchura(self.source,self.sink,parent):
            # se inicia pathflow en inf float 
            # que contendra el minimo flujo del path seleccionado
            path_flow = float('inf')     
            j = self.sink                    
                
            while not j == self.source:
                # se calcula el minimo de todo el path 
                path_flow=min(path_flow, self.residualgraph[parent[j]][j])
                # se asigna el valor del nodo padre  
                j=parent[j]

            
            # se actualiza los valores residuales de los edges en self.residualgraph
            v = self.sink
            while not v == self.source:
                u=parent[v]
                self.residualgraph[u][v] -= path_flow                   
                self.residualgraph[v][u] += path_flow
                v=parent[v]


            # se agrega el path_flow para calcular el maximo
            maximum_flow += path_flow  
            
        return maximum_flow
        
    
    
        
        
        
