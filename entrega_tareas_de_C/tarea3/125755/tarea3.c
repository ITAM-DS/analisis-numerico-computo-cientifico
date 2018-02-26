// Tarea 3
// Luis Fernando Cantú Díaz de León
// CU 000125755

#include<stdio.h>

void imprime_datos(int *arreglo, int array_size) {
  int i=0;
  // Imprimimos los elementos impares del arreglo.
  printf("Valores:\n");
  for(i = 0; i < (array_size); i++) {
    if( i % 2 != 0) {printf("p[%i] = %d\n", i, *(arreglo + i));}
  }
  printf("\n");
}

void imprime_direcciones(int *arreglo, int array_size) {
  int i=0;
  // Imprime las direcciones de elementos impares.
  printf("Direcciones en memoria:\n" );
  for(i = 0; i < (array_size); i++) {
    if( i % 2 != 0) {printf("&p[%i] = %p\n", i, (arreglo+i));}
  }
  printf("\n");
}

int main(){
	int array[10];
	int i,j,k;
  int *p;
  p = array;
  int disp[2][3];
  int *po;
  po = disp;
	//Inicialización del arreglo.
	for(i=0;i<10;i++){
		array[i] = -(i+1);
	}
  // Inicializamos el arreglo multidim.
  i = 0;
  for(k=0; k<2; k++) {
     for(j=0;j<3;j++) {
       disp[k][j] = -(i + 1);
       i = i + 1;
     }
  }
  imprime_datos(p,10);
  imprime_direcciones(p,10);

  imprime_datos(po,6);
  imprime_direcciones(po,6);
	return 0;
}
