#include<stdio.h>
char *corta_string(char *apuntador){
    while(*apuntador != ' '){
	apuntador=apuntador + 1;
    }
    apuntador++;
    return apuntador;
}

int main(void){
    char *s="campos verdes";
    if (strlen(s)>0){
	s=corta_string(s);
	printf("%s\n",s);
    }
    else {
	printf("Error!!\n");
    }

return 0;
}
