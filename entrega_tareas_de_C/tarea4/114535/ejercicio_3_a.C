#include<stdio.h>
char *corta_string(char *apuntador){
    apuntador=apuntador+1;
    return apuntador;
}

int main(void){
    // char *s="";
    char *s="Campos verdes";
    int size;
    size=sizeof(s)/sizeof(s[0]);
    if(size>0){
	s=corta_string(s);
    	printf("%s\n",s);
    }else{
	printf("ERROR");
    }
 
return 0;
}

