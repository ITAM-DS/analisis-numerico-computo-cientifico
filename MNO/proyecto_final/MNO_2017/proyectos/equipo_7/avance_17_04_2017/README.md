## Avance_17_04_2017

---

### Integrantes:

---

- Mariana Carmona Baez
- Omar Díaz Landa

### Trabajo:

---

#### Individual

**Mariana:**

Avances:

Leí la sección 3.7 del libro [Pacheco](https://www.dc.uba.ar/materias/escuela-complutense/2012/pacheco2011) acerca de algoritmos de ordenamiento distribuido. En particular, acerca del algoritmo de burbuja de manera secuencial y el algoritmo de _Odd-even transposition sort_ (tal y como nos aconsejaste en los comentarios de la semana pasada). Aquí entendí de una manera más clara la comunicación entre procesos que debemos de implementar para este algoritmo, el ejemplo de la tabla 3.8 que muestra el libro fue de mucha ayuda, porque me guió paso a paso a entender cada una de las fases en el ordenamiento.

Implementé el [algoritmo de burbuja](./seq_bubble.c).


**Omar:**

Avances:

Leí sobre cómo podemos evaluar el performance de los programas en MPI en libro de [Pacheco](https://www.dc.uba.ar/materias/escuela-complutense/2012/pacheco2011) esto nos va a ayudar para determinar cuál será el algoritmo de ordenamiento con mejor desempeño a través de las métricas *T_serial*, *T_parallel*, *Speedup*, *Efficiency*, así como las gráficas que vimos en la referencia de la semana pasada. Estas métricas, tal y como vimos en el libro, las probaremos bajo distintos escenarios, incrementando tanto el orden de los datos como el número de procesos.

Implementé el [algoritmo quicksort en su manera secuencial](./seq_quicksort.c).




#### Equipo
Elaboramos un nuevo plan de trabajo, el cual se presenta a continuación:

  * Profundizar en los diferentes algoritmos de ordenamiento
  * Implementación de algoritmos de ordenamiento secuenciales (Quick Sort y burbuja)
  * Definición del ambiente en el cual se desarrollará el proyecto (inclinándonos por MPI)
  * Pruebas de Collective Communication
  * Implementar el algoritno de ordenamiento distribuido

Después de compartir lo que cada uno ha leído de manera individual decidimos que debíamos implementar el algoritmo secuencial de burbuja (avance Mariana) para el ordenamiento de datos, ya que ha demostrado ser un algoritmo rápido y eficiente. Además consideramos que este algoritmo puede servir de punto de referencia para su comparación contra algoritmos distribuidos. Decidimos lo anterior, debido a que a que por la naturaleza de este algoritmo no permite su paralelización. Resulta interesante compararlo con algoritmos en los que se pierde tiempo en la comunicación entre procesos. Adicionalmente implementamos el algoritmo secuencial quicksort (avance Omar) para tener la comparación de un mismo algoritmo de manera secuencial y en paralelo.

Nota: La parte del código para leer la información y prepar el arreglo que alimenta a las funciones la trabajamos de manera conjunta para tener inputs homogéneos.

Tenemos como pendientes para los avances posteriores:

* Investigar por qué el cluster semi-distribuido como el que levantamos en clase funciona correctamente para openmp pero no para mpi. No encuentra el compando mpicc
* Investigar cómo definir el tamaño del arreglo de manera automática al ser leido de un archivo desde el stdinput
* Leer los capítulos 10 y 14 del libro parallel Programming with MPI

---

## Comentario sobre avance:
