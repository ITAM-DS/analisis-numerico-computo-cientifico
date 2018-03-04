# Ejercicio 1:
## a)

```{r}
gcc -Wall ejercicio_1_a.C -o out
./out 
```

## b)
Investiga el uso de la función scanf para que imprima la longitud de los strings del archivo.txt:

 ```{r}
gcc -Wall ejercicio_1_b.C -o out
./out < archivo_a.txt
 ```

# Ejercicio 2:
## a) Modifica el programa para que imprima sólo aquellas líneas que tienen más de 80 caracteres.

## b) Modifica el programa para que quite los espacios de cada línea leída.

## c) Modifica la función copia para que no use break pero todavía debe de usar el índice i.

## d) Modifica la función copia para que no use índices y sólo apuntadores.

## e) Escribe una función voltea que reciba un string s e imprima el string s al revés. Añade esta función para que el programa lea líneas y las imprima volteadas.

## f) Qué efecto tiene escribir extern para la declaración de variables dentro de main(), getline() y copia()?
 
