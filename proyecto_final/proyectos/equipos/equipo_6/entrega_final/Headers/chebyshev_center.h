#include <stdio.h>
#include <stdlib.h>
#include "../lpsolve/lp_lib.h"
#include <math.h>
// Define number of variables
static unsigned NUMBER_VARIABLES;
// Define number of equalities and inequalities
static unsigned NUMBER_EQUALITIES;
static unsigned NUMBER_INEQUALITIES;
// Structs of restrictions
static Plinear_eq P_EQUALITY;
static Plinear_ineq P_INEQUALITY;

double norm_2(int N, double x[N]) {
  double sum = 0.0;
  for (int i = 0; i < N; i++) {
    sum += pow(x[i], 2.0);
  }
  return sqrt(sum);
}

void get_initvalue(double x_0[NUMBER_VARIABLES]) {
  lprec *lp;
  // Define empty model  printf("hola\n");

  lp = make_lp(0, 0);

  set_col_name(lp, (NUMBER_VARIABLES+1), "R");
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

  get_variables(lp, x_0);
}
