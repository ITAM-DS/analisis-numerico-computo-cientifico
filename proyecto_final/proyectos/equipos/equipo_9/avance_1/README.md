## Equipo 9
#### Avance 1:	

## Trabajo

+ **Equipo:** Revisamos los artículos para determinar el problema y el alcance del trabajo.
Participamos en la construcción del trabajo escrito final.

+ **Eduardo:** Investigó las referencias para la construcción del marco teórico acerca de valuación de opciones en general. Las definiciones de los contratos forward, call y put, los estilos de éstos y el framework riesgo neutro para la valuación. Escribió una rutina para simulación de trayectorias basándose en las observación de los precios de cierto activo (subyacente). También revisó la teoría que garantiza la convergencia del algoritmo a un precio riesgo-neutro.

+ **Jorge:** Se encuentra investigando los detalles para una posible implementación en paralelo de los m-1 problemas de optimización, enfocándose en las descomposiciones en valores singulares. Propuso guardar las simulaciones en S3 y realizar el procesamiento en una instancia de AWS o Azure. Está evaluando convertir algunos scripts en R a Python, con el fin de obtener un desempeño aceptable.

+ **Ariel:** Dado el dataframe de payoffs en todas las trayectorias simuladas, escribió una rutina que describe explícitamente los escenarios de ejercicio de la call (o put), además determina los días en los que el ejercicio es óptimo y finalmente estimar el precio de la opción Americana en estudio. Está pensando en una rutina de acoplamiento para las matrices de diseño de dimensión variable.

