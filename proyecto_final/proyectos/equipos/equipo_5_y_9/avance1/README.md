# Avance 1: Reporte al 9 de Mayo 2020

## Integrantes:

* Dorely Morales Santiago

* Margarita M. Muñoz Sancén

* Guillermo Zarazúa Cruz

* Alfie S. Gonzalez Salcedo

* Javier Valencia Goujon

* Oscar A. Aguilar Castillo

## Trabajo: 

### Resumen

El 2 de mayo tuvimos una reunión para la definición de nuestro proyecto final. En ella discutimos los alcances del proyecto, el lenguaje y herramientas a utilizar para la implementación del mismo. 

El 5 de mayo nos reunimos el equipo 5 y 9 para discutir la investigación que cada equipo llevaba y determinar la viabilidad de la fusión de ambos equipos y trabajar ambos en sistemas de recomendación. Acordamos la fusión.

El 6 de mayo nos reunimos nuevamente para definir la dinámica de trabajo. Se determinó Python como el lenguaje a utilizar. Decidimos usar la paquetería libmf para el desarrollo del proyecto. Al usar dicha paquetería, en una primera fase se busca avanzar en el potencial uso de la misma para sistemas de recomendación y complementar el desarrollo del proyecto como un trabajo de investigación.
Para la primera fase decidimos una división del equipo como sigue:

* Project Manager: Dorely
* Equipo de programación: Margarita, Guillermo, Alfie y Javier
* Investigación, Revisión y Documentación: Oscar

El 7 de mayo tuvimos un workshop para el entendimiento del problema que queremos resolver a partir del estudio conjunto de las [notas de referencia base](https://heuristic-bhabha-ae33da.netlify.app/sistemas-de-recomendaci%C3%B3n-y-filtrado-colaborativo.html) así como la implementación del [ejercicio muestra libmf](https://github.com/DorelyMS/proyecto-final-equipo5-mno-2020-1/tree/master/Implementaci%C3%B3n/Ejemplo0_libmf) ejecutado a través de línea de comandos de bash y arrojando [resultados para las muestras de entrenamiento y validación.](https://github.com/DorelyMS/proyecto-final-equipo5-mno-2020-1/blob/master/Implementaci%C3%B3n/Ejemplo0_libmf/salida_ejemplo_inicial.txt)

Los avances logrados sobre los equipos se describen a continuación:

### Project Manager

Se acordó que además de los trabajos usuales del project manager, apoya al equipo de programación en la investigación del uso de libmf y apoyo sobre el planteamiento del problema para el trabajo escrito.

Resolvimos el *milestone* de **Definición de Tema de Proyecto Final** relacionado con el issue #4 para la tarea del planteamiento inicial del proyecto. Seleccionando como lenguaje de Programación Python y seleccionamos la imagen de Docker basada en Python del curso MNO 2020 (palmoreck/jupyterlab_numerical:1.1.0).

### Equipo de programación

Enfoque en la investigación del uso de la paquetería libmf.
Avanzamos sobre el *milestone* de **Implementación** resolviendo el issue #8 sobre la tarea de correr el ejemplo muestra del repo de libmf, los resultados de este ejercicio pueden consultarse [aquí](https://github.com/DorelyMS/proyecto-final-equipo5-mno-2020-1/tree/master/Implementaci%C3%B3n/Ejemplo0_libmf)


### Investigación, Revisión y Documentación

Se agregaron issues en el project board. Se estudiaron las [notas de referencia base](https://heuristic-bhabha-ae33da.netlify.app/sistemas-de-recomendaci%C3%B3n-y-filtrado-colaborativo.html). Y se está consultando el material de esta [tesis](https://mariobecerra.github.io/files/school_projects/tesis_lma.pdf) y el siguiente [libro](https://rd.springer.com/book/10.1007%2F978-3-319-29659-3) para escribir el framework del trabajo escrito.

## Tareas (o *milestone* o trabajo) que continúa

Se busca que las tareas específicas a realizar sigan siendo en su mayoría para el *milestone* de **Implementación**. Por ello, se decidió subdividir al equipo de programación para avanzar de forma paralela en las siguientes tareas:

1. Programación para la lectura del archivo de películas, separación eficiente de las muestras de prueba y validación con el formato de lectura adecuado para su correcta lectura en libmf. Para la realización de esta tarea, se creó el issue #14.
2. Implementación de pruebas para entender todos los parámetros disponibles en lidmf: loss function, number of latent factors, number of iterations, initial learning rate, number of threads, number of folds for cross validation así como los métodos para encontrar la factorización con los que cuenta. Para la realización de esta tarea, se creó el issue #15.
3. Investigación sobre cómo implementar la eliminación de la heterogeneidad en uso de escala de calificaciones de películas. Para la realización de esta tarea, se creó el issue #16.
4. Redacción de Introducción sobre Trabajo Escrito: Se debe realizar una primera redacción sobre la Introducción al trabajo escrito en Overleaf que contenga la descripción de para qué sirve libmf, cómo a partir de la factorización en k factores latentes se generan recomendaciones de películas para una base de netflix con m usuarios, n películas y k factores latentes. Para la realización de esta tarea, se creó el issue #19.

Finalmente, nos conectaremos a la reunión del 9 de Mayo a las 9am con el profesor, presentar los avances y preguntar las dudas con lo relativo al avance hasta el momento.
