/* Equipo 9
 *  Factorización QR utilizando CUDA, cuSolver
 *  Para compilar se debe ejecutar:
 *  make 
 *  Para ejecutar el programa, se debe realizar:
 *  make ejecutarlo 
 *  Si se quiere compilar sin el archivo make
 *  nvcc  -I/usr/local/cuda/include MCQR.cu -lcublas -lcusolver
 *  Rutina para calcular mínimos cuadrados usando la factorización QR
 */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <cuda_runtime.h>
#include <cublas_v2.h>
#include <cusolverDn.h>
#include "definiciones.h"

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
    int m = 1;
    int lda = m;
    int ldb = m;
    int nrhs = 1; 
    arreglo_2d_T AA, BB, XX;

    // Lee matriz A


    m = atoi(argv[1]);

    AA = (arreglo_2d_T) malloc(sizeof(*AA));
    
    renglones(AA)=m;
    columnas(AA)=m;
    entradas(AA)=(double*)malloc(renglones(AA)*columnas(AA)*sizeof(double));
    inicializa_matriz(AA,"A.txt");
    imprime_matriz(AA);


    // Lee Matriz B

    printf("\n");

    BB = (arreglo_2d_T) malloc(sizeof(*BB));
    
    renglones(BB)=m;
    columnas(BB)=1;
    entradas(BB)=(double*)malloc(renglones(BB)*columnas(BB)*sizeof(double));
    inicializa_matriz(BB,"B.txt");
    imprime_matriz(BB);


    // Configura matriz con el resultado

    XX = (arreglo_2d_T) malloc(sizeof(*XX));

    renglones(XX)=m;
    columnas(XX)=1;
    entradas(XX)=(double*)malloc(renglones(XX)*columnas(XX)*sizeof(double));

    nrhs = 1;
    
    lda = m;
    ldb = m;    
    
    double A[lda*m]; 
    double B[ldb*nrhs];
    double XC[ldb*nrhs]; 
        

    double *d_A = NULL; 
    double *d_tau = NULL; 
    double *d_B  = NULL; 
    int    *devInfo = NULL; 
    double *d_work = NULL;
    int     lwork = 0; 
    int info_gpu = 0;
    const double one = 1;
    

    cusolver_status = cusolverDnCreate(&cusolverH);    
    cublas_status = cublasCreate(&cublasH);        
    cudaStat1 = cudaMalloc ((void**)&d_A  , sizeof(double) * lda * m);
    cudaStat2 = cudaMalloc ((void**)&d_tau, sizeof(double) * m);
    cudaStat3 = cudaMalloc ((void**)&d_B  , sizeof(double) * ldb * nrhs);
    cudaStat4 = cudaMalloc ((void**)&devInfo, sizeof(int));
    cudaStat1 = cudaMemcpy(d_A, entradas(AA), sizeof(double) * lda * m   , cudaMemcpyHostToDevice);
    cudaStat2 = cudaMemcpy(d_B, entradas(BB), sizeof(double) * ldb * nrhs, cudaMemcpyHostToDevice);
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
    cudaStat1 = cudaMemcpy(entradas(XX), d_B, sizeof(double)*ldb*nrhs, cudaMemcpyDeviceToHost);


    printf("\n");        
    printf("=======================\n");        
    printf("Solución X\n");
    imprime_matriz(XX);
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

double randomRange(double m,double n){
    return m + (rand() / ( RAND_MAX / (n-m) ) ) ;  
}
