#include<stdio.h>
#include<string.h>
#define MAX_LONG 200
int longitud_string(char* s){
    int i;
    i=0;
    while(*s != '\0'){
        i++;
				s++;
		}
return i;
}

int main(void){
    char string_aux[MAX_LONG];
		int long_aux;
    while(scanf("%99s", string_aux)!=EOF){
      long_aux=longitud_string(string_aux);
      printf("longitud %s: %d\n", string_aux,long_aux);
    }


return 0;
}
