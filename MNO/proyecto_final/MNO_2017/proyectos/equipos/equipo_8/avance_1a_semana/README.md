En esta ocasión lleve a cabo un análisis minucioso del algoritmo de Cholesky secuencial para tratar de determinar ciertos patrones que nos permitan desarrollar un algoritmo paralelo del mismo.
De lo que me dí cuenta fue que el algoritmo divide los cálculos por columnas y en una iteración va calculando todos los valores de cada columna (una por vez) de los valores finales calculados de la primer columna, luego de la segunda, luego de la tercera, etc. y esto me permite encontrar un primer patrón paralelizable (aunque existe dependencia en el orden de las columnas).
Un problema que surge es el mapeo de la malla de threads hacia las componentes de la matriz. En este caso no existe un patrón claro. Por esta razón y por la de optimizar la memoria opté por guardar la matriz en un arreglo unidimensional. Con esto evito guardar ceros que no uso en los cálculos y optimizo la memoria.
Al llevar a cabo lo anterior, debemos de transformar todo el algoritmo para mapearlo con las nuevas posiciones de las componentes. En eso estamos trabajando ahora.
Por otro lado, para hacer la factorización Cholesky se necesita una matriz simétrica y poisitiva definida. Tenemos que crearla. Para ello debemos implementar la multiplicación de matrices en paralelo, crear una función para implementar la transpuesta de una matriz y guardarla, posteriormente, en un arreglo unidimensional.
En las fotos muestro el trabajo final de mucho tiempo de análisis del algoritmo y muestro borradores para construir el algoritmo final. 


