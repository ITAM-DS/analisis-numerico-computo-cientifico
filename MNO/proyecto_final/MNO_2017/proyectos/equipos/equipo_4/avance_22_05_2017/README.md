# Equipo 4: Avances de trabajo final.

---

## Integrantes:
* Fernanda Téllez Girón
* Guillermo Javier Quiroz Martínez
* Lizbeth Contreras Figueroa

---

### Avances individuales:

**Fernanda**:

Durante esta semana desarrollé un código en R que realizara la multiplicación de matrices de números grandes utilizando la función de multiplicación de Toom-Cook y una implementación de la suma de números grandes que desarrollamos por medio de secciones. Este código servirá para guiar el código en C de esta implementación y para poder comprobar los resultados paso a paso en caso que algo no cuadre en el resultado final. Este código puede encontrarse [aquí](./codigoR).

**Javier**:

Durante esta semana se terminó el código de Toom-Cook 3 que se presentará al final, considerando los posibles casos y variaciones en los números grandes que se reciban como ceros intermedios(que al convertirse en una variable numérica podrían perderse y es necesario considerarlos en el resultado final) o casos en los que un número grande se multiplique por uno pequeño (rellenando con ceros a la izquierda para asegurar el correcto funcionamiento del algoritmo)


**Lizbeth**:

Durante esta semana se detalló más el trabajo final, recompilé ejemplos claros para poder ilustrar mejor el algoritmo en el trabajo final. Además de esto revisé la bibliografía que se propuso en el avance anterior para agregar un poco de  historia y contexto del algoritmo al trabajo. 


---

### Avance de equipo:


Ya que decidimos acotar nuestro enfoque a Toom-3 para evitar posibles problemas ocasionados por la matriz mal condicionada que se genera al evaluar en el polinomio terminamos el código para esta implementación. Este código puede encontrarse [aquí](./codigoC). Además realizamos una implementación en R de la multiplicación de matrices de números grandes. Esta implementación puede encontrarse [aquí](./codigoR). Es necesario para que esta implementación funciona generar un código que sume los números grandes sin perder precisión, es decir que los sume por secciones y regularize los resultados. 
Por último se continuo trabajando en la versión final del trabajo escrito. 






