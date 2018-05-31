// Daniel Sharp Conkling
// 138176

#include<stdio.h>
#include<string.h>

int longitud_string(char *s){
    int i;
    i=0;
    while(*s != '\0'){
        i++;
        s++;
      }
return i;
}

int main() {
  char valor[50];
  int c;
  do{
    scanf("%s",valor); // se implementa la funcion scanf para leeer el input (archivo.txt)
    printf("longitud %s: %d\n",valor, longitud_string(valor));
  }while((c=getchar()) != 10);

  return 0;
}
