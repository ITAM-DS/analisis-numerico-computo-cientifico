## Avance_17_04_2017

---

### Integrantes:

---

- Mariana Godina
- Sonia Mendizábal

### Trabajo:

---

#### Individual


**Mariana:**

Leí el artículo que Sonia leyó la semana pasada para poder hacer la comparación de los ordenamientos que proponen ambos artículos. Con respecto al artículo [1](https://maths-people.anu.edu.au/~brent/pd/rpb084i.pdf) se decidió no profundizar en el nuevo ordenamiento. Sobre la simetría de las matrices se puede tomar ventaja, que $A$ es simétrica y las transformaciones permanecen simétricas por lo tanto sólo es necesario uno de los dos triángulos ya sea el superior o el inferior para la descomposición de los eigenvalores. 

Del artículo [2](https://pdfs.semanticscholar.org/cf5e/afcd87a9fcf1c77cfb431f0b8a8518f11445.pdf) tomamos el ordenamiento *Round Robin* y el _Ring Jacobi Ordering_. Los dos ordenamientos son equivalentes. Después de leer este artículo se investigó más sobre estos ordenamientos y encontré este artículo [3](http://maths-people.anu.edu.au/~brent/pd/rpb153.pdf) en el cual viene más detallado esta equivalencia y cómo funcionan los ordenamientos. 

El artículo 3 explica que los ordenamientos de Jacobi se pueden clasificar en dos grupos equivalentes y que el _odd-even ordering_ y el _Round Robin ordering_ son dos buenas representaciones para cada uno de estos grupos. Los resultados de experimentos muestran que estos dos ordenamientos difieren en la convergencia para _one-side_ Jacobi. El mejor ordenamiento es el _Round Robin_ con una clasificación de índices, también se podría usar _Ring Jacobi ordering_. 



**Sonia:** 

Finalicé la lectura del capítulo 8 del libro *G. H. Golub*, sobre Métodos
Jacobi para obtener eigenvalores. Se incluye un resumen sobre esto en 
el primer avance del [trabajo escrito](equipo_11/trabajo_escrito).

Además, revisé la referencia *G. H. Dunteman. Principal Component Analysis*
y se incluye un capítulo sobre esto en 
el primer avance del [trabajo escrito](equipo_11/trabajo_escrito).







#### Equipo


Discutimos sobre los ordenamiento *Round Robin Ordering* y *Ring Jacobi Ordering*,
hasta este momento no hemos decidido alguno de los dos por la equivalencia entre
ambos. 

Encontramos que el paquete *LAPACK* implementa la descomposición 
en valores singulares. Investigaremos el ordenamiento usado por el 
paquete y si es útil en lugar de la implementación 
manual del algoritmo. 

Queda pendiente revisar la referencia de los [cyclic distribution (round robin)](http://www.cs.usfca.edu/~peter/ppmpi/) en particular el 
apartado 8.4.1. 

También queda pendiente la revisión de la referencia 
*Carl D. Meyer* para 
profundizar 
sobre la teoría de eigenvalores y vectores, diagonalización y 
descomposición en valores singulares, así como las rotaciones 
Givens.






---