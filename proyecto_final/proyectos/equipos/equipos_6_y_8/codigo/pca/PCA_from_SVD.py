import numpy as np
import pandas as pd


def PCA_from_SVD(A):
    """
    Función para PCA a partir de la SVD de numpy 
    params: A			matriz de datos
            num_componentes 	número de componentes deseados

    return: valores_singulares	Los valores singulares de la descomposición SVD
	    componentes		Los coeficientes para calcular los componentes principales
	    Z			Los datos transformados (componentes principales)
	    varianza_explicada	La varianza explicada por cada componente principal
    """
    
    # Centrar los datos
    A = np.array(A) # convertir los datos a un numpy array por si vienen de un DataFrame
    A_centered = A - A.mean(axis=0)
    
    # Calcular SVD
    U, S, Vt = np.linalg.svd(A_centered, full_matrices=False)
    
    # Los valores singulares
    valores_singulares = S
    
    # Los componentes (coeficientes)
    componentes = ((Vt))
    
    # Los datos transformados (componentes principales)
    Z = A_centered@np.transpose(Vt)
    
    # La varianza explicada
    varianza_explicada = S**2/np.sum(S**2)
    
    # Calcula número de componentes de manera automatica de acuerdo a la variana explicada
    # Threshold de 60%
    n = A.shape[1] #numero de columnas
    varianza_acumulada = varianza_explicada.cumsum()
    conteo = (varianza_acumulada)  <  0.8
    num_componentes = conteo.sum() + 1
    
    # regresar 4 objetos
    return valores_singulares[:num_componentes], componentes[:num_componentes].T, Z[:,:num_componentes], varianza_explicada[:num_componentes]

