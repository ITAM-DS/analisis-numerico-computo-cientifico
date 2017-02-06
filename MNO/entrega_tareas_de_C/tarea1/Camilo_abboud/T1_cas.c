#include <stdio.h>
#include <math.h>
int main(){
//digitos originales
    double x_8 = 0.71428571;
    double y_8 = 0.33333333;
    double u_8 = 0.714251;
    double v_8 = 98765.9;

//funcion truncf
    double x_5 = truncf(x_8 * 1e5) / 1e5;
    double y_5 = truncf(y_8 * 1e5) / 1e5;
    double u_5 = truncf(u_8 * 1e5) / 1e5;
    double v_5 = truncf(v_8 * 1e5) / 1e5;
//encabezados de la tabla
    printf("Operacion \t Valor a 8 \t Aritmetica de maquina \t \t ErrA \t  \t \t ErrR \n");
//suma
    double res_8 = x_8 + y_8;
    double res_5 = x_5 + y_5;
    res_5 = truncf(res_5 * 1e5) / 1e5;
    double errA = fabs(res_8 - res_5);
    double errR = errA / fabs(res_8);
    printf("x+y \t \t %f \t \t %f \t \t %1.2e \t \t %1.2e \n", res_8, res_5, errA, errR);
//multiplicacion
    res_8 = x_8 * y_8;
    res_5 = x_5 * y_5;
    res_5 = truncf(res_5 * 1e5) / 1e5;
    errA = fabs(res_8 - res_5);
    errR = errA / fabs(res_8);
    printf("x*y \t \t %f \t \t %f \t \t %1.2e \t \t %1.2e \n", res_8, res_5, errA, errR);
//resta
    res_8 = x_8 - u_8;
    res_5 = x_5 - u_5;
    res_5 = truncf(res_5 * 1e5) / 1e5;
    errA = fabs(res_8 - res_5);
    errR = errA / fabs(res_8);
    printf("x-u \t \t %f \t \t %f \t \t %1.2e \t \t %1.2e \n", res_8, res_5, errA, errR);
//resta y multiplicacion
    res_8 = (x_8 - u_8) * v_8;
    res_5 = (x_5 - u_5) * v_5;
    res_5 = truncf(res_5 * 1e5) / 1e5;
    errA = fabs(res_8 - res_5);
    errR = errA / fabs(res_8);
    printf("(x-u)*v \t %f \t \t %f \t \t %1.2e \t \t %1.2e \n", res_8, res_5, errA, errR);
}