// Cristian Challu
// 120652
// Equipo 1

#include <stdio.h>
#include <math.h>

double pf(double i, int exp){
	// Esta funcion sirve para los numeros del ejercicio. Para hacerla mas general hay que considerar los casos en los que 
	// i es mayor a pow(10.0,exp-1).
	double factor = 1.0;
	while(i*factor <= pow(10.0,exp-1)){
		factor = factor*10.0;
	}
	return trunc(i*factor)/factor;
}

int main(){

	double x = pf(5.0/7.0,8);
	double y = pf(1.0/3.0,8);
	double u = pf(0.714251,8);
	double v = pf(98765.9,8);

	printf("Operacion |  Valor a 8  |   Maquina   |   ErrA   |   ErrR   \n");
	
	double valor = pf(x+y,8);
	double valor_5 = pf(pf(x,5)+pf(y,5),5);
	double error_a = fabs(valor - valor_5);
	double error_r = (error_a / valor);
	printf("x + y     %.8e  %.5e  %.2e  %.2e\n",valor,valor_5,error_a,error_r);
	
	valor = pf(x*y,8);
	valor_5 = pf(pf(x,5)*pf(y,5),5);
	error_a = fabs(valor - valor_5);
	error_r = (error_a / valor);
	printf("x * y     %.8e  %.5e  %.2e  %.2e\n",valor,valor_5,error_a,error_r);

	valor = pf(x-u,8);
	valor_5 = pf(pf(x,5)-pf(u,5),5);
	error_a = fabs(valor - valor_5);
	error_r = (error_a / valor);
	printf("x - u     %.8e  %.5e  %.2e  %.2e\n",valor,valor_5,error_a,error_r);

	valor = pf((x-u)*v,8);
	valor_5 = pf(pf(pf(x,5)-pf(u,5),5)*pf(v,5),5);
	error_a = fabs(valor - valor_5);
	error_r = (error_a / valor);
	printf("(x-u)*v   %.8e  %.5e  %.2e  %.2e\n",valor,valor_5,error_a,error_r);

	return 0;
}
