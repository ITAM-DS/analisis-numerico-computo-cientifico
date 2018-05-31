//Daniel Sharp 138176
// Ejercicio 3A

#include<stdio.h>
#include<string.h> // agregamos string.h para utilizar strlen
char *corta_string(char *apuntador){
  // Definimos mensaje de error en un apuntador
  char *err = "Error: ingresar string con longitud mayor a 1";
  // verificamos si string es mayor a 1, si es, eliminamos primer caracter
  if(strlen(apuntador) > 1){
    apuntador=apuntador+1;
    // si no lo es, regresamos mensaje de error
  }else{
    apuntador = err;
  }
  return apuntador;
}

int main(int argc, char *argv[]){
    char *s=argv[1]; // Recibe el string a través de la línea de comando
    s=corta_string(s);
    printf("%s\n",s);

return 0;
}
