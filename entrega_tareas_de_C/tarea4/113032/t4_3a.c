#include<stdio.h>
#include<string.h>

 char *corta_string(char *apuntador){
     int l; 
     l = strlen(apuntador);
     if(l > 0){
         apuntador = apuntador+1;
         return apuntador;
     }else{
         printf("Longitud %d\n", l);
         return "ERROR";
     }  
 }
 
 int main(void){
     char *s="Campos verdes";
     // char *s = "";
     s = corta_string(s);
     printf("%s\n", s);
  
return 0;
}
