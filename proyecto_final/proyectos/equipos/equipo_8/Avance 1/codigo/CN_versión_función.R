#Método de Crank-Nicolson
#Método Implícito
#Variables Globales.
#r es la tasa de interés vigente.

#s es la varianza al cuadrado del activo.

#E es el precio strike del subyacente.

#Construimos la malla. Esta depende de cierto tiempo a la expiración, y algún
#valor máximo que pueda llegar a valer el activo en consideración.
#Smax > E pero la elección exacta dependerá del tipo de contrato.

#Por simplicidad tomaremos el tiempo como unitario. 

#Malladim es el tamaño de la partición para la variable tiempo y el
#Precio máximo del activo.

#Ejemplo.
CN(r=.08,s=.2,E=120,Smax=160,Tmax=1,Malladim=11,PUT=1)


CN<-function(r,s,E,Smax,Tmax,Malladim,PUT){
  
  #Dimensión de la malla.
  #Cordenada St, eje de las y´s.
  SM<-seq(0,Smax,length.out=Malladim)
  
  #Cordenada t, eje de las x´s.
  TM<-seq(0,Tmax,length.out=Malladim)  

  #Delta tiempo, coincide con el segundo elemento del vector TM.
  dt<-TM[2]
  #Delta Precio del subyacente, coincide con el segundo elemento del vector SM.
  dS<-SM[2]  
  
#Construye la malla vacía.
  Malla<-matrix(0,nrow=length(SM),ncol=length(TM))
  
#Matrices para resolver el sistema MLU^{n}=MRU^{n+1}+B
#ML es la matriz izquierda, mientra que MR la matriz derecha.  
  
aux=round((Smax/dS-1))
  
  MR=matrix(0,ncol=aux ,nrow=aux)
  ML=matrix(0,ncol=aux ,nrow=aux)
  
  
#################################################################################
#################################################################################
#Iniciamos la matriz ML:
  #Valores del primer renglón.
  j<-1
  ML[1,1]=1+(.5*s*(j^2)*dt)+r*dt/2
  ML[1,2]=(-.25*s*(j^2)*dt-(r*j*dt/4))  
  b0l=-.25*s*(j^2)*dt+r*j*dt/4
  
  #Valores para el último renglón.
  j<-(Smax/dS-1)
  ML[j,j-1]<-(-.25*s*(j^2)*dt+r*j*dt/4)
  ML[j,j]<-1+(.5*s*(j^2)*dt)+r*dt/2    
  bml=-(-.25*s*(j^2)*dt-(r*j*dt/4))
  
  #Valores para los demás renglones.
  k<-0
  for(j in 2:(Smax/dS-2) ){
    ML[j,k+1]=(-.25*s*(j^2)*dt+r*j*dt/4)
    ML[j,k+2]=1+(.5*s*(j^2)*dt)+r*dt/2
    ML[j,k+3]=(-.25*s*(j^2)*dt-(r*j*dt/4))
    k<-k+1
  }
#################################################################################
#################################################################################
#Iniciamos la matriz MR:
#Valores del primer renglón.
j<-1
MR[1,1]=1-(.5*s*(j^2)*dt)-r*dt/2
MR[1,2]=(.25*s*(j^2)*dt+(r*j*dt/4))  
b0r=(.25*s*(j^2)*dt-r*j*dt/4)
  
#Valores para el último renglón.
j<-(Smax/dS-1)
MR[j,j-1]=(.25*s*(j^2)*dt-r*j*dt/4)
MR[j,j]=1-(.5*s*(j^2)*dt)-r*dt/2    
bmr=(.25*s*(j^2)*dt+(r*j*dt/4))
  
#Valores para los demás renglones.
k<-0
for(j in 2:(Smax/dS-2) ){
  MR[j,k+1]=(.25*s*(j^2)*dt-r*j*dt/4)
  MR[j,k+2]=1-(.5*s*(j^2)*dt)-r*dt/2
  MR[j,k+3]=(.25*s*(j^2)*dt+(r*j*dt/4))
  k<-k+1
}  

#Condiciones iniciales.  
B=rep(0,nrow(MR))
n=length(TM)-1

#Sí PUT=1 entonces estámos hablando de una opción Put, en caso contrario es Call.
if(PUT==1){
          
  #Condiciones iniciales
  B[1]<-2*b0r*E*exp(-r*dt*(n-1))
  B[nrow(MR)]=0
  U<-MR%*%ifelse((E-SM[-c(1,length(SM))])>0,E-SM[-c(1,length(SM))],0)+B
  
  for(j in 0:(length(TM)-1)){
#j<-4
            #B[1]<-2*b0r*E*exp(-r*dt*(n-j-1))
            #B[nrow(MR)]=0
            #U<-MR%*%ifelse((E-SM[-c(1,length(SM))])>0,E-SM[-c(1,length(SM))],0)+B
  
            Malla[2:(nrow(Malla)-1),ncol(Malla)-j] <-rev(solve(ML,U))
            Malla[1,ncol(Malla)-j]<-0
            Malla[nrow(Malla),ncol(Malla)-j]<-E*exp(-r*dt*(n-j))
                                    
            B[1]=2*b0r*E*exp(-r*dt*(n-j))
            #B[nrow(MR)]=0
            U=MR%*%solve(ML,U)+B
            }
        }
else{
  #Condiciones iniciales        
  B[1]<-0
  B[nrow(MR)]=2*b0r*(Smax-E*exp(-r*dt*(n-j-1)))
  U<-MR%*%ifelse((SM[-c(1,length(SM))]-E)>0,SM[-c(1,length(SM))]-E,0)+B
  
           for(j in 0:(length(TM)-1)){
           #B[1]=0
           #B[nrow(MR)]=2*b0r*(Smax-E*exp(-r*dt*(n-j-1)))
           #U<-MR%*%ifelse((SM[-c(1,length(SM))]-E)>0,SM[-c(1,length(SM))]-E,0)+B
    
           Malla[2:(nrow(Malla)-1),ncol(Malla)-j] <-rev(solve(ML,U))
           Malla[1,ncol(Malla)-j]<-0
           Malla[nrow(Malla),ncol(Malla)-j]<-E*exp(-r*dt*(n-j))
                                    
           
           B[nrow(MR)]=2*b0r*(Smax-E*exp(-r*dt*(n-j)))
           U=MR%*%solve(ML,U)+B
           } 
    }

Malla<<-Malla
ML<<-ML
MR<<-MR
return((Malla[(Malladim+2)/2,1] + Malla[(Malladim+1)/2,1])/2)
}




