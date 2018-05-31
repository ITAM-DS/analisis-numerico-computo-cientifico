#include<stdio.h>

void imprimir_valores(int *arreglo, int longitud){
	for(int i=1; i<longitud; i=i+2){
		printf("posicion %d, valor: %d\n", i, *(arreglo + i));
  	}
}

void imprimir_direcciones(int *arreglo, int longitud){
	for(int i=1; i<longitud; i=i+2){
		printf("posicion %d, memoria: %p\n", i, arreglo + i);
  	}
}


int main(){
	// Se crean ambos arreglos
	int arreglo_1[10] = {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
  	int arreglo_2[2][3] = {-1,-2,-3,-4,-5,-6};

  	// Pointer de primer arreglo
  	int *pointer_1 = arreglo_1;

  	// Se llaman funciones para imprimir
  	printf("Primer arreglo \n");
  	imprimir_valores(pointer_1, sizeof(arreglo_1)/sizeof(arreglo_1[0]));
	imprimir_direcciones(pointer_1, sizeof(arreglo_1)/sizeof(arreglo_1[0]));
	printf("---\n");

	// Pointer de segundo arreglo
  	int *pointer_2 = arreglo_2[0];

  	// Se llaman funciones para imprimir
  	printf("Segundo arreglo \n");
  	imprimir_valores(pointer_2, sizeof(arreglo_2)/sizeof(arreglo_2[0][0]));
	imprimir_direcciones(pointer_2, sizeof(arreglo_2)/sizeof(arreglo_2[0][0]));
	printf("---\n");
	return 0;
}