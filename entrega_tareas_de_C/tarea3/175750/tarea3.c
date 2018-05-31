// Tarea 3: Analisis numerico y optimizacion
// Autor: Victor Augusto Samayoa Donado
// Descripcion: Este programa imprime los valores de las entradas impares, así como las direcciones de memoria impares de estas.


#include<stdio.h>

// Para el caso unidimensional, será suficiente con inicializar lso bucles en 1 y dar pasos de 2 en 2.
// PAra el caso bidimensional, los impares serán cuando el mpodulo de la suma de los dos indices sea 1


int main(){
	int p[10];	//Se inicializa el arreglo
	int i; 		//Se define la variable del contador
	
	//iniciamos el arreglo
	for(i=0; i < 10; i++){
		p[i] = (-1*i) - 1;
	}
	//Imprimimos al arreglo
	 for(i=1; i < 10; i+=2){
            printf("p[%d] = %d\n",i,p[i]);
        }
	
	//Imprimimos las direcciones de memoria
        for(i=1; i < 10; i+=2){
           printf("&p[%d] = %p\n",i,&p[i]);
        }

	//Arreglo multidimensional
	int arreglo_multidimensional[2][3];
	int k = 1;
	int j;
	//Asignamos los valores en el arreglo multidimensional
        for(i=0; i < 2; i++){
                for(j=0; j < 3; j++){
                	arreglo_multidimensional[i][j] = (k * -1);
            			k++;
                }
         }

	//Impresion de las variables
	k = 0;
	for(i=0; i < 2; i++){
		for(j=0; j < 3; j++){
            if((i+j)%2 == 1)
             	{
					printf("p[%d][%d] = %d\n",i, j, arreglo_multidimensional[i][j]);
					}
			k++;
			}
		}

	//Imprimimos las direcciones de memoria
        k = 0;
	for(i=0; i < 2; i++){
           for(j=0; j < 3; j++){
		if((i+j)%2 == 1){
                printf("&p[%d][%d] = %p\n",i, j, &arreglo_multidimensional[i][j]);
                }
		k++;
           }
	}

}
