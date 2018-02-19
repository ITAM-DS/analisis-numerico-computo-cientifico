#include<stdio.h>
#include<math.h>
main(){
	/*
	Se debe llenar la tabla para las operaciones siguientes, considerando
	un SPFN base 10 y precisión 5:
	x+y, xy, x-u, (x-u)v
	*/

	//Inicialización de variables:
	double x, y, v, u;
	double x_5, y_5, u_5, v_5;
	double out8, out5, err_a, err_r;
	//	x = 5/7
	x = 0.71428571;
	x_5 = truncf(x*1e5)*1e-5;
	//	y = 1/3
	y = 0.33333333;
	y_5 = truncf(y*1e5)*1e-5;
	//	u = 0.714251
	u = 0.714251;
	u_5 = truncf(u*1e5)*1e-5;
	//	v = 98765.9
	v = 98765.9;
	v_5 = truncf(v*1e5)*1e-5;
	// Se rellena la tabla
	printf("Operación\t");
	printf("Valor a 8\t");
	printf("Aritmética de la máquina\t");
	printf("Error Absoluto\t");
	printf("Error Relativo\n");
	//	x + y
	out8 = x + y;
	out8 = truncf(out8*1e8)*1e-8;
	out5 = x_5 + y_5;
	out5 = truncf(out5*1e5)*1e-5;
	printf("x + y\t\t");
	printf("%1.7e\t",out8);
	printf("%1.4e\t\t\t", out5);
	err_a = out8 - out5;
	printf("%e\t", err_a);
	err_r = err_a/out8;
	printf("%e\n", err_r);
	//	x * y
	out8 = x * y;
	out8 = truncf(out8*1e8)*1e-8;
	out5 = x_5 * y_5;
	out5 = truncf(out5*1e5)*1e-5;
	printf("x * y\t\t");
	printf("%1.7e\t",out8);
	printf("%1.4e\t\t\t", out5);
	err_a = out8 - out5;
	printf("%e\t", err_a);
	err_r = err_a/out8;
	printf("%e\n", err_r);
	//	x - u
        out8 = x - u;
        out8 = truncf(out8*1e8)*1e-8;
        out5 = x_5 - u_5;
        out5 = truncf(out5*1e5)*1e-5;
        printf("x - u\t\t");
        printf("%1.7e\t",out8);
        printf("%1.4e\t\t\t", out5);
        err_a = out8 - out5;
        printf("%e\t", err_a);
        err_r = err_a/out8;
        printf("%e\n", err_r);

        //     (x - u)v
        out8 = x - u;
        out8 = truncf(out8*1e8)*1e-8;
	out8 = out8 * v;
	out8 = truncf(out8*1e8)*1e-8;
	out5 = x_5 - u_5;
        out5 = truncf(out5*1e5)*1e-5;
	out5 = out5 * v_5;
	out5 = truncf(out5*1e5)*1e-5;
        printf("(x - u)v\t");
        printf("%1.7e\t",out8);
        printf("%1.4e\t\t\t", out5);
        err_a = out8 - out5;
        printf("%e\t", err_a);
        err_r = err_a/out8;
        printf("%e\n", err_r);

}
