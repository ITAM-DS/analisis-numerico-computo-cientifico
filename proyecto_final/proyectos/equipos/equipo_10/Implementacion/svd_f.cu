#include <cuda_runtime.h>
#include <cublas_v2.h>
#include <cusolverDn.h>
#include <fstream>
#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


typedef struct {
  int idx;
  double *el;
} Matrix;

int main(int argc, char*argv[])
{

        if (argc<2) {
                cout << "Input file not specified. Please, specify it as a first argument." << endl;
                cout << "example: " << argv[0] << " train_data_matrix_T.txt" << endl;
                return -1;
        }
        ifstream file(argv[1]);
        ofstream S_diag("S_diag.txt");
        ofstream U_rows("U_rows.txt");
	ofstream VT_cols("VT_cols.txt");

        if (!file)
        {
                cout << "Error opening file" << endl;
                return -1;
        }

        int idx;
        file >> idx;                     
        if (argc>2) cout << "N=" << idx << endl;

	// --- gesvd only supports Nrows >= Ncols
	// --- column major memory ordering

        const int m = 1682; 
        const int n = 943; 
        const int lda = m;

        // --- CUDA solver initialization

        cusolverDnHandle_t solver_handle; 
        cublasHandle_t cublasH = NULL; 
   
        Matrix A, U, VT;      //host matrices
        A.el = new double[lda*n];    //.... 
        U.el = new double[lda*n];    //...
        VT.el = new double[lda*n];   //..

    //reading from file into matrices
        for (long i=0; i<(lda*n); i++){
                file >> A.el[i];
		double io = A.el[i];
                printf("%1.9f,  ",io);
	}
    printf("\n");
    
    double S[n]; // singular value
    double *d_rwork = NULL;

// --- cuSOLVE input/output parameters/arrays

    int work_size = 0;
    int info_gpu = 0;
    int *devInfo; cudaMalloc ((void**)&devInfo, sizeof(int));

 
//  create cusolverDn/cublas handle
    assert(cusolverDnCreate(&solver_handle));
    assert(cublasCreate(&cublasH));


    // --- Setting the device matrix and moving the host matrix to the device

    double *d_A; cudaMalloc ((void**)&d_A  , sizeof(double)*lda*n);
    cudaMemcpy(d_A, A.el, sizeof(double)*lda*n, cudaMemcpyHostToDevice);

    // --- device side SVD workspace and matrices

    double *d_S; cudaMalloc ((void**)&d_S  , sizeof(double)*n);
    double *d_U; cudaMalloc ((void**)&d_U  , sizeof(double)*lda*m);
    double *d_VT; cudaMalloc ((void**)&d_VT , sizeof(double)*lda*n);
    
    double *d_W; cudaMalloc ((void**)&d_W  , sizeof(double)*lda*n);


    // --- CUDA SVD initialization

    assert(cusolverDnDgesvd_bufferSize(solver_handle,m,n,&work_size));
    double *d_work; assert(cudaMalloc((void**)&d_work , sizeof(double)*work_size));


    // --- CUDA SVD execution

    assert(cusolverDnDgesvd (solver_handle,'A','A',m,n,d_A,lda,d_S,d_U,lda,d_VT,lda,d_work,work_size,d_rwork,devInfo));
    assert(cudaDeviceSynchronize());


    // --- Moving the results from device to host

    assert(cudaMemcpy(U.el , d_U , sizeof(double)*lda*m, cudaMemcpyDeviceToHost));
    assert(cudaMemcpy(VT.el, d_VT, sizeof(double)*lda*n, cudaMemcpyDeviceToHost));
    assert(cudaMemcpy(S , d_S , sizeof(double)*n, cudaMemcpyDeviceToHost));
    assert(cudaMemcpy(&info_gpu, devInfo, sizeof(int), cudaMemcpyDeviceToHost));


    assert(0 == info_gpu);
    printf("Singular values\n");
    for (int k=0; k<n; k++){
                        S_diag << S[k] << " ";
    }
    
    printf("=====\n");
    printf("\nLeft singular vectors - For y = A * x, the columns of U span the space of y\n");
    for (int k=0; k<m; k++){
                for (int j=0; j<m; j++)
                        U_rows << U.el[k+j*lda] << " ";
                U_rows << endl;
    }
    
    printf("=====\n");
    printf("\nRight singular vectors - For y = A * x, the columns of V span the space of x\n");
    for (int k=0; k<n; k++){
                for (int j=0; j<n; j++)
                        VT_cols << VT.el[k+j*lda] << " ";
                VT_cols << endl;
    }


    if (solver_handle) cusolverDnDestroy(solver_handle);

    cudaDeviceReset();

    return 0;
}






