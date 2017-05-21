/*
 * toom_cook.c
 *
 *  Created on: Apr 15, 2017
 *      Author: Javier Quiroz, Fernanda Tellez, Lizbeth Contreras
 */
#include <string.h>
#include <memory.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "toom_cook.h"


/********************************************************************************
                        Globals
*********************************************************************************/
int     lastRC = 0;
char    lastError[100] = "";


/********************************************************************************
                        general operations
*********************************************************************************/

long poly_evaluation_values[] = {0L,1L,-1L,2L,-2L};
long matrix5[5][5] = {{0,0,0,0,1},
                      {1,1,1,1,1},
                      {1,-1,1,-1,1},
                      {16,8,4,2,1},
                      {16,-8,4-2,1}};
long matrix5Inv24[5][5] = {{6,-4,-4,1,1},
                      {0,-4,4,2,-2},
                      {-30,16,16,-1,-1},
                      {0,16,-16,-2,2},
                      {24,0,0,0,0},
};

int getLastRC(){
	return lastRC;
}

char* getlastError(){
	return lastError;
}

int setLastRC(int error){
	lastRC = error;
	return 0;
}

int setLastError(char *error){
   strcpy(lastError, error);
   return 0;
}
int numeroteInit(){
	setLastRC( 0 ) ;
	setLastError("OK");

	return 0;
}

/********************************************************************************
                        auxiliary functions
*********************************************************************************/

void string_reverse(char *dst, const char *src)
{
    if (src == NULL) {
        return;
    }

    const char *src_start = src;
    char *dst_end = dst + strlen(src)-1;

    while ((*dst_end-- = *src_start++)) {
        ;
    }
}


int convert_long(long number, int target[]){

	int i;
	long aux = number;

	for (i = 0; aux > 0; i++){
		target[i] = aux % 10 ;
		aux = aux / 10;
	}

    return i;
}



int clean_array(int buffer[NEDEFAULT_BUFER_SIZE])
{
	int i = 0;
	for(;i<NEDEFAULT_BUFER_SIZE; i ++)
		buffer[i] = 0 ;

    return 0 ;
}


int pad_array(int *buffer, int offset, int count)
{
	int i;

	for(i = 0 ;i<count; i ++)
		buffer[i+offset] = 0 ;

    return 0 ;
}

int copyto_array(int *dest, int *source, int offset, int count)
{
	int i;

	for(i = 0 ;i<count; i ++) dest[i+offset] = source[i] ;

    return 0 ;
}

int sum_arrays(int acum[NEDEFAULT_BUFER_SIZE], int b[NEDEFAULT_BUFER_SIZE])
{
	int i;
	int llevamos = 0;
	int suma = 0;

	for(i = 0 ;i<NEDEFAULT_BUFER_SIZE; i ++){
		suma = acum[i] + b[i];
		acum[i] = suma  % 10;
		llevamos =  suma /10;
		acum[i+1] = acum[i+1] + llevamos;
    }
    return 0 ;
}



int print_array(int acum[NEDEFAULT_BUFER_SIZE], char *leyenda )
{
	int i;

	printf("\n%s\n",leyenda);
	for(i = NEDEFAULT_BUFER_SIZE-1 ;i >= 0 ; i-- )
       printf("%d", acum[i]);

    return 0 ;
}

int sum_boxes(long *p, int *resultados){

    int aux[NEDEFAULT_BUFER_SIZE];
    int cumulated[NEDEFAULT_BUFER_SIZE];
    int converted[NEDEFAULT_BUFER_SIZE];

    int i,converted_size;

    clean_array(cumulated);
    clean_array(converted);

    for (i=0; i < 5; i++){
    	clean_array(aux);
      converted_size = convert_long(p[i],converted);
      print_array(converted, "converted");
    	copyto_array(aux, converted,i*NEBOX_LENGTH , converted_size);
    	print_array(aux, "aux");
    	sum_arrays(cumulated, aux);
    	print_array(cumulated, "acumulados en ciclo");
    	printf("---------------------------------\n");
    }

    print_array(cumulated, "acumulados totales");
    memcpy(resultados,cumulated, NEDEFAULT_BUFER_SIZE);

   return 0;
}

char *  intArrayToString(int *parm, char *b, int n){
    int i, k;
    memset(b,n,0);
    for(i = NEDEFAULT_BUFER_SIZE-1 ;i >= 0 ; i-- )
           if (parm[i] != 0 ) break;

    for (k =i; k>0; k--)  sprintf(  b + i-k , "%d" , parm[k] ) ;

    return b;

}
/********************************************************************************
                        numerote operations
*********************************************************************************/
int num_boxes(int len){
    int aux = 0;
	if (len == 0 ) return 0;
    aux = len / NEBOX_LENGTH;
    if ( aux == 0 ) return 1;
    if ( len % NEBOX_LENGTH == 0 ) return aux;
    else return aux + 1;
}



int numeroteNew(pNumerote pNumero, char newValue[50]) {

	int total_length = strlen(newValue);
	char buffer_tempo[16];
	int i,j;

//    printf("testing boxes \n");
//	for (i = 0;i<25;i++)
//		printf("%d = %d \n", i , num_boxes(i) ) ;

	// cleaning, provide for growth in the future
	for (i = 0; i < NEBOXES; i++) {
		pNumero->index[i] = 0;
		pNumero->values[i] = 0;
		pNumero->inUse[i] = 0;
	}
	pNumero->num_boxes = num_boxes(total_length);
	for (j = pNumero->num_boxes-1; j >= 0 ; j--) {
		memset(buffer_tempo, 0, 16);
		memcpy( buffer_tempo, newValue + j*NEBOX_LENGTH, NEBOX_LENGTH);
		pNumero->index[pNumero->num_boxes-1-j] = pNumero->num_boxes-1 -j ;
		pNumero->values[pNumero->num_boxes-1-j] = atol(buffer_tempo);
		pNumero->inUse[pNumero->num_boxes-1] = 1;
	}
  pNumero->buffer = malloc(total_length);
  memcpy(pNumero->buffer, newValue, total_length);
  pNumero->status = 1;


	return 0;
}

int numerotePrint(pNumerote pNumero) {

	// cleaning, provide for growth in the future
	int i ;
	for ( i = 0; i < NEBOXES; i++) {
		printf(" indice  %d =  valor %ld \n", pNumero->index[i], pNumero-> values[i] );
	}
	return 0;
}


int numeroteDestroy(pNumerote pNumero){

    if ( pNumero -> status)
      free(pNumero -> buffer );
	  return 0;
}

long numeroteEvaluate(pNumerote pNumero, long value) {
	int j;
	long aux = 0L;
	for (j = 0; j < pNumero->num_boxes; j++)
		aux = aux + ( pNumero->values[j] ) *  powl( value , pNumero->index[j]) ;
	return aux;
}


int numeroteMultiply(pNumerote pA, pNumerote pB){
      long cValues[NEBOXES], 
           results[NEBOXES], 
           results_reversed[NEBOXES];
      int  results_cumulated[NEDEFAULT_BUFER_SIZE];
      char aux_buffer[NEDEFAULT_BUFER_SIZE];

      long aux;
      int i,j,k;
      //first calculate p(x)* q(x) evaluated in the fixed points
      for (j = 0; j < 5; j++)
    	  cValues[j] = numeroteEvaluate(pA, poly_evaluation_values[j]) * 
    	               numeroteEvaluate(pB, poly_evaluation_values[j]);

      printf("\n Evaluaciones"); 
      for ( i = 0; i< 5; i++)
       	  printf("\n%d = %ld \n", i , cValues[i] ) ;

      // multiply by the fixed matrix
      for ( i = 0, aux= 0; i< 5; i++){
    	  for( k = 0; k < 5; k++)
    	      aux = aux + matrix5Inv24[i][k] * cValues[k];
           results[i] = aux;
           aux = 0;
      }
      // results are in inverse order, index 0 is the most significant
      printf("\n Resultados");    			
      for ( i = 0; i< 5; i++){
    	  printf("\n%d = %ld \n", i , results[i]/24 ) ;
    	  results_reversed[5-i-1] = results[i]/24; // reversando los resultados
      }

      sum_boxes(results_reversed,results_cumulated );
      print_array(results_cumulated, " en multiply results_cumulated");
      
      printf("\nintTo array %s", intArrayToString( results_cumulated, aux_buffer,  NEDEFAULT_BUFER_SIZE) );

	  return 0;
}

int numeroteAdd(pNumerote pA, pNumerote pB, pNumerote pC){
	  return 0;
}
/********************************************************************************
                        numerote Matrix operations
*********************************************************************************/
int     numeroteMatrixNew(pNumeroteMatrix pM, char** newValue, int m, int n){
     
      int i,j, k  ;
      pM->m = m;
      pM->n = n;
      k = 0;
      printf("\nCreating  matrix\n   Dimensions: (%d,%d) ", pM-> m, pM->n);
      for (i = 1; i <= pM->m; i ++)
        //printf("\n");
        for (j = 1 ; j <= pM->n; j++){
            printf("\n setting (i,j) = (%d,%d)", i, j );
            //numeroteNew( & ( pM->matrix[k] )  , newValue[k]);
            numeroteNew( & ( pM->matrix[(i-1)*pM->n + (j-1)] )  , newValue[k]);
            k++;
        }

}

int     numeroteMatrixPrint(pNumeroteMatrix pM){

      int i,j ;
      printf("\nPrinting matrix\n   Dimensions: (%d,%d) ", pM-> m, pM->n);
      for (i = 1; i <= pM->m; i ++){
        printf("\n   ");
        for (j = 1 ; j <= pM->n; j++)
          printf("%s ", pM->matrix[(i-1)*pM->n + (j-1)].buffer);
          // numerotePrint( & pM->matrix[(i-1)*pM->n + (j-1)]) ;
      }

}
