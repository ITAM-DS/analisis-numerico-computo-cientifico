#include <stdio.h>
#include <stdlib.h>
// Función que imprime los contenidos impares de un apuntador
void print_odd(int *x){
  // Empieza en 1, porque el 0 no es impar.
  // x[i] es para probar que el apuntador no sea NULL.
  // Suma de dos para encontrar los impares
  for(int i=1; x[i]; i+=2){
    printf("p[%i] = %i\n",i , x[i]);
  }
}
// Función que imprime las direcciones impares de un apuntador
void print_odd_address(int *x){
  // Empieza en 1, porque el 0 no es impar.
  // x[i] es para probar que el apuntador no sea NULL.
  // Suma de dos para encontrar los impares
  for(int i=1; x[i]; i+=2){
    printf("&p[%i] = %p\n", i, &x[i]);
  }
}
// Función que llena un apuntador a partir de un arreglo multidimensional.
int * fill_pointer(int n, int m,  int arreglo_mult[n][m]){
  // Tamaño total de las alocaciones de memoria.
  int tam = n * m;
  // Inicializa el apuntador.
  int *p_arr = (int*)malloc(sizeof(int) * tam);
  // Nos ayuda recorrer renglones.
  int j = 0;
  // Rellena los apuntadores.
  for(int i = 0; i < tam; i++){
    if((i - j*m)>n){
      j++;
    }
      p_arr[i] = arreglo_mult[j][(i - j*m)];
  }
  return p_arr;
}

int main(){
  // Declaración de variables.
  int *p, *p_arr;
  int arreglo_mult[2][3];
  // Inicializa locaciones de memoria.
  p = malloc(sizeof(int) * 9);
  // Ponemos contenido en el apuntador.
  p[0]=-1;
  p[1]=-2;
  p[2]=-3;
  p[3]=-4;
  p[4]=-5;
  p[5]=-6;
  p[6]=-7;
  p[7]=-8;
  p[8]=-9;
  p[9]=-10;
  // Arreglo multidimensional.
  arreglo_mult[0][0] =-1;   arreglo_mult[0][1] =-2; arreglo_mult[0][2] =-3;
  arreglo_mult[1][0] =-4;   arreglo_mult[1][1] =-5; arreglo_mult[1][2] =-6;
  // Tamaño de renglón.
  int n = sizeof(arreglo_mult)/sizeof(arreglo_mult[0]);
  // Tamaño de columna.
  int m = sizeof(arreglo_mult[0])/sizeof(arreglo_mult[0][0]);
  // LLena con direcciones de memoria el apuntador.
  p_arr = fill_pointer(n,m,arreglo_mult);
  printf("Impresión de contenido vectorial\n");
  print_odd(p);
  printf("Impresión de direcciones vectorial\n");
  print_odd_address(p);
  printf("Impresión de contenido multidimensional\n");
  print_odd(p_arr);
  printf("Impresión de direcciones multidimensional\n");
  print_odd_address(p_arr);
  return(0);
}
