#include<stdio.h>
#include<math.h>
int main(){
	double x_8 = 0.71428571;
	double y_8 = 0.33333333;
	double u=0.714251;
	double v=98765.9;
	double x_5;
	double y_5;
        double u_5;
        double v_5;
	double suma;
	double suma_5;
	double suma_8;
	double error_a_suma;
	double error_r_suma;

        x_5 = truncf(x_8*1e5)*1e-5;
        y_5 = truncf(y_8*1e5)*1e-5;

	u_5 = truncf(u*1e5)*1e-5;
	v_5 = truncf(v);

        printf("Valor x_8 , x_5: %1.10f %1.10f\n",x_8, x_5);
        printf("Valor y_8 , y_5: %1.10f %1.10f\n",y_8, y_5);

        printf("Valor u , u_5: %1.10f %1.10f\n",u, u_5);
        printf("Valor v , v_5: %1.10f %1.10f\n",v, v_5);


	//1. x + y

	suma_8 =x_8 + y_8;
	suma_8=truncf(suma_8*1e7)*1e-7;
	printf("Valor de la suma a 8 dígitos: %1.10f\n" , suma_8);

	x_5 = truncf(x_8*1e5)*1e-5;
	y_5 = truncf(y_8*1e5)*1e-5;
	printf("Valor x_8 , x_5: %1.10f %1.10f\n",x_8, x_5);
	printf("Valor y_8 , y_5: %1.10f %1.10f\n",y_8, y_5);

	suma = x_5 + y_5;
	printf("Valor de la suma a 5 digitos: %1.10f\n" , suma);
	suma_5 =truncf(suma*1e4)*1e-4;
	printf("Aritmética de la máquina para la suma de X y Y: %1.10f\n",suma_5);

	error_a_suma=suma_8 - suma_5;
	printf("El error absoluto de la suma es: %1.10f\n", fabs(error_a_suma));
	error_r_suma= (error_a_suma/suma_8);
	printf("El error relativo de la suma es: %1.10f\n", error_r_suma);

	//3. x * y

	double multi_8;
	double multi_5;
	double multi;
	double error_a_multi;
	double error_r_multi;

	multi_8= x_8 * y_8;
	multi_8=truncf(multi_8*1e8)*1e-8;
	printf("Valor de la multiplicación a 8 dígitos: %1.10f\n" , multi_8);

        multi = x_5 * y_5;
        printf("Valor de la multiplicación a 5 digitos: %1.10f\n" , multi);
        multi_5 =truncf(multi*1e5)*1e-5;
        printf("Aritmética de la máquina para la multiplicación de X y Y: %1.10f\n",multi_5);

        error_a_multi=multi_8 - multi_5;
        printf("El error absoluto de la multiplicación es: %1.10f\n", fabs(error_a_multi));
        error_r_multi= (error_a_multi/multi_8);
        printf("El error relativo de la multiplicación es: %1.10f\n", error_r_multi);


	// 5. x-u

        double resta_8;
        double resta_5;
        double resta;
        double error_a_resta;
        double error_r_resta;

        resta_8= x_8 - u;

        printf("Valor de la resta de x-u a 8 dígitos: %1.10f\n" , resta_8);

        resta = x_5 - u_5;
        printf("Valor de la resta de x-u a 5 digitos: %1.10f\n" , resta);
	resta_5= truncf(resta*1e-5)*1e5;
        printf("Aritmética de la máquina de la resta de x-u: %1.10f\n", resta);

        error_a_resta=resta_8 - resta;
        printf("El error absoluto de la resta es: %1.10f\n", fabs(error_a_resta));
        error_r_resta= (error_a_resta/resta_8);
        printf("El error relativo de la resta es: %1.10f\n", error_r_resta);

	// 7. (x-u)v

        double multiv_8;
        double multiv_5;
        double multiv;
        double error_a_multiv;
        double error_r_multiv;

	multiv_8 = (x_8 - u)*v;

        printf("Valor de la multiplicación de (x-u)*v a 8 dígitos: %1.10f\n" , multiv_8);

	multiv = (x_5 -u_5)*v_5;
        printf("Valor de la multiplicación de (x-u)*v a 5 dígitos: %1.10f\n" , multiv);
	multiv_5= truncf(multiv*1e4)*1e-4;
	printf("Aritmética de la máquina de la multiplicación de (x-u)*v: %1.10f\n", multiv_5);

	error_a_multiv= multiv_8 - multiv;
	printf("El error absoluto de la multiplicación es: %1.10f\n", fabs(error_a_multiv));
	error_r_multiv= (error_a_multiv/multiv_8);
        printf("El error relativo de la multiplicación es: %1.10f\n", error_r_multiv);

}

