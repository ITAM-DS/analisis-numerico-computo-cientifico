#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
// PROPIAMENTE SE CALCULA LA FACTORIZACIÓN CHOLESKY
double *cholesky(double *A, int n) {
    double *L = (double*)calloc(n * n, sizeof(double));
    if (L == NULL)
        exit(EXIT_FAILURE);
 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < (i+1); j++) {
            double s = 0;
            for (int k = 0; k < j; k++)
                s += L[i * n + k] * L[j * n + k];
            L[i * n + j] = (i == j) ?
                           sqrt(A[i * n + i] - s) :
                           (1.0 / L[j * n + j] * (A[i * n + j] - s));
        }
 
    return L;
}
 
 // SE IMPRIME LA MATRIZ
void show_matrix(double *A, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%2.5f ", A[i * n + j]);
        printf("\n");
    }
}

// SE OBTIENE LA DIMENSIÓN DE LA MATRIZ A FACTORIZAR
int get_dim(){
    int n=0;
    char c;

    while((c = getchar()) != EOF) {
        if(c == '\n') {
            n++;
        }
    }
    return(sqrt(n));
}

// SE PUEBLA LA MATRIZ
double *arr_mat(int n, double *arr) {

    FILE * matriz;
    double num;
    int i;

    matriz = fopen("matrizSPD.txt", "r");
    
    for (i=0; i<n; i++) {
        fscanf(matriz, "%lf", &num);
        arr[i]=num;
    }

    return arr;
}
 
int main() {
    int dim,n,i;
    dim = get_dim();
    n=pow(dim,2);
    double *matap = malloc(sizeof(double)*n);
    double matriz[n];

    matap = arr_mat(n, matap);

    for(i=0;i<n;i++){
        matriz[i]=*matap;
//        printf("%f\n", matriz[i]);
        matap++;
    }

    double *fact = cholesky(matriz, dim);
    show_matrix(fact, dim);
    printf("\n");
    free(fact);

    return 0;
}
