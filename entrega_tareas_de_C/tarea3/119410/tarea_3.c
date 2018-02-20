#include<stdio.h>

void print_values(int *arreglo, int longitud){
	for(int i=1; i<longitud; i=i+2){
		printf("valor posicion %d = %d\n", i, *(arreglo + i));
  	}
}

void print_dir(int *arreglo, int longitud){
	for(int i=1; i<longitud; i=i+2){
		printf("valor de posicion %d en dirección de memoria: %p\n", i, arreglo + i);
  	}
}


int main(){
	// Definir arreglos
	int arreglo_1[10] = {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
  	int arreglo_2[2][3] = {-1,-2,-3,-4,-5,-6};

  	// Apuntador arreglo 1
  	int *pointer_1 = arreglo_1;

  	// Llamar funciones
  	printf("Arreglo unidimensional \n");
        printf("Primera función: valores \n");
  	print_values(pointer_1, sizeof(arreglo_1)/sizeof(arreglo_1[0]));
        printf("Segunda función: direcciones de memoria \n");
	print_dir(pointer_1, sizeof(arreglo_1)/sizeof(arreglo_1[0]));

	// Apuntador arreglo 2
  	int *pointer_2 = arreglo_2[0];

  	// Llamar funciones
  	printf("Arreglo multidimensional \n");
        printf("Primera función: valores \n");
  	print_values(pointer_2, sizeof(arreglo_2)/sizeof(arreglo_2[0][0]));
        printf("Segunda función: direcciones de memoria \n");
	print_dir(pointer_2, sizeof(arreglo_2)/sizeof(arreglo_2[0][0]));
	return 0;
}
