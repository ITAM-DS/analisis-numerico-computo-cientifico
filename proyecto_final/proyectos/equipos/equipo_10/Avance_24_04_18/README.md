**Abraham:** 


`Para fijar el objetivo del uso de SVD para recomendaciones se replicó un ejercicio de como se implementa en python para hacer recomendaciones, el cual se puede ver en este notebook` [Advanced+Recommender+Systems+with+Python-Copy1](https://drive.google.com/file/d/1oqzcN_Rl_eK1UG-I8EzF_iNa-1ga44ki/view) `(Bajar version html) en general python ocupa una función svds contenida en la librería scipy.sparse.linalg para hacer la descomposión SVD, pero uno define los factores o en otras palabras  la dimensión de la matriz diagonal S, para hacer el calculo de las predicciones.`
`También tenemos la version Jupyter` [Advanced+Recommender+Systems+with+Python-Copy1](https://drive.google.com/file/d/1NmPLq8uxapbECZp3euR0DDCQ-drqZPBG/view).
`En orden de ideas el hacer un sistema de recomendadores es un algoritmo de machine learning  donde en este caso particular,después de  hacer un tratamiento de datos de usuarios y películas (basado en el algoritmo de netflix), nuestra matriz A tiene renglones de usuarios y nuestras columnas son las peliculas que han visto, todas ellas calificadas del 1 al 5, siguiendo la metodología de machine learning podemos hacer una separación de datos en entrenamiento y test para medir las predicciones.` `El primer paso es hacer la descomposición SVD en los datos de entrenamiento con lo cual tendremos las matrices U,S,V de tal forma que para hacer predicciones en los datos de prueba, entonces lo que hay que hacer es la descomposición, en los datos de entrenamiento, seleccionando el tamaño de k<# de peliculas( esto deriva en un pseudo calculo de SVD) o dimensión de la matriz de S para hacer la predicción, esto último multiplicando las 3 matrices, y medir la precisión tomando en cuenta que una k pequeña podría  tener un overfitting. una de las conclusiones es que el cálculo de SVD es muy lento por tanto la oportunidad de mejorarlo suena perfecto haciendo la paralelización.` 
`Este notebook viene de un curso que se muestra en la` [referencia](https://drive.google.com/drive/u/0/folders/1MYwNlFrKg6u-Z9dAjE5xl6FGSNiz0GqR).

**Roberto:** 

`Se realizó el` [Plan de Proyecto](https://drive.google.com/file/d/1dIRZpcrOpCq7PY08XHte967pCgyqyWIa/view?usp=sharing) `con la finalidad de darle una estructura mucho más formal a las actividades que realizaremos durante la siguientes semanas y poderlas integrar en los avances semanales.`

**Rodrigo:** 

`Para realizar las primeras pruebas de CUDA, se creó una instancia en AWS con el bash script que se sugiere por el profesor en el siguiente` [link](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/extensiones_a_C/CUDA/instalacion)`, de esta manera se podrán ejecutar diferentes códigos de CUDA para poder completar nuestro proyecto. A continuación, se encuentran unas imágenes donde se podrá observar cómo se montó una instancia en AWS con la configuración deseada. Esto se puede observar` [aquí](https://drive.google.com/open?id=1g8ePHvju9y8M4V9CEnmHnweOyE5Ole3z)




**Equipo:** 
`Se platicó con el equipo 7 y se acordó que nosotros realizaríamos la implementación en CUDA, se añade referencia en el readme principal del cuSolver via método de Jacobi. Utilizaremos el dataset MovieLens que consta de 943 usuarios y 1682 peliculas para crear la matriz de user-items(943x1628) y utilizar esta base para como la matriz a descomponer en cuda y como principal matriz donde probaremos nuestro SVD con la idea de poder reducir los tiempos del ejercicio que muestra Abraham.` 
`A pesar de levantar el cuda en AWS debemos definir si esta es la versión  que debemos usar o quiźas una imagen de docker, pero también debemos ver si la función cuSolver  funciona en ambas instancias dependiendo de la versiń de CUDA.`
`Los siguientes pasos serían comenzar con la parte teórica del trabajo escrito, hacer una prueba usando cuSolver con una matriz esta quizás a nivel local y la otra es que tratar de jecutar después en AWS o Docker.`
