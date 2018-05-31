#include<stdio.h>

#define N 10
void daxpy_(int* n, double* alpha,
            double* x, int *incx,
            double* y, int *incy);

int main(){
    static double x[N], y[N];
    double a = 1;
    int i;
    for (i = 0; i < N; i++){
        x[i] = i+1;
        y[i] = i+1;
    }
    int n = N;
    int incx = 1;
    int incy = 1;
    daxpy_(&n, &a, x, &incx, y, &incy);
    printf("Con daxpy se calcula y=a*x+y:\n");
    for (i = 0;i < 10;i++){
        printf ("%f\n",y[i]);
    }
}
