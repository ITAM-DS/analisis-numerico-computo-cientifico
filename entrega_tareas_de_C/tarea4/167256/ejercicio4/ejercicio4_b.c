#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *voltea_string(char *str){
  int longitud,i;
    longitud = strlen(str);
    char *p;
    p = (char*)malloc((longitud+1) * sizeof(char));
    for (i=0;i<longitud;i++)
        p[longitud-i-1] = str[i]; 
    return p;
}

int main(void){
  char s[] = "Campos verdes";
  char *s_volteado;

    s_volteado = voltea_string(s);
    printf("%s\n",s_volteado);
    free(s_volteado);
    
    return 0;
}
