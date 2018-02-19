//1) x+y
//3) xy
//5) x-u
//7) (x-u)v


//x=5/7
//y=1/3
//u=.714251
//v=98765.9
//w=.111111x10-4

//base 10
//k 5

//operacion valor a 8 aritmetica de maquina errA errR
//x+y        .10476190x10^1        .10476 x10^1 .190 x10-4 .181x10-5

#include<stdio.h>
#include<math.h>
main(){
	double x_8 = 0.71428571;
	double y_8 = 0.33333333;
	double x_5;
	double y_5;
        double u=.714251;
        double v=98765.9;
        double u_5;
        double v_5;
        double res1;
        double res1_8;
        double res1_5;
        double res3;
        double res3_8;
        double res3_5;
        double res5;
        double res5_8;
        double res5_5;
        double res7;
        double res7_8;
        double res7_5;

        double erra1;
        double err1;
        double erra3;
        double err3;
        double erra5;
        double err5;
        double erra7;
        double err7;

        x_5 = truncf(x_8*1e5)*1e-5;
        y_5 = truncf(y_8*1e5)*1e-5;
        u_5 = truncf(u*1e5)*1e-5;
        v_5 = truncf(v*1e5)*1e-5;

        //x+y
         res1=x_8+y_8;
         res1_8=truncf(res1*1e8)*1e-8;
         res1_5=x_5+y_5;
         res1_5=truncf(res1_5*1e5)*1e-5;
         erra1=fabs(res1_5*10-res1_8*10);
         err1=fabs(erra1)/res1_8*10;
        //xy
         res3=x_8*y_8;
         res3_8=truncf(res3*1e8)*1e-8;
         res3_5=x_5*y_5;
         res3_5=truncf(res3_5*1e5)*1e-5;
         erra3=fabs(res3_5-res3_8);
         err3=fabs(erra3)/res3_8;
        //x-u
         res5=x_8-u;
         res5_8=truncf(res5*1e8)*1e-8;
         res5_5=x_5-u_5;
         res5_5=truncf(res5_5*1e5)*1e-5;
         erra5=fabs(res5_5-res5_8);
         err5=fabs(erra5)/res5_8;
         //(x-u)v
         res7=res5*v;
         res7_8=truncf(res7*1e8)*1e-8;
         res7_5=res5_5*v_5;
         res7_5=truncf(res7_5*1e5)*1e-5;
         erra7=fabs(res7_5-res7_8);
         err7=fabs(erra7)/res7_8;
         
          printf("Operación | Valor a 8 | Aritmética de máquina | ErrA | ErrR \n");
         printf("x+y | %1.8f|%1.5f|%1.8f|%1.8f\n",res1_8, res1_5, erra1, err1);
	 printf("xy |%1.8f|%1.5f|%1.8f|%1.8f\n", res3_8, res3_5, erra3, err3);
         printf("x-u |%1.8f|%1.5f|%1.8f|%1.8f\n", res5_8, res5_5, erra5, err5);
         printf("(x-u)v |%1.8f|%1.5f|%1.8f|%1.8f\n",  res7_8, res7_5, erra7, err7);
	

}



