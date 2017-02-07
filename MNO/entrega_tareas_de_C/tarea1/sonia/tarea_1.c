// Sonia Mendizabal
// 105720
// Ejercicios pares


#include<stdio.h>
#include<math.h>

main(){
	double x_8 = 0.71428571;
	double x_5 = truncf(x_8*1e5)/1e5;
	double y_8 = 0.33333333;
	double y_5 = truncf(y_8*1e5)/1e5;
	double u_8 = 0.714251;
	double u_5 = truncf(u_8*1e5)/1e5;
	double v_8 = 98765.9;
	double v_5 = truncf(v_8*1e5)/1e5;
	double w_8 = .111111e-4;
	double w_5 = truncf(w_8*1e5)/1e5;

	// Ejercicio 1 (par)
	double res1_a = x_8-y_8;
	double res1_b = truncf((x_5-y_5)*1e5)/1e5;
	double res1_c = fabs (res1_a-res1_b);
	double res1_d = fabs(res1_c)/fabs(res1_a);

	// Ejercicio 2 (par)
	double res2_a = x_8/y_8;
	double res2_b = truncf((x_5/y_5)*1e5)/1e5;
	double res2_c = fabs (res2_a-res2_b);
	double res2_d = fabs(res2_c)/fabs(res2_a);

	// Ejercicio 3 (par)
	double res3_a = (x_8-u_8)/w_8;
	double res3_b = truncf( ( (x_5-u_5)/w_5 )*1e5 )/1e5;
	double res3_c = fabs(res3_a - res3_b);
	double res3_d = fabs(res3_c)/fabs(res3_a);

	// Ejercicio 4 (par)
        double res4_a = u_8+v_8;
        double res4_b = truncf( (u_5 + v_5)*1e5 )/1e5;
        double res4_c = fabs (res4_a-res4_b);
        double res4_d = fabs(res4_c)/fabs(res4_a);


	printf("operacion \t valor a 8 \t\t aritmetica \t error abs \t error r \n");
	printf("      X-Y \t %4.8f \t\t %1.5f \t %1.8f \t %1.8f \n", res1_a, res1_b, res1_c, res1_d);
	printf("      X/Y \t %4.8f \t\t %1.5f \t %1.8f \t %1.8f \n", res2_a, res2_b, res2_c, res2_d);
	printf("  (X-U)/W \t %4.8f \t\t %1.5f \t %1.8f \t %1.8f \n", res3_a, res3_b, res3_c, res3_d);
        printf("    (U+V) \t %5.8f \t %1.5f \t %1.8f \t %1.8f \n", res4_a, res4_b, res4_c, res4_d);
}
