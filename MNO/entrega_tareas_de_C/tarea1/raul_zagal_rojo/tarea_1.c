// Tarea 1
// Raúl Zagal Rojo

#include <stdio.h>
#include <math.h>

double trun5(double x){
	return truncf(x*1e5)/1e5;
}

double trun8(double x){
	return truncf(x*1e8)/1e8;
}

double err_abs(double x, double y){
	return fabs(x-y);
}

double err_rel(double x, double y){
	return (x-y)/x;
}


int main(){
	double x_8 = 0.71428571;
    double y_8 = 0.33333333;
    double u_8 = 0.714251;
    double v_8 = 98765.9;

	double x_5 = trun5(x_8);
    double y_5 = trun5(y_8);
    double u_5 = trun5(u_8);
    double v_5 = trun5(v_8);

    double op1_8 = trun8(x_8 + y_8);
    double op2_8 = trun8(x_8 * y_8);
    double op3_8 = trun8(x_8 - u_8);
    double op4_8 = trun8((x_8 - u_8) * v_8);

    double op1_5 = trun5(x_5 + y_5);
    double op2_5 = trun5(x_5 * y_5);
    double op3_5 = trun5(x_5 - u_5);
    double op4_5 = trun5((x_5 - u_5) * v_5);


    //printf("%1.8f", truncf(v_8));

    printf("Operación \t\t Valoa a 8 \t\t Arit. de Máquina \t Err Abs \t Err R \n");
    printf("x + y \t\t\t %1.8f \t\t %1.8f \t\t %1.8f \t\t %1.8f %% \n", op1_8, op1_5, err_abs(op1_8, op1_5), err_rel(op1_8, op1_5)*100 );
    printf("x * y \t\t\t %1.8f \t\t %1.8f \t\t %1.8f \t\t %1.8f %% \n", op2_8, op2_5, err_abs(op2_8, op2_5), err_rel(op2_8, op2_5)*100 );
    printf("x - u \t\t\t %1.8f \t\t %1.8f \t\t %1.8f \t\t %1.8f %% \n", op3_8, op3_5, err_abs(op3_8, op3_5), err_rel(op3_8, op3_5)*100 );
    printf("(x - u)/v \t\t %1.8f \t\t %1.8f \t\t %1.8f \t\t %1.8f %% \n", op4_8, op4_5, err_abs(op4_8, op4_5), err_rel(op4_8, op4_5)*100 );
    

	return 0;
}

