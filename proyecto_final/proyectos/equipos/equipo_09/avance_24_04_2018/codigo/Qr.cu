/* Equipo 9
 *  Factorización QR utilizando CUDA, cuSolver
 *  Para compilar se debe ejecutar:
 *  make 
 *  Para ejecutar el programa, se debe realizar:
 *  make ejecutarlo 
 *  Si se quiere compilar sin el archivo make
 *  nvcc  -I/usr/local/cuda/include Qr.cu -lcublas -lcusolver
 *  Las matrices se alamacen en orden column major
 */

#include <stdio.h>
#include <stdlib.h>
#include <cuda_runtime.h>
#include <cublas_v2.h> 
#include <cusolverDn.h>


void imprimeMatriz(int m, int n, const double*A, int lda, const char* name);

int main(int argc, char*argv[])
{

    /* Se inicializan variables*/

    cusolverDnHandle_t cusolverH = NULL;
    cublasHandle_t cublasH = NULL;
    cublasStatus_t cublas_status = CUBLAS_STATUS_SUCCESS;
    cusolverStatus_t cusolver_status = CUSOLVER_STATUS_SUCCESS;    
    cudaError_t cudaStat1 = cudaSuccess;
    cudaError_t cudaStat2 = cudaSuccess;
    cudaError_t cudaStat3 = cudaSuccess;
    cudaError_t cudaStat4 = cudaSuccess;

    /* Se realiza una prueba con una matriz de 3 x 2  */

    int m = 3;     // Dimension de la matriz
    int n = 2; 
    int lda = m;   
    
    /* Se define la matriz , se va cambiar para que se lea la matriz de un archivo de texto*/ 

    double A[lda*n] = { 3.0, 4.0, 1.0, -2.0, 5.1, -1.2};
    double Q[lda*n]; 
    double R[n*n]; 
    
    double *d_A = NULL;
    double *d_tau = NULL;
    int    *devInfo = NULL;
    double *d_work = NULL;

    double *d_R = NULL;

    int info_gpu = 0;

    int lwork_geqrf = 0;
    int lwork_orgqr = 0;
    int lwork = 0;


    double h_one = 1;
    double h_minus_one = -1;
    
    printf("Matriz A:\n");
    imprimeMatriz(m, n, A, lda, "A");


    cusolver_status = cusolverDnCreate(&cusolverH);
    cublas_status = cublasCreate(&cublasH);

    cudaStat1 = cudaMalloc ((void**)&d_A , sizeof(double)*lda*n);
    cudaStat2 = cudaMalloc ((void**)&d_tau, sizeof(double)*n);
    cudaStat3 = cudaMalloc ((void**)&devInfo, sizeof(int));
    cudaStat4 = cudaMalloc ((void**)&d_R , sizeof(double)*n*n);


    cudaStat1 = cudaMemcpy(d_A, A, sizeof(double)*lda*n,cudaMemcpyHostToDevice);
    
    cusolver_status = cusolverDnDgeqrf_bufferSize(cusolverH,m,n,d_A,lda,&lwork_geqrf);                                                    
    //cusolver_status = cusolverDnDorgqr_bufferSize(cusolverH,m,n,n,d_A,lda,&lwork_orgqr);
        
    lwork = (lwork_geqrf > lwork_orgqr)? lwork_geqrf : lwork_orgqr;
    cudaStat1 = cudaMalloc((void**)&d_work, sizeof(double)*lwork);


    /* Calcula QR*/ 
    cusolver_status = cusolverDnDgeqrf(cusolverH,m,n,d_A,lda,d_tau,d_work,lwork,devInfo);
    cudaStat1 = cudaDeviceSynchronize();    

    /* Calcula Q */                                                       
    cusolver_status= cusolverDnDorgqr(cusolverH,m,n,n,d_A,lda,d_tau,d_work,lwork,devInfo);
    cudaStat1 = cudaDeviceSynchronize();

    /* Copia a host */
    cudaStat1 = cudaMemcpy(Q, d_A, sizeof(double)*lda*n,cudaMemcpyDeviceToHost);

    printf("Matriz Q:\n");
    imprimeMatriz(m, n, Q, lda, "Q");

    memset(R, 0, sizeof(double)*n*n);
    for(int j = 0 ; j < n ; j++){
        R[j + n*j] = 1.0; 
    }

    /* Copia de host al dispositivo */
    cudaStat1 = cudaMemcpy(d_R, R, sizeof(double)*n*n, cudaMemcpyHostToDevice);

    cublas_status = cublasDgemm_v2(cublasH,CUBLAS_OP_T, CUBLAS_OP_N, n, n,m, 
                                    &h_minus_one, d_A, lda,d_A, lda,&h_one,d_R,n);
    
    double dR_nrm2 = 0.0;
    cublas_status = cublasDnrm2_v2(cublasH, n*n, d_R, 1, &dR_nrm2);    


    // Liberar memoria 

    if (d_A)       cudaFree(d_A);
    if (d_tau )    cudaFree(d_tau);
    if (devInfo)   cudaFree(devInfo);
    if (d_work )   cudaFree(d_work);
    if (d_R)       cudaFree(d_R);
    if (cublasH )  cublasDestroy(cublasH);
    if (cusolverH) cusolverDnDestroy(cusolverH);
    cudaDeviceReset();

    printf("Finaliza ejecución\n");

    return 0;
}



void imprimeMatriz(int m, int n, const double*A, int lda, const char* name)
{
    for(int row = 0 ; row < m ; row++){
        for(int col = 0 ; col < n ; col++){
            double Areg = A[row + col*lda];
            printf("%s(%d,%d) = %f\n", name, row+1, col+1, Areg);
        }
        printf("\n");
    }
}

