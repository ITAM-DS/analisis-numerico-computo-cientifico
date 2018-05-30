# Lista de proyectos:

---

## [Equipo 1](equipos/equipo_01)

Ttulo del proyecto: `Implementación de método de optimización convexa con mínimos cuadrados, a través de descenso en gradiente estocástico`

Objetivo del proyecto: objetivo

[Avances del proyecto](equipos/equipo_01):

* [Avance 10-04-18](equipos/equipo_01/avance_10_04_18): Ok con el cambio de tema. Añadan md's para que directamente pueda leerlos de la página de github y borren los Rmd's, .tex o html's, esos no los suban al repo xfa. Detallen el trabajo individual para el siguiente avance y califique a cada persona (está bien que hayan puesto el trabajo en equipo). Coloquen en su carpeta inicial las referencias (vean el [equipo_ejemplo](equipos/equipo_ejemplo)). Escriban el objetivo de su proyecto (vean el [equipo_ejemplo](equipos/equipo_ejemplo)).

* [Avance 17-04-18](equipos/equipo_01/avance_17_04_18): Super con su avance tanto en trabajo como en código. ¿Liz los datos son los mismos que usó Daniel para el programa `min_cuadrados_basico.c`? me parece que no pero podrías documentar qué datos, dimensiones se usan para este programa? si deseas en el mismo código o en la sección de [aquí](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/mno-2018-1/proyecto_final/proyectos/equipos/equipo_01/avance_17_04_18/codigo) o [aquí](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/mno-2018-1/proyecto_final/proyectos/equipos/equipo_01/avance_17_04_18) porque me quedó duda las dimensiones de tus datos y al final se obtiene un polinomio de grado 2 y ¿eso lo usarán para comparar?. Bien Daniel con tu trabajo. Cristian en la sección de Métodos de optimización del trabajo ¿podrías detallar el uso del operador de proyección? ¿qué ganancia se tiene el utilizar tal operador?

* [Avance 24-04-18](equipos/equipo_01/avance_24_04_18): Revisen la ecuación de la página 2 después de las palabras: "Operando con ellas", la parte de en medio en específico. En la página 5 el cuadro del Algorithm 1 definan qué es THETA  (lo mencionan en la sección de Notación pero lo pueden añadir en la línea de Input). En la parte de notación de la página 5 también se hace mención al conjunto de matrices definidas positivas pero en el libro de Boyd & Vandenberghe utilizan dos signos positivos para este conjunto. Al final de la página 5 sólo es algo en español el Hessiano cambien por la Hessiana (es una matriz, la matriz Hessiana). En la página 6 hay un signo de interrogación que se ve como un typo en las referencias de AMSGRAD y también para AMSGRAD definan qué es beta_1 y beta_2. No encontré el programa de `min_cuadrados_basico.c` con la actualización de este avance (lectura de archivo) añádenlo en el siguiente avance xfa. Falta colocar su objetivo y ligas a su trabajo escrito como [equipo_ejemplo](equipos/equipo_ejemplo) en equipo_01/README.md.


* [Avance 02-05-18](equipos/equipo_01/avance_02_05_18): Está bajando la RSS pero también monitoreen la norma del gradiente de la función objetivo, el valor de la función y utilicen un `while` en lugar de un `for`; como criterio de paro utilicen un valor de máximo de iteraciones y la norma antes mencionada con una tolerancia por ejemplo de 10 ^(-12). En cada iteración impriman tal norma. Muy bien sus avances, son muy claros. Daniel me preguntó sobre unified memory en CUDA ¿podrían poner tal pregunta? relacionada con c++.

---

## [Equipo 2](equipos/equipo_02)

Ttulo del proyecto: `Cholesky Factorization`

Objetivo del proyecto: El objetivo de este trabajo consiste en aprovechar las oportunidades creadas o generadas por las tecnologías actuales para la paralelización de rutinas del cálculo numérico, para cuestiones de este trabajo y para la implementación de alguna de los paradigmas de programación vistos en la clase de Análisis Numérico y Computo Científico. Se hará uso de openMP para la factorización Cholesky.

[Avances del proyecto](equipos/equipo_02):

* [Avance 10-04-18](equipos/equipo_02/avance_10_04_18): No suban html's, Rmd's. xfa borren el .html. No hay avance entonces no tengo qué calificar :( faltan carpetas, referencias (vean el [equipo_ejemplo](equipos/equipo_ejemplo)). Coloquen las referencias que usarán para su proyecto en su carpeta inicial (ver [equipo_ejemplo](equipos/equipo_ejemplo)) (una vez definidas).

* [Avance 17-04-2018](equipos/equipo_02/avance_17_04_2018): Bien sus referencias, los autores Dongarra y Demmel son de los más importantes en cuestión del álgebra lineal numérica. Coloquen las referencias que usarán para su proyecto en su carpeta inicial y también su implementación. LAPACK tiene la factorización de Cholesky pueden revisarla, está bien que hayan buscado otra implementación pero aprovechen lo que vieron en las tareas, en las notas que encuentran en el repo (tema 3, cómputo matricial) también está descrita tal factorización en una forma con tres fors (como tienen [aquí](https://github.com/alexnivi/analisis-numerico-computo-cientifico/blob/mno-2018-1/proyecto_final/proyectos/equipos/equipo_02/avance_17_04_2018/implementacion/choleskyEjemplo.c)) y en una forma block-wise, está basado en el libro de matrix computations de Golub y Van Loan, Héctor y Uriel me parece que este libro les ayudará también. Revisen SCALAPACK. El año pasado un equipo implementó Cholesky en CUDA, también pueden revisar esto para su siguiente avance. Di click a las referencias y me llevó a una página de dropbox que me pedía iniciar sesión. Remuevan el README.html de su carpeta inicial xfa.

* [Avance 24-04-2018](equipos/equipo_02/avance_24_04_2018): Gracias por sus referencias en su README de su carpeta inicial (equipo_02/README.md) pero la liga que se llama Dropbox me pide iniciar sesión y vi en mi correo que me enviaron la invitación pero mejor si escriben una por una las referencias que tengan en esta liga. Vayan realizando su trabajo escrito con introducción, algoritmos a utilizar para Cholesky y se puedan leer mejor la escritura matemática que reporta Uriel para este avance. No tienen que poner una liga [referencia](https://docs.google.com/document/d/1_VOtnyJGHTWvyHCHC9L-mSRSNSslY22qrSikXzquL2g/edit?ts=5ad56af8) con una bitácora de todos los avances. Falta en equipo_02/README.md colocar su objetivo y ligas a su trabajo escrito como [equipo_ejemplo](equipos/equipo_ejemplo). Para algoritmos de optimización usen Boyd & Vandenbergue parte 3 (capítulos 9, 10 y 11) y el libro de Nocedal & Wright de numerical optimization. La referencia de introduction to random signals and applied kalman filtering pdf, no la pude visualizar, pueden arreglar esto? Remuevan y cambien nombre a esto: equipos/equipo_02/avance_24_04_2018/implementacio\314\201n/ (no es buena idea colocar espacios o acentos en bash, no importa la ortografía).

* [Avance 02-05-2018](equipos/equipo_02/avance_02_05_2018): Gracias por sus ligas a su trabajo escrito en su equipo_02/README.md pero como el comentario del avance anterior ésta liga conduce a un documento que tiene secciones de avance de cada persona, esto no lo coloquen como su trabajo escrito, o no he visto la liga al trabajo escrito (hacia google docs que menciona Uriel en este avance) o no la han puesto, revisen esto. Para la liga de Dropbox que está en su equipo_02/README.md en la sección de referencias vean el comentario de avance anterior. Muy buenas referencias que proporciona Alejandro ¿quizás añadirlas en el equipo_02/README.md? (si es que serán de utilidad para el objetivo de su proyecto o enmarcaran la factorización de Cholesky en los objetivos de los papers). Cuidado con el archivo de nombre [verosim.c](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/mno-2018-1/proyecto_final/proyectos/equipos/equipo_02/avance_02_05_2018/implementacion/verosim.c) pues hasta el final aparece no lenguaje de C. Remuevan y cambien nombre a esto: equipos/equipo_02/avance_24_04_2018/implementacio\314\201n/ (no es buena idea colocar espacios o acentos en bash, no importa la ortografía). Pueden usar lo hecho en tareas 5, 6 para lectura de archivos de texto, imprimir vectores, matrices y manejo de arreglos de 1d y 2d en forma column major (sugerencia).

---

## [Equipo 3](equipos/equipo_03)

Ttulo del proyecto: `Factorización de Matriz usando factorización QR`

Objetivo del proyecto: Paralelizar factorización QR

[Avances del proyecto](equipos/equipo_03):

* [Avance 10-04-18](equipos/equipo_03/avance_10_04_2018): [referencia QR en Map Reduce](https://arxiv.org/abs/1301.1071).  Buen avance, gracias por el detalle de cada uno. [Aquí] referencias para la factorización QR en paralelo. El [equipo9](equipos/equipo_09) también revisa QR, debemos definir qué hará cada equipo. Coloquen las referencias que usarán para su proyecto en su carpeta inicial (ver [equipo_ejemplo](equipos/equipo_ejemplo)) (una vez definidas). Di click en dropbox y me pide iniciar sesión.

* [Avance 17-04-18](equipos/equipo_03/avance_17_04_2018): Para implementación de QR pueden revisar las notas de cómputo matricial del repo (tema 3) que están basadas en el libro de matrix computations de Golub y Van Loan y la factorización QR está implementada en LAPACK, pueden usarla. Revisen de igual forma SCALAPACK. Por su descripción Map Reduce podrían considerarlo en otro tiempo, ahora dediquen esfuerzos para la QR con  una implementación para el siguiente avance (puede ser lo de LAPACK que les mencionaba).

* [Avance 24-04-18](equipos/equipo_03/avance_24_04_2018): Diego, sube tus implementaciones al repo, no son pesadas (kb's), y añade outputs de tus ejecuciones, puedes usar lo hecho en tareas 5, 6 para lectura de archivos de texto, imprimir vectores, matrices y manejo de arreglos de 1d y 2d (sugerencia). Rafael sí, inicien el trabajo escrito para el siguiente avance, el autor Dongarra ha sido y continúa siendo muy importante en el álgebra lineal numérica. Víctor, sube tus implementaciones al repo y añade outputs de tus ejecuciones. Para esto aprovechen el markdown. También pueden usar lo de las tareas 5, 6 para leer de archivos, imprimir vectores, matrices y manejo de arreglos 1d y 2d (sugerencia). Una vez inicien el trabajo escrito, coloquen la liga al mismo como [equipo_ejemplo](equipos/equipo_ejemplo) en equipo_03/README.md.

* [Avance 02-05-18](equipos/equipo_03/avance_02_05_2018): Su trabajo escrito está muy bien :) y buena descripción individual. Nuevamente comentarios del avance pasado para su output y lectura de datos con funciones y definiciones ya creadas.

---

## [Equipo 4](equipos/equipo_04)

Ttulo del proyecto: `Reconocimiento de caras utilizando cómputo en paralelo.`

Objetivo del proyecto: El objetivo de nuestro proyecto es la construcción de un sistema de detección de rostros con la capacidad de obtener la identidad de los rostros dada una base de datos de imágenes.

[Avances del proyecto](equipos/equipo_04):

* [Avance 10-04-18](equipos/equipo_04/avance_10_04_18)

* [Avance 17-04-2018](equipos/equipo_04/avance_17_04_2018)

* [Avance 24-04-2018](equipos/equipo_04/avance_24_04_2018)

* [Avance 02-05-2018](equipos/equipo_04/avance_02_05_2018)

* [Avance 08-05-2018](equipos/equipo_04/avance_08_05_2018)


[Trabajo escrito](falta liga, coloquen la liga en su readme de su carpeta de equipos/equipo_04)

[Presentacion](falta liga, coloquen la liga en su readme de su carpeta de equipos/equipo_04 como el del trabajo escrito)

[Implementacion](coloquen la liga en su readme de su carpeta de equipos/equipo_04 como el de la presentación y trabajo escrito) Coloquen una descripción de cómo ejecutar el código, qué datos usar, output de muestra y resultado en un README.md.

---

## [Equipo 5](equipos/equipo_05)

Ttulo del proyecto: `Proyecto Balanceo Línea`

Objetivo del proyecto: Encontrar la distribución óptima de las actividades requeridas para elaborar un producto entre cierto número de estaciones, minimizando el tiempo de ciclo y cumpliendo con las restricciones establecidas. 

[Avances del proyecto](equipos/equipo_05):

* [Avance 10-04-18](equipos/equipo_05/avance_10_04_2018)

* [Avance 17-04-18](equipos/equipo_05/avance_17_04_2018)

* [Avance 24-04-18](equipos/equipo_05/avance_24_04_2018)

* [Avance 01-05-18](equipos/equipo_05/avance_01_05_2018)

* [Avance 08-05-18](equipos/equipo_05/avance_08_05_2018)



Coloquen referencias en el readme de equipos/equipo_05 de Klein & Scholl, Armin, algoritmo depth first y otras que uds consideren

[Trabajo escrito](Falta liga en readme de carpeta equipos/equipo_05)

[Presentacion](falta liga a presentación en readme de carpeta equipos/equipo_05)

[Implementacion] Coloquen una descripción de cómo ejecutar el código, qué datos usar, output de muestra y resultado en un README.md.

---

## [Equipo 6](equipos/equipo_6)

Ttulo del proyecto: `Generating a Random Collection of Discrete Joint Probability Distributions Subject to Partial Information`

Objetivo del proyecto: Paralelizar en GPU un algoritmo de Hit & Run definido por restricciones lineales aplicada a distribuciones de probabilidad discretas

[Avances del proyecto](equipos/equipo_6):

* [Avance 10-04-2018](equipos/equipo_6/avance_10_04_2018)

* [Avance 17-04-2018](equipos/equipo_6/avance_17_04_2018)

* [Avance 01-05-2018](equipos/equipo_6/avance_1_05_2018)

* [Avance 08-05-2018](equipos/equipo_6/avance_8_05_2018)

* [Avance 22-05-2018](equipos/equipo_6/avance_22_05_2018)


Coloquen referencias en el readme de equipos/equipo_07 de los posts, MKL, MAGMA

[Trabajo escrito](Falta liga en readme de carpeta equipos/equipo_6)

[Presentacion](falta liga, coloquen la liga en su readme de su carpeta de equipos/equipo_6 como el del trabajo escrito)

[Implementacion](coloquen la liga en su readme de su carpeta de equipos/equipo_6 como el de la presentación y trabajo escrito) Coloquen una descripción de cómo ejecutar el código, qué datos usar, output de muestra y resultado en un README.md.




---

## [Equipo 7](equipos/equipo_07)

Ttulo del proyecto: `PCA, implementación en C. Secuencial / Paralelo`

Objetivo del proyecto: Implementar el método de “Principal Component Analysis” (PCA) en C, posteriormente de manera secuencial y posteriormente en paralelo. Este trabajo será complementado con lenguajes de alto nivel (ej. R, Python).

[Avances del proyecto](equipos/equipo_07):

* [Avance 10-04-18](equipos/equipo_07/avance_10_04_2018)

* [Avance 17-04-18](equipos/equipo_07/avance_17_04_2018)

* [Avance 24-04-18](equipos/equipo_07/avance_24_04_2018)

* [Avance 02-05-18](equipos/equipo_07/avance_02_05_2018)

* [Avance 22-05-18](equipos/equipo_07/avance_22_05_2018)

Coloquen referencias en el readme de equipos/equipo_07

[Trabajo escrito](Falta liga en readme de carpeta equipos/equipo_07)

[Presentacion](falta liga, coloquen la liga en su readme de su carpeta de equipos/equipo_07 como el del trabajo escrito)

[Implementacion](coloquen la liga en su readme de su carpeta de equipos/equipo_07 como el de la presentación y trabajo escrito) Coloquen una descripción de cómo ejecutar el código, qué datos usar, output de muestra y resultado en un README.md.

---

## [Equipo 8](equipos/equipo_8)

Ttulo del proyecto: `Método de descenso en gradiente en juegos de Cournot`

Objetivo del proyecto: Implementar el método de descenso en gradiente para encontrar el equilibrio de Cournot-Nash de un juego de Cournot.

[Avances del proyecto](equipos/equipo_8):

* [Avance 10-04-18](equipos/equipo_8/avance_10_04_18)

* [Avance 17-04-18](equipos/equipo_8/avance_17_04_18)

* [Avance 24-04-18](equipos/equipo_8/avance_24_04_18)


* [Avance 02-05-18](equipos/equipo_8/entrega_02_05_18)

* [Avance 08-05-2018](equipos/equipo_8/avance_08_05_2018)

[Trabajo escrito](https://www.dropbox.com/sh/hdty83mu03hoiy8/AAC_-McE3iFrOt6bFdsGHfPIa?dl=0) Que la liga lleve directo al trabajo escrito (no a un folder de dropbox). Falta que arreglen palabras que les pedí cambiaran en el avance del 2 de mayo.

[Presentacion](falta liga, coloquen la liga en su readme de su carpeta de equipos/equipo_8 como el del trabajo escrito)

[Implementacion](coloquen la liga en su readme de su carpeta de equipos/equipo_8 como el de la presentación y trabajo escrito) Coloquen una descripción de cómo ejecutar el código, qué datos usar, output de muestra y resultado en un README.md.

---

## [Equipo 9](equipos/equipo_09)

Ttulo del proyecto: `Mínimos Cuadrados usando la Factorización QR y CUDA`

Objetivo del proyecto: Implementar el algoritmo QR para el lenguaje de programación C bajo un enforque de programación en paralelo.

[Avances del proyecto](equipos/equipo_09):

* [Avance 10-04-18](equipos/equipo_09/avance_10_04_2018)

* [Avance 17-04-18](equipos/equipo_09/avance_17_04_2018)

* [Avance 24-04-18](equipos/equipo_09/avance_24_04_2018)


* [Avance 02-05-18](equipos/equipo_09/avance_02_05_2018)

* [Avance 08-05-18](equipos/equipo_09/avance_08_05_2018)

[Trabajo escrito](https://drive.google.com/drive/folders/1EkRomjpJLi_mLgXNvKZA1uizJJKIVNlk) Que la liga lleve directo al trabajo escrito (no volver a dar click en un folder de google drive)

[Presentacion](https://drive.google.com/drive/folders/1KN2nghXPG8c8GwU9f5t46snOMRBbrf-F) Que la liga lleve directo al trabajo escrito (no volver a dar click en un folder de google drive)

[Implementacion](equipos/equipo_09/codigo/MCQR.cu) Coloquen una descripción de cómo ejecutar el código, qué datos usar, output de muestra y resultado en un README.md.

---

## [Equipo 10](equipos/equipo_10)

Ttulo del proyecto: `SVD para sistemas de recomendación`

Objetivo del proyecto: Desarrollar un algoritmo de sistemas de recomendación basado en descomposición SVD en paralelo

[Avances del proyecto](equipos/equipo_10):

* [Avance 10-04-18](equipos/equipo_10/Avance_10_04_18)

* [Avance 17-04-18](equipos/equipo_10/Avance_17_04_18)

* [Avance 24-04-18](equipos/equipo_10/Avance_24_04_18)

* [Avance 02-05-18](equipos/equipo_10/Avance_02_05_18)

* [Avance 08-05-18](equipos/equipo_10/Avance_08_05_18)

[Trabajo escrito](https://drive.google.com/open?id=1z-b_zTksXNujDiJc2sg_0eJND8RpjNmE)

[Presentacion](liga hacia presentacion)

[Implementacion](equipos/equipo_10/Implementacion)


---

## [Equipo 11](equipos/equipo_11)

Ttulo del proyecto: `Implementación de algoritmo Dijkstra`

Objetivo del proyecto: Implementar el algoritmo Dijkstra en C y su versión en paralelo.

[Avances del proyecto](equipos/equipo_11):

* [Avance 10-04-18](equipos/equipo_11/avance_10_04_18)

* [Avance 17-04-18](equipos/equipo_11/avance_17_04_18)

* [Avance 24-04-18](equipos/equipo_11/avance_24_04_18)

* [Avance 01-05-18](equipos/equipo_11/avance_01_05_18)

* [Avance 08-05-18](equipos/equipo_11/avance_08_05_18)

[Trabajo escrito](https://drive.google.com/open?id=1_edvCMJje75oSF46WjvKv6OmfmkKxOAo)

[Presentacion](liga hacia presentacion)

[Implementacion](equipos/equipo_11/22_05/codigo) Coloquen una descripción de cómo ejecutar el código, qué datos usar, output de muestra y resultado en un README.md.

---

## [Equipo 12](equipos/equipo_12)

Ttulo del proyecto: `Generación de método aleatorios mediante algoritmos implementados en C.`

Objetivo del proyecto: Programar un algoritmo para la generación de una cadena de número aleatorios, optimizando su longitud. Medir su eficiencia a través de distintos criterios como pruebas de aleatoriedad, longitud de la cadena generada y la comparación con otras cadenas de números aleatorios obtenidos por fuentes naturales de aleatoriedad como procesos cuánticos: fotones y partículas.

[Avances del proyecto](equipos/equipo_12)

* [Avance 10-04-18](equipos/equipo_12/avance_10_04_18)

* [Avance 17-04-18](equipos/equipo_12/avance_17_04_18)

* [Avance 24-04-18](equipos/equipo_12/avance_24_04_18)

* [Avance 02-05-18](equipos/equipo_12/avance_02_05_18)

* [Avance 08-05-18](equipos/equipo_12/avance_08_05_18)

[Trabajo escrito](falta liga, coloquen la liga en su readme de su carpeta de equipos/equipo_12)

[Presentacion](falta liga, coloquen la liga en su readme de su carpeta de equipos/equipo_12 como el del trabajo escrito. Revisen que las ligas se visualizan correctamente)

[Implementacion](coloquen la liga en su readme de su carpeta de equipos/equipo_12 como el de la presentación y trabajo escrito) Coloquen una descripción de cómo ejecutar el código, qué datos usar, output de muestra y resultado en un README.md.

---

## [Equipo 13](equipos/equipo_13)

Ttulo del proyecto: `Cálculo del AUC`

Objetivo del proyecto: Implementación de un algoritmo para el cálculo del área bajo la curva (AUC) de forma paralela.

[Avances del proyecto](equipos/equipo_13):

* [Avance 10-04-18](equipos/equipo_13/avance_10_04_2018)

* [Avance 17-04-18](equipos/equipo_13/avance_17_04_2018)

* [Avance 24-04-18](equipos/equipo_13/avance_24_04_2018)

* [Avance 02-05-18](equipos/equipo_13/avance_02_05_2018)

* [Avance 08-05-18](equipos/equipo_13/avance_08_05_2018)


Renombren a sus referencias en el README.md de equipos/equipo_13 de modo que sean los títulos en lugar de direcciones de internet

[Trabajo escrito](coloquen la liga en su readme de su carpeta de equipos/equipo_13, que la liga lleve directamente al trabajo y no a una carpeta con contenido. Hay algunos typos y faltas de ortografía en su documento escrito, revísenlas)

[Presentacion](coloquen la liga en su readme de su carpeta de equipos/equipo_13 como el del trabajo escrito)

[Implementacion](coloquen la liga en su readme de su carpeta de equipos/equipo_13 como el de la presentación y trabajo escrito) Coloquen una descripción de cómo ejecutar el código, qué datos usar, output de muestra y resultado en un README.md.


---

## [Equipo 14](equipos/equipo_14)

Ttulo del proyecto: `Multiplicación de matrices en paralelo`

Objetivo del proyecto: implementación de un algoritmo para la multiplicación de matrices en paralelo. 

[Avances del proyecto](equipos/equipo_14):

* [Avance 10-04-18](equipos/equipo_14/avance_10_04_2018): Buen avance, gracias por la descripción individual. Coloquen las referencias que usarán para su proyecto en su carpeta inicial (ver [equipo_ejemplo](equipos/equipo_ejemplo)) (una vez definidas).

* [Avance 17-04-18](equipos/equipo_14/avance_17_04_2018): Revisen el libro de P. Pacheco, parallel programming with MPI para la multiplicación de matrices. 


* [Avance 24-04-18](equipos/equipo_14/avance_24_04_2018): Remuevan y cambien nombre a esto: equipos/equipo_14/Co\314\201digo/ (no es buena idea colocar espacios o acentos en bash, no importa la ortografía) pero gracias por esa carpeta y su readme fue de ayuda. Empiecen con el trabajo escrito, ya han investigado lo de paralelizar la multiplicación de matrices en openmp y lo de eficiencia, eso lo pueden ir añadiendo a su trabajo escrito, no lo dejen para semana de finales. Modifiqué recientemente el archivo de `definiciones.h` para manejo de arreglos-2d, vi Alex que tienes `entrada(C,i,j,M)` me parece que con la modificación que hice no requieres pasar la M en esta macro, revísenlo.

* [Avance 02-05-18](equipos/equipo_14/avance_02_05_2018): Gracias por cambiar el nombre a la carpeta de Codigo. Coloquen las ligas al trabajo escrito y presentación en su carpeta inicial: equipo_14/README.md como [equipo_ejemplo](equipos/equipo_ejemplo/). Vi que tienen `entrada(C,i,j,M)` me parece que con la modificación que hice (al archivo de [definiciones.h](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/BLAS/ejemplos) no requieres pasar la M en esta macro, revísenlo. Ok con el avance del trabajo escrito, continuén en su desarrollo.

---

## [Equipo ejemplo](equipos/equipo_ejemplo)

Ttulo del proyecto: `Ejemplo`

Objetivo del proyecto: objetivo

[Avances del proyecto](equipos/equipo_ejemplo):

* [Avance 07-04-2017](equipos/equipo_ejemplo/avance_07_04_2017)

* [Avance 17-04-2017](equipos/equipo_ejemplo/avance_17_04_2017)

[Trabajo escrito](liga hacia trabajo escrito)

[Presentacion](liga hacia presentacion)

[Implementacion](liga hacia implementacion)
