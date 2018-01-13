rm(list = ls())

library(tidyverse)
library(stringr)


data.raw <- read.table("print_out3.txt", sep = "\n")

#   -----------------------------------------------------------------------
seleccionar_numero <- function(x, pattern = "[0-9]*[0-9]", rank = FALSE){
  if(!rank){
    salida <- x %>%
      data.frame %>%
      setNames("V1") %>%
      mutate(start = str_locate(V1, pattern)[1],
             end = str_locate(V1, pattern)[2],
             posicion = str_sub(.[,1], start, end)) %>%
      arrange(posicion) %>%
      select(V1)
    return(salida)
  } else {
    salida <- x %>%
      data.frame %>%
      setNames("V1") %>%
      mutate(start = str_locate(V1, pattern)[1],
             end = str_locate(V1, pattern)[2],
             posicion = str_sub(.[,1], start, end)) %>%
      select(V1, posicion) %>%
      mutate(start = str_locate(V1, "rank")[1],
             end = str_locate(V1, "rank")[2],
             posicion2 = str_sub(.[,1], start+5, end+5)) %>%
      arrange(posicion, posicion2) %>%
      select(V1)
    return(salida)
  }
}


ordenar_mensajes <- function(df.raw){
  df_hi <- df.raw %>%
    filter(str_detect(V1, "Hi")) %>%
    seleccionar_numero()
  
  df_beforeProcess <- df.raw %>%
    filter(str_detect(V1, "Before: Process")) %>%
    seleccionar_numero()
  
  df_beforePhase <- df.raw %>%
    filter(str_detect(V1, "Before: Phase")) %>%
    seleccionar_numero(rank = TRUE)
  
  df_elapsed <- df.raw %>% 
    filter(str_detect(V1, "Elapsed"))
  
  df_afterProcess <- df.raw %>%
    filter(str_detect(V1, "After: Process")) %>%
    seleccionar_numero()
  
  df_afterPhase <- df.raw %>%
    filter(str_detect(V1, "After: Phase")) %>%
    seleccionar_numero(rank = TRUE)
  
  df_global <- df.raw %>%
    filter(str_detect(V1, "Global"))
  
  df_salida <- rbind(df_hi, df_beforeProcess, df_beforePhase, df_elapsed,
        df_afterProcess, df_afterPhase, df_global)
  return(df_salida)
}

data.raw %>%
  ordenar_mensajes() %>%
  write.table("output_orden.txt", row.names = FALSE, col.names = FALSE)

