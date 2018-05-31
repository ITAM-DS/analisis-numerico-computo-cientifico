#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// includes, project
#include "magma_v2.h"
#include "magma_lapack.h"


int main (int argc, char** argv ){

  double *h_A; //host matrix
  double *tao; //I saw this in a test file

  magmaDouble_ptr  	 d_A; //device matrix
  magma_int_t M, N, lda, ldda, info;
  magma_int_t status   = 0;

  magma_opts opts;

  M = 40; //rows
  N = 40; // cols
  lda = M; // finding max
  h_A = (double*)malloc (M*N*sizeof(double) ); // malloc for device matrix
  ldda   = ((M+31)/32)*32;

  for(int i =0; i<M*M;i++){
    h_A[i]=i;

  }

  init_matrix(M, N, h_A, lda); // init matrix
  magma_dsetmatrix( M, N, h_A, lda, d_A, ldda, opts.queue); // defines the matrix for MAGMA, like cuda_mem_copy
  magma_dgeqrf2_gpu( M, N, d_A, ldda, tao, &info); // Applies QR factorization to d_A

  for(int i =0; i<M*M;i++){
    printf("%lf)\n", d_A[i]);

  }

  magma_free_cpu( tao    );
  magma_free_cpu( h_A    );

}
