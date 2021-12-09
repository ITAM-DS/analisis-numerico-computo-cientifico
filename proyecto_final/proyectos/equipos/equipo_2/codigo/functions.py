import numpy as np
import math

def vect_ini(col):
    """
    Se construye el vector que servira para ceros en las entradas 
    debajo de la primera entrada de la primera columna de la matriz A
    Args:
        col: tamaño del vector
    Regresa:
        vector con 1 en la primera posición y elementos cero en las demás posiciones
    """
    e1 = a = np.zeros(col)
    e1[0] = 1
    return e1

def factorizacion_qr_hh(A):
    """
    Calcula la factorización QR de una matriz usando las refexiones de housholder
    Args:
        A (Matrix): matriz a obtener una matriz superior
    Regresa:
        Q (Matrix): matriz Q
        R (Matrix): matriz R
    """
    # Declaracón de lista a utilizar para guardar a las partes esenciales del vector de Householder y las betas.
    l_betas = []
    l_v_Householder = []
    # Se obtienen las dimensiones de la matriz de entrada
    row, col = A.shape
    # Se construye el vector que servira para ceros en las entradas debajo de la primera columna de la matriz A
    e1 = vect_ini(row)
    # Obteniendo el vector housholder y las betas, y almacenando iterativamente
    # Primera columna
    v = A[:,0] - np.linalg.norm(A[:,0])*e1
    beta = 2/v.dot(v)
    l_betas.append(beta)
    l_v_Householder.append(v)
    # Modificando el primer renglón de la matriz
    Aux = []
    Aux.append(A[:,0:]-beta*np.outer(v,v.dot(A[:,0:])))
    # Columnas subsecuentes    
    for i in range(0, row-2):
        e1 = vect_ini(row-i-1)
        v = Aux[i][1:,1] + np.linalg.norm(Aux[i][1:,1])*e1
        beta = 2/v.dot(v)
        l_betas.append(beta)
        l_v_Householder.append(v)
        Aux.append(Aux[i][1:,1:]-beta*np.outer(v,v.dot(Aux[i][1:,1:])))
        
    # Colocando renglones y columnas para tener a la matriz A(5). 
    # Para esto combinamos columnas y renglones en numpy con column_stack y row_stack:
    A5 = []
    num = len(Aux)
    #print('num:',num)
    number_of_zeros = (row-(len(l_betas)-1))     
    A5.append(np.column_stack((np.zeros(number_of_zeros), Aux[num-1])))
    
    for i in range(0, row-2):
        A5.append(np.row_stack((Aux[num-(2+i)][0, 0:], A5[(len(A5)-1)])))
        number_of_zeros = (row-(len(l_betas)-(2+i)))
        A5.append(np.column_stack((np.zeros(number_of_zeros), A5[(len(A5)-1)]))) 
       
    # Pintando R
    indx = len(A5)    
    R = []    
    # Si es cuadrada
    if(row == col):
        A5.append(np.row_stack((Aux[0][0, 0:], A5[(indx-2)])))
        
    R = A5[(indx-2)]
    
    # Obteniendo Q
    Q_Householder = np.eye(row)
    m = row
    for j in range(col-(len(l_betas)-2),-1,-1):
        v = l_v_Householder[j]
        Q_Householder[j:row, j:row] = Q_Householder[j:row, j:row] - l_betas[j]*np.outer(v, v.dot(Q_Householder[j:row,j:row]))
    
    return Q_Householder, R


def frobeniusNorm(A):    
    """
    Obtiene Norma Frobenius sin la diagonal
    Args:
        A (Matrix): matriz Q
    Regresa:
        off (float): norma Frobenius sin la diagonal off(A)
    """
    s = 0
    m,n = A.shape
    for j in range(m):
        for k in range(n):
            if(j != k):
                s = s + abs(A[j, k])**2;
    return math.sqrt(s)


# Encontrando eigenvalores y Eigenvectores
def eigen_val_vec(A, iteraciones):
    """
    Obtiene eigenvalores y eigenvectores
    Args:
        A (Matrix): matriz Q
        iteraciones (Entero): número de iteracciones a aplicar como condición de paro
    Regresa:
        Lambda (Matrix): matriz que contiene en su diagonal con eigevalores
        X (Matrix): matriz de eigenvectores 
    """
    X = np.eye(A.shape[0])
    T = A.copy()
    tol = 0.00000001
    off = frobeniusNorm(T)
    max_iters = iteraciones
    iterations = 0
    # Criterio de paro while off(T_k) > tol ||T_k||_F && iterations < max_iters
    while off > tol and iterations < max_iters:
        Q,R = factorizacion_qr_hh(T)
        X = X @ Q
        T = R @ Q
        off = frobeniusNorm(T)
        iterations = iterations+1
    #print('iterations: ',iterations)
    #print('off: ',off)
    return T, X

