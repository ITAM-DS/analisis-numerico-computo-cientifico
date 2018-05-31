#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include "definiciones.h"


#define A_matriz "matrizSPD.txt" 
#define L_matriz "matrizL.txt"


arreglo_2d_T cholesky(double *A,int n);

int main(int argc, char *argv[]){

arreglo_2d_T A;
arreglo_2d_T L;

int n=atoi(argv[1]); 

A=malloc(sizeof(*A));
L=malloc(sizeof(*L));

renglones(A)=n;
columnas(A)=n;
renglones(L)=n;
columnas(L) =n;

entradas(A)=malloc(renglones(A)*columnas(A)*sizeof(double));
entradas(L)=malloc(renglones(L)*columnas(L)*sizeof(double));
inicializa_matriz(A,A_matriz);

/*Matrix A and Matrix L */

printf("A =\n");

imprime_matriz(A);

L = cholesky(entradas(A),n);

printf("L =\n");
imprime_matriz(L);
guardar_matriz(entradas(L),n,L_matriz);
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
        thr = n-(j+1);
        #pragma omp parallel for num_threads(thr) private(s,i,l)
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

