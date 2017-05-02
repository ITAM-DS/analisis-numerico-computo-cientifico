/*
 * main.c
 *
 *  Created on: Apr 15, 2017
 *      Author: javier
 */

#include <stdio.h>
#include "toom_cook.h"

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

	return 0;
}
