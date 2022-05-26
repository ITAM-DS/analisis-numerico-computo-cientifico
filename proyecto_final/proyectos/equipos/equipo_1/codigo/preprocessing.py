import pandas as pd
import numpy as np 
from datetime import date
import random
import networkx as nx
import matplotlib.pyplot as plt

class data_to_graph():
    def __init__(
        self,
        path_to_file='../data/historical_data.csv',
        size=100,
        date=date.today().strftime("%Y-%m-%d"),
        price='Open',
        max_spread_pct=0.05
    ):
        self.path_to_file = path_to_file
        self.size = size
        self.date = date
        self.price = price
        self.max_spread_pct = max_spread_pct

    def get_graph(self):
        '''
        Pipeline to get graph object
        param:
            dataframe
        return:
            dataframe
        '''
        self.read_data()
        self.filter_data()
        self.exchange_rate_matrix()
        self.log_transformed_rep()
        self.build_graph()
        
        return self
    
    def read_data(self):
        '''
        Read data from file
        param:
            dataframe
        return:
            dataframe
        '''
        self.data = pd.read_csv(self.path_to_file)
        return self
    
    def filter_data(self):
        '''
        Filter data
        param:
            dataframe
        return:
            dataframe
        '''
        self.read_data()
        df = self.data.copy()
        df_date = df[df['Date'] == self.date]
        
        assert (df_date.shape[0] != 0), 'No hay datos para esa fecha'
        
        df_date = df_date[
            df_date[self.price] > 0
        ]
        
        if(self.size == None):
            self.filter_data = df_date
        else:
    
            self.filter_data = df_date.sample(
                n = self.size
            )
        
        self.filter_data = self.filter_data.reset_index()[
                [
                    "ticker", 
                    self.price
                ]
            ].rename(
                columns = {
                    "ticker":'Símbolo',
                    self.price:'Precio'
                }
            )
        
        return self
    
    def exchange_rate_matrix(self):
        """
        Exchange Rate Matrix Representation
        param:
            dataframe
        return:
            dataframe
        """
        n = self.filter_data.shape[0]

        c1 = self.filter_data[['Precio']].copy()
        aux = c1.copy()
        random.seed(10)
        for i in range(n):
            c1[i] = aux/c1.loc[i]['Precio'] *(1+random.uniform(0,self.max_spread_pct))
            
        c1.drop(columns=['Precio'],inplace=True)
        for i in range(len(c1.index)):
            for j in range(len(c1.columns)):
                if i==j:
                    c1.loc[i,j] = 1
        self.exchange_rate_matrix = c1
        
        return self
    
    def log_transformed_rep(self):
        """
        Log-Transformed Representations
        param:
            dataframe
        return:
            dataframe
        """

        self.log_exchange_rate_matrix = np.round(-np.log(self.exchange_rate_matrix),2)
        
        return self
    
    def build_graph(self):
        """
        Crea grafo a partir de los datos de cripomonedas y precio
        param:
            dataframe
        return:
            grafo
        """
        n = self.log_exchange_rate_matrix.shape[0]

        edge = []
        # Covert to format to use a graph
        for i in range(n):
            for j in range(n):
                if (i != j):
                    edge.append([str(i), str(j), self.log_exchange_rate_matrix.loc[i][j]])

        G = nx.DiGraph()        
        G.add_weighted_edges_from(edge)
        self.graph = G

        return self


def get_data(data_dir, date=date.today().strftime("%Y-%m-%d"), tam_data=100, price='Open'):
    """
    Obtiene datos de un directorio de una fecha dada
    param:
    data_dir: directorio de datos
    date: fecha a analizar, por default toma la fecha actual si no se especifica
    tam_data: analiza cierto tamaño del dataset de forma aleatoria, por default son 100 monedas a analizar
    price: selecciona con que precio se hará el ejercicio(High,Low,Open,Close), por default es Open
    return:
    dataframe: con datos especificados
    """
    df = pd.read_csv(data_dir)
    df_date = df[df['Date']==date]
    df_date = df_date[df_date[price] > 0]
              
    if(tam_data == None):
        df_random = df_date       
    else:
        df_random = df_date.sample(n = tam_data)
    
    df_random = df_random.reset_index()
    data = df_random[["ticker", price]]
    data.columns = ['Símbolo', 'Precio']
    
    
    return data

def exchange_rate_matrix(data):
    """
    Exchange Rate Matrix Representation
    param:
        dataframe
    return:
        dataframe
    """
    n = data.shape[0]

    max_spread_pct = 0.05 # maximum bid-ask spread in pct of bid, 0.05 for 5%

    c1 = data[['Precio']]
    aux = c1.copy()
    random.seed(10)
    for i in range(n):
        c1[i] = aux/c1.loc[i]['Precio']*(1+random.uniform(0,max_spread_pct))
        
    c1.drop(columns=['Precio'],inplace=True)
    
    for i in range(len(c1.index)):
        for j in range(len(c1.columns)):
            if i==j:
                c1.loc[i,j] = 1    
    return c1

def log_transformed_rep(data):
    """
    Log-Transformed Representations
    param:
        dataframe
    return:
        dataframe
    """
    
    df_ln = np.round(-np.log(data),2)
    return df_ln

def create_grap(data):
    """
    Crea grafo a partir de los datos de cripomonedas y precio
    param:
        dataframe
    return:
        grafo
    """
    df = exchange_rate_matrix(data)
    df_ln = log_transformed_rep(df)
    
    n = df_ln.shape[0]
    
    edge = []
    # Covert to formatto use un graph
    for i in range(n):
        for j in range(n):
            if (i != j):
                edge.append([str(i), str(j), df_ln.loc[i][j]])

    G = nx.DiGraph()        
    G.add_weighted_edges_from(edge)
    
    return G

def show_graph(G):
    """
    Graph Representation
    param:
        Graph
    return:
        Plot
    """
    pos = nx.spring_layout(G,k=10)

    nx.draw(G, pos, with_labels=True)
    nx.draw_networkx_edge_labels(G,
                                 pos,
                                 edge_labels={(u, v): d for u, v, d in G.edges(data="weight")},
                                 label_pos=.66)
    plt.show()
