

// Librerias necesarias
#include <stdio.h>
#include <stdlib.h>


// argc es un entero con el número de argumentos, minimo 1 pues el nombre del programa es el primer argumento siempre.
// *argv[] es un vector de strings que recive todas las variables de la terminal aen stdin
// al usar el operador <, se leera en stdin todo lo contenido en el archivo de texto
int main(int argc, char *argv[]){

// se inicializa un char para revisar caracter por caracter, y dos enteros
// m : el numero de caracteres diferentes de \n
// n : el numero de \n o lineas en el texto	
 int c, m=0, n=0;
   
// para guardar los caracteres y los  \n
    char stringm[5000];
    char stringn[5000];
    
// el loop continua hasta que se encuentre con EOF (que es end of file o el fin del la cadena de caracteres)   
    // getchar() es capas de leer del stdin de la terminal, por lo que al pasar ./ejecutable.out < archivo.txt, se encarga de leer
    // todo lo contenido en el texto como una cadena de caracteres, pues "<" convierte su contenido en input que recive *argv[] 
    //y revisa uno por uno hasta que encuentra el EOF.
   
    while( (c = getchar()) != EOF){
  // incrementa m cuando ve un caracter diferende de \n      
        if(c != '\n'){
        stringm[m]=c;
        ++m;   
    	}else if(c == '\n'){ //incrementa cuando ve un \n
        stringn[n]=c;
        ++n;   
    	}

    } 

    printf("\nEl numero de caracteres es : %d \n",m);

    printf("El numero de lineas es : %d \n ",n);
}