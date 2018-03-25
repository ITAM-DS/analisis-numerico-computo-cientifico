#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <mkl.h>

//tomado de https://stackoverflow.com/questions/30270916/how-do-you-use-cblas-dgemm-to-do-a-vector-outer-product 

void PrintMatrix(double* pMatrix, const size_t nR, const size_t nC, const CBLAS_ORDER Order) {
    unsigned int i, j;
    if (Order == CblasRowMajor) {
        for (i = 0; i < nR; i++) {
            for (j = 0; j < nC; j++) {
                printf("%f \t ", pMatrix[i * nC + j]); // !!!
            }
            printf("\n"); // !!!
        }
    } else {
        for (i = 0; i < nR; i++) {
            for (j = 0; j < nC; j++) {
                printf("%f \t ", pMatrix[i + j* nR ]); // !!!
            }
            printf("\n"); // !!!
        }
    }
    printf("\n"); // !!!
}


int main(void)
{
    const int m = 20;
    const int n = 5;
    const int k = 1;

    double A[] = { 8, 4, 7, 3, 5, 1, 1, 3, 2, 1, 2, 3, 2, 0, 1, 1, 2, 3, 4, 1};
    double B[] = { -1, 2, -1, 1, 2 };

    double alpha = 1.0, beta = 0.0;

    double * C = (double*) malloc(m * n * sizeof(double));
    double * D = (double*) malloc(m * n * sizeof(double));

    for (int i = 0; i < m*n; i++) C[i] = 0.0;
    for (int i = 0; i < m*n; i++) D[i] = 0.0;

    int lda = 20;
    int ldc = 20;

    cblas_dger(CblasColMajor, m, n, alpha, A, 1, B, 1, C, ldc);

    PrintMatrix(C, m, n, CblasRowMajor);

    free(C);

    return 0;
}
