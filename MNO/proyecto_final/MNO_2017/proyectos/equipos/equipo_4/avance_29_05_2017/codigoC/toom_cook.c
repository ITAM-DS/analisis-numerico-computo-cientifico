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
#include <pthread.h>
#include "toom_cook.h"


/********************************************************************************
                        Globals
*********************************************************************************/
int     lastRC = 0;
char    lastError[100] = "";
pthread_mutex_t mutex;


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



int clean_array(int *buffer, int num_bytes )
{
	int i = 0;
	for(;i<num_bytes; i ++)
		buffer[i] = 0 ;

    return 0 ;
}


int clean_array_long(long *buffer, int num_bytes )
{
  int i = 0;
  for(;i<num_bytes; i ++)
    buffer[i] = 0L ;

    return 0 ;
}


int pad_array(int *buffer, int offset, int count)
{
	int i;

	for(i = 0 ;i<count; i ++)
		buffer[i+offset] = 0 ;

    return 0 ;
}

int copy_array(int *dest, int *source, int offset, int count)
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

int regularize_array(int acum[NEDEFAULT_BUFER_SIZE]){
   int i;
  int llevamos = 0;

  for(i = 0 ;i<NEDEFAULT_BUFER_SIZE; i ++){
    llevamos = acum[i] /10;
    if ( llevamos > 1) {
        acum[i] = acum[i] % 10 ;
        acum[i+1] = acum[i+1] + llevamos;
    }
    
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

    clean_array(cumulated, NEDEFAULT_BUFER_SIZE);
    clean_array(converted, NEDEFAULT_BUFER_SIZE);
    clean_array(resultados,NEDEFAULT_BUFER_SIZE);

    for (i=0; i < 5; i++){
      clean_array(converted, NEDEFAULT_BUFER_SIZE);
    	clean_array(aux, NEDEFAULT_BUFER_SIZE);
      converted_size = convert_long(p[i],converted);      
      if (NDEBUG) print_array(converted, "converted");
    	copy_array(aux, converted,i*NEBOX_LENGTH , converted_size);
    	if (NDEBUG) print_array(aux, "aux");
    	sum_arrays(cumulated, aux);
    	if (NDEBUG)print_array(cumulated, "acumulados en ciclo");
    	if (NDEBUG)printf("---------------------------------\n");
    }

    //print_array(cumulated, "acumulados totales");
    for (i=0; i < NEDEFAULT_BUFER_SIZE ; i++) resultados[i] = cumulated[i];
    if (NDEBUG) print_array(resultados, "acumulados totales");

   return 0;
}


char *  intArrayToString(char *b, int *parm,  int n){
    int i, k;
    // activar en caso necesario: pthread_mutex_lock(&mutex);   
    memset(b,'\0',n);


    for(i = NEDEFAULT_BUFER_SIZE-1 ;i >= 0 ; i-- )
           if (parm[i] != 0 ) break;

    for (k =i; k>=0; k--)  sprintf(  b + i-k , "%d" , parm[k] ) ;
    // pthread_mutex_unlock(&mutex);
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
  int len  = strlen(newValue);
	char buffer2 [19], buffer3[7];

	int i;



	// cleaning, provide for growth in the future
	for (i = 0; i < NEBOXES; i++) {
		pNumero->index[i] = 0;
		pNumero->values[i] = 0;
		pNumero->inUse[i] = 1;
	}


  memset(buffer2, '0', 18);
  memset(buffer3, '\0',7);
  memcpy(buffer2+ 18-len, newValue, len);

  if (NDEBUG) printf("\n buffer2 = %s", buffer2);

  memcpy(buffer3, buffer2, 6);
  pNumero->values[2] = atol(buffer3);
  pNumero->index [2] = 2;

  memcpy(buffer3, buffer2+6, 6);
  pNumero->values[1] = atol(buffer3);
  pNumero->index [1] = 1;
  
  memcpy(buffer3, buffer2+12, 6);
  pNumero->values[0] = atol(buffer3);
  pNumero->index [0] = 0;

  pNumero->num_boxes = 3;

  pNumero->buffer = malloc(len);
  memcpy(pNumero->buffer, newValue, len);
  pNumero->status = 1;


	return 0;
}

//aqui voy
int numeroteNewFromIntArray(pNumerote pNumero, int newValue[50]) {

  char buffer_tempo[NEDEFAULT_BUFER_SIZE];
  intArrayToString(buffer_tempo, newValue, NEDEFAULT_BUFER_SIZE);
  if (NDEBUG)  print_array(newValue, "llego");
  if (NDEBUG)  printf("\n convertido %s", buffer_tempo);
  numeroteNew(pNumero, buffer_tempo);

  return 0;
}

int numerotePrint(pNumerote pNumero) {

	// cleaning, provide for growth in the future
	int i ;
	for ( i = 0; i < pNumero->num_boxes; i++) {
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
	// activar en caso necesario: pthread_mutex_lock(&mutex);
	for (j = 0; j < pNumero->num_boxes; j++)
		aux = aux + ( pNumero->values[j] ) *  powl( value , pNumero->index[j]) ;
	//pthread_mutex_unlock(&mutex);
	return aux;
}


int  numeroteMultiply(pNumerote pA, pNumerote pB, int mul_results[NEDEFAULT_BUFER_SIZE]){
    
      long aux,total ;
      int i,j,k;
      long cValues[NEDEFAULT_BUFER_SIZE], 
           results[NEDEFAULT_BUFER_SIZE], 
           results_reversed[NEDEFAULT_BUFER_SIZE];
      int  results_cumulated[NEDEFAULT_BUFER_SIZE];



      clean_array_long(cValues, NEBOXES);
      clean_array_long(results, NEBOXES);
      clean_array_long(results_reversed, NEBOXES);
      clean_array(results_cumulated, NEDEFAULT_BUFER_SIZE);

      //first calculate p(x)* q(x) evaluated in the fixed points
      for (j = 0; j < 5; j++)
    	  cValues[j] = numeroteEvaluate(pA, poly_evaluation_values[j]) * 
    	               numeroteEvaluate(pB, poly_evaluation_values[j]);

      if (NDEBUG) printf("\n Evaluaciones"); 
      if (NDEBUG) for ( i = 0; i< 5; i++) printf("\n%d = %ld \n", i , cValues[i] ) ;

      // multiply by the fixed matrix
    
      for ( i = 0; i< 5; i++){
        total = 0;
    	  for( k = 0; k < 5; k++){
    	      aux =   matrix5Inv24[i][k] * cValues[k];
            total = total + aux;
            if (NDEBUG) printf("\n elemento de la matriz %ld", matrix5Inv24[i][k]);
            if (NDEBUG) printf ("\n cValue %ld", cValues[k]);
          }
        results[i] = total;
      }
      // results are in inverse order, index 0 is the most significant
      if (NDEBUG)printf("\n numeroteMultiply: Resultados");    	

      for ( i = 0; i< 5; i++){
    	  if (NDEBUG) printf("\n%d = %ld \n", i , results[i]/24 ) ;
    	  results_reversed[5-i-1] = results[i]/24; // reversando los resultados, asume matriz 5X5
      }

      sum_boxes(results_reversed,results_cumulated );
      if (NDEBUG) print_array(results_cumulated, " numeroteMultiply en multiply results_cumulated");
      

      copy_array(mul_results, results_cumulated, 0 , NEDEFAULT_BUFER_SIZE);

	   return 0;
}


int numeroteAdd(pNumerote pA, pNumerote pB, pNumerote pC){
	  return 0;
}



/********************************************************************************
                        numerote Matrix operations
                        indexing starts in 1, not zero
*********************************************************************************/
int numeroteMatrixNew(pNumeroteMatrix pM, char** newValue, int m, int n){
     
      int i,j, k  ;
      pM->m = m;
      pM->n = n;
      k = 0;
      if (NDEBUG) printf("\nCreating  matrix\n   Dimensions: (%d,%d) ", pM-> m, pM->n);
      for (i = 1; i <= pM->m; i ++)
        for (j = 1 ; j <= pM->n; j++){
            if (NDEBUG) printf("\n setting (i,j) = (%d,%d)", i, j );
            numeroteNew( & ( pM->matrix[(i-1)*pM->n + (j-1)] )  , newValue[k]);
            k++;
        }
        return 0;
}


int numeroteMatrixPrint(pNumeroteMatrix pM){

      int i,j ;
      printf("\nPrinting matrix\n   Dimensions: (%d,%d) ", pM-> m, pM->n);
      for (i = 1; i <= pM->m; i ++){
        printf("\n   ");
        for (j = 1 ; j <= pM->n; j++)
          printf("%s ", pM->matrix[(i-1)*pM->n + (j-1)].buffer);
         
      }
      return 0;
}

//
//  Multiply matrix pMa row  by matrix pMB column ,
//  indexing starts in 1 not zero
//
int numeroteMatrixMultiplyPoint(pNumeroteMatrix pA, pNumeroteMatrix pB, int row, int col, int results[NEDEFAULT_BUFER_SIZE] ){

	int aux[NEDEFAULT_BUFER_SIZE];
	int k;

    clean_array( results, NEDEFAULT_BUFER_SIZE);
    for (k=1; k <= pA->n; k++){
         clean_array(aux, NEDEFAULT_BUFER_SIZE);
    	   numeroteMultiply(& pA->matrix[(row-1)*pA->n + (k-1)], & pB->matrix[(k-1)*pB->n + (col -1)], aux);
         sum_arrays(results, aux);   	  
    }
   
    //regularize_array(results);
     if (NDEBUG) print_array(results, "imprimiendo results");
    return 0;
}



/********************************************************************************
                        numerote Threading Matrix operations
                        indexing starts in 1, not zero
*********************************************************************************/
int numeroteMatrixMultiply(pNumeroteMatrix pA, pNumeroteMatrix pB, pNumeroteMatrix pC){
    long thread, thread_count;
    pthread_t *thread_handles;
    MatrixThreadData  threadData[3];

    thread_count = 3; //pA->n ;
    thread_handles=malloc(thread_count*sizeof(pthread_t));

    pthread_mutex_init(&mutex, NULL);
    for(thread=0;thread<thread_count;thread++){
        threadData[thread].pA = pA;
        threadData[thread].pB = pB;
        threadData[thread].pC = pC;
        threadData[thread].row = thread +1;
        pthread_create(&thread_handles[thread], NULL, multiplyMatrizRow,
            (void*) &( threadData [thread] ) ) ;
    }
    for(thread=0;thread<thread_count;thread++)
        pthread_join(thread_handles[thread], NULL);
    free(thread_handles);
    pthread_mutex_destroy(&mutex);
    return 0;
}




void * multiplyMatrizRow(void *commArea){
  pNumeroteMatrix pA, pB, pC;
  int row;

  pA =  ((MatrixThreadData *) commArea)->pA;
  pB =  ((MatrixThreadData *) commArea)->pB;
  pC =  ((MatrixThreadData *) commArea)->pC;
  row = ((MatrixThreadData *) commArea)->row;
  
   
  int k;
  int resultados[NEDEFAULT_BUFER_SIZE];
  
  for (k=1; k <= (pB->n);   k++){
      //pthread_mutex_lock(&mutex);
      clean_array(resultados, NEDEFAULT_BUFER_SIZE);
      numeroteMatrixMultiplyPoint(pA, pB, row, k, resultados);
      numeroteNewFromIntArray(&pC->matrix[(row-1)* (pC->n) +  (k-1) ], resultados);
      //pthread_mutex_unlock(&mutex);
  }  
  
  return NULL;
}


int numeroteMatrixMultiplyNoThreads(pNumeroteMatrix pA, pNumeroteMatrix pB, pNumeroteMatrix pC){
  int k;
  int resultados[NEDEFAULT_BUFER_SIZE];
  int row; 
  for (row=1; row <= pA->m; row++)
    for (k=1; k <= (pB->n);   k++){
      clean_array(resultados,NEDEFAULT_BUFER_SIZE);
      numeroteMatrixMultiplyPoint(pA, pB, row, k, resultados);
      numeroteNewFromIntArray(&pC->matrix[(row-1)* (pC->n) +  (k-1) ], resultados);
  }  
  return 0;
}