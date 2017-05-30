library(ProjectTemplate)
load.project()

library(tidyverse)
library(xtable)

theme_set(theme_bw())

# Código anterior  para obtener datos originales
source("src/01_matrices_correlacion.R")

# Lectura de resultados
results <- read_delim("src/matriz_result.txt", 
                      " ", 
                      escape_double = FALSE, 
                      col_names = FALSE,
                      trim_ws = TRUE)
mat <- results %>% 
  select(X1:X10)
mat_mat <- as.matrix(mat)

#eigenvectores 
mat_eg <- matrix(NA, nrow = 10, ncol = 10)
norm_vec <- function(x) sqrt(sum(x^2))
eig <- c(norm_vec(mat$X1),
         norm_vec(mat$X2),
         norm_vec(mat$X3),
         norm_vec(mat$X4),
         norm_vec(mat$X5),
         norm_vec(mat$X6),
         norm_vec(mat$X7),
         norm_vec(mat$X8),
         norm_vec(mat$X9),
         norm_vec(mat$X10))

for(i in 1:length(mat)){
  mat_eg[,i] <- mat_mat[ , i]/eig[i] 
}

# write.table(eig, "vector_eig.txt")
# write.table(mat_eg, "matrix_eig.txt")



# Lectura de matriz resultante del método y eigenvalores
mat_vector <- read.table("src/matrix_eig.txt") %>% 
  dplyr::select(V1:V10)
dim(mat_A)

eigen_values <- read.table("src/vector_eig.txt") 
dim(eigen_values)

# Ordenamiento de eigenvalores y columnas
orden.eigenvalues <- order(eigen_values$x, decreasing = T)

eigevalues_ordenados <- eigen_values$x[orden.eigenvalues]
eigevalues_ordenados <- 10*eigevalues_ordenados/sum(eigevalues_ordenados)
eigenvectores_ordenados <- mat_vector[, orden.eigenvalues]



# Valores ordenados
eigenvalues <- eigevalues_ordenados
eigenvectors <- eigenvectores_ordenados %>% as.matrix()
dim(eigenvectors)
colnames(eigenvectors) <- 1:ncol(eigenvectors)
eigenvectors 


tab <- data.frame(eig = eigenvalues) %>% 
  mutate(`% Var` = round(100*eig/length(eigenvalues), 2), 
         `Acum % Var` = cumsum(`% Var`))
print(xtable(tab), include.rownames = T)

x_mat <- df.protein.c
rownames(x_mat) <- df.protein$country
x_mat %>% head


# Representación de individuos/paises para bigrafico
scores <- (x_mat %*% eigenvectors) 
scores_c <- scores %>% 
  scale(scale = T)
  
scores %>%  head
scores_c %>%  head

ggplot(data.frame(scores_c), aes(x = X1, y = X2)) + 
  geom_point(alpha = .5) + 
  geom_text(label = rownames(scores), check_overlap = T) + 
  ylab("Comp 2") +
  xlab("Comp 1")
ggsave("graphs/biplot_paises.png", width = 6, height = 6)


# Representación de variables/fuente para bigrafico
beta <-( t(scores)*(1/sqrt(eigenvalues))) %>% t()
loadings <- t(x_mat) %*% beta
loadings_c <- loadings %>% 
  scale(scale= T)
loadings %>% dim

ggplot(data.frame(loadings_c), aes(x = X1, y = X2)) + 
  geom_point(alpha = .5, color = "red") + 
  geom_text(label = rownames(loadings_c), color = "red") + 
  ylab("Comp 2") +
  xlab("Comp 1")
ggsave("graphs/biplot_fuente.png", width = 6, height = 6)



# Representación conjunta: Bigráfico
df.scores <- data.frame(scores_c) %>% 
  rownames_to_column()
df.loadings <- data.frame(loadings_c) %>% 
  rownames_to_column()

ggplot(data = df.scores, aes(x = X1, y =X2)) + 
  geom_point(alpha = .5) + 
  geom_text(aes(label = rowname), 
            alpha = .5, 
            nudge_x = .3) + 
  geom_point(data = df.loadings, 
             aes(x = X1, y = X2), 
             color = "red") +
  geom_text(data = df.loadings, 
            nudge_x = .3,
            aes(x = X1, y = X2, label = rowname), 
            color = "red", size = 5) +
  ylab( paste0("Comp 2: ", 
              round(100*eigenvalues[2]/length(eigenvalues)),
              "%") )+
  xlab( paste0("Comp 1: ", 
             round(100*eigenvalues[1]/length(eigenvalues)),
             "%") )+
  coord_fixed(ratio = .75) 
ggsave("graphs/biplot_alimentos.png", width = 6, height = 6)
