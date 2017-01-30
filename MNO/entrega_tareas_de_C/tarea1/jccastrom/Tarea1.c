#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main(){
    double x = 5/7;
    double y = 1/3;
    double u = 0.71428571;
    double v = 0.33333333;
    //definimos las variables doble
    double xf =(truncf(x*1e5))*1e-5;
    double yf =(truncf(y*1e5))*1e-5;
    double uf =(truncf(u*1e5))*1e-5;
    double vf =(truncf(v*1e5))*1e-5;
    //Operaciones con valor a 8
    double op1_8 = x+y;
    double op3_8 = x*y;
    double op5_8 = x-u;
    double op7_8 = (x-u)*v;
    //Operaciones con maquina de 5
    double op1_5 = (truncf((xf+yf)*1e5))*1e-5;
    double op3_5 = (truncf((xf*yf)*1e5))*1e-5;
    double op5_5 = (truncf((xf-uf)*1e5))*1e-5;
    double op7_5 = (truncf((op5_5*vf)*1e5))*1e-5;
    //errores absolutos
    double err_abs1 = abs(op1_8 - op1_5);
    double err_abs3 = abs(op3_8 - op3_5);
    double err_abs5 = abs(op5_8 - op5_5);
    double err_abs7 = abs(op7_8 - op7_5);

    //errores relativos
    double err_rel1 = abs(op1_8 - op1_5)/err_abs1;
    double err_rel3 = abs(op3_8 - op3_5)/err_abs3;
    double err_rel5 = abs(op5_8 - op5_5)/err_abs5;
    double err_rel7 = abs(op7_8 - op7_5)/err_abs7;

    //aquí imprimimos los resultados de las operaciones a 8 dígitos
    printf("La primera operación en valor a 8 vale %e\n" , op1_8);
    printf("La tercera operación en valor a 8 vale %e\n" , op3_8);
    printf("La quinta operación en valor a 8 vale %e\n" , op5_8);
    printf("La septima operación en valor a 8 vale %e\n" , op7_8);	
    
    //aquí imprimimos los resultados de las operaciones a 5 dígitos
    printf("La primera operación en valor a 5 vale %e\n" , op1_5);
    printf("La tercera operación en valor a 5 vale %e\n" , op3_5);
    printf("La quinta operación en valor a 5 vale %e\n" , op5_5);
    printf("La septima operación en valor a 5 vale %e\n" , op7_5); 

    //aquí imprimimos los errores absolutos
    printf("El primer error absoluto es %e\n" , err_abs1);
    printf("El tercer error absoluto es %e\n" , err_abs3);
    printf("El quinto error absoluto es %e\n" , err_abs5);
    printf("El septimo error absoluto es %e\n" , err_abs7); 

    //aquí imprimimos los errores relativos 
    printf("El primer error relativo es %e\n" , err_rel1);
    printf("El tercer error relativo es %e\n" , err_rel3);
    printf("El quinto error relativo es %e\n" , err_rel5);
    printf("El septimo error relativo es %e\n" , err_rel7); 
    return 0;
}
