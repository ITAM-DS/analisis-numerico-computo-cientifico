# Estimación de probabilidades de incumplimiento en el tiempo

## Introducción

La obtención de probabilidades de incumplimiento es una parte fundamental en la toma de decisiones en las instituciones de crédito. La probabilidad de incumplimiento se define en general como la probabilidad de que un acreditado no cumpla con las obligaciones de su crédito durante 90 días o más. Generalmente se cree que la probabilidad de incumplimiento es una cantidad que puede ser como una etiqueta y que esa misma etiqueta puede usarse para definir tasas de productos (pricing), análisis temporal o credit scoring. En este trabajo se mostrará una forma de calcular probabilidades en el tiempo y contrastarla con la forma de calcular probabilidades de incumplimento para realizar Credit Scoring de créditos hipotecarios.




### 1. Objetivo:

Análisis de las Probabilidades de Incumplimiento de créditos hipotecarios de Estados Unidos para identificar periodos de crisis y propuesta de credit scoring, mediante el uso de las herramientas vistas en el curso de Análisis Numérico y Computo Científico.




### 2. Datos:

Se utilizará la información de 60 trimestres de 5000 créditos hipotecarios de Estados Unidos tomada de protafolios bursatilizado (RMBSs) a partir del año 2000 (hasta 2015). El proveedor de la base es el International Financial Research (www.internationalfinancialreaserch.org) , y se tiene acceso a ella por la adquisición del libro Deep Credit Risk de Daniel Rosch y Harald Scheule, que es la principal fuente de este trabajo.



### 3. Temas

a. Análisis exploratorio de la base de datos.

b. Selección de variables usando distintas herramientas: "Feature Enginering".
	
	b.1 Análisis de Probabilidades de incumplimiento en el tiempo : PCA.
	
	b.2 Credit Scoring: Mapeo WOE (weight of evidence) para obtención de Information Value.
	
c. Modelo de Regresión Logística para obtención de Probabilidades de incumplimiento en el tiempo.
	
	c.1 Selección de Técnica.
	
	c.2 Obtención de Parámetros.
	
	c.3 Análisis de medidas de validación.
	
	c.4 Proyección o estimación.
	
d. Modelo de Regresión para uso en Credit Scoring (sobre el mapeo de WOEś).
	
	d.1 Selección de Técnica.
	
	d.2 Obtención de Parámetros.
	
	d.3 Análisis de medidas de validación.
	
	d.5 Transformación a scorecards.
	
e. Conclusiones



### 4. Software
Python y AWS
* [Liga de la instancia](http://ec2-3-239-61-177.compute-1.amazonaws.com:8888/lab).




### 5. Bibliografía:
Rosch Daniel, Scheule Harald. Deep Credit Risk. 2020. Amazon Fulfillment, Polonia.
Siddiqi, Naeem. Credit Risk Scorecards, Developing and Implementing Credit Scoring. 2006. Wiley, New Jersey 

### 6. Repositorio
* [Liga del repositorio](https://github.com/arenitss/Proyecto_Final_Analisis_Numerico_Computo_Cientifico).



## Integrantes y asignación de tareas del equipo

|User | Nombre Completo| Tarea |
|:---:|:---:|:---:|
|@oaperez3|Oscar Perez|Project manager, levantamiento de instancia en AWS, implementación de metodología, responder preguntas
|@Eduardo-Moreno|Eduardo Moreno|Investigación de variables, hardcodear código, implementación metodología, responder preguntas
|@yefovar|Yedam Fortiz|Testing, estudio de parte matemática, expositor
|@arenitss|Nayeli Arenas|Redacción, revisón de resultados, expositor
