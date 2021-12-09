# Equipo 4

## **Título del proyecto**: Algoritmo BFGS para regresión logística. 

### Integrantes:
* @nelsonalejandrov: Nelson Alejandro Gil Vargas
* @mig-calval: Miguel Calvo Valente
* @Monfiz: Alejandro Muñoz Gutiérrez
* @AdrianTJ: Adrian Tame Jacobo

### Distribución de Tareas

|User| Trabajo|
|:---:|:---:|
|@nelsonalejandrov| Project Manager, y encargado de presentar resultados finales. Encargado también de hacer gráficas de los resultados. |
|@Monfiz| Equipo de testing. Verificación de calidad. One man team. |
|@mig-calval, @AdrianTJ| Equipo de desarollo/programación. Encargados de implementación del algoritmo. |

### **Objetivo del proyecto**
Implementación del algoritmo BFGS para poder hacer estimación numérica de los coeficientes óptimos de una regresión logística, con un conjunto de datos dado. Los datos son datos de pacientes que tuvieron un derrame cerebral, y usamos el método para clasificación. 


[Liga a repo](https://github.com/Monfiz/Proyecto_final_opt_eq_4)

Trabajo escrito (fuera de la repo): [Drive con el Reporte](https://drive.google.com/file/d/16Wtwd2kilk4LA6NT-3Fyd7DuFLHrivoj/view)

Presentación (fuera de la repo): [Drive con la Presentación](https://drive.google.com/file/d/1cCK-d9wEWkSzn3xvBUmX_qFt8jrvxgBZ/view?usp=sharing)

En la carpeta [AWS](https://github.com/Monfiz/Proyecto_final_opt_eq_4/tree/main/AWS) hay screenshots de evidencia de que utilizamos AWS. 

En la carpeta [Avances](https://github.com/Monfiz/Proyecto_final_opt_eq_4/tree/main/Avances) se encuentra el reporte de los avances en nuestro proyecto. En este caso, fueron 3 avances.

En la carpeta [Datos](https://github.com/Monfiz/Proyecto_final_opt_eq_4/tree/main/Datos) se encuentan los datos sim limpiar, `healthcare-dataset-stroke-data.csv` y los datos limpios, `Stroke_Data.csv`. 

En la carpeta [Desarrollo](https://github.com/Monfiz/Proyecto_final_opt_eq_4/tree/main/Desarrollo) se encuentran varios archivos que estuvimos utilizando para probar y generar el reporte y los datos finales. 

En la carpeta [Figuras](https://github.com/Monfiz/Proyecto_final_opt_eq_4/tree/main/Figuras) incluimos el archivo `BFGS.png` que es una imagen del latex del pseudocódigo del algoritmo.

En la carpeta [Reporte](https://github.com/Monfiz/Proyecto_final_opt_eq_4/tree/main/Reporte), está el `.Rmd` que utilizamos para generar la versión final del reporte. 

## Librerías y Paquetes Utilizados

- Pytest
- Matplotlib
- Sklearn
- Numpy
- Scipy
- Scipy.optimize
- Pandas

## Referencias 

* [Simpy](https://www.sympy.org/en/index.html)
* [Stroke-prediction-dataset](https://www.kaggle.com/fedesoriano/stroke-prediction-dataset)
* [scipy.optimize](https://docs.scipy.org/doc/scipy/reference/generated/scipy.optimize.minimize.html)
* [How to minimize with BFGS in Python?](https://stackoverflow.com/questions/45374421/how-to-minimize-with-bfgs-in-python)
* [Python implementation example BFGS](https://sudonull.com/post/68834-BFGS-method-or-one-of-the-most-effective-optimization-methods-Python-implementation-example)
* [Broyden–Fletcher–Goldfarb–Shanno algorithm](https://en.wikipedia.org/wiki/Broyden–Fletcher–Goldfarb–Shanno_algorithm)
* [Line search in gradient and Newton directions](https://people.duke.edu/~ccc14/sta-663-2018/notebooks/S09E_Optimization_Line_Search.html)
* [Wolfe conditions](https://en.wikipedia.org/wiki/Wolfe_conditions)
* [Unconstrained Convex Optimization](https://itam-ds.github.io/analisis-numerico-computo-cientifico/3.optimizacion_convexa/3.2/Algoritmos_de_descenso_y_busqueda_de_linea_en_uco.html?highlight=line%20search)

