#!/usr/bin/env python
# coding: utf-8

#========================================================
# Funciones empleadas para la implementación del proyecto
#========================================================

import math
import numpy as np
import pandas as pd
from sklearn.preprocessing import OneHotEncoder
import seaborn as sns
import sys
import matplotlib.pyplot as plt
import adds
import pprint

from adds import pretty_output
import adds

# Text attributes
BOLD = '\033[1m'
out = pretty_output()

# Functions
def sigmoide(z):
    '''
    
    Función que devuelve el sigmoide de un vector
    
        - Parámetros:
        
            -- z (vec): vector numérico de m entradas
        
        - Salidas
        
            -- sig (vec): vector númerico de m entradas, cada entrada tiene 
        
                         un valor entre -1 y 1
    '''
    # Se revisa que los parámetros de entrada sean congruentes con la funcionalidad
    if type(z) is not np.ndarray:
        sys.exit('Error: la entrada debe ser de tipo numpy.ndarray')
        
    sig = 1/(1+ np.exp(-z))
    
    return sig
    
def calc_mu(X,beta):
    '''
    
    Función que calcula la media para una variable aleatoria con distribución bernoulli.
    
        - Parámetros:
        
            -- X (mat): matriz de mxp entradas
            
            -- beta (vec): vector con p entradas
            
        - Salidas
        
            -- mu (vec): vector de m entradas
    '''
    a = np.matmul(beta,np.transpose(X))
    mu = sigmoide(a)

    return mu
    
def f(X,y,beta):
    '''
    
    Función que computa la log-verosimilitud negativa
    
        - Parámetros:
    
            -- X (mat): matriz de mxp entradas

            -- y (vec): vector de de m entradas de la variable output

            -- beta (vec): vector de p entradas

        - Salidas
    
            -- lvn (int): log-verosimilitud negativa
    '''
    
    
    # Se revisa que los parámetros de entrada sean congruentes con la funcionalidad
    m,p = X.shape
    if y.shape[0]!= m:
        sys.exit('Error:  El número de renglones de X debe ser igual al número de entradas del vector y.')
    if beta.shape[0]!= p:
        sys.exit('Error:  El número de columnas de X debe ser igual al número de entradas del vector beta.')

    prob = calc_mu(X,beta)
    # Log-verosimilitud negativa 
    lvn = -sum(y*np.log(prob)+(1-y)*(np.log(1-prob)))
    return lvn

def gradiente_f(X,y,beta):
    '''
    
    Función que calcula el gradiente asociado la log-verosimilitud negativa del 
    
    problema de regresión logística
    
        ** Parámetros:
        
            - X (mat): matriz de mxp entradas
            
            - y (vec): vector de de m entradas de la variable output
            
            - beta (vec): vector de p entradas
        
        ** Salidas
        
            - grad (vec): vector de m entradas
    '''
        
    # Se revisa que los parámetros de entrada sean congruentes con la funcionalidad
    m,p = X.shape
    if y.shape[0]!= m:
        sys.exit('Error:  El número de renglones de X debe ser igual al número de entradas del vector y.')
    if beta.shape[0]!= p:
        sys.exit('Error:  El número de columnas de X debe ser igual al número de entradas del vector beta.')

    mu = calc_mu(X,beta)    
    grad = np.matmul(np.transpose(X), mu-y)    
    return grad


def hessiana_f(X,y,beta):
    '''
    
    Función que calcula la matriz Hessiana asociada a la log-verosimilitud negativa del 
    
    problema de regresión logística
    
        ** Parámetros:
        
            - X (mat): matriz de mxp entradas
            
            - y (vec): vector de de m entradas de la variable output
            
            - beta (vec): vector de p entradas
        
        ** Salidas
        
            - hes (vec): vector de m entradas
    '''
    # Se revisa que los parámetros de entrada sean congruentes con la funcionalidad
    m,p = X.shape
    if y.shape[0]!= m:
        sys.exit('Error:  El número de renglones de X debe ser igual al número de entradas del vector y.')
    if beta.shape[0]!= p:
        sys.exit('Error:  El número de columnas de X debe ser igual al número de entradas del vector beta.')

    mu = calc_mu(X,beta)
    S = np.diag(mu*(1-mu))
    hes = np.matmul(np.transpose(X),np.matmul(S,X))
    return hes

def normalize(x):
    '''
    
    Función que normaliza un vector
    
        ** Parametros:
    
            - x: vector a normalizar
    
        ** Salidas:
    
            - norm : vector x normalizado
    '''
    # Se revisa que los parámetros de entrada sean congruentes con la funcionalidad
    if type(x) is not np.ndarray:
        sys.exit('Error: la entrada debe ser de tipo numpy.ndarray')
         
    norm = x/np.sqrt(sum(x*x))
    return norm

def clasifica(X, beta_hat,limit=0.5):
    '''
    
    Función que clasifica la ocurrencia de probabilidades en dos grupos.
    
    Emplea el parámetro límite para delimitar si se clasifica en el grupo 0 o 1.
    
        ** Parámetros:
        
            - X (mat): matriz de mxp entradas
            
            - beta_hat (array): optimized parameter
            
            - limit (float64): 0<limit<1: Threshold for each classification
            
        
        ** Salidas:
        
            - yhat: array of classifed data
    '''
    # Se revisa que los parámetros de entrada sean congruentes con la funcionalidad
    if type(X) is not np.ndarray or type (beta_hat) is not np.ndarray:
        sys.exit('Error: X y beta_hat deben ser de tipo numpy.ndarray')
    if limit > 1 or limit < 0:
        sys.exit('Error:  limit es un paramétro que debe estar entre 0 y 1')       
    
    mu = calc_mu(X,beta_hat)
    yhat = mu
    yhat[mu<limit] = 0
    yhat[mu>=limit] = 1
    return yhat


def descent_direction(X, y, beta, method="max",H=None):
    '''
    
    Función que devuelve vector normalizado (px1) que apunta en la direccion de decenso
    
        ** Parámetros:
        
            - X (mat): matriz de mxp entradas

            - y (vec): vector de de m entradas de la variable output

            - beta (vec float64): vector de entradas a optimizar

            - method (str): método que determina la dirección de descenso
    
                    --Opciones:
    
                            --- max: método de descenso
                            
                            --- newton: método de Newton
                            
                            --- bfsg: metodo bfsg
                            
            - H (mat pxp): Parámetro para la dirección de decenso del metodo bfgs
    
        ** Salidas
    
            - pk (vec): vector normalizado con la direccion del paso
    '''
    if(method == "max"):
        pk = gradiente_f(X,y,beta)
    
    elif(method == "newton"):
        grad = gradiente_f(X,y,beta)
        hess = hessiana_f(X,y,beta)
        pk = np.linalg.solve(hess,grad)
        
    elif(method=="bfsg"):
        # Se revisa que los parámetros de entrada sean congruentes con la funcionalidad
        if type(H) is not np.ndarray:
            sys.exit('Error: H debe ser de tipo numpy.ndarray')
        pk = np.matmul(H,gradiente_f(X,y,beta))
                              
    return - normalize(pk)


def calc_H(X,y,beta,beta_new=None,H=None):
    '''
    
    Función que actualiza los valores de la matriz H del metodo bfgs para cada iteracion
    
        ** Parametros:
        
            - X (mat): matriz de mxp entradas

            - y (vec): vector de de m entradas de la variable output
        
            - beta (array) - valor de cantidad a optimizar en la iteracion actual
            
            - beta_new (array)- valore de la cantidad a optimizar despues de la actualizacion
            
            - H (mat)- valor de la matriz H en la iteracion anterior
        
        
        
        ** Salidas:
        
            - H (mat): valor de la matriz para la siguiente iteracion       
    '''
    
    w = gradiente_f(X,y,beta_new)- gradiente_f(X,y,beta)
    z = beta_new-beta
    Hz = np.matmul(H,z)
    dotwz = np.dot(w,z)
    dotzhz = np.dot(Hz,z)
    H = H+(np.outer(w,w)/dotwz)-(np.outer(Hz,Hz)/dotzhz)
   
    return H


def calc_lr(X, y, beta, lr, pk, c1=10**(-4), tao=0.5, reset_lr=False):
    '''
    
    Función que calcula el tamaño del paso para cada iteración utilizando la condicion de armijo.
    
    La tasa de aprendizaje minima es la que tenia en el paso anterior.
    
        ** Parámetros:
        
            - X (mat): matriz de mxp entradas
            
            - y (vec): vector de de m entradas de la variable output
            
            - lr (float64): tasa de aprendizaje
            
            - pk (array px1 float64): direccion de decenso
            
            - c1 (float64) 0<c1<1: parametro de control
            
            - tao (float64) 0<tao<1: parametro de decrecimiento de lr
            
        ** Salidas
        
            - lr (float64): tamaño de paso
    '''
    # Se revisa que los parámetros de entrada sean congruentes con la funcionalidad    
    if tao > 1 or tao < 0:
        sys.exit('Error:  tao es un parámetro que debe estar entre 0 y 1')  
    if c1 > 1 or c1 < 0:
        sys.exit('Error:  c1 es un paramétro que debe estar entre 0 y 1') 

    # Inicializamos 
    tao = 0.9
    max_iter = 100
    iter = 0
    
    # Inicializa lr
    if reset_lr==True: lr = 1

    # Evaluaciones periódicas
    grad = gradiente_f(X,y,beta)
    eval_f = f(X,y, beta)
    
    # Primera iteracion
    f_x =  f(X,y, beta + lr*pk) #en nocedal es phi(alpha)
    f_x1 = eval_f + c1 * lr *  np.dot(grad,pk) # en nocedal es l(alhpa)
    
    while ((f_x > f_x1) & (iter < max_iter)):
        lr = lr*tao
        f_x =  f(X,y, beta + lr*pk) 
        f_x1 = eval_f + c1 * lr *  np.dot(grad,pk) 
        iter+=1
    
    return lr

def calc_lr_wolf(X, y, beta, lr, pk, c1=10**(-4), c2=0.9, tao=0.5, reset_lr=False):
    '''
    
    Función que calcula el tamaño del paso para cada iteración utilizando la condicion de armijo.
    
    La tasa de aprendizaje minima es la que tenía en el paso anterior.
    
        ** Parámetros:
        
            - X (mat): matriz de mxp entradas
            
            - y (vec): vector de de m entradas de la variable output
            
            - lr (float64): tasa de aprendizaje
            
            - pk (array px1 float64): direccion de decenso
            
            - c1 (float64) 0<c1<1: parametro de control
            
            - tao (float64) 0<tao<1: parametro de decrecimiento de lr
        
        
        
        ** Salidas
        
            - lr (float64): tamaño de paso
    '''
    # Se revisa que los parámetros de entrada sean congruentes con la funcionalidad
    if tao > 1 or tao < 0:
        sys.exit('Error:  tao es un parámetro que debe estar entre 0 y 1')  
    if c1 > 1 or c1 < 0:
        sys.exit('Error:  c1 es un paramétro que debe estar entre 0 y 1') 
    #if pk >= 0 :
    #    sys.exit('Error: pk debe ser negativo')
        
    # Inicializamos 
    tao = 0.5
    max_iter = 50
    iter = 0
    
    # Inicializa lr
    if reset_lr==True: lr=1

    # Evalauciones periodicas
    grad = gradiente_f(X,y,beta)
    eval_f = f(X,y, beta)
    
    # Primera iteracion
    f_x =  f(X,y, beta + lr*pk) #en nocedal es phi(alpha)
    f_x1 = eval_f + c1 * lr *  np.dot(grad,pk) # en nocedal es l(alhpa)
    
    gf_x = np.dot(gradiente_f(X,y, beta+lr*pk) , pk)
    gf_x1 = c2* np.dot(grad, pk)
    
    while ((f_x>f_x1) & (gf_x<gf_x1) & (iter<max_iter)):
        lr =lr*tao
        f_x =  f(X,y, beta + lr*pk) 
        f_x1 = eval_f + c1 * lr *  np.dot(grad,pk) 
        
        gf_x = np.dot(gradiente_f(X,y, beta+lr*pk) , pk)
        #gf_x1 = c2* np.dot(grad, pk)
    
        
        iter+=1
    
    return lr

def gradient_descent(X, y, lr=1, tol=10**(-7), max_iter=10**5, method="max", reset_lr=False, verbose_n=1000):
    '''
    
    Función que devuelve vector de parámetros beta (px1) resultante del proceso
    
    de optimización por descenso de gradiente
    
        ** Parámetros:
        
            - X (mat): matriz de mxp entradas
            
            - y (vec): vector de de m entradas de la variable output
            
            - lr (float64): valor inicial de la tasa de aprendizaje
            
            - tol (float64): criterio de convergencia
            
            - max_iter (int): número máximo de iteraciones
            
            - method (str): método que determina la dirección de descenso
            
                Opciones:
                
                    -- max: método de descenso
                    
                    -- newton: método de Newton
                    
                    -- bfsg
        
        ** Salidas
        
            - beta_new (vec): vector de p entradas con parámetros que minimizan la función de pérdida
    '''
    # imprime método
    out.write(BOLD + "="*65)
    if (method=="max"):
        out.write(BOLD + 'Método de máximo descenso')
    elif (method=="newton"):
        out.write(BOLD + 'Método de Newton')
    elif (method=="bfsg"):
        out.write(BOLD + 'Método de BFGS')
    out.write(BOLD + "="*65)
    
    # Se revisa que los parámetros de entrada sean congruentes con la funcionalidad
    m,p = X.shape
    if y.shape[0]!= m:
        sys.exit('Error:  El número de renglones de X debe ser igual al número de entradas del vector y.')

    
    # Inicializa
    iteraciones=0
    H = None
    dims = X.shape[1]
    tol = tol*dims
    
    # Inicializamos beta aleatoria
    beta = np.random.normal(1,3,dims)
    if method =="bfsg": H = np.identity(dims)
    
    # Primera iteracion
    pk =  descent_direction(X, y, beta, method,H)
    beta_new = beta + lr*pk
    if method == "bfsg": H=calc_H(X,y,beta,beta_new,H) 
    
    # Condición de paro.
    while ((np.linalg.norm(gradiente_f(X,y,beta_new)) > tol) & (iteraciones < max_iter)):
        iteraciones+=1 #contador de ciclo
        
        beta = beta_new
        pk =  descent_direction(X,y,beta,method,H)
        lr = calc_lr(X, y, beta, lr, pk, reset_lr = reset_lr)
        
        beta_new = beta + lr*pk
        
        if method == "bfsg": H=calc_H(X,y,beta,beta_new,H)
            
        # Imprime

        if iteraciones % verbose_n == 0:
            grad=np.linalg.norm(gradiente_f(X,y,beta_new))
            out.write(UNDERSCORE + f'Iteración: {iteraciones}' + ALL_OFF + f' gradiente: {grad:.7E}, alpha: {lr:.4E}')            

    print("\n") 
    out.write(BOLD  + '** Resultados Finales')
    if iteraciones == max_iter:out.write(BOLD + 'El algoritmo paro porque' + BOLD + FG_RED + 'se alcanzo el nro. máximo de iteraciones.')
    out.write(BOLD + f'* Total de iteraciones: ' +ALL_OFF+ f'{iteraciones}'  )
    out.write(BOLD + f'* Norma del gradiente de f: ' +ALL_OFF+ f'{np.linalg.norm(gradiente_f(X,y,beta_new))}' )
    out.write(BOLD + f'* beta_hat:' )
    pprint.pprint(beta_new)
    print("\n") 
    
    return beta_new

#========================================================
# DESCENSO DEL GRADIENTE ESTOCÁSTICO
#========================================================

import random

def riesgo_empirico(X,y,beta):
    
    '''
    Función que calcular el riesgo empírico como la esperanza de la función de pérdida
    
    evaluada sobre todos los puntos del dominio.
    
        - Parámetros:
            -- X (mat): matriz de mxp entradas
    
            -- y (vec): vector de de m entradas de la variable output
            
            -- beta (vec): vector con p entradas

        - Salidas
            
            -- loss (float64): riesgo empírico
    '''
    # Se revisa que los parámetros de entrada sean congruentes con la funcionalidad
    m,p = X.shape
    if y.shape[0]!= m:
        sys.exit('Error:  El número de renglones de X debe ser igual al número de entradas del vector y.')
    if beta.shape[0]!= p:
        sys.exit('Error:  El número de columnas de X debe ser igual al número de entradas del vector beta.')


    mu=calc_mu(X,beta)
    loss=-sum(y*np.log(mu)+(1-y)*np.log(1-mu))
    return loss

def gradiente_riesgo_empirico(X,y,beta):
    
    '''
    Función que calcular el gradiente de la función de riesgo.
    
        - Parámetros:
        
            -- X (mat): matriz de mxp entradas.
            
            -- y (vec): vector de de m entradas de la variable output.
            
            -- beta (vec): vector con p entradas.

        - Salidas
            
            -- grad_riesgo_emp (vec): vector de p entradas
    '''
    # Se revisa que los parámetros de entrada sean congruentes con la funcionalidad
    m,p = X.shape
    if y.shape[0]!= m:
        sys.exit('Error:  El número de renglones de X debe ser igual al número de entradas del vector y.')
    if beta.shape[0]!= p:
        sys.exit('Error:  El número de columnas de X debe ser igual al número de entradas del vector beta.')

    m = X.shape[0]
    mu = calc_mu(X,beta)
    grad_riesgo_emp = np.matmul(np.transpose(X),mu-y)/m
    return grad_riesgo_emp

def batch(m,q=10):
    index=np.random.randint(low=0,high=m,size=q)
    return index

def error_train(X,y,beta):
    prediction=clasifica(X,beta)
    err=round(100*sum(abs(y-prediction))/len(prediction),2)
    return err

def SGD(X,y,batch_size,verbose_n=100,max_iter=10**5):
    
    '''
        Función que computa el gradiente de descenso estocastico
    
        - Parámetros:
        
            -- X (mat): matriz de mxp entradas.
            
            -- y (vec): vector de de m entradas de la variable output.
            
            -- batch_size (int): tamaño del lote 
            
            -- verbose_n (int): Numero de interaciones a las que imprime en pantalla el estatus
            
            -- max_iter (int): Numero máximo de iteraciones

        - Salidas
            
            -- beta (vec): Vector de parametros a optimizar
            
            -- perdida (vec): vecor con las perdidas de cada iteracion
            
            -- error (vec): Error de clasificacion con los parámetros actuales
    
    
    '''

     # Se revisa que los parámetros de entrada sean congruentes con la funcionalidad
    m,p = X.shape
    if y.shape[0]!= m:
        sys.exit('Error:  El número de renglones de X debe ser igual al número de entradas del vector y.')


    # Inicializa
    m=X.shape[0]
    epsilon = 10**(-6)
    beta = np.random.normal(0,1,X.shape[1])    
    step_size=.01
    iteraciones = 0
    epoca=0
    ipe=int(m/batch_size)#iteraciones por epoca
    
    # Primera iteracion
    index=batch(m,batch_size)
    x_lote=X[index,:]
    y_lote = y[index]
    beta_new = beta - step_size * gradiente_riesgo_empirico(x_lote,y_lote,beta) 
    

    perdida=riesgo_empirico(X,y,beta)
    error=error_train(X,y,beta)
    
    # while ((np.linalg.norm(gradiente_f(X,y,beta_new)) > epsilon) & (iteraciones < max_iter)):
    # while abs(f(X,y,beta) - f(X,y,beta_new)) > epsilon:
    while iteraciones<max_iter:
        iteraciones +=1
        #print("iteraciones1=",iteraciones)
        beta = beta_new
        #x_lote,y_lote = mini_lotes(X,y,q)
        index=batch(m,batch_size)
        x_lote=X[index,:]
        y_lote = y[index]
        beta_new = beta - step_size * gradiente_riesgo_empirico(x_lote,y_lote,beta)
        #print("iteraciones2=",iteraciones)
        if iteraciones%10000==0:
            epoca+=1
            loss=riesgo_empirico(X,y,beta)
            perdida=np.append(perdida,loss)
            err=error_train(X,y,beta)
            error=np.append(error, error_train(x_test,y_test,beta_hat))
            print(f'loss:{loss:.4}, epoca:{epoca}, iter:{iteraciones}')
        #print("iteraciones3=",iteraciones)
    print("Nº DE INTERACIONES: ",iteraciones)
    return beta_new,perdida,error

def graf_loss_err(loss,error,title):
    '''
    
    Función para graficar la pérdida o riesgo emírico y el error
    
    de entrenamiento en cada iterazación.
    
        - Entradas:
                    -- loss (vec): vector con las perdidas por época
                    -- error(ver): voctor con los errores de cada época
                    ---title (str): Titulo de la gráfica
        
        - Salidas:
                    -- Imprime gráfica en pantalla
    
    '''
    
    x=np.arange(0,len(error))
    fig, axs = plt.subplots(2, 1)
    axs[0].plot(x, error)
    axs[0].set_xlabel('Iteraciones')
    axs[0].set_ylabel('Train error %')
    axs[0].grid(True)
    
    axs[1].plot(x, loss)
    axs[1].set_xlabel('Iteraciones')
    axs[1].set_ylabel('Perdida')
    axs[1].grid(True)
    axs[0].set_title(title, fontsize=14)
    
    fig.tight_layout()
    plt.show()



#========================================================
# PARALELIZACIÓN DEL DESCENSO DEL GRADIENTE ESTOCÁSTICO

#========================================================

import multiprocessing
import time
from dask.distributed import Client, progress


def n_batch(m):
    index=np.arange(0,m)
    np.random.shuffle(index)
    return index


def construye_indices(ids,m,cores):
    '''
    Argumentos:
    ----------
    * ids: Identificador del core dónde se está corriendo el task. 
    * m (array): Numero total de puntos de entrenamiento.
    * cores (int) : Número de cores o cpus disponibles
    
    Salidas:
    -------
    * (index_from, index_to): Rango de indices que se seleccionan del verctor de permutaciones
    '''
    
    tamano_int = int(m/cores) #tamaño de cada sub intervalo.
    index_from = ids*tamano_int #construyen los subintervalo
    index_to = index_from + tamano_int
    if ids==(cores-1): index_to=m
    return (index_from,index_to)


def evalua_gradiente(intervalo,perm,X,y,beta):
    """
    Función que evalúa el gradiente del riesgo empirico para cada conjunto de indices de permutaciones    
    Argumentos:
    ----------
    * intervalo: Intervalo de indices del vector perm a utilizar
    * perm: Vector de permutaciones 
    * X: Puntos de entrenamiento
    * y: Etiquetas de los puntos de entrenamiento
    * beta: Vector de parametros a optimizar
    
    Salidas:
    * Evaluacion del gradiente del riesgo empirico para un mini lote
    --------

    """   
    index=perm[intervalo[0]:intervalo[1]]
    x_lote = X[index,:]
    y_lote = y[index]
    gradiente=gradiente_riesgo_empirico(x_lote,y_lote,beta) 
    return gradiente



def SGD_paralelo(X,y,verbose_n=100,max_iter=10**5):
    
    '''
    Función que computa el gradiente de descenso estocastico de forma paralela
    
        - Parámetros:
        
            -- X (mat): matriz de mxp entradas.
            
            -- y (vec): vector de de m entradas de la variable output.
            
            -- verbose_n (int): Numero de interaciones a las que imprime en pantalla el estatus
            
            -- max_iter (int): Numero máximo de iteraciones

        - Salidas
            
            -- beta (vec): Vector de parametros a optimizar
            
            -- perdida (vec): vecor con las perdidas de cada iteracion
            
            -- error (vec): Error de clasificacion con los parámetros actuales
    
    
    '''
    
    
    '''

     # Se revisa que los parámetros de entrada sean congruentes con la funcionalidad
    m,p = X.shape
    if y.shape[0]!= m:
        sys.exit('Error:  El número de renglones de X debe ser igual al número de entradas del vector y.')


    # Inicializa
    m=X.shape[0]
    epsilon = 10**(-6)
    beta = np.random.normal(0,1,X.shape[1])    
    step_size=.01
    iteraciones = 0
    epoca=0
    
    # Primera iteracion
    perm=n_batch(m)
    #calcula los indices
    indices = client.map(construye_indices,range(cores),
                **{'m':m,'cores':cores})

    #evalua el gradiente en cada batch en paralelo
    grad_riesgo_empirico=client.map(evalua_gradiente,indices,
                **{'perm':perm,'X':X,'y':y,'beta':beta})

    results=client.gather(grad_riesgo_empirico)
    actualiza=sum(results)
    
    beta_new = beta - step_size * actualiza  
    #gradiente_riesgo_empirico(x_lote,y_lote,beta) 
    
    perdida=riesgo_empirico(X,y,beta)
    error=error_train(X,y,beta)
    
    # while ((np.linalg.norm(gradiente_f(X,y,beta_new)) > epsilon) & (iteraciones < max_iter)):
    # while abs(f(X,y,beta) - f(X,y,beta_new)) > epsilon:
    while iteraciones<max_iter:
        iteraciones +=1
        beta = beta_new
        perm=n_batch(m)
        #calcula los indices
        indices = client.map(construye_indices,range(cores),**{'m':m,'cores':cores})
        #evalua el gradiente en cada batch en paralelo
        grad_riesgo_empirico=client.map(evalua_gradiente,indices,
                     **{'perm':perm,'X':X,'y':y,'beta':beta})
        #gather results
        results=client.gather(grad_riesgo_empirico)
        actualiza=sum(results)
        
        beta_new = beta - step_size * actualiza
        end_time = time.time()
        
        if iteraciones%100==0:
            epoca+=1
            loss=riesgo_empirico(X,y,beta)
            perdida=np.append(perdida,loss)
            err=error_train(X,y,beta)
            error=np.append(error, error_train(x_test,y_test,beta_hat))
            print(f'loss:{loss:.4}, epoca:{epoca}, iter:{iteraciones}')
    print("Nº DE INTERACIONES: ",iteraciones)
    return beta_new,perdida,error

