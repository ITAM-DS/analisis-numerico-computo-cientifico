#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "red.h"

// Definición de constantes

#define LONGITUDLINEA 1000

// Definición de tipos

typedef struct linea {
  char *str;
  struct linea *ptr;
} LINEA;

// Globales

LINEA *primera;
LINEA *actual;


// Función para leer una lina de un stream específico. Regresa un 1 si
// encuentra un EOF, 0 si no.

int read_linea(FILE *stream, char linea[LONGITUDLINEA])
{
  if (fgets(linea,LONGITUDLINEA,stream)==NULL) return 1;
  linea[strlen(linea)-1] = '\0'; 
  return 0;
}


// Función para leer el archivo completo a una lista de aristas

int fill_buffer(FILE *stream)
{
  int longitud;
  char linea[LONGITUDLINEA];
  LINEA *pasada;

  if (read_linea(stream,linea)!=0) {
    primera = NULL;                 
    return 1;
  }
  longitud = strlen(linea) + 1;
  primera = malloc(sizeof(LINEA));
  primera->str = malloc(longitud*sizeof(char));
  strcpy(primera->str,linea);

  pasada = primera;
  while (read_linea(stream,linea)==0) {
    longitud = strlen(linea) + 1;
    pasada->ptr = malloc(sizeof(LINEA));
    pasada = pasada->ptr;
    pasada->str = malloc(longitud*sizeof(char));
    strcpy(pasada->str,linea);
  }
  pasada->ptr = NULL;

  return 0;
}


// Liberar el buffer.

void free_buffer()
{
  LINEA *estaptr;
  LINEA *siguienteptr;

  estaptr = primera;
  while (estaptr!=NULL) {
    siguienteptr = estaptr->ptr;
    free(estaptr->str);
    free(estaptr);
    estaptr = siguienteptr;
  }
}


// Resetear el buffer.

void reset_buffer()
{
  actual = primera;
}


// Ir a la siguiente linea. 0 si hay línea o 1 si se acabó el buffer

int siguiente_linea(char linea[LONGITUDLINEA])
{
  if (actual==NULL) return 1;
  strcpy(linea,actual->str);
  actual = actual->ptr;
  return 0;
}



// Leer del archivo gml si la red es o no dirigida. Si el archivo no dice
// nada al respecto se asume no dirigida.

int es_dirigida()
{
  int result=0;
  char *ptr;
  char linea[LONGITUDLINEA];

  reset_buffer();

  while (siguiente_linea(linea)==0) {
    ptr = strstr(linea,"directed");
    if (ptr==NULL) continue;
    sscanf(ptr,"directed %i",&result);
    break;
  }

  return result;
}


// Para contar los nodos, regresa la cuenta

int count_nodos()
{
  int result=0;
  char *nonspace;
  char linea[LONGITUDLINEA];

  reset_buffer();

  while (siguiente_linea(linea)==0) {
    for (nonspace=linea; *nonspace==' '; nonspace++);
    if (strncmp(nonspace,"node",4)==0) result++;
  }

  return result;
}


// Comparar los id de dos nodos

int cmpid(NODO *v1p, NODO *v2p)
{
  if (v1p->id>v2p->id) return 1;
  if (v1p->id<v2p->id) return -1;
  return 0;
}


// Para alojar el espacio de la estructura red en un gml y determinar
// los parámetros de cada nodo

void create_red(RED *red)
{
  int i;
  int longitud;
  char *ptr;
  char *start,*stop;
  char *nonspace;
  char linea[LONGITUDLINEA];
  char etiqueta[LONGITUDLINEA];

  // Determinar si es dirigida

  red->dirigida = es_dirigida();

  // Contar nodos

  red->nnodos = count_nodos();

  // Hacer espacio para los nodos

  red->nodo = calloc(red->nnodos,sizeof(NODO));

  // Leer los detalles de los nodos

  reset_buffer();
  for (i=0; i<red->nnodos; i++) {

      // Ir a la siguiente entrada de nodo. Revisa si dice "node" explícitamente en el inicio
      // por si a caso :/

    do {
      siguiente_linea(linea);
      for (nonspace=linea; *nonspace==' '; nonspace++);
    } while (strncmp(nonspace,"node",4)!=0);

    // Leer los detalles de los nodos

    do {


      for (nonspace=linea; *nonspace==' '; nonspace++);

      // Buscar los id

      if (strncmp(nonspace,"id",2)==0) {
	sscanf(nonspace,"id %i",&red->nodo[i].id);
      }

      // Busca etiquetas

      if (strncmp(nonspace,"label",5)==0) {
	start = strchr(linea,'"');
	if (start==NULL) {
	  sscanf(nonspace,"label %s",&etiqueta);
	} else {
	  stop = strchr(++start,'"');
	  if (stop==NULL) longitud = strlen(linea) - (start-linea);
	  else longitud = stop - start;
	  strncpy(etiqueta,start,longitud);
	  etiqueta[longitud] = '\0';
	  red->nodo[i].etiqueta = malloc((longitud+1)*sizeof(char));
	  strcpy(red->nodo[i].etiqueta,etiqueta);
	}
      }


      if (strstr(linea,"]")!=NULL) break;

    } while (siguiente_linea(linea)==0);

  }

  // Ordenar los nodos de menor a mayor

  qsort(red->nodo,red->nnodos,sizeof(NODO),(void*)cmpid);
}


// Usar binary search para buscar nodos con id específico
// regresa el elemento del arreglo nodo[] con dicho id o -1
// si no existe

int find_nodo(int id, RED *red)
{
  int top,bottom,split;
  int idsplit;

  top = red->nnodos;
  if (top<1) return -1;
  bottom = 0;
  split = top/2;

  do {
    idsplit = red->nodo[split].id;
    if (id>idsplit) {
      bottom = split + 1;
      split = (top+bottom)/2;
    } else if (id<idsplit) {
      top = split;
      split = (top+bottom)/2;
    } else return split;
  } while (top>bottom);

  return -1;
}
    

// Lee los datos de las aristas para determinar el grado de cada nodo

void get_grados(RED *red)
{
  int s,t;
  int vs,vt;
  char *ptr;
  char linea[LONGITUDLINEA];

  reset_buffer();

  while (siguiente_linea(linea)==0) {


    ptr = strstr(linea,"edge");
    if (ptr==NULL) continue;

    // Lee el nodo entrada y el nodo llegada

    s = t = -1;

    do {

      ptr = strstr(linea,"source");
      if (ptr!=NULL) sscanf(ptr,"source %i",&s);
      ptr = strstr(linea,"target");
      if (ptr!=NULL) sscanf(ptr,"target %i",&t);


      if (strstr(linea,"]")!=NULL) break;

    } while (siguiente_linea(linea)==0);

    // aumenta el grado cada que encuentra una arista con ese nodo

    if ((s>=0)&&(t>=0)) {
      vs = find_nodo(s,red);
      red->nodo[vs].grado++;
      if (red->dirigida==0) {
	vt = find_nodo(t,red);
	red->nodo[vt].grado++;
      }
    }

  }

  return;
}


// Leer las aristas

void read_aristas(RED *red)
{
  int i;
  int s,t;
  int vs,vt;
  int *count;
  double w;
  char *ptr;
  char linea[LONGITUDLINEA];

  // Hacer espacio para las aristas

  for (i=0; i<red->nnodos; i++) {
    red->nodo[i].arista = malloc(red->nodo[i].grado*sizeof(ARISTA));
  }
  count = calloc(red->nnodos,sizeof(int));


  reset_buffer();

  while (siguiente_linea(linea)==0) {


    ptr = strstr(linea,"edge");
    if (ptr==NULL) continue;

    // Leer la entrada, la entrada y el peso

    s = t = -1;
    w = 1.0;

    do {

      ptr = strstr(linea,"source");
      if (ptr!=NULL) sscanf(ptr,"source %i",&s);
      ptr = strstr(linea,"target");
      if (ptr!=NULL) sscanf(ptr,"target %i",&t);
      ptr = strstr(linea,"value");
      if (ptr!=NULL) sscanf(ptr,"value %lf",&w);


      if (strstr(linea,"]")!=NULL) break;

    } while (siguiente_linea(linea)==0);

    // Añadir las aristas al nodo apropiado

    if ((s>=0)&&(t>=0)) {
      vs = find_nodo(s,red);
      vt = find_nodo(t,red);
      red->nodo[vs].arista[count[vs]].entrada = vt;
      red->nodo[vs].arista[count[vs]].peso = w;
      count[vs]++;
      if (red->dirigida==0) {
	red->nodo[vt].arista[count[vt]].entrada = vs;
	red->nodo[vt].arista[count[vt]].peso = w;
	count[vt]++;
      }
    }

  }

  free(count);
  return;
}


// Leer la red completa

int leer_red(RED *red, FILE *stream)
{
  fill_buffer(stream);
  create_red(red);
  get_grados(red);
  read_aristas(red);
  free_buffer();

  return 0;
}


// Liberar la memoria

void free_red(RED *red)
{
  int i;

  for (i=0; i<red->nnodos; i++) {
    free(red->nodo[i].arista);
    free(red->nodo[i].etiqueta);
  }
  free(red->nodo);
}
