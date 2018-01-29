/* Clase: Metodos numericos y optimizacion */
/* Tarea 1 */
/* Autor: Victor Augusto Samayoa Donado */

#include<stdio.h>

void main(){

// Se definen e inicializan las variables a usar para el ejercicio
FILE *fptr;
double suma5, suma8, resta5, resta8, div5, div8, errorA, errorR;

float x5 = 0.71428;
float x8 = 0.71428571;

float y5 = 0.33333;
float y8 = 0.33333333;

float u5 = 0.71425;
float u8 = 0.714251;

float v5 = 0.98765E+05;
float v8 = 0.987659E+05;

float w5 = 0.11111E-04;
float w8 = 0.111111E-04;

float xmu5 = 0.3E-04;
float xmu8 = 0.347E-04;

// Se abre el archivo donde se van a guardar los resultados (la ruta del archivo parte que es donde esta el ejecutable)
fptr = fopen("tarea1.txt", "w");

// Se imprimen los valores a usar
fprintf(fptr, "\n");
fprintf(fptr, "Tarea 1\n");
fprintf(fptr, "Victor Augusto Samayoa Donado\n \n");
fprintf(fptr, "Los valores que se usaron para los calculos fueron:\n");
fprintf(fptr, "x = 0.71428E+00 con precision a 5 cifras.\n");
fprintf(fptr, "x = 0.71428571E+00 con precision a 8 cifras.\n");
fprintf(fptr, "y = 0.33333E+00 con precision a 5 cifras.\n");
fprintf(fptr, "y = 0.33333333E+00 con precision a 8 cifras.\n");
fprintf(fptr, "u = 0.71425E+00 con precision a 5 cifras.\n");
fprintf(fptr, "u = 0.714251E+00 con precision a 8 cifras.\n");
fprintf(fptr, "v = 0.98765E+05 con precision a 5 cifras.\n");
fprintf(fptr, "v = 0.987659E+05 con precision a 8 cifras.\n");
fprintf(fptr, "w = 0.11111E-04 con precision a 5 cifras.\n");
fprintf(fptr, "w = 0.111111E-04 con precision a 8 cifras.\n");
fprintf(fptr, "x-u = 0.3E-04 con precision a 5 cifras.\n");
fprintf(fptr, "x-u = 0.347E-04 con precision a 8 cifras.\n \n");

// Se comienza a crear la tabla en el txt
// Debido a la estrucutra de notacion cientifica en C, el formato de la mantisa en C difiere al visto en clase
// Ejemplo: Los siguientes formatos son equivalentes
// Mantisa en clase 0.12345678E+01
// Mantisa en C     1.2345678E+00
fprintf(fptr, "Mantiza usando la notacion de C:\n");
fprintf(fptr, "______________________________________________________________________________\n");
fprintf(fptr, "| Operacion |    Valor a 8   | Aritmetica  |      ErrA      |     ErrR       |\n");
fprintf(fptr, "|           |                |  de maquina |                |                |\n");
fprintf(fptr, "|___________|________________|_____________|________________|________________|\n");
fprintf(fptr, "|___________|________________|_____________|________________|________________|\n");

// Se hacen los calculos de la resta
resta8 = x8+y8;
resta5 = x5+y5;
errorA = resta8-resta5;
errorR = errorA/resta8;
fprintf(fptr, "|   x + y   | %.7E  | %.4E  | %.7E  | %.7E  |\n", resta8, resta5, errorA, errorR); 
fprintf(fptr, "|___________|________________|_____________|________________|________________|\n");

// Se hacen los calculos de la division
div8 = x8/y8;
div5 = x5/y5;
errorA = -1.0*(div8-div5); // Se multiplica por -1 para volver el error en valor positivo ya que la funcion abs lo redndea a entero.
errorR = errorA/div8;
fprintf(fptr, "|   x / y   | %.7E  | %.4E  | %.7E  | %.7E  |\n", div8, div5, errorA, errorR);
fprintf(fptr, "|___________|________________|_____________|________________|________________|\n");

// Se hacen los calculos de la resta y la division
div8 = xmu8/w8;
div5 = xmu5/w5;
errorA = div8-div5;
errorR = errorA/div8;
fprintf(fptr, "| (x - u)/w | %.7E  | %.4E  | %.7E  | %.7E  |\n", div8, div5, errorA, errorR);
fprintf(fptr, "|___________|________________|_____________|________________|________________|\n");

// Se hacen los calculos de la suma
suma8 = u8+v8;
suma5 = u5+v5;
errorA = suma8-suma5;
errorR = errorA/suma8;
fprintf(fptr, "|   u + v   | %.7E  | %.4E  | %.7E  | %.7E  |\n", suma8, suma5, errorA, errorR);
fprintf(fptr, "|___________|________________|_____________|________________|________________|\n");
fprintf(fptr, "\n \n");

// Correccion a la notacion cientifica del C
fprintf(fptr, "Notemos que la mantisa no tiene el formato definido en SPFN, donde el entero siempre es cero y la primer posicion del decimal es diferente de cero.\n");
fprintf(fptr, "Debido a que no se identifico una opcion en C para modificar la forma en que escribe la notacion cientifica, se procede a crear la tabla directamente.\n \n");

fprintf(fptr, "Mantiza usando la notacion en clase:\n");

fprintf(fptr, "______________________________________________________________________________\n");
fprintf(fptr, "| Operacion |    Valor a 8   |  Aritmetica  |     ErrorA     |     ErrorR     |\n");
fprintf(fptr, "| Operacion |                |   de maquina |                |                |\n");
fprintf(fptr, "|___________|________________|______________|________________|________________|\n");
fprintf(fptr, "|___________|________________|______________|________________|________________|\n");
fprintf(fptr, "|   x - y   | 0.10476191E+01 | 0.104761E+01 | 0.9059906E-05  | 0.86480916E-05 |\n");
fprintf(fptr, "|___________|________________|______________|________________|________________|\n");
fprintf(fptr, "|   x / y   | 0.21428571E+01 | 0.21429E+01  | 0.42915344E-05 | 0.20027161E-05 |\n");
fprintf(fptr, "|___________|________________|______________|________________|________________|\n");
fprintf(fptr, "| (x - u)/w | 0.3123003E+01  | 0.27E+01     | 0.42297626E+00 | 0.13543895E+00 |\n");
fprintf(fptr, "|___________|________________|______________|________________|________________|\n");
fprintf(fptr, "|   u + v   | 0.9876609E+05  | 0.98766E+05  | 0.8984375E+00  | 0.9096573E-05  |\n");
fprintf(fptr, "|___________|________________|______________|________________|________________|\n");

fclose(fptr);
}
