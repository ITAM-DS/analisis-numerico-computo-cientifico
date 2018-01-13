#include <stdio.h>
#include <math.h>Y

int main()
{
    double a[6][2] = {{0,2},{2,-1},{2,-1},{0,1.5},{2,-1},{2,-1}};
    int m=6;
    int n=2;
    int info = 0;
    int lda = m;
    int lwork = n;
    double *work;
    double *tau;
    dgeqrf_(&m, &n, a, &lda, tau, work, &lwork, &info);

}