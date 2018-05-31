#include<stdio.h>
#include<math.h>
main(){
        double x_8 = 0.71428571;
        double y_8 = 0.33333333;
	double u_8 = 0.714251;
	double v_8 = 98765.9;
	double w_8 = 0.111111*1e-4;
        double res1_8, res2_8, res3_8, res4_8;
        double error1a, error2a, error3a, error4a;
        double errorR1, errorR2, errorR3, errorR4;
        double x_5;
        double y_5;
	double u_5;
	double v_5;
	double w_5;
        double resultado1, resultado2, resultado3, resultado4;
        double res1_5, res2_5, res3_5, res4_5;
        //función: truncf
        //printf("Valor x_8 con truncf: %1.5f", truncf(x_8));

        res1_8 = 0.38095238;  // de hacer la resta a mano
        x_5 = truncf(x_8*1e5)*1e-5;
        y_5 = truncf(y_8*1e5)*1e-5;
        resultado1 = x_5 - y_5;
        res1_5 = truncf(resultado1*1e5)*1e-5;
        error1a = res1_8 - res1_5;
        errorR1 = error1a/res1_8;
        printf("Valor x_5: %1.4e\n",x_5);
        printf("Valor y_5: %1.4e\n",y_5);

        printf("------- resta ------- \n");

        printf("resta a 8 dig: %f\n", res1_8);
        printf("resta aritmetica maquina: %f\n",res1_5);
        printf("error A de resta: %f\n", error1a);
        printf("error Relativo de resta: %f\n", errorR1);

        printf("------- Division------ \n");

        res2_8 = 0.21428571*1e1;
        resultado2 = x_5/y_5;
        res2_5 = truncf(resultado2*1e5)*1e-5;
        error2a = res2_8 - res2_5;
        errorR2 = error2a/res2_8;
        printf("division a 8 dig: %f\n", res2_8);
        printf("division aritmetica maquina: %f\n", res2_5);
        printf("error A de division: %f\n", error2a);
        printf("error Relativo de division: %f\n", errorR2);

	printf("------- division (x-u)/w ------- \n");
	
	res3_8 = 0.31242892*1e-7;
	u_5 = truncf(u_8*1e5)*1e-5;
	w_5 = truncf(w_8*1e5)*1e-5;
	resultado3 = (x_5 - u_5)/w_5;
	res3_5 = truncf(resultado3*1e5)*1e-5;
	error3a = res3_8 - res3_5;
	errorR3 = error3a/res3_8;
	printf("division compuesta a 8 dig: %f\n", res3_8);
        printf("division compuesta aritmetica maquina: %f\n", res3_5);
        printf("error A de division compuesta: %f\n", error3a);
        printf("error Relativo de division compuesta: %f\n", errorR3);

	printf("------- u + v ------- \n");
	res4_8 = .98766614*1e5;
	v_5 = truncf(v_8*1e5)*1e-5;
	resultado4 = u_5 + v_5;
	res4_5 = truncf(resultado4*1e5)*1e-5;
	error4a = res4_8 - res4_5;
	errorR4 = error4a/res4_8;
	printf("u + v a 8 dig: %f\n", res4_8);
        printf("u + v en aritmetica de maquina: %f\n", res4_5);
        printf("error A de u+v compuesta: %f\n", error4a);
        printf("error Relativo de u+v: %f\n", errorR4);	

}





