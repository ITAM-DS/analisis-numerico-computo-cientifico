
#include<stdio.h>
#include<string.h>
#define MAX_LONG 200


int longitud_string(char * s){
    int i=0;
    while(*(s++) != '\0')
        i++;
    return i;
}

int main(void){

    char buffer[MAX_LONG]; //definición y declaracion.
   
    while(scanf("%s", buffer) != EOF)
       printf("longitud  %s:  %d\n",buffer, longitud_string(buffer));
	    
    return 0;
}
