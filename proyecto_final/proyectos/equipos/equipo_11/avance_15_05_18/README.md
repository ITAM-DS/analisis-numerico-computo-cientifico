---
title: "Avance Segunda Semana"
output: html_document
---

Thalía: 

Se arregló la definición de variables y funciones de la implementación del algoritmo de dijkstra en paralelo que se había entregado la semana pasada y que no corría. El código se puede encontrar [aquí](https://github.com/taguerram/analisis-numerico-computo-cientifico/blob/6b00963b8f267cd1c74134ecb1c26fbce861159a/proyecto_final/proyectos/equipos/equipo_11/avance_15_05_18/dijkstra_paralelo.c) y el ejemplo del output del código se puede encontrar [aquí](https://drive.google.com/file/d/1xvlTuS9gnpFnVwLrZe7bea9cQDxIDSxy/view?usp=sharing). Como se puede ver, el resultado de la implementación en paralelo es la misma que arrojó la [implementación secuencial de Roberto](https://drive.google.com/file/d/1Q7uL5tYb59l_S_70q9xlNdUk_TOHtYLV/view?usp=sharing). La implementación en paralelo se realizó a partir de la implementación secuencial para asegurar que el código y el resultado fueran correctos.

Lorena: 
Modifiqué la función que generaba la matriz de adyacencia del código de Dijkstra en secuencial para que la lea de un archivo de texto. El código está  [aquí]() y el ejemplo del output está [aquí](https://drive.google.com/open?id=1OGTp2O2qjjGWeHbQrSeY_MT2z0TXjciQ). El archivo con la matriz de adyacencia se guarda en la misma carpeta y tiene el nombre "Graph1.txt".

Para compilar:
gcc -Wall dijkstra_secuencial.c -o dijkstra_secuencial.out

Para ejecutar:
./dijkstra_secuencial.out

Modifiqué la sección del trabajo escrito de OpenMP, y agregué la información de las directivas que usó Thalía para la implementación en paralelo de Dijkstra. Dado que se incorporó la función *timestamp* para medir eficiencia del algoritmo, también reintroduje al trabajo escrito la sección de Software en Paralelo, que habla de los principios generales para paralelizar un algoritmo y de cómo medir la eficiencia. Link al trabajo escrito: (https://drive.google.com/open?id=1_edvCMJje75oSF46WjvKv6OmfmkKxOAo)


Roberto:

Se agregó la función *timestamp* a la implementación en paralelo del algoritmo de dijkstra para posteriormente poder medir eficiencia. La [función](https://github.com/taguerram/analisis-numerico-computo-cientifico/blob/6b00963b8f267cd1c74134ecb1c26fbce861159a/proyecto_final/proyectos/equipos/equipo_11/avance_15_05_18/dijkstra_paralelo.c) y el [resultado](https://drive.google.com/file/d/1xvlTuS9gnpFnVwLrZe7bea9cQDxIDSxy/view?usp=sharing) ya están incorporados al código que Thalía corrigió esta semana. Como se puede ver, la matriz utilizada para corroborar que el código estuviera bien implementado es muy pequeña como para que se puedan observar diferencias sustanciales con respecto a la implementación secuencial. Para la próxima entrega se integrará la función *timestamp* a la implementación secuencial y se revisará si es necesario a) modificar la matriz utilizada, o b) agregar unidades de medida de tiempo para poder tener una medida de eficiencia. 

