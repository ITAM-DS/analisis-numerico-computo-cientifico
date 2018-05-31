#include <cuda.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "magma_v2.h"
#include "magma_lapack.h"


//Assuming we read the matrix A and not A'
int main()
{

  magma_init ();
// For dgemv -> y = alpha*Ax + beta*y.
// We want to calculate  b -Ax => alpha=-1, beta=1, y=b

  magma_trans_t  	transA = MagmaTrans;
  magma_int_t  	m=4;
  magma_int_t  	n=2;
  double  	alpha=-1;
  magmaDouble_ptr  	dA=NULL;
  magma_int_t  	ldda=n;
  magmaDouble_ptr  	dx=NULL;
  magma_int_t  	incx=1;
  double  	beta=1;
  magmaDouble_ptr  	db=NULL;
  magma_int_t  	incy=1;
  magma_queue_t  	queue=NULL;

  // We want this to calculate Ad
  magmaDouble_ptr  	dd=NULL;
  magmaDouble_ptr  	daux=NULL;




  printf("Debug\n" );

  double d[n], aux[n],x[n], b[m]; //Direction and point of previous iteration. Both already in the hyperplane.
  double lambda[m]; // Parameter to find.
  double A[m][n];



  magma_dmalloc( &dA, n*m ); // Remember the load is transpose
  magma_dmalloc( &dx, 1*n );
  magma_dmalloc( &db, 1*m );

  magma_dmalloc( &dd, 1*n );
  magma_dmalloc( &daux, 1*m );


  if (dA == NULL || dx == NULL || db == NULL || dd == NULL || daux)
  {
    printf("malloc failed\n" );
  }

/* For debbuging porpouses: Fills MAtrix and vectors */

  for(int i = 0; i<m; i++)
  {
    for(int j = 0; j<n; j++)
    {
      A[i][j]= 0.0;
      if(j==i && i < n)A[i][j]= -1.0;
      if((j%n)==(i%n) && i >= n)A[i][j]= 1.0;

    }
  }

  for(int i = 0 ; i <n; i++)
  {
    d[i]= (double) 1/n;
    x[i]= (double) 1/n;
  }

  for(int j=0; j < m; j++)
  {
    b[j] = (double)0;

  }


  b[0]=0;
  b[1]=0;
  b[2]=1;
  b[3]=1;

x[0]=.5;
x[1]=.5;

d[0]=1.3;
d[1]=-.3;

/*Fill debugging ends */

for(int j=0; j < m; j++)
{
  lambda[j]= 0.0;

}

for(int j = 0; j < n; j++)
{
  aux[n]=0;

}


magma_int_t dev = 0;
magma_queue_create( dev, &queue );

printf("\n Before set \n");
magma_setmatrix(n,m, sizeof(double),A,n,dA,n, queue);
magma_setvector(n, sizeof(double),x,1,dx,1, queue);
magma_setvector(m, sizeof(double),b,1,db,1, queue);

printf(" A_GPU: \n");
magma_dprint_gpu(n,m, dA,n, queue);

printf(" x_GPU: \n");
magma_dprint_gpu(n,1, dx,n, queue);

printf(" b_GPU: \n");
magma_dprint_gpu(m,1, db,m, queue);

// Calculates  b - Ax for inequalities
  magma_dgemv
  (
  	transA,
    n,
    m,
    alpha,
    dA,
    ldda,
    dx,
    incx,
    beta,
    db,
    incy,
    queue
 );

/*After this db no longer contains b. db= b -Ax */
 printf(" Solution b_GPU: \n");
 magma_dprint_gpu(m,1, db,m, queue);

//We upload to the device d
 magma_setvector(n, sizeof(double),d,1,dd,1, queue);

 printf(" Load d_GPU: \n");
 magma_dprint_gpu(n,1, dd,n, queue);

 magma_dgemv
 (
   transA,
   n,
   m,
   1, //alpha
   dA,
   ldda,
   dd,
   incx,
   0, //beta
   daux,
   incy,
   queue
);

//After here dd no longer contains d. dd=Ad

printf(" Solution aux_GPU: \n");
magma_dprint_gpu(m,1, daux,m, queue);

magma_getvector(m,sizeof(double),db,1,b,1, queue);
magma_getvector(m,sizeof(double),daux,1,aux,1, queue);

for(int j = 0; j < m; j++)
{
  if(aux[j] !=0)
  {
    lambda[j]=b[j]/aux[j];
  }else{lambda[j]=-10000000000;}
}



double lambda_f[2]={1000000, -1000000};

for(int j=0; j<m ; j++)
{
  // Find positive lambda
  printf("Lambda_%d : %lf \n",j,lambda[j]);
  if(lambda[j]<lambda_f[0] && lambda[j]>=0){lambda_f[0]=lambda[j];}
  if(-lambda[j]>lambda_f[1]){lambda_f[1]=-lambda[j];}

}

// if(lambda_f[0]<0)lambda_f[0]=0;
// if(lambda_f[1]>0)lambda_f[1]=0;

printf("\n Lambda_1 : %lf\n",lambda_f[0]);
printf("\n Lambda_2 : %lf\n",lambda_f[1]);

printf("X: \n");
for(int i= 0; i < n ; i++)
{
  x[i] = x[i] + lambda_f[0]*d[i];
  printf(" %lf\n",x[i]);

}

 magma_free(dA);
 magma_free(dx);
 magma_free(db);
 magma_free(dd);

}
