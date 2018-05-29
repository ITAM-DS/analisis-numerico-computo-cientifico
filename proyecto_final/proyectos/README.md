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

* [Avance 10-04-18](equipos/equipo_04/avance_10_04_18): Entrega tarde avance.

* [Avance 17-04-2018](equipos/equipo_04/avance_17_04_2018): Pueden usar algo ya implementado para su objetivo y realizar un trabajo descriptivo, es decir, qué método(s) se utilizó(aron), la teoría, el problema de optimización que se resuelve. Me parece la parte de computación está resuelta. Las referencias que colocan en su carpeta inicial son aquellas que les ayudan a realizar su proyecto, no es necesario que escriban cada modelo/método que existe en CV para el reconocimiento de caras.

* [Avance 24-04-2018](equipos/equipo_04/avance_24_04_2018): Están bien sus avances pero mejor si añaden ejecuciones y output de sus resultados. También ¿cómo ejecutan su programa, qué requieren instalar, con cuál ejemplo ya lo probaron? Comiencen con el trabajo escrito y añadan ligas como aquí [equipo_ejemplo](equipos/equipo_ejemplo) en equipo_04/README.md. 

* [Avance 02-05-2018](equipos/equipo_04/avance_02_05_2018): Arturo Torre, está bien lo que escribes en el README de este avance pero añádelo al trabajo escrito en la sección de introducción (por ejemplo) tiene algunos typos y uso de palabras repetidas (redacción) y la escritura matemática se leería mejor en un procesador de texto designado para ello y no el md, pero en general se entiende y sirve bien como intro, gracias por esto. Gracias por la descripción Arturo González de tu trabajo individual y de lo que se debe ir realizando paso a paso con sus códigos y datos, también añadirlo en el trabajo escrito sería buena idea. Las referencias que colocaron en este avance si van a seguir utilizándolas, escríbanlas en equipo_04/README.md y aprovecho para mencionar que mejoren esta sección de referencias adicionales, referencias Pytorch y otras referencias de este README pues ahora están amontonadas y poco legibles, mejor si ponen algo como `Implementing_face_recognition_using_a_parallel_image_processing_environment_based_on_algorithmic_skeletons` y la liga hacia esto en lugar de la página de internet. ¿Habrá algo de código de C o será el uso de pytorch-Alexnet? 


---

## [Equipo 5](equipos/equipo_05)

Ttulo del proyecto: `Proyecto Balanceo Línea`

Objetivo del proyecto: Encontrar la distribución óptima de las actividades requeridas para elaborar un producto entre cierto número de estaciones, minimizando el tiempo de ciclo y cumpliendo con las restricciones establecidas. 

[Avances del proyecto](equipos/equipo_05):

* [Avance 10-04-18](equipos/equipo_05/avance_10_04_2018): Coloquen la estructura del [equipo_ejemplo](equipos/equipo_ejemplo) en su README.md y añadan referencias en este, así me facilita la revisión. Escriban los avances/problemas que están enfrentando y el trabajo que realizaron para los mismos en sus carpetas de avances. Les puede ayudar la referencia: CUDA Programming de Shane Cook, 2013. Aunque es clara la presentación preferiría un formato que no tenga que descargar a mi máquina y usar pptx (den un link y remuevan el .pptx del repo) :). El nombre de su carpeta es "equipo_05", cambien el nombre "equipo_Paco_Miguel". Coloquen las referencias que usarán para su proyecto en su carpeta inicial (ver [equipo_ejemplo](equipos/equipo_ejemplo)) (una vez definidas).

* [Avance 17-04-18](equipos/equipo_05/avance_17_04_2018): No hay avance para esta entrega :(

* [Avance 24-04-18](equipos/equipo_05/avance_24_04_2018): Es un trabajo enorme lo que han realizado pero es difícil de seguir.  Sólo algo mínimo: cambien carpetas "2017" por "2018". Falta la liga a la documentación que mencionan en este avance. Añádanla en la carpeta inicial del README (equipo_05/README.md) y también referencias (por ejemplo: Klein & Scholl, Armin), como aquí [equipo_ejemplo](equipos/equipo_ejemplo). Inicien con el trabajo escrito. Ya acepté la invitación al repo de Paco para lo del código, son varios archivos (todos son indispensables?), quizás una documentación de lo que realiza cada archivo?  En su trabajo escrito coloquen una introducción al problema de balanceo, referencias, documentación de códigos. La presentación ayuda en este sentido pero traten de compactarla pues el día que presenten su trabajo sólo tendrán 10 min o como máximo 15 y en el trabajo escrito sí pueden escribir el contenido de ésta y más información. Entonces en resumen para el siguiente avance concéntrense en compactar la presentación, incluir un trabajo escrito con lo pedido anteriormente, escribir en su README de su carpeta inicial (equipo_05/README.md) referencias, ligas a su trabajo escrito, presentación y en lo concerniente a los archivos de código, dar una descripción o documentación de los mismos (también no sé si sirven todos esos archivos).

* [Avance 01-05-18](equipos/equipo_05/avance_01_05_2018): Gracias por borrar la carpeta de equipo_Paco_Miguel. No se atendieron los comentarios del avance pasado: cambien el nombre de carpetas "2017" por "2018" en equipo_05. Escribir en equipo_05/README.md sus referencias (por ejemplo: Klein & Scholl, Armin, algoritmo depth first y otras que uds consideren) ligas a su trabajo escrito, presentación y en lo concerniente a los archivos de código, dar una descripción o documentación de los mismos pues me pierdo fácilmente en ellos. Al usar datos o hacer referencias a códigos escriban ` balanceolinea/Data_BL/Problem_Set/LASCURAIN.IN2` para encontrar fácilmente en el repo privado.


---

## [Equipo 6](equipos/equipo_6)

Ttulo del proyecto: `Generating a Random Collection of Discrete Joint Probability Distributions Subject to Partial Information`

Objetivo del proyecto: Paralelizar en GPU un algoritmo de Hit & Run definido por restricciones lineales aplicada a distribuciones de probabilidad discretas

[Avances del proyecto](equipos/equipo_6):

* [Avance 10-04-2018](equipos/equipo_6/avance_10_04_2018): Buen avance, bien sus referencias. Coloquen las referencias que usarán para su proyecto en su carpeta inicial (ver [equipo_ejemplo](equipos/equipo_ejemplo)) (una vez definidas).

* [Avance 17-04-2018](equipos/equipo_6/avance_17_04_2018): Pueden usar funciones de LAPACK para calcular funciones sencillas como el de la norma. Buena idea utilizar lo ya hecho como lo de lpsolve. Podrían empezar a realizar el inicio de su trabajo escrito para el próximo avance.

* [Avance 24-04-2018](equipos/equipo_6/avance_24_04_2018): No hay entrega de avance.


* [Avance 1-05-2018](equipos/equipo_6/avance_1_05_2018): Coloquen la liga de su trabajo escrito e implementaciones en su equipo_6/README.md como [equipo_ejemplo](equipos/equipo_ejemplo). En las notas que encuentran en el repo (tema 3, cómputo matricial) está la factorización QR y también en el libro de Golub y Van Loan de Matrix computations para la referencia sobre proyección con reflexiones de Householder.  Los avances que consistan en lecturas de papers (además de la lectura) acompáñenlos de un borrador (mejor si tienen algo escrito en forma) en su trabajo escrito (o discusión del paper), sólo lo menciono para futuros avances, ahora estuvo bien. Las referencias que usen para su objetivo colóquenlas en equipo_6/README.md. Bien por el avance en trabajo escrito (no sé si estoy acostumbrado a la lectura en inglés pero entendí muy bien/rápido lo que escribieron, just saying) y una pregunta ¿qué indican los super índices prima de la sección 2.2?.

---

## [Equipo 7](equipos/equipo_07)

Ttulo del proyecto: `PCA, implementación en C. Secuencial / Paralelo`

Objetivo del proyecto: Implementar el método de “Principal Component Analysis” (PCA) en C, posteriormente de manera secuencial y posteriormente en paralelo. Este trabajo será complementado con lenguajes de alto nivel (ej. R, Python).

[Avances del proyecto](equipos/equipo_07):

* [Avance 10-04-18](equipos/equipo_07/avance_10_04_2018): Enmarquen el objetivo, ahora es muy general (esto se ve con el título también). Modifiquen la sección Integrantes del README del avance. Luis mejor si colocas los títulos de tus referencias en lugar de escribir la palabra referencia muchas veces (después de dar click en la última olvidé cuál era la tercera). Me parece que su enfoque es googlear algo relacionado con PCA y cómputo en paralelo, si bien es una forma de buscar me parece que una persona termina con mucha literatura y no se tiene algo concreto, creo que deberían iniciar con un problema y objetivo a resolver. Ahora tenemos: map-reduce, CUDA, Gram Schmidt, hyperspectral images, Face recognition, iterative PCA, dimensionality reduction y dicen que en dos semanas les tomará implementar los algoritmos ¿? (perdonen pero creo que si no tienen el objetivo o título definidos es muy aventurado dar una fecha). Coloquen las referencias que usarán para su proyecto en su carpeta inicial (ver [equipo_ejemplo](equipos/equipo_ejemplo)) (una vez definidas).

* [Avance 17-04-18](equipos/equipo_07/avance_17_04_2018): Bien en su avance. ¿Han hablado con el equipo 10?. Una vez tengan las referencias que les ayudará a su proyecto coloquen las mismas en la carpeta inicial de su equipo.

* [Avance 24-04-18](equipos/equipo_07/avance_24_04_2018): En su equipo_07/README.md coloquen sus referencias como [equipo_ejemplo](equipos/equipo_ejemplo). Pueden usar BLAS para las operaciones de normalización de su matriz (sugerencia). Añadan forma de compilar y output de su programa.

* [Avance 02-05-18](equipos/equipo_07/avance_02_05_2018): En su equipo_07/README.md coloquen sus referencias como [equipo_ejemplo](equipos/equipo_ejemplo) (comentario avance pasado). Falta descripción de trabajo individual o ¿tod@s realizaron lo del escalamiento? quizás una opción de realizar esto es que una persona haga una función, otra busque x librería, otra trabaje en la lectura de archivos (si es el caso) piensen en una forma de presentar su trabajo individual (está pendiente la calificación de este avance de forma individual, actualizo esto al tener su descripción individual, pueden añadirla cuando hagan el pull request para el siguiente avance). Comiencen con el trabajo escrito y coloquen la liga en equipo_07/README.md 


---

## [Equipo 8](equipos/equipo_8)

Ttulo del proyecto: `Método de descenso en gradiente en juegos de Cournot`

Objetivo del proyecto: Implementar el método de descenso en gradiente para encontrar el equilibrio de Cournot-Nash de un juego de Cournot.

[Avances del proyecto](equipos/equipo_8):

* [Avance 10-04-18](equipos/equipo_8/avance_10_04_18): No coloquen html's pues son pesados, si quieren den una liga o pueden poner un md en lugar de esto. Falta crear carpetas correspondientes. Coloquen las referencias que usarán para su proyecto en su carpeta inicial (ver [equipo_ejemplo](equipos/equipo_ejemplo)) (una vez definidas). ¿Tienen ligas a sus referencias? pregunto para que sea más fácil el acceso a ellas.


* [Avance 17-04-18](equipos/equipo_8/avance_17_04_18): Quiten el archivo Avance_10_04_2018.html en su carpeta inicial. Entiendo pero es difícil de leer: $$ \frac{\partial \pi_{i} }{\partial q_{i}} = (q_{1}+q_{2})^{-\frac{1}{n}} - \frac{1}{n}(q_{1}+q_{2})^{\frac{-1}{\eta - 1}}q_{i}-c_{i}q_{i}=0$$ ¿hay una mejor forma de desplegar esto? quizás en su trabajo escrito?. Está bien los artículos que escribe Mónica pero detalla más (y hablas de un tercero pero ¿cuál es? ¿el de Quoc et. al que está en su página de inicio de referencias), aquí hay un clásico de métodos numéricos para optimización: Numerical optimization de Nocedal & Wright. ¿Para el próximo avance tienen contemplado uso de funciones/librerías hechas en C? Para el siguiente avance finalicen la revisión de literatura y comiencen con el trabajo escrito.

* [Avance 24-04-18](equipos/equipo_8/avance_24_04_18): Gracias por remover el html. Coloquen la liga a su trabajo escrito en equipo_8/README.md como [equipo_ejemplo](equipos/equipo_ejemplo). En la página 4 al final hay algunas cosas que cambiar, por ejemplo separar la palabra "para" y hay dos "si". La figura al inicio de la página 5 no hacen referencia a ella. Están bien sus figuras aunque se ven algo borrosas, hay una forma de desplegar los algoritmos de una forma más legible con .tex, revísenla. Para el siguiente avance consideren iniciar con su implementación en C y continúen completando su trabajo escrito.


* [Avance 02-05-18](equipos/equipo_8/avance_02_05_18): Liga a su trabajo escrito no a carpeta, directamente que sea al documento. Mismo comentario que vez anterior para las figuras. Página 8 es algo sútil por el lenguaje, Jacobiano--->Jacobiana (es una matriz). Página 9 "más empinado" ---> "máximo descenso", "regla de parado" ---> "regla de paro", "colineares"--->"colineales". Página 10 "puntero"---> "apuntador" (o coloquen puntero en todos lados). Mónica, mejor en tu descripción individual del .md escribe las secciones que escribiste en el trabajo en lugar de un copy-paste. Eduardo no encontré la tabla 1.1 ni la actualización de imágenes por tablas (está pendiente tu calificación para este avance). Hay que ir resolviendo lo de la implementación en C.

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

[Implementacion](equipos/equipo_11/22_05/codigo) Coloquen una descripción de cómo ejecutar el código, qué datos usar, output de muestra y resultado en un README.md.

---

## [Equipo 10](equipos/equipo_10)

Ttulo del proyecto: `SVD para sistemas de recomendación`

Objetivo del proyecto: Desarrollar un algoritmo de sistemas de recomendación basado en descomposición SVD en paralelo

[Avances del proyecto](equipos/equipo_10):

* [Avance 10-04-18](equipos/equipo_10/Avance_10_04_18): Buen avance, gracias por la descripción individual. [Aquí] referencias para la SVD en paralelo. Coloquen las referencias que usarán para su proyecto en su carpeta inicial (ver [equipo_ejemplo](equipos/equipo_ejemplo)) (una vez definidas).

* [Avance 17-04-18](equipos/equipo_10/Avance_17_04_18): Bien en su avance. Escriban la referencia  de lo que utiliza cuSolver o MAGMA para la SVD (una liga, un párrafo) y que apoye lo que mencionan que en cuSolver una forma es con el método de Jacobi. ¿Entonces será la SVD con CUDA? Puede ser un trabajo que utilice lo ya realizado en código y se haga una descripción/investigación de lo que detrás está realizando las funciones.

* [Avance 24-04-18](equipos/equipo_10/Avance_24_04_18): Sugiero usen CUDA de forma nativa, es decir no con docker para iniciar, después podrían considerar usar docker+NVIDIA (una vez hecho pruebas con cusolver por ejemplo). Inicien con el trabajo escrito para el siguiente avance. Suban el notebook al repo en lugar que deba descargarse (es muy pesado? si no, entonces podrían añadirlo). Es probable que el examen final sea la última semana de mayo, lo menciono para que ajusten lo necesario en su cronograma. Es importante que realicen pruebas para que revisen que todo está bien con configuración de instancia, librerías necesarias y puedan seguir avanzando o resolver lo que surja. Se ve bien la configuración de la instancia (aunque la instancia no tenía tag de nombre...) añade una compilación de hello_world y output de cusolver para apoyar lo anterior que comentaba (chequeo de dependencias para CUDA y librerías necesarias).

* [Avance 02-05-18](equipos/equipo_10/Avance_02_05_18): ¿por qué falla el deviceQuery? y ¿pueden añadir descripción de trabajo individual de cada persona xfa? sus calificaciones están pendientes. El trabajo escrito busquen una mejor forma de presentarlo, .md no es buena idea y pueden utilizar  el tema 3 cómputo matricial (3.2.2, 3.6.2) y el libro de matrix computations de Golub y Van Loan para el mismo. Las referencias de su equipo_10/README.md en lugar de colocar páginas de internet coloquen los títulos o nombres

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

[Avances del proyecto](equipos/equipo_12):

* [Avance 10-04-18](equipos/equipo_12/avance_10_04_18): No hay descripción, carpetas iniciales creadas, referencias. Nada que comentar.

* [Avance 17-04-18](equipos/equipo_12/avance_17_04_18): El formato de despliegue de las referencias en su carpeta inicial no es legible, arreglen esto. El trabajo consistirá en medir ¿eficiencia? ¿probar que es posible generar números pseudo-aleatorios con cómputo en paralelo? ¿realizar pruebas para el generador de números pseudo-aleatorios, en el sentido de calidad de los números obtenidos? Para el siguiente avance definan lo anterior y empiecen con el trabajo escrito y revisen implementaciones.

* [Avance 24-04-18](equipos/equipo_12/avance_24_04_18): Dan buenas referencias en este avance ¿serán utilizadas en el objetivo de su proyecto? si es así colóquenlas en equipo_12/README.md y un comentario sobre sus referencias de este README, es mejor si colocan el título de sus referencias en lugar de las ligas con nombre de google docs pues si yo veo una por una después se me olvida cuál era la tercera. Comiencen con su trabajo escrito y lo que añade para este avance Víctor lo pueden incluir allí. Muy bien su descripción de trabajo individual, gracias por eso.


* [Avance 02-05-18](equipos/equipo_12/avance_02_05_18): añadan su trabajo escrito en equipo_12/README.md como [equipo_ejemplo](equipos/equipo_ejemplo), así como ligas a su presentación e implementación. Falta avance en trabajo escrito. Añádanlo para el avance del 8 de mayo. Incluyan referencia a algoritmo de Mersenne Twister en sus referencias de equipo_12/README.md
---

## [Equipo 13](equipos/equipo_13)

Ttulo del proyecto: `Cálculo del AUC`

Objetivo del proyecto: Implementación de un algoritmo para el cálculo del área bajo la curva (AUC) de forma paralela.

[Avances del proyecto](equipos/equipo_13):

* [Avance 10-04-18](equipos/equipo_13/avance_10_04_2018): Buen avance, gracias por su descripción individual. Coloquen las referencias que usarán para su proyecto en su carpeta inicial (ver [equipo_ejemplo](equipos/equipo_ejemplo)) (una vez definidas).

* [Avance 17-04-18](equipos/equipo_13/avance_17_04_2018): Definan si realizarán una implementación en CUDA pues Alejandro menciona que no se ha hallado tal implementación al realizar una búsqueda. Esto tomen en cuenta pues el proyecto final no consiste en desarrollar algo nuevo, eso podría tomar más tiempo del estimado. Den oportunidad en la semana de buscar algo respecto a esto, si no encuentran opten por otra extensión a C. ¿Cómo ven la integración por MC? ¿viable, factible en tiempo y entregas? pues aquí se encuentran con generación de números pseudo aleatorios [equipo12](equipos/equipo_12)

* [Avance 24-04-18](equipos/equipo_13/avance_24_04_2018): Empiecen con su trabajo escrito para el siguiente avance con lo que se ha investigado por ustedes. Ok con lo de MPI. La propuesta de Federico podrían implementarla también en el siguiente avance de forma secuencial y hacer pruebas de ejecución y presentar outputs. Si hay referencias que añadir en equipo_13/README.md realícenlo.

* [Avance 02-05-18](equipos/equipo_13/avance_02_05_2018): Coloquen la liga a su trabajo escrito e implementaciones en equipo_13/README.md como [equipo_ejemplo](equipos/equipo_ejemplo). ¿Y utilizaran un clúster en su implementación de openMPI? o ¿será algo pseudo distribuido con docker?. Se ve extraño que esté en inglés la sección de su trabajo escrito de Implementación en paralelo - Riemann. ¿Usarán la implementación que desarrollen en openMPI para alguna aplicación? por ejemplo en ¿estadística, finanzas u otra rama?.

---

## [Equipo 14](equipos/equipo_14)

Ttulo del proyecto: `Multiplicación de matrices en paralelo`

Objetivo del proyecto: implementación de un algoritmo para la multiplicación de matrices en paralelo. 

[Avances del proyecto](equipos/equipo_14):

* [Avance 10-04-18](equipos/equipo_14/avance_10_04_2018): Buen avance, gracias por la descripción individual. Coloquen las referencias que usarán para su proyecto en su carpeta inicial (ver [equipo_ejemplo](equipos/equipo_ejemplo)) (una vez definidas).

* [Avance 17-04-18](equipos/equipo_14/avance_17_04_2018): Revisen el libro de P. Pacheco, parallel programming with MPI para la multiplicación de matrices. 


* [Avance 24-04-18](equipos/equipo_14/avance_24_04_2018): Remuevan y cambien nombre a esto: equipos/equipo_14/Co\314\201digo/ (no es buena idea colocar espacios o acentos en bash, no importa la ortografía) pero gracias por esa carpeta y su readme fue de ayuda. Empiecen con el trabajo escrito, ya han investigado lo de paralelizar la multiplicación de matrices en openmp y lo de eficiencia, eso lo pueden ir añadiendo a su trabajo escrito, no lo dejen para semana de finales. Modifiqué recientemente el archivo de `definiciones.h` para manejo de arreglos-2d, vi Alex que tienes `entrada(C,i,j,M)` me parece que con la modificación que hice no requieres pasar la M en esta macro, revísenlo.

*[Avance 02-05-18](equipos/equipo_14/avance_02_05_2018): Gracias por cambiar el nombre a la carpeta de Codigo. Coloquen las ligas al trabajo escrito y presentación en su carpeta inicial: equipo_14/README.md como [equipo_ejemplo](equipos/equipo_ejemplo/). Vi que tienen `entrada(C,i,j,M)` me parece que con la modificación que hice (al archivo de [definiciones.h](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/BLAS/ejemplos) no requieres pasar la M en esta macro, revísenlo. Ok con el avance del trabajo escrito, continuén en su desarrollo.

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
