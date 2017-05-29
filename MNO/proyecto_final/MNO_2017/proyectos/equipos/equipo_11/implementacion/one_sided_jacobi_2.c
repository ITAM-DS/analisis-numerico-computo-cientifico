#include<stdio.h>
#include<stdlib.h>
#include<math.h>


void imprime_matriz(double **matriz);
double **leer_matriz(int M);
double **leer_ind(int M);
double **leer_round_robin(int M);
double multiplica_vector(int col1, int col2, double **matriz);
double jacobi(int i, int j, double **matrizA, double **matrizI);


int main(void){
    int ncol = 10, i , j;
    int col1, col2;
    double **matrizA = leer_matriz(ncol);
    double paro;
    printf("Imprime Matriz A\n");
    //imprime_matriz(matrizA);
    
    double **matrizI = leer_ind(ncol);
    printf("Imprime Matriz I\n");
    //imprime_matriz(matrizI);
    
    double **matrizR = leer_round_robin(ncol);
    printf("Imprime Matriz R\n");
    
    /*Round Robin*/
    for(i = 0; i < 9; i++){
        for(j = 0; j < 10; j = j+2){
            col1 = matrizR[i][j];
            //printf("col1 %d\n", col1);
            col2 = matrizR[i][j+1];
            //printf("col2 %d\n", col2);
            paro = jacobi(col1, col2, matrizA, matrizI);

        }
    }
    //imprime_matriz(matrizI);
    imprime_matriz(matrizA);
    
    //imprime_matriz(matrizR);
    
    //    printf("Imprime Matriz I_2\n");
    //    imprime_matriz(matrizI);
    
    
    return 0;
}


double jacobi(int i, int j, double **matriz1, double **matriz2){
    double a, b, c, epsilon, t, sgn, cs, sn, temp, paro, num,den,eps_maq;
    int l;
    
    a = multiplica_vector(i, i, matriz1);
    b = multiplica_vector(j, j, matriz1);
    c = multiplica_vector(i, j, matriz1);
    
    printf("a %f\n: ", a);
    printf("b %f\n: ", b);
    printf("c %f\n: ", c);
    
    epsilon = (b-a)/(2*c);
    sgn = (epsilon)/fabs(epsilon);
    t = sgn/(fabs(epsilon) + sqrt(1+ pow(epsilon,2) ) );
    cs = 1/sqrt(1 + pow(epsilon,2));
    sn = cs*t;
    
    paro = c/(pow(a,.5)*pow(b,.5));
    num = a - b;
    den = 2*c;
    eps_maq = pow(10,-4);
    
    if (fabs(den) > eps_maq*fabs(num)) {
        
        for(l= 0; l < 10; l++){
            matriz1[l][i] = cs*matriz1[l][i] - matriz1[l][j]*sn;
            matriz1[l][j] = cs*matriz1[l][i] - matriz1[l][j]*sn;
        }
    
        for(l= 0; l < 10; l++){
            matriz2[l][i] = cs*matriz2[l][i] - matriz2[l][j]*sn;
            matriz2[l][j] = cs*matriz2[l][i] - matriz2[l][j]*sn;
        }
    
    }
    
    return paro;
    
}


double multiplica_vector(int col1, int col2, double **matriz){
    double multacum = 0;
    int i;
    
    for(i = 0; i < 10; i++){
        multacum = multacum + matriz[i][col1] * matriz[i][col2];
        //printf("Multip %f\n", multacum);
    }
    
    return multacum;
}

void imprime_matriz(double **matriz){
    int i , j;
    
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++) {
            printf("mat[%d,%d] = %lf\n", i, j, matriz[i][j]);
        }
    }
}




double **leer_ind(int M){
    int i, j;
    
    printf("2. Leer Indicadora\n");
    
    /*archivo*/
    FILE *file;
    file = fopen("ind.txt", "r");
    
    /*number of rows*/
    double ** mat = malloc(M * sizeof(double*));
    
    /*size per row*/
    for(i = 0; i < M; ++i){
        mat[i] = malloc(M * sizeof(double));
    }
    
    /*leer*/
    for(i = 0; i < M; i++){
        for(j = 0; j < M; j++) {
            //Use lf format specifier, %c is for character
            if (!fscanf(file, "%lf", &mat[i][j])) {
                break;
            }
            //Use lf format specifier, \n is for new line
            //printf("mat[%d,%d] = %lf\n", i, j, mat[i][j]);
        }
    }
    
    fclose(file);
    return mat;
}


double **leer_matriz(int M){
    int i, j;
    
    printf("2. Leer Matriz\n");
    
    /*archivo*/
    FILE *file;
    file = fopen("cor.txt", "r");
    
    /*number of rows*/
    double ** mat = malloc(M * sizeof(double*));
    
    /*size per row*/
    for(i = 0; i < M; ++i){
        mat[i] = malloc(M * sizeof(double));
    }
    
    /*leer*/
    for(i = 0; i < M; i++){
        for(j = 0; j < M; j++) {
            //Use lf format specifier, %c is for character
            if (!fscanf(file, "%lf", &mat[i][j])) {
                break;
            }
            //Use lf format specifier, \n is for new line
            //printf("mat[%d,%d] = %lf\n", i, j, mat[i][j]);
        }
    }
    
    fclose(file);
    return mat;
}

double **leer_round_robin(int R){
    int i, j;
    
    printf("1. Leer datos\n");
    
    /*archivo*/
    FILE *file;
    file = fopen("mat_rr.txt", "r");
    
    /*number of rows*/
    double ** mat_r_r = malloc(R * sizeof(double*));
    
    /*size per row*/
    for(i = 0; i < R; ++i){
        mat_r_r[i] = malloc(R * sizeof(double));
    }
    
    /*leer*/
    for(i = 0; i < R; i++){
        for(j = 0; j < R; j++) {
            //Use lf format specifier, %c is for character
            if (!fscanf(file, "%lf", &mat_r_r[i][j])) {
                break;
            }
            //Use lf format specifier, \n is for new line
            //printf("mat[%d,%d] = %lf\n", i, j, mat[i][j]);
        }
    }
    
    fclose(file);
    return mat_r_r;
}


