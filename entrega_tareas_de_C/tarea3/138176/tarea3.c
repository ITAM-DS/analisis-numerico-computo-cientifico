
// Daniel Sharp 138176
// Tarea 3

#include<stdio.h>

// Función para imprimir los valores del arreglo utilizando un apuntador y la longitud del arreglo
void print_nones_valores(int *point, int longitud){
  point += 1;
  for(int i=1; i<=longitud; i=i+2){
      printf("p[%i]:%i\n", i, *point);
      point += 2;
  }
}

void print_nones_direcciones(int *point, int longitud){
  point += 1;
  for(int i=1; i<=longitud; i=i+2){
      printf("&p[%i]:%p\n", i, point);
      point += 2;
  }
}

int main(int argc, char const *argv[]) {
  int arreglo_singular[10] = {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
  int arreglo_multi[2][3] = {{-1,-2,-3},{-4,-5,-6}};

  int *loc_sin = arreglo_singular;
  int tam_sin = sizeof(arreglo_singular)/sizeof(arreglo_singular[0]);

  printf("----- Arreglo Singular -----\n");
  printf("--- Valores ---\n");
  print_nones_valores(loc_sin, tam_sin);
  printf("--- Direcciones ---\n");
  print_nones_direcciones(loc_sin, tam_sin);

  int *loc_mul = arreglo_multi;
  int tam_mul = sizeof(arreglo_multi)/sizeof(arreglo_multi[0][0]);

  printf("----- Arreglo Multidimensional -----\n");
  printf("--- Valores ---\n");
  print_nones_valores(loc_mul, tam_mul);
  printf("--- Direcciones ---\n");
  print_nones_direcciones(loc_mul, tam_mul);

  return 0;
}
