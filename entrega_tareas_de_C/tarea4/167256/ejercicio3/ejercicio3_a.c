#include<stdio.h>
#include<string.h>
char *corta_string(char *apuntador){
  int longitud;
  longitud = strlen(apuntador);
  if(longitud>1) apuntador=apuntador+1;
  else apuntador = "Error: La cadena ingresada no cuenta con 1 o mas caracteres";
  return apuntador;
}

int main(void){
    char *s="Campos verdes";
    printf("Probamos con la cadena: %s\n",s);
    s=corta_string(s);
    printf("Resultado: %s\n",s);

    char *s1="";
    printf("Probamos con la cadena: %s\n",s1);
    s1=corta_string(s1);
    printf("Restulado: %s\n",s1);

    char *s2="X";
    printf("Probamos con la cadena: %s\n",s2);
    s2=corta_string(s2);
    printf("Resultado: %s\n",s2);

    char *s3=" Y";
    printf("Probamos con la cadena: %s\n",s3);
    s3=corta_string(s3);
    printf("Resultado: %s\n",s3);
 
return 0;
}
