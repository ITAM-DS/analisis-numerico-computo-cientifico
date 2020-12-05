# avance2  

**Update: Cambio de Proyecto**  
_______
> Durante la sesisón de revisión de avances1 con Prof. Erick el día de 1ero de Diciembre, nos comentó que existía otro equipo que también realizaría el método de PCA
([ver avance1](https://github.com/Rodriguit/analisis-numerico-computo-cientifico/tree/optimizacion-2020-2/proyecto_final/proyectos/equipos/equipo_hessiano/avance1)).
Posteriormente, en la clase del miércoles 2 de Diciembre mencionó que ya había 4 equipos que realizarón PCA, algo que nos motivo a realizar una reunión de emergencia y analizar si continuar PCA o replantear. Se decidió por votación cambiar el problema planteado.  

**Inetegrantes y Roles del Equipo:**  
_______

| Github_User  | Alumno    | Scrum Rol                      |
|:------------:|:---------:|:-------------------------------|
| @lobolc      | Miguel    | Solución y Programación        |
| @jreyesgar93 | José      | Solución y Programación        |
| @Rodriguit   | Rodrigo   | Programación y Revisión        |
| @ZarCorvus   | José Luis | Project Manager                |

### Trabajo:  
_______

### Project manager  
_______

 * Se construye el diseño del Proyecto con los milestones e Issues requeridos para el proyecto.  
 * Se diseñan las sesiones y la forma de trabajo inspirado en el modelo Scrum para analizar los avances diarios con comunicación.  
 * Se da continuidad y seguimiento para el desarrollo adecuado del proyecto.  
  * Se realizó la documentación de diversas fuentes que nos permitieran plantear este problema.  
 * Concluimos el Milestone "Infraestructura", "Cómputo en la Nube" #3  
    - Se constrye la infraestructura de AWS y se abren los puertos para el equipo utilizando un Docker file, creando una instancia EC2 Ubuntu:Bionic. Issue 3Cómputo en la Nube  

Se trabaja en el issue **Solución del Problema #4**, asociado al Milestone "Definición e Investigación del Problema"   
    * Se analizaron las diversas opciones de temas que podríamos seleccionar para redefinir nuestro problema (proyecto). Se decidió el siguiente problema:  
      - ## Método de Máxima Verosimilitud como problema de Optimización (maximizar)  
      - Métodos de Optimización a aplicar**: Descenso en Gradiente y Newton-Raphson  
    * Se decidió que para demostrar la aplicación de nuestra solución al problema planteado sea la estimación de parámetros para una distribución normal mediante método de  
    descenso en gradiente  
    * Se decidió que para demostrar la aplicación de nuestra solución al problema planteado sea la estimación de parámetros para una distribución Poisson mediante método de  
    Newtow-Raphson  

Se trabaja en el Issue **Reporte Escrito #1**, asociado el Milestone "Reporte Escrito y Presentación"  
    * Se crea el ambiente para la integración del reporte en Overleaf.  
    * Se inicia la construcción de nuestro reporte en Overleaf, segmentando los temas que cada integrante estaría desarrollando  


### Grupo de programación:**  
_______   

Se trabaja en el Issue **Programación de la Solución #5**, asociado el Milestone "Solución del Problema y Programación"  
    * Se desarrolló la función de verosimilitud y el estimador de máxima verosimilitud para la distribución de Poisson.  
    * Se construye la función de Newton Raphson  
    * Cree una calse con las funciones normal_loglikelihood, gradient_normal_loglike  
    * Diseñé la función de verosimilitud y el método de gradiente  
    * Construí un bosquejo de un primer reporte con apoyo de las funciones creadas.  
    * Se construye un bosquejo de la primer solución al problema con el dataset "wheat_yield.txt", el cual tiene uns distribución normal.  

### Grupo de revisión  
_______
* Se realizaron pruebas para validar la viabilidad del proyecto dado el tiempo restante del que disponemos  

### Trabajo continúa...  

- Finalizar Issue Reporte Escrito #1  
- Finalizar Issue Implementación a Distribuciones Conocidas #6   
- Finalizar Issue Presentación #2  




