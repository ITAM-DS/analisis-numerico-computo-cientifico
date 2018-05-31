/*
For the first version we will focus on making the hit and run sampler for discrete and finite
probability distributions
*/

 /*--------------------- Setting Parameteres -------------------*/

// Libraries
#include <stdio.h>
#include <stdlib.h>

// Headers
#include "hr1.h"

// For reading constraint matrix from text files
#define MATRIX_EQ   "m_eq.txt"
#define MATRIX_INEQ "m_ineq.txt"

// For reading constraint vector form txt files
#define VECTOR_EQ   "v_eq.txt"
#define VECTOR_INEQ "v_ineq.txt"


// Define skeleton for restrictions
static linear_eq    EQ;
static linear_ineq  INEQ;

// Define pointers to restrictions
static Plinear_eq   P_EQ;
static Plinear_ineq P_INEQ;

// Define number of variables
static unsigned NUMBER_VARIABLES=2;

// Define number of equalities and inequalities
static unsigned NUMBER_EQUALITIES = 2;
static unsigned NUMBER_INEQUALITIES = 2;


 /*--------------------- Setting Parameteres -------------------*/


void define_pointers(){

P_EQ = &EQ;
P_INEQ = &INEQ;

}


void define_parameters(){

 P_EQ   -> var= NUMBER_VARIABLES;
 P_INEQ -> var= NUMBER_VARIABLES;

 P_EQ   -> req    = NUMBER_EQUALITIES;
 P_INEQ -> rineq  = NUMBER_INEQUALITIES;

 FILE *m_eq = fopen(MATRIX_EQ,"r");
 FILE *m_ineq = fopen(MATRIX_INEQ,"r");
 FILE *v_eq = fopen(VECTOR_EQ,"r");
 FILE *v_ineq = fopen(VECTOR_INEQ,"r");

 P_EQ    -> a = (double **) malloc(sizeof(double *)*NUMBER_EQUALITIES);
 P_INEQ  -> a = (double **) malloc(sizeof(double *)*NUMBER_INEQUALITIES);

 P_EQ   -> b = (double *) malloc(sizeof(double)*NUMBER_EQUALITIES);
 P_INEQ -> b = (double *) malloc(sizeof(double)*NUMBER_INEQUALITIES);

 for(int i =0; i < NUMBER_EQUALITIES; i++){

   P_EQ->a[i] = (double *)malloc(sizeof(double)*NUMBER_VARIABLES);
   P_INEQ->a[i] = (double *)malloc(sizeof(double)*NUMBER_VARIABLES);

   fscanf(v_eq, "%lf", &(P_EQ->b[i]));
   fscanf(v_ineq, "%lf", &(P_INEQ->b[i]));

   for(int j=0; j< NUMBER_VARIABLES; j++){

     fscanf(m_eq, "%lf", &(P_EQ->a[i][j]));
     fscanf(m_ineq, "%lf", &(P_INEQ->a[i][j]));
   }
 }

}




int main(){

define_pointers();

define_parameters();



// Free mallocs
free(P_EQ->a); free(P_INEQ->a);
free(P_EQ->b); free(P_INEQ->b);
  return 0;
}
