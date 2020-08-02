# Tarea 3

Realiza un programa en el que se impriman las entradas impares de un arreglo y las direcciones de memoria también en las posiciones impares. Define dos funciones que realicen las impresiones en pantalla. Las funciones como mínimo reciben un apuntador y funcionan para arreglos de una dimensión y de dos dimensiones.

Por ejemplo, si tengo un arreglo de tamaño 10:


```
p[0]:-1
p[1]:-2
p[2]:-3
p[3]:-4
p[4]:-5
p[5]:-6
p[6]:-7
p[7]:-8
p[8]:-9
p[9]:-10
```

Con direcciones de memoria:

```
&p[0]:0x7fff5d5ef090
&p[1]:0x7fff5d5ef094
&p[2]:0x7fff5d5ef098
&p[3]:0x7fff5d5ef09c
&p[4]:0x7fff5d5ef0a0
&p[5]:0x7fff5d5ef0a4
&p[6]:0x7fff5d5ef0a8
&p[7]:0x7fff5d5ef0ac
&p[8]:0x7fff5d5ef0b0
&p[9]:0x7fff5d5ef0b4

```

Entonces la función 1 imprime:

```
p[1]=-2
p[3]=-4
p[5]=-6
p[7]=-8
p[9]=-10

```


La función 2 imprime:

```
&p[1]=0x7fff5d5ef094
&p[3]=0x7fff5d5ef09c
&p[5]=0x7fff5d5ef0a4
&p[7]=0x7fff5d5ef0ac
&p[9]=0x7fff5d5ef0b4
```

Si tengo un arreglo multidimensional:

```
arreglo_mult[0][0] =-1	arreglo_mult[0][1] =-2	arreglo_mult[0][2] =-3
arreglo_mult[1][0] =-4	arreglo_mult[1][1] =-5	arreglo_mult[1][2] =-6
```

Con direcciones de memoria:

```
&p[0]:0x7fff5d5ef090	&p[1]:0x7fff5d5ef094	&p[2]:0x7fff5d5ef098
&p[3]:0x7fff5d5ef09c	&p[4]:0x7fff5d5ef0a0	&p[5]:0x7fff5d5ef0a4
```

La función 1 imprime:

```
p[1]=-2
p[3]=-4
p[5]=-6
```

Y la función 2 imprime:

```
&p[1]=0x7fff5d5ef094
&p[3]=0x7fff5d5ef09c
&p[5]=0x7fff5d5ef0a4

```




