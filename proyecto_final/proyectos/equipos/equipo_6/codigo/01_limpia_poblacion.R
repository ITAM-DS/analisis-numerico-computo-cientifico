library(tidyverse)

pob <- read_csv('data/pob_mit_proyecciones.csv',
                locale = readr::locale(encoding = "latin1"))


pob %>% 
  filter(AÑO %in% 2015:2021,
         ENTIDAD != "República Mexicana") %>% 
  group_by(AÑO, ENTIDAD, CVE_GEO) %>% 
  summarise(across(POBLACION, sum),
            .groups = "drop") %>% 
  write_csv('data/poblacion_clean.csv')
