
// gcc one_side_jacobi.c -o one_side_jacobi.out -lm


#include<stdio.h>
#include<stdlib.h>
#include<math.h>


/* Definiciones de funciones necesarias */
void imprime_matriz(double **matriz);
void escribe_matriz(double **matriz);
double **leer_matriz(int M);
double **leer_ind(int M);
double **leer_round_robin(int M);
double multiplica_vector(int col1, int col2, double **matriz);
double jacobi(int i, int j, double **matrizA, double **matrizI);

/* Función principal*/
/* En esta función se corre realiza la distribución de índices*/
int main(void){
    int ncol = 10, i , j, cont;
    int col1, col2, colmin, colmax;
    double paro;
    
    
    /* Lectura de matriz de correlaciones A*/
    double **matrizA = leer_matriz(ncol);
    //printf("Imprime Matriz A\n");
    //imprime_matriz(matrizA);
    
    /* Lectura de matriz diagonal I*/
    double **matrizI = leer_ind(ncol);
    //printf("Imprime Matriz I\n");
    //imprime_matriz(matrizI);
    
    /* Lectura de matriz con secuencia de parejas Round Robin*/
    double **matrizR = leer_round_robin(ncol);
    //printf("Imprime Matriz R\n");
    
    /*Cíclico Round Robin*/
    while (paro < pow(10,-8)) {
      
        /* Inicio de Sweep */
        for(i = 0; i < 9; i++){
            for(j = 0; j < 10; j = j+2){
              
                /* Orden de pareja de columnas */
                col1 = matrizR[i][j];
                //printf("col1 %d\n", col1);
                col2 = matrizR[i][j+1];
                //printf("col2 %d\n", col2);
              
                /* Condición i < j, renombramiento de columnas */
                if(col1 < col2){
                    colmin = col1;
                    colmax = col2;
                }
                else{
                    colmin = col2;
                    colmax = col1;
                }
                
                
                /* Metodo Jacobi */
                /* Actualizción de Matriz y evaluación de condición de paro */
                paro = jacobi(colmin, colmax, matrizA, matrizI);
                //escribe_matriz(matrizA);
                
            }
        } 
        /* Fin de Sweep */

    } /* Fin de Algoritmo */
        
    //imprime_matriz(matrizI);
    //escribe_matriz(matrizA);
    //imprime_matriz(matrizR);
    
    //    printf("Imprime Matriz I_2\n");
    //    imprime_matriz(matrizI);
    
    
    return 0;
}


/* Algoritmo One-Side Jacobi */
double jacobi(int i, int j, double **matriz1, double **matriz2){
    double a, b, c, epsilon, t, sgn, cs, sn, temp, paro, num,den;
    double eps_maq = 1.0;
    int l, cont;
    
    /* Normas de las columnas */
    a = multiplica_vector(i, i, matriz1);
    b = multiplica_vector(j, j, matriz1);
    c = multiplica_vector(i, j, matriz1);
    
   // printf("a %f\n: ", a);
   // printf("b %f\n: ", b);
   // printf("c %f\n: ", c);
    
    /* Valores para la rotación */
    epsilon = (b-a)/(2*c);
    sgn = (epsilon)/fabs(epsilon);
    t = sgn/(fabs(epsilon) + sqrt(1+ pow(epsilon,2) ) );
    cs = 1/sqrt(1 + pow(t,2));
    sn = cs*t;
    
    /* Valores para la condición de columnas ortogonales */
    paro = c/(sqrt(a) * sqrt(b));
    num = a - b;
    den = 2*c;
    
   // while(1.0+eps_maq != 1.0){
   //     eps_maq = eps_maq/2.0;
   // }
    
    /* Condición de columnas ortogonales */  
    if (fabs(den) > pow(10,-16)*fabs(num)) {
        
        /* Actualización matriz A */  
        for(l= 0; l < 10; l++){
            matriz1[l][i] = cs*matriz1[l][i] - matriz1[l][j]*sn;
            matriz1[l][j] = sn*matriz1[l][i] + matriz1[l][j]*cs;
        }
        
        /* Actualización matriz I */  
        for(l= 0; l < 10; l++){
            matriz2[l][i] = cs*matriz2[l][i] - matriz2[l][j]*sn;
            matriz2[l][j] = sn*matriz2[l][i] + matriz2[l][j]*cs;
        }
    
    }
    else{
        /* Conteo de columnas ortogonales */  
        cont = cont + 1;
    }
    
    /* Regresa evaluación de paro */  
    //printf("contador: %d\n", cont);
    return paro;
    
}


/* Función que imprime una matriz */  
/* Únicamente de prueba */  
void escribe_matriz(double **matriz){
    int i , j;
    
    printf("\n");
    
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++) {
            printf("%lf ",  matriz[i][j]);
        }
        printf("\n");
    }
}

/* Función para obtener producto punto de dos vectores */  
double multiplica_vector(int col1, int col2, double **matriz){
    double multacum = 0;
    int i;
    
    for(i = 0; i < 10; i++){
        multacum = multacum + matriz[i][col1] * matriz[i][col2];
        //printf("Multip %f\n", multacum);
    }
    
    return multacum;
}

/* Imprimir matriz en formato para txt */  
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
    
    //printf("2. Leer Indicadora\n");
    
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
    
   // printf("2. Leer Matriz\n");
    
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
    
    //printf("1. Leer datos\n");
    
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


