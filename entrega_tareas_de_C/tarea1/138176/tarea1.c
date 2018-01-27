/* Daniel Sharp
138176
Equipo 1
*/
#include <stdio.h>
#include <math.h> // Se carga la librería de matemáticas para la función roundf

// Se define función que hará el redondeo de los datos a 5 digitos
  double rounder (double x, double digits){
  double val = 0;
    while(x >=1){
      x = x/10;
      val = val + 1;
    }
    while(x < .1){
      x = x*10;
      val = val -1;
    }
    double res = roundf(x * pow(10, digits)) / pow(10, digits);
    res = res * pow(10, val);
    return res;
  }

int main(int argc, char const *argv[]) {

// Se definen los valores reales para las operaciones
  double x =  5.0/7.0;
  double y = 1.0/3.0;
  double u = 0.714251;
  double v = 98765.9;
  double w = 0.111111E-4;


  x = rounder(x, 8);
  y = rounder(y, 8);
  u = rounder(u, 8);
  v = rounder(v, 8);
  w = rounder(w, 8);

printf("Se toman los valores originales redondeando a 8 dígitos\n");
  printf("Valor de x: %.8e\n", x);
  printf("Valor de y: %.8e\n", y);
  printf("Valor de u: %.8e\n", u);
  printf("Valor de v: %.8e\n", v);
  printf("Valor de w: %.8e\n", w);


// Se aplica la función de redondeo a los valores originales
  double x_k5 = rounder(x,5);
  double y_k5 = rounder(y,5);
  double u_k5 = rounder(u,5);
  double v_k5 = rounder(v,5);
  double w_k5 = rounder(w,5);

  printf("Después de aplicar la función de redondeo para tener k igual a 5 tenemos los siguientes valores: \n");
  printf("Valor de x_k5: %#.5e\n", x_k5);
  printf("Valor de y_k5: %#.5e\n", y_k5);
  printf("Valor de u_k5: %#.5e\n", u_k5);
  printf("Valor de v_k5: %#.5e\n", v_k5);
  printf("Valor de w_k5: %#.5e\n", w_k5);

// Desarrollamos la artimética de máquina con los valores a 5 digitos
// Por ser del equipo 1 me corresponde hacer los incisos impares


// x+y
char suma[10] = "x+y";
double x_mas_y = rounder(x+y,8);
double x_mas_y_k5 = rounder(x_k5 + y_k5,5);
double erra_x_mas_y = x_mas_y - x_mas_y_k5;
double errr_x_mas_y = erra_x_mas_y / x_mas_y;

// x*y
char mult[10] = "x*y";
double x_por_y = rounder(x * y,8);
double x_por_y_k5 = rounder(x_k5 * y_k5, 5);
double erra_x_por_y = x_por_y - x_por_y_k5;
double errr_x_por_y = erra_x_por_y / x_por_y;

// x-u
char resta[10] = "x-u";
double x_menos_u = rounder(x - u, 8);
double x_menos_u_k5 = rounder(x_k5 - u_k5, 5);
double erra_x_menos_u = x_menos_u - x_menos_u_k5;
double errr_x_menos_u = erra_x_menos_u / x_menos_u;

// (x-u)/v
char divi[10] = "(x-u)/v";
double x_menos_u_entre_v = rounder(x_menos_u / v, 8);
double x_menos_u_entre_v_k5 = rounder(x_menos_u_k5 / v_k5, 5);
double erra_x_menos_u_entre_v = x_menos_u_entre_v - x_menos_u_entre_v_k5;
double errr_x_menos_u_entre_v = erra_x_menos_u_entre_v / x_menos_u_entre_v;

// Imprimimos la tabla con los resultados en la terminal
char heading[100] = "Operación     Valor a 8     Aritmética de Máquina     Error Abs     Error Rel";
printf("%s \n", heading);
printf("%s         %.8e      %.5e          %.3e    %.3e\n", suma, x_mas_y,x_mas_y_k5,erra_x_mas_y,errr_x_mas_y);
printf("%s         %.8e      %.5e          %.3e    %.3e\n", mult, x_por_y,x_por_y_k5,erra_x_por_y,errr_x_por_y);
printf("%s         %.8e      %.5e          %.3e    %.3e\n", resta, x_menos_u,x_menos_u_k5,erra_x_menos_u,errr_x_menos_u);
printf("%s     %.8e      %.5e          %.3e    %.3e\n", divi, x_menos_u_entre_v,x_menos_u_entre_v_k5,erra_x_menos_u_entre_v,errr_x_menos_u_entre_v);

// Guardamos la tabla de resultados en un .txt
FILE *f = fopen("resultados.txt", "w");
if (f == NULL)
{
    printf("Error opening file!\n");
}
fprintf(f,"%s \n", heading);
fprintf(f,"  %s       %.8e      %.5e             %.3e     %.3e\n", suma, x_mas_y,x_mas_y_k5,erra_x_mas_y,errr_x_mas_y);
fprintf(f,"  %s       %.8e      %.5e             %.3e     %.3e\n", mult, x_por_y,x_por_y_k5,erra_x_por_y,errr_x_por_y);
fprintf(f,"  %s       %.8e      %.5e          %.3e    %.3e\n", resta, x_menos_u,x_menos_u_k5,erra_x_menos_u,errr_x_menos_u);
fprintf(f,"%s     %.8e      %.5e          %.3e    %.3e\n", divi, x_menos_u_entre_v,x_menos_u_entre_v_k5,erra_x_menos_u_entre_v,errr_x_menos_u_entre_v);

fclose(f);





  return 0;

}
