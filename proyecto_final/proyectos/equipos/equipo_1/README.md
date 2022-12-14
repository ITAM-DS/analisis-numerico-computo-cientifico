# Optimization-Delaunay-surfaces
In this respository is developed the optimization problem related with Delaunay surfaces.

<p align = "center">

# <p align = "center"> Maestría en Ciencia de Datos del ITAM :computer:
    
# <p align = "center"> Métodos Numéricos y Optimización (Otoño 2022)    
    
# <p align = "center"> Proyecto Final: Superficies de Delaunay. Una perspectiva desde el cálculo de variaciones.
  
# <p align = "center"> Equipo 1

## Integrantes 👨‍🔬 👨‍🔬 👩‍🔬 👨‍🔬

|     ***Contributors***           |             ***Usuario de Github***                  |  ***Roles***  |                               
|:--------------------------------:|:----------------------------------------------------:|:----------------------:|
|        David Damián Arbeu        |     [David-Damián](https://github.com/David-Damian)  |       Grupo de programación   | 
| Juan Francisco Palmeros Barradas | [JuanPalms](https://github.com/JuanPalms)            |       Grupo de programación   | 
|       Valeria Roberts Trujillo   |  [ValeriaRoberts](https://github.com/ValeriaRoberts) |       Project manager   | 
|  José Alberto Mandujano Montes   | [AlbertoMandujanoMontes](https://github.com/AlbertoMandujanoMontes) |       Grupo de revisión  |

## :rocket: ```Título del proyecto``` Superficies de Delaunay

## 👉 ```Objetivo del proyecto``` 

 Dado uno volumen $v$, se busca aproximar la superficie de revolución de área mínima cuyo volumen interior es $v$. La forma de abordar este problema es vía el método de multiplicadores de Lagrange. Se
define el lagrangiano a partir del funcional que define el problema de minimización y la resitricción de volumen dado. 

La ecuación de [Euler-Lagrange](https://en.wikipedia.org/wiki/Euler%E2%80%93Lagrange_equation#Statement), condición necesaría para un extremo, induce una **ecuación diferencial ordinaria no lineal** cuya solución analítica es posible obtener **solo en algunos casos** (para cierta configuración de sus parámetros). 

Para resolver la ecuación diferencial inducida de manera más general (no solo para cierta combinación de parámetros), se emplea el *Método de Runge-Kuta de orden 4* (Burden & Faires, 2010, pp. 288-289),  y se muestran en particular algunas superficies solución, conocidas como Superficies de Delaunay.

## 🌐 [Repositorio de nuestro proyecto](https://github.com/David-Damian/Optimization-Delaunay-surfaces)

## 🌐 [Trabajo escrito](https://drive.google.com/drive/u/1/folders/1xI_h8CFtNFiVacF_iKLZ7yscHh8LnNec)

## 🌐 [Presentación](https://drive.google.com/drive/u/1/folders/1PFiHOE2EAaN4GCr1xib3-4OOl3eIG-nY)

## [🌐 Implementación](https://github.com/David-Damian/Optimization-Delaunay-surfaces/tree/main/src)


> En la carpeta [avance1](https://github.com/David-Damian/Optimization-Delaunay-surfaces/tree/main/avance1) se encuentra el reporte del primer avance en nuestro proyecto.
 
> En la carpeta [avance2](https://github.com/David-Damian/Optimization-Delaunay-surfaces/tree/main/avance2) se encuentra el reporte del segundo avance en nuestro proyecto.

## Referencias del proyecto :books: 
* Troutman, J. L. (2022). Variational Calculus and Optimal Control: Optimization with Elementary Convexity (Undergraduate Texts in Mathematics) by John L. Troutman (1995-12-01). Springer.
* Burden, R. L. & Faires, J. D. (2010). Numerical Analysis. Cengage Learning.
* [Inspiración del formarto del README](https://github.com/David-Damian/analisis-numerico-computo-cientifico/blob/optimizacion-2021/proyecto_final/proyectos/equipos/equipo_1/README.md)
* [Generar una *malla* en \mathbb{R}^2](https://numpy.org/doc/stable/reference/generated/numpy.meshgrid.html)
* [Sólidos de revolución con Python](https://stackoverflow.com/questions/59402531/how-to-produce-a-revolution-of-a-2d-plot-with-matplotlib-in-python)
* [Parametrización de sólidos de revolución](https://sistemas.fciencias.unam.mx/~erhc/calculo4_20172/superficies_parametricas_2017_a.pdf)
* [Cálculo de integrales sin conocer expresión analítica del integrando usando `Python`](https://docs.scipy.org/doc/scipy-0.14.0/reference/generated/scipy.integrate.cumtrapz.html)
* [Plantilla de LaTeX para el reporte](https://www.latextemplates.com/template/legrand-orange-book)
* [Plantilla de LaTeX para presentación](https://www.overleaf.com/latex/templates/jmu-prasentations-vorlage/cjgfjrsxwhfv)
* [Problema de la braquistócrona en `Python`](https://scipython.com/blog/the-brachistochrone-problem/)
* [Documentación de la librería para probar la integración](https://docs.scipy.org/doc/scipy/reference/generated/scipy.integrate.solve_ivp.html)
