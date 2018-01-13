#include<stdio.h>
#include<math.h>

main(){
	double x_8 = 0.71428571;
	double x_5 = truncf(x_8*1e5)/1e5;
	double y_8 = 0.33333333;
	double y_5 = truncf(y_8*1e5)/1e5;
	double u_8 = 0.71425100;
	double u_5 = truncf(u_8*1e5)/1e5;
	double v_8 = 98765.900;
	double v_5 = truncf(v_8*1e5)/1e5;
	double w_8 = truncf(.111111e-4*1e8)/1e8;
	double w_5 = truncf(w_8*1e5)/1e5;

// Ej. 2 
	double res2_8 = x_8-y_8;
	double res2_5 = truncf((x_5-y_5)*1e5)/1e5;
	double res2_ea = fabs (res2_8-res2_5);
	double res2_er = fabs(res2_ea)/fabs(res2_8);

// Ej. 4 
	double res4_8 = x_8/y_8;
	double res4_5 = truncf((x_5/y_5)*1e5)/1e5;
	double res4_ea = fabs (res4_8-res4_5);
	double res4_er = fabs(res4_ea)/fabs(res4_8);

// Ej. 6
	double res6_8 = (x_8-u_8)/w_8;
	double res6_5 = truncf( ( (x_5-u_5)/w_5 )*1e5 )/1e5;
	double res6_ea = fabs(res6_8 - res6_5);
	double res6_er = fabs(res6_ea)/fabs(res6_8);

// Ej. 8
        double res8_8 = u_8+v_8;
        double res8_5 = truncf( (u_5 + v_5)*1e5 )/1e5;
        double res8_ea = fabs (res8_8-res8_5);
        double res8_er = fabs(res8_ea)/fabs(res8_8);

printf("Número \t Operación \t Valor a 8 \t\t Aritmética \t Err A \t\t Err R \n");
printf("2\t      X-Y \t %4.8f \t\t %1.5f \t %1.8f \t %1.8f \n", res2_8, res2_5, res2_ea, res2_er);
printf("4\t      X/Y \t %4.8f \t\t %1.5f \t %1.8f \t %1.8f \n", res4_8, res4_5, res4_ea, res4_er);
printf("6\t  (X-U)/W \t %4.8f \t\t %1.5f \t %1.8f \t %1.8f \n", res6_8, res6_5, res6_ea, res6_er);
printf("8\t    (U+V) \t %5.8f \t %1.5f \t %1.8f \t %1.8f \n", res8_8, res8_5, res8_ea, res8_er);

}
