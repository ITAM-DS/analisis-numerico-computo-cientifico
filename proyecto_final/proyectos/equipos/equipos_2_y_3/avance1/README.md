#### Avance 1

#### Integrantes
* Danahi 
* Itzel
* Yalidt
* Cesar
* Bruno
* León

### Trabajo <br>

#### Project Manager<br>
Resolvimos 3 milestones para cada grupo de trabajo, el grupo de programación fueron los siguientes:<br>

**Programación Etapa 1** - relacionado con los issues *1.a Extracción de los datos desde Yahoo Finance* y *1.b Limpieza y 1c.Transformación* para resolver la etapa de extracción y carga de datos de nuestro proyecto. Los datos fueron extraidos de la base de datos de Yahoo Finance y se realizaron funciones para la extrlacción y la limpieza de la base de datos.<br>
**Programación Etapa 2**  - relacionado con los issues *2.a Valor medio esperado de activos*, *2b. Corrección en conversión de tasa anual* y *2c. Retorno esperado r* para obtener funciones que nos ayudaran a determinar la matriz de covarianzas de los rendimientos, el retorno medio y el retorno esperado de las acciones.<br>
**Programación Etapa 3** - relacionado con los issues *3a. Formación de vectores con matriz de covarianzas*,*Formación de valores A,B,C*, *3.c Formación de matriz Delta*,*3.d Formación de vectores auxiliares* y *3.e Solución del sistema markowitz* para resolver el problema de optimización con restricciones estimado a partir del método de multiplicadores de lagrange.

#### Grupo de Programación<br>
**Etapa I** (Responsable : Itzel) - Se programó una función que se llama *extraer_datos_yahoo* con la cual fue posible extraer el precio de las acciones de 50 empresas a evaluar, esta función se apoya de un paquete ya implementado en pyhton llamado *fix_yahoo_finance*.<br>
Adicionalmente, se levantó una instancia en AWS con GPUs, configurando un Dockerfile para construir una imagen con CuPy y con los paquetes necesarios para ejecutar nuestras funciones. Una vez finalizado el solver, se ejecutó el mismo en la instancia en un contenedor de la imagen construida de Docker a partir del Dockerfile.<br>
**Etapa II** (Responsable : Bruno)- Se programaron 3 funciones, la primera *calcular_rendimiento_vector* con la cual se calculan los rendimientos diarios de los precios obtenidos, la segunda *calcular_rendimiento* se encarga de promediar los rendimientos diarios y convertir esa tasa a nominal anual, y la tecera función *calcular_varianza* calcula la matriz de varianzas y covarianzas de los rendimientos diarios.<br>
**Etapa III** (Responsable : Cesar) - Se programaron 4 funciones auxiliares (*formar_vectores*, *formar_abc*, *delta* y *formar_omegas*), y del mismo modo de programó el solver que se poya de las funciones auxiliares para de esta manera llegar al vector de pesos que minimiza la varianza de los rendimientos.<br>

#### Grupo de Revisión<br>
**Etapa I** - Se revisó la primera etapa de programación y se levantó un issue para modificar el *input* que recibia la funcion de *extraer_datos_yahoo*, ya que los rangos de fecha de descarga para los precios no se recibía como parámetro y se mejoró esta función para que fuera lo más general posible.<br>
**Etapa II** - Sólo se encontraron los hallazgo de que para el cálculo del rendimiento anual la conversión era incorrecta, por lo que se levantó un issue para realizar la modificación correspondiente.<br>
**Etapa III** - Se revisó la etapa III del *solver* de Markowitz y no se realizaron hallazgos negativos<br>

[Código Avance 1](https://github.com/czammar/MNO_finalproject/blob/master/notebooks/Programacion/4_Solver.ipynb)

#### Siguiente milestone a resolver<br>

Hemos terminado la solución cerrada del sistema de minimización del portafolio para obtener mínima varianza de Markowitz y el siguiente proyecto a resolver se concentra en desarrollar el método de newton con cupy para resolver nuestro problema de optimización con restricciones de igualdad.




