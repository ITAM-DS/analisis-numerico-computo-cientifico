#include <stdio.h>
#include <stdlib.h>
#include <csvparser.h>
#include "matrix.h"

int avg(matrix *m, int col);
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
    //CsvParser_destroy_row(row);
  }
  m->vectors = vectors_ptr;
  
  const char **headerFields = CsvParser_getFields(header);
  for (int i = 0 ; i < CsvParser_getNumFields(header) ; i++)
    printf("%s\t", headerFields[i]);
  printf("\n");
  
  for(int i = 0; i < m->cols; i++) {
    printf("%*d\t", 10, avg(m, i));
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

int avg(matrix *m, int col) {
  int sum = 0;
  for(int i = 0; i < m->rows; i++) {
    const char **rowFields = CsvParser_getFields(m->vectors[i]);
    int val = atoi(rowFields[col]);
    sum += val;
  }
  return sum / m->rows;
}

void free_rows(matrix *m) {
  for(int i = 0; i < m->rows; i++)
    CsvParser_destroy_row(m->vectors[i]);
}
