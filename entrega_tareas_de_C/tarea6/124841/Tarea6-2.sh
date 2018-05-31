#En la carpeta analisis-numerico-computo-cientifico/C/BLAS/ejemplos/#level2/ ejecuta el programa dgemv_mult_mat_vec.c y realiza pruebas #con diferentes matrices y vectores definidos por ti.

#Vector y matriz originales
printf "Vector y matriz originales :\n" > Resultados6-2.txt
printf "1\n0\n" > v.txt
printf "0 1.5\n4 -5\n-1 2.5\n" > A.txt
gcc -Wall dgemv_mult_mat_vec.c funciones.c -o programa.out -lblas
./programa.out 3 2 >> Resultados6-2.txt


#Prueba 1
printf "\nPrueba 1:\n" >> Resultados6-2.txt
printf "1\n2\n\5.5\n6\n" > v.txt
printf "1 2.2 3 -2\n11 -10 -3 1\n0 2 6 2\n" > A.txt
gcc -Wall dgemv_mult_mat_vec.c funciones.c -o programa.out -lblas
./programa.out 3 4 >> Resultados6-2.txt


#Prueba 2
printf "\nPrueba 2:\n" >> Resultados6-2.txt
printf "1\n-5\n3\n" > v.txt
printf "1 0 15\n2 -3 23\n" > A.txt
gcc -Wall dgemv_mult_mat_vec.c funciones.c -o programa.out -lblas
./programa.out 2 3 >> Resultados6-2.txt



#Prueba 3
printf "\nPrueba 3:\n" >> Resultados6-2.txt
printf "2\n-5\n6\n" > v.txt
printf "7 13 20\n-2 1 -3\n12 3 2\n" > A.txt
gcc -Wall dgemv_mult_mat_vec.c funciones.c -o programa.out -lblas
./programa.out 3 3 >> Resultados6-2.txt

