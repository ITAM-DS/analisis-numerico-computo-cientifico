#M?todo de Crank-Nicolson
#M?todo Impl?cito
#Variables Globales.
#r es la tasa de inter?s vigente.
#s es la varianza al cuadrado del activo.
#E es el precio strike del subyacente.
#Construimos la malla. Esta depende de cierto tiempo a la expiraci?n, y alg?n
#valor m?ximo que pueda llegar a valer el activo en consideraci?n.
#Smax > E pero la elecci?n exacta depender? del tipo de contrato.
#Por simplicidad tomaremos el tiempo como unitario. 
#Malladim es el tama?o de la partici?n para la variable tiempo y el
#Precio m?ximo del activo.

########Output########
#Malla es la matriz de soluciones.
#MR es la matriz derecha del sistema.
#ML es la matriz izquierda del sistema.

#Vectores diagonal:
#LDL: Vector con la informaci?n por abajo de la diagonal de ML.
#DL: Vector con la informaci?n de la diagonal de ML.
#UDL: Vector con la informaci?n por arriba de la diagonal de ML.

#LDR:Vector con la informaci?n por abajo de la diagonal de MR.
#DR:Vector con la informaci?n de la diagonal de MR.
#UDR: Vector con la informaci?n por arriba de la diagonal de MR.



CN<-function(r,s,E,Smax,Tmax,Malladim,PUT){
  
  #Dimensi?n de la malla.
  #Cordenada St, eje de las y?s.
  SM<-seq(0,Smax,length.out=Malladim)
  
  #Cordenada t, eje de las x?s.
  TM<-seq(0,Tmax,length.out=Malladim)  

  #Delta tiempo, coincide con el segundo elemento del vector TM.
  dt<-TM[2]
  #Delta Precio del subyacente, coincide con el segundo elemento del vector SM.
  dS<-SM[2]  
  
#Construye la malla vac?a.
  Malla<-matrix(0,nrow=length(SM),ncol=length(TM))
  
#Matrices para resolver el sistema MLU^{n}=MRU^{n+1}+B
#ML es la matriz izquierda, mientra que MR la matriz derecha.  
  
aux=round((Smax/dS-1))
  
  MR=matrix(0,ncol=aux ,nrow=aux)
  ML=matrix(0,ncol=aux ,nrow=aux)
  

UDL=vector("numeric",(aux-1))
DL=vector("numeric",aux)
LDL=vector("numeric",(aux-1))

UDR=vector("numeric",(aux-1))
DR=vector("numeric",aux)
LDR=vector("numeric",(aux-1))  
#################################################################################
#################################################################################
#Iniciamos la matriz ML:
  #Valores del primer rengl?n.
  j<-1
  ML[1,1]=1+(.5*s*(j^2)*dt)+r*dt/2
  ML[1,2]=(-.25*s*(j^2)*dt-(r*j*dt/4))  
  b0l=-.25*s*(j^2)*dt+r*j*dt/4
  
#Iniciamos los primeros valores de los vectores que guardan los valores
#de la diagonal y por arriba de la diagonal.
UDL[1]=ML[1,2]
DL[1]=ML[1,1]

  
  #Valores para el ?ltimo rengl?n.
  j<-(Smax/dS-1)
  ML[j,j-1]<-(-.25*s*(j^2)*dt+r*j*dt/4)
  ML[j,j]<-1+(.5*s*(j^2)*dt)+r*dt/2    
  bml=-(-.25*s*(j^2)*dt-(r*j*dt/4))
  
#Iniciamos los ?ltimos valores de los vectores que guardan los valores
#de la diagonal y por debajo de la diagonal.
LDL[j-1]=ML[j,j-1]
DL[j]=ML[j,j]  
    
  #Valores para los dem?s renglones.
  k<-0
  for(j in 2:(Smax/dS-2) ){
    ML[j,k+1]=(-.25*s*(j^2)*dt+r*j*dt/4)
    ML[j,k+2]=1+(.5*s*(j^2)*dt)+r*dt/2
    ML[j,k+3]=(-.25*s*(j^2)*dt-(r*j*dt/4))
   
    #Dem?s valores para los vectores que guardan la diagonal.
    LDL[j-1]=ML[j,k+1]
    DL[j]=ML[j,k+2]
    UDL[j]=ML[j,k+3]
    
     k<-k+1
  }
#################################################################################
#################################################################################
#Iniciamos la matriz MR:
#Valores del primer rengl?n.
j<-1
MR[1,1]=1-(.5*s*(j^2)*dt)-r*dt/2
MR[1,2]=(.25*s*(j^2)*dt+(r*j*dt/4))  
b0r=(.25*s*(j^2)*dt-r*j*dt/4)

#Iniciamos los primeros valores de los vectores que guardan los valores
#de la diagonal y por arriba de la diagonal.
UDR[1]=MR[1,2]
DR[1]=MR[1,1]

#Valores para el ?ltimo rengl?n.
j<-(Smax/dS-1)
MR[j,j-1]=(.25*s*(j^2)*dt-r*j*dt/4)
MR[j,j]=1-(.5*s*(j^2)*dt)-r*dt/2    
bmr=(.25*s*(j^2)*dt+(r*j*dt/4))

#Iniciamos los ?ltimos valores de los vectores que guardan los valores
#de la diagonal y por debajo de la diagonal.
LDR[j-1]=MR[j,j-1]
DR[j]=MR[j,j] 

#Valores para los dem?s renglones.
k<-0
for(j in 2:(Smax/dS-2) ){
  MR[j,k+1]=(.25*s*(j^2)*dt-r*j*dt/4)
  MR[j,k+2]=1-(.5*s*(j^2)*dt)-r*dt/2
  MR[j,k+3]=(.25*s*(j^2)*dt+(r*j*dt/4))
  
  #Dem?s valores para los vectores que guardan la diagonal.
  LDR[j-1]=MR[j,k+1]
  DR[j]=MR[j,k+2]
  UDR[j]=MR[j,k+3]
  
  k<-k+1
}  

#Condiciones iniciales.  
B=rep(0,nrow(MR))
n=length(TM)-1

#S? PUT=1 entonces est?mos hablando de una opci?n Put, en caso contrario es Call.
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
  
            Malla[2:(nrow(Malla)-1),ncol(Malla)-j] <-rev(TDMA(ML,U))
            Malla[1,ncol(Malla)-j]<-0
            Malla[nrow(Malla),ncol(Malla)-j]<-E*exp(-r*dt*(n-j))
                                    
            B[1]=2*b0r*E*exp(-r*dt*(n-j))
            #B[nrow(MR)]=0
            U=MR%*%TDMA(ML,U)+B
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
    
           Malla[2:(nrow(Malla)-1),ncol(Malla)-j] <-rev(TDMA(ML,U))
           Malla[1,ncol(Malla)-j]<-0
           Malla[nrow(Malla),ncol(Malla)-j]<-E*exp(-r*dt*(n-j))
                                    
           
           B[nrow(MR)]=2*b0r*(Smax-E*exp(-r*dt*(n-j)))
           U=MR%*%TDMA(ML,U)+B
           } 
    }

Malla<<-Malla
ML<<-ML
MR<<-MR

LDL<<-LDL
DL<<-DL
UDL<<-UDL

LDR<<-LDR
DR<<-DR
UDR<<-UDR

return((Malla[(Malladim+2)/2,1] + Malla[(Malladim+1)/2,1])/2)
}





