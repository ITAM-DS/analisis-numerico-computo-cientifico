#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <csvparser.h>
#include "matrix.h"

double average(matrix *m, int col);
double variance(matrix *m, int col, double average);
void free_matrix(matrix *m);

int main() {
  CsvParser *csvparser = CsvParser_new("train.csv", ",", 1);
  const CsvRow *header = CsvParser_getHeader(csvparser);
  if (header == NULL) {
    printf("%s\n", CsvParser_getErrorMessage(csvparser));
    return 1;
  }

  matrix *m = malloc(sizeof(matrix));
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

  const char **headerFields = CsvParser_getFields(header);
  double *averages = calloc(m->cols, sizeof(double));
  double *std_deviations = calloc(m->cols, sizeof(double));
  for(int i = 0; i < m->cols; i++) {
    averages[i] = average(m, i);
    std_deviations[i] = sqrt(variance(m, i, averages[i]));
    printf("Field: %s\n", headerFields[i]);
    printf("Average: %*f\n", 5, averages[i]);
    printf("Standard deviation: %*f\n", 5, std_deviations[i]);
    printf("\n");
  }
  printf("\n");
  printf("Total rows: %zu\n", m->rows);
  printf("Total cols: %zu\n", m->cols);

  free(averages);
  free(std_deviations);
  free_matrix(m);
  CsvParser_destroy(csvparser);
  return 0;
}

double average(matrix *m, int col) {
  double sum = 0.0;
  for(int i = 0; i < m->rows; i++)
    sum += m->vectors[i][col];

  return sum / (double)m->rows;
}

double variance(matrix *m, int col, double average) {
 double sum = 0.0;
 for(int i = 0; i < m->rows; i++)
   sum += pow((m->vectors[i][col] - average), 2);

  return sum / (double)m->rows;
}

void free_matrix(matrix *m) {
  for(int i = 0; i < m->rows; i++)
    free(m->vectors[i]);
  free(m);
}