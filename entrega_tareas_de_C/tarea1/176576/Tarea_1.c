#include<stdio.h>
#include<math.h>

main(){

	double x = 0.71428571;
	double y = 0.33333333;
	double u = 0.714251;
	double v = 98765.9;
	double w = 0.111111e-4;

	double x5 = truncf(x*1e5)/1e5;
	double y5 = truncf(y*1e5)/1e5;
	double u5 = truncf(u*1e5)/1e5;
	double v5 = truncf(v*1e5)/1e5;
	double w5 = truncf(w*1e5)/1e5;

	double val_8_1, val_8_2, val_8_3, val_8_4;
	double arit_maq_1, arit_maq_2, arit_maq_3, arit_maq_4;
	double err_ab_1, err_ab_2, err_ab_3, err_ab_4;
	double err_rel_1, err_rel_2, err_rel_3, err_rel_4;

	val_8_1 = x-y;
	val_8_2 = x/y;
	val_8_3 = (x-u)/w;
	val_8_4 = u+v;

	arit_maq_1 = truncf((x5-y5)*1e5)/1e5;
	arit_maq_2 = truncf((x5/y5)*1e5)/1e5;
	arit_maq_3 = truncf(((x5-u5)/w)*1e5)/1e5;
	arit_maq_4 = truncf((u5+v5)*1e5)/1e5;

	err_ab_1 = fabs(val_8_1-arit_maq_1);
	err_ab_2 = fabs(val_8_2-arit_maq_2);
	err_ab_3 = fabs(val_8_3-arit_maq_3);
	err_ab_4 = fabs(val_8_4-arit_maq_4);

	err_rel_1 = err_ab_1/fabs(val_8_1);
	err_rel_2 = err_ab_2/fabs(val_8_2);
	err_rel_3 = err_ab_3/fabs(val_8_3);
	err_rel_4 = err_ab_4/fabs(val_8_4);


	printf("1) x-y      \t %0.8f \t %0.5f \t %1.2e \t %1.2e \n", val_8_1, arit_maq_1, err_ab_1, err_rel_1);
	printf("2) x/y      \t %0.8f \t %0.5f \t %1.2e \t %1.2e \n", val_8_2, arit_maq_2, err_ab_2, err_rel_2);
	printf("3) (x-u)/w     \t %0.8f \t %0.5f \t %1.2e \t %1.2e \n", val_8_3, arit_maq_3, err_ab_3, err_rel_3);
	printf("4) u+v      \t %0.8f \t %0.5f \t %1.2e \t %1.2e \n", val_8_4, arit_maq_4, err_ab_4, err_rel_4);

}
