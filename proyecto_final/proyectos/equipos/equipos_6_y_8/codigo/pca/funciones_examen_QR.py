import numpy as np
import copy
import codecs
import sys
#from scipy.linalg import solve_triangular

def busca_ayuda(cadena):
    """
    Función que devuelve el texto de ayuda correspondiente a la función
    que se pase como parámetro, obtenida de un unico archivo .txt
    donde están documentadas las "ayudas" de todas las funciones asociadas
    a la factorización QR (contenidas en este .py)
    
    params: cadena  nombre de la función de la que se desea obtener ayuda
                    
    return: help    ayuda de la función buscada en forma de texto
    
    """
    l=len(cadena)
    help=codecs.open('Help_funciones_factorizacion_QR.txt', "r", "utf-8").read()
    p_inicio=help.find("****i****" + cadena)
    p_final=help.find("****f****" + cadena)
    help=help[(p_inicio+9+l):p_final]
    return help






def crear_matriz_aleatoria(renglones,columnas,maximo_valor,minimo_valor,entero=False):
    """
    Función de apoyo para genear matrices aleatorias
    params: renglones       no. de renglones de la matriz
            columnas        no. de columnas de la matriz
            maximo_valor    valor máximo de las entradas de la matriz
            minimo_valor    valor mínimo de las entradas de la matriz
            entero          Indica si las entradas serán enteras (True) o no
            
    return: M               Matriz con numeros al azar
    """
    
    #Se checa que los parámetros sean congruentes con la funcionalidad
    if isinstance(renglones, int)==False or isinstance(columnas, int)==False:
        sys.exit('Los parámetros de renglones y columnas deben ser enteros positivos')
    elif renglones<=0 or columnas<=0:
        sys.exit('Los parámetros de renglones y columnas deben ser enteros positivos')            
    if isinstance(maximo_valor, (int, float))==False or isinstance(minimo_valor, (int, float))==False:
        sys.exit('Los parámetros maximo_valor y minimo_valor deben ser numericos')

    #Se inicializa una matriz llena de ceros con las dimensiones deseadas (mxn)
    M=np.zeros((renglones, columnas))
    for i in range(renglones):
        for j in range(columnas):
            #Si entero es verdadero se obtiene el maximo entero menor o igual a 1 (//1)
            if entero:
                M[i][j]=(np.random.rand(1)*(maximo_valor+1-minimo_valor)+minimo_valor)//1
            else:
                M[i][j]=np.random.rand(1)*(maximo_valor-minimo_valor)+minimo_valor
    return M

#crear_matriz_aleatoria.__doc__ =busca_ayuda("crear_matriz_aleatoria")






def house(x):
    """
    Función que calcula vector de householder
    
    params: x       vector al que se le hará la reflexión householder
                    
    return: Beta    factor para obtener matriz de reflexión householder Rf
            v       vector de householder
    """
    
    #Se checa que los parámetros sean congruentes con la funcionalidad
    if type(x) is not np.ndarray:
        sys.exit('x debe ser de tipo numpy.ndarray')
    
    #longitud del vector x=(x_0,x_1,x_2,...,x_(m-1))
    m=len(x)
    norm_2_m=x[1:m].dot(np.transpose(x[1:m]))
    #Se hace v=x=(1,x_1,x_2,...,x_(m-1))
    v=np.concatenate((1,x[1:m]), axis=None)
    Beta=0
    #con las siguientes condiciones se checa si x es múltiplo del vector canónico e_1 
    #y el signo de x[0]
    if (norm_2_m==0 and x[0]>=0):
        Beta=0
    elif (norm_2_m==0 and x[0]<0):
        Beta=2
    else:
        norm_x=np.sqrt(pow(x[0],2)+norm_2_m)
        if (x[0]<=0):
            v[0]=x[0]-norm_x
        else:
            v[0]=-norm_2_m/(x[0]+norm_x)
        Beta=2*pow(v[0],2)/(norm_2_m+pow(v[0],2))
        v=v/v[0]
    return Beta, v

#house.__doc__ =busca_ayuda("house")






def matriz_auxiliar_Arv(A,ind_singular=False):
    """
    Función que genera una matriz que contiene los elementos r distintos de cero de la 
    matriz R y las entradas de los vectores householder v (excepto la primera), con los 
    cuales se puede calcular la matriz Q. Ambas matrices componentes de la factorización QR
    
    params: A      Matriz (mxn) de la que se desea obtner factorización QR
            
    return: Arv    Matriz (mxn) que incluye las componentes distintas de cero de la matriz R 
                   y los vectores householder con los que se puede obtener la matriz Q, y 
                   con ello la factorización QR
    """
    
    #Se checa que los parámetros sean congruentes con la funcionalidad
    if type(A) is not np.ndarray:
        sys.exit('A debe ser de tipo numpy.ndarray')
    m,n=A.shape
    if m<n:
        sys.exit('EL numero de renglones de A debe ser mayor o igual al no. de columnas')
    
    #m contiene el numero de renglones y n el de columnas
    m,n=A.shape
    #se crea una matriz con los valores de A
    Arv=copy.copy(A)
    
    #si no se pide que se cheque que la matriz es singular, se obtendrá la matriz R
    #aún si esta es singula (que exista algún elemento de la diagonal que sea 0
    if ind_singular==False:
        for j in range(n):
            beta, v=house(Arv[j:m,j])
            #Con esta multiplicación se van generando las componentes r de la matriz R
            Arv[j:m,j:n]=Arv[j:m,j:n]-beta*np.outer(v,(np.transpose(v)@Arv[j:m,j:n]))
            #se guarda en cada columnas los valores de v d, excepto la primer componente (que vale 1)
            Arv[(j+1):m,j]=v[1:(m-j)]
    else:
        for j in range(n):
            beta, v=house(Arv[j:m,j])
            Arv[j:m,j:n]=Arv[j:m,j:n]-beta*np.outer(v,(np.transpose(v)@Arv[j:m,j:n]))
            #Si se detecta que alguna entrada de la diagonal (elemento de la maatriz R)
            #es cero, se devuelve un valor nulo (None), y para el cálculo de Arv
            #No se condiciona sobre si alcanza el valor de cero, sino más bien
            #si está lo suficientemente cercano, pues dados los errores por redondeo
            #no siempre se alcanza el cero aunque teóricamente sí lo sea, pero el
            #algoritmos arroja un valor cercano a cero
            if Arv[j,j]<10**(-14) and Arv[j,j]>-10**(-14):
                return None
            Arv[(j+1):m,j]=v[1:(m-j)]
    return Arv

#matriz_auxiliar_Arv.__doc__ =busca_ayuda("matriz_auxiliar_Arv")






def matriz_Q_R(A,ind_singular=False):
    """
    Función que devuelve la matriz R y Q de la factorización QR de una matriz A
    
    params: A    Matriz (mxn)
    return: Q    Matriz Q (mxm) de la factorización A=QR
            R    Matriz Q (mxm) de la factorización A=QR
    """
    
    #Se checa que los parámetros sean congruentes con la funcionalidad
    if type(A) is not np.ndarray:
        sys.exit('A debe ser de tipo numpy.ndarray')
    elif A.shape[0]<A.shape[1]:
        sys.exit('El numero de renglones de A tiene que ser igual o mayor al no. de columnas')
    
    #si ind_singular es True, entonces no se devuelve la matriz R ni Q
    #esto se plantea así como un sistema de contról, para evitar comprobar que las matrices
    #sean singulares (y no tengan una única solución) mediante el determinante, que
    #involucra un alto costo computacional para matrices de tamaño representativo
    Arv=matriz_auxiliar_Arv(A,ind_singular)

    if Arv is None:
        return None, None
    else:
        m,n=A.shape
        Q=np.eye(m)
        R=copy.copy(A)
        for j in range(n):
            Qj=Q_j(Arv,j+1)
            Q=Q@Qj
            R=Q_j(Arv,j+1)@R
        return Q,R

#matriz_Q_R.__doc__ =busca_ayuda("matriz_Q_R")






def Q_j(Arv,j):
    """
    Función que calcula la matriz Qj (en el proceso de obtención de factorización QR se van 
    obteniendo n Qj's, que si se multiplican todas da por resultado Q=Q_1*Q_2*...*Q_n)
                            
    params: Arv   Matriz (mxn) con la info escencial
            j     indica el índice de la matriz Q_j
    return: Qj    Matriz Q de la j-esima iteración del proceso iterativo de factorización QR
    """
    
    #Se checa que los parámetros sean congruentes con la funcionalidad
    if type(Arv) is not np.ndarray:
        sys.exit('Arv debe ser de tipo numpy.ndarray')
    elif Arv.shape[0]<Arv.shape[1]:
        sys.exit('El numero de renglones de Arv tiene que ser igual o mayor al no. de columnas')
    if isinstance(j, int)==False:
        sys.exit('El parámetro j deber ser un entero')
    elif 1>j or j>Arv.shape[1]:
        sys.exit('El parámetro j debe estar en el rango [1,no. columnas de Arv]')
    
    m,n=Arv.shape
    Qj=np.eye(m)
    #Para construir Q_j requerimos usar el vector v contenido en Arv contenido
    #en la j-1 columna (considerando que en Python la primer columna es la cero)
    v=np.concatenate((1,Arv[j:m,(j-1)]), axis=None)
    beta=2/(1+Arv[j:m,(j-1)].dot(Arv[j:m,(j-1)]))
    Qj[(j-1):m,(j-1):m]=np.eye(m-(j-1))-beta*np.outer(v,v)
    return Qj

#Q_j.__doc__ =busca_ayuda("Q_j")






#def Solucion_SEL_QR_nxn(A,b):
#    """
#    Función que obtiene la solución de un sistema de ecuaciones lineales (SEL) con n ecuaciones y n incognitas
#            
#    params: A   Matriz (nxn) que representa los coeficientas de las ecuaciones
#            b   vector (nx1) constantes del sistema
#    return: x   vector que satisface (Ax=b)
#    """
#
#    #Se checa que los parámetros sean congruentes con la funcionalidad
#    if type(A) is not np.ndarray or type(b) is not np.ndarray: #esto implica que A y b tienen más de 1 elemento
#        sys.exit('A y b deben ser de tipo numpy.ndarray')
#    m,n = A.shape
#    if m<n:
#        sys.exit('EL numero de renglones de A debe ser mayor o igual al no. de columnas')
#    elif b.shape[0]!= m:
#        sys.exit('b debe representar un vector columna (mx1), m=no. renglones de A')
#    else:
#        try:
#            flag=b.shape[1]
#        except Exception:
#            flag=1
#        if flag!=1:
#            sys.exit("b debe representar un vector de m renglones y 1 columna")
#
#    #Si la matriz A es singular, Q y R serán igual a None
#    Q,R=matriz_Q_R(A,1)
#    if Q is None:
#        sys.exit('La matriz A asociada al sistema de ecuaciones es singular')
#    b_prima=np.transpose(Q)@b
#    x=solve_triangular(R, b_prima,lower=False)
#    return x

#Solucion_SEL_QR_nxn.__doc__ =busca_ayuda("Solucion_SEL_QR_nxn")





def crear_bloques(A, b, m1=False, n1=False):
    """
    Esta es la función para la creación de bloques usando un arreglo de numpy
    
    params: A   Matriz (mxn) que representa los coeficientas de las ecuaciones
            b   vector (mx1) constantes del sistema
            n1  Numero de renglones que tendrá el 1er bloque
            m1  Numero de columnas que tendrá el 1er bloque
    
    return: A11 Fraccion de la matriz dividida
            A12 Fraccion de la matriz dividida
            A12 Fraccion de la matriz dividida
            A12 Fraccion de la matriz dividida
            b1  Fraccion del vector dividido
            b2  Fraccion del vector dividido
    """

    #Se checa que los parámetros sean congruentes con la funcionalidad
    if type(A) is not np.ndarray or type(b) is not np.ndarray: #esto implica que A y b tienen más de 1 elemento
        sys.exit('A y b deben ser de tipo numpy.ndarray')
    m,n = A.shape
    if m<n:
        sys.exit('EL numero de renglones de A debe ser mayor o igual al no. de columnas')
    elif b.shape[0]!= m:
        sys.exit('b debe representar un vector columna (mx1), m=no. renglones de A')
    else:
        try:
            flag=b.shape[1]
        except Exception:
            flag=1
        if flag!=1:
            sys.exit("b debe representar un vector de m renglones y 1 columna")    
    
    if m1==False:
        m1=m//2
    if n1==False:
        n1=n//2
    
    b1 = b[:m1]
    b2 = b[m1:m]
    A11 = A[:m1,:n1]
    A21 = A[m1:m,:n1]
    A12 = A[:m1,n1:n]
    A22 = A[m1:m,n1:n]

    return A11,A21,A12,A22,b1,b2

#crear_bloques.__doc__ =busca_ayuda("crear_bloques")






def eliminacion_bloques(A,b, m1=False, n1=False):
    """
    Función que obtiene la solución de un sistema de ecuaciones lineala (SEL) con n ecuaciones y n incognitas
            
    params: A   Matriz (mxn) que representa los coeficientas de las ecuaciones
            b   vector (mx1) constantes del sistema
    
    return: x1 Solucion al 1er sistema de ecuaciones obtenido con la división por bloques
            x2 Solucion al 2do sistema de ecuaciones obtenido con la división por bloques
    """
    
    #Se checa que los parámetros sean congruentes con la funcionalidad
    if type(A) is not np.ndarray or type(b) is not np.ndarray: #esto implica que A y b tienen más de 1 elemento
        sys.exit('A y b deben ser de tipo numpy.ndarray')
    m,n = A.shape
    if m<n:
        sys.exit('EL numero de renglones de A debe ser mayor o igual al no. de columnas')
        
    elif b.shape[0]!= m:
        sys.exit('b debe representar un vector columna (mx1), m=no. renglones de A')
    else:
        try:
            flag=b.shape[1]
        except Exception:
            flag=1
        if flag!=1:
            sys.exit("b debe representar un vector de m renglones y 1 columna")
    
    if m1==False:
        m1=m//2
    if n1==False:
        n1=n//2

    if m != n:
        sys.exit('A debe ser cuadrada')

#     if np.linalg.det(A)==0:
#         sys.exit('A debe ser no singular')

    A11,A21,A12,A22,b1,b2=crear_bloques(A,b,m1,n1)

    # 1. Calcular Y=A11^{-1}A12 y y=A11^{-1}b1 teniendo cuidado en no calcular la inversa sino un sistema de ecuaciones lineales
    #if np.linalg.det(A11)==0:
    #    sys.exit('A11 debe ser no singular')
    y=Solucion_SEL_QR_nxn(A11,b1)
    
    Y=np.zeros((n1,n-n1))
    for j in range(n-n1):
        Y[:,j]=Solucion_SEL_QR_nxn(A11,A12[:,j])
    
    # 2. Calcular el complemento de Schur del bloque A11 en A. Calcular b_hat
    S=A22-A21@Y
    b_h=b2-A21@y

    # 3. Resolver Sx2 = b_hat
    x2=Solucion_SEL_QR_nxn(S,b_h)

    # 4. Resolver A11x1 = b1-A12x2
    x1=Solucion_SEL_QR_nxn(A11,b1-A12@x2)

    return np.concatenate((x1,x2), axis=0)

#eliminacion_bloques.__doc__ =busca_ayuda("eliminacion_bloques")
