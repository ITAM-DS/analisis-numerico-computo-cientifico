#include<stdio.h>
#include<math.h>

double truncar(double num, int exp){
    // Esta función trunca al número de decimales
    // indicados.
    double fac = pow(10, exp);
    return truncf(num*fac)/fac;
}    

float errA(float val1, float val2){
    // Esta función devuelve el error absoluto
    // entre los valores indicados.
    float absoluto;

    absoluto = fabs(val1 - val2);

    return absoluto;
}

float errR(float val1, float val2){
    // Esta función devuelve el error relativo
    // entre los valores indicados.
    float absoluto;
    float relativo;

    absoluto = fabs(val1 - val2);
    relativo = fabs(absoluto/val1);

    return relativo;
}

int main(){
    /* Dentro de esta función se harán todos los
    cálculos necesarios para realizar la tabla
    de las operaciones con sus respectivos errores
    y también imprime al STDOUT
    */
    double x_8 = 0.71428571;
    double y_8 = 0.33333333;
    double u_8 = 0.714251;
    double v_8 = 98765.9;

    double x_5 = truncar(x_8,5); 
    double y_5 = truncar(y_8,5);
    double u_5 = truncar(u_8,5);
    double v_5 = truncar(v_8,5);

    // Operación 1 ----- Suma

    double suma_8 = x_8 + y_8;
    double suma_5 = x_5 + y_5;
    double absoluto_suma = errA(suma_8,suma_5);
    double relativo_suma = errR(suma_8,suma_5);

    // Operación 2 ----- Multiplicación

    double mult_8 = x_8 * y_8;
    double mult_5 = x_5 * y_5;
    double absoluto_mult = errA(mult_8,mult_5);
    double relativo_mult = errR(mult_8,mult_5);

    // Operación 3 ----- (x-u)

    double menu_8 = x_8 - u_8;
    double menu_5 = x_5 - u_5;
    double absoluto_menu = errA(menu_8,menu_5);
    double relativo_menu = errR(menu_8,menu_5);

    // Operación 4 ----- (x-u)v

    double porv_8 = (x_8 - u_8)*v_8;
    double porv_5 = (x_5 - u_5)*v_5;
    double absoluto_porv = errA(porv_8,porv_5);
    double relativo_porv = errR(porv_8,porv_5);
    
    printf("\n");

    printf("En primer lugar revisamos que se esté truncando bien, para eso imprimimos un decimal de más que debe ser cero.\n\n");
    printf("\t\t|\t     x \t\t|\t     y \t\t|\t     u \t\t|\t     v \n");
    printf("8 decimales \t|\t %1.8f \t|\t %1.8f \t|\t %1.8f \t|\t %1.8f \n", x_8, y_8, u_8, v_8);
    printf("5 decimales \t|\t %1.6f \t|\t %1.6f \t|\t %1.6f \t|\t %1.6f \n\n\n", x_5, y_5, u_5, v_5);

    printf("La tabla de las operaciones impares\n\n");
    
    printf("Operación \t\t Valor a 8 \t\t\t Aritmética de máquina \t\t ErrA \t\t\t\t ErrR\n");

    printf("X+Y \t\t\t %1.8f \t\t\t %1.5f \t\t\t %e \t\t\t %e\n", suma_8, suma_5, absoluto_suma, relativo_suma);

    printf("X*Y \t\t\t %1.8f \t\t\t %1.5f \t\t\t %e \t\t\t %e\n", mult_8, mult_5, absoluto_mult, relativo_mult);
    
    printf("X-U \t\t\t %1.8f \t\t\t %1.5f \t\t\t %e \t\t\t %e\n", menu_8, menu_5, absoluto_menu, relativo_menu);

    printf("(X-U)*V \t\t %1.8f \t\t\t %1.5f \t\t\t %e \t\t\t %e\n", porv_8, porv_5, absoluto_porv, relativo_porv);
}
