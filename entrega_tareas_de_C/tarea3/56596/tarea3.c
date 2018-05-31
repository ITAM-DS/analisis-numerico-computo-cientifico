#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h> 

typedef struct Matrix {
  int rows;
  int cols;
  int **data;
} Matrix;

Matrix *allocate_matrix(int rows, int cols) {
  Matrix *matrix = malloc(sizeof(Matrix));
  matrix->rows = rows;
  matrix->cols = cols;
  int **data_ptr = malloc(sizeof(int*) * rows);
  for(int i = 0; i < rows; i++)
    data_ptr[i] = calloc(cols, sizeof(int));
  matrix->data = data_ptr;
  return matrix;
};

Matrix *build_matrix(int rows, int cols) {
  Matrix *matrix = allocate_matrix(rows, cols);
  int p = 0;
  for(int i = 0; i < rows; i++)
    for(int j = 0; j < cols; j++) {
      printf("Ingresa elemento[%d][%d]: ", i, j);
      scanf("%d", &matrix->data[i][j]);
    }
  return matrix;    
}

void print_matrix_values(Matrix *matrix) {
  printf("Los valores en las posiciones impares son:\n");
  int p = 0;
  for (int i = 0; i < matrix->rows; i++)
    for (int j = 0; j < matrix->cols; j++) {
      if (p % 2 != 0)
        printf("p[%d]=%d\n", p, matrix->data[i][j]);
      p++;
    }
}

void print_matrix_addresses(Matrix *matrix) {
  printf("Las direcciones en las posiciones impares son:\n");
  int p = 0;
  for (int i = 0; i < matrix->rows; i++) 
    for (int j = 0; j < matrix->cols; j++) {
      if (p % 2 != 0)
        printf("p[%d]=%p\n", p, &matrix->data[i][j]);
      p++;
    }
}

void free_matrix(Matrix *matrix) {
  for(int i = 0; i < matrix->rows; i++)
    free(matrix->data[i]);
  free(matrix->data);
  free(matrix);
}


int main() {
  printf("Introduce el numero de elementos del vector: ");
  int elem;
  scanf("%d", &elem);
  if (elem > 0) {
    Matrix *vector = build_matrix(1, elem);
    print_matrix_values(vector);
    print_matrix_addresses(vector);
    free_matrix(vector); 
    printf("\n\n");
  } else {
    printf("El numero de elementos debe ser >= 0\n");
    exit(EXIT_FAILURE);
  }
  
  printf("Introduce el numero filas de la matriz: ");
  int rows;
  scanf("%d", &rows);
  if (rows <= 0) {
    printf("El numero de filas debe ser >= 0\n");
      exit(EXIT_FAILURE);
  }

  int cols;
  printf("Introduce el numero columnas de la matriz: ");
  scanf("%d", &cols);
  if (cols <= 0) {
    printf("El numero de  debe ser >= 0\n");
    exit(EXIT_FAILURE);
  }
  Matrix *matrix = build_matrix(rows, cols);
  print_matrix_values(matrix);
  print_matrix_addresses(matrix);
  free_matrix(matrix);

  exit(EXIT_SUCCESS);
}
