# Equipo 8:
	-Walter Martínez Santana
	-José Carlos Castro Montes

## Descenso por coordenadas para L1

# Avance 03/04/2017
- Nuestro proyecto consiste en implementar el método de optimización libre de derivada descenso por coordenadas, el cual se puede paralelizar. El método requiere de resolver un sistema de ecuaciones de la forma Ax = b, el cuál resolveremos con el método de Jacobi. Para la paralelización utilizaremos CUDA.

# Avance 19/04/2017
En principio pensabamos implementar este método en CUDA, pero el algoritmo de JACOBI no era puramente paralelizable ya que teníamos dos opciones:
  - Poner banderas y condicionar nuestros nodos ya que no iterarian de forma libre lo cual es una de las grandes ventajas de usar CUDA.
  - Otra opción era usar un factor de memoria via "stencil computations" considerando las entradas vecinas para asegurarnos de no actualizar nuestros vectores antes de tiempo, analizamos este método y no lo consideramos conveniente ya que incrementaba las operaciones en 4n, lo que nos lleva a perder la ventaja que tenía paralelizar y al compararlo resulta solo más eficiente utilizando un poder de computo mucho mayor (GPU TESLA C 1060).
  
Por las razones anteriores decidimos implementar descomposición de Cholesky para matrices densas ya que es uno de los métodos mas usados del análisis numérico para resolver ecuaciones y por consecuente un método muy util en optimización y por lo tanto en aprendizaje de máquina.

Este método lo implementaremos en CUDA, por lo que uno de los principales retos será idear la malla.
