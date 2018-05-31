#include<stdio.h>
#include<math.h>
main(){
//Variables a usar
	double x_8 = 0.71428571;
	double y_8 = 0.33333333;
	double u_8 = 0.714251;
	double v_8 = 98765.9;
	double w_8 = 0.111111e-4;
//Resta
	double resta_8 = x_8-y_8;
	double resta_5_aux =(truncf(x_8*1e5)*1e-5)-(truncf(y_8*1e5)*1e-5);
	double resta_5 = truncf(resta_5_aux*1e5)*1e-5;
	double resta_ab = fabs(resta_8 - resta_5);
	double resta_re = fabs(resta_ab/resta_8); 
printf("\nOperacion	Valor a 8	Aritmética de Maquina	ErrA		ErrR\n");
printf("x-y		%1.8f		%1.5f		%1.8f	%1.8f\n",resta_8,resta_5,resta_ab,resta_re);
//División	
	double div_8 = x_8/y_8;
	double div_5_aux = (truncf(x_8*1e5)*1e-5)/(truncf(y_8*1e5)*1e-5);
	double div_5 = truncf(div_5_aux*1e5)*1e-5;
	double div_ab = fabs(div_8-div_5);
	double div_re = fabs(div_ab/div_8);
printf("x/y             %1.8f          	%1.5f         %1.8f  	%1.8f\n",div_8,div_5,div_ab,div_re);
//Resta y división
        double rdiv_8 = (x_8-u_8)/w_8;
        double rdiv_5_aux1 = (truncf(x_8*1e5)*1e-5)-(truncf(u_8*1e5)*1e-5);
	double rdiv_5_aux2 = rdiv_5_aux1/(truncf(w_8*1e5)*1e-5);
     	double rdiv_5 = truncf(rdiv_5_aux2*1e5)*1e-5;
        double rdiv_ab = fabs(rdiv_8-rdiv_5);
        double rdiv_re = fabs(rdiv_ab/rdiv_8);
printf("(x-u)/w         %1.8f           	%1.5f         %1.8f      %1.8f\n",rdiv_8,rdiv_5,rdiv_ab,rdiv_re);
//u mas v
        double sum_8 = u_8+v_8;
        double sum_5_aux = (truncf(u_8*1e5)*1e-5)+(truncf(v_8*1e5)*1e-5);
        double sum_5 = truncf(sum_5_aux*1e5)*1e-5;
        double sum_ab = fabs(sum_8-sum_5);
        double sum_re = fabs(sum_ab/sum_8);
printf("u+v	        %1.8f          %1.5f     %1.8f      %1.8f\n",sum_8,sum_5,sum_ab,sum_re);

}
