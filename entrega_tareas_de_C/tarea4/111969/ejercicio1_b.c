#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_LONG 200
#define CADENA_PRUEBA "Hola a todos"
int longitud_string(char *s){
    int i;
    i=0;
    
  
    int s_0 = s;
    while(s[i] != '\0'){
        s=s+1;
        //printf(" la direccion es %d \n ", s);
    }
        
    int longit = s - s_0;
return longit;
}
 
int main(void){
    char string1[MAX_LONG];
    char string2[MAX_LONG];
    char string3[MAX_LONG];
    char string4[MAX_LONG];
    FILE *fp; // Declaramos nuestro apuntador del archivo
    fp = fopen("test.txt","r"); // Abrimos el archivo
    fscanf(fp,"%s %s %s %s" ,string1,string2,string3,string4);

    printf("cadena: %s , longitud: %d \n", string1,longitud_string(string1));
    printf("cadena: %s , longitud: %d \n", string2,longitud_string(string2));
    printf("cadena: %s , longitud: %d \n", string3,longitud_string(string3));
    printf("cadena: %s , longitud: %d \n", string4,longitud_string(string4));
    
    
return 0;
}
