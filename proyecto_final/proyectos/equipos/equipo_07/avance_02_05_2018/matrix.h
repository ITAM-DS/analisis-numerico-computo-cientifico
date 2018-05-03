#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h> 
#include <csvparser.h>

typedef struct matrix {
  size_t cols;
  size_t rows;
  CsvRow **vectors;
} matrix;

typedef struct normalized_matrix {
  size_t cols;
  size_t rows;
  float **vectors;
} normalized_matrix;

