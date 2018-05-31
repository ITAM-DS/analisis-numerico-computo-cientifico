## Equipo 05

Integrantes:

* Miguel

* Francisco

Título del proyecto: `Balanceo de Línea`

Objetivo del proyecto: `Encontrar la distribución óptima de las actividades requeridas para elaborar un producto entre cierto número de estaciones, minimizando el tiempo de ciclo y cumpliendo con las restricciones establecidas.`

En la carpeta [avance_01_05_2018](avance_01_05_2018) se encuentra el reporte del primer avance en nuestro proyecto. 

Equipo:

Nota: Se intentó modificar el método por


1. Se implementó la solucion de LASCURAIN.IN2 como datos default a correr en el programa, estos
corresponden a los mismos que la presentación en la liga, esto para mejor entendimiento. Las restricciones de la presentación fueron corregidas, tenían errores de álgebra.

2. Se terminó de diseñar la nueva metodología para generar tablas booleanas de restricciones. consiste en ordenar y generar las tablas conforme a la primera actividad en cada estacion.
(Tomamos la primera de actividad de la restricción de la  primera estación, la primera de la segunda, y continúa..)

3. En el folder nuevo se reescribieron métodos y se limpió código para obtener y mejorar los métodos generadores de restricciones. Se escribieron
	
	 Activity.cpp  FileReader.cpp  Graph.cpp  GraphCreator.cpp  main.cpp

Hubo varios errores de 
dependencias por lo que se invirtió tiempo considerable en la documentación de objetos y métodos de c++. Actualmente si
se corre, en el folder nuevo, el comando:

	g++ --std c++11 Activity.cpp  FileReader.cpp  Graph.cpp  GraphCreator.cpp  main.cpp

habrá errores en la matriz de restricciones de precedencia. Se sigue trabajando en ello.

4. Se determinó que el punto óptimo para hacer threading con cuda es en la operación de tablas booleanas como se creía anteriormente, sin embargo, se pretendía paralelizar desde antes, en particular en la determinación de la actividad origen y la actividad destino (método Graph::getOrigin y Graph::getDestination en el archivo Graph.cpp). Se intentará hacer threads con las mismas si hay tiempo al final.

Miguel: 

Puntos 1 y 2.

Paco:

Puntos 3 y 4.



Referencias del proyecto:

[liga c++ docs 1]: http://www.cplusplus.com/doc/
[liga objetos y métodos c++ 2]: https://www.tutorialspoint.com/cplusplus/index.htm