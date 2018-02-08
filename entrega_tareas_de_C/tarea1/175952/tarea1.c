#include<stdio.h>
#include<math.h>

//gcc tarea-01.c -o tarea-01.out -lm

void main(){
        double x_8 = 5.0/7.0;
        double y_8 = 1.0/3.0;
        double u_8 = 0.714251;
        double v_8 = 98765.9;
        double x_5, y_5, u_5, v_5;
        double valor_a_8, maquina, err_a, err_r;

        x_5 = truncf(x_8*1e5)/1e5;
        y_5 = truncf(y_8*1e5)/1e5;
        u_5 = truncf(u_8*1e5)/1e5;
        v_5 = truncf(v_8*1e5)/1e5;

        printf("truncado con truncf x_5: %1.5f\n", x_5);
        printf("truncado con truncf y_5: %1.5f\n", y_5);
        printf("truncado con truncf u_5: %1.5f\n", u_5);
        printf("truncado con truncf v_5: %1.5f\n", v_5);
        printf("-------------[¬ | ¬]-----------------------\n\n");

        valor_a_8 = x_8 + y_8;
        maquina = x_5 + y_5;
        err_a = valor_a_8 - maquina;
        err_r = err_a / valor_a_8;


        printf("|Operacion \t |Valor a 8 \t |Aritmetica de Maquina \t |Err Abs \t |Err Rel\n");
        printf("|x + y \t\t |%f \t |%f \t\t |%e \t\t |%e \n", valor_a_8, maquina, err_a, err_r);

        printf("------------------------------------\n\n\n");

        valor_a_8 = x_8 * y_8;
        maquina = x_5 * y_5;
        err_a = valor_a_8 - maquina;
        err_r = err_a / valor_a_8;


        printf("|Operacion \t |Valor a 8 \t |Aritmetica de Maquina \t |Err Abs \t |Err Rel\n");
        printf("|x * y \t\t |%f \t |%f \t\t |%e \t\t |%e \n", valor_a_8, maquina, err_a, err_r);

        printf("------------------------------------\n\n\n");

        valor_a_8 = x_8 - u_8;
        maquina = x_5 - u_5;
        err_a = valor_a_8 - maquina;
        err_r = err_a / valor_a_8;


        printf("|Operacion \t |Valor a 8 \t |Aritmetica de Maquina \t |Err Abs \t |Err Rel\n");
        printf("|x - u \t\t |%f \t |%f \t\t |%e \t\t |%e \n", valor_a_8, maquina, err_a, err_r);

        printf("------------------------------------\n\n\n");

        valor_a_8 = (x_8 - u_8) * v_8;
        maquina = (x_5 - u_5) * v_5;
        err_a = valor_a_8 - maquina;
        err_r = err_a / valor_a_8;


        printf("|Operacion \t |Valor a 8 \t |Aritmetica de Maquina \t |Err Abs \t |Err Rel\n");
        printf("|(x - u)*v \t\t |%f \t |%f \t\t |%e \t\t |%e \n", valor_a_8, maquina, err_a, err_r);

        printf("------------------------------------\n\n\n");

}
