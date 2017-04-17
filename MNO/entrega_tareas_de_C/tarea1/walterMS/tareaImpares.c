#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){

    double x = 5/7.0;
    double y = 1/3.0;
    double u = 0.71428571;
    double v = 0.33333333;

    

    double xf =(truncf(x*1e5))*1e-5;
    double yf = (truncf(y*1e5))*1e-5;
    //printf("xf = %1.4e\n",xf);
    //printf("yf = %1.4e\n",yf);
    double uf =(truncf(u*1e5))*1e-5;
    double vf =(truncf(v*1e5))*1e-5;
    //printf("uf = %1.4e\n",uf);
    //printf("vf = %1.4e\n",vf);

    double op1_5 = (truncf((xf+yf)*1e5))*1e-5;
    double op2_5 = (truncf((xf*yf)*1e5))*1e-5;
    double op3_5 = (truncf((xf-uf)*1e5))*1e-5;
    double op4_5 = truncf((truncf((xf-uf)*1e5))*1e-5*vf*1e5)*1e-5;
    //printf("\nxf+yf = %1.4e\n",op1_5);

    double xf8 =(truncf(x*1e8))*1e-8;
    double yf8 = (truncf(y*1e8))*1e-8;
    double op1_8 = (truncf((xf8+yf8)*1e8))*1e-8;
    double op2_8 = (truncf((xf8*yf8)*1e8))*1e-8;
    double op3_8 = (truncf((xf8-u)*1e8))*1e-8;
    double op4_8 = truncf((truncf((xf8-u)*1e8))*1e-8*v*1e8)*1e-8;
   // printf("\nxf+yf = %1.7e\n",op1_8);

    double err_abs1 = op1_8 - op1_5;
    double err_rel1 = (op1_8 - op1_5)/op1_8;
    double err_abs2 = op2_8 - op2_5;
    double err_rel2 = (op2_8 - op2_5)/op2_8;
    double err_abs3 = op3_8 - op3_5;
    double err_rel3 = (op3_8 - op3_5)/op3_8;
    double err_abs4 = op4_8 - op4_5;
    double err_rel4 = (op4_8 - op4_5)/op4_8;
    //printf("El primer error absoluto es %1.8e\n" , err_abs1);
   // printf("El primer error absoluto es %1.8e\n" , err_rel1);

    printf("\nOperacion\t\tValor 8\t\t     Aritmetica maquina    \tErrorA\t\tErrorR\n");
    printf("\nx+y          \t\t%1.7e \t      %1.4e\t\t %e \t %e", op1_8,op1_5, err_abs1,err_rel1);
    printf("\nx*y          \t\t%1.7e \t      %1.4e\t\t %e \t %e", op2_8,op2_5, err_abs2,err_rel2);
    printf("\nx+y          \t\t%1.7e       %1.4e\t         %e  %e", op3_8,op3_5, err_abs3,err_rel3);
    printf("\nx+y          \t\t%1.7e       %1.4e\t         %e  %e", op4_8,op4_5, err_abs4,err_rel4);




    return 0;
}