**Notas para contenedor de docker:**

Comando de docker para ejecución de la nota de forma local:

nota: cambiar `<ruta a mi directorio>` por la ruta de directorio que se desea mapear a `/datos` dentro del contenedor de docker.

```
docker run --rm -v <ruta a mi directorio>:/datos --name jupyterlab_c_kernel_local -p 8888:8888 -d palmoreck/jupyterlab_c_kernel:1.1.0
```

password para jupyterlab: `qwerty`

Detener el contenedor de docker:

```
docker stop jupyterlab_c_kernel_local
```

Documentación de la imagen de docker `palmoreck/jupyterlab_c_kernel:1.1.0` en [liga](https://github.com/palmoreck/dockerfiles/tree/master/jupyterlab/c_kernel).

---

Nota generada a partir de [liga](https://www.dropbox.com/s/9fsupm3bhwmv7cb/1.2.Sistema_de_punto_flotante.pdf?dl=0)

# 1.2 Sistema de punto flotante

## Representación de los números en la computadora

Las computadoras utilizan una determinada cantidad de cifras de un número real para realizar operaciones. Además, utilizan una representación de los números en bases no usadas por las personas para realizar cálculos comunes, ejemplos son la **2, 8 o 16**.  En contraste, la mayoría de las personas utilizamos la base **10** para representar a los números y realizar cálculos.

A continuación se muestran construcciones que se han hecho para representar los números en una computadora.

### Enteros

Tenemos distintos métodos para la representación de los enteros en una computadora, pero uno que es más utilizado es el de "magnitud con signo" en el que se utiliza un bit para el signo del número y los bits restantes para almacenar al número. El primer bit se le da el valor de $0$ para  codificar al signo `+` y el valor $1$ codifica al bit `-`. Entonces el número $-173$ se almacena con la cadena de $16$ bits:

| | | | | | | | | | | | | | | | |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|1|0|0|0|0|0|0|0|1|0|1|0|1|1|0|1|



Utilizamos la notación posicional para convertir este número binario a base 10: el primer bit es $1$ por lo que se tiene un signo negativo. Luego:

$$0*2^{14} + 0*2^{13} + \dots+ 1*2^7+0*2^6+ 1*2^5+0*2^4+1*2^3+1*2^2+0*2^1+1*2^0 = 1*2^7+ 1*2^5+1*2^3+1*2^2+1*2^0 = 173$$

//%cflags:-lm
#include<stdio.h>
#include<math.h>
int main(){
    printf("suma: %f",pow(2,7)+pow(2,5)+pow(2,3)+pow(2,2)+pow(2,0));
    return 0;
}

**Ejercicio:**

Determina el rango de enteros de base $10$ que puede representarse en una computadora de $16$ bits utilizando el primer bit para el signo

### Reales

Dadas las limitaciones en el almacenamiento de una computadora (hardware), sólo se representa un subconjunto de los números reales en ella, tal conjunto se denota como $\mathcal{F}\mathcal{l}$ y contiene números racionales:

$$\mathcal{F}\mathcal{l} \subset \mathbb{Q} \subset \mathbb{R}.$$


**Un poco de historia...**
En 1985 la IEEE publicó un estándar de nombre [Binary Floating Point Arithmetic Standard 754-1985](https://standards.ieee.org/standard/754-1985.html) y ha habido más estándares publicados, siendo el más reciente el [IEEE 754-2019](https://standards.ieee.org/standard/754-2019.html). El estándar $754-1985$ proveía estándares para números de punto flotante binarios y decimales, formatos para intercambio de datos, algoritmos para operaciones de redondeo y manejo de excepciones. Los formatos se especificaron para precisiones simple, doble y extendida y tales estándares son seguidos por las manufactureras de computadoras que utilizan el hardware de punto flotante:

"...A family of commercially feasible ways for new systems to perform binary floating-point arithmetic is defined. This standard specifies basic and extended floating-point number formats; add, subtract, multiply, divide, square root, remainder, and compare operations; conversions between integer and floating-point formats; conversions between different floating-point formats; conversions between basic-format floating-point numbers and decimal strings; and floating-point exceptions and their handling, including nonnumbers..." (estándar $754-1985$)

## Sistema de punto flotante (SPF)

En un sistema de punto flotante se define:

1. Rango de un exponente definido por un límite inferior y uno superior.

2. Base del sistema.

3. Precisión.

Así, un número $x$ en el SPF, $x \in \mathcal{F}\mathcal{l}$, se representa de la forma:

$$\pm 0.d_1d_2 \dots d_k \times \beta^n .$$

donde:

$n$ es el exponente, $n \in [L,U] \cap \mathbb{Z}$ con $L, U$ fijos.

$k$ es la precisión.

$\beta$ es la base.

$d_i \in \{0,1,\dots,\beta-1\} \forall i=1,\dots,k$ son los dígitos.

**Obs:** a la parte $\pm 0.d_1d_2 \dots d_k$ se le llama **mantisa**. A la porción $d_2 \dots d_k$ se le llama **fracción $f$**.

Los números reales que tienen una representación exacta en el $\mathcal{F}\mathcal{l}$ se les conoce como **números de máquina**.

**Ejemplo:**

Supóngase un $\mathcal{F}\mathcal{l}$ con $\beta = 10, k=4, n\in[-4,3]\cap \mathbb{Z}$ entonces:

$$0.3330 \times 10^{-1} , 0.3300 \times 10^{3} \in \mathcal{F}\mathcal{L}$$

pero: $$\frac{1}{3} \notin \mathcal{F}\mathcal{l}$$

por lo que $0.333 \times 10^{-1} , 0.3300 \times 10^{3}$ son números de máquina.

## SPFN

Un Sistema de Punto Flotante Normalizado es aquel que cumple: $$d_1 \in \{1,2,\dots \beta -1\}.$$ para números distintos de cero.

**Obs: el número cero es el único que tiene dígitos de la mantisa y exponente iguales a cero.**

**Ejemplos:**

1) $\beta = 10, k=3$, rango del exponente en $[-3,3] \cap \mathbb{Z}$, entonces algunos números en el SPFN:

|Notación de punto flotante |Mantisa |Exponente|Valor de punto fijo|
|:---:|:---:|:---:|:---:|
|$0.153\times10^0$|$0.153$|$0$|$0.153$|
|$-0.990\times10^2$|$-0.990$|$2$|$-99.0$|
|$0.343\times10^{-3}$|$0.343$|$-3$|$0.000343$|


2) En un SPFN con $\beta=2, k=3$, rango del exponente en $[0,2] \cap \mathbb{Z}$ se tiene:

a) El número más grande positivo que es posible representar es:

$$0.111 \times 2^2 = (11.1)_2 = 1*2^1 + 1*2^0 + 1*2^{-1} = (3.5)_{10}.$$

b) El más chico positivo es:

$$0.100 \times 2^0 = (0.1)_2 = 1*2^{-1} = (0.5)_{10}.$$


**Obs: se utiliza $(\cdot)_{10}$ para representar un número en base 10 pero típicamente se omite escribir paréntesis y la base.**

**Obs2: la representación normalizada permite una representación única de los números reales en el $\mathcal{F}{l}$:**

el número $0.343 \times 10^{-3}$ como se vio en el ejemplo $1)$ está en $\mathcal{F}\mathcal{l}$ pero ni $0.0343 \times 10^{-2}$ ni $3.43 \times 10^{-4}$ están en el $\mathcal{F}\mathcal{l}$.

**Obs3: por la Obs2 en un SPFN con $\beta=2$ no es necesario almacenar el primer bit pues siempre es $1$ por lo que sólo se almacenará la parte fraccionaria de la forma $1.f$ (más sobre esto en la siguiente sección).**

## Números de máquina binarios

Un SPF de doble precisión utiliza:

* 64 bits para representar un número real. El primero es un indicador de signo denotado por $s$. Le siguen $11$ bits para construir al exponente $c$ llamado también **característica** y $52$ bits que construyen a la parte fraccionaria $f$ de la mantisa. La base es $\beta=2$.

**Nota 1: si es SPFN entonces aunque se tienen 52 bits, éstos se utilizan para almacenar un dígito más del número (ver Obs3 anterior). Así, en un SPF en general maneja 52 (o 53) dígitos binarios, que corresponden a aproximadamente 15 (o 16) dígitos decimales**. Ver: [Double-precision floating-point format](https://en.wikipedia.org/wiki/Double-precision_floating-point_format#Implementations).

//%cflags:-lm
#include<stdio.h>
#include<math.h>
int main(){
    printf("52 bits corresponden aproximadamente a: %f dígitos decimales\n", log10(pow(2,52)));
    printf("53 bits corresponden aproximadamente a: %f dígitos decimales\n", log10(pow(2,53)));
    return 0;
}

**Nota 2: los 11 bits que se utilizan para construir al exponente producen un rango de $0$ a $2^{11}-1=2047:$**

//%cflags:-lm
#include<stdio.h>
#include<math.h>
int main(){
    int suma = 0;
    int n=10;
    int i;
    for(i=0;i<=n;i++)
        suma+=pow(2,i);
    printf("Suma de 2^0 + 2^1 + ... + 2^10: %d", suma);
    return 0;
}

**pero esto construye un exponente con signo positivo, por lo que se resta (offset) la cantidad de $-1023$ de la característica y se tiene el rango del exponente en $[-1023,1024] \cap \mathbb{Z}$:**

$$2^{c-1023}.$$

Y un valor de $c=1023$ representa un exponente de $0$.

**Nota3: los valores $-1023$ (todos los bits iguales a $0$) y $1024$ (todos los bits iguales a $1$) para la característica se reservan para números especiales. Por esto, el exponente corre en el rango de $[-1022, 1023] \cap \mathbb{Z}$.**

**Nota4: todos los bits iguales a 0 para la característica se utiliza para representar al número 0 con signo (si su fracción $f$ es $0$) y a los números subnormales* (si su fracción $f$ es $\neq0$). Todos los bits iguales a 1 se utiliza para representar $\infty$ (si su fracción $f$ es $0$) y NaNs (si su fracción $f$ $\neq 0$).**

Entonces un número de máquina binario en un SPFN se representa por:

$$(-1)^s2^{c-1023}(1+f)$$

Y los subnormales como:

$$(-1)^s2^{1-1023}(0+f)=(-1)^s2^{-1022}f.$$

*Los números subnormales son todos aquellos números con magnitud menor al número más chico positivo normalizado. Con estos números se sacrifica precisión por representatividad alrededor del $0$. Para representar a estos números $d_1$ no es igual a $1$.

**Obs: hay dos representaciones para el $0$, una con signo positivo ($s=0, c=0, f=0$) y otra con signo negativo ($s=1,c=0,f=0$).**

**Ejemplos:**

1. El valor del exponente más chico para los números normales es: $2^{1-1023} = 2^{-1022}$.

2. El valor del exponente más grande es: $2^{2046-1023} = 2^{1023}$.


3. Considérese el número formado por:

primer bit: $0$.

bits de la característica: $10000000011$.

bits de la mantisa: $1011100100010\dots0$.

Entonces:

1. El número es positivo pues $s=0$: $(-1)^s = 1$.

2. Los bits de la característica generan al número decimal:

$$c = 1*2^{10} + 0*2^9+\dots+0*2^2+1*2^1+1*2^0=1024+2+1=1027$$

por lo que el exponente es $4$: $2^{1027-1023}=2^4$.

3. Los bits de la mantisa generan al número decimal:

$$1*2^{-1} + 1*2^{-3}+1*2^{-4}+1*2^{-5}+1*2^{-8} + 1*2^{-12} = 0.7229.$$

//%cflags:-lm
#include<stdio.h>
#include<math.h>
int main(){
    printf("Suma de 2^-1 + 2^-3 + 2^-4+2^-5+2^-8+2^-12: %f", pow(2,-1)+pow(2,-3)+pow(2,-4)+pow(2,-5)+pow(2,-8)+pow(2,-12));
    return 0;
}

Entonces el número de máquina binario $0$ $10000000011$ $1011100100010\dots0$ es el número decimal:

$$(-1)^s2^{c-1023}(1+f)=(-1)^{0}2^{4}(1+0.7229) =27.5664 $$


//%cflags:-lm
#include<stdio.h>
#include<math.h>
int main(){
    printf("2^4(1.7229): %f",pow(2,4)*1.7229);
    return 0;
}

## Valores interesantes en un SPFN de doble precisión

El número de máquina más grande positivo normalizado es: $$2^{1023}(1+(2^{-1}+\dots+2^{-52}))=2^{1023}(1+(1-2^{-52})) = 2^{1023}(2-2^{-52}) \approx 1.7977 \times 10^{308}.$$

#include<stdio.h>
#include<float.h>
int main(){
    printf("Numéro más grande positivo: %e\n", DBL_MAX);
    return 0;
}


Números que rebasen este límite superior resultan en un **overflow**:

//%cflags:-lm
#include<stdio.h>
#include<float.h>
#include<math.h>
int main(){
    printf("overflow: %e\n", DBL_MAX + 0.0000000000000001*pow(10,308));
    return 0;
}


**Ejercicio: da más ejemplos de ejecuciones como la anterior que resulten en overflow.**

El número de máquina **normalizado** más pequeño positivo es: $$2^{-1022}(1+0) \approx 2.2251 \times 10^{-308}.$$

#include<stdio.h>
#include<float.h>
int main(){
    printf("Numéro normalizado más chico positivo: %e\n", DBL_MIN);
    return 0;
}


El número de máquina no normalizado o **subnormalizado** más chico positivo es del orden de $2^{-1022}(2^{-52})=2^{-1074} \approx 10^{-324}$.

//%cflags:-lm
#include<stdio.h>
#include<float.h>
#include<math.h>
int main(){
    printf("Numéro más chico positivo: %e\n", pow(2,-52)*DBL_MIN);
    return 0;
}

Números con magnitud más chica que el valor anterior resultan en un **underflow**:

**Ejercicio: da más ejemplos de ejecuciones como la anterior que resulten en underflow.**

//%cflags:-lm
#include<stdio.h>
#include<float.h>
#include<math.h>
int main(){
    printf("Underflow: %e\n",(1-.5)*pow(2,-52)*DBL_MIN);
    return 0;
}

**Epsilon de la máquina $\epsilon_{maq}$**

//%cflags:-lm
#include<stdio.h>
#include<float.h>
#include<math.h>
int main(){
    printf("Epsilon de la máquina equivale aproximadamente a 2^(-53): %e\n", DBL_EPSILON/2);
    return 0;
}

El valor anterior representa el máximo error relativo* en la representación de un número real en su número de máquina. Como se observa en la ejecución anterior $\epsilon_{maq} \approx 2^{-53} \approx 1.11 \times 10 ^{-16}$ por lo que tenemos alrededor de $15$ o $16$ dígitos de precisión para un número real en el SPFN de doble precisión.

*Si `aprox` es mi cantidad con la que aproximo a mi objetivo `obj` entonces el error absoluto de `aprox` y el error relativo de `aprox` es:

$$ErrAbs(aprox) = |aprox - obj|.$$

$$ErrRel(aprox) = \frac{ErrAbs(aprox)}{|obj|}.$$

**Obs: si $ErrRel(aprox) \approx 10^{-k}$ se dice que `aprox` aproxima a `obj` con alrededor de $k$ dígitos correctos.**

**Obs2: otras definiciones para $\epsilon_{maq}$ son:**

* $\epsilon_{maq}$ es el número más chico positivo tal que: $1 + \epsilon_{maq} \neq 1$ a precisión de la máquina.

* $\epsilon_{maq}$ es la distancia del número $1$ al siguiente número de máquina.

Aunque las tres definiciones pueden diferir ligeramente, las tres pretenden dar la medida de granularidad de un SPF. Una representación gráfica para números positivos de un SPF es la siguiente:



<img src="https://dl.dropboxusercontent.com/s/bkxfiqni0f8izhi/SPFN_graficamente.png?dl=0" heigth="500" width="500">

y se tienen las siguientes afirmaciones:

* El intervalo $[1,2]$ en un SPFN de doble precisión está formado por la secuencia de números de máquina: $1, 1+ 2^{-52}, 1 + 2\times 2^{-52}, 1+ 3\times2^{-52}, \dots, 2$.

* El intervalo $[2,4]$ en tal sistema está formado por: $2, 2+ 2^{-51}, 2 + 2\times 2^{-51}, 2+ 3\times2^{-51}, \dots, 4$.

Por lo que el intervalo $[2^j, 2^{j+1}]$ se obtiene multiplicando $2^j$ veces la secuencia en $[1,2]$ y los huecos entre un número de máquina y otro número de máquina no son en términos relativos más grandes que $2^{-52} \approx 2.22 \times 10^{-16}$.

Asimismo, el intervalo $[\frac{1}{2}, 1]$ en tal sistema está formado por: $\frac{1}{2}, \frac{1}{2}+2^{-53},\frac{1}{2}+2\times2^{-53},\frac{1}{2}+3\times2^{-53},\dots , 1$.



Entonces el espaciado entre cada número de máquina en el intervalo $[2^j, 2^{j+1}]$ siempre es menor o igual a $2^{-53} = \epsilon_{maq}$. Para lo anterior, obsérvese que el espaciado en el intervalo $[2^j, 2^{j+1}]$ para los números de máquina es $2^{j-52}$ y por tanto: $\text{error_relativo}(\text{número de máquina}_{j+1} - \text{número de máquina}_{j})=\frac{2^{j-52}}{2^{j+1}} = 2^{-53}$.

**Obs2: una forma computacional de obtener al $\epsilon_{maq}$ de forma sencilla es con el cálculo:**

#include<stdio.h>
#include<float.h>
int main(){
    printf("Epsilon de la máquina: %e\n", 1-3.0*(4/3.0-1));
    return 0;
}

**Pregunta: ¿por qué funciona esto? tip: imprímase el cálculo $3.0*(4/3.0-1)$ con el especificador de formato de la función `printf` `%.16f` o bien `%.15e`**

## Reglas de corte y redondeo

Al ver el diagrama anterior de la representación gráfica de un SPF se observa que existen huecos entre cada número de máquina. Lo anterior implica que al ingresar un número real $x$ en la computadora, ésta realiza una aproximación a $x$ que se encuentre en el SPF. Esta aproximación genera errores conocidos con el nombre de **errores por redondeo**.

Entre las reglas que una computadora realiza para dar las aproximaciones a un número $x \in \mathbb{R}$ están: la regla de corte y la de redondeo y se pueden representar con funciones matemáticas:

**Regla de corte:** sea $fl_c : \mathbb{R} \rightarrow \mathcal{F}\mathcal{l}$ una función cuya regla de correspondencia es: $x \in \mathbb{R}$ con $x$ en el rango de valores del SPF, entonces: $x = \pm 0.d_1d_2 \dots d_kd_{k+1}\dots \times \beta^n$ y la regla de corte a $k$ dígitos es: $fl_c(x) = \pm 0.d_1d_2 \dots d_k$.

**Regla de redondeo:** sean $\beta=10$ y $fl_r : \mathbb{R} \rightarrow \mathcal{F}\mathcal{l}$ una función cuya regla de correspondencia es: $x \in \mathbb{R}$ con $x$ en el rango de valores del SPF, entonces: $x = \pm 0.d_1d_2 \dots d_kd_{k+1}\dots \times \beta^n$ y la regla de redondeo es:

 $$f_r(x) = \begin{cases}
\text{sumar uno a } d_k & \text{si } d_{k+1} \geq 5,\\
f_c(x) & \text{en otro caso}
\end{cases}$$

**Obs: también la regla $fl_r(\cdot)$ se define como antes pero se añade la restricción entre si es par o impar el último dígito en caso de empate, entonces se almacena el par.**

**Ejemplos:**

1)

$\pi=3.141592\dots = 0.3141592\dots \times 10^1$. Si un SPFN usa $k=5$ entonces:

$$fl_c(\pi) = 0.31415.$$

$$fl_r(\pi) = 0.31416.$$

2) Supóngase que $fl_r(\cdot)$ hace diferencia entre el último dígito almacenado es par e impar. Entonces para $k=2$:

|Número: x|Corte: $fl_c(x)$|Redondeo: $fl_r(x)$| 
|:--:|:--:|:--:|
|0.1649|0.16|0.16|
|0.1650|0.16|0.16|
|0.1651|0.16|0.17|
|0.1749|0.17|0.17|
|0.1750|0.17|0.18|
|0.1751|0.17|0.18|


Por los ejemplos anteriores se puede comprobar que la regla de redondeo tiene más exactitud que la de corte:

<img src="https://dl.dropboxusercontent.com/s/e8iqxqelkxj1y8r/regla_corte_redondeo.png?dl=0" heigth="500" width="500">

**Nota: otra expresión utilizada para la regla $fl(\cdot)$ es a partir de la definición de error relativo: $aprox = obj(1+ErrRel(aprox))$ (si $aprox \geq obj$ y $obj > 0$):**

$$\forall{x}\in \mathbb{R} \exists \epsilon \in \mathbb{R} \text{ con } |\epsilon| \leq \epsilon_{maq} \text{ tal que: }.$$

$$fl(x) = x(1+\epsilon), |\epsilon| \leq \epsilon_{maq}.$$

cuya interpretación es: la diferencia entre $x$ con $fl(x)$ es un término (en magnitud) de a lo más $\epsilon_{maq}$ relativo a $|x|$.

**Nota: un resultado que se puede verificar es:**

 $$\epsilon_{maq} = \begin{cases}
\beta^{1-k} &\text{ si se utiliza regla de corte},\\
\frac{1}{2}\beta^{1-k} &\text{ si se utiliza la regla de redondeo}
\end{cases}$$

**Ejemplo:**

Considérese un SPFN con $\beta=2, k=3$ entonces si se utiliza la regla de corte:

$$\epsilon_{maq} = \beta^{1-k} = \beta^{-2}=2^{-2}=0.25.$$

si se utiliza la regla de redondeo:

$$\epsilon_{maq} = \frac{1}{2}\beta^{1-k} = \frac{1}{2}\beta^{-2}=\frac{1}{2}2^{-2}=0.125.$$

## Aritmética de máquina.

Además de representar números reales en la máquina otro objetivo es el de realizar operaciones entre ellos. Si la representación de números tiene un error asociado (error por redondeo) entonces es natural pensar que las operaciones aritméticas también tendrán errores por redondeo. Las razones de los errores son nuevamente el uso de precisión finita y la conversión entre bases: al ingresar números a la computadora se convierte a base $2$ (por ejemplo), se realizan operaciones y el resultado se presenta en base $10$. 

Para analizar los errores por redondeo que se presentan en la aritmética de máquina es suficiente considerar la base $10$, no conversiones entre bases (por ejemplo de la base $2$ a la base $10$)) y utilizar los siguientes operadores y suposiciones:

Supongamos que se tiene un SPFN y $fl(\cdot)$ regla de corte o redondeo a una precisión $k$ dada. Sean $a,b \in \mathbb{R}$, se definen los siguientes operadores en el SPFN:

$$\oplus: \mathbb{R}^2 \rightarrow \mathcal{F}\mathcal{l} \quad a \oplus b = fl(fl(a) + fl(b)).$$


$$\ominus: \mathbb{R}^2 \rightarrow \mathcal{F}\mathcal{l} \quad a \ominus b = fl(fl(a) - fl(b)).$$


$$\otimes: \mathbb{R}^2 \rightarrow \mathcal{F}\mathcal{l} \quad a \otimes b = fl(fl(a) \cdot fl(b)).$$


$$\oslash: \mathbb{R}^2 \rightarrow \mathcal{F}\mathcal{l} \quad a \oslash b = fl(fl(a) \div fl(b)).$$


**Ejercicio:**

Considérese $x = \frac{5}{7} \approx \overline{0.714285}$, $y=\frac{1}{3} = \overline{.3}$, $u=0.714251, v=98765.9, w=0.111111 \times 10^{-4}$ y un SPFN con $\beta=10, k=5$. Entonces llenar la siguiente tabla de acuerdo a las instrucciones: 

1. En la columna "Aritmética de máquina con k=8" se realiza aritmética a $8$ dígitos con las operaciones definidas previamente $\oplus, \ominus, \otimes, \oslash$ con la regla de corte $fl_c(\cdot)$. 

2. En la columna "Aritmética de máquina con k=5" se realiza aritmética a $5$ dígitos con las operaciones definidas previamente $\oplus, \ominus, \otimes, \oslash$ con la regla de corte $fl_c(\cdot)$. 

3. Para el cálculo de errores absoluto y relativo tomar como valor real u objetivo el valor a $8$ dígitos.

|Operación|Aritmética de máquina con k=8| Aritmética de máquina con k=5|Error Absoluto de aprox|Error Relativo de aprox|
|:--:|:--:|:--:|:--:|:--:|
|x $\oplus$y|||||
|x$\ominus$y|||||
|x$\otimes$y|||||
|x$\oslash$y|||||
|x$\ominus$u|||||
|(x$\ominus$u)$\oslash$w|||||
|(x$\ominus$u)$\otimes$ v|||||
|u$\oplus$v|||||

**Ejemplo:**

El resultado del primer renglón con aritmética exacta es: 

$$x+y = \frac{5}{7} + \frac{1}{3} = \frac{22}{21} \approx 0.10476190.$$

Para el llenado de las columnas:

1. Aritmética de máquina a $8$ dígitos usamos $k=8$: $x \oplus_8 y = fl_c(0.71428571 + 0.33333333) = 0.10476190 \times 10^1$.

2. Aritmética de máquina usamos $k=5$: $x \oplus_5 y = fl_c(fl_c(x)+fl_c(y)) = fl_c(0.71428 + 0.33333) = fl_c(0.104761\times10^1) = 0.10476 \times10^1$.

3. Error absoluto de aprox: $ErrAbs(x \oplus_5 y) =  |(x \oplus_8) y - (x \oplus_5)| = |0.10476190 \times 10^1 - 0.10476 \times10^1| = |0.00000190| = .190 \times 10^{-5}$.

4. Error relativo de aprox: $ErrRel(x \oplus_5 y) = \frac{ErrAbs(x \oplus_5 y)}{|x \oplus_8|} =\frac{.190 \times 10^{-5}}{0.10476190 \times 10^1} \approx 1.81 \times 10^{-6} = 0.181 \times 10^{-5}$.

//%cflags:-lm
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double fl_c_k(double a, int k){
    return (double)((int)(pow(10,k)*a)*pow(10,-k));
}

double err_abs(double aprox, double obj){   
    return fabs(obj-aprox);
}

double err_rel(double errabs, double obj){
    return errabs/fabs(obj);
}

int main(){
    double x = 5/7.0;
    double y = 1/3.0;
    double res1=0;
    double res2=0;
    int k;

    k=8; //precisión 8
    printf("valor x a 8 dígitos: %0.7e\n", fl_c_k(x,k));
    printf("valor y a 8 dígitos: %0.7e\n", fl_c_k(y,k));
    res1 = fl_c_k(fl_c_k(x,k)+fl_c_k(y,k),k-1); //k-1 para seguir manteniendo 5 dígitos pues la suma aumenta un dígito
    printf("x+y a 8 dígitos %0.7e\n", res1);
    
    k=5; //precisión 5
    printf("valor x a 5 dígitos: %0.4e\n", fl_c_k(x,k));
    printf("valor y a 5 dígitos: %0.4e\n", fl_c_k(y,k));
    res2 = fl_c_k(fl_c_k(x,k)+fl_c_k(y,k),k-1); //k-1 para seguir manteniendo 5 dígitos pues la suma aumenta un dígito
    printf("x+y a 5 dígitos %0.4e\n", res2); 
    
    printf("--------\n");
    printf("Error absoluto de aprox: %e\n",err_abs(res2,res1));
    printf("Error relativo de aprox: %e\n",err_rel(err_abs(res2,res1),res1));
    return 0;
}

**Ejercicio: finalizar la tabla con un programa en C.**

**Solución de la tabla:** [liga](https://www.dropbox.com/scl/fi/oplgwf10lmve0fam0wvz8/respuestas.xlsx?dl=0&rlkey=j3ro10hw9ptvirpn38fadvi7a)

### Listando algunos problemas típicos que se presentan en la aritmética de máquina se tienen:

1. Problema de cancelación: pérdida de cifras significativas a partir de la resta de números similares.

2. Suma entre un número de magnitud grande y un número de magnitud pequeña.

3. Sumas con términos que involucren signos alternados. 

4. Multiplicación por un número de magnitud grande.

5. División por un número de magnitud pequeña.



### Posibles soluciones:

1. Usar mayor precisión.

2. Reordenar operaciones.

3. Reescribir expresiones matemáticas para obtener expresiones equivalentes.

4. Escalar las variables. También funciona estandarizarlas.


**Ejercicios**

1. Resuelve los ejercicios y preguntas de la nota.
2. Utiliza la notación posicional para representar al número $86409$ y $(1001.1)_2$ en base $10$.
3. ¿Cuáles de los siguientes números son números de máquina en un SPFN con $\beta=2$?

a. $(2.125)_{10}$.

b. $(3.1)_{10}$.

**tip: escribe los números anteriores como sumas de potencias de $2$.**

4. Considérese un SPFN con $\beta=2, k=3$. En este sistema se tienen $7$ bits para almacenar números. El primer bit se utiliza para el signo del número, el segundo bit se utiliza para el signo del exponente, los dos siguientes bits para construir al exponente y el último bit para construir a la mantisa. Entonces el número positivo normalizado más pequeño que es posible representar en este SPFN es:

$$(0111100)_2=(.5\times2^{-3})_{10}=.0625.$$

a. Escribe los siguientes números más grandes a este número que forman al SPFN hasta el valor más grande positivo que es posible representar en este SPFN.

b. Calcula las distancias entre los números con mismo valor de exponente.

c. Verifica que el error relativo para $x=0.156249$ utilizando la regla de corte es menor o igual a $\epsilon_{maq}=.25$ y el error relativo para $x=0.14$ utilizando la regla de redondeo es menor o igual a $\epsilon_{maq}=0.125$.


**Preguntas de comprehensión**.

1)¿Cuáles componentes definen  a un sistema de punto flotante?

2)Si un número tiene una representación exacta en la máquina, ¿qué nombre recibe?

3)¿Qué es un sistema de punto flotante normalizado?

4)Menciona algunas propiedades de un sistema de punto flotante normalizado.

5)¿Cuántos bits se utilizan en el hardware de una máquina para almacenar un número en un sistema de doble precisión?

6)¿Qué nombre reciben los errores que se generan por utilizar un sistema de punto flotante?

7)¿Cuáles reglas utiliza la máquina para dar aproximaciones a un número?

8)Explica con palabras la diferencia entre el epsilon de la máquina y el nivel de underflow:

a.¿Cuál de ellos depende únicamente del número de dígitos de la mantisa?

b.¿Cuál de ellos depende únicamente del número de dígitos del exponente?

c.¿Cuál de ellos no depende de la reglas usadas que se preguntaron en la pregunta 7?

9)Si calculamos un error relativo para una aproximación y resulta ser del orden de $10^{-8}$ ¿alrededor de cuántos dígitos correctos tengo en mi aproximación?

10)Menciona algunos problemas típicos de la aritmética de máquina y algunas formas de resolverlos.


**Referencias:**

1. R. L. Burden, J. D. Faires, Numerical Analysis, Brooks/Cole Cengage Learning, 2005.

2. M. T. Heath, Scientific Computing. An Introductory Survey, McGraw-Hill, 2002.

3. [Clases de C](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/clases).

