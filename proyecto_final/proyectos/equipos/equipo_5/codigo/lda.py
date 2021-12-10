import pandas as pd
import numpy as np
from codigo.qr import eigen_qr,eigen_qr_with_shift


def lda_f(df,target,n_features,aprox_eigen=True,iterations=10000,shift=True):

    """Función que reduce la dimensionalidad de un problema supervisado de clasificación binaria; n_features debe ser menor o igual que el número de features del problema dado.
    	
    Parameters
    ----------
    df: dataframe
        Dataframe que contiene los features a ser considerados así como la variable objetivo 'target'
    target: character
        Nombre de la variable objetivo del problema de clasificación, que debe estar presente en el dataframe 'df'. Implementación para problemas de clasificación binaria con etiquetas [0,1]
    n_features: int
        Número de dimensiones a las cuales se reducirá el problema. Debe ser menor igual a la dimensión actual del problema de clasificaciín binaria
    aprox_eigen: boolean
    	Si 'True' se aproximan los eigenvalores y eigenvectores a través del método QR. Si 'False' se utiliza la función linalg.solve de numpy
    iterations: int
    	Número de iteraciones para el método QR si aprox_eigen=='True'
    shift: boolean
    	Si 'True' se utiliza la variante shift del método QR
    
    Returns
    -------
    dataframe
    	Dataframe asociado al problema de clasificación binaria con reducción de dimensionalidad
    """
    
    features=[x for x in df.columns if x!=target]
    if n_features>len(features):
    
        print("n_features deber ser menor o igual al número de features del problema dado")
    
    else:
    	
        # Obtención del vector de medias por clase

        m0=[]
        m1=[]
        m=[]
        for c in features:
            aux=df[[c,target]].groupby([target]).agg({c:"mean"}).reset_index()
            m0.append(aux[aux[target]==0].values[0][1])
            m1.append(aux[aux[target]==1].values[0][1])
            m.append(df[c].mean())
        m0=np.array(m0)
        m1=np.array(m1)
        m=np.array(m)  
    
    	# Within-class scatter matrix SW
    	
        s0=df[df[target]==0][features]
        s0=np.array(s0)-m0
        s0=s0.T @ s0
        s1=df[df[target]==1][features]
        s1=np.array(s1)-m1
        s1=s1.T @ s1
        SW=s0+s1
       
    	### Between-class scatter matrix SB
    	
        N0=df[df[target]==0].shape[0]
        p0=((m0-m).reshape(-1,1) @ (m0-m).reshape(1,-1))*N0
        N1=df[df[target]==1].shape[0]
        p1=((m1-m).reshape(-1,1) @ (m1-m).reshape(1,-1))*N1
        SB=p0+p1
    
    	# Solving the generalized eigenvalue problem
        if aprox_eigen==True:
            if shift==False:
                R=np.linalg.solve(SW,SB)
                eig_vals, eig_vecs = eigen_qr(R,iterations)
            else:
                R=np.linalg.solve(SW,SB)
                eig_vals, eig_vecs = eigen_qr_with_shift(R,iterations)
        else:	
            R=np.linalg.solve(SW,SB)
            eig_vals, eig_vecs = np.linalg.eig(R)
    
    	# Los ordeno de mayor a menor en función de los eigenvalores
    	
        eig_pairs = [(np.abs(eig_vals[i]), eig_vecs[:,i]) for i in range(len(eig_vals))]
        eig_pairs = sorted(eig_pairs, key=lambda k: k[0], reverse=True)
    
    	# Seleccionar los eigenvalores con mayor aportación
    	
        W=np.hstack((eig_pairs[0][1].reshape(len(features),1)))
        if n_features>1:
            for i in range(1,n_features):
                aux=np.hstack((eig_pairs[i][1].reshape(len(features),1)))
                W=np.hstack((W.reshape(len(features),1),aux.reshape(len(features),1)))
            
    	# Transformamos al nuevo sub-espacio
    	
        X=np.array(df[features])
        Y=np.array(df[target])
        X_lda=X@W
        X_lda=pd.DataFrame(X_lda,columns=range(n_features))
        X_lda[target]=Y
    
        return X_lda

