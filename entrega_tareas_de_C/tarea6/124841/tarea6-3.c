/*
 dger performs the rank 1 operation  A  :=  alpha*x*y'  +  A,
     where alpha is a scalar, x is an m element vector, y is an n
     element vector and A is an m by n matrix.
*/

#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define INC 1
#define A_matriz "A1.txt" //de tamaño MxN
void dger_(int *m, int *n, double *alpha, double *x, int *incx, double *y, int *incy, double *a, int *lda);
int main (int argc, char *argv[]){
int i;
int m=atoi(argv[1]), n=atoi(argv[2]); 
int lda=m;
arreglo_2d_T a;
double *x, *y, alpha=0;

printf("Introduce el parámetro alpha\n");
scanf("%lf", &alpha);

int incx=INC;
int incy=INC;

a=malloc(sizeof(*a));
renglones(a)=m;
columnas(a)=n;
entradas(a)=malloc(renglones(a)*columnas(a)*sizeof(double));
inicializa_matriz(a, A_matriz);


x=malloc(sizeof(double)*m);
y=malloc(sizeof(double)*n);


printf("Introduce el vector x:\n");
for ( i=0; i<m; i++){
printf("x[%d]:\n", i+1);
scanf("%lf", x+i);
}


printf("Introduce el vector y:\n");
for ( i=0; i<n; i++){
printf("y[%d]:\n", i+1);
scanf("%lf", y+i);
}



printf("\nParámetro alpha: %lf\n", alpha);
printf("\nVector x:\n");
for ( i=0; i<n; i++)
printf("x[%d]=%lf ", i+1, x[i]);
printf("\n");

printf("\nVector y:\n");
for ( i=0; i<n; i++)
printf("y[%d]=%lf ", i+1, y[i]);
printf("\n");


printf("matriz A:\n");
	imprime_matriz(a);
	printf("------------\n");
/*nota importante encontrada en: http://matlab.izmiran.ru/help/techdoc/matlab_external/ch04cr17.html a las rutinas de fortran todos los argumentos se deben pasar por referencia*/
dger_(&m, &n, &alpha, x, &incx, y, &incy, entradas(a), &lda);

printf("\nResultado A  :=  alpha*x*y'  +  A\n");
imprime_matriz(a);
	printf("------------\n");


free(x);
free(y);
free(entradas(a));
	free(a);
return 0;
}

