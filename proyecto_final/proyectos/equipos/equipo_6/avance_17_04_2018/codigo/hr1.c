/*
For the first version we will focus on making the hit and run sampler for
discrete and finite probability distributions
*/

/*--------------------- Setting Parameteres -------------------*/

// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Headers
#include "hr1.h"
#include "lpsolve/lp_lib.h"
// For reading constraint matrix from text files
#define MATRIX_EQ "m_eq.txt"
#define MATRIX_INEQ "m_ineq.txt"

// For reading constraint vector form txt files
#define VECTOR_EQ "v_eq.txt"
#define VECTOR_INEQ "v_ineq.txt"

// Define skeleton for restrictions
static linear_eq EQUALITY;
static linear_ineq INEQUALITY;

// Define pointers to restrictions
static Plinear_eq P_EQUALITY;
static Plinear_ineq P_INEQUALITY;

// Define number of variables
static unsigned NUMBER_VARIABLES = 3;

// Define number of equalities and inequalities
static unsigned NUMBER_EQUALITIES = 1;
static unsigned NUMBER_INEQUALITIES = 1;

/*--------------------- Setting Parameteres -------------------*/

double norm_2(int N, double x[N]) {
  double sum = 0.0;
  for (int i = 0; i < N; i++) {
    sum += pow(x[i], 2.0);
  }
  return sqrt(sum);
}

void define_pointers() {

  P_EQUALITY = &EQUALITY;
  P_INEQUALITY = &INEQUALITY;
}

void define_parameters() {

  P_EQUALITY->var = NUMBER_VARIABLES;
  P_INEQUALITY->var = NUMBER_VARIABLES;

  P_EQUALITY->req = NUMBER_EQUALITIES;
  P_INEQUALITY->rineq = NUMBER_INEQUALITIES;

  FILE *m_eq = fopen(MATRIX_EQ, "r");
  FILE *m_ineq = fopen(MATRIX_INEQ, "r");
  FILE *v_eq = fopen(VECTOR_EQ, "r");
  FILE *v_ineq = fopen(VECTOR_INEQ, "r");

  P_EQUALITY->a = (double **)malloc(sizeof(double *) * NUMBER_EQUALITIES);
  P_INEQUALITY->a = (double **)malloc(sizeof(double *) * NUMBER_INEQUALITIES);

  P_EQUALITY->b = (double *)malloc(sizeof(double) * NUMBER_EQUALITIES);
  P_INEQUALITY->b = (double *)malloc(sizeof(double) * NUMBER_INEQUALITIES);

  for (int i = 0; i < NUMBER_EQUALITIES; i++) {

    P_EQUALITY->a[i] = (double *)malloc(sizeof(double) * NUMBER_VARIABLES);
    P_INEQUALITY->a[i] = (double *)malloc(sizeof(double) * NUMBER_VARIABLES);

    fscanf(v_eq, "%lf", &(P_EQUALITY->b[i]));
    fscanf(v_ineq, "%lf", &(P_INEQUALITY->b[i]));

    for (int j = 0; j < NUMBER_VARIABLES; j++) {
      fscanf(m_eq, "%lf", &(P_EQUALITY->a[i][j]));
      fscanf(m_ineq, "%lf", &(P_INEQUALITY->a[i][j]));
    }
  }
}

// Gets Chebyshev center

void get_initvalue() {
  lprec *lp;
  // Define empty model
  lp = make_lp(0, 0);
  set_col_name(lp, 1, "x_1");
  set_col_name(lp, 2, "x_2");
  set_col_name(lp, 3, "x_3");
  set_col_name(lp, 4, "R");
  // Objective function
  double obj_vector[NUMBER_VARIABLES + 2];
  for (int i = 0; i < (NUMBER_VARIABLES + 1); i++) {
    obj_vector[i] = 0.0;
  }
  obj_vector[(NUMBER_VARIABLES + 1)] = 1.0;
  // Set objective function
  set_obj_fn(lp, obj_vector);
  set_add_rowmode(lp, TRUE);
  // Set equality restrictions
  double aux[NUMBER_VARIABLES + 2];
  for (int i = 0; i < NUMBER_EQUALITIES; i++) {
    for (int j = 0; j < NUMBER_VARIABLES; j++) {
      aux[j + 1] = (P_EQUALITY->a[i][j]);
    }
    // ||a_i||_2
    aux[(NUMBER_VARIABLES + 1)] = 0;
    add_constraint(lp, aux, EQ, P_EQUALITY->b[i]);
  }
  // Set inequality restrictions
  for (int i = 0; i < NUMBER_INEQUALITIES; i++) {
    for (int j = 0; j < NUMBER_VARIABLES; j++) {
      aux[j + 1] = (P_INEQUALITY->a[i][j]);
    }
    // ||a_i||_2
    aux[(NUMBER_VARIABLES + 1)] = norm_2(NUMBER_VARIABLES, P_INEQUALITY->a[i]);
    add_constraint(lp, aux, LE, P_INEQUALITY->b[i]);
  }
  // Positivity conditions
  for (int i = 0; i < NUMBER_VARIABLES; i++) {
    for (int j = 0; j < NUMBER_VARIABLES; j++) {
      if(i == j){
        aux[j+1] = 1.0;
      } else {
        aux[j+1] = 0.0;
      }
    }
    aux[(NUMBER_VARIABLES + 1)] = -1;
    add_constraint(lp, aux, GE, 0);
  }

  // End model definition
  set_add_rowmode(lp, FALSE);
  set_maxim(lp);
  // write_lp(lp,"lp.model");
  solve(lp);
  // print_solution(lp, 1);
}

/*
 Box-Muller normal generator: Generates a vector from independent normal distributions.
 Receives:   a pointer to an array of doubles with the same size as the number of NUMBER_VARIABLES.
 Returns:    by pointer a normalized vector that represents the direction.

*/

void normal_generator(double *d){

/*The algorith creates them in pairs, so one entry may need to be discarded */
  unsigned discard = NUMBER_VARIABLES % 2;
  unsigned discard_index = rand()%NUMBER_VARIABLES ;
  double U1, U2, W, mult;

  for(int i = 0; i< NUMBER_VARIABLES ; i +=2 )
  {
    do
    {
      U1 = -1 + ((double) rand () / RAND_MAX) * 2;
      U2 = -1 + ((double) rand () / RAND_MAX) * 2;
      W = pow (U1, 2) + pow (U2, 2);
    }while (W >= 1 || W == 0);

    mult = sqrt ((-2 * log (W)) / W);

    if( discard & (discard_index == i || discard_index == i+1 ))
    {
        d[i] = U1 * mult;
        i--;
    }else{
        d[i] = U1 * mult;
        d[i+1] = U2 * mult;
    }
  }
  double a =0;

  for(int j = 0 ; j<NUMBER_VARIABLES; j++)
  {
    a += d[j];
  }

  for(int j = 0 ; j<NUMBER_VARIABLES; j++)
  {
    d[j] = d[j]/a;
  }

} // END of normal_generator 

int main() {

  define_pointers();

  define_parameters();

  // Free mallocs
  free(P_EQUALITY->a);
  free(P_INEQUALITY->a);
  free(P_EQUALITY->b);
  free(P_INEQUALITY->b);
  return 0;
}
