// 1b. = Investiga el uso de la función "scanf" 
// para que imprima la longitud de los strings del archivo.txt:

///// GLOBAL /////////////////////////////////////////
#include<stdio.h>
#include<string.h>
#define MAX_LONG 200
int longitud_string(char *s);

/////////////////////////////////////////////////////////// 

int main(void){
    int c;
    char string[MAX_LONG];
    while(scanf("%s",string) && (c = getchar()) != EOF){
        printf("'%s' tiene longitud:%d\n", string,longitud_string(string));
    }
return 0;
}
///// FUNCIONES ///////////////////////////////////////////

int longitud_string(char *s){
    int i;
    i=0;
    
    while(*s != '\0'){
        i++;
        s=s+1; //strting es apuntador        
    }
return i;
}

////  RUN!!!   /////////////////////////////////////////////
//  ./4_1b.out < 4_1b.txt
//  ./4_1b.out < 4_1b_modif.txt