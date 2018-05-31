/* 
Arturo Gonzalez Bencomo 172906

Tarea4

Ejercicio1B
*/

#include<stdio.h>
#include<string.h>
#define MAX_LONG 200

// Definimos el prototipo de la funcion
int longitud_string(char *s);

// Funcion principal main 
int main(){
    char cadena[MAX_LONG];
    int longitud, i, contador = 0;    
    scanf("%[^EOF]s", cadena);
    longitud = longitud_string(cadena);    
    for(i=0; i<=longitud; i++){                
        if(cadena[i]=='\n' || cadena[i] == '\0'){
            printf(":%d\n",contador);
            contador = 0;
        }
        else{
            printf("%c", cadena[i]);
            contador++;
        }
    }
    return 0;
}

//Hacemos como tal la implementacion de la funcion longitud_string
int longitud_string(char *s){
    int i=0;    
    while(*s != '\0'){
    	s=s+1;
    	i++;        
    }
	return i;
}
