#include<stdio.h>
#include<math.h>

main(){
	
        // Definir variables

	double x = 5.0/7.0;
	double y = 1.0/3.0;
	double u = 0.714251;
	double v = 98765.9;
	double w = 0.111111e-4;
	double x_t, y_t, u_t, v_t, w_t;
	double a8, a5, err_a, err_r;


	// Definir variables truncadas
	x_t = truncf(x*10000)/10000;
	y_t = truncf(y*10000)/10000;
	u_t = truncf(u*10000)/10000;
	v_t = truncf(v*10000)/10000;
	w_t = truncf(w*10000)/10000;

	// header
	printf("Operación \tValor a 8 dig\tArit de maq.\tErr Abs\t\tErr Rel\n");

	// x + y
	a8 = x + y;
	a8 = truncf(a8*10000000)/10000000;
	a5 = x_t + y_t;
	a5 = truncf(a5*10000)/10000;
        err_a = a8 - a5;
	
	printf("x + y\t\t");
	printf("%1.7e\t", a8);
	printf("%1.4e\t", a5);
	printf("%e\t", err_a);
	printf("%e\n",  err_a/a8);
	
	// x * y
	a8 = x * y;
	a8 = truncf(a8*10000000)/10000000;
	a5 = x_t * y_t;
	a5 = truncf(a5*10000)/10000;
	err_a = a8 -a5;

	printf("x * y\t\t");
	printf("%1.7e\t", a8);
	printf("%1.4e\t", a5);
	printf("%e\t", err_a);
	printf("%e\n",  err_a/a8);
	
	
	// x - u
        a8 = x - u;
        a8 = truncf(a8*10000000)/10000000;
        a5 = x_t - u_t;
        a5 = truncf(a5*10000)/10000;
        err_a = a8 - a5;

        printf("x - u\t\t");	
	printf("%1.7e\t", a8);
	printf("%1.4e\t", a5);
	printf("%e\t", err_a);
	printf("%e\n",  err_a/a8);
	

        // (x - u)v
        a8 = x - u;
        a8 = truncf(a8*10000000)/10000000;
	a8 = a8 * v;
	a8 = truncf(a8*10000000)/10000000;
	a5 = x_t - u_t;
        a5 = truncf(a5*10000)/10000;
	a5 = a5 * v_t;
	a5 = truncf(a5*10000)/10000;
        err_a = a8 - a5;

        printf("(x - u)v\t");
	printf("%1.7e\t", a8);
	printf("%1.4e\t", a5);
	printf("%e\t", err_a);
	printf("%e\n",  err_a/a8);
	

}
