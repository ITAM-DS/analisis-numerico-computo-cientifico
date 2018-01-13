# Equipo 4: Avances de trabajo final.

---

## Integrantes:
* Fernanda Téllez Girón
* Guillermo Javier Quiroz Martínez
* Lizbeth Contreras Figueroa

---

### Avances individuales:

**Fernanda**:

Esta semana me percaté que podrían aparecer problemas numéricos al intentar resolver el sistema de ecuaciones al que conduce el algoritmo para el caso de dividir los números en 5 secciones ya que este problema conduce a una matriz de 9x9 que representa los puntos en los que se debe evaluar el polinomio. Incluso utilizando números enteros pequeños (el número máximo en el que se evalua es el 4) existe un problema ya que el menor exponente al que se eleva este número es 0 y el máximo es 8. Esto genera que la matriz resultante tenga números pequeños y números grandes que aunque no salen del rango en el que la computadora genera máxima precisión si ocasionan que la matriz tenga un número de condición alto. 
Dado que esta matríz está mal condicionada busqué maneras de resolver este sistema lineal manteniendo la confianza en nuestros resultados. 

Propuse al equipo dos opciones; dividir los números en máximo cuatro pedazos y aumentar la longitud de estos cuidando que se mantenga la precisión total o , para el caso de dividir los números en 5 secciones, utilizar factorización *QR* ya sea por *House Holder* o por el método de *Givens* de acuerdo con lo que leí en esta [referencia](https://www-old.math.gatech.edu/academic/courses/core/math2601/Web-notes/3num.pdf). 

Después de comentarlo con el profesor comente al equipo que un método sería utilizar SVD para resolver el problema, investigaremos acerca de esto y buscaremos como implementarlo en el código.  


**Javier**:

Esta semana trabajé en el código en C para esta implementación, ya terminé el algoritmo para el caso de dividir los números en 3 subsecciones, mismo que genera la matriz de 5x5 que no nos preocupa tanto por el número de condición que presenta. Los avances en este código pueden encontrarse [aquí](./codigo).

Además de esto realicé pruebas simples y validaciones de los resultados utilizando la librería que decidimos con anterioridad utilizar para corroborar los resultados. También revisé algunas referencias que me hicieron llegar mis compañeras. 


**Lizbeth**:

Continué con en el entregable final del trabajo escrito cuya versión actual puede encontrarse [aquí](https://www.dropbox.com/scl/fi/prtfa2a24snrx9i6o4ewa/Trabajo%20final.docx?dl=0&oref=e&r=AAaa0MNkh97EqTnpysa1RsjQ-IKn_ny1yYna2TCGTshPicMl8iMKjiXizJz2NW8df1mY3r6GbssV8FYTuLZvP_oU0UH15dR-33rM216-Tg077bybqUyy2LvkWJCJ_0LbHDjBbo9CbQoGoxuvQmtmAP1j1c-VKnu2GcCzWOUb2OJYcQ&sm=1). Se buscó mayor bibliografía para poder agregar información más detallada del modelo de Toom-Cook, como [esta](https://www.dropbox.com/s/w65j5vvqti00bi5/algorithm-the_art_of_computer_programming-knuth.pdf?dl=0) y [esta](http://www.bodrato.it/papers/WhatAboutToomCookMatricesOptimality.pdf) que es además una referencia que ya se había sugerido por parte del profesor. 

Revisé el problema con el que se encontró Fer y que nos comunicó a finales de la semana pasada acerca la matriz problemática que encontró. Queda pendiente la decisión final del equipo en cuanto a la manera de atacar el problema. 

---

### Avance de equipo:

Durante esta semana continuamos leyendo algunas referencias que nos ayudaron a aclarar algunas dudas que surgieron. Realizamos algunas validaciones de la primera versión del cógigo aunque solo incluya la implementación para dividir el número en 3 subsecciones. Discutimos acerca de los pasos a seguir para no perder precisión como consecuencia de resolver el sistema de ecuaciones con la matriz mal condicionada del último caso. Queda por decidir si se reducirá el scope del proyecto (a solo dividir en 3 o 4 secciones los números) o si se atacará este problema con otros métodos numéricos (como descomposición en valores singulares) esto se decidirá de acuerdo con los tiempos y que tanto nos ayuden estas aproximaciones a cumplir con los objetivos del proyecto. 





