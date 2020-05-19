<div align =center>

# Implementación de métodos de optimización numérica en un modelo de aprendizaje
</div>

***
<div align=justify>

**Objetivo del proyecto**:

Tomando como referencia el trabajo de investigación realizado por Colubri et al. (2019), se busca entrenar un modelo de regresión logística que permite pronosticar la supervivencia a enfermedad por virus del ébola.  Para tal propósito, se utilizan datos recolectados por el Cuerpo Internacional de Medicina (IMC, por sus siglas en inglés) durante 2014 y 2016 en Liberia y Sierra Leona.  El fin del presente proyecto es evaluar el desempeño de diferentes métodos de optimización numérica en un contexto de machine learning, utilizando métodos  de cómputo simples y en paralelo.  En particular, se mide el desempeño de los modelos, tanto en términos del uso de recursos computacionales para lograr convergencia, como con relación a métricas de desempeño del modelo.  Finalmente, se realiza un análisis de los resultados en torno a la pregunta planteada inicialmente y el modelo de regresión asociado.


**Avances del proyecto**:

+ Avance 1 (85 por ciento)

  + Definición de milestones y proyecto.

  + Revisión de la referencia principal del trabajo de investigación Colubri et al. (2019), accesible a través del siguiente [link](https://www.ncbi.nlm.nih.gov/pmc/articles/PMC6610774/).

  + Revisión de métodos de optimización en notas de clases, así como los otros libros (ver referencias al final del documento)

  + Definición de conjunto de datos a emplear, disponibles en el repositorio público [ebola-imc-public](https://github.com/afcarl/ebola-imc-public).

  + Creación de dockerfile asociado al repo, disponible en [dockerhub](https://hub.docker.com/layers/c1587s/mno_numopt/v1/images/sha256-48614267cf02eacc537e6824729407ca92e170548b115d01749184d59e658322?context=explore); inclusión de boton de binder.

  + Creación de EC2 en AWS.

  + EDA del conjunto de datos y definición de modelo de regresión logística a implementar.

  + Programación de los métodos de optimización definidos al principio, junto con las funciones auxiliares necesarias.

  + Programación de algunos unittests relativo a la ingesta de datos y los outputs de algunas funciones auxiliares.

  + Creación de módulos con las funciones que tenemos hasta el momento.

  + Documentación (parcial) de las funciones.

  + Primera iteración de paralelización de los métodos desarrollados, empleando multiprocessing y dask.distributed.

  + Ajuste del reporte final, completado al 85 por ciento.


+ Avance 2 (pendiente)

**Ligadas asociadas:**

[Trabajo escrito](https://github.com/C1587S/MNO_numericalOptimization/blob/master/reporte/reporte_final.pdf): Reporte parcial de la implementación del trabajo.

[Presentacion](https://github.com/C1587S/MNO_numericalOptimization/blob/master/notebooks/notebook_implementacion.ipynb): Notebook con el desarrollo autocontenido del proyecto.

[Implementacion](https://github.com/C1587S/MNO_numericalOptimization): Misma que se encuentra dispuesta en un repositorio que tiene la siguiente estructura de carpetas:

```
├── aws                    <- Contiene los scripts e indicaciones necesarias
├                             para la configuración de una instancia EC2 en
├                             donde se llevará acabo el procesamiento.
├── data
│   ├── external           <- Data recolectada del repositorio público ebola-imc-public
│   ├── preprocessed       <- Data que ha sido transformada y empleada en el
│                             presente trabajo.
├── docs                   <- documentos asociados a la configuración de la imagen de docker empleada
│
├── images                 <- Imágenes asociadas al proyecto.
│
├── modulos                <- Módulos asociados al proyecto
│
├── notebooks              <- Jupyter notebook autocontenido con todo lo implementado a propósito del proyecto.
│
├── referencias            <- Referencias empleadas.
│
├── reporte                <- Reporte final generado en LaTex y compilado en
├                             PDF.
│   └── figures            <- Gráficas y figuras generadas que son empleadas en
│                             el reporte.
│
├── test                   <- Unittest implementados.
│
├── Dockerfile             
├── LICENSE                <- Licencia
├── README.md              <- Descripción breve del proyecto, estructura de carpetas del repositorio y datos de contacto.
│
└── requirements.txt       <- Las paqueterías y librerías empleadas
```


**Integrantes del equipo:**

- Juan Pablo Herrera Mussi ([Pilo1961](https://github.com/Pilo1961)) – Programador/Revisor
- Daniela Pinto Veizaga ([dapivei](https://github.com/dapivei)) – Team Leader/Revisora
- Sebastián Cadavid-Sánchez ([C1587S](https://github.com/C1587S))– Revisor/Programador

**Referencias:**



+ Colubri, A., Hartley, M. A., Siakor, M., Wolfman, V., Felix, A., Sesay, T., ... & Sabeti, P. C. (2019). Machine-learning Prognostic Models from the 2014–16 Ebola Outbreak: Data-harmonization Challenges, Validation Strategies, and mHealth Applications. EClinicalMedicine, 11, 54-6º4.

+ Murphy, K. P. (2012). Machine learning: a probabilistic perspective. MIT press.

+ Nocedal, J., & Wright, S. (2006). Numerical optimization. Springer Science & Business Media.


</div>
