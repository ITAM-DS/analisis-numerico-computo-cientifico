/* Equipo 9
 *  Factorización QR utilizando CUDA, cuSolver
 *  Para compilar se debe ejecutar:
 *  make 
 *  Para ejecutar el programa, se debe realizar:
 *  make ejecutarlo 
 *  Si se quiere compilar sin el archivo make
 *  nvcc  -I/usr/local/cuda/include Solver.cu -lcublas -lcusolver
 *  Las matrices se alamacen en orden column major
 *  TODO: 
 *  Revisando la compilacion usando cuda + c
 *  https://devblogs.nvidia.com/separate-compilation-linking-cuda-device-code/
 */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <cuda_runtime.h>
#include <cublas_v2.h>
#include <cusolverDn.h>
#include "definiciones.h"

void imprimeMatriz(int m, int n, const double*A, int lda, const char* name);
double randomRange(double m,double n);

int main(int argc, char*argv[])
{
    cusolverDnHandle_t cusolverH = NULL;
    cublasHandle_t cublasH = NULL;
    cublasStatus_t cublas_status = CUBLAS_STATUS_SUCCESS;
    cusolverStatus_t cusolver_status = CUSOLVER_STATUS_SUCCESS;    
    cudaError_t cudaStat1 = cudaSuccess;
    cudaError_t cudaStat2 = cudaSuccess;
    cudaError_t cudaStat3 = cudaSuccess;
    cudaError_t cudaStat4 = cudaSuccess;
    int m = 3;
    int lda = m;
    int ldb = m;
    int nrhs = 2; 
    arreglo_2d_T AA, BB;


    srand(175840);


    m = atoi(argv[1]);
    nrhs = atoi(argv[2]);
    
    lda = m;
    ldb = m;    
    
    double A[lda*m]; 
    double B[ldb*nrhs];
    double XC[ldb*nrhs]; 
    
    for(int i =0;i< m * m ;i++)
        A[i] = randomRange(-5,5);

    for(int i =0;i<m*nrhs;i++)
        B[i] = randomRange(-5,5);

        

    double *d_A = NULL; 
    double *d_tau = NULL; 
    double *d_B  = NULL; 
    int    *devInfo = NULL; 
    double *d_work = NULL;
    int     lwork = 0; 
    int info_gpu = 0;
    const double one = 1;

    printf("Matriz A:\n");
    imprimeMatriz(m, m, A, lda, "A");
    printf("=======================\n");
    printf("Vector B:\n");
    imprimeMatriz(m, nrhs, B, ldb, "B");
    printf("=======================\n");

    cusolver_status = cusolverDnCreate(&cusolverH);
    
    cublas_status = cublasCreate(&cublasH);
    
    
    cudaStat1 = cudaMalloc ((void**)&d_A  , sizeof(double) * lda * m);
    cudaStat2 = cudaMalloc ((void**)&d_tau, sizeof(double) * m);
    cudaStat3 = cudaMalloc ((void**)&d_B  , sizeof(double) * ldb * nrhs);
    cudaStat4 = cudaMalloc ((void**)&devInfo, sizeof(int));
    
    cudaStat1 = cudaMemcpy(d_A, A, sizeof(double) * lda * m   , cudaMemcpyHostToDevice);
    cudaStat2 = cudaMemcpy(d_B, B, sizeof(double) * ldb * nrhs, cudaMemcpyHostToDevice);
    
    cusolver_status = cusolverDnDgeqrf_bufferSize(cusolverH, m, m, d_A, lda, &lwork);
    cudaStat1 = cudaMalloc((void**)&d_work, sizeof(double)*lwork);
    cusolver_status = cusolverDnDgeqrf(cusolverH, m, m, d_A, lda, d_tau, d_work, lwork, devInfo);
    cudaStat1 = cudaDeviceSynchronize();    
    cudaStat1 = cudaMemcpy(&info_gpu, devInfo, sizeof(int), cudaMemcpyDeviceToHost);
    
    cusolver_status= cusolverDnDormqr(cusolverH, CUBLAS_SIDE_LEFT, CUBLAS_OP_T,m, 
                                      nrhs, m, d_A, lda,d_tau,d_B,ldb,
                                      d_work,lwork,devInfo);
    cudaStat1 = cudaDeviceSynchronize();    

    cudaStat1 = cudaMemcpy(&info_gpu, devInfo, sizeof(int), cudaMemcpyDeviceToHost);


    cublas_status = cublasDtrsm(cublasH,CUBLAS_SIDE_LEFT,CUBLAS_FILL_MODE_UPPER,CUBLAS_OP_N, CUBLAS_DIAG_NON_UNIT,
                                m,nrhs,&one,d_A,lda,d_B,ldb);
  cudaStat1 = cudaDeviceSynchronize();

  cudaStat1 = cudaMemcpy(XC, d_B, sizeof(double)*ldb*nrhs, cudaMemcpyDeviceToHost);


  printf("Vector Solución X\n");
  imprimeMatriz(m, nrhs, XC, ldb, "X");
  printf("=======================\n");

  if (d_A    ) cudaFree(d_A);
  if (d_tau  ) cudaFree(d_tau);
  if (d_B    ) cudaFree(d_B);
  if (devInfo) cudaFree(devInfo);
  if (d_work ) cudaFree(d_work);


  if (cublasH ) cublasDestroy(cublasH);   
  if (cusolverH) cusolverDnDestroy(cusolverH);   

  cudaDeviceReset();

  return 0;
}


void imprimeMatriz(int m, int n, const double*A, int lda, const char* name){
    for(int row = 0 ; row < m ; row++){
        for(int col = 0 ; col < n ; col++){
            double Areg = A[row + col*lda];
            printf("%s[%d,%d] = %f\t", name, row+1, col+1, Areg);
        }
        printf("\n");
    }
}


double randomRange(double m,double n){
    return m + (rand() / ( RAND_MAX / (n-m) ) ) ;  
}




