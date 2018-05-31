# Instrucciones

## Descripción

Este programa cuenta el numero de caracteres alfanuméricos y símbolos,
con la excepción de los caracteres usados para espacios (tab, newline, vertical tab, form feed, carriage return & space) 
y además cuenta el número de líneas.

## Como compilar el programa
El programa debe compilarse de la siguiene manera:


gcc tarea2.c -o tarea2.out

## Cómo ejecutar el programa

echo -n -e "Hello\n\n" | ./tarea2.out

o

./tarea2.out < README.md


## Preguntas y respuestas

1. Investiga lo que quiere decir las letras EOF:

EOF es un acróninmo de End Of File y es un indicador de que no hay más información disponible de una fuente de datos (Entrada estandar, un archivo, etc) y
es una constante que tiene asignado el valor de -1 en el archivo stdio.h.

2. Por qué se debe definir c como int?

Porque la función getchar regresa el caracter leido como un unsigned char haciendo cast a un int, EOF o un error.
