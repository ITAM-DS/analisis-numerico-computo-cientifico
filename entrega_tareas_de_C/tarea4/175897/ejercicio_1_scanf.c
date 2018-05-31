#include<stdio.h>
#include<string.h>
#define MAX_LONG 200

int longitud_string(char *s){
    int i;
    i=0;
    while(*s != '\0'){
        i++;
        s=s+1;
    }
return i;
}
 
int main(void){
    char string1[MAX_LONG]; //definición y declaracion.
    char * pch;

    scanf("%[^\t\n]",string1);
    pch =strtok (string1," ");

    while (pch != NULL) {
    printf ("longitud %s",pch);
    printf(": %d\n", longitud_string(pch));
    pch = strtok (NULL, " ");
    }

return 0;
}


