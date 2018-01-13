# Avance_29_05_2017

## Trabajo:

### Individual

#### Ollin:
Hice un gran esfuerzo por lograr la paralelización en CUDA pero me encontré con una gran limitante para importar funciones de C a archivos CUDA, pues ni con *extern* se lograba realizar esto. Indagando en el tema las soluciones que se proponen es cambiar de C a C++ para que sea compatible el linking con el compilador nvcc. También hay propuestas con g++ y hacer el linking pero como las estructuras están hechas en C y no conozco C++ fue algo no realizable. De cualquier manera el código sí compila directo con make y se hace un linking (que pude hacer gracias a StackOverflow y la página de ayuda de CUDA), pero de cualquier manera no se puede correr la función leer_red por lo que la estructura queda vacía y justo regresa valores de nodos y aristas iguales a cero. Para llegar a éste punto también tuve que lograr importar las estructuras que tengo de red, que son bastante complejas y tuve que estar muy consciente de la forma en la que dichas estructuras se mueven entre el Host y el Device y cómo deben ser usadas en cada uno de ellos en el kernel, en el main o en funciones compartidas. También ayudé con el reporte escrito.

[Repositorio](https://github.com/ollin18/complex_network_c/cuda)


#### Equipo:
Realizamos el reporte escrito y la presentación.

[Trabajo_Escrito](../trabajo_escrito/hashimoto_equipo_13.pdf)
