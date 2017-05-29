library(tidyverse)
library(foreign)


# Lectura de datos
df.protein <- read.spss("data/Proteina.sav", to.data.frame = T) %>% 
  dplyr::select(Country, Comunista:FrampVeg) %>% 
  as_tibble() %>% 
  mutate(Country = str_trim(Country))
names(df.protein) <- tolower(names(df.protein))
df.protein


apply(df.protein[, -1], 1, sum)
apply( is.na(df.protein), 2, sum)

df.protein



# Imprimir matrices
df.protein.c <- df.protein[, -1] %>% 
  scale(scale = F)

tab.cor <- cor(df.protein.c)
tab.cor
write.table(tab.cor, sep = " ",
            file = "doc/cor.txt",
            row.names = F, col.names = F)


write.table(diag(ncol(tab.cor)), sep = " ",
            file = "doc/ind.txt",
            row.names = F, col.names = F)

