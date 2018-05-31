Tarea 4 - 114535

## Ejercicio 1:
### a)

```{r}
gcc -Wall ejercicio_1_a.C -o out
./out 
```

### b)
Investiga el uso de la función scanf para que imprima la longitud de los strings del archivo.txt:

 ```{r}
gcc -Wall ejercicio_1_b.C -o out
./out < archivo_a.txt
 ```

## Ejercicio 2:
### a) Modifica el programa para que imprima sólo aquellas líneas que tienen más de 80 caracteres.

 ```{r}
gcc -Wall ejercicio_2_a.C -o out
./out < archivo_a.txt
 ```

### b) Modifica el programa para que quite los espacios de cada línea leída.
 ```{r}
gcc -Wall ejercicio_2_b.C -o out
./out < archivo_a.txt
 ```

### c) Modifica la función copia para que no use break pero todavía debe de usar el índice i.
 ```{r}
gcc -Wall ejercicio_2_c.C -o out
./out < archivo_a.txt
 ```

### d) Modifica la función copia para que no use índices y sólo apuntadores.
 ```{r}
gcc -Wall ejercicio_2_d.C -o out
./out < archivo_a.txt
 ```

### e) Escribe una función voltea que reciba un string s e imprima el string s al revés. Añade esta función para que el programa lea líneas y las imprima volteadas.
 ```{r}
gcc -Wall ejercicio_2_e.C -o out
./out < archivo_a.txt
 ```

### f) Qué efecto tiene escribir extern para la declaración de variables dentro de main(), getline() y copia()?

la keyword extern se utiliza para declarar variables globales que pueden usarse en las diferentes funfunciones. En el ejercicio anterior se utiliza para guardad linea y linea_max.

### a) La funcion corta_string no hace un chequeo si el string que recibe como parámetro debe de tener al menos un caracter. Modifica esta función de modo que haga este chequeo:
gcc ejercicio_3_a.C -o out

## b) Cómo modificas la forma en que es llamada corta_string dentro de main de modo que devuelva: verdes ?? (hay un espacio antes del string "verdes").

gcc ejercicio_3_b.C -o out

### Ejercicio 4
gcc ejercicio_4_a.C -o out 
