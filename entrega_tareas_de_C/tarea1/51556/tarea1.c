//Tarea 1 Abraham Nieto 51556 
//Operaciones pares

#include<stdio.h>
#include<math.h> 

main(){
       double x=0.71428571;
       double y=0.33333333;
       double u=0.714251;
       double v=98765.9;
       double w=0.111111e-4;
       double x5,y5,u5,v5,w5;
       double v8,amaq,errA,errR,v81,amaq1,errA1,errR1,v82,amaq2,errA2,errR2,v83,amaq3,errA3,errR3;

      //Usamos la funcion truncf para poner los valores a 5 digitos

       x5=truncf(x*1e5)/1e5;
       y5=truncf(y*1e5)/1e5;
       u5=truncf(u*1e5)/1e5;
       v5=truncf(v*1e5)/1e5;
       w5=truncf(w*1e5)/1e5;

       
      v8=x-y;
      amaq=truncf((x5-y5)*1e5)/1e5;
      errA=fabs(v8-amaq);
      errR=errA/fabs(v8);

      v81=x/y;
      amaq1=truncf((x5/y5)*1e5)/1e5;
      errA1=fabs(v81-amaq1);
      errR1=errA1/fabs(v81);

      v82=(x-u)/w;
      amaq2=truncf(((x5-u5)/w5)*1e5)/1e5;
      errA2=fabs(v82-amaq2);
      errR2=errA2/fabs(v82);

      v83=u+v;
      amaq3=truncf((u5+v5)*1e5)/1e5;
      errA3=fabs(v83-amaq3);
      errR3=errA3/fabs(v83);

      printf("Operacion\t|\tValor a 8\t|\tAritmetica de maquina\t|\tErrA \t        |   \tErrR\n");
      printf("       X-Y\t|\t   %1.8f\t|\t              %1.5f  \t|\t%1.2e \t|\t%1.2e\n",v8,amaq,errA,errR);
      printf("       X/Y\t|\t   %1.8f\t|\t              %1.5f  \t|\t%1.2e \t|\t%1.2e\n",v81,amaq1,errA1,errR1);
      printf("   (X-U)/W\t|\t   %1.8f\t|\t              %1.5f  \t|\t%1.2e \t|\t%1.2e\n",v82,amaq2,errA2,errR2);
      printf("       U+V\t|\t %1.8f\t|\t       %1.5f  \t|\t%1.2e \t|\t%1.2e\n",v83,amaq3,errA3,errR3);


}
