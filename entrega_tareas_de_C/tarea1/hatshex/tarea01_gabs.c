/*
# Métodos Numéricos y de Optimización
## Tarea 01
### Gabriela Flores Bracamontes | 160124 
*/
#include<stdio.h>
#include<math.h>
main(){
//Definicion y declaracion de variables

      double x_8 = 0.71428571, y_8 = 0.33333333, u_8 = 0.71425100, v_8 = 98765.900, w_8 = 0.111111e-4;
      double x_5, y_5, u_5, v_5, w_5, operacion_8, operacion_5, ErrorA, ErrorR;

	double error_absoluto(double a, double b)
	{
		double ErrorA =fabs(a - b);
		return ErrorA;
	}

	double error_relativo(double a, double b)
	{
		double ErrorR= a/b;
		return ErrorR;
	}

      //Truncamiento a 5 dígitos
      x_5 = truncf(x_8*1e5)*1e-5;
      y_5 = truncf(y_8*1e5)*1e-5;
      u_5 = truncf(u_8*1e5)*1e-5;
      v_5 = truncf(v_8*1e5)*1e-5;
      w_5 = truncf(w_8*1e5)*1e-5;

      printf("Considera los siguientes valores para realizar los cálculos de la siguiente tabla \n x=5/7, 0.71428571 \n y=1/3, y_8 = 0.33333333 \n u=0.714251 \n v=98765.9 \n w=0.111111x10e-4\n y un SPFN con B=10, K=5\n");
//    printf("%0.8f\n %0.8f\n %0.5f\n %0.5f\n %0.8f\n", x_8, y_8, x_5, y_5, u_8);
      printf("-----------------------------------------------------------------------------------------\n");
      printf("Operación\t Valor a 8\t AritDeMáq\t Err Abs\t Err Rel\n");
      printf("-----------------------------------------------------------------------------------------\n");

      operacion_5 = truncf((x_5+y_5)*1e5)*1e-5;
      operacion_8 = x_8+y_8;
      ErrorA = error_absoluto(operacion_8, operacion_5);
      ErrorR = error_relativo(ErrorA,operacion_8);
      printf("1) x+y      \t %0.8f \t %0.5f \t %0.8f \t %0.8f \n", operacion_8, operacion_5, ErrorA, ErrorR);
      //----------------------------------------------------------------------------------------------------//
      operacion_5 = truncf((x_5*y_5)*1e5)*1e-5;
      operacion_8 = x_8*y_8;
      ErrorA = error_absoluto(operacion_8, operacion_5);
      ErrorR = error_relativo(ErrorA,operacion_8);
      printf("3) x*y      \t %0.8f \t %0.5f \t %0.8f \t %0.8f \n", operacion_8, operacion_5, ErrorA, ErrorR);
      //----------------------------------------------------------------------------------------------------//
      operacion_5 = truncf((x_5-u_5)*1e5)*1e-5;
      operacion_8 = x_8-u_8;
      ErrorA = error_absoluto(operacion_8, operacion_5);
      ErrorR = error_relativo(ErrorA,operacion_8);
      printf("5) x-u      \t %0.8f \t %0.5f \t %0.8f \t %0.8f \n", operacion_8, operacion_5, ErrorA, ErrorR);
      //----------------------------------------------------------------------------------------------------//

      operacion_5 = truncf(((x_5-u_5)*v_5)*1e5)*1e-5;
      operacion_8 = (x_8-u_8)*v_8;
      ErrorA = error_absoluto(operacion_8, operacion_5);
      ErrorR = error_relativo(ErrorA,operacion_8);
      printf("7) (x-u)*v  \t %0.8f \t %0.5f \t %0.8f \t %0.8f \n", operacion_8, operacion_5, ErrorA, ErrorR);
      printf("----------------------------------------------------------------------------------------\n");

}
