#include<stdio.h>
//Carlos Castro Correa 103531
//Tarea3: Analisis Numerico ITAM

//Declaramos un funcion auxiliar para determinar si es un numero par o non
int isOdd(int num)
{
    return (num & 1);
}

main(){
	//Arreglo multidimensional
	//En esta parte, se declara la dimension del vector o arreglo multidimensional, a partir de este punto se determina el numero de renglones y columnas 
	//Este mismo codigo funciona para cualquier arreglo.
	int arreglo_multidimensional[10][1];
	int k = 1;
	int j;
	int i;
	int renglones;
	int columnas;
	//Obtenemos el numero de renglones de arreglo para el for()
	renglones = sizeof(arreglo_multidimensional)/sizeof(arreglo_multidimensional[0]);
	columnas = sizeof(arreglo_multidimensional[0])/sizeof(arreglo_multidimensional[0][0]);
	//Asignamos los valores en el arreglo multidimensional
        for(i=0;i<renglones;i++){
                for(j=0;j<columnas;j++){
                        arreglo_multidimensional[i][j] = (k * -1);
			k = k + 1;
                }
        }
	//Funcion 1
	//Impresion de las variables
	k = 0;
	for(i=0;i<renglones;i++){
		for(j=0;j<columnas;j++){
			if(isOdd(k)){
			printf("&p[%d] = %d\n",k,arreglo_multidimensional[i][j]);
			}
			k = k + 1;
		}
	}
	//Funcion 2
	//Imprimimos las direcciones de memoria
        k = 0;
	for(i=0;i<renglones;i++){
           for(j=0;j<columnas;j++){
		if(isOdd(k)){
                printf("&p[%d] = %p\n",k,&arreglo_multidimensional[i][j]);
                }
		k = k + 1;
           }
	}


}
