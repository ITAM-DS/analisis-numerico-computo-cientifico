//Equipo 12  Carlos Castro Correa 103531
#include<stdio.h>
#include<math.h>
main(){
	//definimos todas las variables
        double x = 5.0/7.0;
        double y = 1.0/3.0;
        double u = 0.714251;
        double v = 98765.9;
        double w = 0.0000111111;

	// Resta
	printf("X - Y \n");

	// Resta 8 digitos
	double resta_8 = trunc((x - y)*100000000) / 100000000;
        printf("Resta_8digitos: %1.8f \n", resta_8);
	// Resta aritmetica
        double x_resta = trunc(x * 100000) / 100000;
	double y_resta = trunc(y * 100000) / 100000;
	double resta = ((x_resta - y_resta) * 100000) / 100000;
        printf("Resta_aritmetica: %1.5f \n", resta);
	// Resta error A
  	double resta_err_a = (x-y) -(x_resta - y_resta);
	printf("Resta_error_a: %1.8f \n", resta_err_a);
	// Resta error R
	double resta_err_r =  resta_err_a / (x-y);
	printf("Resta_error_r: %1.8f \n", resta_err_r);
	printf("\n");


	// Division
        printf("X / Y \n");

	//Division 8 digitos
        double div_8 = trunc((x/y)*10000000) / 10000000;
        printf("Multiplicacion_8digitos: %1.7f \n", div_8);
	//Division  aritmetica
        double x_div = trunc(x * 10000) / 10000;
        double y_div = trunc(y * 10000) / 10000;
        double div = ((x_div / y_div) * 10000) / 10000;
        printf("Multiplicacion_aritmetica: %1.4f \n", div);
        // Dvision error A
        double div_err_a = fabs((x_div/y_div) - (x / y));
        printf("Multiplicacion_error_a: %1.8f \n", div_err_a);
        // Division error R
        double div_err_r = fabs( div_err_a / (x/y));
        printf("Multiplicacion_error_r: %1.8f \n", div_err_r);
        printf("\n");

	//Resta_U / W
 	printf("(X-U)/W \n");

        //Resta_U 8 digitos
        double op_8 = trunc(((x-u)/w)*10000000) / 10000000;
        printf("8digitos: %1.7f \n", op_8);
        //Division  aritmetica
        double x_op = trunc(x * 100000) / 100000;
        double u_op = trunc(u * 100000) / 100000;
        double w_op = trunc(w * 100000) / 100000;
        double op = ( ((x_op -  u_op) / w_op)  * 100000) / 100000;
        printf("Aritmetica: %1.4f \n", op);
	//Error A
	double op_err_a = fabs( op - ((x-u)/w) );
        printf("Error_a: %1.8f \n", op_err_a);
        //Error R
        double op_err_r = fabs( op_err_a / ((x-u) /w ));
        printf("Multiplicacion_error_r: %1.8f \n", op_err_r);
        printf("\n");


        // Suma
        printf("X + V \n");

        // Resta 8 digitos
        double suma_8 = trunc((x + v)*100000000) / 100000000;
        printf("Resta_8digitos: %1.8f \n", suma_8);
        // Resta aritmetica
        double x_suma = trunc(x * 100000) / 100000;
        double v_suma = trunc(v * 100000) / 100000;
        double suma  = ((x_suma + v_suma) * 100000) / 100000;
        printf("Resta_aritmetica: %1.5f \n", suma);
        // Resta error A
        double suma_err_a = (x+v) -(x_suma + v_suma);
        printf("Resta_error_a: %1.8f \n", suma_err_a);
        // Resta error R
        double suma_err_r =  suma_err_a / fabs(x+v);
        printf("Resta_error_r: %1.8f \n", suma_err_r);
        printf("\n");
}


