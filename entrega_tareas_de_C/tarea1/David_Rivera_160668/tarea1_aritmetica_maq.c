#include<stdio.h>
#include<math.h>
main(){
	int  a;
	double x, y,u ,v ,w ,result, aritmq, err_a,err_r;
	x= 5.0 / 7.0;
	y= 1.0 / 3.0;
	u= 0.714251;
	v= 98765.9;
	w=0.111111*pow(10,-4);


	printf("Operacion \t Valor a 8 \t Aritmetica de máquina \t   ErrA \t  ErrR \n");

	//a) x+y
	result =x+y;
	a=8-findn(truncf(result));
	result=truncf(result*pow(10,a))*pow(10,-a);

	aritmq=truncf(x*1e5)*1e-5+truncf(y*1e5)*1e-5;
	a=5-findn(truncf(aritmq));
	aritmq=truncf(aritmq*pow(10,a))*pow(10,-a);

	err_a = fabs(result-aritmq);
	err_r = err_a / fabs(result);

	printf("x+y \t  \t %1.8f \t \t %1.5f \t %1.6e \t %1.6e \n",result, aritmq, err_a, err_r);

	//b) x-y
	result =x-y;
        a=8-findn(truncf(result));
        result=truncf(result*pow(10,a))*pow(10,-a);

        aritmq=truncf(x*1e5)*1e-5-truncf(y*1e5)*1e-5;
        a=5-findn(truncf(aritmq));
        aritmq=truncf(aritmq*pow(10,a))*pow(10,-a);

        err_a = fabs(result-aritmq);
        err_r = err_a / fabs(result);

        printf("x-y \t  \t %1.8f \t \t %1.5f \t %1.6e \t %1.6e \n",result, aritmq, err_a, err_r);

	//c) xy
	result =x*y;
        a=8-findn(truncf(result));
        result=truncf(result*pow(10,a))*pow(10,-a);

        aritmq=(truncf(x*1e5)*1e-5)*(truncf(y*1e5)*1e-5);
        a=5-findn(truncf(aritmq));
        aritmq=truncf(aritmq*pow(10,a))*pow(10,-a);

        err_a = fabs(result-aritmq);
        err_r = err_a / fabs(result);

        printf(" xy  \t  \t %1.8f \t \t %1.5f \t %1.6e \t %1.6e \n",result, aritmq, err_a, err_r);

	//d) x/y
	result =x/y;
        a=8-findn(truncf(result));
        result=truncf(result*pow(10,a))*pow(10,-a);

        aritmq=(truncf(x*1e5)*1e-5)/(truncf(y*1e5)*1e-5);
        a=5-findn(truncf(aritmq));
        aritmq=truncf(aritmq*pow(10,a))*pow(10,-a);

        err_a = fabs(result-aritmq);
        err_r = err_a / fabs(result);

        printf(" x/y  \t  \t %1.8f \t \t %1.5f \t %1.6e \t %1.6e \n",result, aritmq, err_a, err_r);

	//e) x-u
	result =x-u;
        a=8-findn(truncf(result));
        result=truncf(result*pow(10,a))*pow(10,-a);

        aritmq=truncf(x*1e5)*1e-5-truncf(u*1e5)*1e-5;
        a=5-findn(truncf(aritmq));
        aritmq=truncf(aritmq*pow(10,a))*pow(10,-a);

        err_a = fabs(result-aritmq);
        err_r = err_a / fabs(result);

        printf("x-u \t  \t %1.8f \t \t %1.5f \t %1.6e \t %1.6e \n",result, aritmq, err_a, err_r);

	//f) (x-u)/w
	result =(x-u)/w;
        a=8-findn(truncf(result));
        result=truncf(result*pow(10,a))*pow(10,-a);

        aritmq=truncf(x*1e5)*1e-5-truncf(u*1e5)*1e-5;
        a=5-findn(truncf(aritmq));
        aritmq=truncf(aritmq*pow(10,a))*pow(10,-a);
	aritmq=aritmq/truncf(w*1e5)*1e-5;
        a=5-findn(truncf(aritmq));
        aritmq=truncf(aritmq*pow(10,a))*pow(10,-a);

        err_a = fabs(result-aritmq);
        err_r = err_a / fabs(result);

        printf("(x-u)/w \t  %1.8f \t \t %1.5f \t %1.6e \t %1.6e \n",result, aritmq, err_a, err_r);

	//g) (x-u)v
	result =(x-u)*v;
        a=8-findn(truncf(result));
	result=truncf(result*pow(10,a))*pow(10,-a);

        aritmq=truncf(x*1e5)*1e-5-truncf(u*1e5)*1e-5;
        a=5-findn(truncf(aritmq));
        aritmq=truncf(aritmq*pow(10,a))*pow(10,-a);
        aritmq=aritmq*truncf(v);
        a=5-findn(truncf(aritmq));
        aritmq=truncf(aritmq*pow(10,a))*pow(10,-a);

        err_a = fabs(result-aritmq);
        err_r = err_a / fabs(result);

	printf("(x-u)v \t  \t %1.8f \t \t %1.5f \t %1.6e \t %1.6e \n",result, aritmq, err_a, err_r);


	//h) u+v

        result =u+v;
	result=truncf(result*1e3)*1e-3;

        aritmq=truncf(u*1e5)*1e-5+truncf(v);
	aritmq=trunc(aritmq);
        err_a = fabs(result-aritmq);
        err_r = err_a / fabs(result);

       printf("u+v \t  \t %1.8f \t  %1.5f \t %1.6e \t %1.6e \n",result, aritmq, err_a, err_r);

}

int findn(int num)
{
if ( num == 0)
      return 0;
   if ( num < 10 )
         return 1;
      if ( num <100 )
            return 2;
         if (num <1000 )
	       return 3;
	   if  (num <10000 )
		   return 4;
	      if (num <100000 )
	               return 5;
}
