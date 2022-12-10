# avance 1

## Integrantes:

* Brandon Francisco Hernandez Troncoso, Desarrollador.

* Miguel Angel Castañeda Martínez, Desarrollador.

* José Eduardo Gutiérrez Navarrete, Project manager.

## Problema:

Entender el funcionamiento y poder replicar el metodo de *simulated annealing (SA)* para encontrar minimos globales en funciones con diversos minimos locales como: Ackley.

Adicionalmente, creemos que es relevante, entender las aplicaciones de este algoritmo, por lo que en conjunto con el profesor Erick y Ezequiel decidimos aplicar el algoritmo para solucionar el problema del agente viajero. RRRR

### Resúmen

En conjunto, los integrantes del equipo se dieron a la tarea de investigar diversos metodos de optimización consultando diversas referencias.RRRR. El equipo decidió trabajar con el metodo SA, ya que este método involucra la optimización global a traves de movimientos aleatorios en la función objetivo. 

Como primer avance los desarrolladores lograron crear la función de SA e implementarla para encontrar minimos globales en diversas funciones

### Individual

José Eduardo: 

Al buscar referencias adecuadas para el proyecto, encontré la siguiente [bibliografía](https://algorithmsbook.com/optimization/files/optimization.pdf). En este libro me llamó la atención el algoritmo SA e inmediatamente lo discutí con mis compaleros de equipo.

Una vez que decidimos trabajar con SA mis compañeros desarrolladores comenzaron a implementar funciones que replicaban el funcionamiento de SA, con sus resultados preliminares, comencé a escribir el reporte final a la par de que me aseguraba de que los objetivos fueran claros para todos y la cooperación y apoyo se mantuviera constante a lo largo de las diferentes tareas.

Miguel Angel:

Al haber defindo el enfoque del proyecto, encontré la siguiente [liga](https://www.sfu.ca/~ssurjano/ackley.html) como referencia de la función Ackley.

Para el primer avance, tomé las funciones que implementó mi compañero **Brandon** del método `SA`, y las expandí para conseguir hacer una representación visual de las mismas, en las que además se mapeara la trayectoria que siguen las iteraciones del método.

Brandon:

Después de analizar la referencia proporcionada por mi compañero **Eduardo**, acordé con mi compañero **Miguel** que yo estaría a cargo de la traducción a código del pseudo-algoritmo disponible en la referencia. Así mismo, el algoritmo no especifica ciertas restricciones o consideraciones técnicas, por lo que tuve que investigar posibles alternativas y recomendaciones, por ejemplo la forma de escoger un punto vecino por medio de un tipo de distribución de probabilidad. 

También me di a la tarea de definir funciones sencillas con mínimos globales para que el algoritmo pudiera ser puesto a prueba. 


### Project manager

Resolvimos el *milestone* (...) relacionado con los *issues* (...) para la tarea (...)

### Grupo de programación

Programamos (...) que puede consultarse (...).

### Grupo de revisión

Revisamos (...) con diferentes parámetros y generamos el reporte (...)


---

## Tarea (o *milestone* o trabajo) que continúa

Determinamos que nos tomará dos días revisar los índices de las referencias que mencionó Erick y revisaremos la implementación de Erica para que la [funcion_imprime_hello_world_cuda.cu](src/funcion_imprime_hello_world_cuda.cu) imprima un `hello_world` por cada bloque de threads.

