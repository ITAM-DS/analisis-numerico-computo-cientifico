//Tarea2 By Ricardo Lastra



//1)Investiga lo que quieren decir las letras EOF. ¿Por que se debe definir c como int?
//Respuesta:
//Para facilitar el cierre del bucle una vez se ha extraído el último dato del archivo (el último número, la última palabra, la última línea, etc.) se utiliza un parámetro booleano conocido por sus siglas en inglés, EOF (End Of File), al que se le llama simplemente Final de archivo o Finarchivo.
//Se define c como Int  ya que la funcion regresa un valor numerico entero correspondiente al caracter y asi permitir el caracter especial EOF.

//Considerar el siguiente programa:
//#include <stdio.h>

//void main(){
//	int c;
//	c = getchar();
//	while(c !=EOF){
//		putchar(c);
//		c = getchar();
//	}
//}

//2)Modifica main para que solo llame una vez a la funcion getchar()

#include <stdio.h>
void main(){
	int c;
	while( c != EOF){
		c = getchar();
		putchar(c);
	}
}





