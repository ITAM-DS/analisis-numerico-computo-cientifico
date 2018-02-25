#include<stdio.h>

//Función 1: Imprimimos las entradas impares del arreglo
void print_elements(int size, int arreglo[size]){
	for (int i = 0; i <= size; i++) {
					if (i % 2 != 0)
			 printf("posición %d, valor: %d\n",i,arreglo[i]);
	}
}

//FUNCION 2: mprimimos la dirección de memoria en las posiciones impares del arregloMVG
void print_directory(int size, int arreglo[size]){
 		 for(int i=0;i<size;i++){
					if (i % 2 != 0){
						printf("posición %i, memoria: %p\n", i, &arreglo[i]);
					}
	}
}


int main(){
	int arregloMVG[10]; //declaración y definición del arregloMVG
	int i;

	//Inicialización del arregloMVG empezando en el 3:
	for(i=0;i<11;i++){
		arregloMVG[i] = i+3;
	}

	//Imprimimos al arregloMVG
		printf("\n\nEntradas del arregloMVG que empieza en el 3:\n");
	for(i=0;i<11;i++){
		printf("arregloMVG[%d] = %d\n",i,arregloMVG[i]);
	}

	//FUNCION 1: mprimimos elementos en las posiciones impares del arregloMVG
	 printf("\n\nElementos del arregloMVG en las posiciones IMPARES:\n");
	 print_elements(10,arregloMVG);

  //FUNCION 2: mprimimos la dirección de memoria en las posiciones impares del arregloMVG
	 printf("\n\nDirección de memoria del arregloMVG en las posiciones IMPARES:\n");
   print_directory(10,arregloMVG);

	return 0;
}
