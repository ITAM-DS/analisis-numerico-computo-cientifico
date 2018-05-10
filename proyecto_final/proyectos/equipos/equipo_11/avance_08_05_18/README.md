Esta semana se realizaron más avances en el código a entregar y se terminó la lectura y resumen para la sección de openmp y para la sección implementación en dijkstra.

Individual:

Thalía: Primer "borrador" de la implementación en paralelo del algoritmo de dijkstra. Es una modificación del código secuencial implementado por Roberto esta semana que modifica las funciones: *dijkstra_distance* y *main*. El código no corre todavía. Como se puede ver [aquí](https://drive.google.com/file/d/1JfkdBlnN32Af7yez1DwlN8EP5xzlBhrD/view?usp=sharing), el código tiene algunos problemas con la definición de variables y hay un error con la implementación paralela del algoritmo, que estamos investigando como resolver. Los warnings y notas de la definición de variables van a quedar arreglados para la siguiente entrega.

Roberto: Implementación secuencial del algoritmo de dijkstra en C. Esta implementación aún no incorpora los avances de Lorena que permiten leer un grafo desde un archivo .txt. El output de la implementación secuencial del algoritmo de dijkstra esta en el git o también se puede ver [aquí](https://drive.google.com/file/d/1Q7uL5tYb59l_S_70q9xlNdUk_TOHtYLV/view?usp=sharing).

Lorena: Resumen de la lectura realizada por Thalía para la semana pasada (https://ieeexplore.ieee.org/document/6240942/) acerca de las implementaciones en paralelo del algoritmo de Dijkstra en openmp. Tambien ;eí el artículo *Fibonacci heaps and their uses in improved network optimization algorithms*, y redacté la sección del trabajo escrito acerca de Implementaciones existentes del Algoritmo de Dijkstra, así como la sección de los artículos discutidos la semana anterior, especificamente las secciones OpenMP y Algoritmo de Dijkstra en Paralelo. ![Trabajo escrito semana 5](https://drive.google.com/file/d/1Y-FJfFDE45l5zJd6eE1oV0i-kYoL5AYH/view). El link a los artículos y los detalles de las referencias se encuentran en el README de la carpeta principal. Todavía no modifico lo de las observaciones que me hiciste de la implementación que hice la vez anterior, lo del macro para el arreglo de 1 dimension, pero planeo corregir eso esta semana cuando combine mi script con el de Roberto, disculpa. Adicionalmente actualicé el README del código de la semana pasada para poner lo de compilación y ejecución, de nuevo disculpa. Se puede ver ![aquí](https://github.com/lmalpicas/analisis-numerico-computo-cientifico/blob/master/proyecto_final/proyectos/equipos/equipo_11/avance_01_05_18/codigo/README.md).
.

Equipo: 

Reunión para discutir la manera de implementar el algoritmo en paralelo. Lorena y Roberto le explicaron a Thalía los detalles del código que implementaron (Lorena para la entrega pasada y Roberto para esta entrega) para que Thalía pudiera modificarlo y empezar con la implementación en paralelo.

[Link](https://drive.google.com/file/d/1Y-FJfFDE45l5zJd6eE1oV0i-kYoL5AYH/view) al trabajo escrito: 

[Link](https://github.com/taguerram/analisis-numerico-computo-cientifico/blob/mno-2018-1/proyecto_final/proyectos/equipos/equipo_11/avance_08_05_18/dijkstra_secuencial.c) a la implementación secuencial del algoritmo:

[Link](https://github.com/taguerram/analisis-numerico-computo-cientifico/blob/mno-2018-1/proyecto_final/proyectos/equipos/equipo_11/avance_08_05_18/dijkstra_paralelo.c) a la implementación en paralelo del algoritmo.

Comentarios anteriores:

El algoritmo en python generaba el siguiente error:
![Resultado ejecución en python.] (https://drive.google.com/file/d/1yrzLDiyAgr7WTgQ4q1I3QA7XnhY8fbZ3/view)
Pero en lugar de corregirlo preferimos avanzar con la implementación en C. 
Una disculpa de lo del trabajo escrito, en el avance anterior si te pusimos el link al texto pero se nos fue esta vez, ya lo corregimos. 
![Trabajo escrito semana 5](https://drive.google.com/file/d/1Y-FJfFDE45l5zJd6eE1oV0i-kYoL5AYH/view).
Se corrigió el README de la carpeta principal para incluir los links a las implementaciones que llevamos, ya que el README anterior solo tenía el link a la implementación del primero de mayo. Esto se puede ver ![aquí](https://github.com/lmalpicas/analisis-numerico-computo-cientifico/tree/master/proyecto_final/proyectos/equipos/equipo_11)

