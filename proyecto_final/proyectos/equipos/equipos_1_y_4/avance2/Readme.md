
Ruta óptima para los colaboradores de la fuerza de ventas
==============================

### Milestone 2. Fin: 19 de mayo de 2020

El objetivo principal del milestone fue construir la solución end to end para encontrar la ruta de los colaboradores de la fuerza de ventas. Para lograrlo, se llevaron a cabo las siguientes actividades: 

1. Creación de base de datos con tablas finales. El [código](https://github.com/lauragmz/proyecto-final-mno2020/tree/master/src/sql) se puede consultar en el repositorio del equipo. 

2. Diseño y primera iteración del pipeline

3. Diseño y primera iteración del dashboard

En un inicio se había planeado realizar la paralización de las rutas en ambos algoritmos. Sin embargo, por la forma en la que está implementada la función de Simulated Annelaning de Python esto no fue posible. 


El detalle de las actividades realizadas por cada integrante del equipo se muestran a continuación:

+**Diego:** integración y documentación de diversas funciones en el archivo [Utilería](https://github.com/lauragmz/analisis-numerico-computo-cientifico/blob/mno-2020-1/proyecto_final/proyectos/equipos/equipos_1_y_4/avance2/codigo/Utileria.py). En este avance, se integra la versión actualizada

+**Lau:** construcción de la clase [Particle Swarm](https://github.com/lauragmz/analisis-numerico-computo-cientifico/blob/mno-2020-1/proyecto_final/proyectos/equipos/equipos_1_y_4/avance2/codigo/particle_swarm.py). Trabaja en la paralelización del algoritmo de Particle Swarm y en la segunda iteración del gridsearch. 

+**Marco:** diseño y primera iteración del pipeline de la solución. Creación de tablas finales para el algoritmo. Trabaja en la paralelización del algoritmo de Particle Swarm y en la segunda iteración del gridsearch.

+**Pao:** Corrección de estilos de Utileria.py, separación de la función de visualización para integración con el dashboard. Diseño y primera iteración del dashboard. 

+**Miguel:** homologación de scripts para base de datos y construcción de la clase [Simulated Annealing](https://github.com/lauragmz/analisis-numerico-computo-cientifico/blob/mno-2020-1/proyecto_final/proyectos/equipos/equipos_1_y_4/avance2/codigo/simulated_annealing.py)

+**Ana:** creación de archivos plano con nodos, latitud y longitud y construcción de funciones para la transformación de los datos de salida y visualización de las rutas en un mapa. 

Siguientes pasos:  

+ Pruebas de los algoritmos
+ Ejecución de algoritmo de Particle Swarm en paralelo y Simulated Annealing secuencial para todas las rutas
+ Reporte para entrega del 22 de mayo

