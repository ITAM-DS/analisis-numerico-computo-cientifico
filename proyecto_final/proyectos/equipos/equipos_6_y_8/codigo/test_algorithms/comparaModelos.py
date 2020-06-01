import pandas as pd 
import numpy as np 
from pathlib import Path


from src.pca import todoJunto
from src.test_algorithms.err_relativo import err_relativo


def compara_resultados_sk_np(A):
    """
    compara_resultados_sk_np: compara resultados de las funciones PCA_from_sklearn y PCA_from_SVD
    
    Función que compara los resultados de las funciones PCA_from_sklearn y PCA_from_SVD, 
    y regresa la información en forma de un pandas data frame.
    
    Parameters
    ----------
    A - sección de los datos a la que se aplicará PCA
    
    Returns
    ---------
    Dataframe con comparación y errores relativos 
    
    
    """    
    
    # PCA de scikit learn
    pca, var_exp, comp_prin, val_sing, pca_coef, eigenvalues = todoJunto.PCA_from_sklearn(A)

    # PCA a partir de SVD de numpy
    np_val_sing, np_pca_coef, np_comp_prin, np_var_exp = todoJunto.PCA_from_SVD(A)


    coef_iguales = np.allclose(pca_coef,np_pca_coef)
    err_coef = err_relativo(pca_coef, np_pca_coef)
    
    var_exp_igual = np.allclose(var_exp,np_var_exp)
    err_var_exp = err_relativo(var_exp, np_var_exp)

    comp_iguales = np.allclose(comp_prin,np_comp_prin)
    err_comp = err_relativo(comp_prin, np_comp_prin)
    
    val_sing_igual = np.allclose(val_sing, np_val_sing)
    err_val_sing = err_relativo(val_sing, np_val_sing)

    data_a_comparar = {'elemento':['varianza explicada','valores singulares', 'coeficientes', 'componentes principales'],
                     'Igualdad':[var_exp_igual,val_sing_igual,coef_iguales,comp_iguales],
                     'Max error relativo': [np.amax(err_var_exp),np.amax(err_val_sing),np.amax(err_coef),np.amax(err_comp)],
                     'Error relativo':[err_var_exp, err_val_sing, err_coef, err_comp]}

    
    comparativa = pd.DataFrame(data=data_a_comparar)
    
    
    return comparativa

def compara_resultados_abs_sk_np(A):
    """
    compara_resultados_abs_sk_np: compara resultados de las funciones PCA_from_sklearn y PCA_from_SVD, ignorando el signo
    
    Función que compara los  que resultan de aplicar las funciones PCA_from_sklearn y PCA_from_SVD, 
    sin tomar en cuenta el signo en los coeficientes y componentes principales, 
    y regresa la información en forma de un pandas data frame.
    
    Parameters
    ----------
    A - sección de los datos a la que se aplicará PCA
    
    Returns
    ---------
    Dataframe con comparación y errores relativos 
    
    
    """    
    
    # PCA de scikit learn
    pca, var_exp, comp_prin, val_sing, pca_coef, eigenvalues = todoJunto.PCA_from_sklearn(A)

    # PCA a partir de SVD de numpy
    np_val_sing, np_pca_coef, np_comp_prin, np_var_exp = todoJunto.PCA_from_SVD(A)
    

    var_exp_igual = np.allclose(var_exp,np_var_exp)
    err_var_exp = err_relativo(var_exp, np_var_exp)

    val_sing_igual = np.allclose(val_sing, np_val_sing)
    err_val_sing = err_relativo(val_sing, np_val_sing)

    coef_abs_iguales = np.allclose(np.abs(pca_coef),np.abs(np_pca_coef))
    err_coef_abs = err_relativo(np.abs(pca_coef),np.abs(np_pca_coef))

    comp_abs_iguales = np.allclose(np.abs(comp_prin),np.abs(np_comp_prin))
    err_comp_abs = err_relativo(np.abs(comp_prin), np.abs(np_comp_prin))


    data_a_comparar = {'elemento':['varianza explicada','valores singulares','coeficientes', 'componentes principales'],
                     'Igualdad (en valor absoluto)':[var_exp_igual,val_sing_igual,coef_abs_iguales, comp_abs_iguales],
                     'Max error relativo (con valor absoluto)': [np.amax(err_var_exp),np.amax(err_val_sing),np.amax(err_coef_abs),np.amax(err_comp_abs)],
                     'Error relativo (con valor absoluto)':[err_var_exp, err_val_sing,err_coef_abs, err_comp_abs]}


    comparativa = pd.DataFrame(data=data_a_comparar)
    
    return comparativa



def compara_resultados_abs_sk_qr(A):
    """
    compara_resultados_abs_sk_qr: compara resultados de las funciones PCA_from_sklearn y PCA_from_QR
    
    Función que compara los resultados de las funciones PCA_from_sklearn y PCA_from_QR, 
    y regresa la información en forma de un pandas data frame.
    
    Parameters
    ----------
    A - sección de los datos a la que se aplicará PCA
    
    Returns
    ---------
    Dataframe con comparación y errores relativos 
    
    
    """    
    
    # PCA de scikit learn
    pca, var_exp, comp_prin, val_sing, pca_coef, eigenvalues = todoJunto.PCA_from_sklearn(A)

    # PCA a partir de algoritmo QR
    qr_eigenvalues, qr_pca_coef, qr_comp_prin, qr_var_exp = todoJunto.PCA_from_QR_vf(A)

    try:
        # if len(val_sing) == len(qr_val_sing):
        var_exp_igual = np.allclose(var_exp,qr_var_exp)
        err_var_exp = err_relativo(var_exp, qr_var_exp)

        eigen_igual = np.allclose(np.abs(eigenvalues), np.abs(qr_eigenvalues))
        err_eigen = err_relativo(np.abs(eigenvalues), np.abs(qr_eigenvalues))

        coef_abs_iguales = np.allclose(np.abs(pca_coef),np.abs(qr_pca_coef))
        err_coef_abs = err_relativo(np.abs(pca_coef),np.abs(qr_pca_coef))

        comp_abs_iguales = np.allclose(np.abs(comp_prin),np.abs(qr_comp_prin))
        err_comp_abs = err_relativo(np.abs(comp_prin), np.abs(qr_comp_prin))

    except:
        print('Nota: Los resultados son de distinta longitud y por lo tanto se comparan solo las entradas en común')
        min_len = min(len(eigenvalues),len(qr_eigenvalues))
        var_exp_igual = np.allclose(var_exp[:min_len],qr_var_exp[:min_len])
        err_var_exp = err_relativo(var_exp[:min_len], qr_var_exp[:min_len])

        eigen_igual = np.allclose(np.abs(eigenvalues)[:min_len], np.abs(qr_eigenvalues)[:min_len])
        err_eigen = err_relativo(np.abs(eigenvalues)[:min_len], np.abs(qr_eigenvalues)[:min_len])

        coef_abs_iguales = np.allclose(np.abs(pca_coef[:min_len]),np.abs(qr_pca_coef[:min_len]))
        err_coef_abs = err_relativo(np.abs(pca_coef[:min_len]),np.abs(qr_pca_coef[:min_len]))

        comp_abs_iguales = np.allclose(np.abs(comp_prin[:,:min_len]),np.abs(qr_comp_prin[:,:min_len]))
        err_comp_abs = err_relativo(np.abs(comp_prin[:,:min_len]), np.abs(qr_comp_prin[:,:min_len]))
        
             
    data_a_comparar = {'elemento':['varianza explicada','eigenvalores','coeficientes', 'componentes principales'],
                     'Igualdad (en valor absoluto)':[var_exp_igual,eigen_igual,coef_abs_iguales, comp_abs_iguales],
                     'Max error relativo (con valor absoluto)': [np.amax(err_var_exp),np.amax(err_eigen),np.amax(err_coef_abs),np.amax(err_comp_abs)],
                     'Error relativo (con valor absoluto)':[err_var_exp, err_eigen,err_coef_abs, err_comp_abs]}

    
    comparativa = pd.DataFrame(data=data_a_comparar)
    
    
    return comparativa


def compara_resultados_abs_sk_potencia(A):
    """
    compara_resultados_abs_sk_qr: compara resultados de las funciones PCA_from_sklearn y PCA_from_potencia
    
    Función que compara los resultados de las funciones PCA_from_sklearn y PCA_from_potencia, 
    y regresa la información en forma de un pandas data frame.
    
    Parameters
    ----------
    A - sección de los datos a la que se aplicará PCA
    
    Returns
    ---------
    Dataframe con comparación y errores relativos 
    
    
    """    
    
    # PCA de scikit learn
    pca, var_exp, comp_prin, val_sing, pca_coef, eigenvalues = todoJunto.PCA_from_sklearn(A)

    # PCA a partir del método de la potencia
    pow_eigenvalues, pow_pca_coef, pow_comp_prin, pow_var_exp = todoJunto.PCA_from_potencia(A)

    try:
        # if len(val_sing) == len(pow_val_sing):
        var_exp_igual = np.allclose(var_exp,pow_var_exp)
        err_var_exp = err_relativo(var_exp, pow_var_exp)

        eigen_igual = np.allclose(np.abs(eigenvalues), np.abs(pow_eigenvalues))
        err_eigen = err_relativo(np.abs(eigenvalues), np.abs(pow_eigenvalues))

        coef_abs_iguales = np.allclose(np.abs(pca_coef),np.abs(pow_pca_coef))
        err_coef_abs = err_relativo(np.abs(pca_coef),np.abs(pow_pca_coef))

        comp_abs_iguales = np.allclose(np.abs(comp_prin),np.abs(pow_comp_prin))
        err_comp_abs = err_relativo(np.abs(comp_prin), np.abs(pow_comp_prin))

    except:
        print('Nota: Los resultados son de distinta longitud y por lo tanto se comparan solo las entradas en común')
        min_len = min(len(eigenvalues),len(pow_eigenvalues))
        var_exp_igual = np.allclose(var_exp[:min_len],pow_var_exp[:min_len])
        err_var_exp = err_relativo(var_exp[:min_len], pow_var_exp[:min_len])

        eigen_igual = np.allclose(np.abs(eigenvalues)[:min_len], np.abs(pow_eigenvalues)[:min_len])
        err_eigen = err_relativo(np.abs(eigenvalues)[:min_len], np.abs(pow_eigenvalues)[:min_len])

        coef_abs_iguales = np.allclose(np.abs(pca_coef[:min_len]),np.abs(pow_pca_coef[:min_len]))
        err_coef_abs = err_relativo(np.abs(pca_coef[:min_len]),np.abs(pow_pca_coef[:min_len]))

        comp_abs_iguales = np.allclose(np.abs(comp_prin[:,:min_len]),np.abs(pow_comp_prin[:,:min_len]))
        err_comp_abs = err_relativo(np.abs(comp_prin[:,:min_len]), np.abs(pow_comp_prin[:,:min_len]))
        
             
    data_a_comparar = {'elemento':['varianza explicada','eigenvalores','coeficientes', 'componentes principales'],
                     'Igualdad (en valor absoluto)':[var_exp_igual,eigen_igual,coef_abs_iguales, comp_abs_iguales],
                     'Max error relativo (con valor absoluto)': [np.amax(err_var_exp),np.amax(err_eigen),np.amax(err_coef_abs),np.amax(err_comp_abs)],
                     'Error relativo (con valor absoluto)':[err_var_exp, err_eigen,err_coef_abs, err_comp_abs]}

    
    comparativa = pd.DataFrame(data=data_a_comparar)
    
    
    return comparativa