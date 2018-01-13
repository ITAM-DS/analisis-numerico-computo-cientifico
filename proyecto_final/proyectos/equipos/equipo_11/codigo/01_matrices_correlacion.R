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

tab.cov <- cov(df.protein.c)
tab.cov
write.table(tab.cor, sep = " ",
            file = "doc/cov.txt",
            row.names = F, col.names = F)


write.table(diag(ncol(tab.cor)), sep = " ",
            file = "doc/ind.txt",
            row.names = F, col.names = F)




tab.cor %>% 
  data.frame(check.names = F) %>% 
  rownames_to_column() %>% 
  as_tibble() %>% 
  gather(var.lab, var.value, -rowname) %>% 
  ggplot(aes(x = rowname, y = var.lab, 
             color = var.value,
             size = abs(var.value))) + 
  geom_point() +
  scale_size_continuous(range= c(2, 9)) +
  scale_color_continuous(high = "red", low = "#4cc9c9") +
  theme(axis.text.x = element_text(angle = 90)) + 
  guides(color = guide_legend("Correlación"),
         size = guide_legend("Magnitud")) +
  ylab(NULL) + 
  xlab(NULL)
ggsave("graphs/cor_map.png", width =7, height = 6)

tab.pais.cor <- t(df.protein.c) %>% cor()
rownames(tab.pais.cor) <- df.protein$country
colnames(tab.pais.cor) <- df.protein$country

tab.pais.cor %>% 
  data.frame(check.names = F) %>% 
  rownames_to_column() %>% 
  as_tibble() %>% 
  gather(var.lab, var.value, -rowname) %>% 
  ggplot(aes(x = rowname, y = var.lab, 
             color = var.value,
             size = abs(var.value))) + 
  geom_point() +
  scale_size_continuous(range= c(.5, 6)) +
  scale_color_continuous(high = "red", low = "#4cc9c9") +
  theme(axis.text.x = element_text(angle = 90)) + 
  guides(color = guide_legend("Correlación"),
         size = guide_legend("Magnitud")) +
  ylab(NULL) + 
  xlab(NULL)
ggsave("graphs/pais_cor_map.png", width =7, height = 6)

