# Avance 2

<p align = "center">

# <p align = "center"> Maestría en Ciencia de Datos del ITAM :computer:
    
# <p align = "center"> Métodos Numéricos y Optimización (Otoño 2022)    
    
# <p align = "center"> Proyecto Final: Superficies de Delaunay. Una perspectiva desde el cálculo de variaciones.
  
# <p align = "center"> Equipo 1

## Integrantes 👨‍🔬 👨‍🔬 👩‍🔬 👨‍🔬

|     ***Contributors***           |             ***Usuario de Github***                  |  ***Roles***  |                               
|:--------------------------------:|:----------------------------------------------------:|:----------------------:|
|        David Damián Arbeu        |     [David-Damián](https://github.com/David-Damian)  |       Grupo de programación   | 
| Juan Francisco Palmeros Barradas | [JuanPalms](https://github.com/JuanPalms)            |       Grupo de programación   | 
|       Valeria Roberts Trujillo   |  [ValeriaRoberts](https://github.com/ValeriaRoberts) |       Project manager   | 
|  José Alberto Mandujano Montes   | [AlbertoMandujanoMontes](https://github.com/AlbertoMandujanoMontes) |       Grupo de revisión  |

## :rocket: ```Título del proyecto``` Superficies de Delaunay

## 🌐 [Trabajo escrito](https://drive.google.com/file/d/1eFj753-au0vghaDgTBWP7twcqc6HtbRp/view?usp=sharing)

## 🌐 [Presentación](https://drive.google.com/drive/u/1/folders/1PFiHOE2EAaN4GCr1xib3-4OOl3eIG-nY)

## Trabajo:

### Resúmen

En primera instancia cada rol se encargo de ajustar los detalles que faltaban. En el caso del grupo de programación terminaron de programar las gráficas de las superfices generadas y se corrigieron detalles correspondientes al método. El grupo de testing termino exitosamente su tarea. Y el project manajer termino el reporte y cerro los issues correspondientes a esta entrega.

Especificamente el grupo de programación para lograr generar las gráficas tuvo que, primero, ejecutar un grid search (lo cual era costoso en algunos casos) y se apoyaron de AWS. La evidencía se puede ver [aquí.](https://github.com/David-Damian/Optimization-Delaunay-surfaces/tree/main/evidencias_AWS)
    
Posteriormente se realizaron reuniones para revisar el trabajo grupal, eso con la finalidad de hacer correcciones más profundas y además asegurar que todo el equipo conociera todos los detalles del trabajo. Estas reuniones fueron muy útiles para correciones correspondientes al reporte final.
    
Por último se realizó otra junta para acordar la división de roles en la presentacion final, la cual se ensayo y se dejo lista para su exposición en el salón de clases.

### Grupo de programación [David-Damián](https://github.com/David-Damian) y [JuanPalms](https://github.com/JuanPalms)

Se refinó la lógica de programación del método de Runge-Kutta ya que en ocasiones las soluciones de ecuaciones diferenciales  no eran correctas

Así mismo, programamamos la funcion `delunay` que se encuentra en la ruta `/src/utils1.py` de este respositorio. Dicha función nos permitió implementar una especie de *grid search* para encontrar hiperparámetros que nos permitieran generar las superficies de Delaunay.

#### Individual

[David-Damián](https://github.com/David-Damian): 

- Para generar [superficies de Delaunay](https://www.researchgate.net/publication/236935602_Delaunay_Surfaces), programé una función de modo que dadas condiciones iniciales para la ecuación diferencial se encontraran los mejores hiperparámetros y mediante rotación a lo largo del eje horizontal obtener algunas de estas supericies.

- También me encargué de contribuir a la mejora del reporte y comienzo de la presentación.

[JuanPalms](https://github.com/JuanPalms):

 - Me encargué de refinar la programación del método de Runge Kutta y de proponer *templates* en LaTeX en los cuales migraramos los avances del reporte del Aavance 1 y otro para la presentación final.
 
 - Añadí al reporte, la implementación en `Python` del problema de la braquistócrona.
 
 - También me encargué de contribuir a la mejora del reporte.

### Grupo de revisión [AlbertoMandujanoMontes](https://github.com/AlbertoMandujanoMontes)
- Me encargué de escribir los scripts de testeo de las funciones de integración.
- Reemplace el testeo dummy por las pruebas finales, incluyendo 2 ecuaciones que se presentan en el proyecto y 2 ecuaciónes base, para validar el proceso.

### Project manager [ValeriaRoberts](https://github.com/ValeriaRoberts)

Se solucionaron los 3 Issues restantes:
* ***3.1 Programación para resolver el problema*** asignado a [David-Damián](https://github.com/David-Damian) y [JuanPalms](https://github.com/JuanPalms)
* ***4. 1 Final Testing*** asignado a [AlbertoMandujanoMontes](https://github.com/AlbertoMandujanoMontes)
* ***5.1 Reporte Final*** asignado a [ValeriaRoberts](https://github.com/ValeriaRoberts)

Correspondientes al *milestone* 2 que esta asociado al segundo avance.

Además se terminó el Reporte final. Donde se incluyeron las siguientes secciones que quedaron pendientes del avance 1:
* Antecedentes históricos del problema de optimización
* Resultados
    * Interpretación de los resultados
* Conclusión
* Bibliografía

Por último se hizo la presentación correspondiente al trabajo con los puntos que se consideran más relevantes. Debido a la extensión del trabajo final solo se incluyo lo fundamental para la comprehensión de mis compañeros. 
