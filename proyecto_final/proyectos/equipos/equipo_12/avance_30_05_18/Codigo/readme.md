En esta carpeta encontramos los códigos utilizados para las diferentes partes del proyecto.

[Generadores_no paralelos:](https://github.com/oliab/analisis-numerico-computo-cientifico/tree/mno-2018-1/proyecto_final/proyectos/equipos/equipo_12/avance_30_05_18/Codigo/Generadores_no_paralelos)  

Estos generadores se crearon en el contendor de docjer que se hizo siguiendo las instrucciones de la [primer clase de c](https://www.dropbox.com/s/2btpracfm4munik/historia_clase1.txt?dl=0)

Para poder compilar usamos el comando:
nvcc random_MT.c  -o random_MT.out

Para correr utilizamos
./random_MT.out > salida1.txt

- metodo_congruencial.c  Implementación del método congruencial en c
- random_MT.c  Implementación del método Mersenne Twister en c

[Generadores_paralelos:](https://github.com/oliab/analisis-numerico-computo-cientifico/tree/mno-2018-1/proyecto_final/proyectos/equipos/equipo_12/avance_30_05_18/Codigo/Generadores_paralelos)  

Este código está implementado en un sevvidor de AWS tipo p2.xlarge que se configuró de acuerdo a la [guia](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/extensiones_a_C/CUDA/instalacion) vista en clase.  
Los dos programas son implementaciones de cuRAND, el generador de números aleatorios de CUDA que viene en el toolkit.  

El compendio de cadenas generadas se encuentra [aqui](https://drive.google.com/open?id=160P8Rv0qCESNVFGC8hHb2SAVGL0gzdrmGLv7gWLbAbY) y son los que se utilizaron para generar las aplicaciones y las pruebas o en cada carpeta hay une ejemplo de los outputs de cada algoritmo.

Para poder compilar usamos el comando:
nvcc rand_parallel.cu -o rand_parallel.out  
  
Para correr utilizamos
./rand_parallel.out  

- rand_parallel.cu Implementación de método congruencial en CUDA  
- mt_parallel.cu Implementación del método Marsenne Twister en CUDA  

[Pruebas:](https://github.com/oliab/analisis-numerico-computo-cientifico/tree/mno-2018-1/proyecto_final/proyectos/equipos/equipo_12/avance_30_05_18/Codigo/Pruebas)

Código generado para la implementación de pruebas tal como cálculo de frecuencia, pruebas de NIST y cambio de números a binarios para poder ejecutar las pruebas.
Para compilar los scripts es necesario ejecutar los siguientes comandos

gcc DecimalToBinary.c -o DecimalToBinary.out -lm
gcc CongruencialRand.c -o CongruencialRand.out -lm
gcc ToBinary.c -o ToBinary.out -lm

Una vez compilados, se procede a explicar la ejecución de cada archivo:

AL ejecutar el código
./DecimalToBinary.out >> datos/set_bin1.txt
se obtiene un archivo con una seríe de número aleatorios en formato binario. Por default la seríe es de 1,000 números pero es posible modificar el Script DecimalToBinary.c y modificar el tamaño de la seríe o los parámetros del método congruencial.


AL ejecutar el código
./CongruencialRand.out >> datos/set2.txt
se obtiene un archivo con una seríe de número aleatorios en formato decimal. Por default la seríe es de 1,000 números pero es posible modificar el Script CongruencialRand.c.c y modificar el tamaño de la seríe o los parámetros del método congruencial.


AL ejecutar el código
./ToBinary.out < set2.txt >> datos/set_bin2.txt
se procede a convertir la seríe de número aleatorios del archivo set2.txt a formato binario y lo guarda en el archivo set_bin2.txt.

De esta forma es posible obtener series binarias directamente para probar su aleatoriedad, generar series de números para su uso/aplicación, o convertir seríes generadas por otros programas para probar su aleatoreidad.


Para ejecutar las pruebas del NIST, es necesario instalar el programa de acuerdo al instructivo del NIST que está en las referncias y ejecutar el comando
./assess 1000
donde 1000 indica la longitud de la cadena a evaluar.
Una vez, se van seleccionando las opciones deseado. En nuestro caso las opcines son:
Para deicr que se van a leer los datos de un archivo
0

Para indicar la ubicacion del archivo
"ubicacion_del_archivo/nombre del archivo"

PAra indicar que aplique todas las pruebas
1

No se modifican los parametros iniciales de las pruebas
0

El número de repeticiones que se ahcen a las pruebas
10

Que el archivo es en formato ASCII de ceros y unos
0

[Aplicaciones:](https://github.com/oliab/analisis-numerico-computo-cientifico/tree/mno-2018-1/proyecto_final/proyectos/equipos/equipo_12/avance_30_05_18/Codigo/Aplicaciones)  

Código en el que se usan las cadenas en la resolución de problemas reales, en particular el cálculo del área de un círculo.

El código es un RMD que puede ser ejecutado en una terminal de R o en RStudio. Utiliza como insumos el archivo .xlsx Cadenas, el cual contiene un compendio de las cadenas que fueron generadas por los diferentes algoritmos.


-Aplicaciones.rmd Calculo del área de un circulo y medición del error de este cálculo

