**Abraham:** 
`Avancé en la implemetación`[implement150518](codigo) `se armó la primera parte utilizando la base de datos Movie Lens, se armó en jupyter python el notebook es` [Base](codigo/Base.ipynb), `el objetivo de esta primera parte fue trasformar la base datos a una matriz de tipo user-items de tal modo que los renglones representen los usuarios y las columnas las películas y en cada celda i,j podamos ver la calificación del usuario i a la película j, y con ello poder tener datos listos para hacer descomposición SVD, cabe destacar que esto se hizo haciendo data partition donde dejamos 20% de los datos  de la matriz para prueba después usamos la librería scipy y la función svds aplicada a la matriz de entrenamiento y evaluamos en test usando la métrica rmse, este último proceso queremos optimizarlo con cuda y lo que vamos a necesitar es la matriz de entrenamiento que será input del programa svd.cu, para hacer el svd ahí.`


**Roberto:**
`Para este avance se desarrolló un ejemplo de SVD para ilustrar de manera intuitiva los pasos analíticos que se hacen en el proceso de descomposición. El ejemplo se puede ver` [aquí](https://drive.google.com/open?id=1S24oHTtZAMrZx1ISKTdPWBXZoP96jmEJ)  `, o en el trabajo escrito que ha estado desarrollando Rodrigo.`


**Rodrigo**
`Para este avance continué con el desarrollo del trabajo escrito. Las dos actualizaciones principales fueron las siguientes. Primero añadí el ejemplo de descomposición SVD con una matriz pequeña aportada por Roberto, con esto se complementa la descripción del procedimiento de descripción y ayuda a hacer más claro este proceso. Por otra parte se desarrolló la sección de implementación, donde se realiza una descripción de los datos que se utilizarán en el proyecto para probar nuestro sistema de recomendación; aquí se encuentra la procedencia de los datos, descripción de la obtención de los datos así como la descripción de todos los archivos con los que se cuenta para poder completar el proyecto.`[Avnce trabajo](https://drive.google.com/open?id=1VAqoUCzUEWzEkXHtCWGmJfCpjn0OC7HE)


**Equipo:** 
`Se hicieron modificaciones y avances al trabajo escrito, tanbién se incluyó el avance en la implementación, los siguientes pasos es cerrar la fase 2 de implementación  para que en la entrega final cerremos el proyecto.` 
