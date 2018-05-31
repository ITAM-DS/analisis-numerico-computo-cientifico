#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include "definiciones.h"
#include <time.h>

#define A_matriz "matrizSPD.txt"
#define L_matriz "matrizL.txt"
#define Ls_matriz "matrizLs.txt"

arreglo_2d_T cholesky(double *A,int n);
arreglo_2d_T cholesky_seq(double *A,int n);

int main(int argc, char *argv[]){

arreglo_2d_T A;
arreglo_2d_T L;
arreglo_2d_T Ls;
int n=atoi(argv[1]);
double time_p=0;
double time_s=0;

A=malloc(sizeof(*A));
L=malloc(sizeof(*L));
Ls=malloc(sizeof(*Ls));



renglones(A)=n;
columnas(A)=n;
renglones(Ls)=n;
columnas(Ls)=n;
renglones(L)=n;
columnas(L) =n;
renglones(Ls)=n;
columnas(Ls)=n;

entradas(A)=malloc(renglones(A)*columnas(A)*sizeof(double));
entradas(L)=malloc(renglones(L)*columnas(L)*sizeof(double));
entradas(Ls)=malloc(renglones(Ls)*columnas(Ls)*sizeof(double));
inicializa_matriz(A,A_matriz);

/*Matrix A and Matrix L */

printf("A =\n");

imprime_matriz(A);
clock_t start=clock();
L = cholesky(entradas(A),n);
clock_t end=clock();

time_p=(double)(end-start);

printf("L =\n");
/*
imprime_matriz(L);
*/
clock_t start_s=clock();
Ls = cholesky_seq(entradas(A),n);
clock_t end_s = clock();

time_s=(double)(end_s-start_s);

printf("Ls=\n");
/*
imprime_matriz(Ls);
*/

guardar_matriz(entradas(L),n,L_matriz);
guardar_matriz(entradas(Ls),n,Ls_matriz);
printf("Matriz de %d x %d :\n Tiempo Paralelo: %f \n Tiempo Secuencial: %f\n",n,n,time_p,time_s);

free(entradas(A));
free(A);
free(entradas(L));
free(L);
free(entradas(Ls));
free(Ls);
return 0;
}



arreglo_2d_T cholesky(double *A,int n){

int k,j,i,l;
double s=0;
int thr =1;
arreglo_2d_T L;
L=malloc(sizeof(*L));
columnas(L) =n;
renglones(L)=n;
entradas(L)=calloc(renglones(L)*columnas(L),sizeof(double));


for(j=0;j<n;j++){
        s=0;
        for(k=0;k<j;k++){

                s+= entrada(L,j,k)*entrada(L,j,k);
                /*printf("(L[%d,%d])L[%d,%d]:%f\n s: %f\n",j,j,j,k,entrada(L,j,k),s);*/
        }

        entrada(L,j,j) = sqrt(A[j * n + j]-s);
        /*printf("(A[%d,%d]):%f==========L[%d,%d]:%f=========\n",j,j,A[j * n + j],j,j,entrada(L,j,j));*/
        /*thr = n-(j+1);*/
        #pragma omp parallel for private(s,i,l)
        for (i=j+1;i<n;i++){
                double s =0;

/*printf("Thread: %d de %d para calcular L(%d,%d)\n",omp_get_thread_num()+1,omp_get_num_threads(),i,j);*/

                for (l=0;l<j;l++){

                        s+=entrada(L,i,l) * entrada(L,j,l);

                        /*printf("(L[%d,%d]:)(il)L[%d,%d]:%f\n s: %f\n",i,j,i,l,entrada(L,i,l),s);
                        printf("(L[%d,%d]:)(jl)L[%d,%d]:%f\n s: %f\n",i,j,j,l,entrada(L,j,l),s);*/
                }
                entrada(L,i,j) = (1.0 / entrada(L,j,j) ) * (A[i * n + j]-s);
                /*printf("==========L[%d,%d]:%f=========L[%d,%d]:%f============================\n",j,j,entrada(L,j,j),i,j,entrada(L,i,j));*/
        }
}

return L;
}


arreglo_2d_T cholesky_seq(double *A, int n) {

        arreglo_2d_T L;
        L=malloc(sizeof(*L));
        columnas(L)=n;
        renglones(L)=n;
        entradas(L)=calloc(renglones(L)*columnas(L),sizeof(double));


    if (L == NULL)
        exit(EXIT_FAILURE);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < (i+1); j++) {
            double s = 0;
            for (int k = 0; k < j; k++)
                s += entrada(L,i,k)*entrada(L,j,k);
            entrada(L,i,j) = (i == j) ?
                           sqrt(A[i * n + i] - s) :
                           (1.0 / entrada(L,j,j) * (A[i * n + j] - s));
        }

    return L;
}

