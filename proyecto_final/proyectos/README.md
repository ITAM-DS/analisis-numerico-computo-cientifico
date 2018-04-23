# Lista de proyectos:

---

## [Equipo 1](equipos/equipo_01)

Ttulo del proyecto: `Implementación de método de optimización convexa con mínimos cuadrados, a través de descenso en gradiente estocástico`

Objetivo del proyecto: objetivo

[Avances del proyecto](equipos/equipo_01):

* [Avance 10-04-18](equipos/equipo_01/avance_10_04_18): Ok con el cambio de tema. Añadan md's para que directamente pueda leerlos de la página de github y borren los Rmd's, .tex o html's, esos no los suban al repo xfa. Detallen el trabajo individual para el siguiente avance y califique a cada persona (está bien que hayan puesto el trabajo en equipo). Coloquen en su carpeta inicial las referencias (vean el [equipo_ejemplo](equipos/equipo_ejemplo)). Escriban el objetivo de su proyecto (vean el [equipo_ejemplo](equipos/equipo_ejemplo)).

* [Avance 17-04-18](equipos/equipo_02/avance_17_04_18): Super con su avance tanto en trabajo como en código. ¿Liz los datos son los mismos que usó Daniel para el programa `min_cuadrados_basico.c`? me parece que no pero podrías documentar qué datos, dimensiones se usan para este programa? si deseas en el mismo código o en la sección de [aquí](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/mno-2018-1/proyecto_final/proyectos/equipos/equipo_01/avance_17_04_18/codigo) o [aquí](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/mno-2018-1/proyecto_final/proyectos/equipos/equipo_01/avance_17_04_18) porque me quedó duda las dimensiones de tus datos y al final se obtiene un polinomio de grado 2 y ¿eso lo usarán para comparar?. Bien Daniel con tu trabajo. Cristian en la sección de Métodos de optimización del trabajo ¿podrías detallar el uso del operador de proyección? ¿qué ganancia se tiene el utilizar tal operador?


---

## [Equipo 2](equipos/equipo_02)

Ttulo del proyecto: `Cholesky Factorization`

Objetivo del proyecto: objetivo

[Avances del proyecto](equipos/equipo_02):

* [Avance 10-04-18](equipos/equipo_02/avance_10_04_18): No suban html's, Rmd's. xfa borren el .html. No hay avance entonces no tengo qué calificar :( faltan carpetas, referencias (vean el [equipo_ejemplo](equipos/equipo_ejemplo)). Coloquen las referencias que usarán para su proyecto en su carpeta inicial (ver [equipo_ejemplo](equipos/equipo_ejemplo)) (una vez definidas).

* [Avance 17-04-2018](equipos/equipo_02/avance_17_04_2018): Bien sus referencias, los autores Dongarra y Demmel son de los más importantes en cuestión del álgebra lineal numérica. Coloquen las referencias que usarán para su proyecto en su carpeta inicial y también su implementación. LAPACK tiene la factorización de Cholesky pueden revisarla, está bien que hayan buscado otra implementación pero aprovechen lo que vieron en las tareas, en las notas que encuentran en el repo (tema 3, cómputo matricial) también está descrita tal factorización en una forma con tres fors (como tienen [aquí](https://github.com/alexnivi/analisis-numerico-computo-cientifico/blob/mno-2018-1/proyecto_final/proyectos/equipos/equipo_02/avance_17_04_2018/implementacion/choleskyEjemplo.c)) y en una forma block-wise, está basado en el libro de matrix computations de Golub y Van Loan, Héctor y Uriel me parece que este libro les ayudará también. Revisen SCALAPACK. El año pasado un equipo implementó Cholesky en CUDA, también pueden revisar esto para su siguiente avance. Di click a las referencias y me llevó a una página de dropbox que me pedía iniciar sesión. Remuevan el README.html de su carpeta inicial xfa.


---

## [Equipo 3](equipos/equipo_03)

Ttulo del proyecto: `Factorización de Matriz usando factorización QR`

Objetivo del proyecto: Paralelizar factorización QR

[Avances del proyecto](equipos/equipo_03):

* [Avance 10-04-18](equipos/equipo_03/avance_10_04_2018): [referencia QR en Map Reduce](https://arxiv.org/abs/1301.1071).  Buen avance, gracias por el detalle de cada uno. [Aquí] referencias para la factorización QR en paralelo. El [equipo9](equipos/equipo_09) también revisa QR, debemos definir qué hará cada equipo. Coloquen las referencias que usarán para su proyecto en su carpeta inicial (ver [equipo_ejemplo](equipos/equipo_ejemplo)) (una vez definidas). Di click en dropbox y me pide iniciar sesión.

* [Avance 17-04-18](equipos/equipo_03/avance_17_04_2018): Para implementación de QR pueden revisar las notas de cómputo matricial del repo (tema 3) que están basadas en el libro de matrix computations de Golub y Van Loan y la factorización QR está implementada en LAPACK, pueden usarla. Revisen de igual forma SCALAPACK. Por su descripción Map Reduce podrían considerarlo en otro tiempo, ahora dediquen esfuerzos para la QR. Realicen una implementación para el siguiente avance (puede ser lo de LAPACK que les mencionaba).

---

## [Equipo 4](equipos/equipo_04)

Ttulo del proyecto: `Reconocimiento de caras utilizando cómputo en paralelo.`

Objetivo del proyecto: El objetivo de nuestro proyecto es la construcción de un sistema de detección de rostros con la capacidad de obtener la identidad de los rostros dada una base de datos de imágenes.

[Avances del proyecto](equipos/equipo_04):

* [Avance 10-04-18](equipos/equipo_04/avance_10_04_18): Entrega tarde avance.

* [Avance 17-04-2018](equipos/equipo_04/avance_17_04_2018): Pueden usar algo ya implementado para su objetivo y realizar un trabajo descriptivo, es decir, qué método(s) se utilizó(aron), la teoría, el problema de optimización que se resuelve. Me parece la parte de computación está resuelta. Las referencias que colocan en su carpeta inicial son aquellas que les ayudan a realizar su proyecto, no es necesario que escriban cada modelo/método que existe en CV para el reconocimiento de caras.

---

## [Equipo 5](equipos/equipo_05)

Ttulo del proyecto: `Proyecto Balanceo Línea`

Objetivo del proyecto: Encontrar la distribución óptima de las actividades requeridas para elaborar un producto entre cierto número de estaciones, minimizando el tiempo de ciclo y cumpliendo con las restricciones establecidas. 

[Avances del proyecto](equipos/equipo_05):

* [Avance 10-04-18](equipos/equipo_05/avance_10_04_18): Coloquen la estructura del [equipo_ejemplo](equipos/equipo_ejemplo) en su README.md y añadan referencias en este, así me facilita la revisión. Escriban los avances/problemas que están enfrentando y el trabajo que realizaron para los mismos en sus carpetas de avances. Les puede ayudar la referencia: CUDA Programming de Shane Cook, 2013. Aunque es clara la presentación preferiría un formato que no tenga que descargar a mi máquina y usar pptx (den un link y remuevan el .pptx del repo) :). El nombre de su carpeta es "equipo_05", cambien el nombre "equipo_Paco_Miguel". Coloquen las referencias que usarán para su proyecto en su carpeta inicial (ver [equipo_ejemplo](equipos/equipo_ejemplo)) (una vez definidas).

* [Avance 17-04-18](equipos/equipo_05/avance_17_04_18): No hay avance para esta entrega :(


---

## [Equipo 6](equipos/equipo_6)

Ttulo del proyecto: `Generating a Random Collection of Discrete Joint Probability Distributions Subject to Partial Information`

Objetivo del proyecto: Paralelizar en GPU un algoritmo de Hit & Run definido por restricciones lineales aplicada a distribuciones de probabilidad discretas

[Avances del proyecto](equipos/equipo_6):

* [Avance 10-04-2018](equipos/equipo_6/avance_10_04_2018): Buen avance, bien sus referencias. Coloquen las referencias que usarán para su proyecto en su carpeta inicial (ver [equipo_ejemplo](equipos/equipo_ejemplo)) (una vez definidas).

* [Avance 17-04-2018](equipos/equipo_6/avance_17_04_2018): Pueden usar funciones de LAPACK para calcular funciones sencillas como el de la norma. Buena idea utilizar lo ya hecho como lo de lpsolve. Podrían empezar a realizar el inicio de su trabajo escrito para el próximo avance.


---

## [Equipo 7](equipos/equipo_7)

Ttulo del proyecto: `PCA`

Objetivo del proyecto: Implementar el análisis de componenetes principales a una base de con gran número de datos de preferencia en paralelo

[Avances del proyecto](equipos/equipo_7):

* [Avance 10-04-18](equipos/equipo_7/avance_10_04_2018): Enmarquen el objetivo, ahora es muy general (esto se ve con el título también). Modifiquen la sección Integrantes del README del avance. Luis mejor si colocas los títulos de tus referencias en lugar de escribir la palabra referencia muchas veces (después de dar click en la última olvidé cuál era la tercera). Me parece que su enfoque es googlear algo relacionado con PCA y cómputo en paralelo, si bien es una forma de buscar me parece que una persona termina con mucha literatura y no se tiene algo concreto, creo que deberían iniciar con un problema y objetivo a resolver. Ahora tenemos: map-reduce, CUDA, Gram Schmidt, hyperspectral images, Face recognition, iterative PCA, dimensionality reduction y dicen que en dos semanas les tomará implementar los algoritmos ¿? (perdonen pero creo que si no tienen el objetivo o título definidos es muy aventurado dar una fecha). Coloquen las referencias que usarán para su proyecto en su carpeta inicial (ver [equipo_ejemplo](equipos/equipo_ejemplo)) (una vez definidas).

* [Avance 17-04-18](equipos/equipo_7/avance_17_04_2018): Bien en su avance. ¿Han hablado con el equipo 10?. Una vez tengan las referencias que les ayudará a su proyecto coloquen las mismas en la carpeta inicial de su equipo.


---

## [Equipo 8](equipos/equipo_8)

Ttulo del proyecto: `Optimización por descenso de gradiente`

Objetivo del proyecto: objetivo

[Avances del proyecto](equipos/equipo_8):

* [Avance 10-04-18](equipos/equipo_8/avance_10_04_18): No coloquen html's pues son pesados, si quieren den una liga o pueden poner un md en lugar de esto. Falta crear carpetas correspondientes. Coloquen las referencias que usarán para su proyecto en su carpeta inicial (ver [equipo_ejemplo](equipos/equipo_ejemplo)) (una vez definidas). ¿Tienen ligas a sus referencias? pregunto para que sea más fácil el acceso a ellas.


* [Avance 17-04-18](equipos/equipo_8/avance_17_04_18): Quiten el archivo Avance_10_04_2018.html en su carpeta inicial. Entiendo pero es difícil de leer: $$ \frac{\partial \pi_{i} }{\partial q_{i}} = (q_{1}+q_{2})^{-\frac{1}{n}} - \frac{1}{n}(q_{1}+q_{2})^{\frac{-1}{\eta - 1}}q_{i}-c_{i}q_{i}=0$$ ¿hay una mejor forma de desplegar esto? quizás en su trabajo escrito?. Está bien los artículos que escribe Mónica pero detalla más (y hablas de un tercero pero ¿cuál es? ¿el de Quoc et. al que está en su página de inicio de referencias), aquí hay un clásico de métodos numéricos para optimización: Numerical optimization de Nocedal & Wright. ¿Para el próximo avance tienen contemplado uso de funciones/librerías hechas en C? Para el siguiente avance finalicen la revisión de literatura y comiencen con el trabajo escrito.

---

## [Equipo 9](equipos/equipo_09)

Ttulo del proyecto: `Factorización QR`

Objetivo del proyecto: Implementar el algoritmo QR para el lenguaje de programación C bajo un enforque de programación en paralelo

[Avances del proyecto](equipos/equipo_09):

* [Avance 10-04-18](equipos/equipo_09/avance_10_04_2018): su carpeta tiene el año 2017, cambien esto. Buen avance, gracias por el detalle de cada uno. [Aquí] referencias para la factorización QR en paralelo. El [equipo3](equipos/equipo_03) también revisa QR, debemos definir qué hará cada equipo.

* [Avance 17-04-18](equipos/equipo_09/avance_17_04_2018): ¿pudieron hablar con el equipo3?  Fernando, el avance anterior mencionas la búsqueda de implementaciones en paralelo de QR, para este avance no haces mención a esto y es general la descripción de tu trabajo individual. Para el siguiente avance comiencen con el trabajo escrito y finalicen la lectura de literatura.

---

## [Equipo 10](equipos/equipo_10)

Ttulo del proyecto: `SVD para sistemas de recomendación`

Objetivo del proyecto: Desarrollar un algoritmo de sistemas de recomendación basado en descomposición SVD en paralelo

[Avances del proyecto](equipos/equipo_10):

* [Avance 10-04-18](equipos/equipo_10/Avance_10_04_18): Buen avance, gracias por la descripción individual. [Aquí] referencias para la SVD en paralelo. Coloquen las referencias que usarán para su proyecto en su carpeta inicial (ver [equipo_ejemplo](equipos/equipo_ejemplo)) (una vez definidas).

* [Avance 17-04-18](equipos/equipo_10/Avance_17_04_18): Bien en su avance. Escriban la referencia  de lo que utiliza cuSolver o MAGMA para la SVD (una liga, un párrafo) y que apoye lo que mencionan que en cuSolver una forma es con el método de Jacobi. ¿Entonces será la SVD con CUDA? Puede ser un trabajo que utilice lo ya realizado en código y se haga una descripción/investigación de lo que detrás está realizando las funciones.

---

## [Equipo 11](equipos/equipo_11)

Ttulo del proyecto: `Implementación de algoritmo Dijkstra`

Objetivo del proyecto: Implementar el algoritmo Dijkstra en C y su versión en paralelo.

[Avances del proyecto](equipos/equipo_11):

* [Avance 10-04-18](equipos/equipo_11/avance_10_04_18): Coloquen el formato pedido sus carpetas pues me es más difícil la revisión con formatos diferentes, es mejor normalizar vean [equipo_ejemplo](equipos/equipo_ejemplo). Gracias por su descripción de trabajo individual. Coloquen las referencias que usarán para su proyecto en su carpeta inicial (ver [equipo_ejemplo](equipos/equipo_ejemplo)) (una vez definidas).

* [Avance 17-04-18](equipos/equipo_11/avance_17_04_18): Thalía y Lorena realicen más detalle de la lectura de sus referencias, pues es muy general su descripción después que han leído ambas el mismo artículo "A note on two problems connected with graphs", ¿quizás mencionando lo que han realizado directamente en el trabajo escrito?. Para las referencias de su proyecto después de estos dos avances ¿ya han decidido cuáles serán? Roberto, si añades output de la implementación estaría muy bien. Para el siguiente avance coloquen las referencias en su carpeta inicial.

---

## [Equipo 12](equipos/equipo_12)

Ttulo del proyecto: `Números Aleatorios`

Objetivo del proyecto: Implementación de un algoritmo para generar números aleatorios de forma paralela.

[Avances del proyecto](equipos/equipo_12):

* [Avance 10-04-18](equipos/equipo_12/avance_10_04_18): No hay descripción, carpetas iniciales creadas, referencias. Nada que comentar.

* [Avance 17-04-18](equipos/equipo_12/avance_17_04_18): El formato de despliegue de las referencias en su carpeta inicial no es legible. 


---

## [Equipo 13](equipos/equipo_13)

Ttulo del proyecto: `Cálculo del AUC`

Objetivo del proyecto: Implementación de un algoritmo para el cálculo del área bajo la curva (AUC) de forma paralela.

[Avances del proyecto](equipos/equipo_13):

* [Avance 10-04-18](equipos/equipo_13/avance_10_04_2018): Buen avance, gracias por su descripción individual. Coloquen las referencias que usarán para su proyecto en su carpeta inicial (ver [equipo_ejemplo](equipos/equipo_ejemplo)) (una vez definidas).


---

## [Equipo 14](equipos/equipo_14)

Ttulo del proyecto: `Multiplicación de matrices en paralelo`

Objetivo del proyecto: implementación de un algoritmo para la multiplicación de matrices en paralelo. 

[Avances del proyecto](equipos/equipo_14):

* [Avance 10-04-18](equipos/equipo_14/avance_10_04_2018): Buen avance, gracias por la descripción individual. Coloquen las referencias que usarán para su proyecto en su carpeta inicial (ver [equipo_ejemplo](equipos/equipo_ejemplo)) (una vez definidas).





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
