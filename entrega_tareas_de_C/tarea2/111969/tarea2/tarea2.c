#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Ejercicio 1:

/*EOF significa ENDO OF FILE, su valor es -1,
 dado que getchar() produce valores enteros, tenemos que poner a c como tal de lo contrario no podríamos redefinir la variable.  */


// Ejercicio 2-3:
 int fun_2(void){
    char c;
    char d;
    char e;
    int i =0;
    printf("ingresa un valor: \n");
    while(c != '\n' && c != EOF){
        c = getchar();
        ++i; 
    }
    printf("%d \n",i-1); 
}
//Ejercicio 4:
 int fun_3(char *filename){
    char c;
    char d;
    char e;
    int lines = 0;
    FILE *fp = fopen(filename,"r");
     if (fp == NULL){printf("NULL");}
    while( c != EOF){//!feof(fp)){
        c = fgetc(fp);
        if(c =='\n'){
            ++lines; 
        }
        
    }
    printf("%d \n",lines); 
}

main(void){

fun_2();
printf("el numero de lineas en el archivo es de: \n");
fun_3("test.txt");


}






