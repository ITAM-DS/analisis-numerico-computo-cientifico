# Implementación en R del Algoritmo Toom Cook 

# Cargando librerías necesarias----
library(stringr) # creo que ni la usé 

# Cargando funciones necesarias----

calcula_base <- function(num_1,num_2,b,k){
  i <- max(floor(floor(log(x = as.numeric(num_1), base= b))/k),
           floor(floor(log(x = as.numeric(num_2), base= b))/k))
  i <- i+1
  return(i)
}

separa_en_secciones <- function(cadena, tamanio_max_secciones){
  "Esta función recibe el número como caracter y el tamaño máximo de las secciones
  y lo separa en pedazos del tamaño correcto. Devuelve un vector con el número seccionado"
  num_secciones <- ceiling(nchar(cadena)/tamanio_max_secciones)
  numero_seccionado <- vector(mode="character")
  for(i in 1:num_secciones){
    numero_seccionado[num_secciones+1-i] <- substr(x = cadena,
                                                   start = max(1,(nchar(cadena)-i*tamanio_max_secciones+1)),
                                                   stop = nchar(cadena)-((i-1)*tamanio_max_secciones))
  }# for 
  return(numero_seccionado)
}# function separa_en_secciones

define_numero_de_puntos_a_evaluar <- function(k_m,k_n){
  num_puntos_a_evaluar <- k_m + k_n -1
  return(num_puntos_a_evaluar)
}#function define_numero_de_puntos_a_evaluar

rellena_matriz_evaluada <- function(valores_a_evaluar, num_columnas, num_puntos_a_evaluar){
  
matriz_final <- matrix(ncol=num_columnas, nrow=num_puntos_a_evaluar)

   for(i in 1:num_puntos_a_evaluar){
    for(k in 1:num_columnas){
      matriz_final[i,k] <-  valores_a_evaluar[i]^(num_columnas-k)
    }#for anidado
  }#for

  return(matriz_final)
}#function

# Declaración de variables----
# m_original <- "1234567890123456789012"
# n_original <- "987654321987654321098"
# m_original <-"831275469"
# n_original <-"897512436"
m_original <- "1234567890123456789012"
n_original <- "987654321987654321098"
base_b <- 10
exponente_inicial_b <- 4
b <-base_b ^ exponente_inicial_b # esto es un ejemplo, 10^4 es un buen inicio
k <-3

# Calculamos la i y el tamaño máximo de las secciones----
# B=b^i si b es 10^4 entonces i*4 es el tamaño de máximo de los pedacitos

i <- calcula_base(num_1 = m_original,
                  num_2 = n_original,
                  b = base_b^exponente_inicial_b,
                  k = k)

tamanio_max_secciones <- i*exponente_inicial_b

# eligiendo el tamaño de las secciones a lo salvaje ---- 
secciones<-3
len<-1
longitud_max <- secciones*len
while(nchar(m_original)>longitud_max | nchar(n_original)>longitud_max){
 if(len<8){
  len <- len+1
 } else {
   len <- 1
   secciones <- secciones +1
 }
  longitud_max <- secciones*len
}


# Separamos los números originales en k secciones de tamaño máximo "tamanio_maximo_secciones"----

m_vector <- separa_en_secciones(cadena = m_original,
                                tamanio_max_secciones = tamanio_max_secciones)

n_vector <- separa_en_secciones(cadena = n_original,
                                tamanio_max_secciones = tamanio_max_secciones)

# Definimos el número de puntos a evaluar ----
# esto es un cálculo super sencillo (lo especifico por si k_m y k_n llegaran a ser diferentes)
num_puntos_a_evaluar <- define_numero_de_puntos_a_evaluar(k_m = k,
                                                          k_n = k)

# Elegimos la matriz correcta ----

valores <- c(0,1,-1,2,-2)
matriz_evaluada_p_q <- rellena_matriz_evaluada(valores_a_evaluar = valores,
                                               num_columnas = 3,
                                               num_puntos_a_evaluar = num_puntos_a_evaluar)

matriz_evaluada_r <- rellena_matriz_evaluada(valores_a_evaluar = valores,
                                             num_columnas = 5,
                                             num_puntos_a_evaluar = num_puntos_a_evaluar)


# Encontramos el vector r(x) <- p(x)q(x) ----

vector_r <-(matriz_evaluada_p_q%*%as.numeric(m_vector))*(matriz_evaluada_p_q%*%as.numeric(n_vector))

# Resolvemos para encontrar los sumandos a utilizar----

sumandos <- solve(a=matriz_evaluada_r,b=vector_r)

# dividimos estos mismos en secciones del mismo tamaño----

sumandos_char <- as.character(trunc(sumandos))

num_columnas_matriz_final <- length(sumandos_char)+1
# creamos una matriz con las columnas necesarias y una fila extra para sumar los que llevamos----
matriz_suma_posicionada <- matrix(data=rep("0",(num_columnas_matriz_final*num_columnas_matriz_final)),
                                  ncol = num_columnas_matriz_final,
                                  nrow = num_columnas_matriz_final)
sumando_a_acomodar <- vector(mode="character")

# Relleno matriz sumandos ----

for(i in num_columnas_matriz_final:2){
  sumando_a_acomodar <- separa_en_secciones(cadena = sumandos_char[i-1],
                                            tamanio_max_secciones = tamanio_max_secciones)
  for(j in length(sumando_a_acomodar):1){
    matriz_suma_posicionada[i,i-length(sumando_a_acomodar)+j] <- sumando_a_acomodar[j]
  }#for anidado1
}#for

# sumamos matriz y guardamos en el vector resultado_seccionado ----
resultado_seccionado <- vector(mode="character")
options(scipen=999)
for(i in ncol(matriz_suma_posicionada):1){
  suma_auxiliar <- as.character(sum(as.numeric(matriz_suma_posicionada[,i])))
  if(nchar(suma_auxiliar)>tamanio_max_secciones & i !=1){
    matriz_suma_posicionada[1,i-1] <- substr(suma_auxiliar,
                                             start = 1,
                                             stop = nchar(suma_auxiliar)-tamanio_max_secciones)
    
    resultado_seccionado[i] <- substr(suma_auxiliar,
                                      start = nchar(suma_auxiliar)-tamanio_max_secciones+1,
                                      stop = nchar(suma_auxiliar))
  }else{
    resultado_seccionado[i] <- suma_auxiliar
  }#if
}#for

# Juntamos las secciones en un solo número-caracter ----
resultado_final <- str_c(resultado_seccionado,collapse = "")
