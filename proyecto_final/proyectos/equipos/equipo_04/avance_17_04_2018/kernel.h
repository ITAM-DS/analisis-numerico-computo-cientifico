/************************************************************************************************/
/************ Arturo Gonzalez Bencomo 172906, Arturo Torre Gonzalez 90226 ***********************/
/************************************************************************************************/
/********************************** kernel.h ****************************************************/
/************************************************************************************************/
/** Este archivo define el prototipo de funcion matrixMultiplication ****************************/

#ifndef KERNEL_CUH_
#define KERNEL_CUH_

//Esta funcion recibe 4 parametros, 3 apuntadores a datos float (matrices) y 1 entero(tamanio de matrices).
void matrixMultiplication(float *A, float *B, float *C, int N);  

#endif

