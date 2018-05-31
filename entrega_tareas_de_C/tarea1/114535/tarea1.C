#include<stdio.h>
#include<math.h>

main(){
	
	double x = 0.71428571;
	double y = 0.33333333;
	double u = 0.714251;
	double v = 0.987659*1e5;
	double w = 0.111111e-4;
	double x_t, y_t, u_t, v_t, w_t;
	double resp_8, resp_5, err_a, err_r;


	//	Truncamos las variables
	x_t = truncf(x*1e5)*1e-5;
	y_t = truncf(y*1e5)*1e-5;
	u_t = truncf(u*1e5)*1e-5;
	v_t = truncf(v*1e5)*1e-5;
	w_t = truncf(w*1e5) / 1e5;

	// header tabla
	printf("Operación \tValor_a_8\tArit de maq.\tErr_A\tErr_R\n");

	//	x + y
	resp_8 = x + y;
	resp_8 = truncf(resp_8*1e8)*1e-8;
	resp_5 = x_t + y_t;
	resp_5 = truncf(resp_5*1e5)*1e-5;
	
	printf("x + y\t\t");
	printf("%1.7e\t",resp_8);
	printf("%1.4e\t", resp_5);
	printf("%e\t", resp_8 - resp_5);
	printf("%e\n",  err_a/resp_8);
	
	//	x * y
	resp_8 = x * y;
	resp_8 = truncf(resp_8*1e8)*1e-8;
	resp_5 = x_t * y_t;
	resp_5 = truncf(resp_5*1e5)*1e-5;
	
	printf("x * y\t");
	printf("%1.7e\t",resp_8);
	printf("%1.4e\t", resp_5);
	printf("%e\t", resp_8 - resp_5);
	printf("%e\n",  err_a/resp_8);
	
	
	//	x - u
        resp_8 = x - u;
        resp_8 = truncf(resp_8*1e8)*1e-8;
        resp_5 = x_t - u_t;
        resp_5 = truncf(resp_5*1e5)*1e-5;
        printf("x - u\t");
	
	printf("%1.7e\t",resp_8);
	printf("%1.4e\t", resp_5);
	printf("%e\t", resp_8 - resp_5);
	printf("%e\n",  err_a/resp_8);
	

        //     (x - u)v
        resp_8 = x - u;
        resp_8 = truncf(resp_8*1e8)*1e-8;
	resp_8 = resp_8 * v;
	resp_8 = truncf(resp_8*1e8)*1e-8;
	resp_5 = x_t - u_t;
        resp_5 = truncf(resp_5*1e5)*1e-5;
	resp_5 = resp_5 * v_t;
	resp_5 = truncf(resp_5*1e5)*1e-5;
        printf("(x - u)v\t");
	
	printf("%1.7e\t",resp_8);
	printf("%1.4e\t", resp_5);
	printf("%e\t", resp_8 - resp_5);
	printf("%e\n",  err_a/resp_8);
	

}
