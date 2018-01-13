//Tarea 1 by  Ricardo Lastra
//Operaciones nones


#include<stdio.h>
#include<math.h>


void main(){
        double x_8 = 0.71428571;
        double y_8 = 0.33333333;
        double u_8 = 0.714251;
        double v_8 = 98765.9;
        double x_5, y_5, u_5, v_5;
        double valor_a_8, maquina, err_absoluto, err_relativo;

	//Usamos la funcion TRUNCF


        x_5 = truncf(x_8*100000)/100000;
        y_5 = truncf(y_8*100000)/100000;
        u_5 = truncf(u_8*100000)/100000;
        v_5 = truncf(v_8*100000)/100000;

        printf("truncado con truncf x_5: %1.5f\n", x_5);
        printf("truncado con truncf y_5: %1.5f\n", y_5);
        printf("truncado con truncf u_5: %1.5f\n", u_5);
        printf("truncado con truncf v_5: %1.5f\n", v_5);
        printf("-------------[¬ | ¬]-----------------------\n\n");

        valor_a_8 = x_8 + y_8;
        maquina = x_5 + y_5;
        err_absoluto = valor_a_8 - maquina;
        err_relativo = err_absoluto / valor_a_8;


        printf("|Operacion \t |Valor a 8 \t |Aritmetica de Maquina \t |Err Abs \t |Err Rel \n");
        printf("|X + Y \t\t |%f \t |%f \t\t |%e \t\t |%e \n", valor_a_8, maquina, err_absoluto, err_relativo);

        printf("------------------------------------\n\n\n");

        valor_a_8 = x_8 * y_8;
        maquina = x_5 * y_5;
        err_absoluto = valor_a_8 - maquina;
        err_relativo = err_absoluto / valor_a_8;


        printf("|Operacion \t |Valor a 8 \t |Aritmetica de Maquina \t |Err Abs \t |Err Rel\n");
        printf("|X * Y \t\t |%f \t |%f \t\t |%e \t\t |%e \n", valor_a_8, maquina, err_absoluto, err_relativo);

        printf("------------------------------------\n\n\n");

        valor_a_8 = x_8 - u_8;
        maquina = x_5 - u_5;
        err_absoluto = valor_a_8 - maquina;
        err_relativo = err_absoluto / valor_a_8;


        printf("|Operacion \t |Valor a 8 \t |Aritmetica de Maquina \t |Err Abs \t |Err Rel\n");
        printf("|X - Y \t\t |%f \t |%f \t\t |%e \t\t |%e \n", valor_a_8, maquina, err_absoluto, err_relativo);

        printf("------------------------------------\n\n\n");

        valor_a_8 = (x_8 - u_8) * v_8;
        maquina = (x_5 - u_5) * v_5;
        err_absoluto = valor_a_8 - maquina;
        err_relativo = err_absoluto / valor_a_8;


        printf("|Operacion \t |Valor a 8 \t |Aritmetica de Maquina \t |Err Abs \t |Err Rel\n");
        printf("|X - Y \t\t |%f \t |%f \t\t |%e \t\t |%e \n", valor_a_8, maquina, err_absoluto, err_relativo);

        printf("------------------------------------\n\n\n");

}
