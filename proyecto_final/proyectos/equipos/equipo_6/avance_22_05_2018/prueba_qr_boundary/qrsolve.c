
#include <cuda.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "magma_v2.h"
#include "magma_lapack.h"

void error_dsgeqrsv(int iter, int info)
{
  switch(iter) {

    case -1  :
      printf("-1 : the routine fell back to full precision for implementation- or machine-specific reasons \n");
      break; /* optional */

    case -2  :
    printf("-2 : narrowing the precision induced an overflow, the routine fell back to full precision \n");
      break; /* optional */

    case -3  :
    printf("-3 : failure of SGEQRF \n");
       break; /* optional */

    case -31  :
    printf("-31: stop the iterative refinement after the 30th iteration \n");
      break; /* optional */

   default : /* Optional */
   printf(" Iterative refinement has been successfully used. Returns the number of iterations: %d \n",iter);
}

if(info == 0)
{
  printf("Succesful Exit");
}
else
{
  printf(" The -%dth argument has ilegal value \n",info);
}

}


// The mas without descompositon is around m=565 por GPU 1050 Ti
int main()
{
  magma_init ();
  magma_int_t m = 565;
  magmaDouble_ptr dA=NULL, dX=NULL, dI=NULL;
  magma_int_t iter ;
  magma_int_t info ;
  magma_queue_t queue=NULL;

  iter=0;
  info=1;

  double A[m][m]; //Restriction Matrix (A'*A)
  double I[m][m]; //Identity
  double X[m][m]; // The inverse
  int mod = 7 ;



  magma_dmalloc( &dA, m*m );
  magma_dmalloc( &dX, m*m );
  magma_dmalloc( &dI, m*m );

  if (dA == NULL || dX == NULL || dI == NULL)
  {
    printf("malloc failed\n" );
  }


// Creates the matrix for testing

int i=0;
int j=0;

  for( i = 0; i<m; i++)
  {
    for(j = 0; j<m; j++)
    {
      X[i][j] = (double)-1;
      I[i][j] = (double)0;
      A[j][i]= (double)0;
      if(j == i){ I[i][j] = 1; }
      if(j <= i){ A[j][i]= (double)1;}
      printf(" %lf ",A[i][j]);

    }
    printf("\n");
  }

  magma_int_t dev = 0;
  magma_queue_create( dev, &queue );

  printf("\n Before set \n");
  magma_setmatrix(m,m, sizeof(double),A,m,dA,m, queue);
  magma_setmatrix(m,m, sizeof(double),I,m,dI,m, queue);
  magma_setmatrix(m,m, sizeof(double),X,m,dX,m, queue);


//Debugging: Prints the matrix stored in the GPU

  printf(" A_GPU: \n");
  magma_dprint_gpu(m,m, dA,m, queue);

  printf(" I_GPU: \n");
  magma_dprint_gpu(m,m, dI,m, queue);

  printf(" X_GPU: \n");
  magma_dprint_gpu(m,m, dX,m, queue);





printf("\n Before function \n");
   magma_dsgeqrsv_gpu( m, m, m,
                      dA, m, dI, m,
                      dX, m, &iter, &info );
if(info !=0){
  error_dsgeqrsv(iter,info);
}else{printf("\n Praise the Sun !!!! \n");}

  magma_queue_create( dev, &queue );
  magma_getmatrix(m,m, sizeof(double),dX,m,X,m, queue);

  //Print status of the solver operation

  printf(" Sol_GPU: \n");
  magma_dprint_gpu(m,m, dX,m, queue);

  printf(" Sol_CPU: \n");
  magma_dprint(m,m, X,m);

  /*Free memory*/

  if(info !=0){
    error_dsgeqrsv(iter,info);
  }else{printf("\n Praise the Sun !!!! \n");}
magma_free(dA);
magma_free(dX);
magma_free(dI);

return 0;

}
