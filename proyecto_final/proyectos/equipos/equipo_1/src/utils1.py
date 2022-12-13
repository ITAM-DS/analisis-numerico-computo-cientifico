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
                valor=(np.sqrt(4*x**2-(lam*x**2-k)**2))/(lam*x**2-k)
                return valor
            fun = fun_difEq #funcion de la ecuacion diferencial que resolveremos
            solu=RK4(f=fun,a=a, b=b, alpha=xa, N=1000)
            t=solu[0]
            solu=solu[1]
            nans= np.isnan(solu)
            #verificar que el vector de soluciones no tenga nan's
            if(sum(nans)==0):
                #verificar que la condicion final e inicial no sean iguales
                if(xb!=xa):
                    xb=1196
                    error=abs(solu[-1]-xb) #verificamos que el ultimo punto de la solucion este cerca de la condicion final
                    #si cierto, nos quedamos con esta solucion y verificamos que cumple la condicion de volumen
                    if(error<2):
                        print('3')
                        #areas=np.zeros(len(solu))
                        #Verificar que la solucion satisface la condición de volumen
                        integrando=np.pi*solu**2
                        x = t
                        y = integrando
                        integral = integrate.cumtrapz(y, x, initial = a)
                        integral=integral[-1]-integral[0] #por el teorema fundamental del calculo
                        print(integral)
                        #calcular error relativo(para que la magnitud de ambas cantidades no sea la que afecte)
                        err_integral=compute_error(obj=vol,approx=integral)
                        print(err_integral)
                        #si la solucion stisface la condicion de volumen, salvo por un error <2, quedarse con la solucion          
                        if(err_integral<0.05): #tolerancia del 5%
                            err_integral=np.abs(integral-vol)
                            solfinal=solu
                            integral_fin=integral
                            err_int=err_integral
                            best_hyperparams= lam,k
                            print(f"Los parametros que mejor se ajustan son", lam, k)
                            print(f"El volumen de la mejor superficie es", integral_fin)
                            return t, solfinal, integral_fin, err_integral, best_hyperparams