## Avance_24_04_2017

---

### Integrantes:

---

- Mariana Godina
- Sonia Mendizábal

### Trabajo:

---

#### Equipo

**Mariana y Sonia** 

Leímos el capitulo 8 de la refrencia de P.Pacheco. Parallel Programming with MPI. Sobre los I/O decidimos que la matriz que va a leer el algoritmo va a ser stdin. Pues leer un archivo es más complicado para MPI ya que es difícil el I/O para la programación en paralelo con MPI pero en el capítulo dan ejemplos para hacerlo. De los 3 métodos que describen para leer los datos en diferentes procesos, el *Cyclic distribution* para nuestro proyecto es la mejor opción. Concluimos que si transformamos la matriz de datos en un vector tal que al mandar cada entrada a un proceso, el proceso contenga bloques de la matriz.

- ¿Es esta una buena idea? 

Una vez definido esto lo incluiremos en el trabajo escrito y empezaremos la programación.

---