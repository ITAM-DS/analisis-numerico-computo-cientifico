# Métodos Numéricos y Optimización 2018

[Temario](https://www.dropbox.com/s/je8py3q0623u7jk/TEMARIO_MNO.pdf?dl=0)

[El curso, calificación y entregas, correo al cual escribir](https://www.dropbox.com/s/j4duvz17oxm70ts/Curso_MNO.pdf?dl=0)

[Equipos de MNO](https://www.dropbox.com/s/06t0yvzhg4d860l/equipos_por_nombres.txt?dl=0)

[Lista alumn@s con calificaciones](https://www.dropbox.com/s/7istu5rzfa4zlol/salon_pf_103.xlsx?dl=0)

[Objetivo, descripción, lista de ejemplos para proyecto final](proyecto_final)

[Indicaciones para proyecto final MNO](proyecto_final/indicaciones)

[Lista de proyectos finales MNO](proyecto_final/proyectos)

[Liga hacia clases de C](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C)

[Liga hacia índice del branch master](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master)

[Tutorial para activar créditos de Amazon Web Services](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/wiki/Activar-creditos-de-AWS)

## Clase 1

15 de enero

Introducción, forma de calificar, dinámica de clase, generalidades del curso.

Revisamos notas: 

[I/1.1](https://www.dropbox.com/s/z5ifw3ti66gukdy/1.1.Analisis_numerico_y_computo_cientifico.pdf?dl=0)

[I/1.2](https://www.dropbox.com/s/9fsupm3bhwmv7cb/1.2.Sistema_de_punto_flotante.pdf?dl=0) hasta ejercicio de aritmética en punto flotante.


## Clase 2

20 de enero

Revisión de notas [I/1.1](https://www.dropbox.com/s/z5ifw3ti66gukdy/1.1.Analisis_numerico_y_computo_cientifico.pdf?dl=0), [I/1.2](https://www.dropbox.com/s/9fsupm3bhwmv7cb/1.2.Sistema_de_punto_flotante.pdf?dl=0)

Nota [I/1.3](https://www.dropbox.com/s/5bc6tn39o0qqg35/1.3.Condicion_estabilidad_y_normas.pdf?dl=0) hasta normas matriciales.

Introducción a C: [clase1](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/clases/clase1.md), [historia de clase de C](https://www.dropbox.com/s/2btpracfm4munik/historia_clase1.txt?dl=0)

Clase 27 de enero introducción a C. [historia de clase de C, repetición](https://www.dropbox.com/s/ci934tf4vvzsi0e/historial_clase1_repetcion.txt?dl=0)

## Clase 3

22 de enero

Revisión de notas [I/1.3](https://www.dropbox.com/s/5bc6tn39o0qqg35/1.3.Condicion_estabilidad_y_normas.pdf?dl=0) y [II/2.1](https://www.dropbox.com/s/z465znq3wwao9ad/2.1.Un_poco_de_historia_y_generalidades.pdf?dl=0) hasta Cache

## Clase 4

29 de enero

Nota [II/2.1](https://www.dropbox.com/s/z465znq3wwao9ad/2.1.Un_poco_de_historia_y_generalidades.pdf?dl=0) hasta términos de paralelo, concurrencia y distribuido.

Clases de C: [clase2](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/clases/clase2.md), [clase3](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/clases/clase3.md) hasta arreglos.

## Clase 5

10 de febrero

Finalizamos nota [II/2.1](https://www.dropbox.com/s/z465znq3wwao9ad/2.1.Un_poco_de_historia_y_generalidades.pdf?dl=0) 

[Levantamos clúster de forma pseudodistribuida con docker y openMPI.](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/extensiones_a_C/MPI/openMPI)

Se inició la configuración en la cuenta de AWS de acuerdo al [tutorial](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/wiki/Iniciar-cluster-con-Autoscaling-y-OpenMPI). Se indicó finalizar el mismo para la clase de lunes 12.

## Clase 6

12 de febrero

Nota de MPI [II/2.2](https://www.dropbox.com/s/v4ub0p3ndf7w1p0/2.2.Sistemas_de_memoria_distribuida_MPI.pdf?dl=0) hasta ejemplo de `hello_world.c`

Clases de C: [clase3](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/clases/clase3.md), [clase4](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/clases/clase4.md) hasta definición y declaración de arreglos de apuntadores.

## Clase 7

19 de febrero

Clases de C: [clase4](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/clases/clase4.md) y [clase 5](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/clases/clase5.md)

Se revisó hasta el punto 6.2 del [tutorial](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/wiki/Iniciar-cluster-con-Autoscaling-y-OpenMPI) para levantar un clúster en AWS y openMPI.

## Clase 8

26 de febrero

Clase 6 de C: [clase6](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/clases/clase6.md)

Se terminó el  [tutorial](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/wiki/Iniciar-cluster-con-Autoscaling-y-OpenMPI) para levantar un clúster en AWS y openMPI.

Se corrieron los [ejemplos](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/extensiones_a_C/MPI/openMPI/ejemplos/1_send_receive_broadcast_reduce) hello_clase.c y trapecio_compuesto.c en el clúster de AWS.

Terminamos la nota  de MPI [II/2.2](https://www.dropbox.com/s/v4ub0p3ndf7w1p0/2.2.Sistemas_de_memoria_distribuida_MPI.pdf?dl=0), sólo faltan algunas observaciones para MPI.

Fijamos fecha de exámenes: 

* 5 de marzo de teoría preguntas de temas: 1.1, 1.2, 1.3, 2.1 (ir a la branch de [master](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master) para tener las preguntas)

* 12 de marzo examen de C

## Clase 9

5 de marzo

Finalizamos tema de MPI.

Examen módulo 1 hasta 2.1

Iniciamos nota sobre Pthreads [II/2.3](https://www.dropbox.com/s/oauifmx3e19ofyq/2.3.Sistemas_de_memoria_compartida_Pthreads.pdf?dl=0) y [ejemplos](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/extensiones_a_C/Pthreads/ejemplos)


## Clase 10

10 de marzo

Finalizamos notas de Pthreads [II/2.3](https://www.dropbox.com/s/oauifmx3e19ofyq/2.3.Sistemas_de_memoria_compartida_Pthreads.pdf?dl=0) y openMP [II/2.4](https://www.dropbox.com/s/vcxbrqkk6x946d7/2.4.Sistemas_de_memoria_compartida_openMP.pdf?dl=0) con [ejemplos](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/extensiones_a_C/openMP/ejemplos) de directivas y clauses o cláusulas de openMP.


## Clase 11

12 de marzo

Nota sobre CUDA [II/2.4](https://www.dropbox.com/s/yjijtfuky3s5dfz/2.5.Compute_Unified_Device_Architecture.pdf?dl=0) hasta CUDA memories.

Examen de C.


## Clase 12

2 de abril

Revisión de nota [II/2.4](https://www.dropbox.com/s/yjijtfuky3s5dfz/2.5.Compute_Unified_Device_Architecture.pdf?dl=0) hasta CUDA memories y levantamiento en AWS de una instancia con toolkit de CUDA instalado de acuerdo a [liga](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/extensiones_a_C/CUDA/instalacion)







