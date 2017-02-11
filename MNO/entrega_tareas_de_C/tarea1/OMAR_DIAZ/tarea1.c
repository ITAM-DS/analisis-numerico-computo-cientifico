#include<stdio.h>
#include<math.h>

main(){
	//input
	double x=0.71428571;
	double y=0.33333333;
	double u=0.714251;
	double v=98765.9;
	double w=0.0000111111;

        double r0 = x+y;
        double r0_5 =truncf(((truncf(x*1e5)/1e5)+(truncf(y*1e5)/1e5))*1e5)/1e5;
        double err_abs0 = fabs(r0-r0_5);
        double err_rel0 = fabs(err_abs0)/fabs(r0);
        printf("------------------------------------------\n");
        printf(" x+y: \n val8 %1.8f \n Aritmetica máquina %1.5f \n Error Absoluto %1.8f \n Error Relativo %1.8f \n",
        r0,r0_5,err_abs0,err_rel0);
        printf("------------------------------------------\n");




	double r1 = x-y;
	double r1_5 = truncf( ( (truncf(x*1e5)/1e5) - (truncf(y*1e5)/1e5) )*1e5)/1e5;
	double err_abs1 = fabs(r1-r1_5);
	double err_rel1 = fabs(err_abs1)/fabs(r1);
	printf("------------------------------------------\n");
	printf(" x-y: \n val8 %1.8f \n Aritmetica máquina %1.5f \n Error Absoluto %1.8f \n Error Relativo %1.8f \n",
	r1,r1_5,err_abs1,err_rel1);
	printf("------------------------------------------\n");

	double r2 = x/y;
        double r2_5 = truncf( (  (truncf(x*1e5)/1e5) / (truncf(y*1e5)/1e5) )*1e5)/1e5;
        double err_abs2 = fabs(r2-r2_5);
        double err_rel2 = fabs(err_abs2)/fabs(r2);
	printf("------------------------------------------\n");
        printf(" x/y: \n val8 %1.8f \n Aritmetica máquina %1.5f \n Error Absoluto %1.8f \n Error Relativo %1.8f \n",
	r2,r2_5,err_abs2, err_rel2);
	printf("------------------------------------------\n");

	double r3 = (x-u)/w;
	double r3_5 = truncf((  ( (truncf(x*1e5)/1e5) - (truncf(u*1e5)/1e5) ) / (truncf(w*1e5)/1e5) )*1e5)/1e5 ;
	double err_abs3 = fabs(r3-r3_5);
        double err_rel3 = fabs(err_abs3)/fabs(r3);
        printf("------------------------------------------\n");
        printf(" (x-u)/w: \n val8 %1.8f \n Aritmetica máquina %1.5f \n Error Absoluto %1.8f \n Error Relativo %1.8f \n",
        r3,r3_5,err_abs3, err_rel3);
        printf("------------------------------------------\n");


	double r4 = u+v;
	double r4_5 =  truncf(( (truncf(u*1e5)/1e5) + (truncf(v*1e5)/1e5) ) *1e5)/1e5 ;
        double err_abs4 = fabs(r4-r4_5);
        double err_rel4 = fabs(err_abs4)/fabs(r4);
        printf("------------------------------------------\n");
        printf(" u+v: \n val8 %1.8f \n Aritmetica máquina %1.5f \n Error Absoluto %1.8f \n Error Relativo %1.8f \n",
        r4,r4_5,err_abs4, err_rel4);
        printf("------------------------------------------\n");


}	



