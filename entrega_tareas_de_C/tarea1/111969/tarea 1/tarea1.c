#include <math.h>
#include <stdio.h>

int main()
{

//Declaramos nuestras variables iniciales 
double a = 5.0; //Al definir esto como 5.0 en lugar de 5 conseguimos que el compilador interprete como double la aritmetica
int b = 7;
double c = 1.0;
int d = 3;
//Declaramos x, y, z
double x = a / b; // al definirlo como double conseguimos 64 bits para almacenar en el SPFN
double y = c / d;
double v = 98765.9;
double u = 0.714251;
double w = 0.0000111111;
double z;
double z_2;
double error;
double sum;
// Suma: x+y
printf("x+y \n");   
   // Suma a 5 decimales:
   z = truncf(1e5*(x + y))/1e5 ; //Lo que estamos haciendo es truncar un float a 5 dígitos multiplicando y dividiendo por 100000
   printf("el valor de z = x + y a 5 decimales es %.10f :\n",z);// Le pongo que imprima a 10 decimales para verificar que todo es 0 después del 5to
   // suma a 8 decimales:
      z_2 = truncf(1e8*(x + y))/1e8 ; //Lo que estamos haciendo es truncar un float a 5 dígitos multiplicando y dividiendo por 100000
   printf("el valor de z = x + y a 8 decimales es %.10f : \n",z_2);
   // Calculamos el error:
    error = (z-z_2) ; //Lo que estamos haciendo es truncar un float a 5 dígitos multiplicando y dividiendo por 100000
   printf("el valor del error absoluto es %.10f : \n",error);
   error /=z_2  ; //Lo que estamos haciendo es truncar un float a 5 dígitos multiplicando y dividiendo por 100000
   printf("el valor del error relativo es %.10f : \n",error);
// Multiplicación: x*y
printf("x*y \n");   
   // Mult a 5 decimales:
    z = truncf(1e5*(x * y))/1e5 ; 
    printf("el valor de z = x * y a 5 decimales es %.10f :\n",z);
    z_2 = truncf(1e8*(x * y))/1e8 ;
    printf("el valor de z = x * y a 8 decimales es %.10f : \n",z_2);
   // Calculamos los errores:
    error = (z-z_2); 
    printf("el valor del error absoluto es %.10f : \n",error);
    error /=z_2; 
    printf("el valor del error relativo es %.10f : \n",error);  
// Resta: x-y
printf("x-y \n");   
   //  a 5 decimales:
    z = truncf(1e5*(x - y))/1e5 ; 
    printf("el valor de z = x - y a 5 decimales es %.10f :\n",z);
   //  a 8 decimales:
    z_2 = truncf(1e8*(x - y))/1e8 ; 
    printf("el valor de z = x - y a 8 decimales es %.10f : \n",z_2);
   // Calculamos los errores:
    error = (z-z_2); 
    printf("el valor del error absoluto es %.10f : \n",error);
    error /=z_2; 
    printf("el valor del error relativo es %.10f : \n",error);
// División: x/y
printf("x/y \n");  
   //  a 5 decimales:
    z = truncf(1e5*(x / y))/1e5; 
    printf("el valor de z = x / y a 5 decimales es %.10f :\n",z);
   //  a 8 decimales:
    z_2 = truncf(1e8*(x / y))/1e8; 
    printf("el valor de z = x / y a 8 decimales es %.10f : \n",z_2);
   // Calculamos los errores:
    error = (z-z_2); 
    printf("el valor del error absoluto es %.10f : \n",error);
    error /=z_2; 
    printf("el valor del error relativo es %.10f : \n",error);    


//  (x-u)/w
printf("(x-u)/w \n"); 
   //  a 5 decimales:
    z = truncf(1e5*((x - u)/w))/1e5; 
    printf("el valor de z = (x - u)/w) a 5 decimales es %.10f :\n",z);
   //  a 8 decimales:
    z_2 = truncf(1e8*((x - u)/w))/1e8; 
    printf("el valor de z = (x - u)/w) a 8 decimales es %.10f : \n",z_2);
   // Calculamos los errores:
    error = (z-z_2); 
    printf("el valor del error absoluto es %.10f : \n",error);
    error /=z_2; 
    printf("el valor del error relativo es %.10f : \n",error); 

//  (x-u)*w 
printf("(x-u)*w \n");
   //  a 5 decimales:
    z = truncf(1e5*((x - u)/w))/1e5; 
    printf("el valor de z = (x - u)/w) a 5 decimales es %.10f :\n",z);
   //  a 8 decimales:
    z_2 = truncf(1e8*((x - u)/w))/1e8; 
    printf("el valor de z = (x - u)/w) a 8 decimales es %.10f : \n",z_2);
   // Calculamos los errores:
    error = (z-z_2); 
    printf("el valor del error absoluto es %.10f : \n",error);
    error /=z_2; 
    printf("el valor del error relativo es %.10f : \n",error); 

//  (x-u)*v
printf("(x-u)*v \n");  
   //  a 5 decimales:
    z = truncf(1e5*((x - u)/v))/1e5; 
    printf("el valor de z = (x - u)/v) a 5 decimales es %.10f :\n",z);
   //  a 8 decimales:
    z_2 = truncf(1e8*((x - u)/v))/1e8; 
    printf("el valor de z = (x - u)/v) a 8 decimales es %.10f : \n",z_2);
   // Calculamos los errores:
    error = (z-z_2); 
    printf("el valor del error absoluto es %.10f : \n",error);
    error /=z_2; 
    printf("el valor del error relativo es %.10f : \n",error);

//  u+v
printf("u+v \n"); 
   //  a 5 decimales:
    z = truncf(1e5*(u+v))/1e5; 
    printf("el valor de z = (u+v) a 5 decimales es %.10f :\n",z);
   //  a 8 decimales:
    z_2 = truncf(1e8*(u+v))/1e8; 
    printf("el valor de z = (u+v) a 8 decimales es %.10f : \n",z_2);
   // Calculamos los errores:
    error = (z-z_2); 
    printf("el valor del error absoluto es %.10f : \n ",error);
    error /=z_2; 
    printf("el valor del error relativo es %.10f : \n ",error);    
return 0;
}
