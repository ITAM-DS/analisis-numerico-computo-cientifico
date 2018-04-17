#En la carpeta analisis-numerico-computo-cientifico/C/BLAS/ejemplos/level3/ ejecuta el programa dgemm_mult_mat.c y realiza pruebas con diferentes matrices definidas por ti.



#Matrices originales

printf "Matrices originales :\n" > Resultados6-6.txt
printf "0 1.5\n4 -5\n-1 2.5\n" > A2.txt
printf "1 0 0\n0 -1 1\n" > B2.txt
gcc -Wall dgemm_mult_mat.c funciones.c -o programa2.out -lblas
./programa2.out 3 2 2 3 >> Resultados6-6.txt

#Prueba 1
printf "Prueba 1:\n" >> Resultados6-6.txt
printf "1 12\n13 0\n" > A2.txt
printf "3 -1 2\n-1 -1 11\n" > B2.txt
gcc -Wall dgemm_mult_mat.c funciones.c -o programa2.out -lblas
./programa2.out 2 2 2 3 >> Resultados6-6.txt


#Prueba 2
printf "Prueba 2:\n" >> Resultados6-6.txt
printf "0 1 2 3 4 5\n2 -2 3 -5 7\n0 8 0 8 9\n" > A2.txt
printf "0 1\n-3 -2\n" > B2.txt
gcc -Wall dgemm_mult_mat.c funciones.c -o programa2.out -lblas
./programa2.out 3 5 2 2 >> Resultados6-6.txt



#Prueba 3
printf "Prueba 3:\n" >> Resultados6-6.txt
printf "1 1\n13 10\n-1 -2\n-3 -5\n" > A2.txt
printf "1 -12\n0 -2\n1 2\n" > B2.txt
gcc -Wall dgemm_mult_mat.c funciones.c -o programa2.out -lblas
./programa2.out 4 2 3 2 >> Resultados6-6.txt

