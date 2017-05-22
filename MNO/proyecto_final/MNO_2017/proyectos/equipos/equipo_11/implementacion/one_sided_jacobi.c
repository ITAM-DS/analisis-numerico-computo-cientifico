#include<stdio.h>
#include<stdlib.h>
#include<math.h>


#define NUM_REN_MAT1 3
#define NUM_COL_MAT1 3
#define NUM_REN_MAT2 3
#define NUM_COL_MAT2 3 

void imprime_matrices(void);
void imprime_matrices(void);
void imprime_matriz_resultado(void);
void aloja_espacio_e_incializa_matrices(void);
void libera_espacio(void);


//definiciones de variables que serán externas solo apuntadores
static int i=0,j=0, k=0;
double (*matriz1)[NUM_COL_MAT1];
double (*matriz2)[NUM_COL_MAT2];
double (*matriz_resultado)[NUM_COL_MAT2];


void aloja_espacio_e_incializa_matrices(void){
  // matriz 1
  matriz1 = malloc(  NUM_REN_MAT1 * NUM_COL_MAT1 * sizeof(double) );
  // columna 1
  *( *( matriz1 + 0 ) + 0 ) = 1;
  *( *( matriz1 + 1 ) + 0 ) = .15;
  *( *( matriz1 + 2 ) + 0 ) = .59;
  // columna 2  
  *( *( matriz1 + 0 ) + 1 ) = .15;
  *( *( matriz1 + 1 ) + 1 ) = 1;
  *( *( matriz1 + 2 ) + 1 ) = .62;
  // columna 3
  *( *( matriz1 + 0 ) + 2 ) = .59;
  *( *( matriz1 + 1 ) + 2 ) = .62;
  *( *( matriz1 + 2 ) + 2 ) = 1;
  
  
  
  // matriz 2
  matriz2 = malloc(  NUM_REN_MAT2 * NUM_COL_MAT2 * sizeof(double) );
  // columna 1
  *( *( matriz2 + 0 ) + 0 ) = 1;
  *( *( matriz2 + 1 ) + 0 ) = 0;
  *( *( matriz2 + 2 ) + 0 ) = 0;
  // columna 2  
  *( *( matriz2 + 0 ) + 1 ) = 0;
  *( *( matriz2 + 1 ) + 1 ) = 1;
  *( *( matriz2 + 2 ) + 1 ) = 0;
  // columna 3
  *( *( matriz2 + 0 ) + 2 ) = 0;
  *( *( matriz2 + 1 ) + 2 ) = 0;
  *( *( matriz2 + 2 ) + 2 ) = 1;
  
  
  // matriz resultado (reng_mat1 x col_mat2)
  matriz_resultado = malloc(  NUM_REN_MAT1 * NUM_COL_MAT2 * sizeof(double) );
}

void libera_espacio(void){
  
  // matriz 1
  free(matriz1);
  // matriz 2
  free(matriz2);
  // matriz resultado
  free(matriz_resultado);
  
}



void imprime_matrices(void){
  
  printf("Matriz1\n");
  for(i = 0; i < NUM_REN_MAT1; i++ ){ //el nombre: NUM_REN_MAT1 está definido en "definiciones.h"
    for(j = 0; j < NUM_COL_MAT1; j++){
      if(j < NUM_COL_MAT1 - 1)
        printf("matriz1[%d][%d]=%4.2f\t", i, j, matriz1[i][j] );
      else
        printf("matriz1[%d][%d]=%4.2f\n", i, j, matriz1[i][j] );
    }
  }
  printf("\n");
  
  printf("Matriz2\n");
  for(i = 0; i < NUM_REN_MAT2; i++){
    for(j=0; j < NUM_COL_MAT2; j++){
      if(j < NUM_COL_MAT2 - 1)
        printf("matriz2[%d][%d]=%4.2f\t", i, j, matriz2[i][j] );
      else
        printf("matriz2[%d][%d]=%4.2f\n", i, j, matriz2[i][j] );
    }
  }
  printf("\n");
}


void imprime_matriz_resultado(void){
  
  printf("Matriz resultado\n");    
  for(i = 0; i < NUM_REN_MAT1; i++){
    for(j=0; j < NUM_COL_MAT2; j++){
      if(j < NUM_COL_MAT2 - 1)
        printf("matriz_res[%d][%d]=%4.2f\t", i, j, matriz_resultado[i][j] );
      else
        printf("matriz_res[%d][%d]=%4.2f\n", i, j, matriz_resultado[i][j] );
    }
  }
  
  printf("\n");
  
}




void jacobi(int i, int j){
  double a, b, c, epsilon, t, sgn, cs, sn, temp;
  int l;
  
  a = matriz_resultado[i][i];
  b = matriz_resultado[j][j];
  c = matriz_resultado[i][j];
  epsilon = (b-a)/(2*c);
  sgn = (epsilon)/fabs(epsilon);
  t = sgn/(fabs(epsilon) + sqrt(1+ pow(epsilon,2) ) );
  cs = 1/sqrt(1 + pow(epsilon,2));
  sn = cs*t;
  
  for(l= 0; l < NUM_REN_MAT1; l++){
    matriz1[l][i] = cs*matriz1[l][i] - matriz1[l][j]*sn;
    matriz1[l][j] = cs*matriz1[l][i] - matriz1[l][j]*sn;
  }
  for(l= 0; l < NUM_REN_MAT1; l++){
    matriz2[l][i] = cs*matriz2[l][i] - matriz2[l][j]*sn;
    matriz2[l][j] = cs*matriz2[l][i] - matriz2[l][j]*sn;
  }

}


extern void dgemm_(char *transaA, char *transaB,int *m,int *n,int *k,double *alpha,double *A,int *lda,double *B,int *ldb,double *beta,double *C,int *ldc);
extern double (*matriz1)[], (*matriz2)[], (*matriz_resultado)[];



int main(void){
  char TRANSA, TRANSB;
  int M = NUM_REN_MAT1;
  int K = NUM_COL_MAT1;
  int N = NUM_COL_MAT2;
  double ALPHA, BETA;
  
  TRANSA = 'N';
  TRANSB = 'N';
  ALPHA = 1.0;
  BETA = 0.0;
  
  aloja_espacio_e_incializa_matrices();
  imprime_matrices();
  dgemm_(&TRANSA, &TRANSB, &N, &M, &K, &ALPHA, *matriz1, &N, *matriz1, &K, &BETA, *matriz_resultado, &N);
  imprime_matriz_resultado();
  jacobi(0,1);
  jacobi(1,2);
  imprime_matrices();
  libera_espacio();
  return 0;
}

