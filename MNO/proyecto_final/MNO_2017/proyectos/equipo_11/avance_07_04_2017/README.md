## Avance_07_04_2017

---

### Integrantes:

---

- Mariana Godina
- Sonia Mendizábal

### Trabajo:

---

#### Individual

**Sonia:** 

Leí la siguiente [referencia](https://pdfs.semanticscholar.org/cf5e/afcd87a9fcf1c77cfb431f0b8a8518f11445.pdf) sobre la implementación en paralelo de los métodos Jacobi. En este artículo recomiendan el método one-sided Jacobi y analizan dos metodologías. La primera, es un 
ordenamiento 
de las rotaciones en un sweep; la segunda, se refiere a
parámetros de rotación de los planos en cada iteración. 
Además presentan tres algoritmos de rotaciones con
diferentes ventajas entre ellos, y diferentes
formas de ordenamiento. 
En particular presentan parallel ring Jacobi ordering 
como una forma de ordenamiento de índices y 
ordenamiento en sweep simultáneo.


**Mariana:**

Leí la siguiente [referencia](https://maths-people.anu.edu.au/~brent/pd/rpb084i.pdf) que explica dos modelos para la descomposición de valores singulares: Hestenes que usa cyclic-by-rows (que no es amable para el computo en paralelo) y el serial de Jacobi que usa una secuencia de matrices simétricas vía la relación. 
Para el método de Jacobi el sistema ideal para implementar la descomposición de eigenvalores es emitir los parámetros de rotación de filas y columnas en un tiempo constante.
Habla también de la estrategia de threshold que garantiza la convergencia. 
En el artículo creen que new ordering es mejor que cylic-by-rows.

#### Equipo
Después de discutir los artículos y definir una solución en paralelo del problema queda por estudiar
los algoritmos que se implementaran. Se descartaron algunos, por ejemplo cyclic-by-rows, por la in eficiencia en el cómputo elegido y 
se probarán los algoritmos eligiendo el mejor. 
Seguimos estudiando el capítulo 8 sobre métodos Jacobi de la [referencia](http://web.mit.edu/ehliu/Public/sclark/Golub%20G.H.,%20Van%20Loan%20C.F.-%20Matrix%20Computations.pdf).
Determinamos el uso de threads para la solución del problema y en una semana tener un dummy de la programación 
del método.

---

## Comentario sobre avance:

* Muy buen avance respecto a la lectura de los papers de las referencias :)

* Discutan sobre los ordenamientos que se proponen en ambos papers. En el paper que leyó Mariana se habla sobre un nuevo ordenamiento y sobre simetría. La SVD se aplica a la matriz de correlación para encontrar las componentes principales, esta matriz resulta ser simétrica positiva semidefinida. Por simetría, esto equivale a encontrar la descomposición espectral de esta matriz. Los ordenamientos que aparecen en el paper que leyó Sonia son prometedores, en particular el de round robin.
