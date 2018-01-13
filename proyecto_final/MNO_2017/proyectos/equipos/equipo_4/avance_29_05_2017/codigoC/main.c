/*
 * main.c
 *
 *  Created on: Apr 15, 2017
 *      Author: Javier Quiroz, Fernanda Tellez, Lizbeth Contreras
 */
// compilar con
// gcc -g -Wall main.c  toom_cook.c -o main.o -lpthread -lm 

#include <stdio.h>
#include <pthread.h>
#include "toom_cook.h"

int NDEBUG = 0;

/*
char *  z[] = {"1234567890", "1234567890", "78978978", 
               "7897879", "78979879", "34245322",
                "67867877", "1234567890", "5676567"};
*/
char *  z[] = {"1234567890123456", "1234567890123456", "8765432109876543", 
               "8765432109876543", "8765432109876543", "1111111111111111",
               "2222222222222222", "3333333333333333", "4444444444444444"};



int main(void){

int resultados[NEDEFAULT_BUFER_SIZE];


// inicializando la interface 

// Ejemplo de multiplicacion de dos numeros

    numeroteInit();
	numerote xx;
  numeroteNew(&xx, "1234567890");
  numerotePrint(&xx);
	numerote yy;
	numeroteNew(&yy, "7897879");
	numerotePrint(&yy);
	numeroteMultiply(&xx,&yy, resultados);
	print_array(resultados, "Despues de multiplicar");
    printf("\n--------------------------------------------------------------------------------------");

//  trabajando con matrices
	numeroteMatrix x;
	numeroteMatrixNew(&x,z,3,2);
	numeroteMatrixPrint(&x);
    printf("\n--------------------------------------------------------------------------------------");	
	numeroteMatrix y;
	numeroteMatrixNew(&y,z,2,3);
	numeroteMatrixPrint(&y); 
    printf("\n--------------------------------------------------------------------------------------");	
	numeroteMatrix w;
	numeroteMatrixNew(&w,z,3,3);

//  mutiplicando un renglon por una columna con pthreads	
	numeroteMatrixMultiplyPoint(&x,&y, 1,3, resultados);
	print_array(resultados, "Despues de multiplicar renglon por columna");
    printf("\n--------------------------------------------------------------------------------------");
// multiplicando dos matrices comoletas
    printf("\nVoy a multiplicar xy= w");
	//numeroteMatrixMultiplyNoThreads(&x,&y,&w);
	numeroteMatrixMultiply(&x,&y,&w);
	numeroteMatrixPrint(&w);
    printf("\n--------------------------------------------------------------------------------------");
	return 0;
}
