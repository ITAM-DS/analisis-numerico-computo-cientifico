Se plantea el problema de ciclo máximo como un problema de optimización estándar:

Se requiere maximizar la función de ciclo la cuál depende de m, a y c.

max ciclo(m, a, c)

con las restricciones de desigualdad siguientes:
m >= 2
a <= m
c <= m

y las restricciones de igualdad siguientes:
m = [m]
a = [a]
c = [c]

donde la función [ ] es la función mayor entero menor o igual. Esto es, regresa un número entero que es el mayor de todos los posibles enteros que son menores al número dado: Ejemplos: [5] = 5, [5.1] = 5, [10.9] = 10, etc

El trabajo a realizar ahora es encontrar la función lagrangiana y su dual y ver si es posible resolver este problema de optimización. Además de continuar trabajando con la calidad de los números aleatorios dados.


Avance Víctor

Se modificó la forma en que se realizaba la transformación de los números binarios para que todos tuvieran la misma longitud de 11 (para llegar a 2048) agregando ceros a la izquierda. (script DecimalToBinary_v2.c y rand.sh)

Se volvieron a generar números aleatorios (rand_m_2048_a_65_c_1.txt, rand_m_2048_a_1229_c_1.txt, rand_m_2048_a_1365_c_1.txt) y se corrieron las pruebas del NIST. En esta ocasión los resultados mejoraron considerablemente (finalAnalysisReport_m_2048_a_65_c_1.txt, finalAnalysisReport_m_2048_a_1229_c_1.txt, finalAnalysisReport_m_2048_a_1365_c_1.txt).

Falta continuar trabajando en las mejoras de la aleatoriedad.

