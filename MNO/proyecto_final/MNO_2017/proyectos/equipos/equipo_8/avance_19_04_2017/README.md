José Carlos Castro

Revisamos el algoritmo secuencial y desarrollamos varios ejemplos numericos que comparamos contra matlab, al hacerlo paso a paso pudimos observar como dependia la información arrojada de cada for para el siguiente.

for k = 1:n-1
	a_kk = (a_kk)^(1/2)
	for i = k+1:n
		a_ik = a_ik/a_kk
	end

	for j = k+1:n
		for i =j:n
			a_ij = a_ij - a_ik a_jk
		end
	end
end
a_nn = (a_nn)^(1/2)

Y aquí como detallamos más adelante notamos que vamos iterando a traves de la columna, luego para poder empezar a actualizar la columna 2 debemos conocer toda la columna 1. Ya que nuestro algoritmo es pensado para que sea óptimo en memoria, i.e que todas las entradas de A se remplacen con las de G por lo que para toda i>=j a_ij se actualiza con g_ij.


Walter Martínez Santana

En esta segunda entrega de avances estuvimos investigando acerca de la factorización de Cholesky para matrices simétricas y positiva definidas. Estudiamos el algoritmo
secuencial y nos percatamos de ciertos "peros" para llevarlo acabo en una arquitectura CUDA de manera paralela. En el análisis del algoritmo nos percatamos de que existe una dependencia
entre los valores de las columnas, es decir, para poder calcular los valores de la Columna 2, primero debo de calcular todos los valores de la Columna 1,etc. Cabe destacar que
el cálculo de cada columna inicia a partir de su elemento "diagonal" (Lii´s) y hacia abajo y no de todos los elemetos de cada una de las columnas. A consecuencia de esto, en mi opinión este factor
es determinante para plantear una solución de un algoritmo paralelo para resolverlo.
Evidentemente esto nos plantea un reto. Parte del proceso, no solo conlleva el análisis del agoritmo "clásico", sino de replantear todo desde una nueva perspectiva del problema 
desde una perspectiva algorítmica, es decir,cómo replanteamos la solución desde una perpectiva de paralelización determinada,en este caso, por una arquitecura de una GPGPU.
Lo que pretendo hacer es tratar de romper con la uniformidad a la que estamos acostumbrados de manera natural y tratar de reorganizarlo de manera que adapte a un modelo paralelo.

Las ventajas de usar ests factorización son que se puede llevar a cabo sin realizar pivoteo manteniendo la estabilidad numérica. Además, se aprovecha de que como A=L'L, 
solo tenemos que calcular una L y no debemos de recalcular, sino solo copiar los resulatdos a la otra L'. Inclusive se puede reescribir los valores en las componentes correspondientes 
de la matriz original,logrando con ello una optimización en los recursos de la memoria, reduciendo la complejidad al reducir el flujo delos datos.

referencias
-Burden, R., Faires, . Análisis Numérico. Cengage Learning. 2011.
-Heath, M. Scientific Computing: An Intriduction Survey. McGraw Hill. 2002.
