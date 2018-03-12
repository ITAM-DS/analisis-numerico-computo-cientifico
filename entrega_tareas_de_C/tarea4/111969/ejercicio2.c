#include <stdio.h>
#include<ctype.h>


#define MAXLINEA  1000000
#define FILENAME  "archivo.txt"

int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA];



int linecount( char *fn){

 int numlines = 0;
 char line[MAXLINEA];
 FILE *fp = fopen(fn, "r");
 if (fp !=0 ) {
    while (fgets (line , sizeof(line), fp ) != 0){
        numlines ++;
    }
    fclose(fp);
    printf("El archivo %s tiene %d lineas \n",fn,numlines);
    return numlines;

 }

}


int readlines(int n){
    FILE *fp = fopen(FILENAME, "r");
    int lengths[n];
    int numchar = 0;// inicializamos el contador de cracateres
    int i = 0; // este nos sirve para contrrolar el número de líneas
    int j = 0; // Nos sirve para controlar el array 
    int max =0;// con este controlaremos el máximo
    int lin_max = 0;
    char line[MAXLINEA];
    int numlines =0;
    // Ahora queremos leer cada línea y ver cuantos cracateres tiene
    char c,d;
    while (d = fgetc(fp) != EOF){
    while (c = fgetc(fp) != '\n'){
        numchar++;
    }
    i++;
    //printf(" el numero de caracteres de la linea %d es de %d \n",i,numchar);
    lengths[i]=numchar;
    numchar = 0;
    }
    for ( j = 0; j<n; j++){
        //printf("el array tiene en la posicion %d el valor %d \n",j,lengths[j]);
        if(lengths[j] >= max && j != 0){
            max = lengths[j];
            lin_max = j;
        }

    }
    
    fclose(fp);
    FILE *fp2 = fopen(FILENAME, "r");

    while (fgets (line , sizeof(line), fp2 ) != 0){
        
        if(numlines == lin_max){
               printf("la linea mas grande es: %d con %d caracteres : \n",lin_max,max);
               fputs(line,stdout);


        }
        numlines ++;
    }
    return 0;
 


        
   

}

int readlines2(int n){
    FILE *fp = fopen(FILENAME, "r");
    int lengths[n];
    int numchar = 0;// inicializamos el contador de cracateres
    int i = 0; // este nos sirve para contrrolar el número de líneas
    int j = 0; // Nos sirve para controlar el array 
    int max =0;// con este controlaremos el máximo
    int lin_max = 0;
    char line[MAXLINEA];
    int numlines =0;
    int q = 0;
    // Ahora queremos leer cada línea y ver cuantos cracateres tiene
    char c,d;
    while (d = fgetc(fp) != EOF){
    while (c = fgetc(fp) != '\n'){
        numchar++;
    }
    i++;
    //printf(" el numero de caracteres de la linea %d es de %d \n",i,numchar);
    lengths[i]=numchar;

    numchar = 0;
    
    }
    for ( j = 0; j<n; j++){
        //printf("el array tiene en la posicion %d el valor %d \n",j,lengths[j]);
        if(lengths[j] >= max && j != 0){
            max = lengths[j];
            lin_max = j;
        }

    }
    
    fclose(fp);
    FILE *fp2 = fopen(FILENAME, "r");

    while (fgets (line , sizeof(line), fp2 ) != 0){
        
        if(lengths[q] >= 80 && q != 0){
               
               fputs(line,stdout);


        }q++;
        
        
    }
    return 0;
 


        
   

}


// ahora hagamos una función que quite los espacios del string: 

int readlines_space(){
    FILE *fp = fopen(FILENAME, "r");
    char c,d;
    int i=0;
    int numchar=0;
    char line[MAXLINEA];
    int j = 0;

    
    while (fgets (line , sizeof(line), fp ) != 0 )
    {
        //printf("%s\n",line);
        for (i=0; line[i] != '\n'; i++)
        {
            if(isspace(line[i]))
            {
            line[i] = 0;
            i++;
            }
            printf("%c",line[i]);
            
            
        }
        
        
    } 
     return 0;      
    }
     

// Función para voltear un string:


char *reversa (char *str){
    char tmp, *src, *dst;
    size_t len;
   
        len = strlen(str);
        printf("size_y es %d\n",len);
        src = str;
        printf("src es : %x , con direccion %d \n", src, &src);
        printf("str es : %x , con direccion %d \n", str, &str);
        dst = src + len -1;// lo apuntamos al último valor del string así podemos usar el while hasta que sea menor estricto
      
        
        while (src < dst) 
        {
            tmp = *src;
            *src++ = *dst;
            *dst-- = tmp;
            
        }
 return str;
}



// corremos mis funciones: 
int main(void){

printf(" -------Programa base, imprime la linea más grande------ \n\n");
int n = linecount(FILENAME);
readlines(n);
printf(" \n\n");
printf(" -------Programa 2, imprime lineas mayores a 80------ \n\n");
readlines2(n);
printf(" \n\n");
printf(" -------Programa 3, Quita espacios------ \n\n");
readlines_space();
printf(" \n\n");
printf(" -------Programa 4, Voltea string  ------ \n\n");
char s[] = "hola";
printf("string original : %s\n", s);
printf ("%s\n", reversa(s));
printf(" \n\n");
printf(" -------Pregunta: para que sirve extern?  ------ \n\n");
printf(" poner extern al momento de declarar las variables, permite utilizarlas con otros archivos fuente de código externos al programa en el que fueron deifnidas");
printf(" \n\n");

}
