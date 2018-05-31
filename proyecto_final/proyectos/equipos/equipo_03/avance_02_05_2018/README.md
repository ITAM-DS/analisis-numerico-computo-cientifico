# Avance 02/05/2018

## Integrantes:

* Diego Alejandro Estrada Rivera    

* Rafael Larrazolo de la Cruz       

* Victor Quintero Mármol González   

## Título del proyecto: Factorización de Matriz usando factorización QR

### Individual

Diego: 

Para el avance de esta semana, debido a que ya habíamos logrado implementar los métodos Gram-Schmidt y Householder en c, decidí implementar el único que nos hacía falta, las rotaciones de Givens. El  [link](https://www.dropbox.com/s/mzrnq3jsfyhhwjo/Givens.pdf?dl=0) que nos había compartido previamente Rafael fue especialmente útil, ya que describe el proceso detalladamente paso por paso, mostrando las rotaciones que se van generando y como se van convirtiendo en 0's a los elementos que están debajo de la diagonal. Agrego un  [link](https://www.dropbox.com/s/qrdrv6ret1y5h4f/givens.c?dl=0) al código implementado en c, así como unas [pruebas](https://www.dropbox.com/s/6g95v0xyx5891cc/pruebasQRconGivens.txt?dl=0) realizadas con el mismo, estás fueron tomadas de ejemplos ya resueltos que hemos visto en referencias pasadas, pero también se comprobó a mano que los resultados fueran satisfactorios. El código y las pruebas también las subiremos al repo. Como una primera impresión tras realizar este código y el de Gram-Schmidt, siento que utilizar OpenMP traería ventajas fáciles de implementar, como la directiva for.  

Rafael:

En este avance me dediqué a comenzar con el trabajo escrito. La idea general de este avance, antes de darle una carátula o temas de presentación, fue plantear el marco teórico de los métodos que investigamos para la factorización QR (Gram-Schmidt, Householder y Givens) tratando de conjuntar la información más relevante que encontramos tanto en la teoría que está en el repo, como de las referencias que leímos. De igual modo, me pareció pertinente incluir un pequeño ejemplo de cómo funcionan cada uno de estos métodos, los cuales sirven para entender la operatividad de los mismos e ilustrar las diferencias en cada uno. Para el próximo avance, continuando con el trabajo escrito, la idea sería complementar o "pulir" lo logrado en este avance y, principalmente, incluir los algoritmos de estos métodos planteando un pseudocódigo e incluso comenzar a hablar de éstos en un ambiente en paralelo para poder comenzar a incorporar las implementaciones que hemos podido realizar. [Trabajo escrito](https://www.dropbox.com/s/d2gkj7jc06d7mzn/trabajo_escrito.pdf?dl=0)

Victor:

Para este avance continue leyendo sobre ScaLapak, en especial sobre la función *pdgeqrf* que sirve para hacer factorización QR en paralelo. Platiqué con el equipo para decidir que camino ibamos a seguir y si veíamos conveniente que empezara a desarrollar un script en ScaLapack o mejor enfocarme ya en otro modelo que consideráramos el final. Decidimos que sería mejor enfocarnos en paralelizar Givens con OpenMP, por lo que volví a leer la [teoría de OpenMP](https://www.dropbox.com/s/vcxbrqkk6x946d7/2.4.Sistemas_de_memoria_compartida_openMP.pdf?dl=0) que vimos en el curso y realicé nuevamente los [ejemplos](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/extensiones_a_C/openMP/ejemplos) vistos en clase. Finalmente, después de implementar la factorización QR en C por el método de rotaciones de Givens, Diego me sugirió que un buen primer acercamiento a paralelizar sería una parte del código donde se copian matrices, por lo que implementé [un programa](https://www.dropbox.com/s/35mvewj8l113qmo/copia_matriz.c?dl=0) con OpenMP que hace en paralelo una copia de una matriz usando *pragma omp parallel for*. El archivo en C y una muestra de la corrida se subirán al repositorio. El siguiente paso sería implementar ese código al de Diego de rotaciones de Givens.


### Equipo  

Dados los tres métodos que hemos visto, así como nuestra experiencia implementándolos de manera secuencial, hemos decidido, a partir del siguiente avance, enfocarnos en implementar el método de rotaciones de Givens utilizando OpenMP. Se decidió optar por OpenMP tras ver su versatilidad en el ejemplo que realizó Victor, pensado como un primer paso a implementar Givens. Para el siguiente avance en concreto, implementaremos el copiado de matriz en el código de Givens, y a partir de allí veremos más opciones para paralelizar el código.  



