#include<stdio.h>
#include<math.h>
main(){
	double x_1 = 5;
	double x_2 = 7;
	double y_1 = 1;
	double y_2 = 3;
	double u = 0.714251;
	double v = 98765.9;
	double w_1 = 111111;
	double w_2 = 10;
	double w_3 = -4;
	double fl_x;
	double fl_y;
	double fl_u;
	double fl_v;
	double fl_w;

	//función: truncf
	fl_x = trunc(x_1/x_2*1e5)*1e-5;
	fl_y = trunc(y_1/y_2*1e5)*1e-5;
	fl_u = trunc(u*1e5)*1e-5;
	fl_v = trunc(v);
	fl_w = trunc(pow(w_1*w_2, w_3)*1e5)*1e-5;
	printf(" Operación | Valor a 8  | Aritmética de Maq | Error Abs  |  Error Rel\n");
	printf("    x-y    | %1.8f |      %1.5f      | %1.8f | %1.8f\n", trunc((x_1/x_2 -y_1/y_2)*1e8)*1e-8, trunc((fl_x-fl_y)*1e5)*1e-5,
		trunc((x_1/x_2 -y_1/y_2)*1e8)*1e-8-trunc((fl_x-fl_y)*1e5)*1e-5, 
		(trunc((x_1/x_2 -y_1/y_2)*1e8)*1e-8-trunc((fl_x-fl_y)*1e5)*1e-5)/(trunc((x_1/x_2 -y_1/y_2)*1e8)*1e-8));	
	printf("    x/y    | %1.8f |      %1.5f      | %1.8f | %1.8f\n", trunc((x_1/x_2)/(y_1/y_2)*1e8)*1e-8, trunc((fl_x/fl_y)*1e5)*1e-5,
		fabs(trunc((x_1/x_2)/(y_1/y_2)*1e8)*1e-8-trunc((fl_x/fl_y)*1e5)*1e-5), 
		fabs((trunc((x_1/x_2)/(y_1/y_2)*1e8)*1e-8-trunc((fl_x/fl_y)*1e5)*1e-5)/(trunc((x_1/x_2)/(y_1/y_2)*1e8)*1e-8)));
	printf("  (x-u)/w) | %1.8f |      %1.5f      | %1.8f | %1.8f\n", trunc(((x_1/x_2)-u)/(pow(w_1*w_2, w_3))*1e-8)*1e8, trunc((fl_x-fl_u)/fl_w*1e5)*1e-5, 
		fabs(trunc(((x_1/x_2)-u)/(pow(w_1*w_2, w_3))*1e8)*1e-8-trunc((fl_x-fl_u)/fl_w*1e5)*1e-5), 
		fabs((trunc(((x_1/x_2)-u)/(pow(w_1*w_2, w_3))*1e8)*1e-8-trunc((fl_x-fl_u)/fl_w*1e5)*1e-5)/(trunc(((x_1/x_2)-u)/(pow(w_1*w_2, w_3))*1e8))*1e-8));
	printf("    u+v    | %1.3f  |      %1.1f      | %1.8f | %1.8f\n", fabs(trunc((trunc((u+v)*1e-5)-(u+v)*1e-5)*1e8)*1e-3), trunc((u*1e-5+v*1e-5)*1e5), 
		fabs(trunc((trunc((u+v)*1e-5)-(u+v)*1e-5)*1e8)*1e-3)-trunc((u*1e-5+v*1e-5)*1e5), 
		(fabs(trunc((trunc((u+v)*1e-5)-(u+v)*1e-5)*1e8)*1e-3)-trunc((u*1e-5+v*1e-5)*1e5))/fabs(trunc((trunc((u+v)*1e-5)-(u+v)*1e-5)*1e8)*1e-3));
}