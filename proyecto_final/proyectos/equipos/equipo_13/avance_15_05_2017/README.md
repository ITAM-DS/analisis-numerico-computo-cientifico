# Avance_15_05_2017

## Trabajo:

### Individual

#### Ollin:
Terminé la implementación de la matriz NBM que me causó muchos problemas, pues me llevó varios días pensar en cómo podría hacerlo aunque al final lo hice de una forma muy directa que se puede seguir de las referencias. Por el momento es secuencial. Hice que al correr el resultado el programa siga imprimiendo la información de la red como el número de nodos y aristas pero esto al stderr para que al guardar la matriz a un archivo no tengamos que limpiar esas líneas pero sí las tengamos presentes.

[Repositorio](https://github.com/ollin18/complex_network_c/NBM)


#### Equipo:
Estudiamos la forma en la que sea posible paralelizar el algoritmo. Vemos que es computacionalmente muy demandante pues tiene una complejidad algorítmica del cuadrado del número de aristas al tener 4 *for loops* anidados, por lo que sí en **muy** conveniente paralelizar.
