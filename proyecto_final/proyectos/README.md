# Lista de proyectos:

---

## [Equipo 1](equipos/equipo_01)

Ttulo del proyecto: `Implementación de método de optimización convexa con mínimos cuadrados, a través de descenso en gradiente estocástico`

Objetivo del proyecto: objetivo

[Avances del proyecto](equipos/equipo_01):

* [Avance 10-04-18](equipos/equipo_01/avance_10_04_18): Ok con el cambio de tema. Añadan md's para que directamente pueda leerlos de la página de github y borren los Rmd's, .tex o html's, esos no los suban al repo xfa. Detallen el trabajo individual para el siguiente avance y califique a cada persona (está bien que hayan puesto el trabajo en equipo). Coloquen en su carpeta inicial las referencias (vean el [equipo_ejemplo](equipos/equipo_ejemplo)). Escriban el objetivo de su proyecto (vean el [equipo_ejemplo](equipos/equipo_ejemplo)).

* [Avance 17-04-18](equipos/equipo_01/avance_17_04_18): Super con su avance tanto en trabajo como en código. ¿Liz los datos son los mismos que usó Daniel para el programa `min_cuadrados_basico.c`? me parece que no pero podrías documentar qué datos, dimensiones se usan para este programa? si deseas en el mismo código o en la sección de [aquí](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/mno-2018-1/proyecto_final/proyectos/equipos/equipo_01/avance_17_04_18/codigo) o [aquí](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/mno-2018-1/proyecto_final/proyectos/equipos/equipo_01/avance_17_04_18) porque me quedó duda las dimensiones de tus datos y al final se obtiene un polinomio de grado 2 y ¿eso lo usarán para comparar?. Bien Daniel con tu trabajo. Cristian en la sección de Métodos de optimización del trabajo ¿podrías detallar el uso del operador de proyección? ¿qué ganancia se tiene el utilizar tal operador?

* [Avance 24-04-18](equipos/equipo_01/avance_24_04_18): Revisen la ecuación de la página 2 después de las palabras: "Operando con ellas", la parte de en medio en específico. En la página 5 el cuadro del Algorithm 1 definan qué es THETA  (lo mencionan en la sección de Notación pero lo pueden añadir en la línea de Input). En la parte de notación de la página 5 también se hace mención al conjunto de matrices definidas positivas pero en el libro de Boyd & Vandenberghe utilizan dos signos positivos para este conjunto. Al final de la página 5 sólo es algo en español el Hessiano cambien por la Hessiana (es una matriz, la matriz Hessiana). En la página 6 hay un signo de interrogación que se ve como un typo en las referencias de AMSGRAD y también para AMSGRAD definan qué es beta_1 y beta_2. No encontré el programa de `min_cuadrados_basico.c` con la actualización de este avance (lectura de archivo) añádenlo en el siguiente avance xfa. Falta colocar su objetivo y ligas a su trabajo escrito como [equipo_ejemplo](equipos/equipo_ejemplo) en equipo_01/README.md.

---

## [Equipo 2](equipos/equipo_02)

Ttulo del proyecto: `Cholesky Factorization`

Objetivo del proyecto: Realizar una implementación de la factorización de cholesky en alguna de las tecnologías de cómputo distribuido o compartido visto en clase.

[Avances del proyecto](equipos/equipo_02):

* [Avance 10-04-18](equipos/equipo_02/avance_10_04_18): No suban html's, Rmd's. xfa borren el .html. No hay avance entonces no tengo qué calificar :( faltan carpetas, referencias (vean el [equipo_ejemplo](equipos/equipo_ejemplo)). Coloquen las referencias que usarán para su proyecto en su carpeta inicial (ver [equipo_ejemplo](equipos/equipo_ejemplo)) (una vez definidas).

* [Avance 17-04-2018](equipos/equipo_02/avance_17_04_2018): Bien sus referencias, los autores Dongarra y Demmel son de los más importantes en cuestión del álgebra lineal numérica. Coloquen las referencias que usarán para su proyecto en su carpeta inicial y también su implementación. LAPACK tiene la factorización de Cholesky pueden revisarla, está bien que hayan buscado otra implementación pero aprovechen lo que vieron en las tareas, en las notas que encuentran en el repo (tema 3, cómputo matricial) también está descrita tal factorización en una forma con tres fors (como tienen [aquí](https://github.com/alexnivi/analisis-numerico-computo-cientifico/blob/mno-2018-1/proyecto_final/proyectos/equipos/equipo_02/avance_17_04_2018/implementacion/choleskyEjemplo.c)) y en una forma block-wise, está basado en el libro de matrix computations de Golub y Van Loan, Héctor y Uriel me parece que este libro les ayudará también. Revisen SCALAPACK. El año pasado un equipo implementó Cholesky en CUDA, también pueden revisar esto para su siguiente avance. Di click a las referencias y me llevó a una página de dropbox que me pedía iniciar sesión. Remuevan el README.html de su carpeta inicial xfa.

* [Avance 24-04-2018](equipos/equipo_02/avance_24_04_2018): Gracias por sus referencias en su README de su carpeta inicial (equipo_02/README.md) pero la liga que se llama Dropbox me pide iniciar sesión y vi en mi correo que me enviaron la invitación pero mejor si escriben una por una las referencias que tengan en esta liga. Vayan realizando su trabajo escrito con introducción, algoritmos a utilizar para Cholesky y se puedan leer mejor la escritura matemática que reporta Uriel para este avance. No tienen que poner una liga [referencia](https://docs.google.com/document/d/1_VOtnyJGHTWvyHCHC9L-mSRSNSslY22qrSikXzquL2g/edit?ts=5ad56af8) con una bitácora de todos los avances. Falta en equipo_02/README.md colocar su objetivo y ligas a su trabajo escrito como [equipo_ejemplo](equipos/equipo_ejemplo). Para algoritmos de optimización usen Boyd & Vandenbergue parte 3 (capítulos 9, 10 y 11) y el libro de Nocedal & Wright de numerical optimization. La referencia de introduction to random signals and applied kalman filtering pdf, no la pude visualizar, pueden arreglar esto? Remuevan y cambien nombre a esto: equipos/equipo_02/avance_24_04_2018/implementacio\314\201n/ (no es buena idea colocar espacios o acentos en bash, no importa la ortografía).

---

## [Equipo 3](equipos/equipo_03)

Ttulo del proyecto: `Factorización de Matriz usando factorización QR`

Objetivo del proyecto: Paralelizar factorización QR

[Avances del proyecto](equipos/equipo_03):

* [Avance 10-04-18](equipos/equipo_03/avance_10_04_2018): [referencia QR en Map Reduce](https://arxiv.org/abs/1301.1071).  Buen avance, gracias por el detalle de cada uno. [Aquí] referencias para la factorización QR en paralelo. El [equipo9](equipos/equipo_09) también revisa QR, debemos definir qué hará cada equipo. Coloquen las referencias que usarán para su proyecto en su carpeta inicial (ver [equipo_ejemplo](equipos/equipo_ejemplo)) (una vez definidas). Di click en dropbox y me pide iniciar sesión.

* [Avance 17-04-18](equipos/equipo_03/avance_17_04_2018): Para implementación de QR pueden revisar las notas de cómputo matricial del repo (tema 3) que están basadas en el libro de matrix computations de Golub y Van Loan y la factorización QR está implementada en LAPACK, pueden usarla. Revisen de igual forma SCALAPACK. Por su descripción Map Reduce podrían considerarlo en otro tiempo, ahora dediquen esfuerzos para la QR con  una implementación para el siguiente avance (puede ser lo de LAPACK que les mencionaba).

* [Avance 24-04-18](equipos/equipo_03/avance_24_04_2018): Diego, sube tus implementaciones al repo, no son pesadas (kb's), y añade outputs de tus ejecuciones, puedes usar lo hecho en tareas 5, 6 para lectura de archivos de texto, imprimir vectores, matrices y manejo de arreglos de 1d y 2d (sugerencia). Rafael sí, inicien el trabajo escrito para el siguiente avance, el autor Dongarra ha sido y continúa siendo muy importante en el álgebra lineal numérica. Víctor, sube tus implementaciones al repo y añade outputs de tus ejecuciones. Para esto aprovechen el markdown. También pueden usar lo de las tareas 5, 6 para leer de archivos, imprimir vectores, matrices y manejo de arreglos 1d y 2d (sugerencia). Una vez inicien el trabajo escrito, coloquen la liga al mismo como [equipo_ejemplo](equipos/equipo_ejemplo) en equipo_03/README.md.

---

## [Equipo 4](equipos/equipo_04)

Ttulo del proyecto: `Reconocimiento de caras utilizando cómputo en paralelo.`

Objetivo del proyecto: El objetivo de nuestro proyecto es la construcción de un sistema de detección de rostros con la capacidad de obtener la identidad de los rostros dada una base de datos de imágenes.

[Avances del proyecto](equipos/equipo_04):

* [Avance 10-04-18](equipos/equipo_04/avance_10_04_18): Entrega tarde avance.

* [Avance 17-04-2018](equipos/equipo_04/avance_17_04_2018): Pueden usar algo ya implementado para su objetivo y realizar un trabajo descriptivo, es decir, qué método(s) se utilizó(aron), la teoría, el problema de optimización que se resuelve. Me parece la parte de computación está resuelta. Las referencias que colocan en su carpeta inicial son aquellas que les ayudan a realizar su proyecto, no es necesario que escriban cada modelo/método que existe en CV para el reconocimiento de caras.

* [Avance 24-04-2018](equipos/equipo_04/avance_24_04_2018): Están bien sus avances pero mejor si añaden ejecuciones y output de sus resultados. También ¿cómo ejecutan su programa, qué requieren instalar, con cuál ejemplo ya lo probaron? Comiencen con el trabajo escrito y añadan ligas como aquí [equipo_ejemplo](equipos/equipo_ejemplo) en equipo_04/README.md. 

---

## [Equipo 5](equipos/equipo_05)

Ttulo del proyecto: `Proyecto Balanceo Línea`

Objetivo del proyecto: Encontrar la distribución óptima de las actividades requeridas para elaborar un producto entre cierto número de estaciones, minimizando el tiempo de ciclo y cumpliendo con las restricciones establecidas. 

[Avances del proyecto](equipos/equipo_05):

* [Avance 10-04-18](equipos/equipo_05/avance_10_04_2018): Coloquen la estructura del [equipo_ejemplo](equipos/equipo_ejemplo) en su README.md y añadan referencias en este, así me facilita la revisión. Escriban los avances/problemas que están enfrentando y el trabajo que realizaron para los mismos en sus carpetas de avances. Les puede ayudar la referencia: CUDA Programming de Shane Cook, 2013. Aunque es clara la presentación preferiría un formato que no tenga que descargar a mi máquina y usar pptx (den un link y remuevan el .pptx del repo) :). El nombre de su carpeta es "equipo_05", cambien el nombre "equipo_Paco_Miguel". Coloquen las referencias que usarán para su proyecto en su carpeta inicial (ver [equipo_ejemplo](equipos/equipo_ejemplo)) (una vez definidas).

* [Avance 17-04-18](equipos/equipo_05/avance_17_04_2018): No hay avance para esta entrega :(

* [Avance 24-04-18](equipos/equipo_05/avance_24_04_2018): Es un trabajo enorme lo que han realizado pero es difícil de seguir.  Sólo algo mínimo: cambien carpetas "2017" por "2018". Falta la liga a la documentación que mencionan en este avance. Añádanla en la carpeta inicial del README (equipo_05/README.md) y también referencias (por ejemplo: Scholl, Armin), como aquí [equipo_ejemplo](equipos/equipo_ejemplo). Inicien con el trabajo escrito. Ya acepté la invitación al repo de Paco para lo del código, son varios archivos (todos son indispensables?), quizás una documentación de lo que realiza cada archivo?  En su trabajo escrito coloquen una introducción al problema de balanceo, referencias, documentación de códigos. La presentación ayuda en este sentido pero traten de compactarla pues el día que presenten su trabajo sólo tendrán 10 min o como máximo 15 y en el trabajo escrito sí pueden escribir el contenido de ésta y más información. Entonces en resumen para el siguiente avance concéntrense en compactar la presentación, incluir un trabajo escrito con lo pedido anteriormente, escribir en su README de su carpeta inicial (equipo_05/README.md) referencias, ligas a su trabajo escrito, presentación y en lo concerniente a los archivos de código, dar una descripción o documentación de los mismos (también no sé si sirven todos esos archivos).

---

## [Equipo 6](equipos/equipo_6)

Ttulo del proyecto: `Generating a Random Collection of Discrete Joint Probability Distributions Subject to Partial Information`

Objetivo del proyecto: Paralelizar en GPU un algoritmo de Hit & Run definido por restricciones lineales aplicada a distribuciones de probabilidad discretas

[Avances del proyecto](equipos/equipo_6):

* [Avance 10-04-2018](equipos/equipo_6/avance_10_04_2018): Buen avance, bien sus referencias. Coloquen las referencias que usarán para su proyecto en su carpeta inicial (ver [equipo_ejemplo](equipos/equipo_ejemplo)) (una vez definidas).

* [Avance 17-04-2018](equipos/equipo_6/avance_17_04_2018): Pueden usar funciones de LAPACK para calcular funciones sencillas como el de la norma. Buena idea utilizar lo ya hecho como lo de lpsolve. Podrían empezar a realizar el inicio de su trabajo escrito para el próximo avance.

* [Avance 24-04-2018](equipos/equipo_6/avance_24_04_2018): No hay entrega de avance.

---

## [Equipo 7](equipos/equipo_07)

Ttulo del proyecto: `PCA, implementación en C. Secuencial / Paralelo`

Objetivo del proyecto: Implementar el método de “Principal Component Analysis” (PCA) en C, posteriormente de manera secuencial y posteriormente en paralelo. Este trabajo será complementado con lenguajes de alto nivel (ej. R, Python).

[Avances del proyecto](equipos/equipo_07):

* [Avance 10-04-18](equipos/equipo_07/avance_10_04_2018): Enmarquen el objetivo, ahora es muy general (esto se ve con el título también). Modifiquen la sección Integrantes del README del avance. Luis mejor si colocas los títulos de tus referencias en lugar de escribir la palabra referencia muchas veces (después de dar click en la última olvidé cuál era la tercera). Me parece que su enfoque es googlear algo relacionado con PCA y cómputo en paralelo, si bien es una forma de buscar me parece que una persona termina con mucha literatura y no se tiene algo concreto, creo que deberían iniciar con un problema y objetivo a resolver. Ahora tenemos: map-reduce, CUDA, Gram Schmidt, hyperspectral images, Face recognition, iterative PCA, dimensionality reduction y dicen que en dos semanas les tomará implementar los algoritmos ¿? (perdonen pero creo que si no tienen el objetivo o título definidos es muy aventurado dar una fecha). Coloquen las referencias que usarán para su proyecto en su carpeta inicial (ver [equipo_ejemplo](equipos/equipo_ejemplo)) (una vez definidas).

* [Avance 17-04-18](equipos/equipo_07/avance_17_04_2018): Bien en su avance. ¿Han hablado con el equipo 10?. Una vez tengan las referencias que les ayudará a su proyecto coloquen las mismas en la carpeta inicial de su equipo.

* [Avance 24-04-18](equipos/equipo_07/avance_24_04_2018): En su equipo_07/README.md coloquen sus referencias como [equipo_ejemplo](equipos/equipo_ejemplo). Pueden usar BLAS para las operaciones de normalización de su matriz (sugerencia). Añadan forma de compilar y output de su programa.


---

## [Equipo 8](equipos/equipo_8)

Ttulo del proyecto: `Método de descenso en gradiente en juegos de Cournot`

Objetivo del proyecto: Implementar el método de descenso en gradiente para encontrar el equilibrio de Cournot-Nash de un juego de Cournot.

[Avances del proyecto](equipos/equipo_8):

* [Avance 10-04-18](equipos/equipo_8/avance_10_04_18): No coloquen html's pues son pesados, si quieren den una liga o pueden poner un md en lugar de esto. Falta crear carpetas correspondientes. Coloquen las referencias que usarán para su proyecto en su carpeta inicial (ver [equipo_ejemplo](equipos/equipo_ejemplo)) (una vez definidas). ¿Tienen ligas a sus referencias? pregunto para que sea más fácil el acceso a ellas.


* [Avance 17-04-18](equipos/equipo_8/avance_17_04_18): Quiten el archivo Avance_10_04_2018.html en su carpeta inicial. Entiendo pero es difícil de leer: $$ \frac{\partial \pi_{i} }{\partial q_{i}} = (q_{1}+q_{2})^{-\frac{1}{n}} - \frac{1}{n}(q_{1}+q_{2})^{\frac{-1}{\eta - 1}}q_{i}-c_{i}q_{i}=0$$ ¿hay una mejor forma de desplegar esto? quizás en su trabajo escrito?. Está bien los artículos que escribe Mónica pero detalla más (y hablas de un tercero pero ¿cuál es? ¿el de Quoc et. al que está en su página de inicio de referencias), aquí hay un clásico de métodos numéricos para optimización: Numerical optimization de Nocedal & Wright. ¿Para el próximo avance tienen contemplado uso de funciones/librerías hechas en C? Para el siguiente avance finalicen la revisión de literatura y comiencen con el trabajo escrito.

* [Avance 24-04-18](equipos/equipo_8/avance_24_04_18): Gracias por remover el html. Coloquen la liga a su trabajo escrito en equipo_8/README.md como [equipo_ejemplo](equipos/equipo_ejemplo). En la página 4 al final hay algunas cosas que cambiar, por ejemplo separar la palabra "para" y hay dos "si". La figura al inicio de la página 5 no hacen referencia a ella. Están bien sus figuras aunque se ven algo borrosas, hay una forma de desplegar los algoritmos de una forma más legible con .tex, revísenla. Para el siguiente avance consideren iniciar con su implementación en C y continúen completando su trabajo escrito.

---

## [Equipo 9](equipos/equipo_09)

Ttulo del proyecto: `Mínimos Cuadrados usando la Factorización QR y CUDA`

Objetivo del proyecto: Implementar el algoritmo QR para el lenguaje de programación C bajo un enforque de programación en paralelo usando CUDA

[Avances del proyecto](equipos/equipo_09):

* [Avance 10-04-18](equipos/equipo_09/avance_10_04_2018): su carpeta tiene el año 2017, cambien esto. Buen avance, gracias por el detalle de cada uno. [Aquí] referencias para la factorización QR en paralelo. El [equipo3](equipos/equipo_03) también revisa QR, debemos definir qué hará cada equipo.

* [Avance 17-04-18](equipos/equipo_09/avance_17_04_2018): ¿pudieron hablar con el equipo3?  Fernando, el avance anterior mencionas la búsqueda de implementaciones en paralelo de QR, para este avance no haces mención a esto y es general la descripción de tu trabajo individual. Para el siguiente avance comiencen con el trabajo escrito y finalicen la lectura de literatura.

* [Avance 24-04-18](equipos/equipo_09/avance_24_04_2018): pueden usar lo hecho en tareas 5, 6 para lectura de archivos de texto, imprimir vectores, matrices y manejo de arreglos de 1d y 2d en forma column major (sugerencia). Miguel tiene buenos avances en la programación desde el avance 1. Para este avance no está clara la aportación de Karen y Fernando en el trabajo escrito (que está mal organizado y escrito). Había mencionado a Fernando en el comentario de su primer avance que él habla sobre búsqueda de implementaciones en paralelo de QR, lo repetí para el avance 2 y para este tercero sigue sin haber comentarios al respecto salvo lo que  Karen refiere del paper de Dongarra. Su trabajo escrito tiene enunciados incompletos como "El método de mínimos cuadrados en palabras de Miller, busca minimizar la diferencia entre
los datos observados y la ecuación de la recta de la forma para" (falta referencia a lo de Miller y completar el enunciado) o "La combinación de puntos que mejor se ajusta a los puntos se encuentra dada por la siguiente
ecuación: (vacío)" y así otros. Al inicio de la sección de "Factorización QR mediante el uso de reflexiones de Householder" se describe el uso de QR para eigenvalores/eigenvectores, perdonen pero ¿cuál es la idea de abordar este tema en la sección de reflexiones de Householder?. No hay buena calificación para Karen y Fernando para este avance.  

---

## [Equipo 10](equipos/equipo_10)

Ttulo del proyecto: `SVD para sistemas de recomendación`

Objetivo del proyecto: Desarrollar un algoritmo de sistemas de recomendación basado en descomposición SVD en paralelo

[Avances del proyecto](equipos/equipo_10):

* [Avance 10-04-18](equipos/equipo_10/Avance_10_04_18): Buen avance, gracias por la descripción individual. [Aquí] referencias para la SVD en paralelo. Coloquen las referencias que usarán para su proyecto en su carpeta inicial (ver [equipo_ejemplo](equipos/equipo_ejemplo)) (una vez definidas).

* [Avance 17-04-18](equipos/equipo_10/Avance_17_04_18): Bien en su avance. Escriban la referencia  de lo que utiliza cuSolver o MAGMA para la SVD (una liga, un párrafo) y que apoye lo que mencionan que en cuSolver una forma es con el método de Jacobi. ¿Entonces será la SVD con CUDA? Puede ser un trabajo que utilice lo ya realizado en código y se haga una descripción/investigación de lo que detrás está realizando las funciones.

* [Avance 24-04-18](equipos/equipo_10/Avance_24_04_18): Sugiero usen CUDA de forma nativa, es decir no con docker para iniciar, después podrían considerar usar docker+NVIDIA (una vez hecho pruebas con cusolver por ejemplo). Inicien con el trabajo escrito para el siguiente avance. Suban el notebook al repo en lugar que deba descargarse (es muy pesado? si no, entonces podrían añadirlo). Es probable que el examen final sea la última semana de mayo, lo menciono para que ajusten lo necesario en su cronograma. Es importante que realicen pruebas para que revisen que todo está bien con configuración de instancia, librerías necesarias y puedan seguir avanzando o resolver lo que surja. Se ve bien la configuración de la instancia (aunque la instancia no tenía tag de nombre...) añade una compilación de hello_world y output de cusolver para apoyar lo anterior que comentaba (chequeo de dependencias para CUDA y librerías necesarias).

---

## [Equipo 11](equipos/equipo_11)

Ttulo del proyecto: `Implementación de algoritmo Dijkstra`

Objetivo del proyecto: Implementar el algoritmo Dijkstra en C y su versión en paralelo.

[Avances del proyecto](equipos/equipo_11):

* [Avance 10-04-18](equipos/equipo_11/avance_10_04_18): Coloquen el formato pedido sus carpetas pues me es más difícil la revisión con formatos diferentes, es mejor normalizar vean [equipo_ejemplo](equipos/equipo_ejemplo). Gracias por su descripción de trabajo individual. Coloquen las referencias que usarán para su proyecto en su carpeta inicial (ver [equipo_ejemplo](equipos/equipo_ejemplo)) (una vez definidas).

* [Avance 17-04-18](equipos/equipo_11/avance_17_04_18): Thalía y Lorena realicen más detalle de la lectura de sus referencias (su trabajo individual), pues es muy general su descripción en este avance después que han leído ambas el mismo artículo "A note on two problems connected with graphs", ¿quizás mencionando lo que han realizado directamente en el trabajo escrito? ¿quizás discusión? piensen en una forma de presentarme su trabajo. Para las referencias de su proyecto después de estos dos avances ¿han decidido cuáles serán? si es así coloquen las referencias en su carpeta inicial. Roberto  ¿ya funciona la implementación en python? ¿supongo que funciona para el grafo que está en el main?. Den más descripción de su trabajo individual, revisé lo que llevan de trabajo escrito para darme una idea de lo que Thalía y Lorena realizaron y revisé el código de Roberto para de igual forma tener esta idea de su trabajo, en este sentido facilítenme la lectura de lo que realizaron.

* [Avance 24-04-18](equipos/equipo_11/avance_24_04_18): Coloquen la liga de su trabajo escrito en su equipo_11/README.md como [equipo_ejemplo](equipos/equipo_ejemplo) y un comentario respecto a esto: la liga a su trabajo escrito me llevó a un folder, mejor una liga que me lleve al trabajo escrito directamente. La lectura de software/hardware paralelo debió de cubrirse con el examen que hicimos en clase el mes anterior y para este avance no  se cubrió algo diferente (salvo quizás lo de ¿eficiencia?). Remuevan de su trabajo escrito la sección de software paralelo y hardware paralelo pues no es necesaria (¿o mediran eficiencia? si es así conserven esa parte, si no remuevan esa sección), vayan directo a la implementación en paralelo de Dijkstra ¿han encontrado referencias para esto último?. Muestren los resultados en su forma secuencial que les mencioné en el avance anterior (sin respuesta a las preguntas que hacía en específico a la implementación en python). Tres personas trabajaron lo de hardware/software paralelo, sugiero asignen mejor sus tareas, una persona podría haber desarrollado lo anterior y las demás la parte de código/implementación/secuencial/paralelo de Dijkstra. Comiencen con la implementación en C si ya funciona lo de python secuencial para el siguiente avance antes de usar openmp.

---

## [Equipo 12](equipos/equipo_12)

Ttulo del proyecto: `Generación de método aleatorios mediante algoritmos implementados en C.`

Objetivo del proyecto: Programar un algoritmo para la generación de una cadena de número aleatorios, optimizando su longitud. Medir su eficiencia a través de distintos criterios como pruebas de aleatoriedad, longitud de la cadena generada y la comparación con otras cadenas de números aleatorios obtenidos por fuentes naturales de aleatoriedad como procesos cuánticos: fotones y partículas.

[Avances del proyecto](equipos/equipo_12):

* [Avance 10-04-18](equipos/equipo_12/avance_10_04_18): No hay descripción, carpetas iniciales creadas, referencias. Nada que comentar.

* [Avance 17-04-18](equipos/equipo_12/avance_17_04_18): El formato de despliegue de las referencias en su carpeta inicial no es legible, arreglen esto. El trabajo consistirá en medir ¿eficiencia? ¿probar que es posible generar números pseudo-aleatorios con cómputo en paralelo? ¿realizar pruebas para el generador de números pseudo-aleatorios, en el sentido de calidad de los números obtenidos? Para el siguiente avance definan lo anterior y empiecen con el trabajo escrito y revisen implementaciones.

* [Avance 24-04-18](equipos/equipo_12/avance_24_04_18): Dan buenas referencias en este avance ¿serán utilizadas en el objetivo de su proyecto? si es así colóquenlas en equipo_12/README.md y un comentario sobre sus referencias de este README, es mejor si colocan el título de sus referencias en lugar de las ligas con nombre de google docs pues si yo veo una por una después se me olvida cuál era la tercera. Comiencen con su trabajo escrito y lo que añade para este avance Víctor lo pueden incluir allí. Muy bien su descripción de trabajo individual, gracias por eso.

---

## [Equipo 13](equipos/equipo_13)

Ttulo del proyecto: `Cálculo del AUC`

Objetivo del proyecto: Implementación de un algoritmo para el cálculo del área bajo la curva (AUC) de forma paralela.

[Avances del proyecto](equipos/equipo_13):

* [Avance 10-04-18](equipos/equipo_13/avance_10_04_2018): Buen avance, gracias por su descripción individual. Coloquen las referencias que usarán para su proyecto en su carpeta inicial (ver [equipo_ejemplo](equipos/equipo_ejemplo)) (una vez definidas).

* [Avance 17-04-18](equipos/equipo_13/avance_17_04_2018): Definan si realizarán una implementación en CUDA pues Alejandro menciona que no se ha hallado tal implementación al realizar una búsqueda. Esto tomen en cuenta pues el proyecto final no consiste en desarrollar algo nuevo, eso podría tomar más tiempo del estimado. Den oportunidad en la semana de buscar algo respecto a esto, si no encuentran opten por otra extensión a C. ¿Cómo ven la integración por MC? ¿viable, factible en tiempo y entregas? pues aquí se encuentran con generación de números pseudo aleatorios [equipo12](equipos/equipo_12)

* [Avance 24-04-18](equipos/equipo_13/avance_24_04_2018): Empiecen con su trabajo escrito para el siguiente avance con lo que se ha investigado por ustedes. Ok con lo de MPI. La propuesta de Federico podrían implementarla también en el siguiente avance de forma secuencial y hacer pruebas de ejecución y presentar outputs. Si hay referencias que añadir en equipo_13/README.md realícenlo.

---

## [Equipo 14](equipos/equipo_14)

Ttulo del proyecto: `Multiplicación de matrices en paralelo`

Objetivo del proyecto: implementación de un algoritmo para la multiplicación de matrices en paralelo. 

[Avances del proyecto](equipos/equipo_14):

* [Avance 10-04-18](equipos/equipo_14/avance_10_04_2018): Buen avance, gracias por la descripción individual. Coloquen las referencias que usarán para su proyecto en su carpeta inicial (ver [equipo_ejemplo](equipos/equipo_ejemplo)) (una vez definidas).

* [Avance 17-04-18](equipos/equipo_14/avance_17_04_2018): Revisen el libro de P. Pacheco, parallel programming with MPI para la multiplicación de matrices. 


* [Avance 24-04-18](equipos/equipo_14/avance_24_04_2018): Remuevan y cambien nombre a esto: equipos/equipo_14/Co\314\201digo/ (no es buena idea colocar espacios o acentos en bash, no importa la ortografía) pero gracias por esa carpeta y su readme fue de ayuda. Empiecen con el trabajo escrito, ya han investigado lo de paralelizar la multiplicación de matrices en openmp y lo de eficiencia, eso lo pueden ir añadiendo a su trabajo escrito, no lo dejen para semana de finales. Modifiqué recientemente el archivo de `definiciones.h` para manejo de arreglos-2d, vi Alex que tienes `entrada(C,i,j,M)` me parece que con la modificación que hice no requieres pasar la M en esta macro, revísenlo.

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
