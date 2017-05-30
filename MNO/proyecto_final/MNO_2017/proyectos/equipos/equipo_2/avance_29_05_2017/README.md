Avance\_29\_05\_2017
================

Integrantes
-----------

-   Mónica Ballesteros
-   Ariana López
-   Fabiola Cerón

Trabajo:
--------

### Equipo:

Con esta entrega damos por finalizado el proyecto.  Se logró cumplir satisfactoriamente con los objetivos planteados concluyendo lo siguiente: 

* Se demostró a través del algoritmo implementado en este trabajo, la eficiencia de las reflexiones de Householder para la factorización QR de una matriz, así como solucionar mínimos cuadrados, comprobando que la teoría investigada va de acuerdo a los resultados obtenidos.  Se pudo verificar la utilidad que representa la estrategia de la sobrescritura de la matriz A (con R y vectores de Householder) y se hizo evidente el beneficio de no almacenar Q en cada iteración.

* La estructura del lenguaje de programación de C permitió una mejor definición de las variables, objetos y funciones a utilizar lo cual facilitó la traducción del problema teórico a un algoritmo secuencial además de facilitar el acceso a los datos.

* En este trabajo se eligió el método de Householder con el fin de profundizar en las propiedades y ventajas de su uso en la factorización QR para solucionar mínimos cuadrados;  sin embargo, existen otros métodos que podrían ser mas eficientes para este tipo de problemas, por ejemplo, el método de SVD que sería de gran interés implementar en un futuro. 

**Implementación en C**: Se entregan los siguientes archivos de programación.  

    + definciones.h: Contiene la definición de las estructuras de matrices y vectores.
    + funciones2.c: Contiene todas las funciones utilizadas por la función main.         
    + mcqrhh.c: Contiene la función main, que ocupa funciones2 para realizar cálculo de QR y MC.

* Los archivos de programaciones anteriores utilizan como insumos los siguientes archivos de texto:

    + A1.txt: Contiene la matriz A a factorizar del sistema de ecuaciones.
    + b.txt: Contiene b, del sistema Ax=b.

* Se implementaron por completo los 4 algoritmos requeridos para la solución de nuestro problema: 
	+ Algoritmo para calcular QR por Reflexiones de Householder
	+ Algoritmo para calcular el Vector de Householder
	+ Algoritmo para calcular Mínimos Cuadrados por Reflexiones de Householder
	+ Algoritmo de Sustitución Hacia Atrás

* El resultado del algoritmo se encuentra en [Resultado](SalidaA1) que muestra paso a paso todo el procedimiento.

* Adicionalmente, se verifica el algoritmo programado utilizando como insumos el [ejemplo proporcionado por el profesor](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/LAPACK/ejemplos) comprobando que los resultados son correctos.  La salida de este ejercicio se presentan en [Resultado Sistema Erick](VerificacionEjercicioProfesor).

**Trabajo Escrito**: Se entrega la versión final de nuestro trabajo escrito que presenta la investigación realizada así como los resultados y la implementación: [Trabajo escrito](trabajo_escrito).

**Presentación**: Se anexa también la presentación que servirá como base para explicar nuestro proyecto en el examen final: [Presentacion](https://drive.google.com/file/d/0B5IJ1w6MjxegSlhFc2xPOW9fRE0/view?usp=sharing).




