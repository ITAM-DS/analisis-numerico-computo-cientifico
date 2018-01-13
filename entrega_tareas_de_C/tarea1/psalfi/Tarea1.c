#include<stdio.h>
#include<math.h>
main(){
      double x1 = 0.71428571;
      double y1 = 0.33333333;
      double u1 = 0.71425100;
      double v1 = 98765.900;
      double x2, y2, u2, v2;
      double valorocho, aritmaq;
      double ErrA, ErrR;

      x2 = truncf(x2*1e5)*1e-5;
      y2 = truncf(y2*1e5)*1e-5;
      u2 = truncf(u2*1e5)*1e-5;
      v2 = truncf(v2*1e5)*1e-5;
      aritmaq = truncf((x1+y1)*1e5)*1e-5;
      valorocho = x1+y1;
      ErrA = (valorocho-aritmaq);
      ErrR = ErrA/valorocho;
      
      printf("Valor a 8 de x+y: %0.7f\n", valorocho);
      printf("Aritmetica maquina de x+y: %0.5f\n", aritmaq);
      printf("Error Absoluto: %0.7f\n", ErrA);
      printf("Error Relativo: %0.7f\n", ErrR);
      printf("-------------\n");
      printf("\n");
      printf("\n");
      aritmaq = truncf((x1*y1)*1e5)*1e-5;
      valorocho = x1*y1;
      ErrA = (valorocho-aritmaq);
      ErrR = ErrA/valorocho;
      printf("Valor a 8 de x*y: %0.7f\n", valorocho);
      printf("Aritmetica maquina de x*y: %0.5f\n", aritmaq);
      printf("Error Absoluto: %0.7f\n", ErrA);
      printf("Error Relativo: %0.7f\n", ErrR);
      printf("-------------\n");
      printf("\n");
      printf("\n");
      aritmaq = truncf((x1-u1)*1e5)*1e-5;
      valorocho = x1-u1;
      ErrA = (valorocho-aritmaq);
      ErrR = ErrA/valorocho;
      printf("Valor a 8 de x-u: %0.7f\n", valorocho);
      printf("Aritmetica maquina de x-u: %0.5f\n", aritmaq);
      printf("Error Absoluto: %0.7f\n", ErrA);
      printf("Error Relativo: %0.7f\n", ErrR);
      printf("-------------\n");
      printf("\n");
      printf("\n");
      aritmaq = truncf(((x1-u1)*v1)*1e5)*1e-5;
      valorocho = (x1-u1)*v1;
      ErrA = (valorocho-aritmaq);
      ErrR = ErrA/valorocho;
      printf("Valor a 8 de (x-u)/v: %0.7f\n", valorocho);
      printf("Aritmetica maquina de (x-u)*v: %0.5f\n", aritmaq);
      printf("Error Absoluto: %0.7f\n", ErrA);
      printf("Error Relativo: %0.7f\n", ErrR);
      printf("-------------\n");
      printf("\n");
      printf("\n");
}
