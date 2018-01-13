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
    char string3[MAX_LONG];
    while(scanf("%s", string3) != EOF)
    {
        printf("Longitud %s: %d\n", string3, longitud_string(string3));
    }
return 0;
}