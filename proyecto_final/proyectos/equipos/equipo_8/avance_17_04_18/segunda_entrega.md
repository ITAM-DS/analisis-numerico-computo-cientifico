Segunda Entrega
===============

Luis Fernando Cantú

Eduardo Hidalgo

Mónica Vargas

El juego de Cournot
-------------------

El juego de Cournot consiste en lo siguiente:

Suponga que existen *n* empresas cada una de las cuales tiene una función de costos *C*<sub>*i*</sub>(*q*<sub>*i*</sub>) al producir *q*<sub>*i*</sub> ≥ 0. Sea *N* = {1, ..., *n*}. Las empresas se enfrentan a una función de demanda inversa agregada *P*(*Q*), donde *Q* = ∑<sub>*i* ∈ *N*</sub>*q*<sub>*i*</sub>. Las ganancias de la empresa *i* están dadas por:

*Π*<sub>*i*</sub>(*q*)=*q*<sub>*i*</sub>∑<sub>*j* ∈ *N*</sub>*q*<sub>*j*</sub> − *C*(*q*<sub>*i*</sub>)
.

Un equilibrio de Cournot-Nash es un vector de cantidades *q*<sup>\*</sup> ∈ *R*<sup>*N*</sup>, tal que para cualesquier empresa *i* ∈ *N*:

*Π*<sub>*i*</sub>(*q*<sup>\*</sup>)=max<sub>*q*<sub>*i*</sub> ≥ 0</sub>*Π*<sub>*i*</sub>(*q*<sub>1</sub><sup>\*</sup>, ..., *q*<sub>*i* − 1</sub><sup>\*</sup>, *q*<sub>*i*</sub><sup>\*</sup>, *q*<sub>*i* + 1</sub><sup>\*</sup>, *q*<sub>*n*</sub><sup>\*</sup>)
.

Eduardo Hidalgo
---------------

Implementación en R
-------------------

### Contexto Teórico

El ejemplo que aquí se presenta se encuentra en: <http://www.brodrigues.co/blog/2014-04-23-r-s4-rootfinding/>. Este, a su vez, es un ejemplo del libro de Miranda y Fackler (2004, pag. 35). Allí se presenta un modelo de dúopolio de Cournot, en él dos firmas **compiten en cantidades**. Ambas producen una cantidad de un bien homogéneo y para esta desición toman la cantidad de su competidor como dada.

La **Demanda Inversa** del bien:

$$P(q)=q^{- \\frac{1}{\\eta}}$$

La **Función de Costos** de la firma **i**:

*C*<sub>*i*</sub>(*q*<sub>*i*</sub>)=*P*(*q*<sub>1</sub> + *q*<sub>2</sub>)\**q*<sub>*i*</sub> − *C*<sub>*i*</sub>(*q*<sub>*i*</sub>)

Y la **Función de Ganancias** de la firma **i**:
*π*<sub>*i*</sub>(*q*<sub>1</sub> + *q*<sub>2</sub>)=*P*(*q*<sub>1</sub> + *q*<sub>2</sub>)*q*<sub>*i*</sub> − *C*<sub>*i*</sub>*q*<sub>*i*</sub>

La condición de optimalidad de la firma **i**:

$$ \\frac{\\partial \\pi\_{i} }{\\partial q\_{i}} = (q\_{1}+q\_{2})^{-\\frac{1}{n}} - \\frac{1}{n}(q\_{1}+q\_{2})^{\\frac{-1}{\\eta - 1}}q\_{i}-c\_{i}q\_{i}=0$$

### Generación de la clase "Model"

``` r
setClass(Class = "Model", slots = list(OptimCond = "function", JacobiOptimCond = "function"))
```

Creación de función que regrese dos funciones para valores dados de los parámetros: *c* y *η*

``` r
my_mod <- function(eta, c) {
    e = -1/eta

    OptimCond <- function(q) {
        return(sum(q)^e + e * sum(q)^(e - 1) * q - diag(c) %*% q)
    }

    JacobiOptimCond <- function(q) {
        return((e * sum(q)^e) * array(1, c(2, 2)) + (e * sum(q)^(e - 1)) * diag(1, 
            2) + (e - 1) * e * sum(q)^(e - 2) * q * c(1, 1) - diag(c))
    }

    return(new("Model", OptimCond = OptimCond, JacobiOptimCond = JacobiOptimCond))

}
```

La función `my_mod` toma dos parámetros, `eta` y `c` y regresa dos funciones, **la condición de optimalidad** y **el jacobiano de la conidición de optimalidad**. Ambas estan disponibles via `my_mod(eta=1.6,c=c(0.6,0.8))@OptimCond` y `my_mod(eta=1.6,c=c(0.6,0.8))@JacobiOptimCond` respectivamente (y al especificar los valores de `eta` y `c`).

Usamos el paquete `rootSolve` para obtener los valores de *q*<sub>1</sub> y *q*<sub>2</sub>:

``` r
library("rootSolve")
```

    ## 
    ## Attaching package: 'rootSolve'

    ## The following object is masked from 'package:formattable':
    ## 
    ##     gradient

``` r
multiroot(f = my_mod(eta = 1.6, c = c(0.6, 0.8))@OptimCond, start = c(1, 1), 
    maxiter = 100, jacfunc = my_mod(eta = 1.6, c = c(0.6, 0.8))@JacobiOptimCond)
```

    ## $root
    ## [1] 0.8395676 0.6887964
    ## 
    ## $f.root
    ##               [,1]
    ## [1,] -2.220197e-09
    ## [2,]  9.928337e-09
    ## 
    ## $iter
    ## [1] 4
    ## 
    ## $estim.precis
    ## [1] 6.074267e-09

Después de 4 iteraciones, se obtiene que:

*q*<sub>1</sub> = 0.84
*q*<sub>2</sub> = 0.69

De acuerdo con el autor existe otra forma de resolver el problema que no requiere la instanciación de una nueva clase de objeto. Esta solución corresponde a un usuario de www.reddit.com, cuyo nombre de usuario es TheDrownedKraken.

``` r
generator <- function(eta, a) {
    e = -1/eta

    OptimCond <- function(q) {
        return(sum(q)^e + e * sum(q)^(e - 1) * q - diag(a) %*% q)
    }

    JacobiOptimCond <- function(q) {
        return((e * sum(q)^e) * array(1, c(2, 2)) + (e * sum(q)^(e - 1)) * diag(1, 
            2) + (e - 1) * e * sum(q)^(e - 2) * q * c(1, 1) - diag(a))
    }

    return(list(OptimCond = OptimCond, JacobiOptimCond = JacobiOptimCond))

}

f.s <- generator(eta = 1.6, a = c(0.6, 0.8))

multiroot(f = f.s$OptimCond, start = c(1, 1), maxiter = 100, jacfunc = f.s$JacobiOptimCond)
```

    ## $root
    ## [1] 0.8395676 0.6887964
    ## 
    ## $f.root
    ##               [,1]
    ## [1,] -2.220197e-09
    ## [2,]  9.928337e-09
    ## 
    ## $iter
    ## [1] 4
    ## 
    ## $estim.precis
    ## [1] 6.074267e-09

Luis Fernando Cantú
-------------------

Implementación en Python
------------------------

En la entrega anterior vimos que el juego de Cournot es un problema de programación cuadrática fuertemente convexo. Esto quiere decir que se puede encontrar el equilibrio de Nash del juego mediante métodos como descenso en gradiente o descenso en coordenadas. Tomando en cuenta lo anterior, se escribió código en Python que encuentra el equilibrio de Nash.

``` python
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
```

    ## [33.33332263 33.33332263]

Como se puede apreciar en el código anterior, se resolvió el modelo utilizando librerías preestablecidas. En próximas entregas se debe de encontrar una manera de implementar este código sin la librería `scipy`.

Mónica Vargas
-------------

Numerical Optimization Methods in Economics
-------------------------------------------

Los métodos numéricos que se usan para resolver modelos económicos de optimización varía tanto como los problemas que enfrentamos. Por este propósito el artículo se enfoca en problemas no lineales (incluyendo lineales), determinísticos y de dimensiones finitas ya que estos problemas son ubicuos en el análisis económico. El artículo primero indica ciertas dificultades técnicas que debemos tener en cuenta. Segundo, realza las fundaciones teóricas básicas para los métodos de optimización numérico, entre ellos, el método de descenso de gradiente que usaremos en el proyecto. Tercero, describe las principales estrategias numéricas que forman la base para la mayoría de los algoritmos y muestra los programas y paqueterías que se más se usan (principalmente MATLAB).

Bibliografía
------------

1.  Miranda, M. J., & Fackler, P. L. (2004). Applied computational economics and finance. MIT press.
2.  Schmedders, Karl. (2008). Numerical Optimization Methods in Economics. 1-27. 10.1057/978-1-349-95121-5\_2232-1. <https://www.researchgate.net/publication/313867455_Numerical_Optimization_Methods_in_Economics?enrichId=rgreq-d983e8a6585dd0a533e66b02013921c9-XXX&enrichSource=Y292ZXJQYWdlOzMxMzg2NzQ1NTtBUzo0NzkzMTkxMzU5MjAxMzNAMTQ5MTI4OTk5NTg2OA%3D%3D&el=1_x_3&_esc=publicationCoverPdf>
