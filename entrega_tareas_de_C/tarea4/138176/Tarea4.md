---
title: "Tarea 4"
author: "Daniel Sharp"
date: "March 7, 2018"
output: 
  html_document:
    keep_md: true
---
## Ejercicio 1:  

### a) Modifica la función longitud_string del siguiente programa siguiendo estos dos pasos:  
Los cambios solicitados se encuentran especificados dentro del código:  


```bash
cat ejercicio_1a.c
```

```
## // Daniel Sharp Conkling
## // 138176
## 
## #include<stdio.h>
## #include<string.h>
## #define MAX_LONG 200
## #define CADENA_PRUEBA "Hola a todos"
## 
## // Paso 1: Versión de la función actualizada
## int longitud_string(char *s){
##     int i;
##     i=0;
##     while(*s != '\0'){
##         i++;
## /*Paso 2: Recorrer string con apuntador, escribir s++ dentro del while y
## escribir una condición para detener el loop. Mantenemos el índice*/
##         s++;
##       }
## return i;
## }
## 
## int main(void){
##     char string1[] = CADENA_PRUEBA; //definición y declaracion de variable e inicializacion.
##     char string2[MAX_LONG]; //definición y declaracion.
##     printf("cadena: %s\n", string1);
##     printf("longitud cadena: %d\n", longitud_string(string1));
##     strcpy(string2, "leer libros y revistas"); //inicializacion de string2
##     printf("cadena2: %s\n", string2);
##     printf("longitud cadena: %d\n", longitud_string(string2));
## return 0;
## }
```
Resultado:

```bash
gcc ejercicio_1a.c
./a.out
```

```
## cadena: Hola a todos
## longitud cadena: 12
## cadena2: leer libros y revistas
## longitud cadena: 22
```
### b) Investiga el uso de la función scanf para que imprima la longitud de los strings del archivo.txt:

```bash
cat ejercicio_1b.c
```

```
## // Daniel Sharp Conkling
## // 138176
## 
## #include<stdio.h>
## #include<string.h>
## 
## int longitud_string(char *s){
##     int i;
##     i=0;
##     while(*s != '\0'){
##         i++;
##         s++;
##       }
## return i;
## }
## 
## int main() {
##   char valor[50];
##   int c;
##   do{
##     scanf("%s",valor); // se implementa la funcion scanf para leeer el input (archivo.txt)
##     printf("longitud %s: %d\n",valor, longitud_string(valor));
##   }while((c=getchar()) != 10);
## 
##   return 0;
## }
```
Resultado:  

```bash
gcc ejercicio_1b.c
./a.out < archivo.txt
```

```
## longitud hamburguesas: 12
## longitud permisos: 8
## longitud exponencialmente: 16
## longitud 549: 3
```

## Ejercicio 2  

### a) Modifica el programa para que imprima sólo aquellas líneas que tienen más de 80 caracteres.  

```bash
cat ejercicio_2a.c
```

```
## // Daniel Sharp 138176
## // Ejercicio 2A
## #include<stdio.h>
## #define MAXLINEA 1000 /*máximo tamaño de una línea*/
## /*definición de variables externas*/
## int max;
## char linea[MAXLINEA];
## char linea_max[MAXLINEA];
## 
## /*Prototipo de funciones:*/
## 
## int obtenlinea(void);
## void copia(void);
## 
## /*imprime las líneas con más de 80 caracteres*/
## int main(void){
##     int longitud;
##     extern int max;
##     extern char linea_max[MAXLINEA];
##     max=0;
##     while((longitud = obtenlinea()) > 0){
##       // Condición que evalúa si la línea tiene más de 80 caracteres
##       if(longitud > 80){
##             copia();
##             printf("%s", linea_max);
##           }
##         }
## return 0;
## }
## 
## /*obtenlinea: lee una linea en el arreglo linea, regresa longitud*/
## int obtenlinea(void){
##     int c;
##     int i;
##     extern char linea[];
##     for(i=0; i < MAXLINEA-1 && (c=getchar())!=EOF && c!= '\n'; i++)
##         linea[i] = c;
##     if(c == '\n'){
##         linea[i] = c;
##         i++;
##     }
##     linea[i]='\0'; //este caracter es necesario para almacenar strings
##     return i;
## }
## 
## /*copia: copia del arreglo "linea" al arreglo "linea_max"*/
## void copia(void){
##     int i;
##     extern char linea[], linea_max[];
##     i=0;
##     while(1){
##         linea_max[i] = linea[i];
##         if(linea_max[i] == '\0') break;
##         i++;
##     }
## }
```
Resultado:  

```bash
gcc ejercicio_2a.c
./a.out < archivo2.txt
```

```
## the role. The ministers, afraid of losing their splendid position at court, give the
## courage and self-sacrifice. The six ministers are convinced that Stach will fall
```
Hay dos líneas con más de 80 caracteres.  

### b) Modifica el programa para que quite los espacios de cada línea leída.

```bash
cat ejercicio_2b.c
```

```
## // Daniel Sharp 138176
## // ejercicio 2B
## 
## #include<stdio.h>
## #define MAXLINEA 1000 /*máximo tamaño de una línea*/
## /*definición de variables externas*/
## int max;
## char linea[MAXLINEA];
## char linea_max[MAXLINEA];
## 
## /*Prototipo de funciones:*/
## 
## int obtenlinea(void);
## void copia(void);
## 
## /*imprime la línea con tamaño más grande*/
## int main(void){
##     int longitud;
##     extern int max;
##     extern char linea_max[MAXLINEA];
##     max=0;
##     // imprime todas las lineas independientemente de su longitud
##     while((longitud = obtenlinea()) > 0){
##             copia();
##             printf("%s", linea_max);
##         }
## return 0;
## }
## 
## /*obtenlinea: lee una linea en el arreglo linea, regresa longitud*/
## int obtenlinea(void){
##     int c;
##     int i;
##     extern char linea[];
##     for(i=0; i < MAXLINEA-1 && (c=getchar())!=EOF && c!= '\n'; i++){
##       /* Evalúa si el caracter obtenido es diferente de espacio, si lo es,
##       agrega el caracter al vector línea. Si es igual a espacio, retrocede el
##       indice en uno*/
##         if(c!=' '){
##           linea[i] = c;
##         }else{
##           i--;
##         }
##       }
##     if(c == '\n'){
##         linea[i] = c;
##         i++;
##     }
##     linea[i]='\0'; //este caracter es necesario para almacenar strings
##     return i;
## }
## 
## /*copia: copia del arreglo "linea" al arreglo "linea_max"*/
## void copia(void){
##     int i;
##     extern char linea[], linea_max[];
##     i=0;
##     while(1){
##         linea_max[i] = linea[i];
##         if(linea_max[i] == '\0') break;
##         i++;
##     }
## }
```
Resultado:  

```bash
gcc ejercicio_2b.c
./a.out < archivo2.txt
```

```
## ThemerryoldkingofKatorenhasdied
## andthere’snoheirtothethrone.Sixsourministersruletheland
## andclaimthatthey’relookingforanewking,
## butnothinghappens–forseventeenyears.
## Thensuddenlythere’saboystandingatthedooroftheroyal
## palacewhowasbornonthenightthekingdied.
## 
## Thisboy,Stach,hasfirmlyresolvedtobecomethenewkingofKatorenand
## heasksthesixministerswhathemustdoinordertobeconsideredfor
## therole.Theministers,afraidoflosingtheirsplendidpositionatcourt,givethe
## boysevenalmostimpossibletasks,whichcanbebroughttoasuccessful
## conclusiononlybyonewhopossesseskinglyattributessuchaswisdom,
## courageandself-sacrifice.ThesixministersareconvincedthatStachwillfall
## atthefirsthurdle,butheturnsouttohaveanamazingamountof
## persistenceandingenuity.
```

### c) Modifica la función copia para que no use break pero todavía debe de usar el índice i.

```bash
cat ejercicio_2c.c
```

```
## // Daniel Sharp 138176
## // Ejercicio 2C
## 
## #include<stdio.h>
## #define MAXLINEA 1000 /*máximo tamaño de una línea*/
## /*definición de variables externas*/
## int max;
## char linea[MAXLINEA];
## char linea_max[MAXLINEA];
## 
## /*Prototipo de funciones:*/
## 
## int obtenlinea(void);
## void copia(void);
## 
## /*imprime la línea con tamaño más grande*/
## int main(void){
##     int longitud;
##     extern int max;
##     extern char linea_max[MAXLINEA];
##     max=0;
##     while((longitud = obtenlinea()) > 0)
##         if( longitud > max){
##             max = longitud;
##             copia();
##         }
##     if(max > 0)
##         printf("%s", linea_max);
## return 0;
## }
## 
## /*obtenlinea: lee una linea en el arreglo linea, regresa longitud*/
## int obtenlinea(void){
##     int c;
##     int i;
##     extern char linea[];
##     for(i=0; i < MAXLINEA-1 && (c=getchar())!=EOF && c!= '\n'; i++)
##         linea[i] = c;
##     if(c == '\n'){
##         linea[i] = c;
##         i++;
##     }
##     linea[i]='\0'; //este caracter es necesario para almacenar strings
##     return i;
## }
## 
## /*copia: copia del arreglo "linea" al arreglo "linea_max"*/
## void copia(void){
##     int i,stop;
##     extern char linea[], linea_max[];
##     i=0;
##     stop=0; // Se inicializa una variable stop que tomará el valor de cero
##     while(stop==0){
##         linea_max[i] = linea[i];
##         if(linea_max[i] == '\0') stop=1; // La variable stop mantiene el valor de cero hasta que se encuentra el signo \0 en el string. En este momento se cambia su valor a uno, y cuando se evalúa en el while se nega la condición y se detiene el ciclo.
##         i++;
##     }
## }
```
Resultado:  

```bash
gcc ejercicio_2c.c
./a.out < archivo2.txt
```

```
## the role. The ministers, afraid of losing their splendid position at court, give the
```

### d) Modifica la función copia para que no use índices y sólo apuntadores.

```bash
cat ejercicio_2d.c
```

```
## // Daniel Sharp 138176
## // Ejercicio 2D
## 
## #include<stdio.h>
## #define MAXLINEA 1000 /*máximo tamaño de una línea*/
## /*definición de variables externas*/
## int max;
## char linea[MAXLINEA];
## char linea_max[MAXLINEA];
## 
## /*Prototipo de funciones:*/
## 
## int obtenlinea(void);
## void copia(void);
## 
## /*imprime la línea con tamaño más grande*/
## int main(void){
##     int longitud;
##     extern int max;
##     extern char linea_max[MAXLINEA];
##     max=0;
##     while((longitud = obtenlinea()) > 0)
##         if( longitud > max){
##             max = longitud;
##             copia();
##         }
##     if(max > 0)
##         printf("%s", linea_max);
## return 0;
## }
## 
## /*obtenlinea: lee una linea en el arreglo linea, regresa longitud*/
## int obtenlinea(void){
##     int c;
##     int i;
##     extern char linea[];
##     for(i=0; i < MAXLINEA-1 && (c=getchar())!=EOF && c!= '\n'; i++)
##         linea[i] = c;
##     if(c == '\n'){
##         linea[i] = c;
##         i++;
##     }
##     linea[i]='\0'; //este caracter es necesario para almacenar strings
##     return i;
## }
## 
## /*copia: copia del arreglo "linea" al arreglo "linea_max"*/
## void copia(void){
##     extern char linea[], linea_max[];
##     // declaramos los apuntadores para cada arrelo
##     char *lm, *l;
##     // Asignamos la direccion de memoria del primer elemento de cada arreglo a los apuntadores
##     lm = &linea_max[0];
##     l = &linea[0];
##     while(1){
##         *lm = *l;
##         if(*lm == '\0') break;
## 	// se itera sobre los apuntadores para no utilizar índices
##         lm++;
##         l++;
##     }
## }
```
Resultado:  

```bash
gcc ejercicio_2d.c
./a.out < archivo2.txt
```

```
## the role. The ministers, afraid of losing their splendid position at court, give the
```
### e) Escribe una función voltea que reciba un string s e imprima el string s al revés. Añade esta función para que el programa lea líneas y las imprima volteadas.

```bash
cat ejercicio_2e.c
```

```
## // Daniel Sharp 138176
## // ejercicio 2E
## 
## #include<stdio.h>
## #define MAXLINEA 1000 /*máximo tamaño de una línea*/
## /*definición de variables externas*/
## int max;
## char linea[MAXLINEA];
## char linea_max[MAXLINEA];
## 
## /*Prototipo de funciones:*/
## 
## int obtenlinea(void);
## void copia(void);
## void voltea(char s[]);
## 
## /*imprime la línea con tamaño más grande*/
## int main(void){
##     int longitud;
##     extern int max;
##     extern char linea_max[MAXLINEA];
##     max=0;
##     // imprime todas las lineas independientemente de su longitud
##     while((longitud = obtenlinea()) > 0){
##             copia();
##             //printf("%s", linea_max);
##             voltea(linea_max);
##         }
## return 0;
## }
## 
## /*obtenlinea: lee una linea en el arreglo linea, regresa longitud*/
## int obtenlinea(void){
##     int c;
##     int i;
##     extern char linea[];
##     for(i=0; i < MAXLINEA-1 && (c=getchar())!=EOF && c!= '\n'; i++)
##         linea[i] = c;
##     if(c == '\n'){
##         linea[i] = c;
##         i++;
##     }
##     linea[i]='\0'; //este caracter es necesario para almacenar strings
##     return i;
## }
## 
## /*copia: copia del arreglo "linea" al arreglo "linea_max"*/
## void copia(void){
##     int i;
##     extern char linea[], linea_max[];
##     i=0;
##     while(1){
##         linea_max[i] = linea[i];
##         if(linea_max[i] == '\0') break;
##         i++;
##     }
## }
## /*voltea: invierte el orden de los caracteres en un string*/
## void voltea(char s[]){
##   int count = 0;
##   while(s[count] != '\0'){
##     count++;
##   }
##   char res[count];
## 
##   for(int i=0; i<=count; i++){
##     // restamos uno a count para que no considere el \0
##     res[i] = s[count-1-i];
##   }
##   res[count] = '\0';
##   printf("%s", res);
## }
```
Resultado:  
En este inciso se eliminan los caracteres especiales (guiones y apóstrofes) del texto porque provocaban problemas de encoding:  

```bash
gcc ejercicio_2e.c
cat archivo2.txt | tr -dc '[:alnum:]\n\r ' | ./a.out
```

```
## 
## deid sah nerotaK fo gnik dlo yrrem ehT
## dnal eht elur sretsinim ruos xiS enorht eht ot rieh on sereht dna
## gnik wen a rof gnikool eryeht taht mialc dna
##  sraey neetneves rof  sneppah gnihton tub
## layor eht fo rood eht ta gnidnats yob a sereht ylneddus nehT
## deid gnik eht thgin eht no nrob saw ohw ecalap
## 
## dna nerotaK fo gnik wen eht emoceb ot devloser ylmrif sah hcatS yob sihT
##  rof deredisnoc eb ot redro ni od tsum eh tahw sretsinim xis eht sksa eh
## eht evig truoc ta noitisop didnelps rieht gnisol fo diarfa sretsinim ehT elor eht
## lufsseccus a ot thguorb eb nac hcihw sksat elbissopmi tsomla neves yob
## modsiw sa hcus setubirtta ylgnik sessessop ohw eno yb ylno noisulcnoc
## llaf lliw hcatS taht decnivnoc era sretsinim xis ehT ecifircasfles dna egaruoc
## fo tnuoma gnizama na evah ot tuo snrut eh tub eldruh tsrif eht ta
## ytiunegni dna ecnetsisrep
```

### f) Qué efecto tiene escribir extern para la declaración de variables dentro de main(), getline() y copia()?  

El uso de extern tiene el objetivo de especiicar al programa que la variable que se esta declarando dentro del main, getline o copia es una variable global preexistente. Sin el extern, se inicializa una variable local que 'rompe' el programa pues no tiene un valor asignado. El extern permite que una variable definida de manera global pueda ser modificada y utilizada por muchas funciones sin que sea necesario que estas la reciban como un argumento. Además, al usar extern no le asigna memoria a la variable.  

## Ejercicio 3  

### a) La funcion corta_string no hace un chequeo si el string que recibe como parámetro debe de tener al menos un caracter. Modifica esta función de modo que haga este chequeo:  
Se modificó el código para poder evaluar fácilmente si funciona correctamente nuestro chequeo. El string que evalúa es el primer argumento que recibe en la línea de comando


```bash
cat ejercicio_3a.c
```

```
## //Daniel Sharp 138176
## // Ejercicio 3A
## 
## #include<stdio.h>
## #include<string.h> // agregamos string.h para utilizar strlen
## char *corta_string(char *apuntador){
##   // Definimos mensaje de error en un apuntador
##   char *err = "Error: ingresar string con longitud mayor a 1";
##   // verificamos si string es mayor a 1, si es, eliminamos primer caracter
##   if(strlen(apuntador) > 1){
##     apuntador=apuntador+1;
##     // si no lo es, regresamos mensaje de error
##   }else{
##     apuntador = err;
##   }
##   return apuntador;
## }
## 
## int main(int argc, char *argv[]){
##     char *s=argv[1]; // Recibe el string a través de la línea de comando
##     s=corta_string(s);
##     printf("%s\n",s);
## 
## return 0;
## }
```
Resultado:  
Se corre el ejemplo original:  

```bash
gcc ejercicio_3a.c
./a.out "Campos verdes" #Indicamos un string con más de 1 caracter
```

```
## ampos verdes
```
Y observamos que efectivamente remueve el primer caracter. Ahora lo probamos con un solo caracter.  

```bash
./a.out C
```

```
## Error: ingresar string con longitud mayor a 1
```
Efectivamente imprime correctamente el mensaje de error.  

### b) Cómo modificas la forma en que es llamada corta_string dentro de main de modo que devuelva: verdes ?? (hay un espacio antes del string "verdes").    


```bash
cat ejercicio_3b.c
```

```
## //Daniel Sharp 138176
## // Ejercicio 3B
## 
## #include<stdio.h>
## char *corta_string(char *apuntador){
##     apuntador=apuntador+1;
##     return apuntador;
## }
## 
## int main(void){
##     char *s="Campos verdes";
##     // Aplicamos la función de corta string hasta que el último valor cortado sea un espacio
##     while(s[-1] != ' ')
##       s=corta_string(s);
##     printf("%s\n",s);
## 
## return 0;
## }
```
Resultado:  

```bash
gcc ejercicio_3b.c
./a.out
```

```
## verdes
```

## Ejercicio 4  

### a) Modifica el programa para que en lugar de inicializar el string s con un tamaño 50 sea dinámica su inicialización, es decir, que no tengas que escribir 50 o algún valor definido para el tamaño del string s.


```bash
cat ejercicio_4a.c
```

```
## // Daniel Sharp 138176
## // Ejercicio 4A
## 
## #include<stdio.h>
## #include<stdlib.h>
## #include<string.h>
## char *duplica_string(char *s){
##     char *p;
##     p = malloc(strlen(s)+1); /* sumamos uno para almacenar el caracter '\0'*/
##         if(p!=NULL)
##         strcpy(p,s);
##     return p;
## }
## int main(void){
##     char *s = "Campos verdes";
##     // Asignamos el espacio de memoria para el string. Dado que sizeof(char)=1 no es necesario incluirlo en la función
##     char *str =(char *) malloc(strlen(s)+1);
##     //copiamos el string a la variable str
##     strcpy(str, s);
##     char *s_duplicado;
##     s_duplicado = duplica_string(str);
##     printf("%s\n", s_duplicado);
##     free(s_duplicado);
##     free(str);
##     return 0;
## }
```
Resultado:  


```bash
gcc ejercicio_4a.c
./a.out
```

```
## Campos verdes
```
### b) Escribe una función voltea_string que reciba como parámetro un char\*  y devuelva un char\*  cuya operación sea devolver un string volteado


```bash
cat ejercicio_4b.c
```

```
## // Daniel Sharp 138176
## // Ejercicio 4B
## 
## #include<stdio.h>
## #include<stdlib.h>
## #include<string.h>
## char *duplica_string(char *s){
##     char *p;
##     p = malloc(strlen(s)+1); /* sumamos uno para almacenar el caracter '\0'*/
##         if(p!=NULL)
##         strcpy(p,s);
##     return p;
## }
## 
## char *voltea_string(char *s);
## 
## 
## int main(void){
##     char s[50] = "Campos verdes";
##     char *s_duplicado, *s_volteado;
##     s_duplicado = duplica_string(s);
##     printf("%s\n", s_duplicado);
##     free(s_duplicado);
##     s_volteado = voltea_string(s);
##     printf("%s\n", s_volteado);
##     free(s_volteado);
##     return 0;
## }
## 
## char *voltea_string(char *s){
##   // definimos la variable de respuesta utilizando y le alojamos espacio con malloc
##   char *volteado;
##   volteado = malloc(strlen(s)+1);
##   if(volteado != NULL){
##     int size = strlen(s);
##     /* creamos variable temporal para hacer las operaciones de invertir el string
##     pues las variables alojadas con malloc no permten recibir valores individuales,
##     es decir, volteado[i] = s[i]*/
##     char temp[size+1];
##     int i=0;
##     while(i<size){
##       temp[i] = s[size-1-i];
##       i++;
##     }
##   temp[i+1] = '\0';
##   // Copiamos el string temporal a la variable de volteado
##   strcpy(volteado, temp);
##   }
##   return volteado;
## }
```
Resultado:  


```bash
gcc ejercicio_4b.c
./a.out
```

```
## Campos verdes
## sedrev sopmaC
```

