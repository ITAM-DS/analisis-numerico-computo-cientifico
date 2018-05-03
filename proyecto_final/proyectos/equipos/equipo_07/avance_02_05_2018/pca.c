#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <csvparser.h>
#include "matrix.h"

double average(matrix *m, int col);
double variance(matrix *m, int col, double average);
void free_rows(matrix *m);

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
  CsvRow **vectors_ptr =  malloc(sizeof(CsvRow*) * 1);
  CsvRow *row;
  while ((row = CsvParser_getRow(csvparser)) ) {
    vectors_ptr[m->rows] = row;
    vectors_ptr = realloc(vectors_ptr, (++m->rows + 1) * sizeof(CsvRow));
  }
  m->vectors = vectors_ptr;
  
  const char **headerFields = CsvParser_getFields(header);
  for(int i = 0; i < m->cols; i++) {
    float avg =  average(m, i);
    float std_deviation = sqrt(variance(m, i, avg));
    printf("Field: %s\n", headerFields[i]);
    printf("Average: %*f\n", 5, avg);
    printf("Standard deviation: %*f\n", 5, std_deviation);
    printf("\n");
  }
  printf("\n");
  printf("Total rows: %zu\n", m->rows);
  printf("Total cols: %zu\n", m->cols);
  
  for(int i = 0; i < m->rows; i++) {
  }
  free_rows(m);
  free(m);
  CsvParser_destroy(csvparser);
  return 0;
}

double average(matrix *m, int col) {
  double sum = 0.0;
  for(int i = 0; i < m->rows; i++) {
    const char **rowFields = CsvParser_getFields(m->vectors[i]);
    sum += atof(rowFields[col]);
  }
  return sum / (double)m->rows;
}

double variance(matrix *m, int col, double average) {
 double sum = 0.0;
  for(int i = 0; i < m->rows; i++) {
    const char **rowFields = CsvParser_getFields(m->vectors[i]);
    sum += pow(atof(rowFields[col]) - average, 2);
  }
  return sum / (double)m->rows;
}

void free_rows(matrix *m) {
  for(int i = 0; i < m->rows; i++)
    CsvParser_destroy_row(m->vectors[i]);
}
