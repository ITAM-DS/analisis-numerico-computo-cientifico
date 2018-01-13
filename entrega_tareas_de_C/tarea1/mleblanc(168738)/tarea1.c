#include <stdio.h>
#include <math.h>

main(){
 	
 double x_8=0.71428571;
 double y_8=0.33333333;
 double u_8=0.71425100;
 double v_8=98765.900;
 double w_8=0.11111100e-4;

 double x_5=truncf(x_8*1e5)/1e5;
 double y_5=truncf(y_8*1e5)/1e5;
 double u_5=truncf(u_8*1e5)/1e5;
 double v_5=truncf(v_8*1e5)/1e5;
 double w_5=truncf(w_8*1e5)/1e5;

 double menos=x_8-y_8;
 double menos_arith=truncf((x_5-y_5)*1e5)/1e5;

 double div=x_8/y_8;
 double div_arith=truncf((x_5/y_5)*1e4)/1e4;

 double menos_div=(x_8-u_8)/w_8;
 double menos_div_arith=truncf(((x_5-u_5)/w_5)*1e5)/1e5;

 double plus=u_8+v_8;
 double plus_arith=truncf((u_8+v_8));

 printf(" x-y \t %0.8f \t %1.5f \t %1.8f \t %1.8f \n",menos,menos_arith,fabs(menos-menos_arith),fabs(menos-menos_arith)/fabs(menos));
		
 printf(" x/y \t %4.8f \t %1.4f \t %1.8f \t %1.8f \n",div,div_arith,fabs(div-div_arith),fabs(div-div_arith)/div);
		
 printf(" (x-u)/w \t %4.8f \t %1.4f \t %1.8f \t %1.8f \n",menos_div,menos_div_arith,fabs(menos_div_arith-menos_div),fabs(menos_div_arith-menos_div)/fabs(menos_div));
		
 printf(" (u+v) \t %5.8f \t %1.0f \t %1.8f \t %1.8f \n",plus,plus_arith,fabs(plus-plus_arith),fabs(plus-plus_arith)/fabs(plus));
		
 }




