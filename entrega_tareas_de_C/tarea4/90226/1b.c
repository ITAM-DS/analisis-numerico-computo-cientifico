#include<stdio.h>
#include<string.h>
#define MAX_LONG 100

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
      char string[MAX_LONG];
  		int longitud;
      while(scanf("%99s", string)!=EOF){
        longitud=longitud_string(string);
        printf("longitud %s: %d\n", string,longitud);
      }
  
  
  return 0;
  }