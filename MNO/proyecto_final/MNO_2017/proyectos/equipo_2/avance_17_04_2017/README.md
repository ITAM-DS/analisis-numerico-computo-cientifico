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

Con la referencia en Golub (ejemplo 5.1.1.) pude aterrizar el concepto de trasformación de reflexión. La reflexión de Householder (P- matriz de Householder) , está basada en una transformación ortogonal con el fin de aprovechar los beneficios de sus propiedades por ser ortogonal, donde se presenta un componente principal que es un vector conocido como vector de Householder (v). Si un vector x multiplica a la matrix P, entonces se refleja x en el hiperplano span (v)^⊥, bajo la lectura de Meyer, aprecié geométricamente la dicha reflexión.

En general se busca que esa matriz P produzca más ceros en un vector a través de la correcta elección del plano de reflexión.

**Ariana López**

Realicé la lectura de las secciones 5.4 a 5.7 de Meyer y 5.1_ de Golub, explica la definición de las matrices ortogonales  <x|y> = 0 (perpendiculares entre si) y la expansión de Fourier que resuelve ‘x’ en ’n’ vectores ortogonales que representan la proyección de ‘x’ en el espacio de ‘u’, esto como preámbulo para explicar la factorización QR que solo se puede llevar a cabo si una de las matrices es ortogonal y la otra triangular superior. En la sección 5.6.2 explica los reflectores elementales (transformación de Householder) en donde se hace una proyección ortogonal de un vector ‘x’ al espacio de ‘u’. Es decir el reflector R mapea cada vector v=(x,y,z) perteneciente a R3 a su reflexion R(v)=(x,y,-z) con respecto al plano xy. Estos reflectores elementales tienen propiedades que deben de cumplirse para que R refleje ‘x’ sobre el primer eje de coordenadas. En la sección 5.1.1 de Golub muestra el Algoritmo para calcular el vector de Household que es critico para la determinación de la matrix de Household.

**Fabiola Cerón**

Leí las primeras dos referencias sugeridas por Erick para tratar de entender las Reflexiones de Householder.  El libro de Meyer me pareció mucho más complejo que el de Golub, pero con mayor sustento teórico. 

Entendí que se trata de una serie de transformaciones para llevar a cabo la triangularización de una matriz.  Lo primero es construir *Qx* = *α**ϵ* donde *Q* es unitaria *ϵ* es vector que tiene 1 en la primera entrada y ceros en el resto.  Lo que se busca es construir una matriz como para una especie de reflexión (de ahí el nombre) sobre un hiperplano tal que la simetría de *x* debe ser *α**ϵ*. Después ese hiperplano debe ser perpendicular a *v*.  También se puede hacer la reflexión de *x* sobre la dirección negativa del eje.  Los reflectores elementales de *v* se llaman reflectores de Householders y aprovechan condiciones de simetría y ortogonalidad.  Las matrices de Householder son simétricas, unitarias y su inversa es ella misma.  Además, son ortogonales. 

Se debe calcular el llamado vector de Householder.  Hice un ejercicio a mano siguiendo el pseudocódigo del algoritmo 5.1.1 del libro de Golub para entender cada paso del cálculo del vector de Householder.   

### Equipo:

Derivado de los comentarios del profesor sobre el primer avance hemos decidido cambiar el enfoque del proyecto. Ahora nos enfocaremos en factorización QR (método de reflexiones Householder) puesto que es la manera generalizada de solución de problemas de mínimos cuadrados.

Definimos un plan de trabajo, el cual se puede consultar en la carpeta principal de nuestro proyecto [Equipo 2](../).

Después de haber leído las secciones sugeridas de [Meyer](https://drive.google.com/file/d/0BxMtevFKwTW_ZmpwcDd1M0RTVzA/view?usp=sharing) y [Golub, Van Loan](https://drive.google.com/file/d/0B5IJ1w6MjxegWGg4V1pDbFhaSzQ/view?usp=sharing) discutimos los siguientes puntos:

* Cálculo del vector de Householder

* La elección del signo del vector de Householder puede tener impacto en la estabilidad numérica e influye en que una matriz *Q* pueda ser "un poco menos ortogonal", es por ello que hicimos un ejemplo muy sencillo en el que *x1* y *||x||2* son "casi" iguales y otro donde *x1* y *-||x||2* son "casi" iguales, para entender el efecto del signo.

* Debemos tener cuidado con problemas que estén mal condicionados porque los errores de redondeo pueden dar lugar a cálculos inexactos

* Nuestro algoritmo debe tomar en cuenta la elección adecuada para el signo