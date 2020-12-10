"""
Módulo para generar pagerank con datos de Stanford
Datos obtenidos de: http://snap.stanford.edu/data/web-Stanford.txt.gz
"""

import pandas as pd
import numpy as np

from networkx.algorithms.link_analysis.pagerank_alg import google_matrix, pagerank, power_method_pagerank, \
    round_dict_2_digits, power_method_opt_pagerank

from pagerank import plot_node_graph, get_h_matrix, Eig_Householder

# Datos obtenidos de: http://snap.stanford.edu/data/web-Stanford.txt.gz
path = "../data/web-Stanford.txt"

def transform_data(df_stanford):
    """
    Transform the nodes that are not in the FromNode and ToNode match
    This only works for 103 nrows
    """
    missing_from = list(set(df_stanford['FromNode']) - set(df_stanford['ToNode']) )
    missing_to = list(set(df_stanford['ToNode'])  - set(df_stanford['FromNode']) )
    mitad = int(len(missing_to)/2)
    for val in missing_to[:mitad]:
        df_stanford['ToNode'][df_stanford['ToNode'] == val] = missing_from[0]
    for val in missing_to[mitad:]:
        df_stanford['ToNode'][df_stanford['ToNode'] == val] = missing_from[1]

    return df_stanford

def read_csv_Stanford(path, nrow=103):
    """
    Read the txt given, only works for web-Stanford
    """
    df = pd.read_csv(path, nrows=nrow)#, usecols=['FromNode', 'ToNode'])
    # Remove the index
    df = df[3:]
    df = df.rename(columns = {'# Directed graph (each unordered pair of nodes is saved once): web-Stanford.txt ':
                         'FromTo'})
    df[['FromNode','ToNode']] = df.FromTo.str.split('\t',expand=True)
    df = df.drop('FromTo', axis=1)
    return df


def main():
    df_stanford = read_csv_Stanford(path, 103)
    df_stanford = transform_data(df_stanford)

    # Hacemos una agrupación y la lista de los outlinks
    paginas_stanford = df_stanford.groupby('FromNode').aggregate(lambda tdf: tdf.unique().tolist()).reset_index()

    paginas_stanford = paginas_stanford.rename(columns={'FromNode': 'pagina',
                                                        'ToNode': 'outlinks'})

    # Obtenemos el grafo
    G = plot_node_graph(paginas_stanford, power_method=None, with_labels=False)
    # Obtenemos la matriz estocástica de adyacencia
    H = get_h_matrix(paginas_stanford)
    # Tendría que ser similar a la matriz de Google
    google_matrix_4 = google_matrix(G, nodelist=paginas_stanford.pagina)
    A = google_matrix_4.T

    # Obtenemos los eigenvalores y eigenvectores
    #eigval, eigvec = Eig_Householder(H)

    # Obtenemos y comparamos con linalg
    eigval_eig, eigvec_eig = np.linalg.eig(H)

    # Probamos con el método de la potencia adaptado
    power_method = power_method_pagerank(paginas_stanford, A, iteraciones=100)
    power_method = round_dict_2_digits(power_method)

    # Probamos con el método de la potencia visto en optimización
    power_method_opt = power_method_opt_pagerank(paginas_stanford, A, iteraciones=100)

    # Obtenemos el page rank con networkx
    pageranknx = pagerank(G, max_iter=20)
    pageranknx = round_dict_2_digits(pageranknx)

    comparison_table = pd.DataFrame({"Pagina": pageranknx.keys(),
                                     "NX PageRank": pageranknx.values(),
                                     "Potencia PR": power_method.values(),
                                     "Potencia OPT-2020": power_method_opt.values(),
                                     "LinAlg": eigvec_eig[:, 0].real}
                                     #"QR_Eq4": eigvec[:, 0]}
                                    ).reset_index().iloc[:, 1:]
    print(comparison_table)

    G_pot = plot_node_graph(paginas_stanford, power_method=power_method, with_labels=True)