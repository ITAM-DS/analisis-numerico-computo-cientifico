#include<stdio.h>
#include<string.h>
#define MAX_LONG 200
#define CADENA_PRUEBA "Hola a todos"
int longitud_string(char *s){
    int i;
    i=0;
    while(*s != '\0'){
        s=s+1;
        i++;
    }
return i;
}

int main(void){
   char str_1[100],str_2[100],str_3[100],str_4[100];
   scanf("%s",str_1);
   scanf("%s",str_2);
   scanf("%s",str_3);
   scanf("%s",str_4);
   char *str[]={str_1,str_2,str_3,str_4};
   int j=0;
   for (j=0;j<4;j++) {
    printf("longitud de %s : %d\n",str[j],longitud_string(str[j]));
   }
   
return 0;
}