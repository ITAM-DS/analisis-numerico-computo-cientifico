/*  Métodos Numéricos y Optimización
    Ejercicio 1
    Ixchel G. Meza Chavez
    Realizar las operaciones pares del ejercicio 1:
    2. x-y
    4. x/y
    6. (x-u)/w
    8. u+v
*/

#include<stdio.h>
#include<math.h>

void main(){
    double atruncar[4]={1e5,1e4,1e4,1};
    double val_8[4], temp[4];
    double x_8 = 0.714285714285714;
    double y_8 = 0.333333333333333;
    double u_8 = 0.714251;
    double v_8 = 98765.9;
    double w_8 = 0.111111e-4;
    double x_5, y_5, u_5, v_5, w_5,temp3;
    double aritm_maq,errA,errR;

    x_5 = truncf(x_8*1e5)/1e5;
    y_5 = truncf(y_8*1e5)/1e5;
    u_5 = truncf(u_8*1e5)/1e5;
    v_5 = truncf(v_8);
    w_5 = truncf(w_8*1e9)/1e9;

    val_8[0] = x_8 - y_8;
    temp[0] = x_5 - y_5;
    val_8[1] = x_8 / y_8;
    temp[1] = x_5 / y_5;
    val_8[2] = (x_8 - u_8) / w_8;
    temp3 = x_5 - u_5;
    temp3 = truncf(temp3*1e5)/1e5;
    temp[2] = temp3 / w_5;
    val_8[3] = u_8 + v_8;
    temp[3] = u_5 + v_5;

    printf("x = %1.8f\ty = %1.8f\tu = %1.7f\tv = %1.2f\tw = %1.11f\n",x_8,y_8,u_8,v_8,w_8);
    printf("operaciones pares:\n2) x-y\n4) x/y\n6) (x-u)/w\n8) u+v\n\n");
    printf("operación\tValor a 8\t\tAritmética de Máquina\tError Absoluto\t\tError Relativo\n");
    for(int i=0;i<4;i++)
    {
        aritm_maq = truncf(temp[i]*atruncar[i])/atruncar[i];
        errA = fabs(val_8[i] - aritm_maq);
        errR = errA/fabs(val_8[i]);
        printf("%d\t\t%e\t\t%e\t\t%e\t\t%e\n",(i+1)*2,val_8[i],aritm_maq,errA,errR);
    }
}
