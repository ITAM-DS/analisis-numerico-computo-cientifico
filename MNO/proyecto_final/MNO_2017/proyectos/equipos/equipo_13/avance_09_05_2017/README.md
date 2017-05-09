# Avance_09_05_2017

## Trabajo:

### Individual

#### Ollin:
Avancé en la implementación (hasta el momento secuencial) de la matriz. Lo que hice fue generar la matriz de adyacencias, esta es mucho más fácil de generar y también computacionalmente mucho menos costosa. Por el tamaño de las mismas, la única que puede verse bien al imprimirse en pantalla es la de Zachary porque es la de menor orden. A continuación se muestra:

![matriz](https://github.com/ollin18/complex_network_c/blob/master/matriz_ady.png)

También implementé la función de delta de Kronecker para que sea mucho más sencillo generar la matriz Nonbacktracking.

#### Raúl

En esta entrega generamos la estructura general del trabajo escrito. Sintetizamos la información que hasta la fecha hemos investigado, buscando plantear los conceptos basicos.

#### Isabel

Junto con Raúl recopile varios conceptos clave que podrían dar un mejor entendimiento del objetivo que buscamos alcanzar. Con ello, dimos una introducción a los sistemas complejos y la importancia de la teória de redes en su análisis.

### Equipo
Empezamos a desarrollar el trabajo escrito y recopilar todas las referencias realmente útiles para la misma.

Respondiendo a la pregunta que nos hiciste:
* Entonces respecto a la primera referencia que da Ollín, la idea es construir a la matriz B, correcto? en Julia es aquí donde se realiza esto:

```
adjacency_matrix(g)

```
?

**No realmente, revisando de nuevo el archivo que subí me doy cuenta que puse un archivo donde la matriz que vamos a implementar realmente no está. Lo que pasa es que está puesta una matriz que tiene las mismas eigenparejas que la de Hashimoto pero en lugar de ser 2 veces el número de aristas es de 2 veces el número de nodos que por lo general es mucho más pequeño. Voy a corregir la referencia de éste archivo para que la comparación sea más directa. Las otras matrices que están puestas ahí son las de los otros papers, las cuales salen directo una vez que tenemos generadas las primeras. Son padres por las propiedades espectrales que nos permiten hacer diferentes típos de análisis de comunidades en redes ralas**


