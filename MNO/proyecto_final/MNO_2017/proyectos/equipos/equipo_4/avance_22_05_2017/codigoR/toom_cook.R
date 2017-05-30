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
# m_original <- "7"
# n_original <- "8"
# m_original <- "78979879"
 m_original <- "1234567890"
 n_original <- "1234567890"
# m_original <- "1234567890123456789012"
# n_original <- "987654321987654321098"
# m_original <-"931275469"
# n_original <-"897512436"
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
tamanio_max_secciones <- 6
# Separamos los números originales en k secciones de tamaño máximo "tamanio_maximo_secciones"----
num_digitos<-18
ceros_m <-  str_c(rep("0",num_digitos - nchar(m_original)),collapse = "")
m_orig_rellenado <- str_c(c(ceros_m,m_original),collapse="")
m_vector <- separa_en_secciones(cadena = m_orig_rellenado,
                                tamanio_max_secciones = tamanio_max_secciones)

ceros_n <-  str_c(rep("0",num_digitos - nchar(n_original)),collapse = "")
n_orig_rellenado <- str_c(c(ceros_n,n_original),collapse="")
n_vector <- separa_en_secciones(cadena = n_orig_rellenado,
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
  inversa <- solve(a=matriz_evaluada_r)*24
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
  }else if(nchar(suma_auxiliar) < tamanio_max_secciones){
    ceros_sumando <-  str_c(rep("0",tamanio_max_secciones - nchar(suma_auxiliar)),collapse = "")
    suma_auxiliar_completa <- str_c(c(ceros_sumando,suma_auxiliar),collapse="")
    resultado_seccionado[i] <- suma_auxiliar_completa
  } else {
    resultado_seccionado[i] <- suma_auxiliar
  }
}#for

# Juntamos las secciones en un solo número-caracter ----
resultado_final <- str_c(resultado_seccionado,collapse = "")

#Creamos las funciónes---- 
multiplica_numerotes <- function(numerote1, numerote2){
  if(nchar(numerote1)<=18 & nchar(numerote2)<=18){
  m_original <- numerote1
  n_original <- numerote2
  tamanio_max_secciones <- 6
  # dividimos los números en secciones completando con ceros a la izquierda de ser necesario
  num_digitos<-18
  ceros_m <-  str_c(rep("0",num_digitos - nchar(m_original)),collapse = "")
  m_orig_rellenado <- str_c(c(ceros_m,m_original),collapse="")
  m_vector <- separa_en_secciones(cadena = m_orig_rellenado,
                                  tamanio_max_secciones = tamanio_max_secciones)
  
  ceros_n <-  str_c(rep("0",num_digitos - nchar(n_original)),collapse = "")
  n_orig_rellenado <- str_c(c(ceros_n,n_original),collapse="")
  n_vector <- separa_en_secciones(cadena = n_orig_rellenado,
                                  tamanio_max_secciones = tamanio_max_secciones)
  # definimos el número de puntos a evaluar
  k <- 3
  num_puntos_a_evaluar <- define_numero_de_puntos_a_evaluar(k_m = k,
                                                            k_n = k)
  
  # definimos las matrices que utilizaremos para evaluar 
  
  valores <- c(0,1,-1,2,-2)
  matriz_evaluada_p_q <- rellena_matriz_evaluada(valores_a_evaluar = valores,
                                                 num_columnas = 3,
                                                 num_puntos_a_evaluar = num_puntos_a_evaluar)
  
  matriz_evaluada_r <- rellena_matriz_evaluada(valores_a_evaluar = valores,
                                               num_columnas = 5,
                                               num_puntos_a_evaluar = num_puntos_a_evaluar)
  
  # encontramos el vector r para el cual buscaremos resolver 
  
  vector_r <-(matriz_evaluada_p_q%*%as.numeric(m_vector))*(matriz_evaluada_p_q%*%as.numeric(n_vector))
  
  # resolvemos el sistemirri 
  
  inversa <- solve(a=matriz_evaluada_r)*24
  sumandos <- solve(a=matriz_evaluada_r,b=vector_r)
  
  # dividimos en pedacillos y los acomodamos en la matriz correcta
  sumandos_char <- as.character(trunc(sumandos))
  num_columnas_matriz_final <- length(sumandos_char)+1
  matriz_suma_posicionada <- matrix(data=rep("0",(num_columnas_matriz_final*num_columnas_matriz_final)),
                                    ncol = num_columnas_matriz_final,
                                    nrow = num_columnas_matriz_final)
  sumando_a_acomodar <- vector(mode="character")
  
  #rellenamos la matriz-illa
  for(i in num_columnas_matriz_final:2){
    sumando_a_acomodar <- separa_en_secciones(cadena = sumandos_char[i-1],
                                              tamanio_max_secciones = tamanio_max_secciones)
    for(j in length(sumando_a_acomodar):1){
      matriz_suma_posicionada[i,i-length(sumando_a_acomodar)+j] <- sumando_a_acomodar[j]
    }#for anidado1
  }#for
  
  #sumamos posicionadamente
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
    }else if(nchar(suma_auxiliar) < tamanio_max_secciones){
      ceros_sumando <-  str_c(rep("0",tamanio_max_secciones - nchar(suma_auxiliar)),collapse = "")
      suma_auxiliar_completa <- str_c(c(ceros_sumando,suma_auxiliar),collapse="")
      resultado_seccionado[i] <- suma_auxiliar_completa
    } else {
      resultado_seccionado[i] <- suma_auxiliar
    }
  }#for
  resultado_final <- str_c(resultado_seccionado,collapse = "")
  }# ifsote  
  return(resultado_final)
}#function multiplica_numerotes

suma_numerotes <- function(numerote1, numerote2){
  # los números pueden ser de hasta 48 dígitos
  num_digitos<-48
  ceros_m <-  str_c(rep("0",num_digitos - nchar(numerote1)),collapse = "")
  m_orig_rellenado <- str_c(c(ceros_m,numerote1),collapse="")
  m_vector <- separa_en_secciones(cadena = m_orig_rellenado,
                                  tamanio_max_secciones = tamanio_max_secciones)
  
  ceros_n <-  str_c(rep("0",num_digitos - nchar(numerote2)),collapse = "")
  n_orig_rellenado <- str_c(c(ceros_n,numerote2),collapse="")
  n_vector <- separa_en_secciones(cadena = n_orig_rellenado,
                                  tamanio_max_secciones = tamanio_max_secciones)
  
  num_columnas_vector_final <- max(length(m_vector), length(n_vector))+1
  # creamos un vector que recibirá todos los pedacitos 
  vector_suma_seccionada <- vector(mode="character",length= num_columnas_vector_final)
  aux_suma_extra <-"0"
  for (seccion in num_columnas_vector_final:2){
    aux_suma_seccionada <- 0
    if(as.numeric(aux_suma_extra)!=0){
      aux_suma_seccionada <- as.character(sum(as.numeric(m_vector[seccion-1]), 
                                              as.numeric(n_vector[seccion-1]),
                                              as.numeric(aux_suma_extra)))
      aux_suma_extra <-0
    } else{
      aux_suma_seccionada <- as.character(sum(as.numeric(m_vector[seccion-1]), 
                                              as.numeric(n_vector[seccion-1])))
    }#if
    # casos para completar la suma
    if(nchar(aux_suma_seccionada)>tamanio_max_secciones){
      aux_suma_extra <- substr(x = aux_suma_seccionada,
                               start = 1,
                               stop = (nchar(aux_suma_seccionada)-tamanio_max_secciones))
      aux_suma_seccionada <- substr(x=aux_suma_seccionada,
                                    start= (nchar(aux_suma_seccionada)-tamanio_max_secciones+1),
                                    stop= nchar(aux_suma_seccionada))
    } else if(nchar(aux_suma_seccionada)<tamanio_max_secciones){
      ceros_sumando <-  str_c(rep("0",tamanio_max_secciones - nchar(aux_suma_seccionada)),collapse = "")
      aux_suma_seccionada <- str_c(c(ceros_sumando,aux_suma_seccionada),collapse="")
    } 
    vector_suma_seccionada[seccion] <- aux_suma_seccionada
  }
  suma_colapsada <- str_c(vector_suma_seccionada,collapse = "")
  return (suma_colapsada)
}# function suma_numerotes

## matrices a multiplicar ----
matriz1 <- matrix(data = c("1234567890","1234567890","78978978","7897879","78979879","34245322"), ncol = 2, nrow=3, byrow = TRUE)
matriz2 <- matrix(data = c("1234567890","1234567890","78978978","7897879","78979879","34245322"), ncol = 3, nrow=2, byrow = TRUE)

res_mult_1 <- multiplica_numerotes(matriz1[1,1], matriz2[1,1])
res_mult_2 <- multiplica_numerotes(matriz1[1,2], matriz2[2,1])
matriz_final <- matrix(data=rep("0",9), ncol=ncol(matriz2), nrow=nrow(matriz1))

for(rowfinal in 1:nrow(matriz_final)){
  for(colfinal in 1:ncol(matriz_final)){
    vectorsin1 <- matriz1[rowfinal,]
    vectorsin2 <-matriz2[,colfinal]
    sumandos <- vector(mode="character", length=length(vectorsin2))
    suma_total<-"0"
      for(i in 1:length(vectorsin2)){
        sumandos[i]<- multiplica_numerotes(vectorsin1[i],vectorsin2[i])
        suma_total <- suma_numerotes(suma_total,sumandos[i])
      }#for i
    matriz_final[rowfinal,colfinal]<- suma_total
  }#for colfinal
}#for rowfinal
