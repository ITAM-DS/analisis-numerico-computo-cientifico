# Instrucciones para compilar los programas

El conjunto de programas puede ser compilado usando gcc traves de la herramienta make o
manualmente.

## Compilar usando gcc desde make
```
make all (Compila todos los ejercicios)

o

make ejercicio_1_a (Compila un ejercicio en especifico)
```

```
make clean (Borra los programas compilados)
```

## Compilar manualmente con gcc
```
gcc -Wall -o ejercicio_1_a.out ejercicio_1_a.c
gcc -Wall -o ejercicio_1_b.out ejercicio_1_b.c
gcc -Wall -o ejercicio_2_a.out ejercicio_2_a.c
gcc -Wall -o ejercicio_2_b.out ejercicio_2_b.c
gcc -Wall -o ejercicio_2_c.out ejercicio_2_c.c
gcc -Wall -o ejercicio_2_d.out ejercicio_2_d.c
gcc -Wall -o ejercicio_2_e.out ejercicio_2_e.c
gcc -Wall -o ejercicio_3_a.out ejercicio_3_a.c
gcc -Wall -o ejercicio_3_b.out ejercicio_3_b.c
gcc -Wall -o ejercicio_4_a.out ejercicio_4_a.c
gcc -Wall -o ejercicio_4_b.out ejercicio_4_b.c
```

# Instrucciones para ejecutar los programas

```
./ejercicio_1_a.out  # Salida esperada en ejercicio_1_a.txt
./ejercicio_1_b.out < archivo.txt # Salida esperada en ejercicio_1_b.txt
```

```
./ejercicio_2_a.out < archivo2.txt # Salida esperada en ejercicio_2_a.txt
./ejercicio_2_b.out < archivo2.txt # Salida esperada en ejercicio_2_b.txt
./ejercicio_2_c.out < archivo2.txt # Salida esperada en ejercicio_2_c.txt
./ejercicio_2_d.out < archivo2.txt # Salida esperada en ejercicio_2_d.txt
./ejercicio_2_e.out < archivo2.txt # Salida esperada en ejercicio_2_e.txt
```
> ejercicio_2_f
Qué efecto tiene escribir extern para la declaración de variables dentro de main(), getline() y copia()?

Le dice al compilador que una variable o una función existe, incluso si el compilador aún no la ha visto en el archivo que está siendo compilado en ese momento. Es decir, Cuando el compilador encuentra la declaración de variables usando extern, este sabe que la definición para ellas debe existir en algún sitio como una variable global.

```
./ejercicio_3_a.out # Salida esperada en ejercicio_3_a.txt
./ejercicio_3_b.out # Salida esperada en ejercicio_3_b.txt
```

```
./ejercicio_4_a.out # Salida esperada en ejercicio_4_a.txt
./ejercicio_4_b.out # Salida esperada en ejercicio_4_b.txt
```
