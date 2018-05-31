#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

matrix2d *allocate_matrix2d(int rows, int cols) {
  matrix2d *m = malloc(sizeof(matrix2d));
  m->rows = rows;
  m->cols = cols;
  double **vector_ptr = malloc(sizeof(double*) * rows);
  for(int i = 0; i < rows; i++)
    vector_ptr[i] = calloc(cols, sizeof(double));
  m->vectors = vector_ptr;
  return m;
};

matrix *allocate_matrix(int rows, int cols) {
  matrix *m = malloc(sizeof(matrix));
  m->rows = rows;
  m->cols = cols;
  m->vectors = malloc(sizeof(double*) * (m->rows * m->cols));
  return m;
};

void free_matrix2d(matrix2d *m) {
  for(int i = 0; i < m->rows; i++)
    free(m->vectors[i]);
  free(m);
}

void free_matrix(matrix *m) {
  free(m->vectors);
  free(m);
}

void print_matrix2d(matrix2d *m) {
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++)
      printf("%.4f\t", m->vectors[i][j]);
    printf("\n");
  }
}

void print_matrix(matrix *m) {
  int i = 0;
  int j = m->cols;
  int total = m->rows * m->cols;
  while (i < total) {
    printf("%.4f\t", m->vectors[i++]); 
    if (i >= j) {
      printf("\n");
      j = j + m->cols;
    }
  }
}