#include<stdio.h>
#include<string.h>
#define MAX_LONG 200
int longitud_string(char *s){
int i;
i=0;
while(*s != '\0'){
    s = s + 1;
    i++;
}
return i;
}

int main(void){
     char str[MAX_LONG];
     while(scanf("%s", str) != EOF){
     	printf("longitud %s: %d\n", str, longitud_string(str));
    }
return 0;
}
