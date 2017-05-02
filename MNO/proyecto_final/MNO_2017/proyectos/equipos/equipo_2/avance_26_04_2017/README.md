Avance\_26\_04\_2017
================

Integrantes
-----------

-   Mónica Ballesteros
-   Ariana López
-   Fabiola Cerón

Trabajo:
--------

### Individual:

**Mónica Ballesteros**

Discusión para unificar la teoría estudiada sobre factorización QR enfocándose en el vector de Householder.  

**Ariana López**

Discusión para unificar la teoría estudiada sobre factorización QR enfocándose en la matriz de reflexión.

**Fabiola Cerón**

Discusión para unificar la teoría estudiada sobre factorización QR enfocándose en cómo trasladar el algoritmo a la lógica de programación.

### Equipo:

* En esta entrega el trabajo fue principalmente en equipo puesto que lo que buscamos era comenzar la implementación del algoritmo que genera el el vector de Householder y debatir su función en la factorización QR.

* Luego de la lectura, principalmente de las notas de Erick y el libro [Golub, Van Loan](https://drive.google.com/file/d/0B5IJ1w6MjxegWGg4V1pDbFhaSzQ/view?usp=sharing), repasamos el cálculo del vector de Househoulder, donde entendimos que en la práctica se normaliza, v(1)=1, quedando v(2:m) como la parte esencial del vector, y su implicación en el almacenamiento y sobreescritura en x(2:m).

* Del 5.2.2 y 5.2.1 de Golub y Notas del Profesor (a partir de pag. 48), revisamos la factorización QR, y su solución con matrices de Householder, donde se realizan n pasos, obteniendo Hn,… H1A=R (producto de matrices ortogonales que logran generar una matriz triangular superior), Q=H1,H2,..Hn, obteniendo así A=QR, operando sobre submatrices, logrando hacer 0 en todas las posiciones debajo de la diagonal por columna en cada paso, el cual representa una ventaja, por ejemplo, respecto de las rotaciones de Givens.

* Algoritmo de cálculo de vector Householder. Llevamos a cabo paso a paso el cálculo del vector de Householder basado en el algoritmo de las notas de Erick y el libro [Golub, Van Loan](https://drive.google.com/file/d/0B5IJ1w6MjxegWGg4V1pDbFhaSzQ/view?usp=sharing).  Entendimos cuáles son las funciones principales requeridas por este algoritmo, las cuales se encuentran el archivo [Funciones](Funciones.c).  Estamos ya programando este algoritmo y seguimos los siguentes pasos:

	+ Creamos una función que recibe un vector x y regresa beta y v (vector de Householder)
	+ Calculamos el producto punto de x a partir de la segunda entrada (función norma2 del archivo Funciones.c)
	+ Calculamos la norma euclidiana de x (función norma)
	+ Creamos el vector v1 con 1 en la primer entrada y el resto del vector toma los valores del vector original x
	+ Se verifica en primer lugar la magnitud de la norma y después el signo del primer elemento del vector
		- En el caso de que la norma es igual a cero no entendemos por qué beta se asigna como 0 o -2 dependiendo del signo
		- En el caso de que la norma es distinta de cero dependiendo del signo de la primer entrada se realiza el cálculo del vector
	+ Calculamos v1 normalizada y actualizamos v1
	+ Calculamos beta
	+ Obtenemos lo insumos para la siguiente función: R que calculará R=Im-betavvT

* Entendimos cómo es que este vector produce ceros bajo la diagonal en la factorización QR

* En el siguiente avance entrgaremos el algoritmo QR secuencial terminado