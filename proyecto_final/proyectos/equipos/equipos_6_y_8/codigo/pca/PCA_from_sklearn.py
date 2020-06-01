# -*- coding: utf-8 -*-
"""
Created on Thu May 21 02:59:13 2020

@author: Elizabeth
"""

import sklearn as sk
import pandas as pd
import numpy as np 
import math

from sklearn import preprocessing
from sklearn.decomposition import PCA


def componentes_principales(X):
    """
    componentes_principales(X): Función que devuelve los componentes principales.
    
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
    
    var_exp_ratio = pca_1.explained_variance_ratio_
    
    ##Se obtiene el número de componentes a través de la varianza explicada acumulada de los componentes, la cual debe sumar 80%.
    
    var_acumulada = var_exp_ratio.cumsum()
    
    conteo = (var_acumulada)  <  0.8
    
    n_componentes = conteo.sum() + 1
    
    pca = PCA(n_componentes, svd_solver='full')
    
    componentesprincipales = pca.fit_transform(X)
    
    pca.components_
    
    varianza_explicada = pca.explained_variance_ratio_
    
    eigenvalues = pca.explained_variance_
    
    val_sing = pca.singular_values_


    return pca, varianza_explicada, var_exp_ratio, componentesprincipales, val_sing, pca.components_, eigenvalues



















