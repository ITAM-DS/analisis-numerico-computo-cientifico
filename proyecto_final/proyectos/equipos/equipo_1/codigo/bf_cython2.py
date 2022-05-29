import numpy as np 
def bf_negative_cycle_cc(graph, node_ini=None, distance_ini=np.inf):
    """
    Description
    -------
    
    Get the shortest path using the Bellman-Ford algorithm with C compilation, 
    modify parameters monitoring: initial node and initial distance
    
    param:
    -------
    
    G : Networkx DiGraph. The input graph.
    node_ini : Optional parameter, indicate begining node
    distance_ini : Deafault value is inf
    
    returns
    -------
    
    list
        A list with the shortest path.   
    """
    
    assert distance_ini>=1, f"La distancia inicial debe de ser mayor o igual a 1. El parámetro fue igual a {distance_ini}"
    
    n_nodes = len(graph.nodes)
    
    if node_ini is not None:
        assert node_ini <= n_nodes, f"El nodo definido es mayor a los del grafo. Deberia de ser menor a {n_nodes}."
        n_nodes = node_ini
                    
    n = n_nodes + 1
    # Remove nan borders inside graph
    edges = [edge for edge in graph.edges().data() if ~np.isnan(edge[2]['weight'])]

    # Add a start node and add zero weighted edges to all other nodes
    for i in range(n-1):
        edges.append((n-1, i, {'weight': 0}))
        
    # Initialize distances of nodes and predecessors
    # https://codingdeekshi.com/initialize-an-array-in-python/
    distance= [distance_ini ]*n
    distance[n_nodes] = 0  
    predecessors = [-1]*n 
    
    for i in range(n):  
        x = -1
        for edge in edges:
            if distance[int(edge[0])] + edge[2]['weight'] < distance[int(edge[1])]:                
                distance[int(edge[1])] = distance[int(edge[0])] + edge[2]['weight']
                predecessors[int(edge[1])] = int(edge[0])
                x = int(edge[1])
        if x == -1:  # If relaxation is not possible, there is no negative cycle
            return None
        
    # Identify negative cycle
    for i in range(n):
        x = predecessors[int(x)]
    cycle = []
    v = x
    while True:
        cycle.append(int(v))
        if v == x and len(cycle) > 1:
            break
        v = predecessors[int(v)]
        
       
    return list(reversed(cycle))
