

#include<stdio.h>
#define MAXLINEA 1000 /*máximo tamaño de una línea*/
/*definición de variables externas*/
int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA];

/*Prototipo de funciones:*/

int obtenlinea(void); 
void copia(void);
void voltea(char* s);

/*imprime la línea con tamaño más grande*/
int main(void){
    int longitud;
    extern int max;
    extern char linea_max[MAXLINEA];
    max=0;
    while((longitud = obtenlinea()) > 0){
        
        
        if (longitud > 80)//a) mas de 80 caracteres
        {
            printf("%s\n", linea);
        
        // e)
            voltea(linea);
        }

        if( longitud > max){
            max = longitud;
            copia();
        }
    }
    if(max > 0){
        printf("%s", linea_max);
        voltea(linea_max);
    }
return 0;
}

/*obtenlinea: lee una linea en el arreglo linea, regresa longitud*/
int obtenlinea(void){
    int c;
    int i;
    extern char linea[];
    for(i=0; i < MAXLINEA-1 && (c=getchar())!=EOF && c!= '\n'; i++){
        
        if (c==' ')//b)
        {
            i--;
        }
        else{
            linea[i] = c;    
        }
    }
    
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
    extern char linea[], linea_max[];
    i=0;
      while(*(linea+i) != '\0'){ //c)
        *(linea_max+i) = *(linea+i); //d)
        i++;    
    }
}


void voltea(char *s){//e)
    int i, size;
    for (i = 0; (*(s+i))!='\0'; ++i)
    {   
    }
    size = i;
   
    for (i = size; i >= 0 ; --i)
    {
    printf("%c", *(s+i));
    }
}



//f) la palabra extern en las declaraciones de main, getline y copia le indican al compilador
//que la variable esta fuera del dominio de la función En nuestro caso podemos no incluir extern.




