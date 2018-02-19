#include <stdio.h>
main(void){
//Pregunta 2
//Este inciso lo utilice para el programa de abajo, por lo que se puede ver
//que el while tiene el getchar en la condición

//Pregunta 3
//Sólo cargo el programa .c sin el .out
    int c;
    int i;
    printf("El contador de letras inicializa en: %d\n",i);
    printf("El string leido es: ");
while((c = getchar()) != EOF && c != '\n'){
        putchar(c);
//        c = getchar();   
    i++;
} 
printf("\nEl número de caracteres es: %d\n",i);
}
