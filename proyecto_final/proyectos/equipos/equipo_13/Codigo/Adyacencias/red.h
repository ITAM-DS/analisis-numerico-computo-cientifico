#ifndef _RED_H
#define _RED_H

typedef struct {
  int entrada;        // Será un arreglo de nodos que son vecinos de un nodo.
  double peso;       // Peso de la arista, 1 si es no pesada.
} ARISTA;

typedef struct {
  int id;            // Identificador en el archivo gml
  int grado;         // Grado del nodo, grado de entrada para dirigidas
  char *etiqueta;    // Etiqueta del nodo en el archivo gml. NULL si no especifica
  ARISTA *arista;    // Arreglo de structs ARISTA, una para cada vecino
} NODO;

typedef struct {
  int nnodos;        // Número de nodos en la red
  int dirigida;      // 1 = si es dirigida, 0 = si es no dirigida
  NODO *nodo;        // Arreglo de structs NODO, uno para cada arista
} RED;

#endif
