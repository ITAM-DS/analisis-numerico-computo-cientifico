// Impresion de valores y direcciones con C 
// Carlos S. Pérez

#include <stdio.h>

void funcion(int *x, int size, int addres_flag);
void funcion_uno(int *x, int size);
void funcion_dos(int *x, int size);

int main(){
	
	//Declaracion de arreglos iniciales  
	
	int d1array[10] = {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
	int d2array[2][3] = {{-1,-2,-3},
						{-4,-5,-6}};
	
	int size_d1  = sizeof(d1array)/sizeof(d1array[0]);
	int size_d2  = sizeof(d2array)/sizeof(d2array[0][0]);
	
	int *d1_pointer = &d1array;
	int *d2_pointer = &d2array;

	//Ejecucion de las funciones .. 
	printf("El argumento es un arreglo es de tamaño %d \n \n", size_d1);
	printf(" |-------- VALORES --------- | \n\n");
	funcion_uno(d1_pointer, size_d1);
	printf(" |-------- DIRECCIONES --------- | \n\n");
	funcion_dos(d1_pointer, size_d1);
	printf(" |-------- --------- --------- | \n\n");
	
	printf("El argumento es un arreglo es de tamaño %d \n \n", size_d2);
	printf(" |-------- VALORES --------- | \n\n");
	funcion_uno(d2_pointer, size_d2);
	printf(" |-------- DIRECCIONES --------- | \n\n");
	funcion_dos(d2_pointer, size_d2);
	printf(" |-------- --------- --------- | \n\n");
	return 0;
}

// Funcion Base 
void funcion(int *x, int size, int addres_flag){
	int i;
		for (i = 0 ; i < size; i++){
			// Imprimir solo pares!
			if(i%2 == 0)
				if (addres_flag == 0){ 
				//	printf(" |-------- array_pos | array_val --------- | \n\n");
					printf(" | array[%d] | %d | \n", i, *(x+i));
				}else{
					printf(" | &array[%d] | %p | \n", i, x+i );
				}
		}
}

// Funcion Base 1
void funcion_dos (int *x, int size){
	return funcion(&x, size, 1);
}


// Funcion Base 2
void funcion_uno (int *x, int size){
	return funcion(&x, size, 0);
}