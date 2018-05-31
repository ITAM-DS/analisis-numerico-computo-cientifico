# Verificación de librerias requeridas
packages <- c("tidyverse", "onehot")
if (length(setdiff(packages, rownames(installed.packages()))) > 0) {
    install.packages(setdiff(packages, rownames(installed.packages())))
    print("Instalando paquetes")
}

library(tidyverse)
library(onehot)
print("Cargando datos...")
data <- read.csv("flights.csv")

print("Limpiando datos...")
data <- data[,-c(1,3,6:11,14,19:31)]

data <- data %>% na.omit()

set.seed(138176)
train_index <- sample(1:nrow(data),nrow(data)*0.7)

cat_vars <- data[,1:3] %>% apply(.,2,as.factor) %>% as.data.frame()

encoder<- onehot(cat_vars, max_levels = 15, stringsAsFactors = TRUE)

cat_vars <- predict(encoder, cat_vars)
cat_vars <- cat_vars %>% as.data.frame()

num_vars_train <- data[train_index,-c(1:3)]
num_vars_val <- data[-train_index,-c(1:3)]

num_vars_train <- scale(num_vars_train)
num_vars_val <- scale(num_vars_val)

y_train <- num_vars_train[,1]
x_train <- data.frame(num_vars_train[,-1],cat_vars[train_index,])

y_val <- num_vars_val[,1]
x_val <- data.frame(num_vars_val[,-1],cat_vars[-train_index,])
print("Escribiendo datos de entrenamiento a archivos...")
write.table(y_train, file = "y_train.txt", sep = "\n",
            row.names = FALSE, col.names = FALSE)
write.table(x_train, file = "X_train.txt", sep = " ",
            row.names = FALSE, col.names = FALSE)
print("Escribiendo datos de validación a archivos...")
write.table(y_val, file = "y_val.txt", sep = "\n",
            row.names = FALSE, col.names = FALSE)
write.table(x_val, file = "X_val.txt", sep = " ",
            row.names = FALSE, col.names = FALSE)

