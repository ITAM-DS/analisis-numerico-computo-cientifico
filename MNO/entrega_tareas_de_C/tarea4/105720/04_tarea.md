
# Tarea 4

---

**CU:** 105720

**Nombre:** Sonia Mendizábal Claustro

---

## Ejercicio 1

#### a) Modifica la función `longitud_string` del siguiente programa siguiendo estos dos pasos:

- paso1: Un primer cambio es: `longitud_string(char *s){ //código ...}`

- paso2: Recorrer el string con un apuntador. Dentro del while escribe el statement: `s=s+1;`

- Escribe una condición en el while para detener el loop. Sigue usando un índice para return.


#### b) Investiga el uso de la función `scanf` para que imprima la longitud de los strings del archivo.txt:

La función `scanf` lee datos 
de una fuente específica o stdin, como un archivo txt, y los almacena 
de acuerdo al parámetro format en lugares distintos. 
Se define `scanf(const char *format, ...)`.

En el archivo `04_tarea_ej1.c` se encuentra la función con los cambios necesarios. 
Se obtienen los siguientes resultados.

```
$04_tarea_ej1.c -o ejercicio_1_scanf.out 
$./ejercicio_1_scanf.out < 04_archivo_ej1.txt
Longitud hamburguesas : 12
Longitud permisos : 8
Longitud exponencialmente : 16
Longitud 549 : 3
```







---

##Ejercicio 2:

El siguiente programa lee un conjunto de líneas del archivo `archivo.txt` e imprime la línea más larga:


#### a) Modifica el programa para que imprima sólo aquellas líneas que tienen más de 80 caracteres.

El código de esta pregunta se encuentra en `04_tarea_ej2a.c`.
En la función main se agrega la siguiente condición.
```
if( longitud > 80)
            printf("%s", linea_max);
```

El resultado obtenido es
```
$gcc 04_tarea_ej2_a.c -o 04_tarea_ej2_a.out 
$./04_tarea_ej2_a.out < 04_archivo_ej2.txt
the role. The ministers, afraid of losing their splendid position at court, give the

courage and self-sacrifice. The six ministers are convinced that Stach will fall

Línea con máxima longitud: the role. The ministers, afraid of losing their splendid position at court, give the
```


#### b) Modifica el programa para que quite los espacios de cada línea leída.

El código de esta pregunta se encuentra en `04_tarea_ej2b.c`. 
En la función `obtenlinea` se agrega la siguiente condición
con la definicion `# include <ctype.h>`:
```
if (!isspace(c))
            linea[i] = c;   
```
El resultado obtenido es: 
```
$gcc 04_tarea_ej2_b.c -o 04_tarea_ej2_b.out 
$./04_tarea_ej2_b.out < 04_archivo_ej2.txt
Línea con máxima longitud: therole.Theministers,afraidoflosingtheirsplendidpositionatcourt,givethe
```





#### c) Modifica la función `copia` para que no use `break` pero todavía debe de usar el índice `i`.

El código de esta pregunta se encuentra en `04_tarea_ej2c.c`. 
En la función `copia` se modifica la condición dentro de while para continuar la 
función:
```
// c) While sin usar break
while( linea[i] != '\0' ){
    linea_max[i] = linea[i];
    i++;    
}
```
El resultado obtenido es el mismo que los incisos anteriores
```
$gcc 04_tarea_ej2_c.c -o 04_tarea_ej2_c.out 
$./04_tarea_ej2_c.out < 04_archivo_ej2.txt
Línea con máxima longitud: the role. The ministers, afraid of losing their splendid position at court, give the
```


#### d) Modifica la función `copia` para que no use índices y sólo apuntadores.


El código del programa de esta pregunta se encuentra en `04_tarea_ej2_d.c`. 
Para este inciso se modifica dentro de la función `copia` 
la condición dentro de while
del inciso **c)**. Se agregan apuntadores para
los arreglos `linea` y `linea_max`: 
```
while( *(linea + i) != '\0' ){
  *(linea_max + i) = *(linea + i);
  i++;    
  }
```
El resultado obtenido es el mismo que los incisos anteriores
```
$gcc 04_tarea_ej2_d.c -o 04_tarea_ej2_d.out 
$./04_tarea_ej2_d.out < 04_archivo_ej2.txt
Línea con máxima longitud: the role. The ministers, afraid of losing their splendid position at court, give the
```



#### e) Escribe una función `voltea` que reciba un string `s` e imprima el string `s` al revés. Añade esta función para que el programa lea líneas y las imprima volteadas.

El programa de este inciso se encuentra en el código `04_tarea_ej2_e.c`.
La función voltea se presenta a continuación. 
```
/*voltea: invierte el arreglo "linea"*/
void voltea(void){
    extern char linea[];
    int l = strlen(linea), k;
    char rev[l + 1];
    
    for(k = 0; k < l ; k++){
        //printf("k %d \n", k);
        rev[l - k - 1] = linea[k];
      }
    rev[k]='\0' ;
    printf("%s", rev);
}
```
Esta función se manda llamar dentro de la función  `obtenlinea`
después de leer cada línea. 
El resultado obtenido es:
```
$gcc 04_tarea_ej2_e.c -o 04_tarea_ej2_e.out 
$./04_tarea_ej2_e.out < 04_archivo_ej2.txt
deid sah nerotaK fo gnik dlo yrrem ehT
dnal eht elur sretsinim ruos xiS .enorht eht ot rieh on sereht dna
,gnik wen a rof gnikool eryeht taht mialc dna
 .sraey neetneves rof sneppah gnihton tub
layor eht fo rood eht ta gnidnats yob a sereht ylneddus nehT
.deid gnik eht thgin eht no nrob saw ohw ecalap

dna nerotaK fo gnik wen eht emoceb ot devloser ylmrif sah ,hcatS ,yob sihT
 rof deredisnoc eb ot redro ni od tsum eh tahw sretsinim xis eht sksa eh
eht evig ,truoc ta noitisop didnelps rieht gnisol fo diarfa ,sretsinim ehT .elor eht
lufsseccus a ot thguorb eb nac hcihw ,sksat elbissopmi tsomla neves yob
,modsiw sa hcus setubirtta ylgnik sessessop ohw eno yb ylno noisulcnoc
llaf lliw hcatS taht decnivnoc era sretsinim xis ehT .ecifircas-fles dna egaruoc
fo tnuoma gnizama na evah ot tuo snrut eh tub ,eldruh tsrif eht ta
```



#### f) Qué efecto tiene escribir `extern` para la declaración de variables dentro de main(), getline() y copia()?

Mantiene la variable global, por lo tanto, cualquier 
cambio realizado en cualquier función se actualiza para las siguientes. 
Permite modificar la variable sin tener que 
modificar 





---


## Ejercicio 3

El siguiente programa `corta_string` 
elimina el primer caracter de un string:

#### a) La funcion `corta_string` no hace un chequeo si el string que recibe como parámetro debe de tener al menos un caracter. Modifica esta función de modo que haga este chequeo:

Para esta revisión una froma es usar la longitud 
del apuntador. Si la longitud es mayor a cero, extrae el 
primer elemento. De lo contrario error. El cambio 
en la función se presenta a continuación. 
```
l = strlen(apuntador);
if(l > 0){
    apuntador = apuntador+1;
    return apuntador;
}else{
    printf("Longitud %d: \n", l);
    return "ERROR";
}  
```
El resultado obtenido para `s = "Campos Verdes"`:
```
$gcc 04_tarea_ej3_a.c -o 04_tarea_ej3_a.out
$./04_tarea_ej3_a.out 
ampos verdes
```
El resultado obtenido para `s = ""`:
```
$gcc 04_tarea_ej3_a.c -o 04_tarea_ej3_a.out
$./04_tarea_ej3_a.out 
Longitud 0
ERROR
```

#### b) ¿Cómo modificas la forma en que es llamada `corta_string` dentro de main de modo que devuelva: `verdes`? (hay un espacio antes del string "verdes").


Una forma en que se modifica es agregando un while
en el que se corte el primer valor de la cadena hasta
que el primer elemento del string sea un espacion en blanco:
```
while( !isspace(s[0]) ){ 
    s = corta_string(s);
}
```

El código del programa se encuentra en `04_tarea_ej3_b.c`.
El resultado obtenido es:
```
$gcc 04_tarea_ej3_b.c -o 04_tarea_ej3_b.out
$./04_tarea_ej3_b.out 
 verdes
```






---

## Ejercicio 4


Utiliza `malloc`.


#### a) Modifica el programa para que en lugar de inicializar el string `s` con un tamaño `50` sea dinámica su inicialización, es decir, que no tengas que escribir `50` o algún valor definido para el tamaño del string `s`. 



El código de este inciso está en `04_tarea_ej4_a.c`. 
La función `main` se modifica en la declaración de la 
variable, se cambia por:
```
char *s = malloc( sizeof(char) * sizeof("Campos verdes")) ;
```
El resultado obtenido es
```
$gcc 04_tarea_ej4_4.c -o 04_tarea_ej4_a.out
$./04_tarea_ej4_a.out 
Campos verdes
```


#### b) Escribe una función `voltea_string` que reciba como parámetro un `char *` y devuelva un `char *` cuya operación sea devolver un string volteado, así, al llamar `voltea_string` con el string `Campos verdes` tenemos: `sedrev sopmaC`.

El código del programa se encuentra en el archivo 
`04_tarea_ej4_b.c`. La función `voltea_string` creada es la 
siguiente:
```
char * voltea_string(char *s){
    char *sinv = malloc( sizeof(s) );    
    int l = strlen(s), k;
    
    for(k = 0; k < l ; k++){
        //printf("k %d \n", k);
        *(sinv + l - k - 1) = *(s + k);
      }
    *(sinv + k) ='\0' ;
    
    return sinv;
}
```
Esta función se llama en la función `main` y 
se obtiene el siguiente resultado:
```
$gcc 04_tarea_ej4_b.c -o 04_tarea_ej4_b.out
$./04_tarea_ej4_b.out 
Campos verdes
sedrev sopmaC
```
