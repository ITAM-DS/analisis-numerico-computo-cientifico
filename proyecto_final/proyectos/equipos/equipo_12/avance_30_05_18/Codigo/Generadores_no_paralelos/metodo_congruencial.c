//Notas: para que el algoritmo funcione es necesario que se cumplan las siguientes condiciones en los parametros
// 0<m es el "modulo"
// 0<a<m es el "multiplicador"
// 0<c<m es el "incremento"
// 0<x0<m es la "semilla" or "valor inicial"
#include<stdio.h>

main(){
	int tam = 1000;
        int X[tam]; //iniciamos el arreglo
        int i; //iniciamos el contador
        int a = 5;
	int m = 1034;
	int c = 45;
	int x0 = 7;
	X[0] = ((a*x0) + c) % m;
	//Iniciamos la secuencia de numeros aleatorios
        for(i=1;i<tam;i++){
                X[i] =  ((a*X[i-1]) + c) % m;
        }
        //Imprimimos al arreglo
        for(i=0;i<tam;i++){
                printf("X[%d] = %d\n",i,X[i]);
        }
}

