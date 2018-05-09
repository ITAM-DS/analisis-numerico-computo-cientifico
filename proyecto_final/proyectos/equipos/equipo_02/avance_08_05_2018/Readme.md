# Proyecto Final: Factorización Cholesky
## Cómputo en paralelo.
## Objetivo: 
### Realizar una implementación de la factorización de cholesky en alguna de las tecnologías de cómputo distribuido o compartido visto en clase.

### Implementación de la factorización de Cholesky:

Hector:

Para el presente avance los esfuerzos se concentraron en revisar la implementación de matrices en C, utilizando como referencia las notas del curso y las recomendaciones para poder introducir matrices de mayor tamaño de una manera mas eficiente en el proceso como tener un mejor manejo de memoria.

Un punto importante es poder medir que tan eficiente es el proceso, por lo cual se revisaron diferentes maneras de medir el tiempo de ejecución para  las funciones en c, siendo algunos de los revisados:

- Incluir la librería strokec4, strokec5, strokec6, strokec7 
- Definir un struct par los datos que vamos a cargar: strokec8 struct\strokec5  timeval  init_time, end_time
- Utilizar la función gettimeofday \strokec7  para obtener el tiempo con precisión en el orden de .001 milisegundos.
- Medir la diferencia entre el tiempo de inicio y el de final para obtener el estimado.

Otro método es utilizando la función Clock:

- incluir la librería \strokec4 #include\strokec5  \strokec6 <time.h>\strokec5 
\strokec7 
- Utilizar clock_t start = clock(); para tomar el tiempo de inicio.
- Utilizar clock_t end = clock(); para tomar el tiempo de finalizaci\'f3n de la función.
- Medir la diferencia entre los tiempos de inicio y final.

Un método que también se puede utilizar cuando compilamos en Linux es aprovechando \strokec9 gprof:

- Agregar el indicador -pg en la compilación y en la ejecución del programa
- Ejecutar el \strokec7
- Hacer el llamado a gprof 'nombre del ejecutabla
- Se despliega una serie de mediciones 



Alejandro:

Utilizando las referencias de entregas anteriores y combinándola con consultas prácticas de foros en internet, se consiguió la implementación del algoritmo secuencial (3 for anidados) del algoritmo de la factorización cholesky.

Para poder dar énfasis en el trabajo y no perder tiempo en particularidades se utilizó un muy rápido y pequeño script en python para generar matrices simétricas positivas definidas y almacenarlas en un archivo .txt con los elementos ordenados de forma secuencial.

Este algoritmo recibirá la dimensión deseada de la matriz a generar con elementos aleatorios, pero asegurándose de cumplir con la condición de positividad y simetría para poder ser posible la factorización, esto mediante la generación de una matriz triangular de números aleatorios y posteriormente haciendo una multiplicación matricial de esta última por su transpuesta.

Se modificó la entrega del algoritmo de factrorización Cholesky de entregas anteriores para que en lugar de tener ejemplos pequeños directamente especificados dentro del script, el algoritmo en C pudiera recibir como standar input el .txt generado por el algoritmo auxiliar en python.

En la carpeta implementación se encontrará un ejemplo de la generación y factorización de una matris simétrica positiva definida de dimensión 50 x 50. Los archivos donde se encontrarán los resultados serán:
 - MATRIX.txt para encontrar la matriz de referencia.
 - matrizSPD.txt donde estará la misma matriz, aunque con sus elementos almacenados en una sola columna para ser ingresados de esta forma secuencialmente al algoritmo ```chol.out``
 - fact.txt donde se encontrará la matriz triangular que factoriza a la matriz generada inicialmente.

 Los pasos siguientes serán:
  - La implementación del generador de matrices positivas definidas en un algoritmo en C.
  - La integración del filtro de Kalman, la función de verosimilitud normal y el algoritmo de optimización para completar el ejercicio.
  - Tiempo de ejecución.
  - Repetición del proceso con una implementación en OpenMP.

  Referencias:
  - [https://en.wikipedia.org/wiki/C_mathematical_functions]
  - [https://www.tutorialspoint.com/c_standard_library/c_function_calloc.htm]
  - [https://www.tutorialspoint.com/cprogramming/c_return_arrays_from_function.htm]
  - [https://stackoverflow.com/questions/19752644/row-to-column-and-column-to-row-using-awk]

Uriel:

La implementación del script del avance anterior dio a la tarea de comparar resultados con diferentes procesos ya ejecutados, por lo cual en este avance la dedicación fue a revisar la implementación secuencial de cholesky presentada en avances anteriores y comparar resultados con la implementación en paralelo, para ello se utilizaron:

1) Matriz de 3x3: 

Resultados, secuencial :
gcc -Wall source chol_sec.c -o chol_sec.out -lm
./chl_sec.out
Tiempo: 80.000000
	
Resultado, Paralelo:
gcc -Wall -fopenmp source/cholesky_1.c -o cholesky_1.out -lm
./cholesky_1.out
tiempo: 105.000000

2) Matriz de 5x5: 
Resultado, secuencial:
Tiempo: 83.000000\

Resultado, Paralelo:
tiempo: 326.000000

En estos resultados se observó un menor tiempo considerable en la ejecución secuencial. Esto puede deberse a diversos factores, entre los cuales se revisaron:
- Las matrices son muy pequeñas y los cálculos no son significativos, por lo cual consume mas tiempo el código adicional y el algoritmo para ejecutar en paralelo y por tanto, en implementaciones de matrices mucho mayores se podrá observar la diferencia.
- El proceso presenta cache miss debido a la forma en que se lee la información y por tanto genera un mayor tiempo de ejecución.
- Existen líeas de código innecesarias que provocan tiempos muertos o retrocesos.





Equipo:

En esta fase el equipo se dedicó a la implementación práctica en C así como revisión y corrección de errores del algoritmo desarrollado en entregas anteriores.


El trabajo escrito también cooperativo está [aquí](https://docs.google.com/document/d/1rZKXnf_56cQ0r0dyJ_M_H3khKhs_tSdgW3_IPnS2EfI/edit)

En la carpeta [Referencias](https://www.dropbox.com/home/Cholesky-Theory) tenemos los artículos escritos.