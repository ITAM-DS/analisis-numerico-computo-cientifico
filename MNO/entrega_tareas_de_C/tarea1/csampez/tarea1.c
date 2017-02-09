/*Ejercicio aritmética de máquina*/

#include <stdio.h>
#include <math.h>

int main(){ 
	/* originales a 8 digitos*/
	double x = 0.71428571;
	double y = 0.33333333;
	double u = 0.714251;
	double v = 98765.9;
	double w = 0.111111e-4;

	double x5;
	double y5;
	double u5;
	double v5;
	double w5;
		
	x5 = truncf(x*1e5)*1e-5;
	y5 = truncf(y*1e5)*1e-5;
	u5 = truncf(u*1e5)*1e-5;
	v5 = truncf(v*1e5)*1e-5;
	w5 = truncf(w*1e5)*1e-5;
	
	//printf("Originales %1.8f, %1.8f, %1.8f, %1.8f, %1.8f \n", x, y, u, v, w);
	//printf("Truncados %1.8f, %1.8f, %1.8f, %1.8f, %1.8f \n \n", x5, y5, u5, v5, w5);
	//printf("##################################################################### \n \n");

	printf("|Operación | Valor a 8 | Aritmética Maquina | Error Abs | Error Rel |\n");
	printf("|----------| ----------| -------------------| ----------| --------- |\n");

	// operacion x-y
	double valor_real = x-y;
	double valor_maq = trunc((x5-y5)*1e5)*1e-5;	
	double err_abs = fabs(valor_real-valor_maq);
	double err_rel = err_abs/valor_real;

	printf("| x-y  | %1.8f  |  %1.8f  |  %1.8f  |  %1.8f |\n", valor_real, valor_maq, err_abs, err_rel);

	// operacion x/y
	valor_real = x/y;
	valor_maq = trunc((x5/y5)*1e5)*1e-5;	
	err_abs = fabs(valor_real-valor_maq);
	err_rel = err_abs/valor_real;

	printf("| x/y  | %1.8f  |  %1.8f  |  %1.8f  |  %1.8f |\n", valor_real, valor_maq, err_abs, err_rel);

	// operacion (x-u)/w
	valor_real = (x-u)/w;
	valor_maq = trunc( ( (trunc((x5-u5)*1e5)*1e-5) / w5)*1e5)*1e-5  ;	
	err_abs = fabs(valor_real-valor_maq);
	err_rel = err_abs/valor_real;

	printf("| (x-u)/w  | %1.8f  |  %1.8f  |  %1.8f  |  %1.8f |\n", valor_real, valor_maq, err_abs, err_rel);

	// operacion (x-u)/w
	valor_real = u+v;
	valor_maq = trunc((u5+v5)*1e5)*1e-5  ;	
	err_abs = fabs(valor_real-valor_maq);
	err_rel = err_abs/valor_real;

	printf("| u+v  | %1.8f  |  %1.8f  |  %1.8f  |  %1.8f |\n", valor_real, valor_maq, err_abs, err_rel);
}
