# Avance_02_05_2018

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

Durante esta semana trabajé en el desarrollo del [trabajo escrito](https://drive.google.com/drive/folders/1qdO82g4tMUY4IvcM4a0dw17bH8PqgW85) en particular sobre los apartados: 
+ Introducción
+ Fundamentos 
    + Método de mínimos Cuadrados
    + Factorización QR mediante el uso de reflexiones de Householder
    + Factorización QR para el problema de mínimos cuadrados
+ Bibliografía

Por otro lado, con el objetivo de continuar abarcando la bibliografía prevista, revisé el artículo de Buttari, et al. ["Parallel computing"](http://www.netlib.org/utk/people/JackDongarra/PAPERS/206_2009_A%20Class-of-Parallel-Tiled-Linear-Algebra-Algorithms-for-Multicore-Architectures.pdf) en donde se describe el paso abordan los algoritmos para la factorización Cholesky, LU y QR donde las operaciones se pueden representar como una secuencia de pequeñas tareas que operan en bloques cuadrados de datos. Menciona que estas tareas pueden programarse dinámicamente en función de las dependencias entre ellas y de la disponibilidad de los recursos computacionales. Esto puede dar como resultado la ejecución fuera de servicio de tareas que ocultará por completo la presencia de tareas intrínsecamente secuenciales en la factorización. 
Por otro lado, aborda las comparaciones en cuanto a rendimiento con algoritmos LAPACK donde el paralelismo solo se puede explotar a nivel de las operaciones BLAS. 
Considero que presenta un buen panorama general en el que muestra un ejemplo de algoritmo para la factorización QR pues facilita algunos diagramas que son de gran utilidad para comprender su funcionamiento de forma más didáctica. 
Finalmente concluye con la comparación de cada uno de los algoritmos evidenciando que el método de factorización QR es competente más no el mejor.

 
Miguel: 

En este avance trabajé en la implementación de la solución Ax = B utilizando la factorización QR. 

Para obtenerla se realizan los pasos 

|Operación|Rutina cuSolver|
|---|---|
|A = Q x R|cusolverDnDgeqrf|
|B = Q^T x B|cusolverDnDormqr|
|R x X = B|cusolverDnDormqr|

Para esta entrega tenía contemplado incluir la lectura de las matrices conforme lo trabajamos en las tareas 5 y 6 ([funciones.c](codigo/funciones.c) y [definiciones.h](codigo/definiciones.h)) pero tuve varios problemas para integrarlos con CUDA, el primero es que la función malloc como la usamos en C no es necesario especificar un cast al invocar la función y en el caso de usar el compilador nvcc está usando el comportamiento como si fuera c++ por lo que para usar la función malloc es necesario indicarle el un cast

Por ejemplo, en el caso de la compilación con gcc se puede hacer: 

```
A = malloc(sizeof(arreglo_2d_T));
```

Pero compilando con nvcc marca un error al indicar que la función regresa un void por lo que tuve que hacer:

```
A = (arreglo_2d_T) malloc(sizeof(arreglo_2d_T));
```

El segundo problema es la compilación de archivos cu y de archivo c y h, el compilador nvcc marcó un error al compilar de la siguiente forma : 

```
$(CC) $(CFLAGS) $(CINCLUDE) SolverQr.cu funciones.c definiciones.h -o SolverQr.out $(CLIBS)
```
[Makefile](codigo/Makefile)

Voy a trabajar en hacer los cambios en la definición de las funciones  y en el archivo Makefile para poder hacer la compilación, busqué una referencia de como se puede atender este problema y encontré
la liga:

[https://devblogs.nvidia.com/separate-compilation-linking-cuda-device-code/](https://devblogs.nvidia.com/separate-compilation-linking-cuda-device-code/)

Para poder probar la implementación con diferentes matrices A y vectores B generé matrices con números aleatorios entre los valores [-5,5], el número de columnas y el total de vectores B se pasan como argumentos al programa


Para compilar el programa usé el contenedor de docker configurado para el proyecto, ejecutando: 

Iniciar el contenedor: 

```
nvidia-docker run -dit -v $PWD:/programas  --name=mno_cuda_gpu  mno_cuda_gcc
```

Para compilar me conecté al contenedor: 

```
nvidia-docker exec -it mno_cuda_gpu /bin/bash
```

Para compilar el programa ejecuté dentro de la carpeta programas

```
make compila
```

Para ejecutarlo y probar con una matriz generada de manera aleatoria de 6x6 y 4 vectores de B lo cual generaría 4 vectores solución X se debe ejecutar: 

```
./SolverQr.out 6 4
```

[Makefile](codigo/Makefile)

[SolverQr.cu](codigo/SolverQr.cu)

Con el siguiente resultado: 

```
root@8ee7dfffba40:/programas# ./SolverQr.out 6 4
Matriz A:
A[1,1] = -0.321278	A[1,2] = 3.861394	A[1,3] = 0.455748	A[1,4] = 4.221673	A[1,5] = -2.855513	A[1,6] = -3.653388	
A[2,1] = 2.136530	A[2,2] = 0.613998	A[2,3] = 2.114917	A[2,4] = -1.884198	A[2,5] = 2.290007	A[2,6] = 0.345506	
A[3,1] = -4.120763	A[3,2] = -0.567862	A[3,3] = 4.771340	A[3,4] = -1.022164	A[3,5] = -4.976972	A[3,6] = 2.270012	
A[4,1] = -2.088790	A[4,2] = -3.885424	A[4,3] = -0.307358	A[4,4] = -1.810088	A[4,5] = -1.551438	A[4,6] = -2.774151	
A[5,1] = -3.961546	A[5,2] = -4.080688	A[5,3] = -1.068173	A[5,4] = 1.477438	A[5,5] = -4.333216	A[5,6] = 3.256716	
A[6,1] = 2.801884	A[6,2] = 4.394467	A[6,3] = 2.984427	A[6,4] = -0.169516	A[6,5] = -4.866518	A[6,6] = 3.308465	
==============
Vector B:
B[1,1] = -4.972267	B[1,2] = -1.145663	B[1,3] = -3.389895	B[1,4] = -4.581575	
B[2,1] = 2.118110	B[2,2] = -1.311567	B[2,3] = 2.602747	B[2,4] = -2.062853	
B[3,1] = -1.077536	B[3,2] = -3.043308	B[3,3] = 4.004322	B[3,4] = -2.228233	
B[4,1] = -0.540129	B[4,2] = -1.374322	B[4,3] = 0.587941	B[4,4] = -4.558548	
B[5,1] = 3.232685	B[5,2] = 3.381075	B[5,3] = -4.207340	B[5,4] = 1.385709	
B[6,1] = -0.158225	B[6,2] = 0.888519	B[6,3] = 0.481760	B[6,4] = -1.561449	
==============
Vector Solución X
X[1,1] = 1.195821	X[1,2] = 0.663631	X[1,3] = -0.971599	X[1,4] = -1.386290	
X[2,1] = -1.515703	X[2,2] = -0.502829	X[2,3] = 0.970302	X[2,4] = 1.386197	
X[3,1] = 0.723005	X[3,2] = -0.473488	X[3,3] = 0.157991	X[3,4] = -1.603250	
X[4,1] = 0.905290	X[4,2] = 0.574159	X[4,3] = -1.569452	X[4,4] = -0.875513	
X[5,1] = 0.196784	X[5,2] = -0.223206	X[5,3] = 0.349953	X[5,4] = 0.606948	
X[6,1] = 0.636335	X[6,2] = 0.502635	X[6,3] = -0.028532	X[6,4] = 1.154998	

```

Es importante que si se compila el programa sin el contenedor se debe utilizar la versión 9 de CUDA. 


Fernando:




### Equipo

Platicamos con el equipo 3 y ellos comentaron que van a trabajar con OpenMP, por lo que nosotros vamos a trabajar con CUDA.







