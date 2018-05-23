#include<stdio.h>
char *corta_string(char *apuntador){
    apuntador=apuntador+1;
    return apuntador;
}

int main(void){
    // char *s="";
    char *s="Campos verdes";
    int size, i;

    size=sizeof(*s)/sizeof(s[0]);
    // printf("size of string %d, %c \n",size, s[0]);
    if(size>0){
	for(i=0;i<size;i++){
		while(*(s+i)!=' '){
		//printf("%c", s[i]);
		 s=corta_string(s);
		}
	}
    	printf("%s\n",s);
    }else{
	printf("ERROR");
    }
 
return 0;
}

