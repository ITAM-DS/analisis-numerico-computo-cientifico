#Creamos nuevos vectores de prueba 
#Vectores originales
printf "Vectores originales:\n"
printf "1\n0\n-3\n" > v1.txt
printf "5\n8\n9\n" > v2.txt
gcc -Wall dot_product.c funciones.c -o programa.out -lblas
./programa.out 3
#Prueba 1
#Vectores 3 y 4 
printf "Prueba1\n"
printf "6\n8\n9\n50\n" > v1.txt
printf "25\n33\n2\n39\n" > v2.txt
gcc -Wall dot_product.c funciones.c -o programa.out -lblas
./programa.out 4 

#Prueba2
#Vectores 5 y 6
printf "Prueba2\n"
printf "5\n68\n9\n53\n45\n" > v1.txt
printf "15\n12\n11\39\n100\n" > v2.txt
gcc -Wall dot_product.c funciones.c -o programa.out -lblas
./programa.out 5 


