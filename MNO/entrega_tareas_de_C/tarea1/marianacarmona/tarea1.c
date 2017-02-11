#include<stdio.h>
#include<math.h>

main(){
	//input
	double x=0.71428571;
	double y=0.33333333;
	double u=0.714251;
	double v=98765.9;
	double w=0.0000111111;


	double res1 = x-y;
	double res1_5 = truncf( ( (truncf(x*1e5)/1e5) - (truncf(y*1e5)/1e5) )*1e5)/1e5;
	double ea1 = fabs(res1-res1_5);
	double er1 = fabs(ea1)/fabs(res1);
	printf(" x-y: \n val8 %1.8f \n Aritmetica máquina %1.5f \n Error Absoluto %1.8f \n Error Relativo %1.8f \n",
	res1,res1_5,ea1,er1);
	printf("------------------------------------------\n");

	double res2 = x/y;
        double res2_5 = truncf( (  (truncf(x*1e5)/1e5) / (truncf(y*1e5)/1e5) )*1e5)/1e5;
        double ea2 = fabs(res2-res2_5);
        double er2 = fabs(ea2)/fabs(res2);
        printf(" x/y: \n val8 %1.8f \n Aritmetica máquina %1.5f \n Error Absoluto %1.8f \n Error Relativo %1.8f \n",
	res2,res2_5,ea2, er2);
	printf("------------------------------------------\n");

	double res3 = (x-u)/w;
	double res3_5 = truncf((  ( (truncf(x*1e5)/1e5) - (truncf(u*1e5)/1e5) ) / (truncf(w*1e5)/1e5) )*1e5)/1e5 ;
	double ea3 = fabs(res3-res3_5);
        double er3 = fabs(ea3)/fabs(res3);
        printf(" (x-u)/w: \n val8 %1.8f \n Aritmetica máquina %1.5f \n Error Absoluto %1.8f \n Error Relativo %1.8f \n",
        res3,res3_5,ea3, er3);
        printf("------------------------------------------\n");


	double res4 = u+v;
	double res4_5 =  truncf(( (truncf(u*1e5)/1e5) + (truncf(v*1e5)/1e5) ) *1e5)/1e5 ;
        double ea4 = fabs(res4-res4_5);
        double er4 = fabs(ea4)/fabs(res4);
        printf(" u+v: \n val8 %1.8f \n Aritmetica máquina %1.5f \n Error Absoluto %1.8f \n Error Relativo %1.8f \n",
        res4,res4_5,ea4, er4);
        printf("------------------------------------------\n");


}	

