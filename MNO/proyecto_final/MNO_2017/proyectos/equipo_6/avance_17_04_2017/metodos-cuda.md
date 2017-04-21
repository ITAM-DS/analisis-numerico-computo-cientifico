

# Docker NVIDIA

## Integrantes:

* Ricardo Lastra

* Adrián Vázquez


## ¿Metodos investigados?
- Aplicaremos la libreria [CUBLAS](http://docs.nvidia.com/cuda/cublas/index.html#introduction) via __cuBLAS API__
	
- Se aplicará el calculo de SVD utilizando CUDA vía el metodo [BLAS-3](http://docs.nvidia.com/cuda/cublas/#cublas-level-3-function-reference)

- Para implementar el metodo utilizaremos una implementación existente en el __SDK CUDA 8-0__ con `CUBLAS` y `cuSOLVER` Ver el archivo ![cuSOLVER](http://docs.nvidia.com/cuda/cusolver/#axzz4epp7wrFR)

- El patron de codificación respnde al siguiente diagrama:

![heterogeneous-programming](images/heterogeneous-programming.png)

1. Mediante la utilización de API cuBLAS, nuestra aplicación estará asignando espacio de memoria en el device (GPU), 
2. posteriormente rellenarlos con datos, 
3. El siguiente paso es llamar a la secuencia de funciones cuBLAS deseadas
4. Finalmente se cargan los resultados del espacio de memoria GPU de nuevo en el host. __La API cuBLAS también proporciona funciones auxiliares para escribir y recuperar datos de la GPU__
 


## Implementación SVD con CUDA

* La implementación original fue tomada del [sitio](http://docs.nvidia.com/cuda/) 
* Se valido el resultado del programa con el programa realizado en python: 
	![cuda vs python](images/cuda_python_resul.png)


* __SVD Implementation__ 

## Step 0: Headers, Include and set variables 

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <cuda_runtime.h>
#include <cublas_v2.h>
#include <cusolverDn.h>

void printMatrix(int m, int n, const double*A, int lda, const char* name)
{
    for(int row = 0 ; row < m ; row++){
        for(int col = 0 ; col < n ; col++){
            double Areg = A[row + col*lda];
            printf("%s(%d,%d) = %f\n", name, row+1, col+1, Areg);
        }
    }
}

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
    cudaError_t cudaStat5 = cudaSuccess;
    cudaError_t cudaStat6 = cudaSuccess;
    const int m = 3;
    const int n = 3;
    const int lda = m;
 /* entradas para la Mtriz A
 *	 | -0.558253 -0.0461681  -0.505735|
 *   A = | -0.411397  0.0365854   0.199707|
 *       |  0.285389 -0.313789    0.200189|
 */
    double A[lda*n] = { -0.558253, -0.411397, 0.285389, -0.0461681, 0.0365854, -0.313789, -0.505735, 0.199707, 0.200189}; 
    double U[lda*m]; // m-by-m unitary matrix 
    double VT[lda*n];  // n-by-n unitary matrix
    double S[n]; // singular value
    double S_exact[n] = {7.065283497082729, 1.040081297712078};

    double *d_A = NULL;
    double *d_S = NULL;
    double *d_U = NULL;
    double *d_VT = NULL;
    int *devInfo = NULL;
    double *d_work = NULL;
    double *d_rwork = NULL;
    double *d_W = NULL;  // W = S*VT

    int lwork = 0;
    int info_gpu = 0;
    const double h_one = 1;
    const double h_minus_one = -1;

 
    printf("A = (matlab base-1)\n");
    printMatrix(m, n, A, lda, "A");
    printf("=====\n");

```

## step 1: se crea cusolverDn/cublas handle

```
    cusolver_status = cusolverDnCreate(&cusolverH);
    assert(CUSOLVER_STATUS_SUCCESS == cusolver_status);

    cublas_status = cublasCreate(&cublasH);
    assert(CUBLAS_STATUS_SUCCESS == cublas_status);

```

## step 2: copiar los datos A y B al device


```
    cudaStat1 = cudaMalloc ((void**)&d_A  , sizeof(double)*lda*n);
    cudaStat2 = cudaMalloc ((void**)&d_S  , sizeof(double)*n);
    cudaStat3 = cudaMalloc ((void**)&d_U  , sizeof(double)*lda*m);
    cudaStat4 = cudaMalloc ((void**)&d_VT , sizeof(double)*lda*n);
    cudaStat5 = cudaMalloc ((void**)&devInfo, sizeof(int));
    cudaStat6 = cudaMalloc ((void**)&d_W  , sizeof(double)*lda*n);
    assert(cudaSuccess == cudaStat1);
    assert(cudaSuccess == cudaStat2);
    assert(cudaSuccess == cudaStat3);
    assert(cudaSuccess == cudaStat4);
    assert(cudaSuccess == cudaStat5);
    assert(cudaSuccess == cudaStat6);

    cudaStat1 = cudaMemcpy(d_A, A, sizeof(double)*lda*n, cudaMemcpyHostToDevice);
    assert(cudaSuccess == cudaStat1);

```

## step 3: consulta el espacio de trabajo para SVD

```
    cusolver_status = cusolverDnDgesvd_bufferSize(
        cusolverH,
        m,
        n,
        &lwork );
    assert (cusolver_status == CUSOLVER_STATUS_SUCCESS);

    cudaStat1 = cudaMalloc((void**)&d_work , sizeof(double)*lwork);
    assert(cudaSuccess == cudaStat1);

```

## step 4: procesa SVD

```
    signed char jobu = 'A'; // all m columns of U
    signed char jobvt = 'A'; // all n columns of VT
    cusolver_status = cusolverDnDgesvd (
        cusolverH,
        jobu,
        jobvt,
        m,
        n,
        d_A,
        lda,
        d_S,
        d_U,
        lda,  // ldu
        d_VT,
        lda, // ldvt,
        d_work,
        lwork,
        d_rwork,
        devInfo);
    cudaStat1 = cudaDeviceSynchronize();
    assert(CUSOLVER_STATUS_SUCCESS == cusolver_status);
    assert(cudaSuccess == cudaStat1);

 
    cudaStat1 = cudaMemcpy(U , d_U , sizeof(double)*lda*m, cudaMemcpyDeviceToHost);
    cudaStat2 = cudaMemcpy(VT, d_VT, sizeof(double)*lda*n, cudaMemcpyDeviceToHost);
    cudaStat3 = cudaMemcpy(S , d_S , sizeof(double)*n    , cudaMemcpyDeviceToHost);
    cudaStat4 = cudaMemcpy(&info_gpu, devInfo, sizeof(int), cudaMemcpyDeviceToHost);
    assert(cudaSuccess == cudaStat1);
    assert(cudaSuccess == cudaStat2);
    assert(cudaSuccess == cudaStat3);
    assert(cudaSuccess == cudaStat4);

    printf("after gesvd: info_gpu = %d\n", info_gpu);
    assert(0 == info_gpu);
    printf("=====\n");

    printf("S = (matlab base-1)\n");
    printMatrix(n, 1, S, lda, "S");
    printf("=====\n");

    printf("U = (matlab base-1)\n");
    printMatrix(m, m, U, lda, "U");
    printf("=====\n");

    printf("VT = (matlab base-1)\n");
    printMatrix(n, n, VT, lda, "VT");
    printf("=====\n");
```

## step 5: calcula presición de error del SVD


```
    double ds_sup = 0;
    for(int j = 0; j < n; j++){
        double err = fabs( S[j] - S_exact[j] );
        ds_sup = (ds_sup > err)? ds_sup : err;
    }
    printf("|S - S_exact| = %E \n", ds_sup);

```

## step 6: |A - U*S*VT|

    W = S*VT

```

    cublas_status = cublasDdgmm(
        cublasH,
        CUBLAS_SIDE_LEFT,
        n,
        n,
        d_VT,
        lda,
        d_S,
         1,
        d_W,
        lda);
    assert(CUBLAS_STATUS_SUCCESS == cublas_status);

    // A := -U*W + A
    cudaStat1 = cudaMemcpy(d_A, A, sizeof(double)*lda*n, cudaMemcpyHostToDevice);
    assert(cudaSuccess == cudaStat1);
    cublas_status = cublasDgemm_v2(
        cublasH,
        CUBLAS_OP_N, // U
        CUBLAS_OP_N, // W
        m, // number of rows of A
        n, // number of columns of A
        n, // number of columns of U 
        &h_minus_one, /* host pointer */
        d_U, // U
        lda,
        d_W, // W
        lda,
        &h_one, /* hostpointer */
        d_A,
        lda);
    assert(CUBLAS_STATUS_SUCCESS == cublas_status);

    double dR_fro = 0.0;
    cublas_status = cublasDnrm2_v2(
        cublasH, lda*n, d_A, 1, &dR_fro);
    assert(CUBLAS_STATUS_SUCCESS == cublas_status);

    printf("|A - U*S*VT| = %E \n", dR_fro);
```

## free resources

```
    if (d_A    ) cudaFree(d_A);
    if (d_S    ) cudaFree(d_S);
    if (d_U    ) cudaFree(d_U);
    if (d_VT   ) cudaFree(d_VT);
    if (devInfo) cudaFree(devInfo);
    if (d_work ) cudaFree(d_work);
    if (d_rwork) cudaFree(d_rwork);
    if (d_W    ) cudaFree(d_W);

    if (cublasH ) cublasDestroy(cublasH);
    if (cusolverH) cusolverDnDestroy(cusolverH);

    cudaDeviceReset();

    return 0;
}

```

## compilamos el codigo

* __Ejecutamos los siguientes comandos__

`nvcc -I /usr/local/cuda-8.0/include svd_example.cu -o svd_example.out -lcublas -lcusolver -lcudart -lcusparse -llapack -lblas -arch=sm_30`

* __Validamos restltados__
```
A = (matlab base-1)
A(1,1) = -0.558253
A(1,2) = -0.046168
A(1,3) = -0.505735
A(2,1) = -0.411397
A(2,2) = 0.036585
A(2,3) = 0.199707
A(3,1) = 0.285389
A(3,2) = -0.313789
A(3,3) = 0.200189
=====
after gesvd: info_gpu = 0
=====
S = (matlab base-1)
S(1,1) = 0.860883
S(2,1) = 0.413613
S(3,1) = 0.296320
=====
U = (matlab base-1)
U(1,1) = -0.849310
U(1,2) = 0.354882
U(1,3) = 0.390809
U(2,1) = -0.278376
U(2,2) = -0.930100
U(2,3) = 0.239626
U(3,1) = 0.448530
U(3,2) = 0.094725
U(3,3) = 0.888734
=====
VT = (matlab base-1)
VT(1,1) = 0.832469
VT(1,2) = -0.129771
VT(1,3) = 0.538660
VT(2,1) = 0.511493
VT(2,2) = -0.193746
VT(2,3) = -0.837160
VT(3,1) = -0.213002
VT(3,2) = -0.972431
VT(3,3) = 0.094911
=====
|S - S_exact| = 6.204401E+00 
|A - U*S*VT| = 2.315970E-16

```


- revisar archivo ![salida.dat](code/svd-sdk-cuda/salida.dat) 

__Lineas de investigación:__

- Se instalaran utilerias para leer los archivos `chunk-001, chunk-002` `...chunk-00n`

- Buscaremos generar __warps__ para ejecutar SVD desde Kernel para funciones como ` __cusolverDnDgesvd__` y `__cublasDdgmm__`.

- Validaremos que estemos ejecutando tipo de operaciones __Level 3 Routines **distributed matrix-matrix operations**__



by ADVP
