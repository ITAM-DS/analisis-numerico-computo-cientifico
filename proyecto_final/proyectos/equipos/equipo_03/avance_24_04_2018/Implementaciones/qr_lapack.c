#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <string.h>

void dgeqrf_(int *rows, int *cols, double *matA, int *LDA, double *TAU, double *WORK, int *LWORK, int *INFO);
void dorgqr_(int *rows, int *cols, int *k ,double *matA, int *LDA, double *TAU, double *WORK, int *LWORK, int *INFO);
int main()
{
    int i;
    // Definimos la dimensión
    int rows=3;
    int cols=3;
    double *matA=malloc(sizeof(double)*rows*cols);

    // Definimos la matriz, llenando por columna
    matA[0]=2;
    matA[1]=2;
    matA[2]=1;
    matA[3]=-2;
    matA[4]=1;
    matA[5]=2;
    matA[6]=18;
    matA[7]=0;
    matA[8]=0;

    //Imprimimos matriz
    printf("Matriz A:");
    printf("\n");
    for(i=0; i<rows*cols; i++)
    {
        printf("%f ",matA[i]);
    }
    printf("\n");

    // Definimos valores de los parémetros de la función
    int LDA=rows;
    int INFO;
    int rowcolmin=rows;
    if(rowcolmin>cols)
    {
        rowcolmin=cols;
    }

    double *TAU=malloc(sizeof(double)*rowcolmin);
    int LWORK=cols;   
    double *WORK=malloc(sizeof(double)*LWORK);

    // Corremos la factorización QR, esta función solo nos regresa la R
    dgeqrf_(&rows, &cols, matA, &LDA, TAU, WORK, &LWORK, &INFO);

    // Imprimimos R
    printf("Matriz R:");
    printf("\n");
    for(i=0; i<rows*cols; i++)
    {
        printf("%f ",matA[i]);
    }
    printf("\n");

    // Corremos función para recuperar la matriz Q
    int k=cols;
    dorgqr_(&rows, &cols, &k,matA, &LDA, TAU, WORK, &LWORK, &INFO);

    // Imprimimos Q
    printf("Matriz Q:");
    printf("\n");
    for(i=0; i<rows*cols; i++)
    {
        printf("%f ",matA[i]);
    }
    printf("\n");


    free(WORK);
    free(TAU);
    free(matA);
    return 0;
}
