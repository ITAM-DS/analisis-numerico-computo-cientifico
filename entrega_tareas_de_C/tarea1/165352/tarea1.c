#include<stdio.h>
#include<math.h>
int main(){
	double x_8 = 0.71428571;
	double y_8 = 0.33333333;

	double v_8 = 98765.9, u_8 = 0.714251;

	double v_5 = truncf(v_8*1e5)*1e-5, u_5 = truncf(u_8*1e5)*1e-5;

	double erra, errr;

	double x_5 = truncf(x_8*1e5)*1e-5;
	double y_5 = truncf(y_8*1e5)*1e-5;

	double resultado_8;
	double resultado_5;

	printf("Operacion	Valor a 8	Aritmetica de maquina	ErrA		ErrR\n");

	resultado_8 = x_8 + y_8;
	//Como el resultado presenta un digito no decimal, lo truncamos a 7 decimales para que en total sean 8 digitos
	resultado_8 = truncf(resultado_8*1e7)*1e-7;

	resultado_5 = x_5 + y_5;
	//Como el resultado presenta un digito no decimal, lo truncamos a 4 decimales para que en total sean 5 digitos
	resultado_5 = truncf(resultado_5*1e4)*1e-4;

	erra = fabs(resultado_8 - resultado_5);

	errr = fabs(resultado_8 - resultado_5) / fabs(resultado_8);

	printf("x + y		%1.7e	%1.4e		%1.3e	%1.3e\n",resultado_8, resultado_5, erra, errr);

	resultado_8 = x_8*y_8;
	resultado_8 = truncf(resultado_8*1e8)*1e-8;

	resultado_5 = x_5*y_5;
	resultado_5 = truncf(resultado_5*1e5)*1e-5;

	erra =fabs(resultado_8 - resultado_5);

        errr =fabs(resultado_8 - resultado_5) / fabs(resultado_8);

        printf("x * y           %1.7e	%1.4e		%1.3e	%1.3e\n",resultado_8, resultado_5, erra, errr);

	resultado_8 = x_8 - u_8;
	resultado_8 = truncf(resultado_8*1e8)*1e-8;

        resultado_5 = x_5 - u_5;
        resultado_5 = truncf(resultado_5*1e5)*1e-5;

        erra =fabs(resultado_8 - resultado_5);

        errr =fabs(resultado_8 - resultado_5) / fabs(resultado_8);

        printf("x - u		%1.7e	%1.4e		%1.3e	%1.3e\n",resultado_8, resultado_5, erra, errr);
	
	resultado_8 = resultado_8*v_8;
	//Como el resultado presenta un digito no decimal, lo truncamos a 7 decimales para que en total sean 8 digitos
	resultado_8 = truncf(resultado_8*1e7)*1e-7;

        resultado_5 = resultado_5*v_5;
	//Como el resultado presenta un digito no decimal, lo truncamos a 4 decimales para que en total sean 5 digitos
        resultado_5 = truncf(resultado_5*1e4)*1e-4;

        erra =fabs(resultado_8 - resultado_5);

        errr =erra / fabs(resultado_8);

        printf("(x - u)*v	%1.7e	%1.4e		%1.3e	%1.3e\n",resultado_8, resultado_5, erra, errr);

}

