#include<stdio.h>
#include<string.h>
#define MAX_LONG 200

int longitud_string(char *s){
    int i = 0;
    while(*s != '\0')
    {
        s = s + 1;
        i++;
    }
return i;
}
 
int main(void){
    char string[MAX_LONG];
    
    scanf("%[^EOF]", string);
    
    int longitud = 0;

    for(int i = 0; i <= longitud_string(string); i++)
    {
        if(string[i] == ' ' || string[i] == '\n' || string[i] == '\0')
        {
            printf(": %d\n",longitud);
            longitud = 0;
        }
        else
        {
            printf("%c", string[i]);
            longitud ++;
        }
         
    }
return 0;
}