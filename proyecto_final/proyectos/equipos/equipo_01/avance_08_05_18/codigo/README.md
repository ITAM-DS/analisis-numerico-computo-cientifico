

## 1. Implementación del programa de Descenso en Gradiente Estocástico en CUDA

Se implementó el programa de SGD en CUDA, basándonos en el programa que teníamos en secuencial. Se utilizó la librería de cuBLAS.

Para compilar el programa se ejecuta la siguiente instrucción en la consola (necesario tener una máquina con GPU NVIDIA y el CUDA Toolkit instalado):  
  
`nvcc SGD_cuda.c funciones.c -o programa.out -lcublas`

La ejecución del programa se hace de la siguiente forma:  

`./programa.out <renglones_entrenamiento> <columnas_entrenamiento> <renglones_validación> <tamaño_del_batch> <iteraciones> <-tasa_aprendizaje>`
  
Para verificar si la ejecución en CUDA proporcionaba mejoras significativas en el tiempo que toman los cálculos en comparación con el modelo secuencial se ejecutaron ambos programas con las mismas instucciones. A continuación se muestran los resultados:  

**Ejecución en Secuencial**  

![Ejecucion en Secuencial](ejecucion_secuencial.png)  

**Ejecución en CUDA**  

![Ejecucion en CUDA](ejecucion_cuda.png)  

Podemos observar que para 100 iteraciones el programa en CUDA tardó 50% menos tiempo que en secuencial (30 segundos vs 57 segundos). Parte de este tiempo consiste en cargar los datos a memoria, que es equivalente para ambos programas. Sin embargo, si comparamos el tiempo de cada iteración, que depende casi exclusivamente del procesamiento en GPU vs CPU vemos que fue casi 80% menor en la GPU que en CPU. Por lo tanto, a mayor número de ejecuciones. El código de la implementación en CUDA encuentra en esta misma carpeta.

Para la siguiente semana se hará la implementación de los otros algorítmos (ADAM, AMSGrad) en CUDA y se ejecutarán los grids para comparar los modelos de forma 'justa'.


## 2. Visualización de los errores de SGD en secuencial

Para realizar pruebas con distintos parametros trabajaremos con los datos de *flights* que han sido procesados como hemos detallado en el avance de la semana pasada.

En caso de que aún no tengamos los datos debemos correr el siguiente comando en la terminal, el cual se encarga de descargar los datos de flights, limpiarlos y separar en set de entrenamiento y prueba:
```
./preproc_flights.sh
```

Compilamos el programa

```
gcc -Wall sgd.c funciones.c -o programa.out -lblas -lm
```

Ejecutamos el programa, los parámetro que deben asignarse son

```
./programa.out <renglones_entrenamiento> <columnas_entrenamiento> <renglones_validación> <tamaño_del_batch> <iteraciones> <-tasa_aprendizaje>
```

Por ejemplo:

```
./programa.out 3999805 39 1714203 65536 500 -0.000001
```

Una vez que se termino de ejecutar, debemos tener 2 archivos csv con resultados (error_sgd_sec.csv) y el resumen (error_sgd_sec_summary.csv). Estos archivos son inputs para una gráfica que se genera con R para lo cual se debe correr el siguiente comando en la terminal

```
chmod +x visualiza_result.sh
./visualiza_result.sh
```

Lo anterior genera una gráfica realizada con R.

