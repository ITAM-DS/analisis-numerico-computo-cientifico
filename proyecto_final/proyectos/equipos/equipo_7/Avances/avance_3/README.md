# Avance 3:  Compresión de Imágenes - PCA


**Lenguaje principal:**  Python


## Integrantes:
* Carlos Bautista
* Edgar Bazo
* Luz Hernández
* Ita Santiago

## Avances del grupo:

Nos reunimos y verificamos lo trabajado: hasta el momento se trabajó en el desarrollo de código para obtener 
la varianza explicada la cual nos ayudara a determinar cuantas componentes serán suficientes para la reconstrucción 
de la imagen. También se calcula la inversa transpuesta para la reconstrucción de la imagen, se generaron Jupyter 
Notebooks con la implementación y se continuó con la revisión de referencias e imágenes pequeñas para mejorar 
el desempeño de nuestras funciones.

## Avances individuales:

**Carlos:**
Realizó el cálculo y el análisis de la varianza explicada, con las gráficas explicativas.

**Edgar:**
* Se realizó actualización a la función jacobi_iteration para que regresara tanto los eValues como 
  los eVectors ordenados de forma descendente esto hace que nuestra función returnPCA se comporte 
  como lo hace la función de Skit-learn para PCA decomposition

**Consulte estas referencias para implementarlo**
* https://www.cienciadedatos.net/documentos/py19-pca-python.html
* https://scikit-learn.org/stable/modules/generated/sklearn.decomposition.PCA.html
* https://www.analyticslane.com/2020/12/14/numpy-ordenar-matrices-de-numpy-por-fila-o-columna/
* https://numpy.org/doc/stable/user/whatisnumpy.html
** **
* Se calcula la inversa transpuesta para poder reconstruir la imagen a partir de las
    componentes obtenidas de nuestra función  

**Referencias consultadas para realizarlo**
* https://stackoverflow.com/questions/32750915/pca-inverse-transform-manually
* https://scikit-learn.org/stable/modules/generated/sklearn.decomposition.PCA.html


**Luz:**
* Escribió la primera versión completa del reporte escrito.

**Ita:** 
* Se trabajó en unificar el reporte con la parte de covarianza y la inversa transpuesta, así como profundizar en 
  los argumentos métodos numéricos y algoritmos que vamos a usar. Agregando más álgebra



## Tareas próximas:

**Carlos:**
* Revisión, complementación y profundizar en los argumentos de métodos numéricos y algoritmos que vamos a usar.

**Ita:**
* Revisión, complementación y profundizar en los argumentos de métodos numéricos y algoritmos que vamos a usar.


**Edgar:**
* Aplicación del algoritmo flujo completo para comprimir las imágenes, revision y complementación del trabajo escrito 
  adicional actualizar las funciones de los scripts.

**Luz:**
* Coordinar las actividades de todos, llevar el control del reporte escrito y la presentación.


## Siguientes reuniones y resultados esperados:

| # | Avance                                            | Fecha            | Entregable                                   |
|---|-------------------------------------------------------------|------------------|----------------------------------------------|
| 5 | Avance 3bis: Resolución de feedbacks de la reunión anterior     | Sáb 4/Dic    | Notebooks reporte final     |
| 6 | Avance 4: Revisión del tercer avance     | Mar 7/Dic   | Notebook final en PDF y mockup de presentación del proyecto|
| 7 | Examen final:  Presentación del proyecto                    | Jue 09/Dic | PDF Reporte final y presentación del proyecto|
