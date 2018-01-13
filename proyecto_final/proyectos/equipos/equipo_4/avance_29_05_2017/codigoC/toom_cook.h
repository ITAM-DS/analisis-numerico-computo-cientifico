/*
 * toom_cook.h
 *
 *  Created on: Apr 15, 2017
 *      Author: Javier Quiroz
 */

/********************************************************************************
 *
 *          A C language "class" for Toom Cook big integer  multiplication
 *
 *          (c) 2000 Javier Quiroz, Fernanda Tellez, Lizbeth Contreras
 *
 *          Current State: Zero code compiled
 *
 *          Trends:        optimize code for speed
 *                         use optimizations for different sizez
 *
 *
 *          Directions:     execute trends
 *
 *          Change History:
 *                          15/04/17  code starts
 *                          13/05/17  Integer multiplication, testing
 *                          15/05/17  Matrix operations starts
 *                          23/05/17  Matrix multiplication operation
                            28/05/17  Multithreading operations working

 *          To do:
 *
*********************************************************************************/

#include  <stdio.h>
#include  <stdlib.h>
#include  <memory.h>
#include  <string.h>
#include  <pthread.h>

#ifndef TOOM_COOK_H_
#define TOOM_COOK_H_


// implementation limits
#define NEDEFAULT_BUFER_SIZE 50
#define NEBOXES 3
#define NEBOX_LENGTH 6

extern int  NDEBUG;

//typedef unsigned char neChar

struct numerote
{
	char* buffer;
	int   status;
	int   num_boxes;
	int   index[NEBOXES];
	long  values[NEBOXES];
	int   inUse[NEBOXES];

};



typedef struct numerote  numerote;
typedef numerote * pNumerote;



#define MAX_MATRIX_SIZE 50

struct numeroteMatrix
{
	char* buffer;
	int   m;
	int   n;
	int   status;
	numerote matrix[MAX_MATRIX_SIZE];   

};

typedef struct numeroteMatrix  numeroteMatrix;
typedef numeroteMatrix * pNumeroteMatrix;	

#define neTrue		1
#define neFalse		0

/********************************************************************************
                        Globals
*********************************************************************************/
extern int     lastRC;
extern char    lastError[100];

/********************************************************************************
                        general operations
*********************************************************************************/
int     numeroteInit             ();
int     getLastRC                ();
char*   getlastError             ();
int     setLastRC                (int error);
int     setLastError             (char *error);
int     print_array              (int acum[NEDEFAULT_BUFER_SIZE], char *leyenda );


/********************************************************************************
                        numerote operations
*********************************************************************************/
int     numeroteNew              (pNumerote pNumero, char newValue[50]);
int     numeroteDestroy          (pNumerote pNumero);
int     numeroteMultiply         (pNumerote pA, pNumerote pB, int resultados[NEDEFAULT_BUFER_SIZE]);
int     numeroteAdd              (pNumerote pA, pNumerote pB, pNumerote pC);
int     numerotePrint            (pNumerote pA);




/********************************************************************************
                        numerote matrix operations
*********************************************************************************/
int     numeroteMatrixNew              (pNumeroteMatrix pMatrix, char** newValue, int m, int n);
int     numeroteMatrixDestroy          (pNumeroteMatrix pMatrix);
int     numeroteMatrixPrint            (pNumeroteMatrix pMatrix);
int     numeroteMatrixMultiply         (pNumeroteMatrix pA, pNumeroteMatrix pB, pNumeroteMatrix pC);
int     numeroteMatrixMultiplyNoThreads(pNumeroteMatrix pA, pNumeroteMatrix pB, pNumeroteMatrix pC);
int     numeroteMatrixAdd              (pNumeroteMatrix pA, pNumeroteMatrix pB, pNumeroteMatrix pC);
int     numeroteMatrixMultiplyPoint    (pNumeroteMatrix pA, pNumeroteMatrix pB, int row, int col, int results[NEDEFAULT_BUFER_SIZE] );
void   *multiplyMatrizRow              (void *commArea);

struct MatrixThreadData
{
	pNumeroteMatrix pA;
	pNumeroteMatrix pB;
	pNumeroteMatrix pC;
	int   row;
	//pthread_t hilo;
};

typedef struct MatrixThreadData  MatrixThreadData;
typedef MatrixThreadData * pMatrixThreadData;	


#endif /* TOOM_COOK_H_ */
