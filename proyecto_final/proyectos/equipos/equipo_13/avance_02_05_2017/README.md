# Avance_02_05_2017

## Trabajo:

### Individual

#### Ollin:
Creé un repositorio en github con el código que mostré en el avance de la semana pasada para poder tener un mejor control de versiones y poder reutilizar todo en trabajos futuros.

También probé que mi código de la semana pasada tenía muchas fallas y no compilaba, pero logré hacer que sí funcionara hace tan sólo unos segundos. Como es posible ver desde la semana pasada, todo está escrito como librerías para fines de reutilización del código en el futuro.

Para probar que el programa funcionara (o al menos las cosas que nos interesan como la lectura de nodos y aristas, aunque también hice pruebas de los grados que no reporto) hice un programita que me imprime el número de nodos y aristas de las redes que se utilizan de entrada. Se utilizaron las redes:
* Los Miserables
* Dolphins
* Zachary Karate Club
* Football NCAA

Las cuales fueron obtenidas del [UCI Network Data Repository](https://networkdata.ics.uci.edu/index.php)

Las pruebas del código se muestran a continuación:
![redes](https://github.com/ollin18/complex_network_c/blob/master/redes.png)

De conocimiento previo al estudiar las redes, los resultados son los que esperábamos.

Aún falta ordenar el repositorio pero es el siguiente:
* [Repositorio](https://github.com/ollin18/complex_network_c)

#### Isabel  

Al revisar el código que Ollin subió, encontré secciones del código que tendrían gran ventaja de ser paralelizados. Al paralelizar tendremos como ventaja aumentar la eficiencia de nuestro código y de esta forma, aprovechar las herramientas vistas en clase. Hay tres formas de paralelizar el código, por nodos, por aristas o por el método llamado "work-efficient method", el cual encontré en la literatura que es el mejor. También encontré que existen otras técnicas más avanzadas como la "hybrid parallelization techniques" pero son muy complicadas y para el código que tenemos, es suficiente paralelizarla de cualquiera de las otras formas.  

#### Raúl

En conjunto con Isabel identificamos varias regiones del código que pueden ser paralelizable, particularmente aquellas que mueven información hacia la matriz y entre esta y el resultado que buscamos obtener.   


### Equipo
Ahora que ya tenemos una estructura de red hemos pensado en la forma en la que construiremos la matriz ya más en forma, teniendo en cuenta el código de **Julia** puesto anteriormente pero con las consideraciones del computo en tarjetas gráficas.
