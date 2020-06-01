#!/usr/bin/env python
# coding: utf-8

import codecs
import sys
import numpy as np


def PCA_from_QR_vf(data,niter):
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
    #return E, componentes, Z, varianza_explicada, varianza_acumulada, num_componentes
