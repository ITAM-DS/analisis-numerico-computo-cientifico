# Equipo 14

# Integrantes
Esthefany Ortiz 
Antonio Manguart
Allan Rosas

# Título del proyecto
Solución del modelo de Markowitz utilizando programación cuadrática

# Objetivo del Proyecto
Implementar la solución de selección de portafolios utilizando el modelo de markowitz haciendo uso de los métodos numéricos vistos en clase.

# Trabajo previo
Fany
Investigar el framework teórico en el que se basa el modelo de Markowitz y buscar bibliografia

Allan
Investigar como hacer la implementación de BLAS en ubuntu para poder usarla con python y dockerizarlo, invetigar el modelo matematico

Antonio
Automatizar scripts para bajar n número de acciones, simular modelo de markowitz con las acciones bajadas y crear la visualización del portafolio

Todos

Lectura del paper original:
H. Markovitz, Portfolio selection: Efficient Diversification of Invest-
ments, Wiley, New York, 1959

# Links finales
Link al repositorio:
https://github.com/manguart/optimizacion
`markowitz.py`implementa cvxopt para un rendimiento dado
`simulacion.py`tiene la impelmentación de la simulación de markowitz 
`stock_data.R`baja acciones
`markowitz_simple_con_condicones_de_optimalidad.R`implementa la matriz de KKT desde R y encuentra una solución

Link a la presentación final:
https://docs.google.com/presentation/d/1w6FHBova72snJpAflVfCCzffHOtu_GmYlhOxZrjLL-o/edit#slide=id.g5acae0e010_6_71

Link al documento final:
https://github.com/manguart/optimizacion/blob/master/Optimizacion_de_portafolios_pf_MNO.pdf


# Referencias
Lectura de los capítulos 1,2,5 y 6 del libro
Optimization Methods in Finance -G. Cornuejols, R. Tutuncu 2nd Ed, Cambridge University Press, Cambridge

Gerard Cornuejols and Reha Tu ̈tu ̈ncu ̈. Optimization methods in finance. Vol. 5. Cambridge University Press, 2006.

Jorge Nocedal and Stephen Wright. Numerical optimization. Springer Science & Business Media, 2006.

Joachim Dahl Martin Andersen. Python Software for Convex Optimization. url: https://cvxopt.org/. (accessed: 01.05.2019).

