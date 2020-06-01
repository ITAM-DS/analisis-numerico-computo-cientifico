import numpy as np
import pandas as pd

def PCA_from_potencia(X):
	"""
    Función que calcula PCA a partir del método de la potencia y deflation de Hotteling  
    params: A:			matriz de datos
    
    
    return:     eigenvalues		Numpy array con los eigenvectores de A
                eigenvectors	Numpy array con los correspondientes eigenvectores de A 

    """
    prop = 0 #Proporción de varianza explicada
    comp = 1 
    cur_var = 0
    comp_vecs = np.zeros([X.shape[1], X.shape[1]])
    
    # convertir a array
    A = np.array(X)
    
    # Centrar los datos
    mean_vec = np.mean(A, axis=0)
    datos_centrados = (A - mean_vec)
    
    #Calculamos la matriz de covarianzas
    cov = np.dot(X.T, X)/X.shape[0]
    
    #Aplicamos el método de la potencia
    evalues_pow, evectors_pow = power_deflation(cov,2000)
    
    # La varianza explicada
    varianza_explicada = evalues_pow/np.sum(evalues_pow)
    
    # Los datos transformados (componentes principales)
    Z = datos_centrados@evectors_pow
    
    
    # Calcula número de componentes de manera automatica de acuerdo a la variana explicada
    # Threshold de 80%
    n = X.shape[1] #numero de columnas
    varianza_acumulada = varianza_explicada.cumsum()
    conteo = (varianza_acumulada)  <  0.8
    num_componentes = conteo.sum() + 1
    
    return evalues_pow[:num_componentes], evectors_pow.T[:num_componentes], Z[:,:num_componentes], varianza_explicada[:num_componentes]  