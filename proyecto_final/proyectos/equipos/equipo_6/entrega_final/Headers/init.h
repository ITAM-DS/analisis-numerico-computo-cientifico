#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
// Define number of variables
static unsigned NUMBER_VARIABLES;
// Define number of equalities and inequalities
static unsigned NUMBER_EQUALITIES;
static unsigned NUMBER_INEQUALITIES;
// For reading constraint matrix from text files
#define MATRIX_EQ "Matrices/m_eq.txt"
#define MATRIX_INEQ "Matrices/m_ineq.txt"

// For reading constraint vector form txt files
#define VECTOR_EQ "Matrices/v_eq.txt"
#define VECTOR_INEQ "Matrices/v_ineq.txt"

typedef struct linear_eq_{

// var:= number of variables ; eq:= number of restrictions
unsigned var;
unsigned req;

// a:= pointer to matrix; b:= pointer to restriction vector
double **a;
double *b;

} linear_eq, *Plinear_eq;



typedef struct linear_ineq_{


  // var:= number of variables ; eq:= number of restrictions
  unsigned var;
  unsigned rineq;

  // a:= pointer to matrix; b:= pointer to restriction vector
  double **a;
  double *b;


} linear_ineq, *Plinear_ineq;

// Define skeleton for restrictions
static linear_eq EQUALITY;
static linear_ineq INEQUALITY;

// Define pointers to restrictions
static Plinear_eq P_EQUALITY;
static Plinear_ineq P_INEQUALITY;

void set_param(param, value)
  int param;
  int value;
{
  switch(param){
    case 1:
    NUMBER_VARIABLES = value;
    break;
    case 2:
    NUMBER_EQUALITIES = value;
    break;
    case 3:
    NUMBER_INEQUALITIES = value;
    break;
  }
}

int parse_arguments(int argc, char *argv[] ){
  int arg_index = 1;
  int value;

  if(argc == 7){
    while (arg_index < argc) {
      if (!strcmp(argv[arg_index], "-V")) {
        value = atoi(argv[arg_index+1]);
        set_param(1, value);
        arg_index += 2;
        continue;
      }

      if (!strcmp(argv[arg_index], "-E")) {
        value = atoi(argv[arg_index+1]);
        set_param(2, value);
        arg_index += 2;
        continue;
      }

      if (!strcmp(argv[arg_index], "-I")) {
        value = atoi(argv[arg_index+1]);
        set_param(3, value);
        arg_index += 2;
        continue;
      }
      printf("Error:  unrecognized flag %s\n", argv[arg_index]);
      exit(-1);
    }
  } else {
    printf("Format of imput is:\n");
    printf("%s -V a -E b -I c\n", argv[0]);
    printf("a: integer number of variables.\n");
    printf("b: integer number of equality restrictions.\n");
    printf("c: integer number of inequality restrictions.\n");
    exit(-1);
  }
  return(0);
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

    fscanf(v_eq, "%lf", &(P_EQUALITY->b[i]));

    for (int j = 0; j < NUMBER_VARIABLES; j++) {
      fscanf(m_eq, "%lf", &(P_EQUALITY->a[i][j]));
    }

  }


    for (int i = 0; i < NUMBER_INEQUALITIES; i++) {

      P_INEQUALITY->a[i] = (double *)malloc(sizeof(double) * NUMBER_VARIABLES);

      fscanf(v_ineq, "%lf", &(P_INEQUALITY->b[i]));

      for (int j = 0; j < NUMBER_VARIABLES; j++) {
        fscanf(m_ineq, "%lf", &(P_INEQUALITY->a[i][j]));
      }

    }


}
