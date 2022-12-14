from utils import *
#librerias necesarias
import numpy as np
from numpy import linalg as LA
import warnings
import math
from scipy import integrate
#La siguiente funcion es una especie de grid search para buscar los mejores hiperparametros
# de la ecuacion diferencial que nos permitan aproximar de mejor manera la solucion del problema
#de optimizacion

def delaunay(k1,Lambda,a,b,xa,xb,vol):

    #extras
    n=len(k1)
    m=len(Lambda)
    global solfinal
    global integral_fin
    err_integral=1
    best_hyperparams=np.zeros(2)

    for i in k1:
        for j in Lambda:
            lam =j
            k=i
            #funcion que define a la ecuacion diferencial que resolveremos
            def fun_difEq(u,x):
                valor= (lam*x**2-k)/(x)
                return valor
            fun = fun_difEq #funcion de la ecuacion diferencial que resolveremos
            solu=RK4(f=fun,a=a, b=b, alpha=xa, N=1000)
            t=solu[0]
            solu=solu[1]
            print(f"0 voy en k,lambda=", lam,k)
            #verificar que el vector de soluciones no tenga nan's
            if(solu[-1]!='nan'):
                print(f"1 potencial solucion")
                #verificar que la condicion final e inicial no sean iguales(pues ello implica que en algun momento)
                if(xb!=xa):
                    print(f"2 test exitoso")
                    error=abs(xb-solu[-1]) #verificamos que el ultimo punto de la solucion este cerca de la condicion final
                    print(error)
                    #print(f"La condicion final se satisface salvo un error de", error/xb)
                    #consideramos como factible soluciones con condicion final cerca y verificamos que cumple la condicion de volumen
                    if(error<0.025):
                        print('3 potencial sol')
                        #Verificar que la solucion satisface la condición de volumen
                        integrando=np.pi*solu**2
                        x = t
                        y = integrando
                        integral = integrate.cumtrapz(y, x, initial = a)
                        integral=integral[-1]-integral[0] #por el teorema fundamental del calculo
                        print(f"La condicion final se satisface salvo un error de", error)
                        print(f"Volumen aproximado", integral)
                        #calcular error relativo(para que la magnitud de ambas cantidades no sea la que afecte)
                        err_integral=abs(vol-integral)
                        print(f"error relativo entre volumen y volumen aprox", err_integral/vol)
                        #si la solucion stisface la condicion de volumen, salvo por un error <2, quedarse con la solucion          
                        if(err_integral <0.1): #tolerancia del 5%
                            print('Se encontró una solución tal que')
                            err_integral=np.abs(integral-vol)
                            solfinal=solu
                            integral_fin=integral
                            err_int=err_integral
                            best_hyperparams= lam,k
                            print(f"Los parametros que mejor se ajustan son k, lambda=", lam, k)
                            print(f"El volumen de la mejor superficie es", integral_fin)
                            print(f"El error absoluto entre el volumen objetivo y volumen aproximado es", err_integral)
                            print(f"El error relativo entre condicion final objetivo y fin de la solucion aproximada es", error/xb)
                            return t, solfinal, integral_fin, err_integral, best_hyperparams