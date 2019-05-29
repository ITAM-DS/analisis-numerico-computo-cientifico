setwd("C:/Users/MB84276/Documents/MCD/MNO/proyecto final")
source("CN_versión_función.R")
source("TDMA_function.R")
source("gráficas_tiempo_CN.R")

#Ejemplo.
CN(r=.08,s=.2,E=120,Smax=160,Tmax=1,Malladim=15,PUT=1)

library(ggplot2)

Int2<-seq(10,1000, by=30)
Int<-seq(10,1000, by=30)
tm<-seq(10,1000, by=30)

k<-1

for(i in Int){
  start_time <- Sys.time()
  try(Int[k]<-CN(r=.08,s=.2,E=120,Smax=160,Tmax=1,Malladim=i,PUT=1))
  
  tm[k]<-end_time-start_time
  rm(start_time)
  rm(end_time)
  k<-k+1
  print(k)
}

#Dimensi?n de la malla
#Int2<-Int2[-c(15,31)]
Int2

#Valor calculado
#Int<-Int[-c(15,31)]
Int

#Tiempo de ejecuci?n
#tm<-tm[-c(15,31)]
#tm[21:32]<-tm[21:32]*60
tm

Dat<-as.data.frame(cbind(Tiempo=tm, Malla=Int2, Valor=Int))

ggplot(Dat,aes(x=Malla,y=Valor))+geom_line(colour = "red") + theme_bw() + ggtitle("Convergencia") 

ggplot(Dat,aes(x=Malla,y=Tiempo))+geom_line(colour = "red") + theme_bw() + ggtitle("Tiempo en segundos vs tama?o del sistema") 

Dat$Valor[-1]/Dat$Valor[-31]

plot.ts(abs(Dat$Valor[-1]-Dat$Valor[-31])/Dat$Valor[-31])




