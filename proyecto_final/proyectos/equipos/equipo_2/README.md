# Equipo 2

Integrantes:
* Iker M. Olivo De Anda | 175482
* Luis Eduardo Ochoa Díaz | 183170
* María Soledad Jassel Pérez Flores | 183352

Título del proyecto: 
**Comparación de Métodos de reducción de dimensionalidad  CUR Descomposition y SVD aplicados a un problema de sistemas de recomendación**

Objetivo del proyecto:
Implementación y evaluación de los algoritmos  CUR Descomposition , SVD y SGD. La evaluación del desempeño de estos algoritmos se realizará en un  problema de sistemas de recomendación (aún no elegimos nuestro data set, lo cual es un punto importante pues podría modificar nuestra selección de la aplicación)  tanto en tiempo de procesamiento como en la precisión de sus resultados (de acuerdo a alguna métrica adecuada al problema de aplicación seleccionado como por ejemplo RECM o MAD).  La premisa es que CUR Descomposition al ser las matrices C y R ralas si la matriz original M es rala, debe ser más rápido que SVD pero desconocemos si esto tiene un trade-off  con la calidad de los resultados obtenidos.

Trabajo escrito:
[Liga a trabajo escrito](https://www.dropbox.com/s/e2vl55iwbxppdok/Proyecto_final_CUR_SVD_aplicados_a_sistemas_recomendacion.html?dl=1)

Presentación:
[Liga a presentación](https://www.dropbox.com/s/q3qrqbt2qp04dvp/Sist_Recom%20CUR_SVD_SGD.pptx?dl=0)

Implementación:
[Liga a código](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/mno-2019-1/proyecto_final/proyectos/equipos/equipo_2/implementacion)

En la carpeta [avance_1](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/mno-2019-1/proyecto_final/proyectos/equipos/equipo_2/avance_1/) se encuentra el reporte del primer avance en nuestro proyecto.

Referencias del proyecto:

* [Reducción de Dimensionalidad](http://infolab.stanford.edu/~ullman/mmds/ch11.pdf)
* [Sistemas de Recomendación](http://infolab.stanford.edu/~ullman/mmds/ch9.pdf)
* [Tradeoffs of Large Scale Learning](https://leon.bottou.org/publications/pdf/nips-2007.pdf)
* [CUR Descomposition video](https://www.youtube.com/watch?v=SO1KTzuKTSI&index=51&list=PLLssT5z_DsK9JDLcT8T62VtzwyW9LNepV)
* [CUR Algorithm video](https://www.youtube.com/watch?v=WgK_D6IyDbM&list=PLLssT5z_DsK9JDLcT8T62VtzwyW9LNepV&index=52)
* [Discussion of the CUR Method](https://www.youtube.com/watch?v=qgsuly5nxIw&list=PLLssT5z_DsK9JDLcT8T62VtzwyW9LNepV&index=53)
* [CUR from a Sparse Optimization Viewpoint](https://papers.nips.cc/paper/3890-cur-from-a-sparse-optimization-viewpoint.pdf)
* [Aprendizaje con descenso en gradiente estocástico con datos de gran escala](http://khalilghorbal.info/assets/spa/papers/ML_GradDescent.pdf)
* [Distributed CUR Decomposition](https://stanford.edu/~rezab/classes/cme323/S16/projects_reports/kline_shaw.pdf)
* [Optmial CUR](https://arxiv.org/pdf/1405.7910.pdf)
* [Optimal CUR ref2](http://www.cs.cmu.edu/afs/cs/user/dwoodruf/www/mmds.pdf)
* [SGD](http://www.albertauyeung.com/post/python-matrix-factorization/)
* [CUR selection](https://www.cs.cornell.edu/courses/cs6220/2017fa/CS6220_Lecture14.pdf)
* [SGD implementacion](https://nbviewer.jupyter.org/github/albertauyeung/matrix-factorization-in-python/blob/master/mf.ipynb)