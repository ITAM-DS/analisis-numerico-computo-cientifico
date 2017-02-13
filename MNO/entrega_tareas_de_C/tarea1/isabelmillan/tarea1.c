#include<stdio.h>
#include<math.h>
int main(){
	double x_8 = 0.71428571;
	double x_5 = truncf(x_8*1e5)/1e5;
	double y_8 = 0.33333333;
	double y_5 = truncf(y_8*1e5)/1e5;
	double u_8 = 0.714251;
	double u_5= truncf(u_8*1e5)/1e5;
	double v_8 = 98765.9;
	double v_5= truncf(v_8*1e5)/1e5;
	double w = 0.111111e-4;

	printf("Operaciones impares\n\n");
	printf("Operación \t\t Valor a 8 \t\t Aritmética de máquina \t\t\t ErrA \t\t\t ErrR\n");

	// Ejercicio 1 (x+y)
	double uno_a = x_8+y_8;
	double uno_b = truncf((x_5+y_5)*1e5)/1e5;
	double uno_c = fabs (uno_a-uno_b);
	double uno_d = fabs(uno_c)/fabs(uno_a);
	printf("x+y \t\t\t  %1.8f \t\t\t %1.5f \t\t\t %1.8f \t\t %1.8f\n", uno_a, uno_b, uno_c, uno_d);

	// Ejercicio 3 (xy)
	double tres_a = x_8*y_8;
	double tres_b = truncf((x_5*y_5)*1e5)/1e5;
	double tres_c = fabs (tres_a-tres_b);
	double tres_d = fabs(tres_c)/fabs(tres_a);
	printf("x*y \t\t\t  %1.8f \t\t\t  %1.5f \t\t\t  %1.8f \t\t  %1.8f\n", tres_a, tres_b, tres_c, tres_d);

	// Ejercicio 5 (x-u)
	double cinco_a = (x_8-u_8);
	double cinco_b = truncf((x_5-u_5)*1e5)/1e5;
	double cinco_c = fabs (cinco_a-cinco_b);
	double cinco_d = fabs(cinco_c)/fabs(cinco_a);
	printf("x-u \t\t\t  %1.8f \t\t\t  %1.5f \t\t\t %1.8f \t\t  %1.8f\n", cinco_a, cinco_b, cinco_c, cinco_d);

	// Ejercicio 7 (x-u)v
	double siete_a = (x_8-u_8)*v_8;
	double siete_b = truncf(((x_5-u_5)*v_5)*1e5)/1e5;
	double siete_c = fabs (siete_a-siete_b);
	double siete_d = fabs(siete_c)/fabs(siete_a);
	printf("(x-u)/v \t\t  %1.8f \t\t  %1.5f \t\t\t  %1.8f \t\t  %1.8f\n", siete_a, siete_b, siete_c, siete_d);
	printf("Observamos que para los primeros dos ejercicios (suma y multiplicación) obtenemos errores absolutos y relativos muy pequeños por lo que no tenemos problemas de presición. Para la resta de x-u el error absoluto es pequeño sin embargo el error relativo es grande. Esto se debe a que los números utilizados son muy cercanos entre sí,lo que hace que el denominador del error relativo sea muy pequeño y el error grande. Para la última operación, ambos errores son grandes ya que v multiplica la resta y como tiene un valor muy grande,  y eleva el valor del error y hace mucho más notorio el truncamiento realizado.");




}
