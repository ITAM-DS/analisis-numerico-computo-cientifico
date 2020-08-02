# Tarea 6


Dirígite a la rama de master a la ruta [analisis-numerico-computo-cientifico/C/BLAS/ejemplos/](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/BLAS/ejemplos).

1) Investiga\* sobre la subrutina de Fortran `dgemv` (parámetros que recibe y la salida). 

2) En la carpeta [analisis-numerico-computo-cientifico/C/BLAS/ejemplos/level2/](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/BLAS/ejemplos/level2) ejecuta el programa `dgemv_mult_mat_vec.c` y realiza pruebas con diferentes matrices y vectores definidos por ti.

3) Haz un programa que utilice la subrutina `dger` de Fortran.

4) Después de haber estudiado  y entendido los archivos de `definiciones.h` y `funciones.c` y realizado los puntos anteriores y la tarea 5 responde: ¿cómo fue que pudimos llamar a las rutinas de Fortran (que almacena en una forma column-major order los arreglos de dos dimensiones) para operaciones con arreglos 2-dimensionales sin haber instalado CBLAS, si en clase se dijo que almacenar arreglos de dos dimensiones en C es en un row-major order? 

5) Investiga\* sobre la subrutina de Fortran `dgemm` (parámetros que recibe y la salida).

6) En la carpeta [analisis-numerico-computo-cientifico/C/BLAS/ejemplos/level3/](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/BLAS/ejemplos/level3) ejecuta el programa `dgemm_mult_mat.c` y realiza pruebas con diferentes matrices definidas por ti.

7) En la carpeta del punto anterior encuentras la sección **Multiplicación matriz-matriz con trick**. Ejecuta el programa de esta sección con diferentes matrices definidas por ti y resuelve la pregunta **¿por qué funciona este trick?**.

8) Haz un programa que utilice la subrutina `dsymm` de Fortran.


**\*Para sus investigaciones utilicen las referencias de los README's:**

[analisis-numerico-computo-cientifico/C/BLAS/](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/BLAS)

[analisis-numerico-computo-cientifico/C/LAPACK/](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/LAPACK)

**La tarea se hace de forma individual y personal.**
