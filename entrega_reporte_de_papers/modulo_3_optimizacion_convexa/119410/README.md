---
title: "Convex Optimization for Big Data"
author: "Thalía Guerra"
date: "30 de mayo de 2018"
output: html_document
---

En la última década ha aumentado la importancia de la optimización convexa por las nuevas teorías y modelos estadísticos de aprendizaje. Este aumento en la importancia se debe principalmente a la existencia de algoritmos eficientes para calcular soluciones óptimas y a la habilidad de utilizar la geometría convexa para comprobar propiedades de la solución.

El uso de bases de datos muy grandes no permite que los problemas de optimización se procesen localmente y para las que las rutinas básicas de algebra lineal son prohibitivas. 

Los algoritmos de optimizacón para Big Data tienen tres fundamentos:

1. Métodos de Primer Orden: 

Se pueden obtener soluciones numéricas medianamente exactas usandodescenso drasiente, aun cuando las funciones objetivo no sean suaves. Usar descenso en gradiente, aunque requiere de más iteraciones para alcanzar el mínimo global, requiere de menos tiempo por iteración que otros algoritmos más complicados. El uso de descenso en gradiente además requiere de métodos computacionales sencillos y funciona para problemas no suaves y con pocas o nulas restricciones. Adicionalmente, es posible modificar la forma funcional del problema de minimización para mejorar las capacidades computacionales y de modelaje. Esto puede ayudar a aplicar Métodos de Primer Orden en aplicaciones como Análisis Robusto de Componentes Principales o aprendizaje de grafos. Modificando la forma funcional se puede también resolver problemas usando el algoritmo ADMM (Alterning Direction Method of Multipliers), que es un buen candidato para optimización distribuida.

2. Aleatorización: 

Es muy utilizada para escalar los Métodos de Primer Orden porque permite controlar el comportamiento esperado. Algunas metodologías de aleatorización son: reemplazar los cálculos determinísticos con estimadores estadísticos y acelerar las rutinas de álgebra lineal básica aleatorizando. Esto es posible ya que los Métodos de Primer Orden son robustos a sus aproximaciones, que se pueden encontrar utilizando aleatorización. Esta técnica se puede utilizar, por ejemplo, para encontrar la solución al problema de Google Page Rank, aleatorizando la selección de la coordenada para encontrar la magnitud máxima de los elementos del gradiente. Dentro de los métodos de aleatorización se encuentra también el descenso gradiente estocástico, que actualiza todas las coordenadas de manera simultánea usando gradientes aproximados. Este método se usa, por ejemplo, para resolver modelos como OLS. La aleatorización es útil también para resolver operaciones de álgebra lineal básica. Utilizar metodos aleatorios para resolver este tipo de operaciones facilita su implementación en cómputo distribuido.

3. Cómputo paralelo y distribuido: 

Los Métodos de Primer Orden proveen un marco que permite distribuir las tareas de optimización e implementarlas en paralelo. Los métodos se pueden escalar aún más usando algoritmos asíncronos con comunicación descentralizada. Esto se debe a que la comunicación (comunicación desigual o defectuosa entre computadoras o dentro de la jerarquía de la memoria local) y la sincronización (cuando una de las computadoras tarda más que las otras, ya que los Métodos de Primer Orden requieren coordinación de las actividades de distintas computadoras sobre un mismo vector en cada iteración) impiden alcanzar un desempeño óptimo. Al paralelizar los Métodos de Primer Orden se logra una comunicación confiable entre procesadores uniformes. Algunos modelos de programación que paralelizan Métodos de Primer Orden son Hadoop, Spark, Mahout, MADlib, etc.

Estos tres conceptos se pueden combinar para lograr escalar los problemas para poder aplicarlos a Big Data. Dado que las restricciones de comunicación y sincronización dictan el algoritmo a utilizar, se espera que se descubran nuevas técnicas de aproximación que adapten los algoritmos convexos a la heterogeneidad de plataformas computacionales.