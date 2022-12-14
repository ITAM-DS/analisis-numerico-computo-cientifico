'''Este archivo contiene las funciones necesarias para 
obtener la solucion de una ecuacion diferencial
vía el Metodo de Runge Kutta de orden 4(hay una funcion programda para esto)
y para generar soluciones particulares de una EDO
y obtener las superficies de Delaunay '''

#librerias necesarias
import numpy as np
from numpy import linalg as LA
import warnings
import math
warnings.filterwarnings("ignore")
#funcion auxiliar para calcular errores relativos
def compute_error(obj,approx):
    
    '''
    Relative or absolute error between obj and approx.
    '''
    if LA.norm(obj) > np.nextafter(0,1):
        Err = LA.norm(obj-approx)/LA.norm(obj)
    else:
        Err = LA.norm(obj-approx)
    return Err


def RK4(f,a,b,alpha,N):
    '''
    Runge-Kutta order four method to approximate the solution of an
    ordinary differential equation with an initial condition
    
    INPUTS:
    
    f(function)  : The function that defines the ordinary differential equation
    a(float)     : left extreme of the solution domain [a,b]
    b(float)     : right extreme of the solution domain [a,b]
    alpha(float) : initial condition y(a)=alpha
    N(integer)   : 
    
    OUTPUT:
    
    w(onedarray) : approximation of function y at N equally spaced point of [a,b]
    '''
    t=np.arange(a,b,step=1/N)
    h=t[1]-t[0]
    w=np.ones(len(t))
    w[0]=alpha
    for i in range(0,len(t)-1):
        K1= h*f(t[i],w[i])
        K2= h*f(t[i]+h/2, w[i]+K1/2)
        K3= h*f(t[i]+h/2, w[i]+K2/2)
        K4= h*f(t[i]+h, w[i]+K3)
        w[i+1]=w[i]+(K1+2*K2+2*K3+K4)/6
    return t,w 


    



