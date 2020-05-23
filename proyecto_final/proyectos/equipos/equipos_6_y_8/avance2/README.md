# Segundo avance del proyecto de Métodos Numéricos y Optimización

**Profesor:** Erick Palacios Moreno

**Lenguaje a utilizar:** Python

## Asignación de tareas por persona y por rol  

* Rafael Ortega
  * Tareas de búsqueda y organización, responsable: Rafael Ortega.
    Se realizó la búsqueda de posibles bases de datos, así como información correspondiente a los algoritmos de  
    optimización a ser vistos en clase.
  * Por otro lado, se organizó una reunión para la asignación de roles y la creación de los milestones y proyectos en github, para la organización del proyecto.
  * Limpieza, EDA y exploración de los datos

* Karla Alfaro Pizaña:  
  * Limpieza de la base de datos: Se elaboró el script para la limpieza de la base de datos y la preparación de los mismos para su uso en el desarrollo e implementación de algoritmos de PCA, EDA y Feature Engineering.
  * Feature engineering, responsable: Karla Alfaro.  
Se realizó el feature engineering de la base de datos, así como la revisión de los pasos anteriores debido al amplio conocimiento de la misma.  
  * Feature Selection, responsable: Karla Alfaro. Se hizo un OLS para intentar buscar variables que pudieran ser no significativas en el modelo,
pues el objetivo está relacionado con la reducción de dimensionalidad. Se obtuvieron los p-values de todas las variables y se encontró que  
prácticamente la mayoría tienen una significacia alta, por lo que se justifica el uso de PCA para la reducción de dimensionalidad.

* Mario Rodríguez:
  * EDA: Se realizó un análisis exploratorio de datos para encontrar y ver de mejor manera posibles relaciones en los datos que puedan ser utilizados para hacer el feature engineering correspondiente.
  * Revisión de los algoritmos de limpieza: Se mejoraron algunas funciones para el procesamiento de los datos, corrección de algunos errores.

* Elizabeth Viveros:  
  * Implementación del algoritmo con scikit-learn y con SVD sobre nuestros datos

* Leonardo Marín:
  * Primera prueba con jacobi y comparación de resultados contra los obtenidos con scikit-learn y con SVD

* Elizabeth Rodríguez
  * Documentación e información del algoritmo: Búsqueda de información sobre PCA para su aplicación en el algoritmo.
  * Revisión, documentación y apoyo con algoritmos: Revisión del algoritmo de jacobi, SVD y scikit-learn, documentación de los algoritmos y revisión.

## Fechas

| # | Milestone/avance                                           | Fecha       | Entregable                          |
|---|------------------------------------------------------------|-------------|-------------------------------------|
| 1 | Avance 1:Selección de BD, lenguaje, tema, roles            | 25/Abril    | README.md en Avance_1               |
| 2 | Avance 2: EDA & Feature Engineering y código simple        | 16/Mayo     | Notebooks de EDA & FE               |
| 3 | Avance 3: Revisión y Perfilamiento y paralelización        | 21/Mayo     | Notebooks del funcionamiento        |
| 4 | Avance 4: Reporte final                                    | 22/Mayo     | PDF Reporte final & Notebooks       |
| 5 | Presentación del proyecto                                  | Examen Final| Notebook Reporte Final y explicación|

## Por realizar

* Paralelización del algoritmo.
* Montarlo en una instancia de Amazon Web Services para intentar paralelizarlo.
* Subir el documento de docker para su uso en las instancias y por el equipo.
* Finalizar el reporte final para entregar.
* Realizar perfilamiento del algoritmo.
* Revisar y hacer más pruebas a los algoritmos realizados.
* Mejorar documentación.
