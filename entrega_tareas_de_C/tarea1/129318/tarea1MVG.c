//Author: Monica Vargas
//Equipo 8 (hacer las pares: x-y, x/y, (x-u)/w, u+v)

#include<stdio.h>
#include<math.h>

main(){
	int beta, ka;
	double x, y, u, v, w;
	//Inicialización de variables:
	beta = 10;
	ka = 5;
	x = 0.71428571;
	y = 0.33333333;
	u = 0.714251;
	v = 98765.9;
	w = 0.0000111111;

	//Valor Fl (truncadas) de las variables
	double  Fl_x, Fl_y, Fl_u, Fl_v, Fl_w;
	//función: truncf
	printf("Valor x con truncf: %1.5f", truncf(x));
	Fl_x = truncf(Fl_x*1e5)*1e-5;
	printf("Valor Fl_x: %e\n", Fl_x);

	printf("Valor y con truncf: %1.5f", truncf(y));
	Fl_y = truncf(Fl_y*1e5)*1e-5;
	printf("Valor Fl_y: %e\n", Fl_y);

	printf("Valor u con truncf: %1.5f", truncf(u));
	Fl_u = truncf(Fl_u*1e5)*1e-5;
	printf("Valor Fl_u: %e\n", Fl_u);

	printf("Valor v con truncf: %1.5f", truncf(v));
	Fl_v = truncf(Fl_v*1e5)*1e-5;
	printf("Valor Fl_v: %e\n", Fl_v);

	printf("Valor w con truncf: %1.5f", truncf(w));
	Fl_w = truncf(Fl_w*1e5)*1e-5;
	printf("Valor Fl_w: %e\n", Fl_w);

	//Realizamos las operaciones
		//1) x-y
		double op1_8, op1_arm, op1_errorA, op1_errorR;
		op1_8 = x - y;
		op1_arm = truncf((Fl_x-Fl_y)*1e5)*1e-5;
		op1_errorA = fabs(op1_8 - op1_arm);
		op1_errorR = op1_errorA/op1_arm;

		//2) x/y
		double op2_8, op2_arm, op2_errorA, op2_errorR;
		op2_8 = x/y;
		op2_arm = truncf((Fl_x/Fl_y)*1e5)*1e-5;
		op2_errorA = fabs(op2_8 - op2_arm);
		op2_errorR = op2_errorA/op2_arm;


		//3) (x-u)/w
		double op3_8, op3_arm, op3_errorA, op3_errorR;
		op3_8 = (x-u)/w;
		op3_arm = truncf(((Fl_x-Fl_u)/Fl_w)*1e5)*1e-5;
		op3_errorA = fabs(op3_8 - op3_arm);
		op3_errorR = op3_errorA/op3_arm;

		//4) u+v
		double op4_8, op4_arm, op4_errorA, op4_errorR;
		op4_8 = u+v;
		op4_arm = truncf((Fl_v+Fl_u)*1e5)*1e-5;
		op4_errorA = fabs(op4_8 - op4_arm);
		op4_errorR = op4_errorA/op4_arm;


printf("Operacion \t Valor a 8 \t Aritmetica de máquina \t   ErrA \t  ErrR \n");
printf("x+y \t  \t %1.8f \t \t %1.5f \t %1.6e \t %1.6e \n",op1_8, op1_arm, op1_errorA, op1_errorR);
printf("x/y \t  \t %1.8f \t \t %1.5f \t %1.6e \t %1.6e \n",op2_8, op2_arm, op2_errorA, op2_errorR);
printf("(x-u)/w \t  \t %1.8f \t \t %1.5f \t %1.6e \t %1.6e \n",op3_8, op3_arm, op3_errorA, op3_errorR);
printf("u+v \t  \t %1.8f \t \t %1.5f \t %1.6e \t %1.6e \n",op4_8, op4_arm, op4_errorA, op4_errorR);



}


