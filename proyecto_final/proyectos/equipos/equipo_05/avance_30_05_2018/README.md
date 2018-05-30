## Equipo 05

Integrantes:

* Miguel

* Francisco

Título del proyecto: `Balanceo de Línea`

Objetivo del proyecto: `Encontrar la distribución óptima de las actividades requeridas para elaborar un producto entre cierto número de estaciones, minimizando el tiempo de ciclo y cumpliendo con las restricciones establecidas.`

En la carpeta [avance_30_05_2018](avance_30_05_2018) se encuentra el reporte.


1. Se terminó la documentación del parallel Mixer. Se eliminaron todos los 
   breakpoints y prints para debugging.

2. Se intentó correr sin éxito el problema Lutz de 32 estaciones, así como el sawyer, de 30, el número de tablas llenó la memoria del servidor. No así la del GPU gracias al sistema de batches en la función runTest.
Se sugiere/sospecha que escribir a disco podría ser una opción. 

3. Se escribió el reporte final así como cambios a la presentación. La liga al reporte es [Reporte final](Soluciones_al_problema_BLP.docx)

4. La descripción general de la ejecución del código se encuentra en [liga_descripcion](descripcion_codigo.md)

Notas: Se agregó también al folder el código del [main_secuencial](main_secuencial.cpp), [main_paralelo](main_paralelo.cpp) y el kernel de cuda.


Miguel: 

Puntos 1,3

Paco:

Puntos 1,2,3

