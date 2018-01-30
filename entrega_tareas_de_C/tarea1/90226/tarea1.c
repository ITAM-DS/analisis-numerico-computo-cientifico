#include <stdio.h>
#include <math.h>


int main()
{  
   float x= 0.71428571;
   float y= 0.33333333;
   float u=0.714251;
   float v=98765.9;
   float w=0.00001111;

   double xt = truncf(x*1e5)*1e-5;
   double yt = truncf(y*1e5)*1e-5;
   double ut = truncf(u*1e5)*1e-5;
   double wt = truncf(w*1e5)*1e-5;
   double vt = truncf(v*1e5)*1e-5;




// x-y
   printf("x-y=%f\n", x-y);
   printf("x-y = %.5f\n",xt-yt);
   printf("ErrA = %f\n",fabs((xt-yt)-(x-y)));
   printf("ErrR= %f\n",fabs((xt/yt)-(x/y))/fabs(x-y));




// x/y
   printf("x/y=%f\n", x/y);
   printf("x/y = %.5f\n",(xt)/(yt));
   printf("ErrA= %f\n",fabs((xt/yt)-(x/y)));
   printf("ErrR= %f\n",fabs((xt/yt)-(x/y))/fabs(x/y));





//(x-u)/w
   printf("(x-u)/w=%f\n", (x-u)/w);
   printf("(x-u)/w = %.5f\n",(xt-ut)/wt);
   printf("ErrA= %f\n",fabs(((xt-ut)/(wt))-((x-u)/w)));
   printf("ErrR= %f\n",fabs(((xt-ut)/(wt))-(x-u)/w)/fabs((x-u)/w));

//u+v
   printf("u+v=%f\n", u+v);
   printf("u+v = %.5f\n",(ut+vt));
   printf("ErrA= %f\n",fabs((ut+vt)-(u+v)));
   printf("ErrR= %f\n",fabs((ut+vt)-(u+v))/fabs(u+v));




}
