#include<stdio.h>
#include<string.h>
#define MAX_LONG 200

int longitud_string(char *s){
    int i=0;
    while(*s != '\0'){
    s++, i++;
    if(i == MAX_LONG)break;
    }
return i;
}

int main(void)
{
	char string[MAX_LONG];
	while(scanf("%s", string) != EOF){
		printf("longitud %s: %d\n", string, longitud_string(string));
	}
	return 0;
}
