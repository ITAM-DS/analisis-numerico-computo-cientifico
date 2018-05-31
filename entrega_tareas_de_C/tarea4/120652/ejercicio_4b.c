#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *voltea_string(char *s){
	char *a;
	a = malloc(strlen(s)+1);
	
	if (a != NULL)
	{
	    int to = 0;
	    
        for(int from = strlen(s)-1; from >= 0 ; from--, to++)
    		*(a+to) = *(s+from);
        
        *(a+to)='\0';
	}
	return a;
}

int main(void){
    
    char *s;
    char *s_al_reves;
    
    s = malloc(sizeof(char)*(strlen("Campos verdes") + 1));
    strcpy(s,"Campos verdes");
    
    s_al_reves = voltea_string(s);
    printf("%s\n", s_al_reves);
    free(s_al_reves);
    free(s);
    return 0;
}