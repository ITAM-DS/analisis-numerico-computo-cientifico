#include<stdio.h>
#include<string.h>
#define MAX_LONG 200
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
    char string[MAX_LONG]; //definición y declaracion.
    while(scanf("%s",string) != EOF){
    printf("Longitud %s:%d\n",string,longitud_string(string));
    }

return 0;
}

