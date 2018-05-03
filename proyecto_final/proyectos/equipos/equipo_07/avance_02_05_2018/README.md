# Equipo 7

## Integrantes:
  * Luis Federico Puente
  * David Rivera 
  * Mirtha Ayala

## Principal Component Analisys
# 02 de mayo de 2018

En esta etapa continuamos con la implementacion para estandarizar los variables de la matriz, hasta este momento hemos logrado 
generar los parametros Media y Desviación estandar usando algunas de las funciones de la biblioteca math como pow() y sqrt, para
el calculo de la potencia y la raiz cuadrada. También agregamos otra nueva estructura de datos para almancenar las matrices normalizadas.

Aún estamos investigando las funciones para la normalización de la matriz por medio de las funciones de BLAS.

Adicionalmente estamos trabajando en la funcionalidad para poder especificar diferentes argumentos en la entrada del programa. Ejemplo:

```
./pca -f archivo.csv -h off 
```
# Referencias

  * https://www.tutorialspoint.com/c_standard_library/math_h.htm
  * https://sourceforge.net/projects/cccsvparser/

# Instrucciones para compilacion del programa
 
  Nuestro programa depende en el compilador gcc y la herramienta make. Para compilar el
  programa debe ejecutarse el siguiente comando:
 
  ```
    make build
  ````
  Para borrar los programas compilados debe ejecutarse el siguientes comando:

  ```
    make clean
  ```
 
# Instrucciones para ejecutar el programa

  Para ejecutar el programa deben seguirse los siguientes pasos:

  1. Descargar el [dataset](https://gist.github.com/lckymirth/4225fb3f4e5e0c89a34dedbc9aef8332) y guardar el archivo como train.csv

  2. Ejecutar el programa compilado
  ```
    ./pca
  ```

# Ejemplo de los resultados

  Puede encontrarse un ejemplo de la salida del programa en el archivo resultados.txt