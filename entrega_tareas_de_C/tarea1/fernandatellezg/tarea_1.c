#include<stdio.h>
//#include<float.h>
#include<math.h>
//math es para tener la funcion trunc
void main(){
	double x,y, x_5, y_5, u_5, v_5;
	double u=0.714251,v=98765.9, w=0.111111*1e-4; 
	double suma_8,mult_8, resta_8, resta_mult_8;
	double suma_5, mult_5, resta_5, resta_mult_5;
	double error_suma, error_r_suma, error_mult, error_r_mult;
	double error_resta, error_r_resta, error_resta_mult, error_r_resta_mult;
	int x_int, y_int,v_int, u_in, suma_int, mult_int, resta_int, resta_mult_int;
	/*asignamos valor de x y y*/
	x = 0.714285714285714285;
	y = 0.333333333333333333;
	/*truncamos y asignamos a x_5 y y_5*/
	x_int = x * 1e5;
	y_int = y * 1e5;
	x_5 = x_int * 1e-5;
	y_5 = y_int * 1e-5;

	/* Realizando operacion suma y asignando a las variables en las variables*/
	suma_int = (x + y)* 1e7;
	suma_8 = suma_int * 1e-7;
	suma_int = (x_5 + y_5)*1e4;
	suma_5 = suma_int * 1e-4;
	error_suma = (suma_8-suma_5);
	error_r_suma = error_suma / suma_8;
	/*Multiplicacion*/
	mult_int = (x * y) * 1e8;
	mult_8 = mult_int * 1e-8;
	mult_int = (x_5 * y_5) * 1e5;
	mult_5 = mult_int * 1e-5;
	error_mult = (mult_8 - mult_5);
	error_r_mult = error_mult / mult_8;
	/*Resta*/
	resta_int = (x - u)* 1e8;
	resta_8 = resta_int * 1e-8;
	u_in = u * 1e5;
	u_5 = u_in * 1e-5;
	resta_int = (x_5 - u_5)*1e5;
	resta_5 = resta_int * 1e-5;
	error_resta =( resta_8-resta_5);
	error_r_resta = error_resta/resta_8;
	/*Resta con multiplicacion*/
	resta_mult_int = ((x - u)*v)*1e8;
	resta_mult_8 = resta_mult_int *1e-8;
	v_int = v;
	v_5 =v_int * 1e-5;
	resta_mult_int = ((x_5 - u_5)*v_5)*1e5;
	resta_mult_5 = resta_mult_int * 1e-5;
	error_resta_mult=(resta_mult_8 - resta_mult_5);
	error_r_resta_mult = error_resta_mult/ resta_mult_8;

char  a_8[]="Valor_a_8";
char  a_5[]="Aritmética_de_máquina";
char err[]="Error_absoluto";
char err_r[]="Error_relativo";
char sum[]="x+y", mul[]="x*y", res[]="x-u",res_mul[]="(x-u)*v", op[]="Operación";

printf("%s \t \t %s \t \t %s \t \t %s \t \t %s\n",op, a_8, a_5, err, err_r );

printf("%s \t \t %0.8e \t \t %1.5e \t \t %0.8e \t \t \t %0.8e\n", sum, suma_8, suma_5, error_suma, error_r_suma );
printf("%s \t \t %0.8e \t \t %1.5e \t \t %0.8e \t \t \t %0.8e\n", mul, mult_8, mult_5, error_mult, error_r_mult );
printf("%s \t \t %0.8e \t \t %1.5e \t \t %0.8e \t \t \t %0.8e\n", res, resta_8, resta_5, error_resta, error_r_resta);
printf("%s \t \t %0.8e \t \t %1.5e \t \t %0.8e \t \t \t %0.8e\n", res_mul, resta_mult_8, resta_mult_5, error_resta_mult, error_r_resta_mult);
}
