/*Arturo Gonzalez Bencomo 172906 */

#include <stdio.h>
#include <math.h>

int main()
{
   double x_num = 5.0;
   double x_den = 7.0;
   double x = x_num/x_den;
   double y_num = 1.0;
   double y_den = 3.0;
   double y = y_num/y_den;
   double u = 0.714251;
   double v = 98765.9;
   double w = .1111E-4;

   //Datos
   printf("Datos originales\n");
   printf("x = %.8f\n",x);
   printf("y = %.8f\n",y);
   printf("u = %.8f\n",u);
   printf("v = %.8f\n",v);
   printf("w = %.8f\n",w);

   double x_5 = truncf(x*1e5)*1e-5;
   double y_5 = truncf(y*1e5)*1e-5;
   double u_5 = truncf(u*1e5)*1e-5;
   double w_5 = truncf(w*1e5)*1e-5;
   double v_5 = truncf(v*1e5)*1e-5;


   //Datos_truncados
   printf("\n\nDatos truncados a 5 posiciones\n\n");
   printf("x_5 = %f\n",x_5);
   printf("y_5 = %f\n",y_5);
   printf("u_5 = %f\n",u_5);
   printf("v_5 = %f\n",v_5);
   printf("w_5 = %f\n",w_5);

   //x-y
   printf("\n\nOperacion 8 digitos\n");
   printf("x-y = %.8f\n",truncf((x-y)*1e9)*(1e-9));
   printf("Operacion 5 digitos x-y\n");
   printf("x-y = %.5f\n",x_5-y_5);
   printf("error absoluto x-y = %.8f\n",fabs((x_5-y_5)-(x-y)));
   printf("error relativo x-y = %.8f\n",fabs((x_5-y_5)-(x-y))/fabs(x-y));

   //x/y
   printf("\n\nOperacion 8 digitos\n");
   printf("x/y = %.8f\n",x/y);
   printf("Operacion 5 digitos x/y\n");
   printf("x/y = %.5f\n",(x_5)/(y_5));
   printf("error absoluto x/y = %.8f\n",fabs((x_5/y_5)-(x/y)));
   printf("error relativo x/y = %.8f\n",fabs((x_5/y_5)-(x/y))/fabs(x/y));

   // (x-u)/w
   printf("\n\nOperacion 8 digitos\n");
   printf("(x-u)/w = %.8f\n",(x-u)/w);
   printf("Operaccion 5 digitos (x-u)/w\n");
   printf("(x-u)/w = %.5f\n",(x_5-u_5)/w_5);
   printf("error absoluto (x-u)/w = %.8f\n",fabs(((x_5-u_5)/(w_5))-((x-u)/w)));
   printf("error relativo (x-u)/w = %.8f\n",fabs(((x_5-u_5)/(w_5))-(x-u)/w)/fabs((x-u)/w));


   // u+v
   printf("\n\nOperacion 8 digitos\n");
   printf("u+v = %8f\n",u+v);
   printf("Operacion 5 digitos u+v\n");
   printf("u+v = %.5f\n",(u_5+v_5));
   printf("error absoluto u+v = %.8f\n",fabs((u_5+v_5)-(u+v)));
   printf("error relativo u+v = %.8f\n",fabs((u_5+v_5)-(u+v))/fabs(u+v));

   return 0;
}
