#!/usr/bin/env python
# coding: utf-8

# # Índice de Incidencia Delictiva en México
# Se comparan 3 métodos para obtener el índice de incidencia delictiva en México, definido como el primer componente principal de la descomposición.
# 
# Los métodos revisados son:
# 
#     - PCA con SciKit Learn
#     - PCA y SVD con Numpy
#     - PCA con algoritmo QR 
#     
# Al final, se realiza un método iterativo para calcular el índice desde 2015 hasta 2021 (octubre) para cada entidad federativa y se almacena el resultado, insumo del [tablero](https://datastudio.google.com/reporting/e4ffda99-e143-4e69-9454-391ea1796dc6).

# In[1]: Librerías utilizadas

import numpy as np
import pandas as pd
from sklearn.decomposition import PCA
np.set_printoptions(formatter={'float_kind':'{:f}'.format})

# In[2]:  Carga de los datos
df = pd.read_csv('data/data_clean.csv')

# In[3]: # La comparación se realiza tomando como año base 2015.

X = df[df.fecha == 2015].drop(columns = ['fecha', 'estado'])
X = X.to_numpy() 

# In[4]: 1.    PCA con SKlearn

pca = PCA(n_components=28, svd_solver='full').fit(X)
z_skl = pca.transform(X)

# ## 2.   PCA a partir de SVD con Numpy
# In[7]: SVD Numpy

U, S, Vt = np.linalg.svd(X, full_matrices= False, compute_uv= True)

# In[9]:  PCA Numpy

z_np = S*U

# ## 3.   PCA a partir de SVD con algoritmo QR
# In[11]: Funciones definidas por el equipo

def givens_rotation(A):
    (r, c) = np.shape(A)
    Q = np.identity(r)
    R = np.copy(A)
    (rows, cols) = np.tril_indices(r, -1, c)
    for (row, col) in zip(rows, cols):
        if R[row, col] != 0:  # Q = 1, s = 0, r, q sin cambios
            r_ = np.hypot(R[col, col], R[row, col])  # d
            c = R[col, col]/r_
            s = -R[row, col]/r_
            G = np.identity(r)
            G[[col, row], [col, row]] = c
            G[row, col] = s
            G[col, row] = -s
            R = np.dot(G, R)  # R=G(n-1,n)*...*G(2n)*...*G(23,1n)*...*G(12)*A
            Q = np.dot(Q, G.T)  # Q=G(n-1,n).T*...*G(2n).T*...*G(23,1n).T*...*G(12).T
    return (Q, R)


# In[12]:

#Algoritmo QR para matrices simetricas (version simple)
def algoritmoQR(matrix):
    #T0
    T_k_minus_1 = matrix
    q,r = givens_rotation(matrix)
    m,n = q.shape
    Q = np.eye(m,n)
    T_k = r@q 
    #Q es la matriz que aproximará a los eigenvectores
    Q = Q@q
    n = 100 # Número de iteraciones
    while n > 0:
        T_k_minus_1 = T_k
        q,r = givens_rotation(T_k_minus_1)
        Q = Q@q
        #T_k es la matriz que aproxima a nuestros eigenvalores
        T_k = r@q
        n = n - 1
    
    return np.diag(T_k), Q

# In[13]: SVD QR
eigenvalores_u, eigenvectores_u = algoritmoQR(X@X.T) #U

# In[14]:
U_qr = pd.DataFrame(eigenvectores_u).iloc[:,0:28]

# In[15]:
D_qr = np.sqrt(eigenvalores_u[eigenvalores_u > 0.000001])

# In[16]: PCA QR

z_qr = D_qr*U_qr

# ## Comparación de resultados

# # Cálculo de índice para todos los años
# In[20]: Con QR

ind_qr = pd.DataFrame(index = df[df.fecha==2015]['estado'])
for i in df.fecha.unique():
    print('Seleccionamos año: '+str(i))
    mat = df[df.fecha==i].drop(columns=['fecha','estado'])
    print('Aplicamos función Algortimo QR a datos estandarizados')
    mat2 = mat.to_numpy()
    print('Obtenemos U')
    eigenvalores_u, eigenvectores_u = algoritmoQR(mat2@mat2.T) #U
    U = pd.DataFrame(eigenvectores_u).iloc[:,0:28]
    print('Calculamos D')
    D = np.sqrt(eigenvalores_u)[:-4]
    print("Obtenemos Z'")
    Z = D*U
    print("Seleccionamos la primera columna de Z como índice")
    print('Almacenamos')
    ind_qr[i] = -Z.iloc[:,0].values #ajuste de signos primer componente
    print('***')

# In[21]: Con  Numpy


ind_np = pd.DataFrame(index = df[df.fecha==2015]['estado'])
for i in df.fecha.unique():
    print('Seleccionamos año: '+str(i))
    X = df[df.fecha==i].drop(columns=['fecha','estado'])
    X = X.to_numpy()    
    print('Aplicamos SVD con Numpy a datos estandarizados')
    U, S, Vt = np.linalg.svd(X, full_matrices= False, compute_uv= True)
    Z = S*U
    print("Seleccionamos la primera columna de Z como índice")
    print('Almacenamos')
    ind_np[i] = pd.DataFrame(Z).iloc[:,0].values
    print('***')


# ### Comparación de índices

# Las cifras de los índices de todos los años coinciden entre los dos métodos.

# In[22]: #QR
ind_qr

# In[38]: #Numpy
ind_np

