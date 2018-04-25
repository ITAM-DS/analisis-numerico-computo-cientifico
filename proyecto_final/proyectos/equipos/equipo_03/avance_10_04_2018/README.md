# Avance 10/04/2018

## Integrantes:

* Diego Alejandro Estrada Rivera    

* Rafael Larrazolo de la Cruz       

* Victor QUintero Mármol González   

## Título del proyecto: Factorización de Matriz usando factorización QR

### Individual

Diego: 

Lei Capítulo 4 del libro Álgebra Lineal de Stanley I. Grossman con el objetivo de refrescar términos básicos como matriz ortogonal, bases ortonormales y proyecciones, entre otros. Posteriormente leí del libro [Matrix Computations,](https://www.dropbox.com/s/v115gmvcvo81g2l/Matrix%20Computations%20by%20Golub%20G.H.%2C%20Van%20Loan%20C.F.pdf?dl=0) la parte referente al método Gram-Schmidt del capítulo 5 (pags. 230 - 233) uno de los 3 métodos más empleados para llevar a cabo la factorización QR. Se habla específicamente de los algoritmos clásico y modificado, y se especifican las diferencias computacionales entre ambos. Me apoyé también del siguiente [ejemplo](https://www.dropbox.com/s/d63fbwugkssfj8c/QR%20Gram%20Schmidt.pdf?dl=0) fácil y rápido de seguir a mano para finalizar la comprensión de la teoría vista. Posteriormente, leí el siguiente [paper](https://www.dropbox.com/s/yzci44fk7y5cd7t/Parallel%20Implementation%20of%20Classical%20Gram-Schmidt%0AOrthogonalization%20on%20CUDA%20Graphics%20Cards.pdf?dl=0) donde se da un idea general acerca de una implementación en CUDA del algoritmo clásico de Gram-Schmidt, le dí especial atención a como usan la paralelización para realizar simultáneamente términos comunes de la sumatoria del algoritmo clásico.

Rafael:

Una vez que definimos que nuestro tema para nuestro proyecto sería la factorización QR, leí la seccíón 6.2 del libro Linear Algebra (*Friedberg, Insel, Spence, 2003. 4a Edición*) el cual trata del proceso de ortogonalización de Gram-Schmidt, esto con la intención de recordar los conceptos y el procedimiento para crear bases ortonormales de un espacio vectorial.

Posteriormente repasé mis notas referentes a la descomposición QR de Álgebra Lineal de la licienciatura. En éstas únicamente encontré la definición de la descomposición y un pequeño ejemplo a mano aplicado a la solución de un problema de mínimos cuadrados; en este ejemplo, el procedimiento usado para la descomposición fue el proceso de Gram-Schmidt. Siguiendo con mis notas de licenciatura, también revisé mis apuntes de Cálculo Numérico donde vimos la motivación de la factorización QR y también implementamos un algoritmo en Matlab para obtener dicha descomposición aunque noté que también el algoritmo hacia uso del proceso de Gram-Schmidt. 

Por otra parte, revisé las [diapositivas](https://courses.engr.illinois.edu/cs554/fa2013/notes/11_qr.pdf) del Departamento de Cómputo Científico de la Univerdad de Illinois que describen el funcionamiento de la factorización QR haciendo uso de algoritmos en paralelo. En estas notas mencionan las *Transformaciones Householder* y *Rotaciones de Givens* las cuales personalmente no conocía. 

Para este avance quise darle más énfasis a la [Rotación de Givens](https://en.wikipedia.org/wiki/Givens_rotation) para entender su concepto y funcionamiento. Este procedimiento trata de la representación en forma de matriz de una rotación en un plano. Aparentemente este procedimiento tiene la ventaja sobre otros métodos que es paralelizable y que suele llevar a cabo un menor número de operaciones para matrices ralas (con muchos ceros). El procedimiento, después de la multiplicación de varias matrices de rotación, lleva a obtener una matriz triangular superior y una matriz ortogonal, obteniendo la descomposición QR. Posteriormente me gustaría investigar sobre la implementación de este procedimiento en paralelo, y también investigar sobre las *Transformaciones Householder* para poder analizar ventajas de cada uno y discutirlo con mis compañeros de equipo. 

Victor:

Para este primer avance leí las secciones 5.1 a 5.7, 5.11 y 5.13 del libro [Matrix Analysis & Applied Linear Algebra](https://www.dropbox.com/home/Proyecto%20MNO?preview=Matrix+Analysis+%26+Applied+Linear+Algebra.pdf) para repasar temas de álgebra lineal, principalmente de ortogonalidad, el procedimiento de Gram-Schmidt y factorización QR, que fue el tema que finalmete elegimos para el proyecto final. Para repasar los conceptos de factorización QR encontre  una [presentación](http://www.seas.ucla.edu/~vandenbe/133A/lectures/qr.pdf) de la Universidad de California en Los Ángeles (UCLA) donde vienen ejercicios sencillos que pude reproducir a mano. En esa presentación también leí sobre el método Householder Reflections, el cuál me llamó la atención y decidí junto con mi equipo que me enfocaría más en ese método. En lo personal me gusta que un primer acercamiento sea algo más visual y guiado, por lo que me apoyé en diferentes [videos](https://www.youtube.com/watch?v=d-yPM-bxREs) [2](https://www.youtube.com/watch?v=DstGBMyWIQM) donde explican el método Householder.

También encontré un [artículo](https://rpubs.com/aaronsc32/qr-decomposition-householder) donde vinen ejemplos sencillos usando Householder Reflections que pude reproducir a mano y una implementación en R, que es un lenguaje con el que estoy más familiarizado, el cuál me ayudó mucho a entender como se programa un ejemplo sencillo.

Para el siguiente avance pienso leer más sobre lo que han estado investigando más a detalle mis compañeros, que son los métodos de Gram-Schmidt en CUDA y rotación de Givens.


### Equipo

Nuestro avance como equipo fue entender o recordar conceptualmente la Factorización QR y que existen diversos algoritmos o métodos para llevarla a cabo. Tenemos contemplado que los tres integrantes del equipo debemos tener claro los procedimientos que encontramos (Gram-Schimdt, Householder, Givens), cómo funcionan y las ventajas/desventajas que tienen cada uno de estos en su implementación; esto consideramos que podría ser nuestro próximo avance así como investigar su funcionamiento en paralelo. De igual modo nos resultó interesante saber que exista una implementación de la Rotación de Givens en Hadoop, lo cual nos gustaría saber a mayor profundidad.






