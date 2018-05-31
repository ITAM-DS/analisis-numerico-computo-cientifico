#include<stdio.h>
#include<math.h>
int main(){

	printf("Tarea 1\n Elizabeth Solis Diaz\n 113032 \n");
	// Definicion e inicializacion de variables 
	double x = 5.0/7.0;
	double y = 1.0/3.0;
	double u = 0.714251;
	double v = 98765.9;

	// el equipo 1 realiza las operaciones: 
	// x+y, xy, x-u, (x-u)v 

	// Definicion de variables para resultados
	double suma = x + y;
	double multip = x * y;
	double resta = x - u;
	double resta_mult = resta * v;

	// Valor a 8: aritmetica a 8 digitos
	double suma_8dig = truncf(suma*1e8)*1e-8;
	double multip_8dig = truncf(multip*1e8)*1e-8;
	double resta_8dig = truncf(resta*1e8)*1e-8;
	double resta_mult_8dig = truncf(resta_mult*1e8)*1e-8; 

	// Aritmetica de maquina: operaciones definidas con beta = 10 y k = 5 (regla de corte porque es fl_c)
	// 1.Obtenemos fl_c para cada variable con los parametros beta = 10 y k = 5
	double x_c = truncf(x*1e5)*1e-5;
	double y_c = truncf(y*1e5)*1e-5;
	double u_c = truncf(u*1e5)*1e-5;
	double v_c = truncf(v*1e5)*1e-5;
	// 2. Aplicamos fl_c a la operación
	double suma_maq = truncf((x_c + y_c) *1e5)*1e-5;
	double multip_maq = truncf((x_c * y_c)*1e5)*1e-5;
	double resta_maq = truncf((x_c - u_c)*1e5)*1e-5;
	double resta_mult_maq = truncf(((x_c - u_c)*v_c)*1e5)*1e-5;	

	// Error absoluto
	double error_a1 = fabs(suma_maq - suma_8dig);
	double error_a2 = fabs(multip_maq - multip_8dig);
	double error_a3 = fabs(resta_maq - resta_8dig);
	double error_a4 = fabs(resta_mult_maq - resta_mult_8dig);

	// Error relativo
	double error_r1 = fabs(suma_maq - suma_8dig)/suma_8dig;
	double error_r2 = fabs(multip_maq - multip_8dig)/multip_8dig;
	double error_r3 = fabs(resta_maq - resta_8dig)/resta_8dig;
	double error_r4 = fabs(resta_mult_maq - resta_mult_8dig)/resta_mult_8dig;

	// Impresión de resultados como fueron solicitados
	printf("Operacion\t Valor a 8\tAritmetica de maquina\tErrA \t \t\tErrR\n");
  	printf(" x + y\t\t %.7e\t  %.4e  \t\t%.5e \t\t%.5e\n",suma_8dig, suma_maq, error_a1, error_r1);
  	printf(" x * y\t\t %.7e\t  %.4e  \t\t%.5e \t\t%.5e\n", multip_8dig, multip_maq, error_a2, error_r2);
  	printf(" x - u\t\t %.7e\t  %.4e  \t\t%.5e \t\t%.5e\n", resta_8dig, resta_maq, error_a3, error_r3);
  	printf(" (x - u) * v\t %.7e\t  %.4e  \t\t%.5e \t\t%.5e\n", resta_mult_8dig, resta_mult_maq, error_a4, error_r4);

}

