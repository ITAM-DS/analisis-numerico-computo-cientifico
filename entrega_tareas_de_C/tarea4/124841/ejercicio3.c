#include<stdio.h>
char *corta_string(char *apuntador){
    if(*(apuntador+1)=='\0') {
     char *error="Error, este string solo tiene un caracter"; //checa que sea un string de mas de 1 caracter y devuelve el error en el caso contrario
      apuntador=error;
      }
     else{
    apuntador=apuntador+1;
     }  
  return apuntador;
}

int main(void){
    char *s="Campos verdes";
    char *s2="o";
    char *s3;
    s=corta_string(s);
    s2=corta_string(s2);
    printf("%s\n",s);
    printf("%s\n",s2);
    
    s3=corta_string(s+5);  //para que devuelva verdes recorremos el apuntador al llamar la funcion para que quede al final de la palabra Campos
    printf("%s\n", s3);
 
return 0;
}
