#include <stdio.h>
#include <math.h>

int main()
{
    double a[4] = {0,2,2,-1};
    int m=2;
    int n=2;
    int info = 0;
    int lda = m;
    int lwork = n;
    double work[2];
    double tau[2];
    dgeqrfp_(&m, &n, a, &lda, tau, work, &lwork, &info);
}