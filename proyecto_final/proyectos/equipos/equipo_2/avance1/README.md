# avance 1

## Integrantes:

* Brandon Francisco Hernández Troncoso, Desarrollador.

* Miguel Ángel Castañeda Martínez, Desarrollador.

* José Eduardo Gutiérrez Navarrete, Project manager.

## Problema:

Entender el funcionamiento y poder replicar el método de *simulated annealing (SA)* para encontrar minimos globales en funciones con diversos mínimos locales como: Ackley.

Adicionalmente, creemos que es relevante entender las aplicaciones de este algoritmo, por lo que en conjunto con los profesores Erick y Ezequiel decidimos aplicarlo para solucionar el problema del agente viajero como parte del segundo avance.

### Resúmen

En conjunto, los integrantes del equipo nos dimos a la tarea de investigar diferentes métodos de optimización consultando diversas referencias. El equipo decidió trabajar con el metodo SA, ya que este método involucra la optimización global a traves de movimientos aleatorios en la función objetivo. 

Como primer avance los desarrolladores lograron crear la función de SA e implementarla para encontrar mínimos globales en diversas funciones al igual que graficar la función con sus aproximaciones. 

### Individual

José Eduardo: 

Al buscar referencias adecuadas para el proyecto, encontré la siguiente [bibliografía](https://algorithmsbook.com/optimization/files/optimization.pdf). En este libro me llamó la atención el algoritmo SA e inmediatamente lo discutí con mis compañeros de equipo.

Una vez que decidimos trabajar con SA mis compañeros desarrolladores comenzaron a implementar funciones que replicaban el funcionamiento de SA, con sus resultados preliminares, comencé a escribir el reporte final a la par de que me aseguraba de que los objetivos fueran claros para todos y la cooperación y apoyo se mantuviera constante a lo largo de las diferentes tareas.

Miguel Angel:

Al haber definido el enfoque del proyecto, encontré la siguiente [liga](https://www.sfu.ca/~ssurjano/ackley.html) como referencia de la función Ackley.

Para el primer avance, tomé las funciones que implementó mi compañero **Brandon** del método `SA`, y las expandí para hacer una representación visual de las mismas en las que se mapeó la trayectoria que siguen las iteraciones del método.

Brandon:

Después de analizar la referencia proporcionada por mi compañero **Eduardo**, acordé con mi compañero **Miguel** que yo estaría a cargo de la traducción a código del pseudo-algoritmo disponible en la referencia. Así mismo, el algoritmo no especifica ciertas restricciones o consideraciones técnicas, por lo que tuve que investigar posibles alternativas y recomendaciones, por ejemplo la forma de escoger un punto vecino por medio de un tipo de distribución de probabilidad. 

También me di a la tarea de definir funciones sencillas con mínimos globales para que el algoritmo pudiera ser puesto a prueba. 


### Project manager

Se resolvieron los issues para cada una de las tareas contempladas en el primer avance. Es decir el código y gáficas para Ackley, coseno y la parábola.

### Grupo de programación

Después de un análisis exhaustivo se encontró que hay algunas variantes de SA por lo que se decidió implementar únicamente la propuesta encontrada en la [referencia](https://algorithmsbook.com/optimization/files/optimization.pdf)

Para la visualización de la función Ackley nos encontramos con el problema de mapear eficientemente dos variables $x_0, x_1$ a una función $f(x_0,x_1)$. Para resolverlo se utilizó el método mgrid de la librería Numpy, cuyo propósito es generar una malla de 2 variables.

### Grupo de revisión

En una llamada previa a hacer commit del código revisamos que este corriera sin fallas y sin typos. Adicionalmente el equipo de programación dió el visto bueno a la primera parte del reporte escrito, mismo que se adjuntará en el segundo avance.

## Tarea (o *milestone* o trabajo) que continúa

Para el segundo avance el equipo se enfocará en la implementación de SA para  resolver el problema del agente viajero y exponer los resultados en el reporte escrito.

