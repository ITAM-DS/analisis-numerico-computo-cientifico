# Primer avance del proyecto de Métodos Numéricos y Optimización

**Profesor:** Erick Palacios Moreno

**Lenguaje a utilizar:** Python

## Equipo y Roles designados

| # | Alumno                            | Clave única | Roles Iniciales     |
|---|-----------------------------------|-------------|---------------------|
| 1 | Rafael Ortega                     | 123972      | Project Manager     |
| 2 | Elizabeth Rodriguez               | 191430      | Revisión de Código  |
| 3 | Karla Alfaro Pizaña               | 137314      | Revisión de Código  |
| 4 | Elizabeth Viveros                 | 161224      | Programadora |
| 5 | Mario Rodríguez                   | 164471      |Programador    |
| 6 | Leonardo Marín                    | 175903      |Programador          |

## Asignación de tareas por persona y por rol

Busqueda de bases de datos:

Se realizó una primer junta para la división de tareas del equipo, así como la asignación de roles que se encuentra en la tabla anterior.

* Rafael Ortega: Preparación del repositorio y búsqueda de bases de datos posibles para la implementación de un algoritmo que pueda ser utilizado en el proyecto, así como la planeación de la junta para hablar sobre el algoritmo.  

* Karla Alfaro: Búsqueda de bases de datos posibles para la implementación de un algoritmo que pueda ser utilizado en el proyecto, así como documentación sobre los algoritmos. Ya que se tenía la base de datos obtenida por Karla Alfaro, ella puso la propuesta del tratamiento de los datos, así como definir el tipo de variable que cada una de ellas tenía. Se inició el análisis de la base y el tratamiento de las variables. 

* Elizabeth Rodríguez: Búsqueda de bases de datos posibles para la implementación de un algoritmo que pueda ser utilizado en el proyecto, así como documentación sobre los algoritmos.

* Elizabeth Viveros:Búsqueda de bases de datos posibles para la implementación de un algoritmo que pueda ser utilizado en el proyecto, así como búsqueda de documentación y papers sobre la implementación de PCA.

* Leonardo Marín:Búsqueda de bases de datos posibles para la implementación de un algoritmo que pueda ser utilizado en el proyecto, así como búsqueda de documentación y papers sobre la implementación de PCA.

* Mario Rodríguez: Búsqueda de bases de datos posibles para la implementación de un algoritmo que pueda ser utilizado en el proyecto, así como búsqueda de documentación y papers sobre la implementación de PCA.

Todo el equipo se enfocó en la revisión de algoritmos y documentación útil para el proyecto.

Se decidió utilizar la base de datos propuesta por Karla, buscando una reducción de la dimensionalidad en el cuestionario PLANEA 2016.

## Propuestas de bases de datos

* [x] Principal Component Analysis con base de datos sobre estudiantes (Encuesta Planea)

  * Son 154 preguntas del cuestionario, se busca hacer PCA para reducir la dimensionalidad en los datos
  * Información de los maestros de español, de matemáticas
  * Información sobre el entorno escolar
  * Preguntas de entorno familiar
  * Preguntas de evaluación psicométrica
  * Preguntas de nivel socioeconómico
  * **579,923 observaciones** de los alumnos
  * variables dependientes: calificación de español y calificación de matemáticas
  * Muchas variables categóricas.* Con una regresión, buscaríamos pronosticar la clasificación de los alumnos en ambas materias.
  * Con una regresión, buscaríamos pronosticar la clasificación de los alumnos en ambas materias.
  
* [ ] Optimización de descenso en gradiente para el algoritmo de recomendación de [Netflix](https://www.kaggle.com/netflix-inc/netflix-prize-data) en concurso de Kaggle

  * Cerca de **1 millón de observaciones** de **480,000 usuarios** acerca de más de **17,000 películas.**
  * Descenso en gradiente estocástico para el algoritmo de recomendaciones
  * 3 columnas: ID usuario, calificación y año
  * Optimizar el algoritmo, grandes cantidades de datos

## Fechas

| # | Milestone/avance                                           | Fecha       | Entregable                          |
|---|------------------------------------------------------------|-------------|-------------------------------------|
| 1 | Avance 1:Selección de BD, lenguaje, tema, roles            | 25/Abril    | README.md en Avance_1               |
| 2 | Avance 2: EDA & Feature Engineering y código simple        | 16/Mayo     | Notebooks de EDA & FE               |
| 3 | Avance 3: Revisión y Perfilamiento y paralelización        | 21/Mayo     | Notebooks del funcionamiento        |
| 4 | Avance 4: Reporte final                                    | 22/Mayo     | PDF Reporte final & Notebooks       |
| 5 | Presentación del proyecto                                  | Examen Final| Notebook Reporte Final y explicación|

## Docker

* [x] Con Jupyter
* [ ] Sin Jupyter

## AWS

¿Cluster o EC2-->S3-->RDS?

## Reporte final

¿qué espera ver?
