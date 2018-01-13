/*
Métodos Numéricos y Optimización
Ixchel G. Meza Chávez

Tarea 4 ejercicio 1 inciso b:

b) Investiga el uso de la función scanf para que imprima la longitud de los strings del archivo.txt:

hamburguesas permisos exponencialmente 549

de stdin:

$./ejercicio_1_scanf.out < archivo.txt
longitud hamburguesas: 12
longitud permisos: 8
longitud exponencialmente: 16
longitud 549: 3

*/

#include<stdio.h>
#include<string.h>
#define MAX_LONG 200

int longitud_string(char *s){
    int i;
    i=0;
    while(*s != '\0'){
        i++;
        s=s+1;
    }
return i;
}

int main(void)
{
	char string1[MAX_LONG];
	while(scanf("%s", string1) != EOF){
		printf("longitud %s: %d\n", string1, longitud_string(string1));
	}
	return 0;
}