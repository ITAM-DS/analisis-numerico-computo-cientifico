#include<stdio.h>
#include<math.h>

double truncar(double a, int k){
	int cont = 0;
	while (a >= 1){
		a = a / 10;
		cont++;
	}
	a = a*(pow(10, k));
	a = truncf(a);
	a = a*(pow(10, -k));	
	return a * pow(10, cont);
}

main(){
	//Datos
	double x_8 = 0.71428571;
	double y_8 = 0.33333333;
	double u_8 = 0.71425100;
	double v_8 = 98765.9;
	//Variables
	double x_5, y_5, u_5, v_5;
	double xmy_8, xpy_8, xmu_8, xuv_8;
	double xmy_5, xpy_5, xmu_5, xuv_5;
	//Trunco los valores a 5 con truncf
	//Lo hago paso por paso
	x_5 = truncar(x_8, 5);
	printf("Valor x_5: %e\n",x_5);
	y_5 = truncar(y_8, 5);
	printf("Valor y_5: %e\n",y_5);
	u_5 = truncar(u_8, 5);
	printf("Valor u_5: %e\n",u_5);
	v_5 = truncar(v_8, 5);
	printf("Valor v_5: %e\n",v_5);
	//Cálculos
	xmy_8 = x_8 + y_8;
	xmy_5 = x_5 + y_5;
	xmy_5 = truncar(xmy_5, 5);
		//
	xpy_8 = x_8 * y_8;
	xpy_5 = x_5 * y_5;
	xpy_5 = truncar(xpy_5, 5);
	//
	xmu_8 = x_8 - u_8;
	xmu_5 = x_5 - u_5;
	xmu_5 = truncar(xmu_5, 5);
	//
	xuv_8 = xmu_8 / v_8;
	xuv_5 = xmu_5 / v_5;
	xuv_5 = truncar(xuv_5, 5);
	//Impresión salida
	printf("\nValor a 8 (x + y): %e\n",xmy_8);
	printf("Valor a 5 (x + y): %e\n",xmy_5);
	printf("Valor diferencia: %e\n", (xmy_8 - xmy_5));
	printf("Valor error: %e\n", (xmy_8 - xmy_5) / xmy_8);
	//
	printf("\nValor a 8 (x * y): %e\n",xpy_8);
	printf("Valor a 5 (x * y): %e\n",xpy_5);
	printf("Valor diferencia: %e\n", (xpy_8 - xpy_5));
	printf("Valor error: %e\n", (xpy_8 - xpy_5) / xpy_8);
	//
	printf("\nValor a 8 (x - u): %e\n",xmu_8);
	printf("Valor a 5 (x - u): %e\n",xmu_5);
	printf("Valor diferencia: %e\n", (xmu_8 - xmu_5));
	printf("Valor error: %e\n", (xmu_8 - xmu_5) / xmu_8);
	//
	printf("\nValor a 8 (x-u)/v: %e\n",xuv_8);
	printf("Valor a 5 (x-u)/v: %e\n",xuv_5);
	printf("Valor diferencia: %e\n", (xuv_8 - xuv_5));
	printf("Valor error: %e\n", (xuv_8 - xuv_5) / xuv_8);

	}

