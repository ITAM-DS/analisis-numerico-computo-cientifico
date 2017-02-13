// Lizbeth Contreras Figueroa
// Tarea 01
// Fecha de entrega: 30/01/2017

#include<stdio.h>
#include<math.h>

main(){
  double x_8 = 0.71428571;
  double y_8 = 0.33333333;
  double u_8 = 0.714251;
  double v_8 = 98765.9;
  //double w_8 = .111111e-4;
  
  double x_5 = truncf(x_8*1e5)/1e5;
  double y_5 = truncf(y_8*1e5)/1e5;
  double u_5 = truncf(u_8*1e5)/1e5;
  double v_5 = truncf(v_8*1e5)/1e5;
  //double w_5 = truncf(w_8*1e5)/1e5;
  
  // Suma
  double res1_a = x_8+y_8;
  double res1_b = truncf((x_5+y_5)*1e5)/1e5;
  double res1_c = truncf((res1_a - res1_b)*1e8)/1e8; 
  double res1_d = res1_c/res1_a;
  
  // Multiplicacion
  double res2_a = x_8*y_8;
  double res2_b = truncf((x_5*y_5)*1e5)/1e5;
  double res2_c = truncf((res2_a - res2_a)*1e8)/1e8; 
  double res2_d = res2_c/res2_a;
  
  // (x-u)
  double res3_a = x_8-u_8;
  double res3_b = truncf( ( (x_5-u_5))*1e5 )/1e5;
  double res3_c = truncf((res3_a - res3_b)*1e8)/1e8; 
  double res3_d = res3_c/res3_a;
  
  // (x-u)v
  double res4_a = (x_8-u_8)*v_8;
  double res4_b = truncf(((x_5 - u_5)*v_5)*1e5)/1e5;
  double res4_c = truncf((res4_a - res4_b)*1e8)/1e8;
  double res4_d = res4_c/res4_a;
  
  
  printf("operacion \t valor a 8 \t aritmetica \t error abs \t error r \n");
  printf("      X-Y \t %4.8f \t %1.5f \t %1.8f \t %1.8f \n", res1_a, res1_b, res1_c, res1_d);
  printf("      X/Y \t %4.8f \t %1.5f \t %1.8f \t %1.8f \n", res2_a, res2_b, res2_c, res2_d);
  printf("  (X-U)/W \t %4.8f \t %1.5f \t %1.8f \t %1.8f \n", res3_a, res3_b, res3_c, res3_d);
  printf("    (U+V) \t %4.8f \t %1.5f \t %1.8f \t %1.8f \n", res4_a, res4_b, res4_c, res4_d);
}
