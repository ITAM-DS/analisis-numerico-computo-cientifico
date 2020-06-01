#!/usr/bin/env python
# coding: utf-8

import codecs
import sys
import numpy as np

from src.pca.funciones_examen_QR import matriz_Q_R	

def eigenvectores_eigenvalores_QR_vf(data,niter,tolerancia = 10**-8):
    """
    Función para obtener los eigenvectores y eigenvalores de una matriz cualquiera
    params: data			matriz de datos
            niter: número de iteraciones máximas 
    
    
    return:     eigenvalores 
                eigenvalores 
                
    Depende de las funciones ue calculan la factorización QR
    """

    # convertir a array
    A = np.array(data)
    
    # La matriz de covarianza ya es simetrica, no necesitamos rellenar columnas de ceros
    # Completamos la matriz A con columnas de ceros para que sea cuadrada
    n, p = A.shape
    columnas = n - p
    ceros = np.zeros((n,columnas))
    
    # Matriz inicial
    A0 = np.append(A, ceros, axis = 1)
    # Factorización inicial
    Qk,Rk =matriz_Q_R(A0)
    
    # Hacer una copia de la matriz Q inicial
    Q = Qk.copy()
    
    valor = 10
    
    #iniciamos ciclo
    for i in range(niter):
        
        #Definimos la nueva Ak+1
        Ak = Rk@Qk
        #calculamos la factorización QR sobre la nueva Ak
        Qk,Rk =matriz_Q_R(Ak)
        
        # Actualizar la matriz Q
        Q = Q@Qk
        
        
        # Se usan los valores distintos de la diagonal para corroborar la tolerancia deseada
        valor = np.sum(np.abs(Qk)) - np.trace(np.abs(Qk))
        
        
        # Detener si se logra la tolerancia deseada
        # Notar que en esta primera prueba no se está actualizando  el valor que checa la tolerancia
        if (valor<tolerancia):
            print("se alcanzo la torelacia deseada")
            break
    
    #se acaba el for
    
    #La diagonal de Ak nos regresa los eigenvalores
    eigenvalores = np.diagonal(Ak)
        
    return eigenvalores, Q
