library(tidyverse)


indice_long <- read_csv('data/indice.csv') %>% 
  mutate(across(where(is.numeric), ~.*-1)) %>% 
  pivot_longer(-estado, "anio", values_to = "indice") %>% 
  mutate(across(anio, as.numeric))


ranking_avg <- indice_long %>% 
  group_by(estado) %>% 
  summarise(across(indice, mean)) %>% 
  arrange(-indice)


indice_long %>% 
  mutate(estado = factor(estado, levels = ranking_avg$estado)) %>% 
  ggplot(aes(anio, indice))+
  geom_line()+
  facet_wrap(~estado, ncol = 8)+
  theme_bw()+
  labs(x = "año")+
  ggsave('reporte/imgs/indice_por_estado.png', width = 12, height = 5.5)
