/*
 * main.c
 *
 *  Created on: Apr 15, 2017
 *      Author: javier
 */

#include <stdio.h>
#include "toom_cook.h"

char *  z[] = {"123445567", "456546456", "78978978", 
                "7897879", "78979879", "34245322",
                "67867877", "78998789", "5676567"};

int main(void){

//	numeroteInit();
//	numerote a;
//	numeroteNew(&a, "1234567890123456789012345");
//	numerotePrint(&a);
//	printf("last error code %s", getlastError() );


	numeroteInit();
	numerote x;
	numeroteNew(&x, "931275469");
	numerotePrint(&x);
	numerote y;
	numeroteNew(&y, "897512436");
	numerotePrint(&y);
	numeroteMultiply(&x,&y);

//trabajando con matrices
	numeroteMatrix w;
	numeroteMatrixNew(&w,z,3,2);
	numeroteMatrixPrint(&w); 

	return 0;
}
