#include<stdio.h>
#include<math.h>
main(){
double x_8 = 0.71428571;
double y_8 = 0.33333333;
double u_8 = 0.714251;
double v_8 = 98765.9;
double x_5 = truncf(x_8*1e5)/1e5;
double y_5 = truncf(y_8*1e5)/1e5;
double u_5 = truncf(u_8*1e5)/1e5;
double v_5 = truncf(v_8*1e5)/1e5;
double valor_8 = x_8+y_8;
double valor_5 = x_5+y_5;
valor_5 = truncf(valor_5 * 1e4)/1e4;
double err_A = truncf((valor_8 - valor_5)*1e8)/1e8;
double err_R = err_A/valor_8;
printf("Operacion \t Valor a 8 \t Aritmetica de Maq \t Err Abs \t Err Rel\n");
printf("X + Y \t \t %f \t \t %f \t %e \t %e \n", valor_8, valor_5, err_A, err_R);
valor_8 = x_8 * y_8;
valor_5 = x_5 * y_5;
valor_5 = truncf(valor_5 * 1e4)/1e4;
err_A = truncf((valor_8 - valor_5)*1e8)/1e8;
err_R = err_A/valor_8;
printf("X * Y \t \t %f \t \t %f \t %e \t %e \n", valor_8, valor_5, err_A, err_R);
valor_8 = x_8-u_8;
valor_5 = x_5-u_5;
valor_5 = truncf(valor_5 * 1e4)/1e4;
err_A = truncf((valor_8 - valor_5)*1e8)/1e8;
err_R = err_A/valor_8;
printf("X - U \t \t %f \t \t %f \t %e \t %e \n", valor_8, valor_5, err_A, err_R);
valor_8 = (x_8-u_8)*v_8;
valor_5 = (x_5-u_5)*v_5;
valor_5 = truncf(valor_5 * 1e4)/1e4;
err_A = truncf((valor_8 - valor_5)*1e8)/1e8;
err_R = err_A/valor_8;
printf("(X - U)*V \t %f \t \t %f \t %e \t %e \n", valor_8, valor_5, err_A, err_R);
}
