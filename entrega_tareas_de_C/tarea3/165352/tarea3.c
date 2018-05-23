#include <stdio.h>

//Funcion que imprime valores de vectores y matrices
double imprime_valores(int *pointer, int size);

//Funcion que imprime direccion de los valores de vectores y matrices
double imprime_direcciones(int *pointer, int size);

int main () {

	//Declaramos variables
   	int vector[5];
   	int matriz[3][4];
	int tamano_matriz, tamano_vector;
	int i, j;

	//Obtenemos numero de elementos del vector, aunque en este caso lo definimos nosotros, asi que es un tanto redundante
	tamano_vector = sizeof(vector)/sizeof(vector[0]);

	printf("\n");
	//Pedimos al usuario ingrese los valores del vector
	for(i = 0; i < tamano_vector; i++){
		printf("Ingresa vector[%d]", i);
		scanf("%d", &vector[i]);
	}
	printf("\n");

	//Imprime los valores del vector usando la funcion definida
	imprime_valores(vector, tamano_vector);
	//Imprime las direcciones del vector usando la funcion definida
	imprime_direcciones(vector, tamano_vector);

	//Obtenemos numero de elementos de la matriz, aunque en este caso la definimos nosotros, asi que es un tanto redundante
	tamano_matriz = (sizeof(matriz)/sizeof(matriz[0]))*(sizeof(matriz[0])/sizeof(matriz[0][0])); 

	//Pedimos al ususario ingrese los valores de la matriz
	for(i = 0; i < sizeof(matriz)/sizeof(matriz[0]); i++){
		for(j = 0; j < sizeof(matriz[0])/sizeof(matriz[0][0]); j++){
			printf("Ingresa matriz[%d][%d]:", i, j);
         		scanf("%d", &matriz[i][j]);
                }
        }
	printf("\n");
	//Imprime los valores de la matriz usando la funcion definida
	imprime_valores(matriz[0], tamano_matriz);
	//Imprime las direcciones de la matriz usando la funcion definida
	imprime_direcciones(matriz[0], tamano_matriz);
}

double imprime_valores(int *pointer, int size) {

	int i;

	printf("Las entradas impares son:\n");
	for (i = 1; i < size; i = i + 2){
     	printf("p[%d] = %d\n",i, pointer[i]);
   	}
	printf("\n");
}

double imprime_direcciones(int *pointer, int size) {

        int i;

	printf("Las direcciones de memoria en las posiciones impares son:\n");
        for (i = 1; i < size; i = i + 2){
        printf("&p[%d] = %p\n",i, &pointer[i]);
        }
	printf("\n");
}

