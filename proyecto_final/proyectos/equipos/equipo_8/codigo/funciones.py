#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Dec  2 16:17:52 2021

@author: goriminaur
"""

import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from decimal import *
import math

def approx_eigval_max(matriz_covarianza,max_iters):
    z_k_minus_1=[]
    eigen_val_ant=1
    eigen_val=0
    k=0
    #Se crea una lista que contenga el número de columnas = al número de renglones de la matriz
    #de covarianzas -1 y al final se agrega un uno para seguir el algoritmo de la potencia
    for i in range(len(matriz_covarianza)):
        if i+1==len(matriz_covarianza):
            z_k_minus_1.append(1)
        else: 
            z_k_minus_1.append(0)
    # A partir del número máximo de iteraciones se crea un ciclo para aproximar el eigenvalor
    while (k <=max_iters) and (abs(Decimal(eigen_val)-Decimal(eigen_val_ant))>=1e-4):
        eigen_val_ant=eigen_val
        z_k=matriz_covarianza@z_k_minus_1
        #Se normaliza el vector utilizando la norma cuadrada
        eigen_vec=z_k/np.linalg.norm(z_k)
        z_k_minus_1=eigen_vec
        #Se genera el eigen valor utilizando el vector resultante y la matriz original
        eigen_val=eigen_vec.T@matriz_covarianza@eigen_vec
        
        k=k+1 
    return eigen_val,eigen_vec,matriz_covarianza


#Método de Deflation
def approx_eigval_min_1(matriz_covarianza,max_iters,eigen_val_1,eigen_vec_1):
    z_k_minus_1=[]
    eigen_val_ant=1
    eigen_val=0
    k=0
    #Se crea una lista que contenga el número de columnas = al número de renglones de la matriz
    #de covarianzas -1 y al final se agrega un uno para seguir el algoritmo de la potencia
    for i in range(len(matriz_covarianza)):
        if i+1==len(matriz_covarianza):
            z_k_minus_1.append(1)
        else: 
            z_k_minus_1.append(0)
    #Para el método de deflaition se elimina el primer eigenvalor de la matriz y la resultante
    # es una matriz que contine los eigenvalores {0,l2,l3...}
    x1=eigen_vec_1
    x1=x1.reshape(len(matriz_covarianza),1)
    u1=eigen_val_1*x1
    matriz_covarianza=matriz_covarianza-x1@u1.T
    #Se genera un nuevo ciclo para calcular el segundo eigenvalor a partir del método potencia
    while (k <=max_iters) and (abs(Decimal(eigen_val)-Decimal(eigen_val_ant))>=1e-4):
        eigen_val_ant=eigen_val
        z_k=matriz_covarianza@z_k_minus_1
        #Se normaliza el vector utilizando la norma cuadrada
        eigen_vec=z_k/np.linalg.norm(z_k)
        z_k_minus_1=eigen_vec
        #Se genera el eigen valor utilizando el vector resultante y la matriz original
        eigen_val=eigen_vec.T@matriz_covarianza@eigen_vec
        k=k+1
    return eigen_val,eigen_vec,matriz_covarianza

def lectura_graficas(archivo_csv):
    datos=pd.read_csv(archivo_csv)
    return datos

def normalizar(dataframe):
    medias = dataframe.mean(axis = 0)
    desv = dataframe.std(axis = 0)
    datos_norm = (dataframe - medias) / desv
    return datos_norm

def graficas_sin_normalizar(datos):
    for i in datos.columns:
        plt.plot(datos[i], label=str(i))
    plt.legend(loc="lower center", bbox_to_anchor=(1.15, 0.35))
    plt.title("Indices sin normalizar")
    plt.xlabel("Observación")
    plt.ylabel("Cotización en bolsa (USD)")
    plt.show()
    
def graficas_normalizadas(datos):
    datos_norm=normalizar(datos)
    for i in datos_norm.columns:
        plt.plot(datos_norm[i], label=str(i))
    plt.legend(loc="lower center", bbox_to_anchor=(1.15, 0.35))
    plt.title("Indices normalizados")
    plt.xlabel("Observación")
    plt.ylabel("Cotización en bolsa (USD)")
    plt.show()
def graficas_PCA(datos):
    for i in datos.columns:
        if (i=="PCA"):
            plt.plot(datos[i],'r+', label=str(i),)
        else:
            plt.plot(datos[i], label=str(i))
    plt.legend(loc="lower center", bbox_to_anchor=(1.15, 0.35))
    plt.title("Indices con PCA")
    plt.xlabel("Observación")
    plt.ylabel("Cotización en bolsa (USD)")
    plt.show()
def componente(sigma,eigen_val):
    j=0
    Acumulada=eigen_val.sum()
    acumulado=0
    componente_necesario=0
    while (j in range(len(sigma)) and acumulado<=.80):
        acumulado=acumulado+eigen_val[j]/Acumulada
        componente_necesario=j+1
        j+=1
    return acumulado, componente_necesario
