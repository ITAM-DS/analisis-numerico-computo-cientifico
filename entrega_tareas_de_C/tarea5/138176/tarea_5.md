---
title: "Tarea 5"
author: "Daniel Sharp"
date: "March 7, 2018"
output: 
  html_document:
    keep_md: true
---

### 1. Estudia y entiende los archivos definiciones.h y funciones.c de ahí, en particular investiga por qué se usan "" en la línea que tiene #include en funciones.c en lugar de usar < >. Investiga el uso de static en la definición de variables externas de funciones.c .  

Cuando se utilizan las comillas ("") se indica al programa que primero busque el archivo entre comillas en el directorio que contiene el programa que está compilando y, si no lo encuentra, que lo busque posteriormente en el directorio estándar del sistema que contiene arhivos como stdin.h y string.h. Únicamente tiene sentido utilizarlas cuando se quiere agregar un programa propio.

Static se utiliza para funciones que solamente son visibles para otras funciones en el mismo ejecutable o unidad de traducción. Es decir, en este caso las funciones static únicamente serán visibles para los archivos que se encuentren en el comando: gcc main.c funciones.c -o programa.out, en este caso, para main.c. Es una forma de encapsular el programa.  
  
### 2. Investiga* sobre BLAS, CBLAS, LAPACK, ATLAS y las operaciones de nivel 1, nivel 2 y nivel 3 de BLAS y reporta sobre esta investigación que realizas. Es una investigación que contiene principalmente una descripción sobre los paquetes y niveles anteriores.  

#### BLAS  
Basic Lineal Algebra Subprograms (BLAS) es una librería con rutinas para resolver problemas de álgebra lineal. Sus funciones se dividen en tres niveles de acuerdo a su nivel de complejidad:  

- Nivel 1: trabaja con escalares, vectores y operaraciones vector-vector  

- Nivel 2: operaciones matriz-vector  

- Nivel 3: operaciones matriciales (matriz-matriz)  

#### CBLAS  
Por lo que se puede entender en las referencias proporcionadas, es el archivo 'cblas.h' que contiene los prototipos para que todas las funciones que puede realizar BLAS se puedan correr desde C. El código original está escrito en Fortran. Proporciona una interfaz para utilizar las funciones de BLAS en C.  

#### LAPACK  
Linear Algebra Package (LAPACK) que provee rutinas de algebra lineal para resolver sistemas de ecuaciones lineales, obtener soluciones de mínimos cuadrados, problemas con eigenvalores y de valores singulares. El objetivo incial de LAPACK consistió en ejecutar las liberías de EISPACK y LINPACK de froma eficiente en procesadores paralelos de memoria compartida. LAPACK está diseñado de tal forma que realiza todas las operaciones que le sea posible a través de BLAS. De hecho, LAPACK está diseñado para optimizar el Nivel 3 de BLAS. LAPACK aprovecha la gruesa granularidad de las operaciones de BLAS Nivel 3, que son altamente eficientes en computadoras de alto desempeño.  

#### ATLAS  
Automatically Tuned Linear Algebra (ATLAS) provee interfaces para BLAS y algunas rutinas de LAPACK para ser ejecutadas en C y Fortran77. El principal objetivo de ATLAS es proveer librerías optimizadas.  


### 3. En la carpeta analisis-numerico-computo-cientifico/C/BLAS/ejemplos/level1/ ejecuta el programa dot_product.c y realiza pruebas con diferentes vectores definidos por ti.  

Pruebo el ejemplo de las notas:  

```bash
gcc -Wall dot_product.c funciones.c -o programa.out -lblas
./programa.out 3
```

```
## ------------
## vector :
## vector[0]=1.00000
## vector[1]=0.00000
## vector[2]=-3.00000
## ------------
## vector :
## vector[0]=5.00000
## vector[1]=8.00000
## vector[2]=9.00000
## ------------
## resultado: -22.000000
```

Pruebo con vectores de 5 valores:  

```bash
echo "2
4" >> v1.txt
echo "5
12" >> v2.txt
gcc -Wall dot_product.c funciones.c -o programa.out -lblas
./programa.out 5
```

```
## ------------
## vector :
## vector[0]=1.00000
## vector[1]=0.00000
## vector[2]=-3.00000
## vector[3]=2.00000
## vector[4]=4.00000
## ------------
## vector :
## vector[0]=5.00000
## vector[1]=8.00000
## vector[2]=9.00000
## vector[3]=5.00000
## vector[4]=12.00000
## ------------
## resultado: 36.000000
```

Pruebo con vector de 10 valores:  

```bash
echo "12
54
13
10
1" >> v1.txt
echo "9
7
11
15
18" >> v2.txt
gcc -Wall dot_product.c funciones.c -o programa.out -lblas
./programa.out 10
```

```
## ------------
## vector :
## vector[0]=1.00000
## vector[1]=0.00000
## vector[2]=-3.00000
## vector[3]=2.00000
## vector[4]=4.00000
## vector[5]=12.00000
## vector[6]=54.00000
## vector[7]=13.00000
## vector[8]=10.00000
## vector[9]=1.00000
## ------------
## vector :
## vector[0]=5.00000
## vector[1]=8.00000
## vector[2]=9.00000
## vector[3]=5.00000
## vector[4]=12.00000
## vector[5]=9.00000
## vector[6]=7.00000
## vector[7]=11.00000
## vector[8]=15.00000
## vector[9]=18.00000
## ------------
## resultado: 833.000000
```

### 4. Investiga* sobre la subrutina de Fortran ddot (parámetros que recibe y la salida).  
* La fuente indicada para BLAS conduce a [este manual de LAPACK]( http://www.netlib.org/lapack/explore-html/de/da4/group__double__blas__level1_ga75066c4825cb6ff1c8ec4403ef8c843a.html#ga75066c4825cb6ff1c8ec4403ef8c843a), pero parece ser aplicable a BLAS   

La función ddot() recibe los siguientes 5 parámetros:  
- N: Número de elementos en vectores a evaluar  
- DX: Arreglo de 'doubles', con dimension ( 1 + ( N - 1 )abs( INCX ) )  
- INCX: Entero con los espacios de almacenamiento entre elementos de DX  
- DY: Arreglo de 'doubles', con dimension ( 1 + ( N - 1 )abs( INCY ) )  
- INCY: Entero con los espacios de almacenamiento entre elementos de DY  

La función regresa un double, con el valor del producto punto entre los vectores provistos.  

### 5. Haz un programa que utilice la subrutina daxpy de Fortran.  
* Las especificaciones de esta función las obtuve del mismo manual mecionado en el inciso anteior.  

La función daxpy ejecuta la multiplicación de una constante por un vector y le suma otro vector, regresa el vector resulante. Para hacer este programa se utilizarán como base los scripts utilizados en el inciso 3. 

La función daxpy() recibe los siguientes parámetros:  
- N: Número de elementos en vectores a evaluar  
- DA: Double constante por el cual multiplicar el primer vector  
- DX: Arreglo de 'doubles', con dimension ( 1 + ( N - 1 )abs( INCX ) )  
- INCX: Entero con los espacios de almacenamiento entre elementos de DX  
- DY: Arreglo de 'doubles', con dimension ( 1 + ( N - 1 )abs( INCY ) )  
- INCY: Entero con los espacios de almacenamiento entre elementos de DY  

Es importante mencionar que daxpy regresa el resultado en el mismo vector DY, por lo que no se asinga a una variable de salida, si no que la función es 'void' y sobreescribe el segundo vector de entrada.  

El código para este problema se encuentra en el archivo ej5_daxpy.c, además se muestra a continuación. La constante que multiplica al primer vector se recibe como el segundo argumento en la línea de comando, donde el primero es la longitud de los vectores y el segundo el antes mencionado. La salida de este programa es de la siguiente forma:  


```bash
gcc -Wall ej5_daxpy.c funciones.c -o daxpy.out -lblas
./daxpy.out 3 10
```

```
## ------------
## vector :
## vector[0]=1.00000
## vector[1]=0.00000
## vector[2]=-3.00000
## ------------
## vector :
## vector[0]=5.00000
## vector[1]=8.00000
## vector[2]=9.00000
## ------------
## Resultado:
## 15.000000
## 8.000000
## -21.000000
```
Código para daxpy

```bash
cat ej5_daxpy.c
```

```
## // Daniel Sharp 138176
## 
## #include<stdio.h>
## #include<stdlib.h>
## #include"definiciones.h"
## /* Se cambian los archivos de los vectores para que el resutlado del programa sea
## facilmente legible en la terminal
## */
## #define v1_vector "v1_daxpy.txt" //de tamaño Nx1
## #define v2_vector "v2_daxpy.txt" //de tamaño Nx1
## extern void daxpy_(int *n, double *a, double *x, int *incx, double *y, int *incy);
## int main(int argc, char *argv[]){
## 	arreglo_1d_T v1, v2;
## 	int incx=1;
## 	int N=atoi(argv[1]);
## 	// Se toma como segundo argumento la constante A que multiplicará al primer vector
## 	double a=atof(argv[2]);
## 
## 	v1=malloc(sizeof(*v1));
## 	v2=malloc(sizeof(*v2));
## 
## 	renglones_vector(v1)=N;
## 	renglones_vector(v2)=N;
## 
## 	entradas_vector(v1)=malloc(N*sizeof(double));
## 	inicializa_vector(v1,v1_vector);
## 	entradas_vector(v2)=malloc(N*sizeof(double));
## 	inicializa_vector(v2,v2_vector);
## 
## 	printf("------------\n");
## 	printf("vector :\n");
## 	imprime_vector(v1);
## 	printf("------------\n");
## 	printf("vector :\n");
## 	imprime_vector(v2);
## 	printf("------------\n");
## 
## 	daxpy_(&N, &a,entradas_vector(v1), &incx, entradas_vector(v2), &incx);
## 	printf("%s\n", "Resultado:");
## 	// Se itera sobre el vector v2 pues ahí es donde la función almacena la solución
## 	for(int i = 0; i<N; i++){
## 		printf("%lf\n", entradas_vector(v2)[i]);
## 	}
## 	free(entradas_vector(v1));
## 	free(v1);
## 	free(entradas_vector(v2));
## 	free(v2);
## 	return 0;
## }
```







