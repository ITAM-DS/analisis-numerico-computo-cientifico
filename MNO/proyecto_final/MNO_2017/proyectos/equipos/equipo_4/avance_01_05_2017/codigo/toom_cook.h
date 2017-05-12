/*
 * toom_cook.h
 *
 *  Created on: Apr 15, 2017
 *      Author: Javier Quiroz
 */

/********************************************************************************
 *
 *           A C language "class" for Toom Cook big integer  multiplication
 *
 *           (c) 2000 Javier Quiroz, Fernanda Tellez, Lizbeth Contreras
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
 *
 *          To do:
 *
*********************************************************************************/

#include  <stdio.h>
#include  <stdlib.h>
#include  <memory.h>
#include  <string.h>

#ifndef TOOM_COOK_H_
#define TOOM_COOK_H_


// implementation limits
#define NEDEFAULT_BUFER_SIZE 50
#define NEBOXES 6
#define NEBOX_LENGTH 3

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


/********************************************************************************
                        numerote operations
*********************************************************************************/
int     numeroteNew              (pNumerote pNumero, char newValue[50]);
int     numeroteDestroy          (pNumerote pNumero);
int     numeroteMultiply         (pNumerote pA, pNumerote pB);
int     numeroteAdd              (pNumerote pA, pNumerote pB);

#endif /* TOOM_COOK_H_ */
