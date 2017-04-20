Avance\_17\_04\_2017
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

Realicé la lectura de Meyer y Golub, comprendiendo en primer lugar, definiciones de matrices ortogonales, sus propiedades como la preservación de la norma de un vector, la preservación de ortogonalidad en su inversa  y del producto de 2 matrices ortogonales, pero no siempre en la suma, entre otras.  Las definiciones anteriores son la base del entendimiento de la trasformación de reflexión HH.

Con la referencia en Golub (ejemplo 5.1.1.) pude aterrizar el concepto de trasformación de reflexión. La reflexión de Householder (P- matriz de Householder) , está basada en una transformación ortogonal con el fin de aprovechar los beneficios de sus propiedades por ser ortogonal, donde se presenta un componente principal que es un vector conocido como vector de Householder (v). Si un vector x multiplica a la matrix P, entonces se refleja x en el hiperplano span (v), bajo la lectura de Meyer, aprecié geométricamente la dicha reflexión.

En general se busca que esa matriz P produzca más ceros en un vector a través de la correcta elección del plano de reflexión.

**Ariana López**

**Fabiola Cerón**

Leía las primeras dos referencias sugeridas por Erick para entender a fondo las Reflexiones de Householder.  Entendí que se trata de una serie de transformaciones para llevar a cabo la triangularización de una matriz.  Lo primero es construir *Q**x* = *α* \* *ϵ* donde *ϵ*

### Equipo:

Derivado de los comentarios del profesor sobre el primer avance hemos decidido cambiar el enfoque del proyecto. Ahora nos enfocaremos en factorización QR (método de reflexiones Householder) puesto que es la manera generalizada de solución de problemas de mínimos cuadrados.

Definimos un plan de trabajo, el cual se puede consultar en la carpeta principal de nuestro proyecto [Equipo 2](../).

Después de haber leído las secciones 5.4 a 5.7 de [Meyer](https://drive.google.com/file/d/0BxMtevFKwTW_ZmpwcDd1M0RTVzA/view?usp=sharing) y [Golub, Van Loan](https://drive.google.com/file/d/0B5IJ1w6MjxegWGg4V1pDbFhaSzQ/view?usp=sharing) discutimos los siguientes puntos:

* Cálculo del vector de Householder
