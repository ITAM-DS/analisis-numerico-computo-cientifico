#include<stdio.h>
#include<math.h>

main(){

       //Inicializamos las variables
       double x=0.71428571;
       double y=0.33333333;
       double u=0.714251;
       double v=98765.9;
       double x5,y5,u5,v5;
       double suma,suma5,errA,errR;
       double multi,multi5,errA2,errR2;
       double resta,resta5,errA3,errR3;
       double multi_resta,multi_resta5,errA4,errR4;

       x5=truncf(x*1e5)*1e-5;
       y5=truncf(y*1e5)*1e-5;
       u5=truncf(u*1e5)*1e-5;
       v5=truncf(v*1e5)*1e-5;

       //Hacemos primera operacion x+y
       //Como solo queremos trabajar con 8 digitos decimales considerando la parte entera como Cero, al no encontrar una manera de hacer esa notacion en C reduzco el numero de decimales a truncar en 7 para este ejercicio
       suma=x+y;
       suma=truncf(suma*1e7)*1e-7;
       suma5=x5+y5;
       suma5=truncf(suma5*1e4)*1e-4;
       errA=fabs(suma-suma5);
       errR=errA/fabs(suma);

       // Hacemos tercera operacion x*y
       multi=x*y;
       multi=truncf(multi*1e8)*1e-8;
       multi5=x5*y5;
       multi5=truncf(multi5*1e5)*1e-5;
       errA2=fabs(multi-multi5);
       errR2=errA2/fabs(multi);

       //Hacemos quinta operacion x-u
       resta=x-u;
       resta=truncf(resta*1e8)*1e-8;
       resta5=x5-u5;
       resta5=truncf(resta5*1e5)*1e-5;
       errA3=fabs(resta-resta5);
       errR3=errA3/fabs(resta);

       //Hacemos septima operacion (x-u)*v
       multi_resta=(resta)*v;
       multi_resta=truncf(multi_resta*1e7)*1e-7;
       multi_resta5=(resta5)*v5;
       multi_resta5=truncf(multi_resta5*1e4)*1e-4;
       errA4=fabs(multi_resta-multi_resta5);
       errR4=errA4/fabs(multi_resta);

       printf("Operacion\t Valor a 8\tAritmetica de maquina\tErrA \t \t\tErrR\n");
       printf(" X+Y\t\t %.7e\t  %.4e  \t\t%.3e \t\t%.3e\n",suma,suma5,errA,errR);
       printf(" XY\t\t %.7e\t  %.4e  \t\t%.3e \t\t%.3e\n",multi,multi5,errA2,errR2);
       printf(" X-U\t\t %.7e\t  %.4e  \t\t%.3e \t\t%.3e\n",resta,resta5,errA3,errR3);
       printf(" (x-u)v\t\t %.7e\t  %.4e  \t\t%.3e \t\t%.3e\n",multi_resta,multi_resta5,errA4,errR4);


}
