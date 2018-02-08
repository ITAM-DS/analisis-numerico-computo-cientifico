#include<stdio.h>
#include<math.h>
main(){
    double x = 0.71428571;
    double y = 0.33333333;
    double u = 0.714251;
    double v = 98765.9;
    double w = 0.111111e-4;
    double x_5,y_5,u_5,v_5,w_5;
    double x_menos_y,x_entre_y,x_u_w,u_mas_v;
    double x_menos_y_5,x_entre_y_5,x_u_w_5,u_mas_v_5;
    
    x_5 = truncf(x*1e5)*1e-5;
    y_5 = truncf(y*1e5)*1e-5;
    u_5 = truncf(u*1e5)*1e-5;
    v_5 = truncf(v*1e5)*1e-5;
    w_5 = truncf(w*1e5)*1e-5;

    //Primera operación:
    x_menos_y=x-y;
    x_menos_y_5 = truncf((x_5-y_5)*1e5)*1e-5;

    //Segunda operación:
    x_entre_y=x/y;
    x_entre_y_5 = truncf((x_5/y_5)*1e5)*1e-5;

    //Tercera operación:
    x_u_w=(x-u)/w;
    x_u_w_5 = truncf(((x_5-u_5)/w_5)*1e5)*1e-5;

    //Cuarta operación:
    u_mas_v=u+v;
    u_mas_v_5 = truncf((u_5+v_5)*1e5)*1e-5;

    printf("\nOperación\t|\tValor a 8\t|\tAritmética de máquina\t|\t ErrA\t\t|\tErrR");
    printf("\n      x-y\t|\t    %1.8f\t|\t         %1.5f\t|\t%1.5f\t\t|\t%1.5f\n",x_menos_y,x_menos_y_5,fabs(x_menos_y-x_menos_y_5),fabs(x_menos_y-x_menos_y_5)/x_menos_y);
    printf("\n      x/y\t|\t    %1.8f\t|\t         %1.5f\t|\t%1.5f\t\t|\t%1.5f\n",x_entre_y,x_entre_y_5,fabs(x_entre_y-x_entre_y_5),fabs(x_entre_y-x_entre_y_5)/x_entre_y);
    printf("\n      (x-u)/w\t|\t    %1.8f\t|\t         %1.5f\t|\t%1.5f\t\t|\t%1.5f\n",x_u_w,x_u_w_5,fabs(x_u_w-x_u_w_5),fabs(x_u_w-x_u_w_5)/x_u_w);
    printf("\n      u+v\t|\t%1.8f\t|\t     %1.5f\t|\t        %1.5f\t|\t%1.5f\n",u_mas_v,u_mas_v_5,fabs(u_mas_v-u_mas_v_5),fabs(u_mas_v-u_mas_v_5)/u_mas_v);
}
