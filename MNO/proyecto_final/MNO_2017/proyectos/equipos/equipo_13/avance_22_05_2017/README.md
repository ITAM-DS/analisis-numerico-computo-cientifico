# Avance_22_05_2017

## Trabajo:

### Individual

#### Ollin:
Comencé la implementación en CUDA del algoritmo pero me he encontrado con algunos problemas para hacer la correcta importación de las estructuras del Host al Device, ya realicé una paralelización con OpenMP pero resultó en un decremento en el performance del algoritmo como es posible observar en las siguientes capturas de pantalla:
![secuencial](https://github.com/ollin18/complex_network_c/blob/master/Capturas/secuencial_nbm_sin_imp_pantalla.png)
![openmp](https://github.com/ollin18/complex_network_c/blob/master/Capturas/openmp_2workers_nbm_ecos.png)

Lo primero que me vino a la mente fue [este](http://www.frankmcsherry.org/graph/scalability/cost/2015/01/15/COST.html) blog que leí a principios de año donde se menciona que hay casos en los que algunos algoritmos de redes tienden a funcionar mejor en un sólo núcleo que en varios.

Dejo la liga al repositorio general donde se muestran los avances es los métodos.

[Repositorio](https://github.com/ollin18/complex_network_c/)

# Actualización
Actualizando las capturas de pantalla anteriores por el error en el nombre de la carpeta
![act_sec](https://github.com/ollin18/complex_network_c/blob/master/Capturas/actualizado_secuencial.png)
![2th](https://github.com/ollin18/complex_network_c/blob/master/Capturas/2threads.png)
![4th](https://github.com/ollin18/complex_network_c/blob/master/Capturas/4threads.png)
![6th](https://github.com/ollin18/complex_network_c/blob/master/Capturas/6threads.png)

# Actualización 2
Hice modificaciones a mi implementación en Julia para leer una red de formato gml por el STDIN y generar la matriz de Hashimoto. Vi que es sencilla de comprender pero no muy eficiente computacionalmente, está hecha secuencial y los resultados son los siguientes:

![julia](https://github.com/ollin18/complex_network_c/blob/master/Capturas/julia.png)

No es sorpresa que tardara tanto puesto que esa fue la razón por la cual propuse el proyecto.

Vemos que la red cambió (número de aristas), por eso también cambié la imagen de secuencial. 

Lo intenté para una red múcho más grande pero no alcanzó la memoria. También lo intenté con 7 y 8 threads pero mi compu no quiso.

#### Equipo:
Avanzamos en el trabajo escrito.
