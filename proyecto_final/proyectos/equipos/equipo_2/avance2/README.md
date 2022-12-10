# avance 1

## Integrantes:

* Brandon Francisco Hernández Troncoso, Desarrollador.

* Miguel Ángel Castañeda Martínez, Desarrollador.

* José Eduardo Gutiérrez Navarrete, Project manager.

## Problema:

En este avance el objetivo era resolver el problema del agente viajero usando SA

### Resúmen

El equipo de desarrollo creo un set de puntos que representan 20 ciudades a las que un viajero debe viajar. Se aplicó la función con el algoritmo y esta minimizó la suma de distancias.

### Individual

José Eduardo: 

Continúe con la escritura del reporte y agregué el resultado gráfico obtenido por el equipo de desarrollo. Esto mientras me aseguraba que el equipo en su totalidad se apegará a los issues establecidos al principio del proyecto.

Miguel Angel:

En esta ocasión nuevamente se tomaron las funciones implementadas por mi compañero *Brandon*, en donde para un conjunto de datos aleatorio se visualizan dos posibles rutas.

* La primera de ellas muestra la ruta que un agente viajero seguiría en caso de tomar decisiones aleatorias a la hora de seleccionar la siguiente ciudad.
* La segunda muestra la ruta con la que el mismo agente minimizaría la distancia entre los destinos.

Brandon:

Como parte de las tareas asignadas dentro del equipo, me di a la tarea de entender y aterrizar el problema del Agente viajero como ejemplo para poder implementar SA. Por lo tanto, investigué en varias fuentes y videos proporcionados por la comunidad, dentro de los cuales se encontraron varias alternativas de implementación y se optó por resolver un problema para puntos aleatorios. As´mismo, me coordiné con mis compañeros para poder generar gráficas que permitieran entender la resolución del problema completo. 


### Project manager

Se resolvieron los issues para cada una de las tareas contempladas en el segundo avance. Es decir el código y gáficas para resolver el problema del agente viajero.

### Grupo de programación

Después de un análisis exhaustivo se encontró que hay algunas variantes de SA por lo que se decidió implementar únicamente la propuesta encontrada en la [referencia](https://algorithmsbook.com/optimization/files/optimization.pdf)

Para la visualización de la función Ackley nos encontramos con el problema de mapear eficientemente dos variables $x_0, x_1$ a una función $f(x_0,x_1)$. Para resolverlo se utilizó el método mgrid de la librería Numpy, cuyo propósito es generar una malla de 2 variables.

### Grupo de revisión

En una llamada previa a hacer commit del código revisamos que este corriera sin fallas y sin typos. Adicionalmente el equipo de programación dió el visto bueno a la primera parte del reporte escrito, mismo que se adjuntará en el segundo avance.

## Tarea (o *milestone* o trabajo) que continúa

- Se analizará la viabilidad de implementar el problema del agente viajero para ciudades reales.
- Se mejorará el formato de las gráficas en el reporte escrito.

