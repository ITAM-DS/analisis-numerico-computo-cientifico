#!/usr/bin/env python
# coding: utf-8

import codecs
import sys

import sklearn as sk
import pandas as pd
import numpy as np 
import math

from sklearn import preprocessing
from sklearn.decomposition import PCA

from src.pca.algoritmo_QR import eigenvectores_eigenvalores_QR_vf
from src.pca.metodo_potencia_deflation import power_iteration
from src.pca.metodo_potencia_deflation import power_deflation


def PCA_from_sklearn(X):
    """
    componentes_principales(X): Función que devuelve las componentes principales.
    
    Parámetros
    ----------
    n_components: número de componentes. 
    svd_solver: str {‘auto’, ‘full’, ‘arpack’, ‘randomized’}
        Se elige 'full', lo que significa que se ejecuta completamente SVD llamando al 
        solucionador estándar LAPACK a través de scipy.linalg.svd y se seleccionan los componentes mediante postprocessing.
        
    Atributos
    ---------
    varianza_explicada: porcentaje de varianza explicada por cada componente.
    valores_singulares: valores singulares correspondientes a cada componente.
    pca.components_: ejes principales que representan las direcciones de máxima varianza en los datos.
    eigenvalues: son los valores propios utilizando la matriz de covarianza.
    
    Método
    ---------
    fit_transform: ajusta el modelo a los datos y aplica la reducción de dimensionalidad en los datos.
    """
    X = pd.DataFrame(X)
    n_components = len(X.columns)
    pca_1 = PCA(n_components, svd_solver='full')
    componentesprincipales_1 = pca_1.fit_transform(X)
    pca_1.components_
    var_exp = pca_1.explained_variance_ratio_
    
    ##Se obtiene el número de componentes a través de la varianza explicada acumulada de los componentes, la cual debe sumar 60%.
    var_acumulada = var_exp.cumsum()
    conteo = (var_acumulada)  <  0.8
    n_componentes = conteo.sum() + 1
    pca = PCA(n_componentes, svd_solver='full')
    componentesprincipales = pca.fit_transform(X)
    pca.components_
    varianza_explicada = pca.explained_variance_ratio_
    eigenvalues = pca.explained_variance_
    val_sing = pca.singular_values_
    
    return pca, varianza_explicada, componentesprincipales, val_sing, pca.components_, eigenvalues


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
    return valores_singulares[:num_componentes], componentes[:num_componentes], Z[:,:num_componentes], varianza_explicada[:num_componentes]


def PCA_from_SVD_jacobi(A):
    """
    Función para PCA a partir de la SVD 
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
    
    # Modificar esta línea de código, mandar a llamar la función creada por el equipo 
    # Calcular SVD
    U, S, Vt = svd_jacobi_aprox(A_centered,1e-12,500)
    
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
    return valores_singulares[:(num_componentes)], componentes[:(num_componentes)], Z[:,:(num_componentes)], varianza_explicada[:(num_componentes)]


def PCA_from_QR_vf(data,niter = 450):
    """
    Función para PCA a partir de los eigenvectores  
    params: data:			matriz de datos
            niter:      número de iteraciones máximas    
    
    
    return:     componentes		Los coeficientes para calcular los componentes principales (eigenvectores de la matriz de covarianzas)
                Z			Los datos transformados (componentes principales)
                varianza_explicada	La varianza explicada por cada componente principal
    
    Depende de la función: eigenvectores_QR
    """
    
    # convertir a array
    A = np.array(data)
    
    # Centrar los datos
    mean_vec = np.mean(A, axis=0)
    datos_centrados = (A - mean_vec)

    # Matriz de Covarianzas
    #C = (datos_centrados.T@datos_centrados)/(datos_centrados.shape[0]-1)
    C = (A - mean_vec).T.dot((A - mean_vec)) / (A.shape[0]-1)
    
    # Calcular algoritmo QR
    E, Q = eigenvectores_eigenvalores_QR_vf(C,niter)
    
    
    # Los componentes (coeficientes)
    componentes = Q.T
    
    # Los datos transformados (componentes principales)
    # Aquí marcaba error al filtrar porque no se reconocia a Z como numpy array
    Z = datos_centrados@Q
    
    # La varianza explicada
    varianza_explicada = E/np.sum(E)
    
    # Calcula número de componentes de manera automatica de acuerdo a la variana explicada
    # Threshold de 60%
    n = data.shape[1] #numero de columnas
    varianza_acumulada = varianza_explicada.cumsum()
    conteo = (varianza_acumulada)  <  0.8
    num_componentes = conteo.sum() + 1
    
    # regresar 4 objetos
    return E[:num_componentes], componentes[:num_componentes], Z[:,:num_componentes], varianza_explicada[:num_componentes] #, varianza_acumulada, num_componentes

def PCA_from_potencia(X):
    """
    Función que calcula PCA a partir del método de la potencia y deflation de Hotteling  
    params: A:			matriz de datos
    
    
    return:     eigenvalues		Numpy array con los eigenvectores de A
                eigenvectors	Numpy array con los correspondientes eigenvectores de A 
    
    """
    
    prop = 0 # Proporción de varianza explicada
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