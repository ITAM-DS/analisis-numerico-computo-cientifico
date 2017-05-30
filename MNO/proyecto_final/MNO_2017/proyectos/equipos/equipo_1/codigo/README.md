## Equipo 1


---

**Integrantes:**
  
  - Paulina Salgado Figueroa - 160314
  - Gabriela Flores Bracamontes - 160124
  - Guillermina Montanari Lujan - 101421

---

**Título del proyecto:** Optimización del Algoritmo Word Embeddings utilizando CUDA c, cómputo en paralelo y matricial.

**Objetivo del proyecto:** Nuestro objetivo en este proyecto es aplicar técnicas de cómputo en paralelo y matricial para optimizar el algoritmo de Word Embeddings.

Calendario:
- 07Abril2017: Definir el alcance del proyecto, discutirlo con Erick y buscar referencias a los temas que vamos a resolver.
- 17Abril2017: Comenzamos la investigación del algoritmo Word2Ved.
- 24Abril2017: Cambio del Algoritmo al entrenamiento de una Red Neuronal Multicapa.
- 02Mayo2017: Análisis del algoritmo completo: entrenamiento con los cálculos de las probabilidades conjuntas, la tasa de aprendizaje, gradiente descendente para minimizar los errores y finalmente el cálculo de los nuevos pesos ajustados.
- 08Mayo2017: Continuamos analizando los componentes del algoritmo. Comenzamos a trabajar en los entregables del proyecto de una vez, para que se vayan reflejando, en el codigo, el documento y la presentacion los avances que llevamos.
- 15Mayo2017: Encontramos una alternativa de optimizacion del algoritmo de softmax a softmax jerarquico, que utiliza árboles binarios de Huffman para armar los caminos de las cercanías de las palabras usando la representación del codigo binario de la palabra dado el contexto
- 1era semana finales: Incorporamos una sección con las estructuras de Datos del algoritmo.
- 2da semana finales: 


**Referencias:**

* [word2vec Explained:  Deriving Mikolov et al.’sNegative-Sampling Word-Embedding Method.] (https://arxiv.org/pdf/1402.3722.pdf)

* [Tomas Mikolov, Kai Chen, Greg Corrado, and Jeffrey Dean. Efficient estimation of word representations in vector space.] (https://arxiv.org/pdf/1301.3781.pdf)

* [Tomas Mikolov, Ilya Sutskever, Kai Chen, Gregory S. Corrado, and Jeffrey Dean. Distributed representations of words and phrases and their compositionality. In Advances in Neural Information Processing Systems 26: 27th Annual Conference on Neural Information Processing Systems 2013.] (https://papers.nips.cc/paper/5021-distributed-representations-of-words-and-phrases-and-their-compositionality.pdf)

---