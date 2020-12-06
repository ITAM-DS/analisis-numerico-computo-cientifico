# Practica Final : Creación de indice con análisis de componentes principales (PCA)

* Profesor: Erick Palacios Moreno
* Lenguaje a utilizar: Python

## Equipo

|Integrantes |Clauve única| GitHub |
|:---:|:---:|:---:|
|Ana Torres |197705| AnaTorresR | 
|Carlos López |   | Carlosrlpzi |
|Iván Salgado |197704| IvanSalgadoVel | 
|Roberto Pérez| 173013 | Roberto919 |

## Instancia AWS
- Public IPv4 DNS: ec2-34-207-190-50.compute-1.amazonaws.com
- Puerto para acceso a jupyterlab: 8787
- Clave de acceso: qwerty

## Tareas a realizar para este primer avance 


*Domingo 22 de noviembre*
- [X] Discutir el tema que deseamos implementar para este proyecto final.

- [X] Una vez decidido el tema nos dirigimos a buscar datos interesante con los cuales pudiéramos desarrollar un trabajo interesante.

- [X] Buscamos bibliografía del tema, así como del análisis de componentes principales, así como su implementación en R y en Python.

*Viernes 27 de noviembre*

- [X] Se analizó la base de datos, notamos que dos de los indicadores socioeconómicos tenían el mismo significado, por lo que decidimos eliminar aquella variable con mayor número de datos faltantes. 

- [X] Una vez seleccionadas las variables con las que trabajaremos notamos que los datos contaban únicamente con 32 valores faltantes, decidimos imputar estos valores con ayuda del lengiaje de programación `R`.


## Tareas a realizar para el segundo avance:

- [X] Definir al project manager -> Roberto Pérez (Roberto919)

- [X] Creación del proyecto, milestones e issues.

- [X] Asiganción de issues para cada integrante.

    - Los issues a asignar son: 

        - [X] Agregar el link a nuestras AWS instances.
    
        - [X] Separar los datos `base.csv` por años `1990`, `2000` y `2015`

        - [X] EDA, GEDA y data profiling de la base de datos `base.csv` ya que esta separada por años, en el notebook analisis_exploratorio.ipynb hay funciones útiles que podemos usar.

        - [X] Crear nuestro el índice de marginación con los pesos obtenidos del análisis de componentes principales.

        - [X] Comparar el índice obtenido de los componentes con el índice creado por el Consejo Nacional de Población (CONAPO).

        - [X] Reportar resultados en un notebook.

        - [X] Crear presentación.
    
        - [X] Agregar ligas hacia el trabajo escrito y presentación


## Docker 

- [X] Con Jupyter
- [ ] Sin Jupyter



## Bibliografía obtenida en el primer avance



[Datos](http://www.conapo.gob.mx/es/CONAPO/Datos_Abiertos_del_Indice_de_Marginacion)

[Diccionario de datos](https://www.gob.mx/cms/uploads/attachment/file/307289/Dicc_ent.pdf)

[Concepto y dimensiones de la marginación](http://www.conapo.gob.mx/work/models/CONAPO/Resource/1755/1/images/01Capitulo.pdf)

[Componentes principales en R](https://books.google.com.mx/books/about/Practical_Guide_To_Principal_Component_M.html?id=eFEyDwAAQBAJ&redir_esc=y)

[Componentes principales en Python](https://towardsdatascience.com/pca-using-python-scikit-learn-e653f8989e60)

[Ejemplo de análisis de componentes principales con R](https://www.cienciadedatos.net/documentos/35_principal_component_analysis)




