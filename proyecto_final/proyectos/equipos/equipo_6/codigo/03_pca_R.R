library(tidyverse)
#PCA

dta_clean <- read_csv('data/data_clean.csv')

dta_f1 <- dta_clean %>% 
  filter(fecha == 2015) %>% 
  select(-fecha) 

princ <- dta_f1 %>% 
  select(-estado) %>% 
  princomp()

princ$loadings[1:28, 1:28] %>% 
  as_tibble()

princ$sdev
