#include<stdio.h>
#define MAXLINEA 1000

int limite = 80;
char linea[MAXLINEA];
char linea_max[MAXLINEA];

int obtenlinea(void); 
void copia(void);
 
int main(void){
    int longitud;
    while((longitud = obtenlinea()) > 0)
        if( longitud >= limite)
            printf("%s", linea);
return 0;
}
 
int obtenlinea(void){
    int c;
    int i;
    extern char linea[];
    for(i=0; i < MAXLINEA-1 && (c=getchar())!=EOF && c!= '\n'; i++)
        linea[i] = c;
    if(c == '\n'){
        linea[i] = c;
        i++;
    }
    linea[i]='\0';
    return i;
}

void copia(void){ 
    int i;
    extern char linea[], linea_max[];
    i=0;
    while(1){
        linea_max[i] = linea[i];
        if(linea_max[i] == '\0') break;
        i++;    
    }
}