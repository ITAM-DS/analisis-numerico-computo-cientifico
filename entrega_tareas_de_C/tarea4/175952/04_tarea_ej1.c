// Tarea 4

// 175952
// Karen Esther Peña Albarrán



// Ejercicio 1 
// Modifica la función `longitud_string` del siguiente programa siguiendo estos dos pasos:
// Investiga el uso de la función `scanf` para que imprima la longitud de los strings del archivo.txt:

# include<stdio.h>
# include<string.h>

# define MAX_LONG 200

int longitud_string(char *s){
    int i;
    i=0;
    while(*s != '\0'){
        s=s+1;
        i++;
        }
return i;
}
 
int main(void){
    char string[MAX_LONG]; //definición y declaracion.
    char * token;
  
    scanf("%[^\n]s", string);
    token = strtok(string, " ");

    while (token != NULL){
      printf ("Longitud %s : %d\n",token, longitud_string(token));
      token = strtok(NULL, " ");
    }
    
return 0;
}