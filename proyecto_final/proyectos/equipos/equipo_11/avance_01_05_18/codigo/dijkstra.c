#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include"definiciones.h"
#define graph_matrix "Graph1.txt" //Matriz representa el grafo donde cada entrada ij es la distancia entre esos nodos, cuando no hay conexión entre ellos se asigna infinito y la distancia a si mismos es 0. 
// Queue  variables y funciones
#define MAX 10 
double qu[MAX];
int front = 0;
int rear= -1;
int itemCount = 0;

int peek(){
  return qu[0];
}

bool isEmpty(){
  return itemCount == 0;
}

bool isFULL (){
 return itemCount == MAX;
}

int size (){
return itemCount;
}

void insert(int data) {

   if(itemCount==MAX) {
	
      if(rear == MAX-1) {
         rear = -1;            
      }       

      qu[++rear] = data;
      itemCount++;
   }
}

int removeData(){
 int data= qu[front++];
 if (front == MAX) {
 front=0;
 }
itemCount--;
return data;
}



//End of queue variables y funciones

int main (int argc, char *argv[]){
int n=atoi(argv[1]); //numero de vertices en el grafo
arreglo_2d_T ady_matrix;
int  *visited; //aquí se guardara 0s o 1s indicando si el nodo ya fue visitado 
double *distance; // aquí se guardarán las distancias entre el vértice origen s y los demas vertices (la distancia de s a sí mismo se asigna como 0), estas son las distancias que se irán actualizando conforme se encuentren caminos más cortos entre s y cada vértice v
int s; //vertice origen
int *v_pi; //en este vector se guardan los nodos v.pi para todo los nodos v, v.pi es el nodo predecesor al nodo v, este se va actualizando dependiendo de si el camino que pasa por un nuevo vertice da como resultado una distancia menor a la que se tiene hasta el momento (para más detalles ver la sección Relajación, del trabajo escrito)

printf("Introduce el nodo origen s\n"); 
scanf("%d", &s);

visited=malloc(n*sizeof(int));
distance=malloc(n*sizeof(double));
ady_matrix=malloc(sizeof(*ady_matrix));
v_pi=malloc(n*sizeof(int));
renglones(ady_matrix)=n;
columnas(ady_matrix)=n;
entradas(ady_matrix)=malloc(renglones(ady_matrix)*columnas(ady_matrix)*sizeof(double));
inicializa_matriz(ady_matrix, graph_matrix); //Se lee la matriz del grafo

//Se inicializan 0 todos los vertices del vector visited 
for(int i=0; i<n; i++)
  visited[i]=0;



printf("Matriz del grafo:\n");
	imprime_matriz(ady_matrix);
	printf("------------\n");



//imprimir visited y la matriz 
printf("Vector que indica los nodos visitados hasta el momento inicializado:\n");
for(int i=0; i<n; i++)
printf("visited[%d]=%d\n", i, visited[i]);

printf("------------\n");


//Se inicializa el vector distance

for (int i=1; i<n; i++){
    distance[i]=INFINITY;
    if(i==s){distance[i]=0;}
}


printf("Vector de distancias inicializado:\n");
for (int i=0; i<n; i++)
    printf("distancia %d-%d=%lf\n",s, i, distance[i]);


//printf("%lf\n", entrada(ady_matrix, s, i));
  printf("------------\n");

//El orden para visitar los nodos y efectuar el proceso de relajación está dado por una estructura de tipo fila para programar nuestra pila se adapto el codigo encontrado en : https://www.tutorialspoint.com/data_structures_algorithms/queue_program_in_c.htm 




        
free(visited);
free(distance);
free(v_pi);
free(entradas(ady_matrix));
	free(ady_matrix);

return 0;
}

