#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#if defined(__linux__)
  #include <cblas.h>
#elif defined(__APPLE__) && defined(__MACH__)
  #include <Accelerate/Accelerate.h>
#else
  #error Unknown environment!
#endif
#include <csvparser.h>
#include "matrix.h"

double average(matrix2d *m, int col);
double variance(matrix2d *m, int col, double average);
void normalize_matrix(matrix2d *m, matrix *c);
                   
int main() {
  CsvParser *csvparser = CsvParser_new("train-short.csv", ",", 1);
  const CsvRow *header = CsvParser_getHeader(csvparser);
  if (header == NULL) {
    printf("%s\n", CsvParser_getErrorMessage(csvparser));
    return 1;
  }

  matrix2d *m = malloc(sizeof(matrix2d));
  m->cols = CsvParser_getNumFields(header);
  m->rows = 0;
  double **vectors_ptr = malloc(sizeof(double*) * 1);
  CsvRow *row;
  while ((row = CsvParser_getRow(csvparser)) ) {
    const char **rowFields = CsvParser_getFields(row);
    double *vector = calloc(m->cols, sizeof(double));
    for(int i = 0; i < m->cols; i++)
      vector[i] = atof(rowFields[i]);
    vectors_ptr[m->rows] = vector;
    vectors_ptr = realloc(vectors_ptr, (++m->rows + 1) * sizeof(double));
    CsvParser_destroy_row(row);
  }
  m->vectors = vectors_ptr;

  matrix *nm = allocate_matrix(m->rows, m->cols);
  normalize_matrix(m, nm);
  //print_matrix2d(m);
  print_matrix(nm);
  free_matrix(nm);
  free_matrix2d(m);
  CsvParser_destroy(csvparser);
  return 0;
}

double average(matrix2d *m, int col) {
  double sum = 0.0;
  for(int i = 0; i < m->rows; i++)
    sum += m->vectors[i][col];

  return sum / (double)m->rows;
}

double variance(matrix2d *m, int col, double average) {
 double sum = 0.0;
 for(int i = 0; i < m->rows; i++)
   sum += pow((m->vectors[i][col] - average), 2);

  return sum / (double)m->rows;
}

void normalize_matrix(matrix2d *m, matrix *c) {
  double *averages = calloc(m->cols, sizeof(double));
  double *std_deviations = calloc(m->cols, sizeof(double));
  for(int i = 0; i < m->cols; i++) {
    averages[i] = -average(m, i);
    std_deviations[i] = sqrt(variance(m, i, averages[i]));
  }

  int incx = 1;
  int incy = 1;
  double alpha = 1.0;
  for(int j =0; j < m->rows; j++)
    cblas_daxpy(m->cols, alpha, averages, incx, m->vectors[j], incy); 

  matrix *a = allocate_matrix(m->rows, m->cols);
  int k = 0;
  for (int i = 0; i < m->rows; i++)
    for (int j = 0; j < m->cols; j++)
      a->vectors[k++] = m->vectors[i][j];

  matrix *b = allocate_matrix(m->cols, m->cols); 
  k = 0;
  for (int i = 0; i < m->cols; i++)
    for (int j = 0; j < m->cols; j++)
      b->vectors[k++] = (j == i) ? 1.0/std_deviations[i] : 0.0;
  
  k = 0;
  for (int i = 0; i < m->rows; i++)
    for (int j = 0; j < m->cols; j++)
      c->vectors[k++] = 0.0;
  
  double beta = 0.0;
  cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
               a->rows, b->cols, a->cols, alpha, a->vectors, a->rows, 
               b->vectors, b->cols, beta, c->vectors, c->rows);
  
  free(averages);
  free(std_deviations);
  free_matrix(a);
  free_matrix(b);
}
