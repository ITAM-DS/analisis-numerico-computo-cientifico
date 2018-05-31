## Alex

En esta semana me dediqué a escribir el código para levantar una maquina de aws usando docker-machine, la idea de esta maquina es poder comparar de manera justa las operaciones realizadas para los scripts "secuencial" y "paralelo".

Algunos de los problemas que se me presentaron fueron cuestiones de opciones a incluir para el levantamiento de la maquina, ya que hasta el momento la configuración de la región me detiene el levantamiento, pero continuaré trabajando en ello para resolverlo lo antes posible.

## Patricio

De mi lado realicé modificaciones al script loop_para_tiempos_mmult.sh y agregué otro loop para poder tener distintos registros cuando modificamos el número de threads y cuando modificamos el tamaño de las matrices.

Me encuentro resolviendo un error de "Violación de segmento", pero he leído que este error se da cuando se intenta accesar a direcciones de memoria no alcanzables. Seguiré revisando el codigo para corregir este error.

## Equipo

Al reunirnos determinamos dividir el código que Patricio modificó y lo rompimos en 2 archivos para revisar los resultados de manera más sencilla,por otro lado, logramos correr con algunos bugs aún, los codigos y ya tenemos un primer ejemplo de los resultados tanto con distintos cores como con distintas matrices.
