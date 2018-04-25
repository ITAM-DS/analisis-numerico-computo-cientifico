#include<stdio.h>

void daxpy_(int* n, double* DA,
            double* DX, int *incx,
            double* DY, int *incy);

int main(){
    int N=5;
    double DX[5]={2,3,4,6,1};
    double DY[5]={1,1,1,1,1};
    int i;
 
    int INCX;
    int INCY;
    double DA;
    DA = 5;
    INCX = 1;
    INCY = 1;
    
    

    daxpy_(&N, &DA, DX, &INCX, DY, &INCY);
    for (i = 0;i < 10;i++){
        printf ("%f  ",DY[i]);
    }
}
