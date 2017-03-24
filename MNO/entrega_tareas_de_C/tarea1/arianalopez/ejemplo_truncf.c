#include<stdio.h>
#include<math.h>
void main(){
    double x_8 = 0.71428571;
    double y_8 = 0.33333333;
    double u_8 = 0.71425100;
    double v_8 = 98765.900;
    double w_8 = 0.111111e-4;
    double x_5;
    double y_5;
    double u_5;
    double v_5;
    double w_5;
    double variable_double = -3.0;
    double valmaq, valocho, ErrA, ErrR;

    //funcion: truncf a 5 posiciones  para todas las variables en 8
    x_5 = truncf(x_8*1e5)*1e-5;
    y_5 = truncf(y_8*1e5)*1e-5;
    u_5 = truncf(u_8*1e5)*1e-5;
    v_5 = truncf(v_8*1e5)*1e-5;
    w_5 = truncf(w_5*1e5)*1e-5;

//x+y
    valmaq = truncf((x_5+y_5)*1e5)*1e-5;
    valocho = x_8+y_8;
    ErrA = valocho - valmaq;
    ErrR = ErrA/valocho;
    printf("Ejercicio x+y--\n");
    printf("Valor x_8: %0.7f\n", x_8);
    printf("Valor y_8:: %0.7f\n", y_8);
    printf("Valor x_5: %0.5f\n", x_5);
    printf("Valor y_5:: %0.5f\n", y_5);
    printf("Valor a ocho de x+y: %0.7f\n", valocho);
    printf("Valor arit maquina de x+y: %0.5f\n", valmaq);
    printf("ErrA: %0.7f\n", ErrA);
    printf("ErrR: %0.7f\n", ErrR);
    printf("Fin---\n");

//x-y
    valmaq = truncf((x_5-y_5)*1e5)*1e-5;
    valocho = x_8-y_8;
    ErrA = valocho - valmaq;
    ErrR = ErrA/valocho;
    printf("Ejercicio x-y--\n");
    printf("Valor x_8: %0.7f\n", x_8);
    printf("Valor y_8: %0.7f\n", y_8);
    printf("Valor x_5: %0.5f\n", x_5);
    printf("Valor y_5: %0.5f\n", y_5);
    printf("Valor a ocho de x-y: %0.7f\n", valocho);
    printf("Valor arit maquina de x-y: %0.5f\n", valmaq);
    printf("ErrA: %0.7f\n", ErrA);
    printf("ErrR: %0.7f\n", ErrR);
    printf("Fin---\n");

//x*y
    valmaq = truncf((x_5*y_5)*1e5)*1e-5;
    valocho = x_8*y_8;
    ErrA = valocho - valmaq;
    ErrR = ErrA/valocho;
    printf("Ejercicio x*y--\n");
    printf("Valor x_8: %0.7f\n", x_8);
    printf("Valor y_8: %0.7f\n", y_8);
    printf("Valor x_5: %0.5f\n", x_5);
    printf("Valor y_5: %0.5f\n", y_5);
    printf("Valor a ocho de x*y: %0.7f\n", valocho);
    printf("Valor arit maquina de x*y: %0.5f\n", valmaq);
    printf("ErrA: %0.7f\n", ErrA);
    printf("ErrR: %0.7f\n", ErrR);
    printf("Fin---\n");

//x/y
    valmaq = truncf((x_5/y_5)*1e5)*1e-5;
    valocho = x_8/y_8;
    ErrA = valocho - valmaq;
    ErrR = ErrA/valocho;
    printf("Ejercicio x/y--\n");
    printf("Valor x_8: %0.7f\n", x_8);
    printf("Valor y_8: %0.7f\n", y_8);
    printf("Valor x_5: %0.5f\n", x_5);
    printf("Valor y_5: %0.5f\n", y_5);
    printf("Valor a ocho de x/y: %0.7f\n", valocho);
    printf("Valor arit maquina de x/y: %0.5f\n", valmaq);
    printf("ErrA: %0.7f\n", ErrA);
    printf("ErrR: %0.7f\n", ErrR);
    printf("Fin---\n");

//x-u
    valmaq = truncf((x_5-u_5)*1e5)*1e-5;
    valocho = x_8-u_8;
    ErrA = valocho - valmaq;
    ErrR = ErrA/valocho;
    printf("Ejercicio x-u--\n");
    printf("Valor x_8: %0.7f\n", x_8);
    printf("Valor u_8: %0.7f\n", u_8);
    printf("Valor x_5: %0.5f\n", x_5);
    printf("Valor u_5: %0.5f\n", u_5);
    printf("Valor a ocho de x-u: %0.7f\n", valocho);
    printf("Valor arit maquina de x-u: %0.5f\n", valmaq);
    printf("ErrA: %0.7f\n", ErrA);
    printf("ErrR: %0.7f\n", ErrR);
    printf("Fin---\n");

//u+v
    valmaq = truncf((u_5+v_5)*1e5)*1e-5;
    valocho = u_8+v_8;
    ErrA = valocho - valmaq;
    ErrR = ErrA/valocho;
    printf("Ejercicio u+v --\n");
    printf("Valor u_8: %0.7f\n", u_8);
    printf("Valor v_8: %0.7f\n", v_8);
    printf("Valor u_5: %0.5f\n", u_5);
    printf("Valor v_5: %0.5f\n", v_5);
    printf("Valor a ocho de u+v: %0.7f\n", valocho);
    printf("Valor arit maquina de u+v: %0.5f\n", valmaq);
    printf("ErrA: %0.7f\n", ErrA);
    printf("ErrR: %0.7f\n", ErrR);
    printf("Fin---\n");

//x-u/v
    valmaq = truncf(((x_5-u_5)/v_5)*1e5)*1e-5;
    valocho = (x_8-u_8)/v_8;
    ErrA = valocho - valmaq;
    ErrR = ErrA/valocho;
    printf("Ejercicio x-u/v --\n");
    printf("Valor x_8: %0.7f\n", x_8);
    printf("Valor u_8: %0.7f\n", u_8);
    printf("Valor v_8: %0.7f\n", v_8);
    printf("Valor x_5: %0.5f\n", x_5);
    printf("Valor u_5: %0.5f\n", u_5);
    printf("Valor v_5: %0.5f\n", v_5);
    printf("Valor a ocho de x-u/v: %0.7f\n", valocho);
    printf("Valor arit maquina de x-u/v: %0.5f\n", valmaq);
    printf("ErrA: %0.7f\n", ErrA);
    printf("ErrR: %0.7f\n", ErrR);
    printf("Fin---\n");

//x-u/w
    valmaq = truncf(((x_5-u_5)/w_5)*1e5)*1e-5;
    valocho = (x_8-u_8)/w_8;
    ErrA = valocho - valmaq;
    ErrR = ErrA/valocho;
    printf("Ejercicio x-u/w --\n");
    printf("Valor x_8: %0.7f\n", x_8);
    printf("Valor u_8: %0.7f\n", u_8);
    printf("Valor w_8: %0.7f\n", w_8);
    printf("Valor x_5: %0.5f\n", x_5);
    printf("Valor u_5: %0.5f\n", u_5);
    printf("Valor w_5: %0.5f\n", w_5);
    printf("Valor a ocho de x-u/w: %0.7f\n", valocho);
    printf("Valor arit maquina de x-u/w: %0.5f\n", valmaq);
    printf("ErrA: %0.7f\n", ErrA);
    printf("ErrR: %0.7f\n", ErrR);
    printf("Fin---\n");
}
