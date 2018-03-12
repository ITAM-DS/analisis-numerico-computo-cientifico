#include<stdio.h>
#include<string.h>

// 1a. Modificar la función longitud_string:
//     longitud_string(char *s)
//     Recorrer el string con un apuntador
//       escribir s = s+1; en el while
//       incluir una condición en el while para detener el loop.

#define MAX_LONG 200
int longitud_string(char *s){
    int count = 0;
    while(*s != '\0') {
        s = s+1;
        count++;
}
return count;
}

int main(void){
    int i=0;
    char string1[MAX_LONG];
    char *palabra;
    scanf("%[^\n]s", string1);
    palabra = strtok(string1, " ");
    while(palabra != NULL) {
      palabra = strtok(NULL, " ");
      if(palabra != NULL) {
          printf("Longitud %s: %d\n", palabra, longitud_string(palabra));
      }
    }
return 0;
}
