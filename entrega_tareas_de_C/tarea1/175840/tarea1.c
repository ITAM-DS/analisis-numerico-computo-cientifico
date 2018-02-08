#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

double truncar(double valor, int digitos){
    int i = 0;
    int base = 10;
    //Contar numero de digitos parte entera
    while( valor >= 1 ){
        valor /= base;
        i++;
    }
    valor  = truncf(valor * pow(base,digitos))*pow(base,-digitos);
    valor  = valor*pow( base,i);

	return valor;
}

double error_a(double a, double b){
    return fabs(a-b);
}

double error_r(double a, double b){
    return fabs(error_a(a,b)/a);
}

int main()
{
    FILE *archivo;

    double x = 0.71428571;
    double y = 0.33333333;
    double u = 0.714251;
    double v = 98765.9;
    double x5 = truncar(x,5);
    double y5 = truncar(y,5);
    double u5 = truncar(u,5);
    double v5 = truncar(v,5);
    int b = 5;
    int k = 10;

    archivo = fopen("resultado.txt","w");


    if(archivo != NULL){

        // Salida a consola
        printf("Tarea 1\nMiguel Castaneda Santiago\nC.U. 175840\n\n");
        printf("Operacion |\tValor a 8      |\tAritmetica de maquina|\tErrA    |\tErrR        |\n");
        printf("____________________________________________________________________________________________\n");
        printf("x + y     |\t%.8e|\t%.5e |\t%.5e    |\t%.5e|\n",
               truncar(x+y,8), x5+y5, error_a(truncar(x+y,8), x5+y5) , error_r(truncar(x+y,8), x5+y5));
        printf("x * y     |\t%.8e|\t%.5e |\t%.5e    |\t%.5e|\n",
               truncar(x*y,8), x5*y5, error_a(truncar(x*y,8), x5*y5) , error_r(truncar(x*y,8), x5*y5));
        printf("x - u     |\t%.8e|\t%.5e |\t%.5e    |\t%.5e|\n",
               truncar(x-u,8), x5-u5, error_a(truncar(x-u,8), x5-u5) , error_r(truncar(x-u,8), x5-u5));
        printf("(x - u)*v |\t%.8e|\t%.5e |\t%.5e    |\t%.5e|\n",
               truncar((x-u)*v,8), (x5-u5)*v5, error_a(truncar((x-u)*v,8), (x5-u5)*v5) ,
               error_r(truncar((x-u)*v,8), (x5-u5)*v5));
        printf("____________________________________________________________________________________________\n");

        // Salida a archivo

        fprintf(archivo,"Tarea 1\nMiguel Castaneda Santiago\nC.U. 175840\n\n");
        fprintf(archivo,"Operacion |\tValor a 8      |\tAritmetica de maquina|\tErrA    |\tErrR        |\n");
        fprintf(archivo,"____________________________________________________________________________________________\n");
        fprintf(archivo,"x + y     |\t%.8e|\t%.5e |\t%.5e    |\t%.5e|\n",
               truncar(x+y,8), x5+y5, error_a(truncar(x+y,8), x5+y5) , error_r(truncar(x+y,8), x5+y5));
        fprintf(archivo,"x * y     |\t%.8e|\t%.5e |\t%.5e    |\t%.5e|\n",
               truncar(x*y,8), x5*y5, error_a(truncar(x*y,8), x5*y5) , error_r(truncar(x*y,8), x5*y5));
        fprintf(archivo,"x - u     |\t%.8e|\t%.5e |\t%.5e    |\t%.5e|\n",
               truncar(x-u,8), x5-u5, error_a(truncar(x-u,8), x5-u5) , error_r(truncar(x-u,8), x5-u5));
        fprintf(archivo,"(x - u)*v |\t%.8e|\t%.5e |\t%.5e    |\t%.5e|\n",
               truncar((x-u)*v,8), (x5-u5)*v5, error_a(truncar((x-u)*v,8), (x5-u5)*v5) ,
               error_r(truncar((x-u)*v,8), (x5-u5)*v5));
        fprintf(archivo,"____________________________________________________________________________________________\n");


        fclose(archivo);
    }
    else {
        printf("No se pudo crear el archivo ...");
    }

    return 0;
}
