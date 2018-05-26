#include <stdio.h>
#include <stdlib.h>

typedef struct matrix2d {
  int cols;
  int rows;
  double **vectors;
} matrix2d;

typedef struct matrix {
  int cols;
  int rows;
  double *vectors;
} matrix;

matrix2d *allocate_matrix2d(int rows, int cols);
matrix *allocate_matrix(int rows, int cols);
void free_matrix2d(matrix2d *m);
void free_matrix(matrix *m);
void print_matrix2d(matrix2d *m);
void print_matrix(matrix *m);
void print_line_header(int cols);