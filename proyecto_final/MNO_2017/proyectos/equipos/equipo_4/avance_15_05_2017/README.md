# Equipo 4: Avances de trabajo final.

---

## Integrantes:
* Fernanda Téllez Girón
* Guillermo Javier Quiroz Martínez
* Lizbeth Contreras Figueroa

---

### Avances individuales:

**Fernanda**:

Esta semana me dediqué a investigar más a fondo los métodos sugeridos para lidiar con el caso de la matriz mal condicionada. Además revisé los avances que se tienen del documento final para comenzar a agregar secciones y perfeccionarlo. 

**Javier**:

Durante esta semana se terminó completamente el código para el caso de dividir los números en 3 y 4 pedazos. Discutí con el equipo acerca de los métodos necesarios para realizar el caso de dividir los números en 5 secciones.


**Lizbeth**:

Revisé los métodos de Newton o Lagrange que se mencionaron en el avance de la semana pasada para que se decidiera en conjuntp si se utilizará este método o no. Además continué avanzando con el documento final, buscando más referencias y algunos ejemplos explicados muy claramente para detallar el algoritmo en el trabajo.


---

### Avance de equipo:

Continuamos con la investigación de los métodos que podriamos usar para evitar perder precisión por tener que resolver un  sistema lineal con una matriz mal condicionada. Nuestro principal problema es que después de resolver el sistema de ecuaciones lineales se utilizan esos resultados para realizar una suma desplazada en la que cada número se suma en una posición diferente para representar cientos, miles, millones, etc. Esto nos provoca problemas extras ya que si los métodos de aproximación nos hacen perder solo algunos dígitos de precisión al hace la suma este error se recorrería a posiciones más elevadas del número por lo que decidimos junto con el profesor limitar los casos que impllementaremos a dividir los números en 3 y 4 secciones y eliminar el caso de realizar 5 secciones. 







