#En la carpeta del punto anterior encuentras la sección Multiplicación matriz-matriz con trick. Ejecuta el programa de esta sección con diferentes matrices definidas por ti y resuelve la pregunta ¿por qué funciona este trick?.
#Sin truco:
# dgemm_("No transpose", "No transpose", &M, &N, &K, &ALPHA, entradas(A), &M, entradas(B), &K, &BETA, entradas(C), &M);
	
# Las matrices estan en forma column-major que es como fortram las procesa y los parámetros se pasan normales. 
# A es de m x k 
# B es de k x n 
# al hacer alpha * A * B queda una matriz de m x n que se suma a la matriz C tambien de m x n. 


#Con truco:
# dgemm_("No transpose", "No transpose", &N, &M, &K, &ALPHA, entradas(B), &N, entradas(A), &K, &BETA, entradas(C), &N);

# Ahora las matrices estan en forma row-major osea para fortran estan:

# A es de k x m 
# B es de n x k

# Antes de llamar a dgemm_ C no se ha inicializado solo se han especificado sus dimensiones que siguen siendo m x n como en el caso sin truco.  

# El truco lo que hace es invertir los parametros a la hora de llamar a dgemm_

#Entonces en lugar de que se haga la multiplicación 

# A x B que en este caso no se podría


# Se hace:  

# B x A que dara como resultado una matriz de dimensiones n x m, pero una matriz de n x m en FORTRAM viene siendo una matriz m x n en C, como sucedió al inicializar A y B. 



#En la carpeta analisis-numerico-computo-cientifico/C/BLAS/ejemplos/level3/ ejecuta el programa dgemm_mult_mat.c y realiza pruebas con diferentes matrices definidas por ti.



#Matrices originales

printf "Matrices originales :\n" > Resultados6-7.txt
printf "0 1.5\n4 -5\n-1 2.5\n" > A3.txt
printf "1 0 0\n0 -1 1\n" > B3.txt
gcc -Wall dgemm_mult_mat_trick.c funciones2.c -o programa3.out -lblas
./programa3.out 3 2 2 3 >> Resultados6-7.txt

#Prueba 1
printf "Prueba 1:\n" >> Resultados6-7.txt
printf "1 12\n13 0\n" > A3.txt
printf "3 -1 2\n-1 -1 11\n" > B3.txt
gcc -Wall dgemm_mult_mat_trick.c funciones2.c -o programa3.out -lblas
./programa3.out 2 2 2 3 >> Resultados6-7.txt


#Prueba 2
printf "Prueba 2:\n" >> Resultados6-7.txt
printf "0 1 2 3 4 5\n2 -2 3 -5 7\n0 8 0 8 9\n" > A3.txt
printf "0 1\n-3 -2\n" > B3.txt
gcc -Wall dgemm_mult_mat_trick.c funciones2.c -o programa3.out -lblas
./programa3.out 3 5 2 2 >> Resultados6-7.txt



#Prueba 3
printf "Prueba 3:\n" >> Resultados6-7.txt
printf "1 1\n13 10\n-1 -2\n-3 -5\n" > A3.txt
printf "1 -12\n0 -2\n1 2\n" > B3.txt
gcc -Wall dgemm_mult_mat_trick.c funciones2.c -o programa3.out -lblas
./programa3.out 4 2 3 2 >> Resultados6-7.txt

