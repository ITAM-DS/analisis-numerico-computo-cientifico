#include <stdio.h>

main(){
	// Se definen los arreglos, contadores y apuntadores
	int a[10] = {-1 ,-2, -3 , -4, -5 , -6, -7, -8, -9, -10};
	int b[2][3] = {-1, -2, -3, -4, -5, -6};
	int i, j, n;
	int *pointer, *pointer2;

	// Se inicializan los apuntadores
	pointer = a;
	pointer2 = b;

	// ARREGLO
	// Se obtiene el tamaño del arreglo
	n = sizeof(a)/sizeof(a[0]);

	// Se imprime el arreglo
	printf("Arreglo ingresado:\n");
	printf("-------------------\n");

	for(i = 0; i < n; i++){
		printf("%d ",a[i]);
	}

	printf("\n\n");

	// Se imprimen las entradas impares y su ubicación
	funcion1(pointer, n);
	funcion2(pointer, n);

	printf("\n\n");

	// ARREGLO MULTIDIMIENSIONAL
	// Se obtiene el tamaño del arreglo multidimensional
	n = sizeof(b)/sizeof(b[0][0]);

	// Se imprime el arreglo multidimensional
	printf("Matriz multidimensional ingresada:\n");
	printf("-------------------\n");

	for(i = 0; i<sizeof(b)/sizeof(b[0]); i++){
		for(j = 0; j < sizeof(b[0])/sizeof(b[0][0]); j++){
			printf("%d ", b[i][j]);
		}
	printf("\n");
	}
	printf("\n\n");

	// Se imprimen las entradas impares y su ubicación
	funcion1(pointer2, n);
	funcion2(pointer2, n);
}

int funcion1(int *p, int n){
	int i;

	printf("Valores impares del arreglo:\n");
	printf("-------------------\n");

	for (i = 1; i <= n ; i = i+2){
		printf("p[%d]:", i);
		printf("%d\n", p[i]);
	}
}

int funcion2(int *p, int n){
	int i;

	printf("\nDirecciones de memoria:\n");
	printf("-------------------\n");

	for (i = 1; i <= n; i = i+2){
		printf("&p[%d]:", i);
		printf("%p\n", &p[i]);
	}
}
