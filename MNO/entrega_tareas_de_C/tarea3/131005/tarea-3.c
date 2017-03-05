#include<stdio.h>

void imprimeArreglo (int*, int, int);
void imprimeDireccion (int*, int, int);

int main(){
	int arreglo[10] = {-5, -4, -3, -2, -1, 1, 2, 3, 4, 5};
	int arreglomult[2][5] = {{1, 2, 3, 4, 5},{-1, -2, -3, -4, -5}};
	int largo;
	int ancho;
	int i;

	largo = sizeof(arreglo)/sizeof(arreglo[0]);
	ancho = 0;

	printf("Arreglo \n");
	imprimeArreglo(&arreglo, largo, ancho);
	printf("Direcciones \n");
	imprimeDireccion(&arreglo, largo, ancho);

	largo = sizeof(arreglomult)/sizeof(arreglomult[0]);
	ancho = sizeof(arreglomult[0])/sizeof(arreglomult[0][0]);

	printf("Arreglo mult \n");
	imprimeArreglo(&arreglomult, largo, ancho);
	printf("Direcciones mult \n");
	imprimeDireccion(&arreglomult, largo, ancho);
}

void imprimeArreglo (int *dir, int largo, int ancho){
	int i;
	int j;
	int aux = 0;
	if (ancho == 0){
		for (i = 0; i < largo; i++){
			if (i%2 == 1)
				printf("p[%d] = %d \n", i, *(dir + i));
			}
	} else {
		for (i = 0; i < largo; i++){
			for (j = 0; j < ancho; j++){
				if (aux%2 == 1){
					printf("p[%d][%d] = %d\n", i, j, *(dir + aux));
				}
				aux++;
			}
		}
	}
}

void imprimeDireccion (int *dir, int largo, int ancho){
	int i;
	int j;
	int aux = 0;
	if (ancho == 0){
		for (i = 0; i < largo; i++){
			if (i%2 == 1)
				printf("p[%d] = %p \n", i, dir +i );
		}
	} else {
		for (i = 0; i < largo; i++){
			for (j = 0; j < ancho; j++){
				if (aux%2 == 1){
					printf("p[%d][%d] = %p\n", i, j, dir + aux);
				}
				aux++;
			}
		}
	}
}
