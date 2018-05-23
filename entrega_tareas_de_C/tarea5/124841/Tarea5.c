/*
Tarea 5
1) #include tiene dos sintaxis:  
       #include <filename.h>  
       #include"filename.h" 
  Las <> se ocupan cuando el archivo .h es parte del sistema, es decir viene con el compilador.
  Las "" se ocupan cuando el archivo .h es parte de tu programa, es decir el programa lo buscará dentro de la carpeta desde la que se esta corriendo el código. 
Al usar static antes de la definición de una variable externa le estas indicando que esta variable solo es visible en el archivo en el que la estás declarando (internal linkage), es decir no es visible para el linker al momento de compilar. El no usar static significa que la variable si es visible para toda la unidad que se compilará (external linkage). En el contexto de variables locales static es la contraparte de automatic, si declaras una variable como static su valor se inicializa una vez y de ahi cada vez que invoques a la funcion el valor se actualiza en lugar de inicializarse de nuevo.  

2)
BLAS: (Basic Linear Algebra Subprograms), son rutinas para facilitar la realización de operaciones en vectores y matrices.  La interfaz para C es CBLAS, aunque Fortran BLAS puede ser llamado desde C. Las operaciones se dividen en 3 niveles, el nivel 1 realiza operaciones escalares, con vectores y vector-vector. El nivel 2 realiza operaciones vector-matriz y el nivel 3 realiza operaciones matriz-matriz.

LAPACK (Linear Algebra Package): Software para álgebra lineal, tiene funciones para diversas tareas, por ejemplo resolver sistemas de ecuaciones lineales, descomposición en valores singulares, mínimos cuadrados, entre otros. LAPACK ocupa operaciones BLAS de nivel 3.  

ATLAS (Automatically Tuned Linear Algebra Software): Es una implementación optimizada de BLAS. Además de implementar todas las APIs de BLAS incluye algunas funciones de LAPACK


3) Para este ejercicio ejecutar en shell se copia a la carpeta el archivo funciones.c , deficniciones.h, v1.txt y v2.txt y se agrega el script Tarea5-3.sh 
Ejecutar en shell:

chmod+x Tarea3-5.sh 
y despues:

./Tarea3-5.sh

4) Subrutina Fortran ddot:
   Subrutina que calcula el producto interno o producto punto de dos vectores. Está estructurada de la siguiente manera:
   Parámetros que recibe:
   
   N Es el número de elementos que contiene cada vector 
   DX Vector X 
   INCX El tamaño de los incrementos con los que se irá recorriendo el vector X
   DY  Vector Y
   INCY  El tamaño de los incrementos con los que se irá recorriendo el vector Y
   
   OUTPUT: El producto punto de los vectores X y Y
  
   DDOT
NOTA: DDOT acepta valores de doble precisión



     */

/* 5) Rutina de daxpy  en c*/ 
/*Esta rutina hace uso de la función de la funcion daxpy, la cual recibe 2 vectores y un escalar, y da como resultado la multiplicación del escalar por uno de los vectores y este resultado sumado al otro vector. Para dos vectores x, y y un escalar a sería:
y=ax+y

Al igual que en el caso de la función ddot otro parámetro que recibe la función es el tamaño de los incrementos al ir recorriendo el vector, en este ejemplo se tomará que este incremento siempre es 1. 
*/
#include<stdio.h>
#include<stdlib.h>
#define INC 1
int daxpy_(int *n, double *sa, double *sx, int *incx, double *sy, int *incy);
int main (void){
int i;
int n=0;
double s=0;
double *x, *y;



printf("Introduce el número de elementos de cada vector:\n");
scanf("%d", &n);

x=malloc(sizeof(double)*n);
y=malloc(sizeof(double)*n);

printf("Introduce la constante por la se multiplicará el vector x:\n");
scanf("%lf", &s);
printf("Introduce el vector x:\n");

for ( i=0; i<n; i++){
printf("x[%d]:\n", i+1);
scanf("%lf", x+i);
}


printf("Introduce el vector y:\n");
for ( i=0; i<n; i++){
printf("y[%d]:\n", i+1);
scanf("%lf", y+i);
}


printf("\nConstante: %lf\n", s);
printf("\nVector x:");
for ( i=0; i<n; i++)
printf("x[%d]=%lf ", i+1, x[i]);

printf("\nVector y:\n");
for ( i=0; i<n; i++)
printf("y[%d]=%lf ", i+1, y[i]);
printf("\n");

int incx=INC;
int incy=INC;

daxpy_(&n, &s, x, &incx, y, &incy);
printf("\nResultado y=ax+y:\n");
for (int i=0; i<n;i++)
printf("y[%d]=%lf\n",i+1, y[i]);
printf("\n");


free(x);
free(y);

return 0;
}






