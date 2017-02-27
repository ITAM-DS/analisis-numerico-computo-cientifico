/*
 ============================================================================
 Name        : Tarea3.c
 Author      : Javier Quiroz
 Version     :
 Copyright   : (2017) Javier Quiroz
 Description : Practicando apuntadores y arreglos
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int print_funcion1( int *a, int tamanio ) {
	int *p = a;
	int i = 1;
	p++;

	while ( i <= tamanio ) {
		printf("p[%d]=%d\n",i, *p);
		p += 2;
		i +=2;
	}
	return EXIT_SUCCESS;
}


int print_funcion2( int *a, int tamanio ) {
	int *p = a;
	int i = 1;
	p++;

	while ( i <= tamanio ) {
		printf("&p[%d]=%p\n",i, p);
		p += 2;
		i +=2;
	}
	return EXIT_SUCCESS;
}


int main( void ) {
	int array[] = {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
	int arreglo_mult[2][3] = {{-1,-2,-3},
			                  {-4,-5,-6}};
	print_funcion1( array, sizeof(array)/sizeof(int) );
	print_funcion2( array, sizeof(array)/sizeof(int) );
	print_funcion1( *arreglo_mult, sizeof(arreglo_mult)/sizeof(int) );
	print_funcion2( *arreglo_mult, sizeof(arreglo_mult)/sizeof(int) );

	return EXIT_SUCCESS;
}
