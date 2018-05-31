# Avance 24/04/2018

## Integrantes:

* Diego Alejandro Estrada Rivera    

* Rafael Larrazolo de la Cruz       

* Victor Quintero Mármol González   

## Título del proyecto: Factorización de Matriz usando factorización QR

### Individual

Diego: 

Para este avance me propuse a realizar una primera implementación de la factorización QR. Empecé por revisar las notas de cómputo matricial del repo, así como el capítulo 5 del libro Matrix Computations nuevamente, donde recuerdo venían desarrollados varios algoritmos para esta factorización. 
Siendo el primer tema que revisé el método Gram-Schmidt, decidí implementar este primero; al hacer esto y revisar futuras implementaciones de los otros 2 métodos (Householder y Givens), espero darme una mejor idea de como podríamos modificar dichas implementaciones para que los cálculos se realicen en paralelo. Específicamente, desarrollé el algoritmo que se encuentra en la página 231 y 232 del libro de Matrix Computations, el cual corresponde al método Gram-Schmidt modificado. Al hacer esto sin ayuda de ningún paquete, no espero que el algoritmo sea lo más eficiente en cuanto al uso de memoria, pero sin duda me sirvió como una excelente práctica, ya que ahora entiendo a la perfección el funcionamiento del método y tengo varias nociones acerca del órden en que se van realizando los cálculos y como se van actualizando las matrices Q y R a lo largo del proceso. Agrego un [link](https://www.dropbox.com/s/pac5jlzr0bxe82g/gs.c?dl=0) al código que desarrollé para el algoritmo del método Gram-Schmidt modificado.
Para verificar que el código realizara bien su labor, se ejecutaron varios [ejemplos](https://www.dropbox.com/s/remlqc96jqiajjw/pruebasQRconGS.txt?dl=0). En estos, se leía una matriz A, columna por columna, y se obtenían las correspondientes matrices Q y R de las cuales se verificaban la ortogonalidad y que las columnas de Q fueran ortonormales a mano, para cada caso; aunque la mayoría de estos ejemplos se basaron en ejemplos resueltos obtenidos de varios sitios. Para el siguiente avance espero empezar a indagar en cuanto al tema de la paralelización de alguna de las implementaciones. 


Rafael:

En este avance leí las notas del repositorio de la materia para la implementación de la factorización QR que, en terminos generales, es una síntesis de lo que hemos revisado en las referencias comentadas anteriormente. También encontré un [paper](https://www.dropbox.com/s/63jnve2udvu6oq3/tomasbaihernandez13.pdf?dl=0) bastante ilustrativo el cual sugiere un algoritmo para arquitecturas multinodo para realizar la factorización QR. En este paper se centran en el método de Householder y hacen permutaciones de las columnas de la matriz a factorizar, a esto le denominan *Column Pivoting* (QRP). De igual modo proponen un algortimo en OpenMP bajo la premisa mencionada. Se me ocurre para futuros avances utilizar este algoritmo, o basarnos en éste, para implementarlo y compararlo con la factorización QR que podemos encontrar en LAPACK. Por otra parte, en esta [referencia](https://www.dropbox.com/s/w5gwds8zk58x8z5/QRmulticore_architectures.pdf?dl=0) hablan de las rutinas para realizar la factorización en LAPACK; también presentan un algoritmo (que le denominan por tejas) para realizar la factorización. Por lo que entiendo, este algoritmo toma las matrices por bloque realizando operaciones iterativamente para reaizar la factorización indicada.

En cuestión del trabajo escrito, considero que con las referencias encontradas hasta este avance podemos comenzar a plantear la teoría de la factorización, así como explicar a grandes rasgos los  métodos encontrados (con sus ligeras variaciones) y su implementación en arquitecturas en paralelo. Para el siguiente avance me gustaría empezar el trabajo escrito y, junto a mis compañeros, comenzar con realizar implementaciones en cómputo.


Victor:

Para este avance hice una implementacion en C usando LAPACK. En el [script](https://www.dropbox.com/s/9rt1kpil79hm0ha/qr_lapack.c?dl=0) se puede ver que estoy ocupando las funciones *dgeqrf* y *dorgqr* para obtener las matrices R y Q respectivamente. Para probar el algoritmo, corrí el [ejemplo](https://rpubs.com/aaronsc32/qr-decomposition-householder) que había encontrado en el primer avance, [aquí](https://www.dropbox.com/s/7wrxqvx6cttxpet/prueba_lapack.txt?dl=0) se puede ver un .txt con la corrida. Es importante aclarar que el ejemplo que se muestra es de una matriz 3x3, sin embargo las matrices salen en formato de vector de una dimensión ya que así deben introducirse a las funciones, pero debe leerse por columna (es decir, los primeros 3 números son la primer columna). Otro punto que es importante aclarar es que la matriz R es triangular superior, sin  embargo en la matriz resultante no es así porque la parte triangular inferior muestra información importante que ocupa LAPACK para luego recuperar la matriz Q, por lo que sólo es importante fijarse en la parte triangular superior de este resultado. 

También leí los apuntes del [tema 3](https://www.dropbox.com/s/s4ch0ww1687pl76/3.2.2.Factorizaciones_matriciales_SVD_Cholesky_QR.pdf?dl=0) , de la clase como nos recomendó Erick, enfocandome más en la parte de Factorización QR. De igual modo leí sobre [SCALAPACK](http://www.netlib.org/scalapack/), que es una librería con rutinas de álgebra lineal paralelizables en memoria distribuida.


### Equipo

Como equipo consideramos que tenemos claro el concepto de la factorización así como el funcionamiento de los algoritmos para llevarla a cabo. Con las primeras implementaciones en código tenemos noción más clara del proceso e incluso podemos visualizar las dificultades a las que nos podemos enfrentar posteriormente. 

