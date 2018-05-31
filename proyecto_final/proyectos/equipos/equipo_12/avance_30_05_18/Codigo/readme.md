En esta carpeta encontramos los códigos utilizados para las diferentes partes del proyecto.

Generadores_no paralelos:
- metodo_congruencial.c  Implementación del método congruencial en c
- random_MT.c  Implementación del método Mersenne Twister en c

Generadores_paralelos:
Este código está implementado en un sevvidor de AWS tipo p2.xlarge que se configuró de acuerdo a la [guia](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/extensiones_a_C/CUDA/instalacion) vista en clase.
Los dos programas son implementaciones de cuRAND, el generador de números aleatorios de CUDA que viene en el toolkit.

- rand_parallel.cu Implementación de método congruencial en CUDA
- mt_parallel.cu Implementación del método Marsenne Twister en CUDA

Pruebas:
Código generado para la implementación de pruebas tal como cálculo de frecuencia, pruebas de NIST y cambio de números a binarios para poder ejecutar las pruebas.

- DecimalToBinary.c hace el cambio de núumeros a decimales para implementar pruebas
- frecuency.c 
- rand.sh

Aplicaciones:
Código en el que se usan las cadenas en la resolución de problemas reales, en particular el cálculo del área de un círculo.

-Aplicaciones.rmd Calculo del área de un circulo y medición del error de este cálculo

-A