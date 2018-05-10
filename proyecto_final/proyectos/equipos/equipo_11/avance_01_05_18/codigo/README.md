# Avances de la implementación del algoritmo en C

Para ejecutar el código se deben tener todos los archivos en la misma carpeta. 

# Para compilar:
gcc -Wall dijkstra.c funciones.c -o dijkstra.out

# Para ejecutar (5 indica el numero total de nodos del grafo  ejemplo, que se representa con una matriz en el archivo Graph1.txt):
./dijkstra.out 5

# El output que se obtiene hasta ahora:
Introduce el nodo origen s

0

Matriz del grafo:
 d[0][0]=0.00000	d[0][1]=2.00000	d[0][2]=8.00000	d[0][3]=5.00000	d[0][4]=inf

 d[1][0]=inf	d[1][1]=0.00000	d[1][2]=1.00000	d[1][3]=inf	d[1][4]=inf

 d[2][0]=inf	d[2][1]=inf	d[2][2]=0.00000	d[2][3]=inf	d[2][4]=3.00000

 d[3][0]=inf	d[3][1]=inf	d[3][2]=inf	d[3][3]=0.00000	d[3][4]=4.00000

 d[4][0]=inf	d[4][1]=inf	d[4][2]=inf	d[4][3]=inf	d[4][4]=0.00000

------------
Vector que indica los nodos visitados hasta el momento inicializado:
 visited[0]=0

 visited[1]=0
 
 visited[2]=0
 
 visited[3]=0
 
 visited[4]=0

------------
Vector de distancias inicializado:
 
 distancia 0-0=0.000000
 
 distancia 0-1=inf

 distancia 0-2=inf

 distancia 0-3=inf
 
 distancia 0-4=inf

------------

![Ejecución.](https://drive.google.com/file/d/1cEm00qbApkFyBJEkN31RXUGhMCOucqP2/view)
