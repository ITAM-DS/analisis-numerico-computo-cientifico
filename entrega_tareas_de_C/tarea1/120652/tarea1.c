// Cristian Challu
// 120652
// Equipo 1

#include <stdio.h>
#include <math.h>

double pf(double i, double exp){
	// Esta funcion sirve para los numeros del ejercicio. Para hacerla mas general hay que considerar los casos en los que 
	// i es mayor a pow(10.0,exp-1).
	double factor = 1.0;
	while(i*factor <= pow(10.0,exp-1)){
		factor = factor*10.0;
	}
	return round(i*factor)/factor;
}

int main(){
	// Nota: entendi del ejemplo en clase que para el valor verdadero se redonde a 8 cifras SOLO al final, no antes de
	// realizar las operaciones como es el caso para la aritmetica de maquina.
	double x = 5.0/7.0;
	double y = 1.0/3.0;
	double u = 0.714251;
	double v = 98765.9;
	double w = 0.111111E-4;
	
	printf("Operacion |  Valor a 8  |   Maquina   |   ErrA   |   ErrR   \n");

	double valor = pf(x+y,8);
	double valor_5 = pf(pf(x,5)+pf(y,5),5);
	double error_a = fabs(valor - valor_5);
	double error_r = (error_a / valor);
	printf("x + y     %.8e  %.5e  %.3e  %.3e\n",valor,valor_5,error_a,error_r);
	
	valor = pf(x*y,8);
	valor_5 = pf(pf(x,5)*pf(y,5),5);
	error_a = fabs(valor - valor_5);
	error_r = (error_a / valor);
	printf("x * y     %.8e  %.5e  %.3e  %.3e\n",valor,valor_5,error_a,error_r);

	valor = pf(x-u,8);
	valor_5 = pf(pf(x,5)-pf(u,5),5);
	error_a = fabs(valor - valor_5);
	error_r = (error_a / valor);
	printf("x - u     %.8e  %.5e  %.3e  %.3e\n",valor,valor_5,error_a,error_r);

	valor = pf((x-u)*v,8);
	valor_5 = pf(pf(pf(x,5)-pf(u,5),5)*pf(v,5),5);
	error_a = fabs(valor - valor_5);
	error_r = (error_a / valor);
	printf("(x-u)*v   %.8e  %.5e  %.3e  %.3e\n",valor,valor_5,error_a,error_r);


	return 0;
}
