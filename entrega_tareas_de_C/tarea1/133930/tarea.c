#include <stdio.h>
#include <math.h>

double truncs(double x, double y){
  double z = truncf(x * pow(10, y)) * pow(10, -y);
  return z;
}

int main(){
  double x = truncs(5.0 / 7.0, 8.0),        x_5 = truncs(x, 5.0);
  double y = truncs(1.0 / 3.0, 8.0),        y_5 = truncs(y, 5.0);
  double u = truncs(0.714251, 8.0),         u_5 = truncs(u, 5.0);
  double v = truncs(98765.9, 8.0),          v_5 = truncs(v, 5.0);
  double w = truncs(0.111111 * 1e-4, 8.0),  w_5 = truncs(w, 5);
  double oper, oper_5;
  printf("Operación   | Valor a 8       | Aritmetica de máquina | Err A           | Err R\n");
  // x - y
  oper = truncs(x - y, 8.0);
  oper_5 = truncs(x_5 - y_5, 5.0);
  printf("x - y       | %1.9e | %1.9e       | %1.9e | %1.9e\n", oper, oper_5, fabs(oper - oper_5), fabs(oper - oper_5) / fabs(oper));
  // x / y
  oper = truncs(x / y, 7.0);
  oper_5 = truncs(x_5 / y_5, 4.0);
  printf("x / y       | %1.9e | %1.9e       | %1.9e | %1.9e\n", oper, oper_5, fabs(oper - oper_5), fabs(oper - oper_5) / fabs(oper));
  // (x-u) / w
  oper = truncs(((x - u) / w), 7.0);
  oper_5 = truncs(((x_5 - u_5) / w_5), 4.0);
  printf("(x - u) / w | %1.9e | %1.9e       | %1.9e | %1.9e\n", oper, oper_5, fabs(oper - oper_5), fabs(oper - oper_5) / fabs(oper));
  // u + v
  oper = truncs((u + v), 3.0);
  oper_5 = truncs((u_5 + v_5), 0.0);
  printf("u + v       | %1.9e | %1.9e       | %1.9e | %1.9e\n", oper, oper_5, fabs(oper - oper_5), fabs(oper - oper_5) / fabs(oper));
  return 0;
}
