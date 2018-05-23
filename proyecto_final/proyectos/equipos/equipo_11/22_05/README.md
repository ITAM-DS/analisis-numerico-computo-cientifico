---
title: "Avance Primera Semana de Finales"
output: html_document
---

Thalía: 

Se agregaron comentarios al código, con énfasis en la función que corre el algoritmo en paralelo, explicando por qué son necesarias las directivas de openmp que se utilizaron para correr el algoritmo en paralelo.
```
gcc -o dijkstra_paraleloc -fopenmp dijkstra_paralelo.c

./dijkstra_paraleloc

```
![Paralelo](fotos/paralelo.png)


Lorena: Empecé a implementar las funciones que ya tenemos en C en Cython ocupando Jupyter-Notebook, esto con el objetivo de tener un ejemplo interactivo que tenga parte del código en Python y parte del código (la parte que requiere optimizarse y la que está programada en paralelo) en C. 

![Cython](fotos/cython1.png)

![Cython](fotos/cython2.png)




Roberto:

Se agregó la función *timestamp* a la implementación secuencial del algoritmo para poder obtener una medida de eficiencia. 
```
gcc -Wall dijkstra_secuencial.c -o dijkstra_secuencial.out

Para ejecutar: ./dijkstra_secuencial.out

```

![Secuencial](fotos/secuencial.png)



Link al trabajo escrito: (https://drive.google.com/open?id=1_edvCMJje75oSF46WjvKv6OmfmkKxOAo)

Link al codigo: [codigo](codigo)
