# Avance_07_04_2017

### Trabajo:

#### Individual

Ollin:

Comenté con mis compañeros de equipo sobre las referencias que motivaron la resolución de éste problema como proyecto, entre ellas se encuentran [éste artículo](https://arxiv.org/pdf/1306.5550.pdf), que es la implementación directa de la matriz de Hashimoto, [el siguiente](https://arxiv.org/pdf/1308.6494.pdf) utiliza la misma matriz con una normalización por medio de los grados de los nodos para obtener un espectro acotado, [en éste otro](http://www.nature.com/articles/srep08828) se presentan dos generalizaciones equivalentes a los anteriores permitiendo el regreso de un caminante aleatorio con una cierta probabilidad proporcional al grado del nodo, todas las referencias anteriores dan una solución al problema de encontrar comunidades. [El último](https://arxiv.org/pdf/1506.08326.pdf) no implementa directamente la matriz pero es utilizada en la solución analítica de la optimización.

Adicionalmente, anexo código de generación de dichas matrices que había escrito anteriormete en el lenguaje Julia.

Isabel:  

Además de comentar con mis compañeros las referencias que mencionó Ollin, leí [esta referencia](https://www.quora.com/What-is-an-intuitive-explanation-of-the-Hashimoto-non-backtracking-matrix-and-its-utility-in-network-analysis) que explica de manera sencilla la matriz de adyacencia así como la matriz de Hashimoto y algunas aplicaciones que ésta tiene. Así como esta [otra](https://arxiv.org/pdf/0712.0192v1.pdf) y [esta](http://iopscience.iop.org/article/10.1209/0295-5075/107/50005/meta) que son más teóricas. 

Raúl:

A través de revisar las referencias sugeridas, observamos que el objetivo de la matriz de Hashimoto nos permite obtener una definición de grafos con una representación matricial, que muestra la conexión de los nodos en el grafo. Está matriz nos permite identificar rutas en el grafo donde para llegar de un nodo a otro no se utilice la conexión directa entre los nodos. De esta manera podemos realizar operaciones al realizar transformaciones de algebra lineal. Con ello podemos obtener diversas medidas centralidad, con lo cual podemos sacar mayor información de la red. En consecuencia la construcción de la matriz de Hashimoto es de particular importancia para el análisis de la red; con ello, nuestro proyecto busca la construcción de esta matriz de forma veloz aprovechando las capacidades del cómputo en paralelo.

Grupal:

Concordamos el tema y el tipo de implementación que llevaremos a cabo para el desarrollo del proyecto. Además cada uno de nosotros investigó referencias y estudió el tema a tratar.

## Comentarios sobre avance:

* Muy bien con la explicación del trabajo individual de cada persona :)

* Muy bien con las referencias dadas. Gracias Isabel por la primera ref para explicación.

* Gracias Raúl por la explicación en tu trabajo individual.

* Me gusta mucho que exista una implementación hecha por Ollín en Julia, así revisamos comparamos con cuda C :)

* Entonces respecto a la primera referencia que da Ollín, la idea es construir a la matriz B, correcto? en Julia es aquí donde se realiza esto:

```
adjacency_matrix(g)

```

?

* Coloquen en su README debajo del nivel equipo_13 sus referencias con bullets y autores y nombre del paper y ligas.

