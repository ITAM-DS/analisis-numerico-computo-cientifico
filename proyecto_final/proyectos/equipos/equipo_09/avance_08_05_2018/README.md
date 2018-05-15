# Avance_08_05_2018

Equipo 9 
=================================================
**Título del proyecto:** Mínimos Cuadrados usando la Factorización QR y CUDA

**Objetivo del proyecto:** Implementar el algoritmo QR para el lenguaje de programación C bajo un enforque de programación en paralelo usando CUDA


Integrantes
---------------------------------------------------
+ Karen Peña (175952)
+ Miguel Catañeda (175840)
+ Fernando Briseño (171349)


## Trabajo:

### Individual

Karen: 

Durante esta semana he revisado los manuales de [Documentación CUDA](https://docs.nvidia.com/cuda/cuda-c-best-practices-guide/#memory-optimizations) y el documento que aborda la [librería CUSOLVER](https://docs.nvidia.com/cuda/pdf/CUSOLVER_Library.pdf) para incorporarlo al trabajo escrito en el apartado:
+ Arquitectura computacional: CUDA
Por otro lado, hice algunas modificaciones de forma a los apartados:
+ Factorización QR mediante el uso de reflexiones de Householder
+ Factorización QR para el problema de mínimos cuadrados
para facilitar la lectura.

 
Miguel: 

En este avance trabajé en la implementación del método de mínimos cuadrados aprovechando el avance realizado la semana pasada para la solución de Ax =B   utilizando la factorización QR. De la semana pasada me habían quedado pendientes el poder utilizar las rutinas utilizadas en las tareas de C, ya hice las modificaciones para que pudieran funcionar las rutinas.

Los cambios que realicé fueron en el programa cuando se invoca malloc le indiqué el cast al tipo de dato resultado, esto es:


```
AA = (arreglo_2d_T) malloc(sizeof(*AA));
BB = (arreglo_2d_T) malloc(sizeof(*BB));
XX = (arreglo_2d_T) malloc(sizeof(*XX));
```

Por otro lado en las instrucciones para compilar se tiene que hacer en dos pasos, primero para los archivos *c* y luego para los archivos cuda *cu*, esto es primero hay que hacer: 


```
nvcc -x cu  -I. -dc funciones.c 
```

Esto compila el archivo funciones generando el archivo funciones.o 

Luego se tiene que compilar y hacer el link para el programa de cuda 

```
nvcc -I/usr/local/cuda/include funciones.o MCQR.cu -o MCQR.out -lcublas -lcusolver
```

Agregué las moficaciones para que se realicen desde el makefile, quedando como: 


Iniciar el contenedor: 

```
nvidia-docker run -dit -v $PWD:/programas  --name=mno_cuda_gpu  mno_cuda_gcc
```

Para compilar me conecté al contenedor: 

```
nvidia-docker exec -it mno_cuda_gpu /bin/bash
```

Para compilar y ejecutar el programa, ejecuté dentro de la carpeta programas, haciendo que lea las matrices desde los archivos A.txt y B.txt

```
make ejecuta
```

[Makefile](../codigo/Makefile)

[MCQR.cu](../codigo/MCQR.cu)

[A.txt](../codigo/A.txt)

[B.txt](../codigo/B.txt)

Con el siguiente resultado: 

```
root@efbde023d434:/programas# ./MCQR.out 
matriz[0][0]=1.00000	matriz[0][1]=-2.00000	matriz[0][2]=3.00000
matriz[1][0]=5.00000	matriz[1][1]=8.00000	matriz[1][2]=-1.00000
matriz[2][0]=2.00000	matriz[2][1]=1.00000	matriz[2][2]=1.00000

matriz[0][0]=2.00000
matriz[1][0]=-1.00000
matriz[2][0]=3.00000

=======================
Solución X
matriz[0][0]=5.30000
matriz[1][0]=-3.90000
matriz[2][0]=-3.70000
=======================

```

Es importante que si se compila el programa sin el contenedor se debe utilizar la versión 9 de CUDA. 

Para la siguiente entrega voy a agregar pruebas con otros conjuntos de datos y hacer comprobaciones de los resultados.



Fernando:

Esta semana revisé los materiales de la implementación en CUDA. No tengo un resultado concreto para reportar, sino hasta la próxima semana.


### Equipo

Se ha generado un documento con corte al día de hoy para facilitar la revisión semanal; así mismo en el plan de trabajo se incluyen las ligas:  

Trabajo escrito (fuera del repo): [liga_trabajo_escrito](https://drive.google.com/drive/folders/1EkRomjpJLi_mLgXNvKZA1uizJJKIVNlk)

Presentación (fuera del repo): [liga_presentación](https://drive.google.com/drive/folders/1KN2nghXPG8c8GwU9f5t46snOMRBbrf-F)

Implementación (en el repo): [código](../codigo/MCQR.cu)
