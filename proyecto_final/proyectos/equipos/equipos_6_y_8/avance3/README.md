# Tercer avance del proyecto de Métodos Numéricos y Optimización

**Profesor:** Erick Palacios Moreno

**Lenguaje a utilizar:** Python

## Asignación de tareas por persona y por rol

* Rafael Ortega  

  * Creación e implementación de Docker en el proyecto: Se realizó el Dockerfile para poder utilizar Docker en el proyecto.
  * Se organiza una reunión para verificar dónde estamos en este momento, y a dónde vamos en los siguientes pasos del proyecto.
  * Implementación de una instancia en EC2 para realizar la paralelización del algoritmo.
  * Meter las componentes a la regresión  
  * Documentación de algoritmos.

* Elizabeth Viveros

  * Implementación de pruebas unitarias sobre SVD y PCA: Prueba unitaria sobre el algoritmo de SVD y PCA para verificar si está correcto.
  * Notebook de muestra del algoritmo de PCA sobre los datos
  * Obtener eigenvalores de la matriz
  * Obtener los componentes
  * Hacer dinámica la obtención del número de componentes
  * Incorporar en el reporte la explicación del algoritmo de PCA implementado por la paquetería sklearn  

* Leonardo Marín

  * Paralelización del algoritmo de PCA from SVD.  
  * Funciones para calcular PCA utilizando SVD en segunda versión directo con jacobi.
  * Hacer dinámica la obtención del número de componentes.

* Mario Rodríguez  
  * Perfilamiento de las funciones que ya tenemos y buscar forma de optimizarlas.  
  * Perfilamiento.
  * Se modificó el EDA para que refleje variables representativas con el modelo.
  * Modificación de las funciones de limpieza para mejorarlas.
  * Revisión de los resultados obtenidos con el PCA de Eli Viveros.

* Elizabeth Rodríguez
  * Revisión del algoritmo de SVD y PCA  
  * calcular PCA utilizando SVD en segunda versión directo con jacobi  
  * Tabla con resumen de los 3 algoritmos para el reporte
  * Validación de errores entre los 3 algoritmos, comparara diferencias.
  * Revisión de los resultados obtenidos con el PCA de Eli Viveros.

* Karla Alfaro
  * Incorporar en el reporte la explicación del algoritmo de PCA implementado por la paquetería sklearn --> Elizabeth Viveros
  * Reporte Final --> Karla Alfaro.

    * Introducción
    * Datos y contexto
    * EDA en el reporte --> Mario Rodríguez y Karla Alfaro
    * Problemas de multicolinealidad y dimensión alta
    * Teoría del análisis de componentes principales

## Fechas

| # | Milestone/avance                                           | Fecha       | Entregable                          |
|---|------------------------------------------------------------|-------------|-------------------------------------|
| 1 | Avance 1:Selección de BD, lenguaje, tema, roles            | 25/Abril    | README.md en Avance_1               |
| 2 | Avance 2: EDA & Feature Engineering y código simple        | 16/Mayo     | Notebooks de EDA & FE               |
| 3 | Avance 3: Revisión y Perfilamiento y paralelización        | 21/Mayo     | Notebooks del funcionamiento        |
| 4 | Avance 4: Reporte final                                    | 22/Mayo     | PDF Reporte final & Notebooks       |
| 5 | Presentación del proyecto                                  | Examen Final| Notebook Reporte Final y explicación|

## Por realizar

* [ ] Paralelización del algoritmo. (en proceso)
* [ ] Montarlo en una instancia de Amazon Web Services para intentar paralelizarlo.(en proceso)
* [x] Subir el documento de docker para su uso en las instancias y por el equipo.
* [x] Finalizar el reporte final para entregar.
* [ ] Realizar perfilamiento del algoritmo. (en proceso)
* [x] Revisar y hacer más pruebas a los algoritmos realizados.
* [x] Mejorar documentación.
