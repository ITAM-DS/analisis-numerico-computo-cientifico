#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

void cholesky(float **A,float **L,int n);
void printm(float **M,int n);


int main(int argc, char **argv){

/*[Test] Values */
float tm[25] = {2,1,1,3,2,1,2,2,1,1,1,2,9,1,5,3,1,1,7,1,2,1,5,1,8};
int n =5;

/*Matrix A and Matrix L */
float  *mA = (float *)malloc(n*n*sizeof(float));
float  *mL = (float *)calloc(n*n,sizeof(float));

float **A;
float **L;

/* Assign values to the array mA*/
int i,j, count = 0;
for (i = 0;i<n;i++)
        for (j = 0;j < n ;j++)
                *(mA + i*n + j) = tm[count++];
/* Print the matrix values */

A = &mA;
L = &mL;

printf("A =\n");
printm(A,n);
cholesky(A,L,n);

printf("L =\n");
printm(L,n);
free(mA);
free(mL);
return 0;
}



void cholesky(float **A,float **L,int n){

int k,j,i,l;
float s=0;
int thr =1;

for(j=0;j<n;j++){
        s=0;
        for(k=0;k<j;k++)
                s+= *(*L+j*n+k)* *(*L+j*n+k);
        /*printf("A:%f\n s: %f\n",*(*A+j*n+j),s);*/
        *(*L+j*n+j) = sqrt( *(*A+j*n+j) -s);
        thr = n-(j+1);
        #pragma omp parallel for num_threads(thr) private(i,l)
        for (i=j+1;i<n;i++){
                s =0;
                printf("Thread: %d de %d para calcular L(%d,%d)\n",omp_get_thread_num()+1,omp_get_num_threads(),i,j);
                for (l=0;l<j;l++){
                        s+= *(*L+i*n+l) * *(*L+j*n+l);
                }
                *(*L+i*n+j) = (1.0/ *(*L+j*n+j) )*( *(*A+i*n+j) - s);
        }
}

}

/*Print matrix values in format | | */
void printm(float **M,int n){
int i,j;
for (i=0; i<n;i++){
        printf("| ");
        for (j=0;j<n;j++)
                printf("%f\t",*(*M+i*n+j));
        printf("|\n");}

}
