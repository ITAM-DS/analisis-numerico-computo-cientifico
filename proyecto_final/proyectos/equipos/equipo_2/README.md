## Equipo 2

Integrantes:

* Ana Torres
* Dira Martínez
* Iván Salgado
* León Garay

Título del proyecto: **Flujo Máximo: Algoritmo Ford - Fulkerson **

Objetivos del proyecto: 

1. Crear el paquete para python [ffmaxflow](https://github.com/optimizacion-2-2021-1-gh-classroom/practica-1-segunda-parte-diramtz) que utiliza el algoritmo Ford - Fulkerson para hallar el flujo máximo en una red.
2. [Robustecer](https://github.com/optimizacion-2-2021-1-gh-classroom/practica-2-primera-parte-diramtz) y [optimizar](https://github.com/optimizacion-2-2021-1-gh-classroom/practica-2-segunda-parte-diramtz) el paquete con compilación a C para mejorar su desempeño y mostrar estas mejoras.
3. Utilizar el paquete para resolver problemas de la vida real como los problemas de eliminaciones en una liga de baseball, transporte máximo y el de flujo máximo con demanda.

[Liga a repo](https://github.com/diramtz/ProyectoFinal_MaxFlow)

Trabajo escrito: [reporte](https://github.com/diramtz/ProyectoFinal_MaxFlow/blob/main/reporte_final_equipo_2.ipynb)

Presentación: [presentación](https://github.com/diramtz/ProyectoFinal_MaxFlow/blob/main/documentos/Presentacion_ffmf.pdf)

Implementación: [codigo](https://github.com/diramtz/ProyectoFinal_MaxFlow/tree/main/ffmaxc), [PyPI](https://pypi.org/project/ffmaxflow/)

En la carpeta [notebooks](notebooks) se encuentra material de apoyo para comprensión del código realizado. En esta carpeta, los notebooks están separados por el tipo de problema que resuelven, contienen contexto del problema así como la correcta utilización de los paquetes `ffmaxflow` y `ffmaxc` para resolverlos y una comparación de sus resultados y sus tiempos de ejecución con la paquetería de `networkx`. Los problemas resueltos son:

+ Eliminación en liga de béisbol: Determinar qué equipos son eliminados en cada momento de la temporada, por ejemplo, cuartos de final, octavos de final, final, etc. 
+ Transporte máximo: Hallar la cantidad máxima de personas que pueden volar de una ciudad a otra.
+ Flujo máximo con demanda: Indica la cantidad de mercancías que deben enviarse por una carretera en particular para satisfacer las demandas.

Referencias del proyecto:

* [Práctica 1 primera parte](https://github.com/optimizacion-2-2021-1-gh-classroom/practica-1-primera-parte-diramtz)
* [Práctica 1 segunda parte](https://github.com/optimizacion-2-2021-1-gh-classroom/practica-1-segunda-parte-diramtz)
* [Práctica 2 primera parte](https://github.com/optimizacion-2-2021-1-gh-classroom/practica-2-primera-parte-diramtz)
* [Práctica 2 segunda parte](https://github.com/optimizacion-2-2021-1-gh-classroom/practica-2-segunda-parte-diramtz)
* [Documentación de nuestro paquete](https://optimizacion-2-2021-1-gh-classroom.github.io/practica-2-segunda-parte-diramtz/)
* [Dataset](https://github.com/SumitPadhiyar/parallel_ford_fulkerson_gpu/tree/master/dataset)
* [Max Flow Problem Introduction](https://www.geeksforgeeks.org/max-flow-problem-introduction/)
* [Cortadura mínima](https://en.wikipedia.org/wiki/Max-flow_min-cut_theorem)
* [Aplicaciones flujo máximo](https://en.wikipedia.org/wiki/Maximum_flow_problem#Real_world_applications)
* [Coindidencia bipartita](https://en.wikipedia.org/wiki/Introduction_to_Algorithms)
* [Kubernetes' Documentation](https://kubernetes.io/es/docs/concepts/)
* [How to explain Kubernetes in plain English](https://enterprisersproject.com/article/2017/10/how-explain-kubernetes-plain-english)
* [Kubeflow: Starter’s Guide](https://www.globaldots.com/resources/blog/kubeflow-concepts-use-cases-and-starters-guide/)
* [5.3 Compilación a C](https://itam-ds.github.io/analisis-numerico-computo-cientifico/V.optimizacion_de_codigo/5.3/Compilacion_a_C.html#compilacion-aot-y-jit)
