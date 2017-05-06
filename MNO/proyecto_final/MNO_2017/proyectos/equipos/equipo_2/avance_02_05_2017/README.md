Avance\_02\_05\_2017
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

Investigué MC y la aplicación de transformaciones Householder (QR) para resolverlo. Programé el vector de Householder con los insumos obtenidos de mu y sigma basado en las notas del Golub.  

**Ariana López**

Investigué MC y la aplicación de transformaciones Householder (QR) para resolverlo. Programé la matriz de reflexión H que se va actualizando para obtener la nueva A.

**Fabiola Cerón**

Investigué MC y la aplicación de transformaciones Householder (QR) para resolverlo. Construí la parte del código para obtener mu y sigma.

### Equipo:

* Continuando con el plan de trabajo, realizamos la lectura del Capítulo 5 de [Eldén](https://drive.google.com/file/d/0BxMtevFKwTW_aDE2Tjg1Zk1FbTQ/view?usp=sharing) y 5.3  [Golub, Van Loan](https://drive.google.com/file/d/0B5IJ1w6MjxegWGg4V1pDbFhaSzQ/view?usp=sharing) para comprender la aplicación de QR a la solución de mínimos cuadrados. La lógica de este proceso es entender que como en general Ax ≠ b para los sistemas sobredeterminados definimos un vector residuo r = b – Ax, en lugar de encontrar una solución exacta para Ax = b intentamos encontrar una x tal que r sea lo mas pequeño posible (equivalente a resolver min ||Ax-b||2). Se pueden construir transformaciones de Householder que reduzcan la matriz Amxm, con el algoritmo de thin QR, A=Q1R, resolviendo x=R-1Q1Tb de la forma Rx = Q1Tb.

* Con respecto al código de factorización QR por Householder logramos desarrollar el código secuencial en C basado en la teoría encontrada en el libro de Golub y las notas de clase. Intregramos en un solo algoritmo las funciones que habíamos identificado en el avance anterior (como producto punto, normalización, cálculo de beta, etc.).  Lo probamos con una matriz de 4x3 que calculamos a mano en la primera entrega de este proyecto, corroboramos los resultados siendo diferentes en el resultado final de A. Estamos llevando a cabo los ajustes necesarios para obtener el resultado correcto en cada sobreescritura de A.