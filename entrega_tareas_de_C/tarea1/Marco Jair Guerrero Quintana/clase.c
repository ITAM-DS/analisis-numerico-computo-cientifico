#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	double x = (double) 5/7; 
	double y = (double)1/3;
	double u = 0.714251;
	double v = 98765.9;
	double w = 0.111111 * (10^(-4));

	double xf =(truncf(x*1e5))*1e-5;
    double yf =(truncf(y*1e5))*1e-5;
    double uf =(truncf(u*1e5))*1e-5;
    double vf =(truncf(v*1e5))*1e-5;
 	double wf =(truncf(w*1e5))*1e-5;

	
	double sum = (double) (x+y);  /* (double) es una casting, convierte una operación o dato, */ 
	double rest = (double) (x-y); /* al tipo de datos que estoy forzando*/
	double mult = (double) (x*y); 
	double divi = (double) (x/y);
	double rest2 = (double) (x-u);
	double divi2 = (double) ((x-u)/w);
	double mult2 = (double) ((x-u)*v);
	double sum2 = (double) (u+v);

	double sum_5 = (truncf((xf+yf)*1e5))*1e-5;
 	double rest_5 = (truncf((xf-yf)*1e5))*1e-5;   
    double mult_5 = (truncf((xf*yf)*1e5))*1e-5;
    double divi_5 = (truncf((xf/yf)*1e5))*1e-5;
    double rest2_5 = (truncf((xf-uf)*1e5))*1e-5;
    double divi2_5 = (truncf(((xf-uf)/wf)*1e5))*1e-5;
    double mult2_5 = (truncf(((xf-uf)*vf)*1e5))*1e-5;
    double sum2_5 = (truncf((uf*vf)*1e5))*1e-5;

    //Errores absolutos
	double err_abs1 = abs(sum-sum_5);
	double err_abs2 = abs(rest-rest2);
	double err_abs3 = abs(mult-mult_5);
	double err_abs4 = abs(divi-divi_5);
	double err_abs5 = abs(rest2-rest2_5);
	double err_abs6 = abs(divi2-divi2_5);
	double err_abs7 = abs(mult2-mult2_5);
	double err_abs8 = abs(sum2-sum2_5);

	//Errores relativos
	double err_rel1 = abs(sum-sum_5)/err_abs1;
	double err_rel2 = abs(rest-rest2)/err_abs2;
	double err_rel3 = abs(mult-mult_5)/err_abs3;
	double err_rel4 = abs(divi-divi_5)/err_abs4;
	double err_rel5 = abs(rest2-rest2_5)/err_abs5;
	double err_rel6 = abs(divi2-divi2_5)/err_abs6;
	double err_rel7 = abs(mult2-mult2_5)/err_abs7;
	double err_rel8 = abs(sum2-sum2_5)/err_abs8;

	printf("\n\n\n x_8:   %.8lf\n", x);
	printf(" y_8:   %.8lf\n", y);
	printf(" u_8:   %.8lf\n", u);
	printf(" v_8:   %.8lf\n", v);
	printf(" w_8:   %.8lf\n\n", w);

	printf(" x_5:   %.5lf\n", xf);
	printf(" y_5:   %.5lf\n", yf);
	printf(" u_5:   %.5lf\n", uf);
	printf(" v_5:   %.5lf\n", vf);
	printf(" w_5:   %.5lf\n\n", wf);

	printf(" x+y: %.8lf\n",sum );
	printf(" x-y: %.8lf\n",rest );
	printf(" x*y: %.8lf\n",mult );
	printf(" x/y: %.8lf\n",(double) (x / y) ); 
	printf(" x-u: %.8lf\n",(double) x-u );
	printf(" (x-u)/w: %.8lf\n",(double) (x-u)/w );
	printf(" (x-u)*v: %.8lf\n",(double) (x-u)*v );
	printf(" u+v: %.8lf\n\n",(double) u+v );

	printf(" ErrA x+y: %.8lf\n\n", err_abs1);
	printf(" ErrA x-y: %.8lf\n", err_abs2);
	printf(" ErrA x*y: %.8lf\n", err_abs3);
	printf(" ErrA x/y: %.8lf\n", err_abs4);
	printf(" ErrA x-u: %.8lf\n", err_abs5);
	printf(" ErrA (x-u)/w: %.8lf\n", err_abs6);
	printf(" ErrA (x-u)*v: %.8lf\n", err_abs7);
	printf(" ErrA u+v: %.8lf\n\n", err_abs8);

	printf(" ErrR x+y: %.8lf\n", err_rel1);
	printf(" ErrR x-y: %.8lf\n", err_rel2);
	printf(" ErrR x*y: %.8lf\n", err_rel3);
	printf(" ErrR x/y: %.8lf\n", err_rel4);
	printf(" ErrR x-u: %.8lf\n", err_rel5);
	printf(" ErrR (x-u)/w: %.8lf\n", err_rel6);
	printf(" ErrR (x-u)*v: %.8lf\n", err_rel7);
	printf(" ErrR u+v: %.8lf\n", err_rel8);


}

