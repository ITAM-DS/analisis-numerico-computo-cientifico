#include<stdio.h>
#include<math.h>
main(){
//Definicion y declaracion de variables

      double x_8 = 0.71428571;
      double y_8 = 0.33333333;
      double u_8 = 0.71425100;
      double v_8 = 98765.900;
      double w_8 = 0.111111e-4;
      double x_5, y_5, u_5, v_5, w_5, oper8, oper5, ErrorA, ErrorR;

      //Transformo 8 digitos a 5
      x_5 = truncf(x_8*1e5)*1e-5;
      y_5 = truncf(y_8*1e5)*1e-5;
      u_5 = truncf(u_8*1e5)*1e-5;
      v_5 = truncf(v_8*1e5)*1e-5;
      w_5 = truncf(w_8*1e5)*1e-5;

      //x+y
      oper5 = truncf((x_5+y_5)*1e5)*1e-5;
      oper8 = x_8+y_8;
      ErrorA = (oper8-oper5);
      ErrorR = ErrorA/oper8;
      printf("-------------\n");
      printf("Operacion 1 - x+y\n");
      printf("-------------\n");
      printf("Valor de x_8: %0.7f\n", x_8);
      printf("Valor de y_8:: %0.7f\n", y_8);
      printf("Valor de x_5: %0.5f\n", x_5);
      printf("Valor de y_5:: %0.5f\n", y_5);
      printf("Valor a 8 de x+y: %0.7f\n", oper8);
      printf("Aritmetica maquina de x+y: %0.5f\n", oper5);
      printf("Error A: %0.7f\n", ErrorA);
      printf("Error R: %0.7f\n", ErrorR);
      printf("-------------\n");
      printf("\n");
      printf("\n");

      //x*y
      oper5 = truncf((x_5*y_5)*1e5)*1e-5;
      oper8 = x_8*y_8;
      ErrorA = (oper8-oper5);
      ErrorR = ErrorA/oper8;
      printf("-------------\n");
      printf("Operacion 3 - x*y\n");
      printf("-------------\n");
      printf("Valor de x_8: %0.7f\n", x_8);
      printf("Valor de y_8:: %0.7f\n", y_8);
      printf("Valor de x_5: %0.5f\n", x_5);
      printf("Valor de y_5:: %0.5f\n", y_5);
      printf("Valor a 8 de x*y: %0.7f\n", oper8);
      printf("Aritmetica maquina de x*y: %0.5f\n", oper5);
      printf("Error A: %0.7f\n", ErrorA);
      printf("Error R: %0.7f\n", ErrorR);
      printf("-------------\n");
      printf("\n");
      printf("\n");

      // x-u
      oper5 = truncf((x_5-u_5)*1e5)*1e-5;
      oper8 = x_8-u_8;
      ErrorA = (oper8-oper5);
      ErrorR = ErrorA/oper8;
      printf("-------------\n");
      printf("Operacion 5 - x-u\n");
      printf("-------------\n");
      printf("Valor de x_8: %0.7f\n", x_8);
      printf("Valor de u_8:: %0.7f\n", u_8);
      printf("Valor de x_5: %0.5f\n", x_5);
      printf("Valor de u_5:: %0.5f\n", u_5);
      printf("Valor a 8 de x-u: %0.7f\n", oper8);
      printf("Aritmetica maquina de x-u: %0.5f\n", oper5);
      printf("Error A: %0.7f\n", ErrorA);
      printf("Error R: %0.7f\n", ErrorR);
      printf("-------------\n");
      printf("\n");
      printf("\n");

      // (x-u)*v
      oper5 = truncf(((x_5-u_5)*v_5)*1e5)*1e-5;
      oper8 = (x_8-u_8)*v_8;
      ErrorA = (oper8-oper5);
      ErrorR = ErrorA/oper8;
      printf("-------------\n");
      printf("Operacion 7 - (x-u)*v \n");
      printf("-------------\n");
      printf("Valor de x_8: %0.7f\n", x_8);
      printf("Valor de u_8:: %0.7f\n", u_8);
      printf("Valor de v_8:: %0.7f\n", v_8);
      printf("Valor de x_5: %0.5f\n", x_5);
      printf("Valor de u_5:: %0.5f\n", u_5);
      printf("Valor de v_5:: %0.5f\n", v_5);
      printf("Valor a 8 de (x-u)/v: %0.7f\n", oper8);
      printf("Aritmetica maquina de (x-u)*v: %0.5f\n", oper5);
      printf("Error A: %0.7f\n", ErrorA);
      printf("Error R: %0.7f\n", ErrorR);
      printf("-------------\n");
      printf("\n");
      printf("\n");
}
