#include<stdio.h>
#include<math.h>
int main(){
	double x_8 = 0.71428571;
	double y_8 = 0.33333333;
	double u_8 = 0.7142251;
	double v_8 = 98765.9;

	double x_5;
	double y_5;
	double u_5;
	double v_5;

	double erra;
	double errb;

	double suma;
	double suma_2;
	double producto;
	double producto_2;
	double resta;
	double resta_2;
	double combo;
	double combo_2;

	printf("Valor x_8: %1.5e\n", x_8);
	x_5 = truncf(x_8*1e5)*1e-5;
	printf("Valor x_5: %1.5e\n\n",x_5);

	printf("Valor y_8: %1.5e\n", y_8);
	y_5 = truncf(y_8*1e5)*1e-5;
	printf("Valor y_5: %1.5e\n\n",y_5);

	printf("Valor u_8: %1.5e\n", u_8);
	u_5 = truncf(u_8*1e5)*1e-5;
	printf("Valor u_5: %1.5e\n\n",u_5);

	printf("Valor v_8: %1.5e\n", v_8);
	v_5 = truncf(v_8*1e5)*1e-5;
	printf("Valor v_5: %1.5e\n\n",v_5);


// Primera operación: suma
	suma = x_8 + y_8;
	suma_2 = truncf((x_5 + y_5)*1e5)*1e-5;
	erra = fabs(suma - suma_2);
	errb = fabs((suma - suma_2)/suma);

	printf("Valor x+y    : %1.8e\n", suma);
	printf("Valor x+y maq: %1.5e\n",suma_2);
	printf("Valor erra   : %1.5e\n", erra);
	printf("Valor errb   : %1.5e\n\n",errb);

// Segunda operación: multiplicacion
	producto = x_8 * y_8;
	producto_2 = truncf((x_5 * y_5)*1e5)*1e-5;
	erra = fabs(producto - producto_2);
	errb = fabs((producto - producto_2)/producto);

	printf("Valor x*y    : %1.8e\n", producto);
	printf("Valor x*y maq: %1.5e\n",producto_2);
	printf("Valor erra   : %1.5e\n", erra);
	printf("Valor errb   : %1.5e\n\n",errb);

// Tercera operación: resta
	resta = x_8 - u_8;
	resta_2 = truncf((x_5 - u_5)*1e5)*1e-5;
	erra = fabs(resta - resta_2);
	errb = fabs((resta - resta_2)/resta);

	printf("Valor x-u    : %1.8e\n", resta);
	printf("Valor x-u maq: %1.5e\n",resta_2);
	printf("Valor erra   : %1.5e\n", erra);
	printf("Valor errb   : %1.5e\n\n",errb);


// Cuarta operación: combo
	combo = (x_8 - u_8)/ v_8;
	combo_2 = truncf(((x_5 - u_5)/v_5)*1e5)*1e-5;
	erra = fabs(combo - combo_2);
	errb = fabs((combo - combo_2)/combo);

	printf("Valor (x-u)/v	 : %1.8e\n", combo);
	printf("Valor (x-u)/v maq: %1.5e\n",combo_2);
	printf("Valor erra	 : %1.5e\n", erra);
	printf("Valor errb	 : %1.5e\n\n",errb);

}
