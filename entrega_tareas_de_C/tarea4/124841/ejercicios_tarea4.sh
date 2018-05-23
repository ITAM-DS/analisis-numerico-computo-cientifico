#Tarea 4

#Compilacion
gcc -Wall ejercicio1a.c -o ejercicio1a.out
gcc -Wall ejercicio1b.c -o ejercicio1b.out
gcc -Wall ejercicio2a.c -o ejercicio2a.out
gcc -Wall ejercicio2b.c -o ejercicio2b.out
gcc -Wall ejercicio2c.c -o ejercicio2c.out
gcc -Wall ejercicio2d.c -o ejercicio2d.out
gcc -Wall ejercicio2e.c -o ejercicio2e.out
gcc -Wall ejercicio3.c -o ejercicio3.out
gcc -Wall ejercicio4.c -o ejercicio4.out

./ejercicio1a.out > ejercicio1a_output.txt
./ejercicio1b.out < archivo.txt > ejercicio1b_output.txt
./ejercicio2a.out < archivo2.txt > ejercicio2a_output.txt
./ejercicio2b.out < archivo2.txt > ejercicio2b_output.txt
./ejercicio2c.out < archivo2.txt > ejercicio2c_output.txt
./ejercicio2d.out < archivo2.txt > ejercicio2d_output.txt
./ejercicio2e.out < archivo2.txt > ejercicio2e_output.txt
./ejercicio3.out > ejercicio3_output.txt
./ejercicio4.out > ejercicio4_output.txt


#Respuesta 2f) El extern adentro de las funciones sirve para declarar las variables sin definirlas, es decir declara que esa variable existe pero que no necesariamente esta definida en esa parte del programa, esto es posible porque extern también significa que esas variables son visibles para todas las funciones del programa. 
echo "Ejercicio 1"

echo "a)"
./ejercicio1a.out > ejercicio1a_output.txt
echo "b)"
./ejercicio1b.out < archivo.txt 
echo "Ejercicio 2"
echo "a)"
./ejercicio2a.out < archivo2.txt 
echo "b)"
./ejercicio2b.out < archivo2.txt
echo "c)"
./ejercicio2c.out < archivo2.txt 
echo "d)"
./ejercicio2d.out < archivo2.txt 
echo "e)"
./ejercicio2e.out < archivo2.txt 


echo "f) El extern adentro de las funciones sirve para declarar las variables sin definirlas, es decir declara que esa variable existe pero que no necesariamente esta definida en esa parte del programa, esto es posible porque extern también significa que esas variables son visibles para todas las funciones del programa."

echo "Ejercicio 3"
./ejercicio3.out 
echo "Ejercicio 4"
./ejercicio4.out 




