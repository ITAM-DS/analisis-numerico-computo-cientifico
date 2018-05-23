#include <stdio.h>

// Hector Adolfo Corro Zarate    114350

// 1.- EOF (End Of File)es un parámetro booleano útil para facilitar el cierre de bucles de extracción de datos desde archivo. En C,EOF es una constante de tipo entero (normalmente  -1) que es el retorno que envían distintas funciones de extracción de información desde archivos al llegar a un final de archivo y no existir más datos. También se puede “simular” EOF mediante una entrada de teclado, normalmente CTRL+Z y enter ó CTRL+D y enter según el sistema operativo que se emplee.



main(void){

// 2.-
	//int c;
	//while( c = getchar()){
		//putchar(c);
		//printf("algo");
	//} 

// 3.-
	//int palabra;
	//int chars = 0;
	//printf("Agrega una oracion : \n");
	//while((palabra = getchar()) != EOF && palabra != '\n'){
		//++ chars;
	//} 
	//printf("Caracteres totales: \n");
	//printf("%d", chars);

// 4.-


	FILE *fp;
	 char filename[100];
	 char ch;
	 int linecount, charcount;	 
	 linecount = 0;
	 charcount = 0;

	 
	  printf("Mete nombre del archivo :");  // especificar la extension del .txt
	  gets(filename);
	  
	    // Open file in read-only mode
	   fp = fopen(filename,"r");

	   // If file opened successfully, then write the string to file
	   if ( fp )
	   {
		//Repeat until End Of File character is reached.	
		   while ((ch=getc(fp)) != EOF) {
		   	  
			   // Increment character count if NOT new line or space
		    	   if (ch != ' ' && ch != '\n') { ++charcount; }
			  // Increment line count if new line character
			   if (ch == '\n') { ++linecount; }

		   }

		   if (charcount > 0) {
			++linecount;			
		   }
	    }
	   else
	      {
		 printf("No se abre el archivo\n");
		}

	    printf("Lineas : %d \n", linecount);
	    printf("Caracteres : %d \n", charcount);

	getchar();
	return(0);

}
