## MNO: Proyecto final

# Función para determinar la columna o tiempo para salirse del contrato:

# Función:
indices <- function(m, r){
  # Para cada fila obtengo el indice del 1er. valor > 0:
  ids <- unlist(lapply(apply(m, 1, function(x) which(x>0)), function(l) l[[1]]))
  # Genero lista de la cantidad de registros:
  pos <- seq(1,length(ids))
  # Armo matriz con Posición + ID ibtenido en el 1er. paso facilitar el recorrido de los datos:
  ids_m <- matrix(c(pos, ids), ncol=2, byrow = FALSE)
  # Recorro la matriz original y para cada pos. tomo el valor del ID y calculo el precio:
  vps <- matrix(lapply(pos, function(i) m[ids_m[i],ids_m[i,2]] * exp(-1*ids_m[i,2]*r)))
  # Retorno matrix con: Posición, ID, VP: 
  ids_m <- cbind(ids_m, vps)
  return(ids_m)
}



# Datos de prueba - genero matriz con numeros aleaorios:
r <- 2
datos <- sample(0:3,30,replace=T) 
datos_m <- matrix(datos, ncol = 5, byrow = TRUE)
datos_m

vps <- indices(datos_m, r)
vps
