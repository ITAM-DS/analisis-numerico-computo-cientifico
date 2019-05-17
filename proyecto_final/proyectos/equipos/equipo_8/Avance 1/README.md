# avance_1

## Integrantes:
* Maria Fernanda Rubio Gonzalez
* David Edgardo Castillo Rodriguez 
* Omar Reyes Villa

## Trabajo:

### Individual

Fer: 
Para resolver el sistema de ecuaciones diferenciales planteado usando Crank-Nicolson utilizaremos la [factorización LU con pivoteo parcial y eliminación Gaussiana](http://lya.fciencias.unam.mx/gfgf/pa20072/data/lecturas/eliminag/index.html), así como el [algoritmo de Thomas](https://www.quantstart.com/articles/Tridiagonal-Matrix-Solver-via-Thomas-Algorithm). Por lo que estuve trabajando en la implementación de estos métodos en R.


David:
Investigué acerca de la aplicación de los métodos en diferencias para resolver ecuaciones diferenciales parciales, en particular la ecuación de calor, la cual nos interesa porque la ecuación de Black-Scholes es de este tipo en el [libro](https://www.dropbox.com/s/iffk2abu739fcnn/Daniel_J._Duffy-Finite_Difference_Methods_in_Financial_Engineering__A_Partial_Differential_Equation_Approach_-Wiley%282006%29.pdf?dl=0) y en el [artículo](https://www.dropbox.com/s/7yhku5wf9wr9xoe/ART13.pdf?dl=0). Además, plantee el sistema de ecuaciones para resolver opciones de compra y un primer borador de su implentación en R.

Omar:
Leí la siguiente [referencia](https://www.dropbox.com/s/iffk2abu739fcnn/Daniel_J._Duffy-Finite_Difference_Methods_in_Financial_Engineering__A_Partial_Differential_Equation_Approach_-Wiley%282006%29.pdf?dl=0) donde me di cuenta que el Método de Líneas es una generalización de Crank-Nicolson, pues con una configuración específica en la discretización del tiempo y del activo podemos llegar al mismo sistema de ecuaciones. Estuve trabajando en el planteamiento teórico y entendimiento de la valuación de opciones para aterrizarlo a la ecuación de Black-Scholes en la siguiente [referencia](https://www.dropbox.com/s/0iecvb1z8tsdtxk/61509445.pdf?dl=0)



### Equipo

Planteamos dividirnos el trabajo en bloques respecto a los tres grandes temas que ibamos a tratar: David vería el planteamiento del sistema de ecuaciones utilizando métodos en diferencia, Omar plantearía el sistema de ecuaciones utilizando el Método de Líneas y, por último, la programación de LU con pivoteo parcial y el Algoritmo de Thomas en R estarían a cargo de Fer.





