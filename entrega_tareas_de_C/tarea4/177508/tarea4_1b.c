#include<stdio.h>
#include<string.h>
#define MAX_LONG 200
#define CADENA_PRUEBA "Hola a todos"

int longitud_string(char *s){
    int i;
    i=0;
    while(s[i] != '\0')
        i++;
	s=s+1;
return i;
}
 
int main(void){
    char string1[MAX_LONG]; //definición y declaracion.
    int Long;
while(scanf("%s", string1)==1){
    Long = longitud_string(string1);
    printf("Longitud %s: %i\n",string1,Long );
    }

return 0;
}