import numpy as np
import pandas as pd

# Función basada en la de Wikipedia- Power Iteration (https://en.wikipedia.org/w/index.php?title=Power_iteration&oldid=957783806)
def power_iteration(A, num_simulations: int):
    """
    Función basada en la de Wikipedia- Power Iteration (https://en.wikipedia.org/w/index.php?title=Power_iteration&oldid=957783806)
    
    Función que implementa el método de la potencia  
    params: A:			matriz (en nuestro caso, la de covarianzas)
            num_simulations:      número de iteraciones a realizar    
    
    
    return:     m_k		Eigenvector dominante
                b_k		Eigenvector correspondiente

    """
    # Ideally choose a random vector
    # To decrease the chance that our vector
    # Is orthogonal to the eigenvector
    b_k = np.random.rand(A.shape[1])

    for _ in range(num_simulations):
        # calculate the matrix-by-vector product Ab
        b_k1 = np.dot(A, b_k)

        # calculate the norm
        b_k1_norm = np.linalg.norm(b_k1)

        # re normalize the vector
        b_k = b_k1 / b_k1_norm
    
    #Obtenemos el eigenvalor correspondiente a b_k con el cociente de Rayleigh
    m_k = (b_k.T@A@b_k)/(b_k.T@b_k)
    
    #Devolvemos el mayor eigenvalor y su correspondiente eigenvector
    return m_k,b_k
	
	
def power_deflation(A,iter):
    """
    Función que itera el método de la potencia, mediante deflation de Hotteling  
    params: A:			matriz (en nuestro caso, la de covarianzas)
            iter:      número de iteraciones a realizar    
    
    
    return:     eigenvalues		Numpy array con los eigenvectores de A
                eigenvectors	Numpy array con los correspondientes eigenvectores de A 

    """
    #numero de columnas
    n = A.shape[1]
    # Inicializamos arrays de ceros
    eigenvalues = np.zeros(n)
    eigenvectors = np.zeros((n,n))
    #Hago una copia de la matriz original
    A_def = A.copy()
    #Iteramos tantas veces como columnas de la matriz
    for i in range(n):
        #Aplicamos el método de la potencia
        m_def,b_def = power_iteration(A_def,iter)
        #Actualizamos los arrays de eigen valores y vectores
        eigenvalues[i] = m_def
        eigenvectors[:,i]= b_def
        # Matriz actualizada
        A_def = A_def - np.outer(b_def,b_def)@A_def@np.outer(b_def,b_def)
    return eigenvalues, eigenvectors
	
