## Alejandro Pérez

Después de reunirnos, discutir las opciones que teniamos para resolver nuestro problema (MPI u OpenMP) y definir que el enfoque que tomaremos es el de OpenMP,
revisé los códigos de multiplicación de matrices que vimos en la tarea6 y, utilizando los archivos definiciones.h y funciones.c,
dediqué el avance a la programación del [código](Código) secuencial para la multiplicación de matrices. Para poder utilizar este código es necesario
tener las matrices a multiplicar A y B en archivos de texto plano.


## Patricio Hernández

Como menciona Alex, una vez que definimos utilizar el efoque de openMP y comenzamos a planear los próximos avances y debido a que 
queremos hacer muchos comparativos para mostrar la mejora que se tiene con la paralelización, notamos que será necesario generar muchas
matrices de prueba por lo que desarrollé el [código](Código) para esto.

## Equipo
Definimos la metodología final que utilizaremos para la paralelización: paralelización de tareas entre los cores. Comenzamos a desarrollar la 
implementación y generamos el código para realizar la multiplicación secuencial que nos será útil como punto de comparación. 

Como mencionamos en el avance pasado, dentro del alcance del proyecto consideramos la comparación del código secuencial con el paralelo para ejemplificar
la mejora que se tiene en diversos escenarios. Dado lo anterior nos dimos cuenta que requerimos generar matrices de prueba de alta dimensión por ello 
desarrollamos el código para generar matrices.

Para los próximos avances definimos:
  * (2-mayo) Implementación en paralelo y pruebas de tiempos y eficiencia.
  * (8-mayo) Prueba de los códigos en AWS e investigación de otras métricas de comparación.
  * (15-mayo) Automatización del pipeline con Docker.
  * (Semana finales) Avance del trabajo escrito, idealmente a un 70%.
