# Avance 1

## Integrantes:

* Carlos Eduardo López de la Cerda Bazaldúa 158122

* Juan Humberto Escalona Santiago 203131

* Fernando Miñaur Olivares 158125

## Trabajo: Índice financiero multidimensional: una aplicación de componentes principales desde la optimización

[Liga al repositorio](https://github.com/kennyldc/proyecto_final_opt21_eq8)


### Objetivo del Trabajo 

En nuestro trabajo final nos concentraremos en crear un índice financiero utilizando como insumo diversos indicadores financieros mundiales. Para conseguir este objetivo, en el proyecto planteamos un Análisis de Componentes Principales (PCA) usando el método de la potencia y deflation.


### Resúmen

Nuestro avance 1 está ligado al primer milestone de nuestro proyecto: [Avance 1 - Discusión de los alcances del proyecto](https://github.com/kennyldc/proyecto_final_opt21_eq8/milestone/1). Durante esta primera etapa los colabores discutimos sobre la temática de nuestra entrega, la factibilidad del mismo y un primer acercamiento a los métodos y referencias a utilizar. 

Para la organización y la logística del proyecto como equipo decidimos seguir el esquema de trabajo Scrum. Con esto en mente, un momento importante del primer avance consistió en un *sprint planning* donde discutimos alguna alternativas de temáticas para el proyecto y propusimos una ruta en cuanto a los objetivos que buscamos del mismo.

Durante el *sprint planning* revisamos detalladamente las [indicaciones del profesor en el repositorio de la materia](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/optimizacion-2021/proyecto_final#trabajo-escrito) con la lista ejemplo de métodos numéricos para proyectos y las áreas de aplicación sugeridas. Consideramos como mejor alternativa centrarnos en el método de componentes principales y aplicarlo al mercado financiero. Como método numérico para aproximarnos al PCA decidimos seguir el método de la potencia y deflation. 

Las tareas que definimos para la primera etapa se pueden sintetizar de la siguiente forma:

User de Github | Tareas a realizar | Rol |
|:---:|:---:|:---:|
|@Fminaurol|Investigar algunas referencias útiles para los objetivos del proyecto, revisar las correcciones de la práctica anterior donde usamos deflation e identificar la correcta aplicación del método. | Desarrollo |
|@Juanes8| Buscar información sobre el sistema financiero e identificar qué indicadores sirven para el proyecto. Buscar fuentes confiables y descargar los datos a utilizar. | Desarrollo |
|@kennyldc|Revisar los esquemas y las indicaciones sugeridas para el proyecto. Crear el repositorio del proyecto y modificarlo con los milestones y issues y proyects que convengan. Documentar los avances para subir al directorio de la clase. | Project Manager |

Cada una de esta tareas se trasladaron a los siguientes issues dentro del [repositorio](https://github.com/kennyldc/proyecto_final_opt21_eq8):

- [Revisar los criterios de paro de la segunda parte de la práctica 1](https://github.com/kennyldc/proyecto_final_opt21_eq8/issues/5)

- [Identificar el métodos de optimización que mejor se ajusta al problema financiero](https://github.com/kennyldc/proyecto_final_opt21_eq8/issues/4)

- [Conseguir los datos de los indicadores financieros](https://github.com/kennyldc/proyecto_final_opt21_eq8/issues/3)

- [Modificar del README del directorio de opt2021 para cumplir con el ejemplo de las indicaciones](https://github.com/kennyldc/proyecto_final_opt21_eq8/issues/1)

- [Crear la carpeta "Avance 1" y modificar las secciones con el contenido de nuestro proyecto.](https://github.com/kennyldc/proyecto_final_opt21_eq8/issues/2)

Por último, hicimos una cita con el profesor (@palmoreck) desde [nuestro grupo de comunicación de Gitter](https://gitter.im/Equipo_8/community) y nos reunimos en Zoom el día martes 30 de noviembre.


### Individual

Carlos:

Organicé el *sprint planning* y llevé algunos temas de propuesta. Una vez que elegimos el tema financiero hice una pequeña investigación del tema. Leí todas las indicaciones del proyecto bajo el repositorio del curso para poder cumplir con los requisitos del profesor. Creé el repositorio del proyecto final y ajusté los *projects*, *milestones* e *issues* para cumplir nuestros objetivos. Hice un fork del repositorio del curso para dejar la estructura con los avances en el directorio del curso. Volví a checar algunas referencias sobre el *framework scrum*, documenté el *sprint planning* y el seguimiento de cada uno de los miembros del equipo y elaboré todo el README del avance para hacer el pull request en el directorio.

Fernando:

Durante el *sprint planning* propuse el tema de los índices del mercado financiero e investigué algunas referencias sobre como podríamos atacar el problema. En particular, encontré en un artículo de Victoria, Buenos Aires que habla de un índice multidimensional que puede ser de gran utilidad para poder desarrollar nuestro modelo y cerré el issue [Identificar el métodos de optimización que mejor se ajusta al problema financiero](https://github.com/kennyldc/proyecto_final_opt21_eq8/issues/4) con los links de las referencias. Luego revisé los criterios de paro del método deflation dado que es una aproximación útil a nuestro problema. Con esto emepecé a trabajar en las funciones que usaremos para el proyecto.

Juan: 

Encontré los índices con los que estaremos trabajando, realicé la descarga de la información histórica de los últimos 4 años y la limpieza de los datos siendo el valor al cierre del día la variable de interés en cada índice. Acomodé todos los índices en un Data Frame para su fácil manejo.


---

## Tarea (*milestone*) que continúa

Después de la aprobación del proyecto por parte profesor nos juntamos de nuevo como equipo y definimos el siguiente milestone en el repositorio: [Avance 2 - Programación de las funciones para solucionar el problema y motivación dentro del trabajo](https://github.com/kennyldc/proyecto_final_opt21_eq8/milestone/2). Para esta nueva tarea proponemos: 1) Limpiar los datos de los indicadores financieros y hacer visualizaciones preliminares; 2) Programar las funciones útiles para el método de la potencia y deflation y 3) Pasar los avances a nuestro trabajo escrito.
