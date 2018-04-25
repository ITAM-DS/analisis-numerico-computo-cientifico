# coding: utf-8

# Importamos paquetes necesarios.
from scipy import optimize,arange
from numpy import array

def demand(x1,x2,a,b): # definimos la función de demanda
    return a-x1-b*x2   # en este caso solo tenemos dos empresas

def cost(x,c): # definimos la función de costos
    if x == 0:
     cost = 0
    else:
     cost = c*x
    return cost

def profit(x1,x2,c1,a,b): # usando las anteirores, definimos función de ganancias
    return demand(x1,x2,a,b)*x1-cost(x1,c1)

def reaction(x2,c1,a,b):  # definimos la función de mejor respuesta 
    x1 = optimize.brute(lambda x: -profit(x,x2,c1,a,b), ((0,a,),)) # brute minimiza la función;
    return x1[0]                                                   # si minimizamos -profits, maximizamos ganancias

def vector_reaction(x,param): # vector de parámetros = (b,c1,c2,a)
    return array(x)-array([reaction(x[1],param[1],param[3],param[0]),reaction(x[0],param[2],param[3],param[0])])

param = [1.0,0.0,0.0,100.0]
x0 = [0, 0]

ans = optimize.fsolve(vector_reaction, x0, args = (param))
print(ans)
