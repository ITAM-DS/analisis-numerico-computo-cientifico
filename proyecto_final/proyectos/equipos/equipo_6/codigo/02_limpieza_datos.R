library(tidyverse)

library(FactoMineR)

#importar datos
Sys.getlocale()
datos <- read_csv('data/IDEFC_NM_oct21.csv', 
                  locale = readr::locale(encoding = "latin1"))

poblacion <- read_csv('data/poblacion_clean.csv') %>% 
  rename(anio = AÑO,cve_ent = CVE_GEO, estado = ENTIDAD, poblacion = POBLACION)

data_yr_avg <- datos %>% 
  pivot_longer(Enero:Diciembre, "mes",values_to = "incidencia") %>% 
  mutate(fecha = as.Date(paste(Año,mes,"01", sep = '-'), format = "%Y-%B-%d")) %>% 
  filter(fecha <= "2021-10-01") %>% #distinct(tipo_delito) %>% print(n = 99)
  select(anio = Año, fecha,cve_ent = Clave_Ent,  tipo_delito =  `Tipo de delito`, incidencia) %>% 
  filter(!tipo_delito %in% c("Incesto", "Tráfico de menores", "Aborto", "Contra el medio ambiente",
                             "Incumplimiento de obligaciones de asistencia familiar")) %>% 
    filter(str_detect(tipo_delito, "Otros", T)) %>% 
  mutate(across(incidencia, ~replace_na(., 0))) %>%
  group_by(anio, cve_ent, tipo_delito, fecha) %>% 
  summarise(across(incidencia, sum), .groups = "drop_last") %>% 
  summarise(across(incidencia, mean), .groups = "drop") %>% 
  left_join(poblacion, by = c("anio", "cve_ent")) %>% 
  select(-cve_ent) %>% 
  mutate(inc_habs = 10e5*incidencia/poblacion) %>%  #inc por cada 100,000 habs
  select(-incidencia, -poblacion)


c("fecha", "estado", "abuso_de_confianza", "abuso_sexual", "acoso_sexual",
  "allanamiento_de_morada", "amenazas", "corrupcion_de_menores",
  "dano_a_la_propiedad", "delitos_cometidos_por_servidores_publicos", 
  "despojo", "electorales", "evasion_de_presos", "extorsion", "falsedad",
  "falsificacion", "feminicidio", "fraude", "homicidio", "hostigamiento_sexual",
  "lesiones", "narcomenudeo", "rapto", "robo", "secuestro", "trata_de_personas",
  "violacion_equiparada", "violacion_simple",
  "violencia_de_genero_en_todas_sus_modalidades_distinta_a_la_violencia_familiar",
  "violencia_familiar")-> clean_names

dta_clean <- data_yr_avg %>%
  group_by(anio, tipo_delito) %>% 
  mutate(inc_std = (inc_habs - mean(inc_habs))/sd(inc_habs)) %>% 
  ungroup() %>% #ggplot(aes(tipo_delito, inc_std))+ geom_boxplot()  
  select(-inc_habs) %>% 
  pivot_wider(names_from = tipo_delito,  values_from = inc_std) %>% 
  # janitor::clean_names() %>% 
  # names() %>% 
  # datapasta::vector_paste()
  set_names(clean_names)

dta_clean %>%
  select(-estado) %>% 
  filter(fecha == 2015) %>%
  summarise_all(mean) %>% 
  pivot_longer(-fecha, "delito", values_to = "inc") %>% 
  print(n = 99)
  mean()

dta_clean %>% 
  write_csv('data/data_clean.csv')
