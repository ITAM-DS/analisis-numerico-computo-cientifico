import numpy as np

def sign(x):
	"""
	Helper function for computing sign of real number x.
	Args:
		x (float): A real number.
	Returns:
		sign(x) (int): 1 if x is non-negative, -1 is x is negative.
	"""
	if x >=0:
		return 1
	else:
		return -1


def ortogonalidad(A,i,j):
	"""
	Helper function that verifies whether two columns of a matrix are orthogonal or not.
	Args:
		A (numpy 2D array of floats): A matrix of real numbers.
		i (int): index that indicates a column of A.
		j (int): index that indicates another column of A.
	Returns:
		ortogonal (bool): True if columns i and j of A are orthogonal, False if
		they are not.
	"""
	tol = 1e-8
	numerador = np.abs(np.dot(A[:,i],A[:,j]))
	denominador = np.linalg.norm(A[:,i]) * np.linalg.norm(A[:,j])

	ortogonal = numerador/denominador < tol

	return ortogonal


def seno_coseno(A, i, j):
	"""
	Helper function for computing the sine and cosine of the angle of the Jacobi
	rotation that diagonalizes the (i,j) submatrix of the matrix A^T A.
	Args:
		A (numpy 2D array of floats): a matrix of real numbers.
                i (int): index that indicates a column of A.
                j (int): index that indicates another column of A.
	Returns:
		c (float): cosine of said angle.
		s (float): sine of said angle.
	"""
	x = A[:,i]
	y = A[:,j]

	a = np.dot(x,x)
	b = np.dot(y,y)
	c = np.dot(x,y)

	tau = (b-a) / (2*c)
	t = sign(tau) / (np.abs(tau) + np.sqrt(1+tau**2))
	c = 1/np.sqrt(1+t**2)
	s = c*t

	return c,s


def actualizar_AV(A, V, i, j):
	"""
	Helper function for updating columns i and j of matrices A and V by performing a
	one sided Jacobi rotation on both of them.
	Args:
		A (numpy 2D array of floats): a matrix of real numbers.
		V (numpy 2D array of floats): an orthogonal matrix of real numbers.
                i (int): index that indicates a column of A in which the rotation is to be
			performed.
                j (int): index that indicates another column of A in which the rotation is
			to be performed.
	Returns:
		A (numpy 2D array of floats): matrix A after performing the rotation.
		V (numpy 2D array of floats): matrix V after performing the rotation.
	"""
	tempA = A[:,i].copy()
	tempV = V[:,i].copy()

	c,s = seno_coseno(A, i, j)

	A[:,i] = c * tempA - s * A[:,j]
	A[:,j] = s * tempA + c * A[:,j]

	V[:,i] = c * tempV - s * V[:,j]
	V[:,j] = s * tempV + c * V[:,j]

	return A,V


def jacobi_one_sided(A_k,max_sweeps):
	"""
	Function that computes the Singular Value Decomposition of matrix A by performing
	a series of one sided Jacobi rotations.
	Args:
		A_k (numpy 2D array of floats): a matrix of real numbers.
		max_sweeps (int): maximun number of sweeps to be performed on matrix A.
	Returns:
		A (numpy 2D array of floats): update matrix A after performing the rotations
			(also known as W in the in-class algorithm)
		V_k (numpy 2D array of floats): orthogonal matrix containing the information
			of all the rotations performed. (also V in the in-class algorithm)
	"""
	sweeps = 0
	num_columnas_ortogonales = 0
	n = A_k.shape[1]
	V_k = np.eye(n)
	A = np.copy(A_k)

	while num_columnas_ortogonales != n*(n-1)/2 and sweeps < max_sweeps:
		num_columnas_ortogonales = 0

		for i in range(n):
			for j in range(i+1,n):

				if ortogonalidad(A,i,j)==False:
					A,V_k=actualizar_AV(A,V_k,i,j)

				else:
					num_columnas_ortogonales += 1
					A,V_k

		sweeps += 1
		print(sweeps)
	return A,V_k


def normalizacion_A(matriz):
	"""
	Function that normalizes matriz A to have the U matriz .
	Args:
		A (numpy 2D array of floats): a matrix of real numbers that comes from 
		jacobi one sided function
	Returns:
		U
	"""
	n = matriz.shape[1]
	m = matriz.shape[0]
	U = np.zeros((m,n))

	for i in range(n):
	    u = matriz[:,i]/np.linalg.norm(matriz[:,i])
	    U[:,i] = u
        
	indexlist = np.argsort(np.linalg.norm(matriz,axis=0))[::-1]
	
	return U[:,indexlist]
