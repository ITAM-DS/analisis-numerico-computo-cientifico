import numpy as np
import math
import pandas as pd
import networkx as nx
import random
import collections
import matplotlib.pyplot as plt

# Se ha utilizado documentación tipo docstring para funciones disponible en
# https://www.programiz.com/python-programming/docstrings
# https://peps.python.org/pep-0257/


def construye_matriz_adyacencias(columnaA,columnaB,pesos,N,nodos,base):
    '''
    Crea una matriz de adyacencias con base en una lista de aristas
            Parametros:
                    columnaA: Nombre en la tabla de la lista de nodos de origen
                    columnaB: Nombre en la tabla de la lista de destino
                    pesos: Nombre en la tabla de los pesos de cada arista
                    N: cantidad de nodos
                    nodos: Array con el nombre de los nodos
                    base: panda dataframe con los datos anteriores
            Regresa:
                    matriz: array con la matriz de adjacencia
    '''
    df1=np.zeros((N,N))
    matriz=pd.DataFrame(df1)
    matriz.columns=matriz.index=nodos
    
    for i in nodos:
        for j in nodos:
            matriz[i][j]=base[(base[columnaA]==i)&(base[columnaB]==j)][pesos]
    
    matriz = matriz.fillna(0)
    
    return matriz

def adj_matrix_2_edge_list(adj_matrix, index_name):
    '''
    Crea una lista de aristas a partir de una matriz de adyacencia. En esta versión de la funcion Esta función los nodos pares donde el peso es mayor a 0 se conservan, cuando el peso es igual a 0 se quitan para que funcione el algoritmo de Dijstra.
            Parametros:
                    adj_matrix: un array con la matriz
                    index_name: eje con los indices de la matriz
            Regresa:
                    matriz: array con la lista de aristas
    '''
    edge_list = []
    matrix_len= len(adj_matrix)
    for i in range(matrix_len):
        for j in range(matrix_len):
                if i==j:
                    pass
                elif adj_matrix[i][j]==0:
                    pass
                else:
                    edge_list.append((index_name[i],index_name[j],adj_matrix[i][j]))
    edge_list = tuple(edge_list) 
    return edge_list

def algoritmo_dijkstra(matriz,origen,destino):
    '''
    Calcula la ruta más corta entre dos nodos bajo el algoritmo dijkstra
            Parametros:
                    matriz: matriz de adyacencia
                    origen: nodo de origen
                    destino: nodo de destino
            Regresa:
                    ruta_final: un array con cada nodo que compone la ruta más corta en orden
    ''' 
    matrix = np.asarray(matriz.values)
    nodos = matriz.index

    edges_list=adj_matrix_2_edge_list(matrix, nodos)
    size = len(nodos)
    G = nx.Graph() 
    node_list = range(size)
    for node in node_list:
        G.add_node(node)
    G.add_weighted_edges_from(edges_list)
    
    ruta_final = nx.dijkstra_path(G, str(origen), str(destino))
    
    return ruta_final

################################Funciones Grafos###############################################

def adj_matrix_2_edge_list_1(adj_matrix):
    '''
    Crea una lista de aristas a partir de una matriz de adyacencia. Esta version de la función es para graficar el grafo.
            Parametros:
                    adj_matrix: un array con la matriz
            Regresa:
                    edge_list: array con la lista de aristas
    '''
    edge_list = []
    matrix_len= len(adj_matrix)
    for i in range(matrix_len):
        for j in range(matrix_len):
                if i==j:
                    pass
                else:
                    edge_list.append((i,j,adj_matrix[i][j]))
    edge_list = tuple(edge_list) 
    return edge_list


def plot_weighted_graph(matriz_adj):
    '''
    Toma una matriz de adj y crea el grafo con cada vertice proporcional al peso.
            Parametros:
                    adj_matrix: un array con la matriz
            Regresa:
                        : grafica el grafo con weighted edges
    '''
    edges_list=adj_matrix_2_edge_list_1(matriz_adj)
    # tamaño de la matriz
    size=max([row[0] for row in edges_list])+1
    
    # Creamos el objeto grafo y le indicamos la cantidad de nodos
    G = nx.Graph() 
    node_list = range(size)
    for node in node_list:
        G.add_node(node)
 
    # Indicamos que queremos una distribución simétrica y circular de los nodos
    # esto lo podemos cambiar a cualquier otra presentaciòn estética
    pos=nx.spring_layout(G)
    #nx.draw_networkx_nodes(G,pos,node_color='blue',node_size=300)
    # Graficamos las red
    # graficamos en un canvass amplio 
    plt.figure(6,figsize=(16,16)) 
    nx.draw(
    G, pos, edge_color='black', width=1, 
        linewidths=1, node_size=600, node_color='pink', 
        alpha=0.9,with_labels = True)
    
    # Agregamos los datos de los vertices y pesos
    G.add_weighted_edges_from(edges_list)
    
    # Ahora pintamos de manera iterativa cada vertice y su peso
    # a la par que normalizamos los pesos para que los vertices no nos salgan tan desproporcionados
    tupla_pesos = []
    for (node1,node2,data) in G.edges(data=True):
        tupla_pesos.append(data['weight']) #we'll use this when determining edge thickness
 
    pesos_unicos = list(set(tupla_pesos))
    for i in pesos_unicos:
        vertices_con_peso = [(node1,node2) for (node1,node2,edge_attr) in G.edges(data=True) if edge_attr['weight']==i]
        # normalizamos un poco los pesos para que la anchura sea proporcional a su peso
        # este *1 lo tenemos que aumentar cuando haya pocos nodos y disminuir cuando 
        # haya más por cuestiones esteticas
        anchura = i*len(node_list)*.75/sum(tupla_pesos)
        nx.draw_networkx_edges(G,pos,edgelist=vertices_con_peso,width=anchura)
 
    plt.axis('off')
    plt.title('Grafo con vertices proporcionales (valor abs)')
    plt.show() 

def plot_labeled_graph(matriz_adj):
    '''
    Toma una matriz de adj y crea el grafo con los pesos en etiquetas y no en el grafo en si.
            Parametros:
                    adj_matrix: un array con la matriz
            Regresa:
                        : grafica del grafo con weighted edges
    '''
    edges_list=adj_matrix_2_edge_list_1(matriz_adj)
    # tamaño de la matriz
    size=max([row[0] for row in edges_list])+1
    
    # Creamos el objeto grafo y le indicamos la cantidad de nodos
    G = nx.Graph() 
    node_list = range(size)
    for node in node_list:
        G.add_node(node)


    # Agregamos la lista de pesos en un diccionario para que sea fácil de interpretar por la función.

    G.add_weighted_edges_from(edges_list)
    edge_labels = dict([((n1, n2), round(d['weight'], 2))
                    for n1, n2, d in G.edges(data=True)])
    # graficamos en un canvass amplio 
    plt.figure(6,figsize=(16,16)) 

    # Indicamos que queremos una distribución simétrica y circular de los nodos
    # esto lo podemos cambiar a cualquier otra presentaciòn estética
    pos=nx.spring_layout(G)
    #pos = nx.spring_layout(G) #este lo activamos si queremos una gráfica asimétrica

    # Graficamos las red

    nx.draw(
    G, pos, edge_color='black', width=1, 
        linewidths=1, node_size=600, node_color='pink', 
        alpha=0.9,with_labels = True)
    # Graficamos las labels de los pesos
    nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels,font_size=10)
 
    plt.axis('off')
    plt.title('Grafo con etiquetas de pesos')
    plt.show()