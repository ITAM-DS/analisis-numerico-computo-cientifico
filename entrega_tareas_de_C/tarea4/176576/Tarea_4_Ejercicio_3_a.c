#include<stdio.h>
char *corta_string(char *apuntador){
    apuntador=apuntador+1;
    return apuntador;
}

int main(void){
    char *s="Campos verdes";
    if (strlen(s)>0){
	s=corta_string(s);
	printf("%s\n",s);
    }
    else {
	printf("Error!!\n");
    }

return 0;
}
