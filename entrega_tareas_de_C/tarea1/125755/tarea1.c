// Tarea 1
// Luis Fernando Cańtú, CU: 000125755
// Equipo 8
#include<stdio.h>
#include<math.h>

main(){
	int beta = 10;
	int ka = 5;

	double x = 0.71428571;
	double y = 0.33333333;
	double u = 0.714251;
	double v = 0.987659*1e5;
	double w = 0.111111e-4;

	// Truncamos las variables con la función truncf

	double xTrunc, yTrunc, uTrunc, vTrunc, wTrunc;
	xTrunc = truncf(x*1e5) / 1e5;
	yTrunc = truncf(y*1e5) / 1e5;
	uTrunc = truncf(u*1e5) / 1e5;
	vTrunc = truncf(v*1e5) / 1e5;
	wTrunc = truncf(w*1e5) / 1e5;

	// x - y
	double op1 = truncf((x - y)*1e8)/1e8;
	double op1_arMaq = truncf((xTrunc - yTrunc)*1e5) / 1e5;
	double op1_errA = fabs(op1 - op1_arMaq);
	double op1_errR = op1_errA / fabs(op1);

	// x / y
	double op2 = truncf((x / y) *1e8)/1e8;
	double op2_arMaq = truncf((xTrunc / yTrunc)*1e5) / 1e5;
	double op2_errA = fabs(op2 - op2_arMaq);
	double op2_errR = op2_errA / fabs(op2);

	// (x-u)/w
	double op3 = truncf(((x-u) / w) *1e8)/1e8;
	double op3_arMaq = truncf(((xTrunc - uTrunc)/wTrunc)*1e5)/1e5;
	double op3_errA = fabs(op3 - op3_arMaq);
	double op3_errR = op3_errA / fabs(op3);

	// u + v
	double op4 = truncf((u + v) *1e8)/1e8;
	double op4_arMaq = truncf((uTrunc+vTrunc)*1e5)/1e5;
	double op4_errA = fabs(op4 - op4_arMaq);
	double op4_errR = op4_errA / fabs(op4);

	// Tabla
	printf("Operación \t\tValor a 8\t\tAritmética de Máq.\tError_A\t\t\tError_R\n");
    printf("       x-y\t\t%1.8e\t\t%1.5e  \t\t%1.2e  \t\t%1.2e\n",op1,op1_arMaq,op1_errA,op1_errR);
    printf("       x/y\t\t%1.8e\t\t%1.5e  \t\t%1.2e  \t\t%1.2e\n",op2,op2_arMaq,op2_errA,op2_errR);
    printf("   (x-u)/w\t\t%1.8e\t\t%1.5e  \t\t%1.2e  \t\t%1.2e\n",op3,op3_arMaq,op3_errA,op3_errR);
    printf("       u+v\t\t%1.8e\t\t%1.5e\t\t%1.2e  \t\t%1.2e\n",op4,op4_arMaq,op4_errA,op4_errR);


}
