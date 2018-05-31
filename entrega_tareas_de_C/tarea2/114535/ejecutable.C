/*
Ejercicio 1:
1. Investiga lo que quieren decir las letras EOF. ¿Por qué se debe definir c como int?
	EOF it's a special value that the input functions return to indicate a condition, that the "end of file

C Se define c como un int porque en los characters se almacenan con el estandar ascii: 
	en donde A=65, a=99

*/

// #include <stdio.h>
// int main(void){
//     int c;
//     while( (c = getchar()) ){
//         putchar(c);
//         c = getchar();  
// 	printf("si imprimimos el character en ascii %d", c); 
//     } 
// }





/*
Ejercicio 2
Utiliza getchar para escribir un programa que cuente el número de caracteres dado un stdin e imprima este número.
Al dar enter (salto de línea) el programa termina. Por ejemplo:
echo -e "hola\n" | ./ejecutable.out
*/

//#include <stdio.h>
//int main(void){
//	int c;
//	int contador = 0;
//	while((c=getchar()) != EOF){
//	++contador;
//	} 
//  return printf(" %d ", contador - 2);
// }





/* 
Ejercicio 3
Modifica el programa de 3) para que cuente el número de líneas dado un archivo de stdin:
// Prueba ejemplo:
// printf 'HelloWorld\n%.0s' {1..5} > file.txt
// echo file.txt | ./ejecutable
*/


#include <stdio.h>
#define MAX_FILE_NAME 100

int main(){
	FILE *fp;
	char c;
	int contador = 0;
	char filename[MAX_FILE_NAME];
    
	printf("Enter file name: ");
	scanf("%s", filename);	
	fp = fopen(filename, "r");

	for (c = getc(fp); c != EOF; c = getc(fp))
		if (c == '\n') 
		    ++contador;
  return printf(" %d ", contador);
 }
