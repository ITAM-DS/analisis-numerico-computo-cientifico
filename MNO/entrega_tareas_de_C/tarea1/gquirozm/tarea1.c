/*
 ============================================================================
 Name        : tarea1.c
 Author      : Javier Quiroz
 Version     :
 Copyright   : (c) 2017
 Description : Utilizacion de punto flotante, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <math.h>
#include <stdlib.h>


/*
 ------------------------------------------------------------------------------
       Funciones auxiliares
 ------------------------------------------------------------------------------
*/


float error_absoluto(float parm1, float parm2){

    float tempo;

    tempo = fabs(parm1 - parm2);
    return tempo;
}

float error_relativo(float parm1, float parm2){

    float temp1;
    float temp2;

    temp1 = fabs(parm1 - parm2);
    temp2 = fabs(temp1/parm1);
    return temp2;
}

double my_trunc(double parm_num, int parm_digitos){
	//utilizando corrimiento a la izquierda con una multiplacion
	//y luego restaurando con una division
    double temp = pow(10, parm_digitos);
    return truncf(parm_num*temp)/temp;
}

/*
 ------------------------------------------------------------------------------
       Funcion principal
 ------------------------------------------------------------------------------
*/

int main(){

	//variables a utilizar
    double varX8 = 0.71428571;
    double varY8 = 0.33333333;
    double varU8 = 0.714251;
    double varV8 = 98765.9;
    // truncando a cinco para ver efecto de la aritmetica
    double varX5 = my_trunc(varX8,5);
    double varY5 = my_trunc(varY8,5);
    double varU5 = my_trunc(varU8,5);
    double varV5 = my_trunc(varV8,5);


    // calculando operaciones previamente para simplificar formateo

    // Suma x + y
    double suma_8 = varX8 + varY8;
    double suma_5 = varX5 + varY5;
    double absoluto_suma = error_absoluto(suma_8,suma_5);
    double relativo_suma = error_relativo(suma_8,suma_5);

    // Multiplicación x * y
    double mult_8 = varX8 * varY8;
    double mult_5 = varX5 * varY5;
    double absoluto_mult = error_absoluto(mult_8,mult_5);
    double relativo_mult = error_relativo(mult_8,mult_5);

    //  Resta (x-u)
    double resta_varU8 = varX8 - varU8;
    double resta_varU5 = varX5 - varU5;
    double absoluto_resta = error_absoluto(resta_varU8,resta_varU5);
    double relativo_resta = error_relativo(resta_varU8,resta_varU5);

    // (x-u)v
    double comb_varV8 = (varX8 - varU8)*varV8;
    double comb_varV5 = (varX5 - varU5)*varV5;
    double absoluto_comb = error_absoluto(comb_varV8,comb_varV5);
    double relativo_comb = error_relativo(comb_varV8,comb_varV5);

    // imprimiendo resultados
    printf("Resultados para operaciones impares\n");
    printf("Operación \t Valor 8 \t\t Aritmética de máquina \t error_absoluto \t error_relativo\n");
    printf("x+y \t\t %1.8f \t\t %1.5f \t\t %e \t\t %e\n", suma_8, suma_5, absoluto_suma, relativo_suma);
    printf("x*y \t\t %1.8f \t\t %1.5f \t\t %e \t\t %e\n", mult_8, mult_5, absoluto_mult, relativo_mult);
    printf("x-u \t\t %1.8f \t\t %1.5f \t\t %e \t\t %e\n", resta_varU8, resta_varU5, absoluto_resta, relativo_resta);
    printf("(x-u)*v \t %1.8f \t\t %1.5f \t\t %e \t\t %e\n", comb_varV8, comb_varV5, absoluto_comb, relativo_comb);

    return EXIT_SUCCESS;

}
