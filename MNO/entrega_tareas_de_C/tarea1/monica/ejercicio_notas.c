#include<stdio.h>
#include<math.h>
main(){
	double x_8 = 0.71428571;
	double y_8 = 0.33333333;
	double x_5;
	double y_5;
	double u_5;
	double w_5;
        double v_5; 
        double u_8= 0.714251;
	double v_8= 98765.9;
        double w_8= 0.00001111;	
	double suma, resta, absoluto, div,div2,suma2,relativo;
	//función: truncf y fabs

        printf("Ejercicio de Notas Aritmetica de Maquina\n");
        printf("Se imprimen los valores a 5\n");

	x_5 = truncf(x_8*1e5)*1e-5;
	printf("Valor x a 5: %e\n",x_5);
	y_5 = truncf(y_8*1e5)*1e-5;
	printf("Valor y a 5: %e\n",y_5);
        u_5 = truncf(u_8*1e5)*1e-5;
        printf("Valor u a 5: %e\n",u_5);
        w_5 = truncf(w_8*1e5)*1e-5;
        printf("Valor w a 5: %e\n",w_5);
        v_5 = truncf(v_8/100000*1e5)*1e-5;
        printf("Valor v a 5: %e\n\n",v_5);

	printf("Ejercicio realizado en clase\n");
	printf("Operacion \t Valor a 8 \t Aritmetica de maquina \t \t ErrAbsoluto \t\t ErrRelativo \n");
	suma=(x_5+y_5)/10;
	suma = truncf(suma*1e5)*1e-5;
        absoluto=fabs(suma-(x_8+y_8)/10);
	relativo=absoluto/(fabs((x_8+y_8))/10);
	printf("x+y \t \t %f \t \t %f \t \t %e \t \t %e \n", x_8+y_8, suma, absoluto, relativo);

 	printf("\nEjercicio de operaciones pares\n");
        resta=(x_5-y_5);
        resta = truncf(resta*1e5)*1e-5;
        absoluto=fabs(resta-(x_8-y_8));
        relativo=absoluto/fabs(x_8-y_8);
	printf("Operacion \t Valor a 8 \t\t Aritmetica de maquina \t ErrAbsoluto \t \t ErrRelativo \n");
	printf("x-y \t \t %1.8f \t \t %f \t \t %e \t \t %e \n", x_8-y_8, resta, absoluto, relativo);

        div=(x_5/y_5)/10;
        div = truncf(div*1e5)*1e-5;
        absoluto=fabs(div*10-(x_8/y_8));
        relativo=absoluto/(fabs(x_8/y_8));
        printf("x/y \t \t %1.8f \t \t %f \t \t %e \t \t %e \n", x_8/y_8, div, absoluto, relativo);

        div2=x_5-u_5;
        div2 = truncf(div2*1e5)*1e-5;
        div2=truncf((div2/w_5)*1e5)*1e-5;
	div2=div2/10;
        absoluto=fabs(div2*10-(x_8-u_8)/w_8);
        relativo=absoluto/(fabs((x_8-u_8)/w_8));
	printf("(x-u)/w \t %1.8f \t\t %f \t \t %e \t \t %e \n", ((x_8-u_8)/w_8), div2, absoluto, relativo);

        suma2=(u_5/100000)+v_5;
        suma2 = truncf(suma2*1e5)*1e-5;
        absoluto=fabs(suma2*100000-(u_8+v_8));
        relativo=absoluto/(fabs(u_8+v_8));
	printf("u+v \t\t %1.8f \t %f \t\t %e \t\t %e \n", u_8+v_8, suma2*100000, absoluto, relativo);
}
