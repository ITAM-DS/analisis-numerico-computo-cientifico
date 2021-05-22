import numpy as np

class Simplex:
    
    """
    This class creates a simplex solver for linear programming.
    """
    
    def __init__(self,c = None,A = None ,b = None, problem = None, verbose = None):
        """
        Creates variables associated to the linear programing problem
        
        :type c: numpy 1D array
        :param c: array asociated with the cost or coefficients of 
                    lineal objective function. 
        
        :type A:  numpy NxM array
        :param A: Matrix associated to the linear restrictions for
                    the objective function. 
        
        :type b:  numpy 1XM array
        :param b: array asociated with constraints to the linear 
                    restrictions for the objective function.
        
        :type problem: str
        :param problem: definition of maximization ('Max') or 
                        minimization ('Min') problem.
        
        :type x:  numpy 1D array
        :param x: array of solution vector once the 
                    solve method is applied. 
        
        """
        
        if problem == 'Max':
            self.c=-np.array(c) 
        else:
            self.c= np.array(c)  
        self.A=np.array(A)   
        self.b=np.array(b)  
        self.x = np.zeros(self.b.size)
        self.problem = problem
        self.verbose = verbose
        
    def solve(self):
        
        """
        Solves the simplex algorithm. 
        Returns
        -------
        :solution: Numpy array with solution
        """
        problem = self.problem
        verbose = self.verbose
        c_N = self.c
        A = self.A
        b = self.b
        status = []
        costo = np.copy(c_N)
      
        n_c_N = c_N.size
        n_A = np.size(A,0)
        identity_A = np.eye(n_A)
        B = np.eye(n_A)
        A= np.hstack((A,identity_A))
        
        n_b = b.size
        x_B = b
        
        c_B = np.zeros(n_b)
        
        n_A_ = np.size(A,1)
        
        N_list_idx = list(range(0,n_c_N))
        B_list_idx = list(range(n_c_N,n_A_))
        
        nu = np.zeros(n_b)
        
        lista = []
        i = 0
        
        for lambda_ in c_N:
            lista.append (-lambda_ + np.dot(nu, A[:, N_list_idx[i]])) 
            i = i + 1
        
        idx_x_N = lista.index(max(lista))
        
        while lista[idx_x_N]>0:
            
            d = np.linalg.solve(B, A[:,idx_x_N])    
            lista2 = []
            
            for indice in range(0,n_b):
                if d[indice]<=0:
                    lista2.append(np.nan)
                else:
                    lista2.append(x_B[indice]/d[indice])
                    
            if np.isnan(lista2).all() == True:  
                status = 3    
                return ("simplex method failed, unbounded solution",-1, status)
            
            idx_x_B = lista2.index(min(np.array(lista2)[np.isfinite(lista2)]))
            
            x_min_plus = x_B[idx_x_B]/d[idx_x_B]
            
            x_B = x_B - d*x_min_plus
            x_B[idx_x_B] = x_min_plus
            
            B[:,idx_x_B] = A[:,idx_x_N]
            aux = B_list_idx[idx_x_B]
            B_list_idx[idx_x_B] = N_list_idx[idx_x_N]
            N_list_idx[idx_x_N] = aux
            
            aux = c_B[idx_x_B]
            c_B[idx_x_B] = c_N[idx_x_N]
            c_N[idx_x_N] = aux
            
            nu = np.linalg.solve(B.T, c_B)
            
            lista = []
            i = 0
            for lambda_ in c_N:
                lista.append (-lambda_ + np.dot(nu, A[:, N_list_idx[i]]))
                i = i + 1
            idx_x_N = lista.index(max(lista))
        
        solution = []

        for indice in range(0,n_c_N):
            j=0
            for indice2 in range(0,len(B_list_idx)):
                if B_list_idx[indice2] == indice:
                    solution.append(x_B[indice2])
                    j = j + 1
                elif (indice2 == len(B_list_idx) - 1 and j == 0):
                    solution.append(0) 
                    
        if verbose == True:
            print("Optimization completed successfully !") 
            print("Solution for x vector:") 
            self.x = solution
            print(solution) 
        
        status = 0
        n = len(solution)
        opt = 0
        for i in range(n):
            opt += solution[i]* costo[i]
        if verbose == True:
            print("Optimal value:")
            print(opt)
            
        print("Solution for x vector, optimization value and status:")
            
        #Solucion    
        self.x = solution
        return solution, opt, status