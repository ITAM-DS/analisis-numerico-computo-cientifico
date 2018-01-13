#include<stdio.h>
#include <string.h>
int main (void){
    char expr1[100];
    char expr2[100];
    int m;
    int x;
    int charcount=0;
    scanf("%[^\n]s", expr1);
    x=strlen(expr1);
    for(m=0;m<=x; m++) {
        if ((expr1[m] == ' ') || (m == x)) {
            printf("Numero de letras de la palabra %s %d \n",expr2,charcount);
            memset(expr2,'\0',100);
            charcount=0;
        }
     else  {
       expr2[charcount]=expr1[m];
       charcount ++;
     }
        
    }
} 
