#include <stdio.h>
int longitud_string(char *s){
    int i;
    i=0;
    while(*(s++) != '\0'){
      i++;
    }
    return i;
}
int main (){
    char str [100];
    while(scanf("%99s", str) != EOF){
        printf ("longitud %s %d\n", str, longitud_string(str));
    }
    return 0;
}