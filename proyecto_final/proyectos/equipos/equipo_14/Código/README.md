## Consideraciones para los códigos

Para correr el script que genera matrices hay que correr el siguiente código:

```
gcc -Wall -fopenmp GeneraMatrices.c -o GeneraMatrices.out
```

Posteriormente se tiene que correr el siguiente código con los parámetros deseados:

```
./GeneraMatrices.out #renglones #columnas ArchivoconMatriz.txt
```

Para correr el script que multiplica matrices de manera secuencial hay que correr el siguiente código:

```
gcc -Wall -fopenmp multip\_secuencial.c -o multip\_secuencial.out
```

Posteriormente se tiene que correr el siguiente código con los parámetros deseados, es importante mencionar que se deben tener los archivos A.txt y B.txt en la misma carpeta:

```
./multip\_secuencial.out dimMatA dimMatB
```
