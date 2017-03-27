#include<stdio.h>
#define MAXLINEA 1000 /*máximo tamaño de una línea*/
/*definición de variables externas*/
int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA];

/*Prototipo de funciones:*/

int obtenlinea(void); 
void copia(void);

char *voltea_string(char *s){
    char *ptr;
    int n=strlen(s),i;
    ptr = (char *)malloc(n+1);
    if(ptr!=NULL)
        for(i=n-1;i>=0;i--)
         *(  ptr+n-1-i)=*(s+i);
        ptr[n]='\0';
    
    return ptr;

}

/*imprime la línea con tamaño más grande*/
int main(void){
    int longitud;
    char *s;
    extern int max;
    extern char linea_max[MAXLINEA];
    max=0;
    while((longitud = obtenlinea()) > 0)
        if( longitud > 80){
            max = longitud;
            copia();
            s=voltea_string(linea_max);
            printf("%s",s );
        }
    
return 0;
}

/*obtenlinea: lee una linea en el arreglo linea, regresa longitud*/
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
    linea[i]='\0'; //este caracter es necesario para almacenar strings
    return i;
}

/*copia: copia del arreglo "linea" al arreglo "linea_max"*/
void copia(void){ 
    int i;
    char *ptrlinea =linea;
    char *ptrmax= linea_max;
    i=0;
    do{
            *(ptrmax+i) = *(ptrlinea+i);
        if(linea_max[i] == '\0') i=-1;
        i++;    
    }while(i);
}
