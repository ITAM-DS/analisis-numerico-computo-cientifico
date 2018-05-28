#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
// Define number of variables
static unsigned NUMBER_VARIABLES;
// Define number of equalities and inequalities
static unsigned NUMBER_EQUALITIES;
static unsigned NUMBER_INEQUALITIES;
// For reading constraint matrix from text files
#define MATRIX_EQ "Matrices/m_eq.txt"
#define MATRIX_INEQ "Matrices/m_ineq.txt"

// For reading constraint vector form txt files
#define VECTOR_EQ "Matrices/v_eq.txt"
#define VECTOR_INEQ "Matrices/v_ineq.txt"

typedef struct linear_eq_{

// var:= number of variables ; eq:= number of restrictions
unsigned var;
unsigned req;

// a:= pointer to matrix; b:= pointer to restriction vector
double **a;
double *b;

} linear_eq, *Plinear_eq;



typedef struct linear_ineq_{


  // var:= number of variables ; eq:= number of restrictions
  unsigned var;
  unsigned rineq;

  // a:= pointer to matrix; b:= pointer to restriction vector
  double **a;
  double *b;


} linear_ineq, *Plinear_ineq;

// Define skeleton for restrictions
static linear_eq EQUALITY;
static linear_ineq INEQUALITY;

// Define pointers to restrictions
static Plinear_eq P_EQUALITY;
static Plinear_ineq P_INEQUALITY;

void set_param(param, value)
  int param;
  int value;
{
  switch(param){
    case 1:
    NUMBER_VARIABLES = value;
    break;
    case 2:
    NUMBER_EQUALITIES = value;
    break;
    case 3:
    NUMBER_INEQUALITIES = value;
    break;
  }
}

int parse_arguments(int argc, char *argv[] ){
  int arg_index = 1;
  int value;

  if(argc == 7){
    while (arg_index < argc) {
      if (!strcmp(argv[arg_index], "-V")) {
        value = atoi(argv[arg_index+1]);
        set_param(1, value);
        arg_index += 2;
        continue;
      }

      if (!strcmp(argv[arg_index], "-E")) {
        value = atoi(argv[arg_index+1]);
        set_param(2, value);
        arg_index += 2;
        continue;
      }

      if (!strcmp(argv[arg_index], "-I")) {
        value = atoi(argv[arg_index+1]);
        set_param(3, value);
        arg_index += 2;
        continue;
      }
      printf("Error:  unrecognized flag %s\n", argv[arg_index]);
      exit(-1);
    }
  } else {
    printf("Format of imput is:\n");
    printf("%s -V a -E b -I c\n", argv[0]);
    printf("a: integer number of variables.\n");
    printf("b: integer number of equality restrictions.\n");
    printf("c: integer number of inequality restrictions.\n");
    exit(-1);
  }
  return(0);
}

void define_pointers() {

  P_EQUALITY = &EQUALITY;
  P_INEQUALITY = &INEQUALITY;
}

void define_parameters() {
  P_EQUALITY->var = NUMBER_VARIABLES;
  P_INEQUALITY->var = NUMBER_VARIABLES;

  P_EQUALITY->req = NUMBER_EQUALITIES;
  P_INEQUALITY->rineq = NUMBER_INEQUALITIES;

  FILE *m_eq = fopen(MATRIX_EQ, "r");
  FILE *m_ineq = fopen(MATRIX_INEQ, "r");
  FILE *v_eq = fopen(VECTOR_EQ, "r");
  FILE *v_ineq = fopen(VECTOR_INEQ, "r");

  P_EQUALITY->a = (double **)malloc(sizeof(double *) * NUMBER_EQUALITIES);
  P_INEQUALITY->a = (double **)malloc(sizeof(double *) * NUMBER_INEQUALITIES);

  P_EQUALITY->b = (double *)malloc(sizeof(double) * NUMBER_EQUALITIES);
  P_INEQUALITY->b = (double *)malloc(sizeof(double) * NUMBER_INEQUALITIES);

  for (int i = 0; i < NUMBER_EQUALITIES; i++) {

    P_EQUALITY->a[i] = (double *)malloc(sizeof(double) * NUMBER_VARIABLES);
    P_INEQUALITY->a[i] = (double *)malloc(sizeof(double) * NUMBER_VARIABLES);

    fscanf(v_eq, "%lf", &(P_EQUALITY->b[i]));
    fscanf(v_ineq, "%lf", &(P_INEQUALITY->b[i]));

    for (int j = 0; j < NUMBER_VARIABLES; j++) {
      fscanf(m_eq, "%lf", &(P_EQUALITY->a[i][j]));
      fscanf(m_ineq, "%lf", &(P_INEQUALITY->a[i][j]));
    }
  }
}

// void error_dsgeqrsv(int iter, int info)
// {
//   switch(iter) {
//
//     case -1  :
//     printf("-1 : the routine fell back to full precision for implementation- or machine-specific reasons \n");
//     break; /* optional */
//
//     case -2  :
//     printf("-2 : narrowing the precision induced an overflow, the routine fell back to full precision \n");
//     break; /* optional */
//
//     case -3  :
//     printf("-3 : failure of SGEQRF \n");
//     break; /* optional */
//
//     case -31  :
//     printf("-31: stop the iterative refinement after the 30th iteration \n");
//     break; /* optional */
//
//     default : /* Optional */
//     printf(" Iterative refinement has been successfully used. Returns the number of iterations: %d \n",iter);
//   }
//
//   if(info == 0)
//   {
//     printf("Succesful Exit");
//   }
//   else
//   {
//     printf(" The -%dth argument has ilegal value \n",info);
//   }
// }
//
// /*
// Matrix Inverse
// Computes X = A^{-1}
// Matrix dimensions:
//   A: m x m
// */
//
// double** invert(magma_int_t m, double A[m][m]){
//
//   magmaDouble_ptr dA=NULL, dX=NULL, dI=NULL;
//   magma_int_t iter ;
//   magma_int_t info ;
//   magma_queue_t queue=NULL;
//
//   iter=0;
//   info=1;
//
//   double I[m][m]; // Identity
//   double X[m][m]; // The inverse
//
//   magma_dmalloc( &dA, m*m );
//   magma_dmalloc( &dX, m*m );
//   magma_dmalloc( &dI, m*m );
//
//   if (dA == NULL || dX == NULL || dI == NULL)
//   {
//     printf("malloc failed\n" );
//   }
//   int i=0;
//   int j=0;
//   // Fills identity and inverse
//   for( i = 0; i<m; i++)
//   {
//     for(j = 0; j<m; j++)
//     {
//       X[i][j] = (double)0.0;
//       I[i][j] = (double)0.0;
//       if(j == i){ I[i][j] = 1.0}
//     }
//   }
//   magma_int_t dev = 0;
//   magma_queue_create( dev, &queue );
//
//   magma_setmatrix(m,m, sizeof(double),A,m,dA,m, queue);
//   magma_setmatrix(m,m, sizeof(double),I,m,dI,m, queue);
//   magma_setmatrix(m,m, sizeof(double),X,m,dX,m, queue);
//
//   //Debugging: Prints the matrix stored in the GPU
//
//   // printf(" A_GPU: \n");
//   // magma_dprint_gpu(m,m, dA,m, queue);
//   //
//   // printf(" I_GPU: \n");
//   // magma_dprint_gpu(m,m, dI,m, queue);
//   //
//   // printf(" X_GPU: \n");
//   // magma_dprint_gpu(m,m, dX,m, queue);
//
//   magma_dsgeqrsv_gpu( m, m, m, dA, m, dI, m, dX, m, &iter, &info );
//
//   if(info !=0){
//     error_dsgeqrsv(iter,info);
//   } // else{ printf("\n Praise the Sun !!!! \n");}
//   magma_queue_create( dev, &queue );
//   magma_getmatrix(m,m, sizeof(double),dX,m,X,m, queue);
//
//   //Print status of the solver operation
//
//   printf(" Sol_GPU: \n");
//   magma_dprint_gpu(m,m, dX,m, queue);
//
//   printf(" Sol_CPU: \n");
//   magma_dprint(m,m, X,m);
//
//   if(info !=0){
//     error_dsgeqrsv(iter,info);
//   } // else{printf("\n Praise the Sun !!!! \n");}
//   magma_free(dA);
//   magma_free(dX);
//   magma_free(dI);
//   free(I);
//   return(X);
// }
//
//
//
// /*
// Matrix multiplication
// Computes C = op(A) * op(B)
// Matrix dimensions:
//   op(A): n x k
//   op(B): k x m
//   C: n x m
// op(X) can be X or X'
// */
//
// void matrix_multiplication(
//   double **a, // Pointer to matrix A
//   double **b, // Pointer to matrix B
//   double **c, // Pointer to matrix C
//   int n,
//   int k,
//   int m,
//   int transA,
//   int transB
// ) {
//   int doublesize = sizeof(double);
//   cudaError_t     cudaStat; //  cudaMalloc  status
//   cublasStatus_t  stat;     //  CUBLAS  functions  status
//   cublasHandle_t  handle;   //  CUBLAS  context
//
//   double *A, *B, *C;
//   A = (double *)malloc(n*k*doublesize);
//   B = (double *)malloc(k*m*doublesize);
//   C = (double *)malloc(n*m*doublesize);
//   // Set matrix A to representation in CUBLAS
//   if(transA == 1){
//     for(int i = 0; i < n; i++){
//       for(int j = 0; j < k; j++){
//         A[(i*k)+ j] = a[j][i];
//       }
//     }
//   } else {
//     for(int i = 0; i < k; i++){
//       for(int j = 0; j < n; j++){
//         A[(i*n)+ j] = a[j][i];
//       }
//     }
//   }
//   // Set matrix B to representation in CUBLAS
//   if(transB == 1){
//     for(int i = 0; i < k; i++){
//       for(int j = 0; j < m; j++){
//         B[(i*m)+ j] = b[j][i];
//       }
//     }
//   } else {
//     for(int i = 0; i < m; i++){
//       for(int j = 0; j < k; j++){
//         B[(i*k)+ j] = b[j][i];
//       }
//     }
//   }
//   // Initialize C matrix to 0
//   for(int i = 0; i < n*m; i++ ){
//       C[i] = 0.0;
//   }
//   // Matrices on the device
//   double* d_A; // A on the device
//   double* d_B; // B on the device
//   double* d_C; // C on the device
//   cudaStat=cudaMalloc ((void **)&d_A , n*k*doublesize);
//   cudaStat=cudaMalloc ((void **)&d_B , k*m*doublesize);
//   cudaStat=cudaMalloc ((void **)&d_C , n*m*doublesize);
//
//   // CUBLAS part
//   stat = cublasCreate (&handle); // Initialize CUBLAS context
//   // Copy Matrices to device
//   if(transA == 1) {
//     stat = cublasSetMatrix(k, n, doublesize, A, k, d_A, k);
//   } else {
//     stat = cublasSetMatrix(n, k, doublesize, A, n, d_A, n);
//   }
//
//   if(transB == 1){
//     stat = cublasSetMatrix(m, k, doublesize, B, m, d_B, m);
//   } else {
//     stat = cublasSetMatrix(k, m, doublesize, B, k, d_B, k);
//   }
//   stat = cublasSetMatrix(n, m, doublesize, C, n, d_C, n);
//   // CUBLAS matrix-matrix multiplication
//   double alpha, beta;
//   alpha = 1.0;
//   beta = 0.0;
//   if(transA == 1){
//     if(transB == 1){
//       stat = cublasDgemm(handle, CUBLAS_OP_T, CUBLAS_OP_T, n, m, k, &alpha, d_A, k, d_B, m, &beta, d_C, n);
//     } else {
//       stat = cublasDgemm(handle, CUBLAS_OP_T, CUBLAS_OP_N, n, m, k, &alpha, d_A, k, d_B, k, &beta, d_C, n);
//     }
//   } else {
//     if(transB == 1){
//       stat = cublasDgemm(handle, CUBLAS_OP_N, CUBLAS_OP_T, n, m, k, &alpha, d_A, n, d_B, m, &beta, d_C, n);
//     } else {
//       stat = cublasDgemm(handle, CUBLAS_OP_N, CUBLAS_OP_N, n, m, k, &alpha, d_A, n, d_B, k, &beta, d_C, n);
//     }
//   }
//   // Transfer result to host
//   stat = cublasGetMatrix(n, m, doublesize, d_C, n, C, n);
//   for(int i = 0; i < n; i++ ){
//     for(int j = 0; j < m; j++){
//       c[i][j] = C[i + j*n];
//     }
//   }
//   // Remove matrices from device
//   free(A);
//   free(B);
//   free(C);
//   // Remove matrices from device
//   cudaFree(&d_A);
//   cudaFree(&d_B);
//   cudaFree(d_C);
//
// }
