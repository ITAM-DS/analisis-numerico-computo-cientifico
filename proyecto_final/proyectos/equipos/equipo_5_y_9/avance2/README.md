# Avance 2: Reporte al 16 de Mayo 2020

## Integrantes:

* Dorely Morales Santiago

* Margarita M. Muñoz Sancén

* Guillermo Zarazúa Cruz

* Alfie S. Gonzalez Salcedo

* Javier Valencia Goujon

* Oscar A. Aguilar Castillo

## Trabajo: 

### Resumen

El 9 de mayo tuvimos reunión con Erick para la revisión de Avances1. Tras el feedback recibido, se agregó como objetivo del proyecto el uso de factorización de matrices No-Negativas y como tarea añadir ejemplos donde se usen las matrices One-Class y Binarias que también están disponibles en la librería. Se decidió además crear un Milestone relativo al diseño de las muestras de películas de Netflix que serán utilizadas para correr libmf con entrenamiento y validación.

El 13 de mayo nos reunimos para discutir avances individuales en el proyecto, así como asignar tareas nuevas. Javier realizó una prueba exitosa levantando una instancia EC2 en AWS, además se verificó que tanto Maggie, como Dorely pudieron conectarse a dicha instancia. Además, se acordó que para garantizar cumplir con el 90% del trabajo el viernes 22 de mayo, el objetivo será utilizar un extracto de la base original para la implementación y presentación de resultados. En caso de lograr los avances y el reporte satisfactoriamente anterior a lo previsto, se buscará correr la base completa del *Netflix prize*.

Los avances logrados sobre los equipos se describen a continuación:

### Project Manager

Avanzamos en el *milestone* de **Implementación** relacionado con los issues #14 #15 #16 y #22 logrando generar las bases pequeñas de entrenamiento, pruebas con funciones disponibles en libmf Python así como levantar una instancia en AWS. En el *milestone* de **Trabajo Escrito** avanzamos con los issues #19 #20 #30 y #32 respecto a la la Introducción del trabajo escrito y parámetros de la librería, así como ejemplos de algunas factorizaciones disponibles. En general, encargada de dar seguimiento y revisión de ambos milestones.

### Equipo de programación

Respecto a los issues #14 #15 #16 y #22 relacionados con el *milestone* de **Implementación** se realizaron los siguientes avances:

+ Maggie genera el código para la lectura de la base de *Netflix prize* y la separación en *train* y *test*, así como revisión y notas a la Introducción del trabajo escrito.
+ Alfie realizó códigos en formato .py para la lectura y centralización de las calificaciones de la base muestra de *Netflix*.
+ Guillermo generó códigos de ejemplo con el uso de funciones de libmf (con shell y magic commands) y libmf-python sobre Python con matrices aleatorias y una muestra de la base netflix

Respecto al *milestone* de **Sampling Design** tuvimos los siguientes avances:

+ Javier realizó la lectura y pruebas exitosas para la manipulación de la base completa del concurso de Netflix sobre una instancia de AWS. Con ello, se confirma que es posible trabajar con la base completa desde la instancia y que se procederá a dar el mismo tratamiento que se dio a la base chica dat_muestra_nflix.csv una vez se concluya el reporte de resultados de esta.

### Investigación, Revisión y Documentación

+ En lo relativo al issue #19, Óscar realiza la Introducción del trabajo escrito en el [overleaf](https://www.overleaf.com/read/ffbjdrrxtmdm). Se crea una tabla para indicar los parámetros de la librería LIBMF y las entradas para utilizar distintos métodos. Se describen dichos métodos de manera general y se proporcionan ejemplos básicos de dichas matrices. Después de las revisiones de Maggie y Dorely, se agrega la introducción al [README del proyecto](https://github.com/DorelyMS/proyecto-final-equipo5-mno-2020-1). 
+ Javier investigó y documentó en el documento de Overleaf ejemplos de uso prácticos para matrices Binarias y One-Class issue #20.
+ Respecto al issue #10 agregaron referencias y se realizan primeras revisiones a documentación de los códigos.
+ Maggie agrega ejemplo práctico de factorización de matrices no negativas (NPF) issue #30.

## Tareas (o *milestone* o trabajo) que continúa

La próxima semana, se completarán todos los *milestones* e issues pendientes completando las siguientes tareas:

+ Agregar documentación sobre la instancia utilizada y un paso a paso sobre cómo se generó con fines de poder hacer reproducible el proyecto.
+ Agregar documentación de cómo funciona el método implementado en libmf para obtener la factorización matricial: FPSG (Fast Parallel Sthocastic Gradient).
+ Correr RVMF y NPF en libmf con base chica Netflix modificando todos los parámetros sobre instancia de AWS con Docker de jupyterlab
+ Documentación de pruebas con libmf, agregar aprendizajes sobre cómo cambia el desempeño cuando se modifica cada parámetro.
+ Reporte ejecutivo de resultados en Notebook con parámetros finales que obtuvieron mejor desempeño en factorizaciones RVMF y NPF y reportar en el trabajo escrito.
+ Comparación de desempeño del modelo implementado en libmf con la referencia base y tomar ejemplos particulares de recomendaciones para evaluar si las recomendaciones tienen sentido.

En caso de lograr los avances en un tiempo menor a lo previsto:

+ Utilizar el código trabajado con los parámetros que obtuvieron el mejor desempeño para intentar correr libmf con la base completa de *Netflix*. En caso de éxito, agregar los resultados obtenidos.
