"""
Módulo para generar pagerank con método de la potencia, qr y networkx
"""

import numpy as np
import pandas as pd
from scipy.sparse import csr_matrix

# Para los grafos
import networkx as nx
import matplotlib.pyplot as plt
from networkx.algorithms.link_analysis.pagerank_alg import google_matrix, pagerank


def create_4_pages():
    """

    :return:
    """
    pages_links = pd.DataFrame(columns=['pagina', 'outlinks'])
    pages_links['pagina'] = ['A', 'B', 'C', 'D']
    pages_links['outlinks'][0] = ['C', 'B']
    pages_links['outlinks'][1] = ['D']
    pages_links['outlinks'][2] = ['A', 'B', 'D']
    pages_links['outlinks'][3] = ['C']

    return pages_links


def plot_node_graph(dataframe_pages, power_method=None, with_labels=False):
    """
    Plotea el grafo
    :param[in] dataframe_pages: dataframe de nx2
                El dataframe debe contener una columna llamada página y otra llamada outlinks;
                donde outlinks contenga una lista de los outlinks por página
    """
    nodos = dataframe_pages['pagina']

    plt.figure(figsize=(10,10))
    G = nx.DiGraph()

    for nodo in nodos:
        G.add_node(nodo)

    for page, outlinks in zip(dataframe_pages['pagina'], dataframe_pages['outlinks']):
        for outlink in outlinks:
            G.add_edge(page, outlink)

    pos = nx.spring_layout(G)


    nx.draw_networkx_nodes(G, pos, node_color='#a0a88a', node_size=400)
    if with_labels:
        labels = {}
        for node in G.nodes():
            if node in power_method:
                #set the node name as the key and the label as its value
                labels[node] = "{}:{}".format(node,round(power_method[node],2))
        nx.draw_networkx_labels(G, pos, labels=labels, font_weight="bold")
    else:
        nx.draw_networkx_labels(G, pos)
    nx.draw_networkx_edges(G, pos, edge_color='#305029', width=1.8, arrows = True, style='dashed')

    plt.show()
    return G


def get_h_matrix(dataframe_pages):
    """
    Obtiene la matriz H, la matriz estocástica
    :param[in] dataframe_pages: dataframe de nx2
                El dataframe debe contener una columna llamada página y otra llamada outlinks;
                donde outlinks contenga una lista de los outlinks por página
    """
    sparseMatrix = csr_matrix((len(dataframe_pages), len(dataframe_pages)),
                          dtype = np.float).toarray()
    newdf = pd.DataFrame(sparseMatrix, columns = dataframe_pages['pagina'], index=dataframe_pages['pagina'])
    count = 0
    for page, outlinks in zip(dataframe_pages['pagina'],dataframe_pages['outlinks']):
        score = 1/len(outlinks)
        dict_page = {page: np.zeros(len(dataframe_pages))}
        for outlink in outlinks:
            newdf[page][outlink] = score
    H = newdf.to_numpy()
    return H


def power_method_pagerank(dataframe_pages, H, iteraciones):
    """
    Obtiene el pagerank
    :param[in] dataframe_pages: dataframe de nx2
                El dataframe debe contener una columna llamada página y otra llamada outlinks;
                donde outlinks contenga una lista de los outlinks por página
    :param[in] H: Matriz estocástica
    :param[in] iteraciones: número de iteraciones a realizar

    :return power_method: Un diccionario con la página como llave y el pagerank como valor
    """
    # Obtenemos nuestro vector inicial
    v = np.ones(len(dataframe_pages))
    v = v * 1 / len(v)

    # Iteramos
    H = np.linalg.matrix_power(H, iteraciones)
    v_n = H @ v

    # Convertimos a dataframe
    print(v_n.shape)
    df = pd.DataFrame(v_n.T, columns=['pagerank'])

    df['nodo'] = dataframe_pages['pagina']

    df = df.set_index('nodo')

    power_method = df.pagerank.to_dict()

    return power_method


def power_method_opt_pagerank(dataframe_pages, H, iteraciones):
    """
    Obtiene el pagerank
    :param[in] dataframe_pages: dataframe de nx2
                El dataframe debe contener una columna llamada página y otra llamada outlinks;
                donde outlinks contenga una lista de los outlinks por página
    :param[in] H: Matriz estocástica
    :param[in] iteraciones: número de iteraciones a realizar

    :return power_method: Un diccionario con la página como llave y el pagerank como valor
    """
    # Obtenemos nuestro vector inicial
    v = np.ones(len(dataframe_pages))
    v = v * 1 / len(v)

    n = len(v)
    q_k = v
    q_k = q_k.reshape(n, 1)
    max_iter = iteraciones

    for k in range(max_iter):
        z_k = H @ q_k
        q_k = z_k / np.linalg.norm(z_k)
        lambda_k = q_k.T @ H @ q_k

    # Convertimos a dataframe
    df = pd.DataFrame(q_k, columns=['pagerank'])

    df['nodo'] = dataframe_pages['pagina']

    df = df.set_index('nodo')

    power_method_opt = df.pagerank.to_dict()

    return power_method_opt

def round_dict_2_digits(dictionary):
    """
    Redondea el valor del diccionario a 2 digitos
    :param dictionary:
    :return:
    """
    # Redondeamos a 2 dígitos
    power_method_round = {}

    for node in dictionary:
        if node in dictionary:
            # set the node name as the key and the label as its value
            power_method_round[node] = round(dictionary[node], 2)

    return power_method_round

def sign(x):
    """
    Helper function for computing sign of real number x.
    """
    if x >= 0:
        return 1
    else:
        return -1


def inverse_matrix(A):
    """
    Helper function for computing the inverse of matrix A nxn.
    """
    inv_temp = []

    for i in range(0, A.shape[0]):
        e1 = np.zeros((A.shape[0], 1))
        e1[i] = 1
        A_inv_i = np.linalg.solve(A.T, e1)
        inv_temp.append(A_inv_i)

    for j in range(0, len(inv_temp) - 1):
        if j == 0:
            r_inv = np.row_stack((inv_temp[j].T, inv_temp[j + 1].T))
        else:
            r_inv = np.row_stack((r_inv, inv_temp[j + 1].T))

    return (r_inv)


def off(T):
    """
    Helper function for computing off(T).
    """
    mask = np.ones(T.shape, dtype=bool)
    np.fill_diagonal(mask, 0)
    T_sin_dig = T[mask]
    sum = 0
    for i in range(0, len(T_sin_dig)):
        # print (T_sin_dig[i])
        sum += T_sin_dig[i] ** 2
    off_T = np.sqrt(sum)

    return (off_T)


def QR_Householder(A):
    """
    Decompose a real square matrix A where: A = QR usign Householder reflections.
    Args:
        A (numpy ndarray): Matrix in which QR algorithm will be performed.
    Returns:
        Q (numpy ndarray): orthogonal matrix (its columns are orthogonal unit vectors meaning
                            Q.TQ = QQ.T = I)
        R (numpy ndarray): upper triangular matrix.
    """
    a_aux = []

    for j in range(0, A.shape[0] - 1):  # Asumimos que A SIEMPRE será cuadrada
        e = np.zeros((A.shape[0] - j, 1))
        e[0] = 1
        if j == 0:
            v = A[:, 0] + sign(A[0, 0]) * np.linalg.norm(A[:, 0]) * e.T[0]
            beta = 2 / v.dot(v)
            aux = A[:, 0:] - beta * np.outer(v, v.dot(A[:, 0:]))
            a_aux.append(aux)
        else:
            v = aux[1:, 1] + sign(aux[1, 1]) * np.linalg.norm(aux[1:, 1]) * e.T[0]
            beta = 2 / v.dot(v)
            aux = aux[1:, 1:] - beta * np.outer(v, v.dot(aux[1:, 1:]))
            a_aux.append(aux)

    n, n = A.shape
    count = 0

    if n == 2:
        R = a_aux[0]
    else:
        for h in range(n - 2, 0, -1):
            if count == 0:
                temp_col = np.column_stack((np.zeros(2 + count), a_aux[h]))
            else:
                temp_col = np.column_stack((np.zeros(2 + count), temp_row))
            temp_row = np.row_stack((a_aux[h - 1][0, 0:], temp_col))
            count += 1
        R = temp_row
    R_inv = inverse_matrix(R)

    Q = A @ R_inv

    return (Q, R)


def Eig_Householder(A):
    """
    Compute QR algorithm usign Householder reflections multiple times to approximate eigenvalues and
    eigenvectors of A.
    Args:
        A (numpy ndarray): Symmetric matrix
    Returns:
        evalues (numpy ndarray): Array with eigenvalues of matrix A.
        evectors (numpy ndarray): Matrix with eigenvectors of matrix A on its columns.
    """
    tol = 10e-8
    max_iters = 2000
    tk_fro_norm = np.linalg.norm(A, 'fro')
    iterations = 0
    off_Tk = off(A)

    q_aux = []

    while off_Tk > tol * tk_fro_norm and iterations < max_iters:
        iterations += 1
        if iterations == 1:
            Tk_minus1 = A
        else:
            Tk_minus1 = Tk

        q, r = QR_Householder(Tk_minus1)
        q_aux.append(q)

        Tk = r @ q

        off_Tk = off(Tk)
        tk_fro_norm = np.linalg.norm(Tk, 'fro')

    # Multiplicación Q0*Q1...Qn para cálculo de eigenvectores
    for g in range(0, len(q_aux) - 1, 1):
        if g == 0:
            q_temp = q_aux[g] @ q_aux[g + 1]
        else:
            q_temp = q_temp @ q_aux[g + 1]

    if iterations == 0:
        evalues = "error"
        evectors = "error"
    else:
        evectors = q_temp
        evalues = np.diag(Tk)

    return (evalues, evectors)


def main():
    """

    :return:
    """
    # Creamos los datos
    pages_4_dataframe = create_4_pages()

    # Obtenemos el grafo
    G_4 = plot_node_graph(pages_4_dataframe, power_method=None, with_labels=False)
    # Obtenemos la matriz estocástica de adyacencia
    H_4 = get_h_matrix(pages_4_dataframe)
    # Tendría que ser similar a la matriz de Google
    google_matrix_4 = google_matrix(G_4, nodelist=pages_4_dataframe.pagina)
    A_4 = google_matrix_4.T

    # Obtenemos los eigenvalores y eigenvectores
    eigval_4, eigvec_4 = Eig_Householder(H_4)

    #Obtenemos y comparamos con linalg
    eigval_eig_4, eigvec_eig_4 = np.linalg.eig(H_4)

    # Probamos con el método de la potencia adaptado
    power_method_4 = power_method_pagerank(pages_4_dataframe, A_4, iteraciones=100)
    power_method_4 = round_dict_2_digits(power_method_4)

    # Probamos con el método de la potencia visto en optimización
    power_method_opt_4 = power_method_opt_pagerank(pages_4_dataframe, H_4, iteraciones=100)

    # Obtenemos el page rank con networkx
    pageranknx_4 = pagerank(G_4, max_iter=20)
    pageranknx_4 = round_dict_2_digits(pageranknx_4)

    comparison_table = pd.DataFrame({"Pagina": pageranknx_4.keys(),
                                     "NX PageRank": pageranknx_4.values(),
                                         "Potencia PR": power_method_4.values(),
                                         "Potencia OPT-2020": power_method_opt_4.values(),
                                         "LinAlg": eigvec_eig_4[:, 0].real,
                                         "QR_Eq4": eigvec_4[:, 0]}
                                        ).reset_index().iloc[:, 1:]
    print(comparison_table)

    G4_pot = plot_node_graph(pages_4_dataframe, power_method=power_method_4, with_labels=True)

