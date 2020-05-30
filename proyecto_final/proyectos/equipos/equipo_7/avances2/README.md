<div align="center">

# Implementación de métodos de optimización numérica en un modelo de aprendizaje
</div>

--------------------------------------------------------------------------------

<div align="justify"><strong>Objetivo del proyecto</strong>:

Tomando como referencia el trabajo de investigación realizado por Colubri et al. (2019), se busca entrenar un modelo de regresión logística que permite pronosticar la supervivencia a enfermedad por virus del ébola.  Para tal propósito, se utilizan datos recolectados por el Cuerpo Internacional de Medicina (IMC, por sus siglas en inglés) durante 2014 y 2016 en Liberia y Sierra Leona.  El fin del presente proyecto es evaluar el desempeño de diferentes métodos de optimización numérica en un contexto de machine learning, utilizando métodos  de cómputo simples y en paralelo.  En particular, se mide el desempeño de los modelos, tanto en términos del uso de recursos computacionales para lograr convergencia, como con relación a métricas de desempeño del modelo.  Finalmente, se realiza un análisis de los resultados en torno a la pregunta planteada inicialmente y el modelo de regresión asociado.


<strong>Avances del proyecto</strong>:

+ Avance 1 (85 por ciento)

  + Definición de milestones y proyecto.

  + Revisión de la referencia principal del trabajo de investigación Colubri et al. (2019), accesible a través del siguiente <a href="https://www.ncbi.nlm.nih.gov/pmc/articles/PMC6610774/">link</a>.

  + Revisión de métodos de optimización en notas de clases, así como los otros libros (ver referencias al final del documento)

  + Definición de conjunto de datos a emplear, disponibles en el repositorio público <a href="https://github.com/afcarl/ebola-imc-public">ebola-imc-public</a>.

  + Creación de dockerfile asociado al repo, disponible en <a href="https://hub.docker.com/layers/c1587s/mno_numopt/v1/images/sha256-48614267cf02eacc537e6824729407ca92e170548b115d01749184d59e658322?context=explore">dockerhub</a>; inclusión de boton de binder.

  + Creación de EC2 en AWS.

  + EDA del conjunto de datos y definición de modelo de regresión logística a implementar.

  + Programación de los métodos de optimización definidos al principio, junto con las funciones auxiliares necesarias.

  + Programación de algunos unittests relativo a la ingesta de datos y los outputs de algunas funciones auxiliares.

  + Creación de módulos con las funciones que tenemos hasta el momento.

  + Documentación (parcial) de las funciones.

  + Primera iteración de paralelización de los métodos desarrollados, empleando multiprocessing y dask.distributed.

  + Ajuste del reporte final, completado al 85 por ciento.


+ Avance 2 (100 por ciento)

    + Completar el reporte final:

        - se incluyeron métodos no documentados (SGD, SGD paralelo)

        - se corrigieron errores menores y typos

        - se completaron resultados

        - se introducen comparaciones de algoritmos en los resultados

        - se incluyen conclusiones


  + Generar notebook para presentación final ante la clase

  + Implementación de SGD en paralelo de forma completa.

  + Se documentaron funciones faltantes

  + Se resolvieron <em>issues</em> pendientes para la entrega.

<strong>Ligadas asociadas:</strong>

<a href="https://github.com/C1587S/MNO_numericalOptimization/blob/master/reporte/reporte_final.pdf">Trabajo escrito</a>: Reporte parcial de la implementación del trabajo.

<a href="https://github.com/C1587S/MNO_numericalOptimization/blob/master/notebooks/implementacionPresentacionMNO.ipynb">Presentacion</a>: Notebook con el desarrollo autocontenido del proyecto.

<a href="https://github.com/C1587S/MNO_numericalOptimization">Implementacion</a>: Misma que se encuentra dispuesta en un repositorio que tiene la siguiente estructura de carpetas:

<code>├── aws                    &lt;- Contiene los scripts e indicaciones necesarias
├                             para la configuración de una instancia EC2 en
├                             donde se llevará acabo el procesamiento.
├── data
│   ├── external           &lt;- Data recolectada del repositorio público ebola-imc-public
│   ├── preprocessed       &lt;- Data que ha sido transformada y empleada en el
│                             presente trabajo.
├── docs                   &lt;- documentos asociados a la configuración de la imagen de docker empleada
│
├── images                 &lt;- Imágenes asociadas al proyecto.
│
├── modulos                &lt;- Módulos asociados al proyecto
│
├── notebooks              &lt;- Jupyter notebook autocontenido con todo lo implementado a propósito del proyecto.
│
├── referencias            &lt;- Referencias empleadas.
│
├── reporte                &lt;- Reporte final generado en LaTex y compilado en
├                             PDF.
│   └── figures            &lt;- Gráficas y figuras generadas que son empleadas en
│                             el reporte.
│
├── test                   &lt;- Unittest implementados.
│
├── Dockerfile
├── LICENSE                &lt;- Licencia
├── README.md              &lt;- Descripción breve del proyecto, estructura de carpetas del repositorio y datos de contacto.
│
└── requirements.txt       &lt;- Las paqueterías y librerías empleadas</code>


<strong>Integrantes del equipo:</strong>

- Juan Pablo Herrera Mussi (<a href="https://github.com/Pilo1961">Pilo1961</a>) – Programador/Revisor
- Daniela Pinto Veizaga (<a href="https://github.com/dapivei">dapivei</a>) – Team Leader/Revisora
- Sebastián Cadavid-Sánchez (<a href="https://github.com/C1587S">C1587S</a>)– Revisor/Programador

<strong>Referencias:</strong>



+ Colubri, A., Hartley, M. A., Siakor, M., Wolfman, V., Felix, A., Sesay, T., ... &amp; Sabeti, P. C. (2019). Machine-learning Prognostic Models from the 2014–16 Ebola Outbreak: Data-harmonization Challenges, Validation Strategies, and mHealth Applications. EClinicalMedicine, 11, 54-6º4.

+ Murphy, K. P. (2012). Machine learning: a probabilistic perspective. MIT press.

+ Nocedal, J., &amp; Wright, S. (2006). Numerical optimization. Springer Science &amp; Business Media.


</div>
