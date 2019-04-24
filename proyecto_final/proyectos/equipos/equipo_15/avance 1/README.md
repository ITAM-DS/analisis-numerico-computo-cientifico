# Avance 1

Integrantes:

* Vianney Sánchez Gutiérrez 167229

* Juan B. Martínez Parente Castañeda 124458

## Trabajo:

### Equipo

El autor del [_paper_ principal](https://pdfs.semanticscholar.org/480a/daf38839240567e82e999b35a8ee7a214d5d.pdf) (Yang, 2018) resuelve el problema con OCO (_Online Convex Optimization_). Nosotros queremos basarnos en el planteamiento del problema de optimización que da el autor pero utilizando algún método _offline_.

### Individual

#### Vianney: 

Profundicé en el problema de minimización relajado que propone Yang, basándose
en el [_paper_ de Sungjin Im _et al._](https://users.cs.duke.edu/~kamesh/psp_focs15.pdf),
para entender mejor el problema convexo con restricciones que es, finalmente, el 
que queremos resolver.


#### Juan:

Estoy investigando sobre métodos _offline_ que podamos implementar para resolver
el problema de minimización con restricciones. De entrada, queremos probar el 
método de Newton (o alguno cuasi-Newton) e idealmente queremos poder implementar 
algún otro, como el método de puntos interiores, y compararlos. Si alcanza el
tiempo, me gustaría encontrar alguna heurística interesante para resolver el 
problema de minimización entera (que es NP-completo).
