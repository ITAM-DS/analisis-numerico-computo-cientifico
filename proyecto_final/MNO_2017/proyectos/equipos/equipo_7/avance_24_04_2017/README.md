## Avance_24_04_2017

---

### Integrantes:

---

- Mariana Carmona Baez
- Omar Díaz Landa

### Trabajo:

---

#### Individual

A ambos nos quedó pendiente la vez pasada leer los capítulos 10 y 14 del libro
de Pachelo de Parallel Programming with MPI.

El resumen sobre esta referencia será incluído en el reporte final.



#### Equipo

Nos reunimos para construir el programa que incluye comunicación entre procesos,
el cual está formado por los siguientes módulos:

- Lectura y validación de argumentos globales de la función
  * Broadcast de parámetros globales a cada uno de los procesos
  * Finaliza la ejecución en caso de que los argumentos no sean válidos
  * Queda por investigar si podemos pasar el nombre del `.txt` como argumento
- Tenemos 3 posibles maneras de pasar a la función el vector de números enteros
 que deseamos ordenar, además de distribuirlos de manera uniforme utilizando la función
 `MPI_Scatter`,
  * Generación de una lista aleatoria
  * Lectura del stdin que ingresa el usuario
  * Lectura de un archivo `.txt`
- Módulo que imprime el arreglo a ordenar
- Módulo para imprimir los elementos que a cada proceso fueron asignados

__NOTA:__ Adjuntamos un screenshot de la comunicación así como los archivos que
se generaron en este primer intento.

Con esto hemos terminado de comprender la lectura de los datos y la distribución
hacia cada uno de los procesos. Nos encontramos desarrollando el algoritmo de
ordenamiento _Odd-even transposition sort_, en particular la identificación de las
fases _odd_ e _even_, así como la definición de cada uno de los _partners_ que necesitamos comparar
en cada de las fases.

Finalmente, usaremos la función `qsort` de `stdlib.h`para ordenar de manera
secuencial los arreglos en cada uno de los procesos, antes de que inicien las fases del
algoritmo.



---

## Comentario sobre avance:
