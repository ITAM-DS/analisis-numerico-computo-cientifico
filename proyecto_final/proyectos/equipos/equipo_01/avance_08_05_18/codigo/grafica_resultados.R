library(tidyverse)
library(ggplot2)

errores <- read_csv("error_sgd_sec.csv", 
                    col_types = list(
                      iteracion = col_integer(),
                      tot_iter = col_integer(),
                      rss_train = col_double(),
                      rss_val = col_double(),
                      lr = col_double()
                    ))

tidy_error <- errores %>% gather(key = "tipo_error", value = "valor_error", 3:4)

ggplot(tidy_error %>% group_by(lr)) +
  geom_point(aes(x = iteracion, y = valor_error, col = factor(tipo_error), shape = factor(tipo_error))) +
  facet_grid(~lr) +
  theme_bw()

ggsave("plot_errors.png", device = "png")

