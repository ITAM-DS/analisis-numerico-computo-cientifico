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

#### Equipo:
Avanzamos en el trabajo escrito.
