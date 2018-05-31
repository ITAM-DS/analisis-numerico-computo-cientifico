#include<stdio.h>
main(){

	int prueba_x,prueba_y,prueba_u,prueba_w, prueba_v;
	double x_trunc,y_trunc,div_x,div_y,resta_directo, resta_flot,error_1,variable_int5, variable_int7, variable_int1, variable_int3,
	division_directa, division_flot, u_truncada,w_truncada,u_real,w_real, ejercicio_6_directo, ejercicio_6_truncado, v_truncado, v_real;
	//Inicialización de variables:
	variable_int3=3.0;
	variable_int1=1.0;
	variable_int7=7.0;
	variable_int5=5.0;

	//fl_x = 0.71428;
	//fl_y = 0.33333;

	div_x=variable_int5/variable_int7;
	div_y=variable_int1/variable_int3;
	prueba_x=div_x*100000;
	prueba_y=div_y*100000;


	x_trunc=(double)prueba_x/(double)100000.0;
	printf("X truncada: %f\n", x_trunc);

	y_trunc=(double)prueba_y/(double)100000.0;
	printf("Y truncada: %f\n", y_trunc);

	u_real = 0.71425100;
	prueba_u=u_real*100000;
	u_truncada = (double)prueba_u/(double)100000.0;

	w_real=0.00001111;
	prueba_w = w_real *100000;
	w_truncada = (double)prueba_w/(double)100000.0;

	//v_real = 98765.9



	//Qué salió de la división
	printf("Valor de x a 8 digitos: %1.8f\n", div_x);
	printf("Valor de y a 8 digitos: %1.8f\n", div_y);

	// RESTA

	resta_directo = div_x-div_y;
	printf("Valor de resta de fracciones a 8: %1.8f\n", resta_directo);

	resta_flot = x_trunc - y_trunc;
	printf("Varlor de resta en aritmètica de máquina resta_flot: %1.5f\n", resta_flot);

	error_1=resta_directo-resta_flot;
	//Error c
	printf("Error c: %1.8f\n", error_1);

	//Error de computo
	printf("Error total resta: %1.8f\n", error_1/resta_directo);

	// DIVISION

	division_directa=div_x/div_y;
	printf("Valor de DIVISION de fracciones a 8: %1.8f\n", division_directa);

	division_flot=x_trunc/y_trunc;
	printf("Valor de DIVISION de aritmetica de maquina : %1.5f\n", division_flot);

	error_1=division_directa - division_flot;
	printf("Error c: %1.8f\n", error_1);

	printf("Error total division: %1.8f\n", error_1/division_directa);


	// EJERCICIO 6 (x-u)/w

	ejercicio_6_directo = (div_x - u_real) / w_real;
	printf("Resultado del ejercicio 6 a 8 digitos: %1.8f\n", ejercicio_6_directo);

	ejercicio_6_truncado = (x_trunc - u_truncada) / w_truncada;
	printf("Resultado del EJERCICIO 6 con aritmética de máquina: %1.8f\n", ejercicio_6_truncado);

	error_1=ejercicio_6_directo - ejercicio_6_truncado;
	printf("Error c del ejercicio 6: %1.8f\n", error_1);

	printf("Error total EJERCICIO 6: %1.8f\n", error_1/ejercicio_6_directo);

	//Ejercicio 8 u+v





}