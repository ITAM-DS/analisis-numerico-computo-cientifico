# Equipo 4: Avances de trabajo final.

---

## Integrantes:
* Fernanda Téllez Girón
* Guillermo Javier Quiroz Martínez
* Lizbeth Contreras Figueroa

---

### Avances individuales:

**Fernanda**:

De acuerdo con lo comentado con el profesor la semana pasada revisé el método de SVD truncada como una posible solución a los problemas de precisión que presenta la matriz mal condicionada para el caso de la matriz de 9x9 que resulta del sistema al dividir los números en 5 segmentos. Sin embargo nuestra matriz es cuadrada y el método de SVD truncado se utiliza para matrices rectangulares. Por lo tanto el método sería descomposición SVD. 

Además de esto probé cambiando algunos puntos de evaluación de la matriz para ver si el número de condición era muy sensible a estos cambios. En efecto el número de condición cambia en gran medida cuando se realizan estos cambios, incluso cuando consideré evaluar el polinomio en el valor *infinito* (de tal manera que solo tenga influencia el coeficiente con el máximo exponente) no fue posible disminuir el número de condición de la matriz. 

Encontré esta sencilla [explicación](http://web.mit.edu/be.400/www/SVD/Singular_Value_Decomposition.htm) de la descomposición SVD y más útil aun la siguiente [presentación](https://www.mpp.mpg.de/~schieck/svd.pdf) que describe muy claramente los pasos a seguir para resolver un sistema de ecuaciones lineales por medio de la descomposición SVD. Continuo investigando de esto además de revisar las referencias que encontró Liz acerca de los métodos sugeridos por el profesor, la matriz de interpolación de Newton o Lagrange. 


**Javier**:

Durante estas semanas continué trabajando en el código en C que se entregará. Algunos de los principales cambios que realicé  fue la corrección de funciones básicas para que funcionaran de manera más general y sin errores. Dado que para que nuestro algoritmo funcione es necesario que un numero se divida en grupos de subgrupos (cajas) mutiplicadas por las diferentes potencias de la base, se preparó el código para aceptar cajas de diferentes longitudes en preparación para adecuaciones al algoritmo base.
Pretendemos presentar una aplicación de este algoritmo para operaciones matriciales (como la mutiplicación). Adicionalmente, esta semana he trabajado en la programación de estas funciones matriciales para números muy grandes sin concluirla. Posteriormente trabajaré en la utilización de pthreads para acelerar las operaciones.

El código de este avance puede encontrarse [aquí](./codigo)


**Lizbeth**:

Revisé la bibliografía mencionada en el avance del 01 de mayo y continué trabajando en el [entregable]( https://www.dropbox.com/scl/fi/prtfa2a24snrx9i6o4ewa/Trabajo%20final.docx?dl=0&oref=e&r=AAaa0MNkh97EqTnpysa1RsjQ-IKn_ny1yYna2TCGTshPicMl8iMKjiXizJz2NW8df1mY3r6GbssV8FYTuLZvP_oU0UH15dR-33rM216-Tg077bybqUyy2LvkWJCJ_0LbHDjBbo9CbQoGoxuvQmtmAP1j1c-VKnu2GcCzWOUb2OJYcQ&sm=1), sin embargo la explicación del algoritmo todavía queda corta. Por tal motivo realicé una tercera búsqueda con el fin de ir llenando los huecos y encontré el trabajo de [Charlton Lu]( https://www.dropbox.com/s/by7qkl6oewuyxq6/CL_Paper3_MultiplicationandDivisionAlgorithms.docx?dl=0) en el cuál se encontró de forma más detallada un ejemplo del método; y el artículo de [Kronenburg]( https://www.dropbox.com/s/l6wt7h881zhnh98/d1bde35dcfe736d03b03ea45d0ba0a28c92e.pdf?dl=0) en el cuál en una revisión rápida se observa el desarrollo del método desde una perspectiva más formal. Queda pendiente que discuta estos artículos con mi equipo.
Finalmente con base en las recomendaciones del profesor del día sábado 6 de mayo para resolver el problema de la matriz mal condicionada, en el que recomendó utilizar matriz por interpolación de Newton o Lagrange se encontró el siguiente material de [Parhi](https://www.dropbox.com/s/8flmijftnfk6her/chap8.pdf?dl=0) y el siguiente [libro]( https://books.google.com.mx/books?id=IA-bCgAAQBAJ&pg=PA19&lpg=PA19&dq=toom-cook+Lagrange+matrix&source=bl&ots=nVBOX-W3Lw&sig=2YPr3OIMp5ufsYzwpGNKIsEiYNg&hl=es&sa=X&ved=0ahUKEwjm4rePmuHTAhUJwWMKHbnuA2QQ6AEIRzAE#v=onepage&q=toom-cook%20Lagrange%20matrix&f=false) estos dos últimos quedan pendientes de revisión para esta semana.


---

### Avance de equipo:

Durante esta semana continuamos avanzando con el [código](./codigo) que se entregará para hacerlo más general y que acepte los tres casos que consideraremos para esta implementación. El avance en este código es ya significativo aunque buscamos agregar una porción de pthreads si el tiempo nos lo permite. Además comenzamos ya el código que utilizaremos al final para demostrar la multiplicación de dos matrices con entradas de números grandes. 

Continuamos con la investigación de los métodos que podriamos usar para evitar perder precisión por tener que resolver un  sistema lineal con una matriz mal condicionada. Por último continuamos con el trabajo, buscamos más referencias para ampliar la teoría y de esa manera tener un marco teórico más completo del algoritmo. 






