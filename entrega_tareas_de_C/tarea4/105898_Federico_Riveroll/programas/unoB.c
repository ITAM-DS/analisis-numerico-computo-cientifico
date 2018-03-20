#include<stdio.h>
#include<string.h>
#define MAX_LONG 200
#define CADENA_PRUEBA "Hola a todos"

int longitud_string(char s[]){
    int i;
    i=0;
    while(s[i] != '\0')
        i++;
return i;
}
 
int main()
{
	int i;
	i = 0;
	char str1[20], str2[30];

	while(i < 4)
	{
	   scanf("%s", str1);
	   printf("Palabra: %s\n", str1);
	   printf("Longitud: %i\n\n", longitud_string(str1));
	   i++;
	}

}
