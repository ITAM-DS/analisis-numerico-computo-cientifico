Avance_24_04_2017
-----------------

---

### Integrantes:

---

-	Mariana Carmona Baez
-	Omar Díaz Landa

### Trabajo:

---

#### Individual

##### Mariana

El aporte que tuve esta semana al equipo consistió en investigar cómo podíamos implementar el algoritmo de ordenamiento secuencial dentro de cada uno de los procesos. Además me encargaré de crear una función en R que nos ayude a ordenar el output del algoritmo, ya que por el no determinismo del mismo mostrar los avances y resultados nos representa mucho tiempo. En esta entrega hemos ajustado el output de manera manual.

##### Omar

El pendiente de esta semana para mi consistía en implementar la definción de los *partners* tal y como se muestra en el pseudocódigo *Compute_partner* del libro de Pacheco. Una vez que conocemos contra qué partner comparar en cada una de las fases, iniciamos el proceso de envio y recepción de los datos entre procesos. Para ello utilizamos la función *MPI_Sendrecv* e imprimios los resultados para validar nuestros avances. Este último avance lo inició Mariana pero lo concluimos juntos.

#### Equipo

Los avances que se muestran en equipo son en parte los mismos que se exhibieron en el avance individual, sin embargo, al encontrarse en esta sección es por que una vez que cada quien realizó su avance, nos tuvimos que juntar para agregar cada uno de los módulos al proyecto final:

-	El arreglo que se está pasando como input y su distribución entre los procesos utilizando el código que generamos para la entrega anterior (obviamente acomodando los resultados de manera manual) es:

```
Global list: 40 6 1 7 8 90 465 71 22 82

Before: Process 0 has the elements: 40 6
Before: Process 1 has the elements: 1 7
Before: Process 2 has the elements: 8 90
Before: Process 3 has the elements: 465 71
Before: Process 4 has the elements: 22 82
```

-	Implementamos el código que ordena de manera secuencial dentro de cada proceso. Parte fundamental del algoritmo de odd-even transposition sort

```
After: Process 0 has the elements: 6 40
After: Process 1 has the elements: 1 7
After: Process 2 has the elements: 8 90
After: Process 3 has the elements: 71 465
After: Process 4 has the elements: 22 82
```

-	Hemos resuelto el pendiente que expresamos la semana pasada referente a la definición de los *partners* contra los que necesitamos comparar en cada de las fases tal y como se muestra a continuación

```
Hi im the process 0, my odd partner is -1 and my even parter is 1
Hi im the process 1, my odd partner is 2 and my even parter is 0
Hi im the process 2, my odd partner is 1 and my even parter is 3
Hi im the process 3, my odd partner is 4 and my even parter is 2
Hi im the process 4, my odd partner is 3 and my even parter is -1
```

-	Finalmente validamos que el envío y la recepción de los datos entre procesos es el indicado. El resto del output se puede encontrar en el archivo *output.txt* adjunto en la entrega, obviamente aún no se puede analizar cada una de las fases ya que nos falta el código que reemplaza los valores por los $n/p$ valores más pequeños o grandes según sea el caso.

```
Before: Phase[0], my_rank[0], even_partner[1], local_A[0] = 6, temp_B[0]=1
Before: Phase[0], my_rank[0], even_partner[1], local_A[1] = 40, temp_B[1]=7
Before: Phase[0], my_rank[1], even_partner[0], local_A[0] = 1, temp_B[0]=6
Before: Phase[0], my_rank[1], even_partner[0], local_A[1] = 7, temp_B[1]=40
Before: Phase[0], my_rank[2], even_partner[3], local_A[0] = 8, temp_B[0]=71
Before: Phase[0], my_rank[2], even_partner[3], local_A[1] = 90, temp_B[1]=465
Before: Phase[0], my_rank[3], even_partner[2], local_A[0] = 71, temp_B[0]=8
Before: Phase[0], my_rank[3], even_partner[2], local_A[1] = 465, temp_B[1]=90

```

Por lo tanto, los pendientes que tenemos para la siguiente entrega consisten en: - Generar el código que conserva los valores pequeños o grandes de ambos arreglos según sea el caso - Investigar cómo correr el programa en el pseudocluster utilizando todos las máquinas y sus respectivos cores - Hacer la matriz de tiempos subiendo el orden de los datos, así como el orden d e los procesos, tanto como en la versión secuencial como en la versión en paralelo

---

Comentario sobre avance:
------------------------
