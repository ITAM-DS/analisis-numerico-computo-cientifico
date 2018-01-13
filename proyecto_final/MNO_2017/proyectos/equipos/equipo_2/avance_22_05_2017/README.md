Avance\_22\_05\_2017
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
* Reestructuré las funciones mcol y vectorhh.

**Ariana López**
* Reestructuré la función I_Bvvt.

**Fabiola Cerón**
* Reestructuré las funciones matrix_mul y factor_form_q y comencé con la función de mínimos cuadrados MC.

### Equipo:

* Se estructuraron los archivos de programación, utilizando el esquema visto en clase: 

    + definciones.h: Contiene la definición de las estructuras de matrices y vectores.
    + funciones2.c: Contiene todas las funciones utilizadas por la función main.         
    + mcqrhh.c: Contiene la función main, que ocupa funciones2 para realizar cálculo de QR y MC.

* Los archivos de programaciones anteriores utilizan como insumos los siguientes archivos de texto:

    + A1.txt: Contiene la matriz A a factorizar del sistema de ecuaciones.
    + b.txt: Contiene b, del sistema Ax=b.

* Modificamos la estructura de las matrices en la implementación en C para facilitar el acceso a las entradas de acuerdo con los ejemplos de BLAS compartidos por el profesor. 

* El resultado del algoritmo se encuentra en [Resultado](SalidaA1), donde el Factor Form Q y R: es la matriz A actualizada, donde la parte triangular superior de A se sobreescribe con la parte triangular superior de R, y la parte esencial del vector de Householder se sobreescribe debajo de la diagonal de A.

* Se definió la estructura general del documento, con un avance al 25%.




