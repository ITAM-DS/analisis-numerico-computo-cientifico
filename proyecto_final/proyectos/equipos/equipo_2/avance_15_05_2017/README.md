Avance\_15\_05\_2017
================

Integrantes
-----------

-   Mónica Ballesteros
-   Ariana López
-   Fabiola Cerón

Trabajo:
--------


### Equipo:

* De acuerdo con las referencias de [Buttari](https://drive.google.com/file/d/0BxMtevFKwTW_OW5wZVF5dFdiV2c/view?usp=sharing), comprendimos que existen funciones de LAPACK que se encuentran relacionadas con reflexiones Householder; sin embargo no todas son paralelizables.

* Para entender el funcionamiento de dichas funciones, se implementaron dos ejercicio básicos: [1](geqrf.c) y [2](geqrfp.c), donde aprendimos los parámetros que requieren así como el formato con el que se deben incorporar. De este ejercicio, no comprendimos lo que regresan las funciones.

* Las funciones encontradas de LAPACK, aplican Householder con distintos métodos: Por bloques (WY), sin bloques y por pivoteo de columnas. Desafortunadamente, el método de nuestro interés y que hemos utilizado en el desarrollo del algoritmo secuencial (Sin bloques), es nivel BLAS 2 y no es paralelizable. 

* Derivado de la revisión del proyecto con Erick y considerando los puntos anteriores:
	+ Limitamos el alcance del proyecto a implementar el código secuencial de QR aplicado a Mínimos Cuadrados.
	+ Ajustamos el calendario de trabajo.
	+ Modificaremos la estructura de las matrices para facilitar el acceso a las entradas a lo largo del algortimo.