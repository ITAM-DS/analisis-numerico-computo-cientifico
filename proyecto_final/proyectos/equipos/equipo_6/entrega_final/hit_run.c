#include "Headers/init.h"
#include "Headers/chebyshev_center.h"
#include "Headers/matrix_operations.h"
#include "Headers/box_muller.h"
#include "lpsolve/lp_lib.h"

// Define number of variables
static unsigned NUMBER_VARIABLES;
// Define number of equalities and inequalities
static unsigned NUMBER_EQUALITIES;
static unsigned NUMBER_INEQUALITIES;
// Structs of restrictions
static Plinear_eq P_EQUALITY;
static Plinear_ineq P_INEQUALITY;


void matrix_debug(double **q,int m, int n)
{
  printf("\n Value \n");
  for(int i = 0; i <m;i++)
  { printf("%d: ",i);
    for(int j = 0; j <n;j++)
    {
      printf(" %lf ",q[i][j]);
    }
  printf("\n");
  }
}



int main(int argc, char *argv[]) {
  parse_arguments(argc, argv);

  define_pointers();
  define_parameters();
  double x_0[NUMBER_VARIABLES];
  get_initvalue(x_0);


int me = NUMBER_EQUALITIES;
int mi = NUMBER_INEQUALITIES;
int n = NUMBER_VARIABLES;

/* Obtain AAT */
  /*
  Matrix multiplication
  Computes C = op(A) * op(B)
  Matrix dimensions:
    op(A): n x k
    op(B): k x m
    C: n x m
  op(X) can be X or X'
  */
double **AAT;
double **A = P_EQUALITY->a;


// Define AAT
AAT = (double **)malloc(sizeof(double *) * me);

for(int i = 0; i <me;i++)
{
AAT[i] = (double *)malloc(sizeof(double) * me);
}


   matrix_multiplication(
    A, // Pointer to matrix A
    A, // Pointer to matrix B
    AAT, // Pointer to matrix C
    me,
    n,
    me,
    0,
    1
  ) ;


//matrix_debug(AAT,me, me);

//printf("Inverse \n");

inverse_matrix(me, AAT); // AAT contains its inverse

//Creating first regression coefficent G=At*(AAt)^-1
double **G;

// Define AAT
G= (double **)malloc(sizeof(double *) * n);

for(int i = 0; i <n;i++)
{
G[i] = (double *)malloc(sizeof(double) * me);
}

matrix_multiplication(
 A, // Pointer to matrix A
 AAT, // Pointer to matrix B
 G, // Pointer to matrix C
 n,
 me,
 me,
 1,
 0
);

double **H;

// Define AAT
H= (double **)malloc(sizeof(double *) * n);

for(int i = 0; i <n;i++)
{
H[i] = (double *)malloc(sizeof(double) * n);
}

matrix_multiplication(
 G, // Pointer to matrix A
 A, // Pointer to matrix B
 H, // Pointer to matrix C
 n,
 me,
 n,
 0,
 0
);

for(int i = 0; i < n; i++)
{
  for(int j = 0; j < n; j++)
  {
    H[i][j]=-H[i][j];
    if(i==j){  H[i][j]+= 1;}
  }
}


double **b;
double **L;


L= (double **)malloc(sizeof(double *) * n);
b= (double **)malloc(sizeof(double *) * me);


for(int i = 0; i <n;i++)
{
L[i] = (double *)malloc(sizeof(double) * 1);
}

for(int i = 0; i <me;i++)
{
b[i] = (double *)malloc(sizeof(double) * 1);
b[i][i] = (P_EQUALITY->b[i]);
}

//matrix_debug(b,me,1);


/*
Matrix multiplication
Computes C = op(A) * op(B)
Matrix dimensions:
  op(A): n x k
  op(B): k x m
  C: n x m
op(X) can be X or X'
*/

// void matrix_multiplication(
//   double **a, // Pointer to matrix A
//   double **b, // Pointer to matrix B
//   double **c, // Pointer to matrix C
//   int n,
//   int k,
//   int m,
//   int transA,
//   int transB
// )

matrix_multiplication(
 G, // Pointer to matrix A
 b, // Pointer to matrix B
 L, // Pointer to matrix C
 n,
 me,
 1,
 0,
 0
);

//matrix_debug(H,n,n);

double **x;
double **xt;
double **d;
double **dn;
double **dp;
double **IN;
double **num;
double **den;
double **aux;


num = (double **)malloc(sizeof(double *) * mi);
den = (double **)malloc(sizeof(double *) * mi);
IN = (double **)malloc(sizeof(double *) * mi);

x= (double **)malloc(sizeof(double *) * n);
xt= (double **)malloc(sizeof(double *) * n);
d= (double **)malloc(sizeof(double *) * n);
dn= (double **)malloc(sizeof(double *) * n);
dp= (double **)malloc(sizeof(double *) * n);
aux= (double **)malloc(sizeof(double *) * n);


for(int i = 0; i<mi; i++)
{
  IN[i]= (double *)malloc(sizeof(double) * n);
  num[i]=  (double *)malloc(sizeof(double) * 1);
  den[i]= (double *)malloc(sizeof(double) * 1);

}

for(int i = 0; i<mi; i++)
{
  for(int j = 0 ; j <n; j++)
  IN[i][j]= P_INEQUALITY->a[i][j];

}

for(int i = 0; i <n;i++)
{
x[i] = (double *)malloc(sizeof(double) * 1);
xt[i] = (double *)malloc(sizeof(double) * 1);
d[i] = (double *)malloc(sizeof(double) * 1);
dn[i] = (double *)malloc(sizeof(double) * 1);
dp[i] = (double *)malloc(sizeof(double) * 1);
aux[i] = (double *)malloc(sizeof(double) * 1);



x[i][0]=x_0[i];
}

double lambda[2];
double theta = 1;
double c;

unsigned T = 10000;

//L= segunda matriz de proyección
// H primera matriz de proyección




for(int t = 0; t<T; t++)
{

for(int i =0; i < n ; i++)
{
  d[i][0]= -1 + ((double) rand () / RAND_MAX) * 2;
  dp[i][0]=d[i][0];
  dn[i][0]=-d[i][0];

}

// dp projection
  matrix_multiplication(
   H, // Pointer to matrix A
   d, // Pointer to matrix B
   dp, // Pointer to matrix C
   n,
   n,
   1,
   0,
   0
  );
  //matrix_debug(L,n,1);

for(int i=0 ; i < n ; i++)
{

  dp[i][0] += L[i][0];
}

//matrix_debug(dp,n,1);
//printf("%lf\n",c );

// Numerator
  matrix_multiplication(
   IN, // Pointer to matrix A
   x, // Pointer to matrix B
   num, // Pointer to matrix C
   mi,
   n,
   1,
   0,
   0
  );


  for(int i=0 ; i < mi ; i++)
  {
    num[i][0] = P_INEQUALITY->b[i] - num[i][0];

  }


//matrix_debug(num,mi,1);

// Denominator

for(int i = 0 ; i<n ; i++)
{
  aux[i][0] = dp[i][0]- x[i][0];

}
//matrix_debug(aux,n,1);


matrix_multiplication(
 IN, // Pointer to matrix A
 aux, // Pointer to matrix B
 den, // Pointer to matrix C
 mi,
 n,
 1,
 0,
 0
);
//matrix_debug(den,mi,1);

lambda[0]=1.00;
lambda[1]=1.00;

 //matrix_debug(den,mi,1);

// for(int i = 0; i <mi; i++)
// {
//   if((den[i][0] > 0.00000001) | (den[i][0] < -0.00000001 )){
//     den[i][0]=(num[i][0]/den[i][0]);
//   }
//   if(den[i][0]<0.0000001) {
//     den[i][0]=0.0;
//   }
//    if(den[i][0]>1.0) {
//     den[i][0]=.9;
//   }
//
//
// }

for(int i = 0; i <mi; i++)
{
  if((den[i][0] > 0.00000001) | (den[i][0] < -0.00000001 )){
    den[i][0]=fabs(num[i][0]/den[i][0]);
  }else {     den[i][0]=1;}
}





 //matrix_debug(den,mi,1);


for(int i = 0; i <mi; i++)
{
  if(  den[i][0]<lambda[0])
  {
    lambda[0]=den[i][0];
  }

}

 //printf(" %lf \n",lambda[0]);

 c=0;

if(lambda[0]!=0){
theta = (double) (double)rand()/RAND_MAX * lambda[0];
// printf(" %lf \n",lambda[0]);
//
//printf(" %lf \n",theta);

for(int i = 0 ; i < n ; i++)
{
  x[i][0]  = (1-theta) *x[i][0] + theta*dp[i][0];
  x[i][0] = x[i][0];
  c += x[i][0];
}
  printf("\n Norma del vector :%lf", c);
 matrix_debug(x,n,1);
}

//matrix_debug(x,n,1);
// // this is for standariaztion
// for(int i = 0 ; i < n ; i++)
// {
//   x[i][0]  = x[i][0] + theta*dp[i][0];
//   if(x[i][0]<0)  control+=-x[i][0];
//   if(x[i][0]>=0)  control+=x[i][0];
//
// }
//
// for(int i = 0 ; i < n ; i++)
// {
//   if(x[i][0]<0) x[i][0]  = -(x[i][0]/control);
//   if(x[i][0]>=0) x[i][0]  =  x[i][0]/control;
//
//
// }



}


  // Free mallocs
  free(P_EQUALITY->a);
  free(P_INEQUALITY->a);
  free(P_EQUALITY->b);
  free(P_INEQUALITY->b);
  return 0;
}
