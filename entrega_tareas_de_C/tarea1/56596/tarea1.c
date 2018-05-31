#include<stdio.h>
#include<math.h>

void print_row(char *label, double value, double arit_maq, double error_abs, double error_rel) {
  printf("%s\t\t\t%1.8f\t\t%1.5f\t\t\t\t%1.2e\t\t%1.2e\n", label, value, arit_maq, error_abs, error_rel);
}

main(){
  double x = 0.71428571;
  double y = 0.33333333;
  double u = 0.714251;
  double v = 98765.9;
  double w = 0.00001111;

  double x5=truncf(x*1e5)/1e5;
  double y5=truncf(y*1e5)/1e5;
  double u5=truncf(u*1e5)/1e5;
  double v5=truncf(v*1e5)/1e5;
  double w5=truncf(w*1e5)/1e5;
  double x_mas_y=x5+y5;
  double x_mas_y8=x+y;
  
  printf("Operacion\t\tValor a 8\t\tAritmetica de maquina\t\tError absoluto\t\tError relativo\n");
  print_row("x+y", x_mas_y8, truncf(x_mas_y*1e5)/1e5, fabs(x_mas_y8-(truncf(x_mas_y*1e5)/1e5)), (fabs(x_mas_y8-(truncf(x_mas_y*1e5)/1e5))/x_mas_y8));

  double x_por_y = x5*y5;
  double x_por_y8 = x*y;

  print_row("xy", x_por_y8, trunc(x_por_y*1e5)/1e5, fabs(x_por_y8-(truncf(x_por_y*1e5)/1e5)), (fabs(x_por_y8-(truncf(x_por_y*1e5)/1e5))/x_por_y8));

  double x_menos_u = x5-u5;
  double x_menos_u8= x-u;
  
  print_row("x-u", x_menos_u8, trunc(x_menos_u*1e5)/1e5, fabs(x_menos_u8-(truncf(x_menos_u*1e5)/1e5)),(fabs(x_menos_u8-(truncf(x_menos_u*1e5)/1e5))/x_menos_u8));
  double x_menos_u_por_v = (x5-u5)*v5;
  double x_menos_u_por_v8 = (x-u)*v;
  
  print_row("(x-u)*v", x_menos_u_por_v8, trunc(x_menos_u_por_v*1e5)/1e5, fabs(x_menos_u_por_v8-(truncf(x_menos_u_por_v*1e5)/1e5)),
  (fabs(x_menos_u_por_v8-(truncf(x_menos_u_por_v*1e5)/1e5))/x_menos_u_por_v8));

 }


