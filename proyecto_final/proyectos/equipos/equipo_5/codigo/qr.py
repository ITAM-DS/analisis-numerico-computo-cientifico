import numpy as np

def eigen_qr(A, iterations=999000):
    """
    Description:
        Función que calcula los eigenvalores y eigenvectores por el método QR
    	
    Parameters:
    ----------
    A: dataframe
        Matriz
    iterations: int
    	Número de iteraciones para el método QR
    
    Returns:
    -------
    eigen_values: (..., M) array
    	Eigenvalores
    
    QQ: (..., M, M) array
        Eigenvectores
    """

    Ak = np.copy(A)
    QQ = np.eye(Ak.shape[0])
    for k in range(iterations):
        Q, R = np.linalg.qr(Ak)
        Ak = R @ Q 
        QQ = QQ @ Q # eigenvector
        
    eigen_values = np.diag(Ak)

    return eigen_values, QQ


def eigen_qr_with_shift(A, iterations=999000):
    """
    Description:
        Función que calcula los eigenvalores y eigenvectores por el método QR con shift. 
        El cuál introduces "shifts" para acelarar la convergencia.
    	
    Parameters:
    ----------
    A: dataframe
        Matriz
    iterations: int
    	Número de iteraciones para el método QR
    
    Returns
    -------
    eigen_values: (..., M) array
    	Eigenvalores
    
    QQ: (..., M, M) array
        Eigenvectores

    References:
    ----------
    https://dspace.mit.edu/bitstream/handle/1721.1/75282/18-335j-fall-2006/contents/lecture-notes/lec16.pdf

    """
    Ak = np.copy(A)
    n = Ak.shape[0]
    QQ = np.eye(n)
    for k in range(iterations):
        sk = Ak.item(n-1, n-1)
        # Cálculo de shift
        smult = sk * np.eye(n)
        # Se calcula qr con la subtración de los shits
        Q, R = np.linalg.qr(np.subtract(Ak, smult))
        Ak = np.add(R @ Q, smult)
        QQ = QQ @ Q # eigenvector

    eigen_values = np.diag(Ak)

    return eigen_values, QQ
