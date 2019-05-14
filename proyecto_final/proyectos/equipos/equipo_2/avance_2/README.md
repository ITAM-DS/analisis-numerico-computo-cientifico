# avance_2

## Integrantes:

* Sol

* Iker

* Luis

## Trabajo:

### Individual

Sol: 
  
* Inicio implementación SVD en Python, utilizando descenso en gradiente estocástico, SGD, por sus siglas en inglés.

* [Aprendizaje con descenso en gradiente estocástico con datos de gran escala](http://khalilghorbal.info/assets/spa/papers/ML_GradDescent.pdf)




Iker:

*	Importación de datos: base Movie Lens con 100,000 registros (cifra redondeada), sólo la tabla con los usuarios y calificaciones. 
	*	El archivo está como csv
* Cálculo del promedio de calificaciones por cada usuario.
* Cálculo del promedio de calificaciones por cada película.
* Normalización (Centrado) de datos (usuarios y películas).
* Cálculo de probabilidades de seleccionar columnas y renglones.
* Implementación de algoritmo para la Descomposición CUR.
* Implementación de función para el cálculo del error cuadrático medio.
* Implementación de función para el cálculo del Coeficiente de Correlación de Spearman
* Pruebas del algoritmo para Descomposición CUR
	*	Selección de 600 renglones y 600 columnas para conjunto de 100,000 registros, resultado: SVD no converge. 
	*	Selección de 90 renglones y 90 columnas para conjunto de 100,000 registros, no se tiene error
* Implementación de algoritmo para la Descomposición en Valores Singulares (SVD).
* Pruebas del algoritmo para el cálculo de SVD.
* Cálculo de tiempos en ambos casos. 
	
	
	
Luis:

* ["Tradeoffs" de aprandizaje con datos en gran escala](https://leon.bottou.org/publications/pdf/nips-2007.pdf)

* Comenzar a unificar los resumenes elaborados y producir el trabajo escrito hasta la base teorica [resumen](https://github.com/luis58/recommendation_algorithms/blob/master/documentaci%C3%B3n/Reducci%C3%B3n%20de%20dimensionalidad%20(Leskovec).docx) 

* Revisar material compartido por el profesor en el [repositorio](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/Python/PyCUDA)






