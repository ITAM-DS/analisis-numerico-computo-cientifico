import math

import numpy as np

from utils_2nd_version import compute_error, logarithmic_barrier, \
                              constraint_inequalities_funcs_eval, \
                              norm_residual
from line_search_2nd_version import line_search_for_log_barrier_by_backtracking, \
                                    line_search_for_residual_by_backtracking
from numerical_differentiation_2nd_version import numerical_differentiation_of_logarithmic_barrier, \
                                                  gradient_approximation, Hessian_approximation


def path_following_method_feasible_init_point(f, A, constraints_ineq,
                                              x_0, tol,
                                              tol_backtracking, x_ast=None, p_ast=None, 
                                              maxiter=30,
                                              mu=None,
                                              gf_symbolic=None, Hf_symbolic=None,
                                              tol_outer_iter=1e-6,maxiter_path=30
                                              ):
    m = len(constraints_ineq.keys())
    if p_ast:
        t_0 = m/math.fabs(f(x_0)-p_ast) #other option: t_0 = mu*m/(f(x_0)-p_ast)
    else:
        print("p_ast must be defined")
    t = t_0
    x = x_0
    log_barrier_eval = logarithmic_barrier(f,x,t,constraints_ineq)
    stopping_criteria = m/t
    outer_iter = 1
    const_ineq_funcs_eval = constraint_inequalities_funcs_eval(x,constraints_ineq)
        
    print("Outer iterations of path following method")
    print('{} {:0.2e}'.format("Mu value:", mu))
    print('Outer iteration\tLogBarrier \tt_log_barrier\tStopping criteria')
    print('{}\t\t{:0.2e}\t{:0.2e}\t{:0.2e}'.format(outer_iter,log_barrier_eval,
                                                 t,stopping_criteria
                                                 ))
    print("----------------------------------------------------------------------------------------")
    iter_barrier = 0
    while(stopping_criteria > tol_outer_iter and outer_iter < maxiter_path):
        [x,iteration,Err_plot,x_plot] = Newtons_method_log_barrier_feasible_init_point(f, A, constraints_ineq, 
                                                                                       t, x_0, tol, 
                                                                                       tol_backtracking, x_ast, p_ast,
                                                                                       maxiter,
                                                                                       gf_symbolic, Hf_symbolic)
        print("Inner iterations")
        print(x)
        const_ineq_funcs_eval = constraint_inequalities_funcs_eval(x,constraints_ineq)
        
        if(sum(const_ineq_funcs_eval > np.nextafter(0,1)) >=1):
            print("Some constraint inequalities evaluated in x were positive, check approximations")
        
        t=mu*t
        log_barrier_eval = logarithmic_barrier(f,x,t,constraints_ineq)
        outer_iter+=1
        stopping_criteria = m/t
        print("----------------------------------------------------------------------------------------")
        print("Outer iterations of path following method")
        print('{} {:0.2e}'.format("Mu value:", mu))
        print('Outer iteration\tLogBarrier \tt_log_barrier\tStopping criteria')
        print('{}\t\t{:0.2e}\t{:0.2e}\t{:0.2e}'.format(outer_iter,log_barrier_eval,
                                                     t,stopping_criteria
                                                     ))
        print("----------------------------------------------------------------------------------------")
        iter_barrier+= iter_barrier + iteration
            
    return [x,iter_barrier,t]
def Newtons_method_log_barrier_feasible_init_point(f, A, constraint_inequalities, 
                                                   t_path, x_0, tol, 
                                                   tol_backtracking, x_ast=None, p_ast=None, maxiter=30,
                                                   gf_symbolic = None,
                                                   Hf_symbolic = None):
    '''
    Newton's method to numerically approximate solution of min f subject to Ax = b.
    IMPORTANT: this implementation requires that initial point x_0, satisfies: Ax_0 = b
    Args:
        f (fun): definition of function f as lambda expression or function definition.
        A (numpy ndarray): 2d numpy array of shape (m,n) defines system of constraints Ax=b.
        
        constraints_ineq
        
        t_path
        
        x_0 (numpy ndarray): initial point for Newton's method. Must satisfy: Ax_0 = b
        tol (float): tolerance that will halt method. Controls stopping criteria.
        tol_backtracking (float): tolerance that will halt method. Controls value of line search by backtracking.
        x_ast (numpy ndarray): solution of min f, now it's required that user knows the solution...
        p_ast (float): value of f(x_ast), now it's required that user knows the solution...
        maxiter (int): maximum number of iterations
        gf_symbolic (fun): definition of gradient of f. If given, no approximation is
                                     performed via finite differences.
        Hf_symbolic (fun): definition of Hessian of f. If given, no approximation is
                                     performed via finite differences.
    Returns:
        x (numpy ndarray): numpy array, approximation of x_ast.
        iteration (int): number of iterations.
        Err_plot (numpy ndarray): numpy array of absolute error between p_ast and f(x) with x approximation
                          of x_ast. Useful for plotting.
        x_plot (numpy ndarray): numpy array that containts in columns vector of approximations. Last column
                        contains x, approximation of solution. Useful for plotting.
    '''
    iteration = 0
        
    x = x_0
    
    feval = f(x)
        
    if gf_symbolic and Hf_symbolic:
        gfeval = gf_symbolic(x)
        Hfeval = Hf_symbolic(x)
    else:
        grad_Hess_log_barrier_dict = numerical_differentiation_of_logarithmic_barrier(f,x,t_path,
                                                                                      constraint_inequalities)
        gfeval = grad_Hess_log_barrier_dict['gradient']
        Hfeval = grad_Hess_log_barrier_dict['Hessian']

    
    normgf = np.linalg.norm(gfeval)
    condHf= np.linalg.cond(Hfeval)
    
    Err_plot_aux = np.zeros(maxiter)
    Err_plot_aux[iteration]=compute_error(p_ast,feval)
    
    Err = compute_error(x_ast,x)
    
    if (np.all(A < np.nextafter(0,1))): #A is zero matrix
        system_matrix = Hfeval
        rhs = -gfeval
        n = x.size
        p = 0
        
    else:
        if(A.ndim == 1):
            p = 1
            n = x.size
            zero_matrix = np.zeros(p)
            first_stack = np.column_stack((Hfeval, A.T))
            second_stack = np.row_stack((A.reshape(1,n).T,zero_matrix)).reshape(1,n+1)[0]
        else:
            p,n = A.shape
            zero_matrix = np.zeros((p,p))
            first_stack = np.column_stack((Hfeval, A.T))
            second_stack = np.column_stack((A,zero_matrix))
            
        system_matrix = np.row_stack((first_stack,second_stack))
        zero_vector = np.zeros(p)
        rhs = -np.row_stack((gfeval.reshape(n,1), zero_vector.reshape(p,1))).T[0]
    
    x_plot = np.zeros((n,maxiter))
    x_plot[:,iteration] = x
    

    #Newton's direction and Newton's decrement
    dir_desc = np.linalg.solve(system_matrix, rhs)
    dir_Newton = dir_desc[0:n]
    dec_Newton = -gfeval.dot(dir_Newton)
    w_dual_variable_estimation = dir_desc[n:(n+p)]


    print('I\tNorm gfLogBarrier \tNewton Decrement\tError x_ast\tError p_ast\tline search\tCondHf')
    print('{}\t\t{:0.2e}\t\t{:0.2e}\t{:0.2e}\t{:0.2e}\t{}\t\t{:0.2e}'.format(iteration,normgf,
                                                                         dec_Newton,Err,
                                                                         Err_plot_aux[iteration],"---",
                                                                         condHf))
    
    stopping_criteria = dec_Newton/2
    iteration+=1
    while(stopping_criteria>tol and iteration < maxiter):
        der_direct = -dec_Newton
        t = line_search_for_log_barrier_by_backtracking(f,dir_Newton,x,t_path,
                                                        constraint_inequalities,
                                                        der_direct)
        x = x + t*dir_Newton
        feval = f(x)
            
        if gf_symbolic and Hf_symbolic:
            gfeval = gf_symbolic(x)
            Hfeval = Hf_symbolic(x)
        else:
            grad_Hess_log_barrier_dict = numerical_differentiation_of_logarithmic_barrier(f,x,t_path,
                                                                                          constraint_inequalities)
            gfeval = grad_Hess_log_barrier_dict['gradient']
            Hfeval = grad_Hess_log_barrier_dict['Hessian']
        
        if (np.all(A < np.nextafter(0,1))): #A is zero matrix
            system_matrix = Hfeval
            rhs = -gfeval
            n = x.size
            p = 0
        else:
            if(A.ndim == 1):
                first_stack = np.column_stack((Hfeval, A.T))
            else:
                first_stack = np.column_stack((Hfeval, A.T))
            system_matrix = np.row_stack((first_stack,second_stack))
            rhs = -np.row_stack((gfeval.reshape(n,1), zero_vector.reshape(p,1))).T[0]

        #Newton's direction and Newton's decrement
        dir_desc = np.linalg.solve(system_matrix, rhs)
        dir_Newton = dir_desc[0:n]
        dec_Newton = -gfeval.dot(dir_Newton)
        w_dual_variable_estimation = dir_desc[n:(n+p)]
        
        Err_plot_aux[iteration]=compute_error(p_ast,feval)
        x_plot[:,iteration] = x
        Err = compute_error(x_ast,x)
        print('{}\t\t{:0.2e}\t\t{:0.2e}\t{:0.2e}\t{:0.2e}\t{:0.2e}\t{:0.2e}'.format(iteration,normgf,
                                                                                dec_Newton,Err,
                                                                                Err_plot_aux[iteration],t,
                                                                                condHf))
        stopping_criteria = dec_Newton/2
        if t<tol_backtracking: #if t is less than tol_backtracking then we need to check the reason
            iter_salida=iteration
            iteration = maxiter - 1
        iteration+=1
    print('{} {:0.2e}'.format("Error of x with respect to x_ast:",Err))
    print('{} {}'.format("Approximate solution:", x))
    cond = Err_plot_aux > np.finfo(float).eps*10**(-2)
    Err_plot = Err_plot_aux[cond]
    
    if iteration == maxiter and t < tol_backtracking:
        print("Backtracking value less than tol_backtracking, check approximation")
        iteration=iter_salida
    else:
        if iteration == maxiter:
            print("Reached maximum of iterations, check approximation")
    x_plot = x_plot[:,:iteration]
    return [x,iteration,Err_plot,x_plot]

def path_following_method_infeasible_init_point(f, A, b,
                                                constraints_ineq,
                                                x_0, nu_0,tol,
                                                tol_backtracking, x_ast=None, p_ast=None, 
                                                maxiter=30,
                                                mu=None,
                                                gf_symbolic=None, Hf_symbolic=None,
                                                tol_outer_iter=1e-6,maxiter_path=30,
                                                ):
    m = len(constraints_ineq.keys())
    if p_ast:
        t_0 = m/math.fabs(f(x_0)-p_ast) #other option: t_0 = mu*m/(f(x_0)-p_ast)
    else:
        print("p_ast must be defined")
    t = t_0
    x = x_0
    stopping_criteria = m/t
    outer_iter = 1
    const_ineq_funcs_eval = constraint_inequalities_funcs_eval(x,constraints_ineq)
    s = 10 + np.max(const_ineq_funcs_eval)
    log_barrier_eval = logarithmic_barrier(f,x,t,constraints_ineq, infeasible = s)
    
    print("Outer iterations of path following method")
    print('{} {:0.2e}'.format("Mu value:", mu))
    print('Outer iteration\tLogBarrier \tt_log_barrier\tStopping criteria')
    print('{}\t\t{:0.2e}\t{:0.2e}\t{:0.2e}'.format(outer_iter,log_barrier_eval,
                                                 t,stopping_criteria
                                                 ))
    print("----------------------------------------------------------------------------------------")
    iter_barrier = 0
    while(stopping_criteria > tol_outer_iter and outer_iter < maxiter_path):
        [x,iteration,Err_plot,x_plot] = Newtons_method_log_barrier_infeasible_init_point(f, A, b,s,
                                                                                         constraints_ineq, t,
                                                                                         x_0, nu_0,tol, 
                                                                                         tol_backtracking, x_ast, p_ast,
                                                                                         maxiter,
                                                                                         gf_symbolic, Hf_symbolic)
        print("Inner iterations")
        print(x)
        const_ineq_funcs_eval = constraint_inequalities_funcs_eval(x,constraints_ineq)
        
        if(sum(const_ineq_funcs_eval > np.nextafter(0,1)) >=1):
            print("Some constraint inequalities evaluated in x were positive, check approximations")
        
        t=mu*t
        s = np.max(const_ineq_funcs_eval)
        log_barrier_eval = logarithmic_barrier(f,x,t,constraints_ineq, infeasible = s)
        outer_iter+=1
        stopping_criteria = m/t
        print("----------------------------------------------------------------------------------------")
        print("Outer iterations of path following method")
        print('{} {:0.2e}'.format("Mu value:", mu))
        print('Outer iteration\tLogBarrier \tt_log_barrier\tStopping criteria')
        print('{}\t\t{:0.2e}\t{:0.2e}\t{:0.2e}'.format(outer_iter,log_barrier_eval,
                                                     t,stopping_criteria
                                                     ))
        print("----------------------------------------------------------------------------------------")
        iter_barrier+= iter_barrier + iteration
            
    return [x,iter_barrier,t]
def Newtons_method_log_barrier_infeasible_init_point(f, A, b, s,
                                                     constraint_inequalities, t_path,
                                                     x_0, nu_0, tol, 
                                                     tol_backtracking, x_ast=None, p_ast=None, maxiter=30,
                                                     gf_symbolic = None,
                                                     Hf_symbolic = None):
    '''
    Newton's method for infeasible initial point to numerically approximate solution of min f subject to Ax = b.
    Calls Newton's method for feasible initial point when reach primal feasibility given by tol.
    Args:
        f (fun): definition of function f as lambda expression or function definition.
        A (numpy ndarray): 2d numpy array of shape (m,n) defines system of constraints Ax=b.
        b (numpy ndarray or float): array that defines system of constraints Ax=b (can be a single number
                                    if just one restriction is defined)
        s
        constraints_ineq
        
        t_path
        
        x_0 (numpy ndarray): initial point for Newton's method. 
        nu_0 (numpy ndarray or float): initial point for Newton's method.
        tol (float): tolerance that will halt method. Controls stopping criteria.
        tol_backtracking (float): tolerance that will halt method. Controls value of line search by backtracking.
        x_ast (numpy ndarray): solution of min f, now it's required that user knows the solution...
        p_ast (float): value of f(x_ast), now it's required that user knows the solution...
        maxiter (int): maximum number of iterations
        gf_symbolic (fun): definition of gradient of f. If given, no approximation is
                                     performed via finite differences.
        Hf_symbolic (fun): definition of Hessian of f. If given, no approximation is
                                     performed via finite differences.
    Returns:
        x (numpy ndarray): numpy array, approximation of x_ast.
        iteration (int): number of iterations.
        Err_plot (numpy ndarray): numpy array of absolute error between p_ast and f(x) with x approximation
                          of x_ast. Useful for plotting.
        x_plot (numpy ndarray): numpy array that containts in columns vector of approximations. Last column
                        contains x, approximation of solution. Useful for plotting.
    '''
    iteration = 0
    x = x_0
    nu = nu_0
    
    feval = f(x)
    if gf_symbolic and Hf_symbolic:
        gfeval = gf_symbolic(x)
        Hfeval = Hf_symbolic(x)
    else:
        grad_Hess_log_barrier_dict = numerical_differentiation_of_logarithmic_barrier(f,x,t_path,
                                                                                      constraint_inequalities,
                                                                                      infeasible = s)
        gfeval = grad_Hess_log_barrier_dict['gradient']
        Hfeval = grad_Hess_log_barrier_dict['Hessian']

    normgf = np.linalg.norm(gfeval)
    condHf= np.linalg.cond(Hfeval)
    
    Err_x_ast = compute_error(x_ast,x)
    Err_p_ast = compute_error(p_ast,feval)

    def residual_dual(nu_fun):
        if(A.ndim>1):
            return gfeval + A.T@nu_fun
        else:
            if(A.ndim==1):
                return gfeval + A.T*nu_fun   
            else: #A is zero matrix
                return np.concatenate((gfeval, nu_fun))
    feasibility_dual = residual_dual(nu)    

    n = x.size
    zero_infeasible1 = np.zeros(n)
    zero_infeasible3 = np.array([0])
    if (np.all(A < np.nextafter(0,1))): #A is zero matrix
        rhs = -np.concatenate((gfeval,zero_infeasible3))
        first_stack = np.column_stack((Hfeval,zero_infeasible1))
        second_stack = np.concatenate((np.zeros(n),np.array([1])))
        system_matrix = np.row_stack((first_stack, second_stack))
        p = 0
        feasibility_primal = s
        residual_primal = lambda s_fun: s
    else:
        if(A.ndim == 1):
            p = 1
            zero_matrix = np.zeros(p)      
            zero_infeasible2 = np.zeros(1)
            first_stack = np.column_stack((Hfeval, A.T, zero_infeasible1))
            second_stack = np.row_stack((A.reshape(1,n).T,zero_matrix, zero_infeasible2)).reshape(1,n+2)[0]
        else:
            p,_ = A.shape
            zero_matrix = np.zeros((p,p))
            zero_infeasible2 = np.zeros(p)
            first_stack = np.column_stack((Hfeval, A.T, zero_infeasible1))
            second_stack = np.column_stack((A,zero_matrix, zero_infeasible2))
            
        third_stack = np.concatenate((np.zeros(n+p),np.array([1]))) 
        system_matrix = np.row_stack((first_stack,second_stack, third_stack))
        
        residual_primal = lambda x_fun: A@x_fun-b
        
        feasibility_primal = residual_primal(x)
        
        rhs = -np.row_stack((feasibility_dual.reshape(n,1), 
                             feasibility_primal.reshape(p,1),
                             zero_infeasible3)).T[0]

    #Newton's direction and Newton's decrement
    dir_desc = np.linalg.solve(system_matrix, rhs)
    dir_Newton_primal = dir_desc[0:n]
    dec_Newton = -gfeval.dot(dir_Newton_primal)
    dir_Newton_dual = dir_desc[n:(n+p)]

    norm_residual_eval = norm_residual(feasibility_primal,
                                       feasibility_dual)

    norm_residual_primal = np.linalg.norm(feasibility_primal)
    norm_residual_dual = np.linalg.norm(feasibility_dual)
    print('I\t||res_primal||\t||res_dual|| \tNewton Decrement\tError x_ast\tError p_ast\tline search\tCondHf')
    print('{}\t{:0.2e}\t{:0.2e}\t{:0.2e}\t{:0.2e}\t{:0.2e}\t{}\t\t{:0.2e}'.format(iteration,norm_residual_primal,
                                                                                  norm_residual_dual,
                                                                                  dec_Newton,Err_x_ast,
                                                                                  Err_p_ast,"---",
                                                                                  condHf))
    
    stopping_criteria = norm_residual_primal > tol
    iteration+=1
    while(stopping_criteria>tol and iteration < maxiter):
        der_direct = -dec_Newton
        t = line_search_for_residual_by_backtracking(residual_primal, residual_dual,
                                                     dir_Newton_primal, dir_Newton_dual,
                                                     x, nu,
                                                     norm_residual_eval
                                                     )
        x = x + t*dir_Newton_primal
        nu = nu + t*dir_Newton_dual
        feval = f(x)
        
        
        if gf_symbolic:
            gfeval = gf_symbolic(x)
        else:
            gfeval = gradient_approximation(f,x)
        
        if Hf_symbolic:
            Hfeval = Hf_symbolic(x)
        else:
            Hfeval = Hessian_approximation(f,x)

        if (np.all(A < np.nextafter(0,1))): #A is zero matrix
            rhs = -np.concatenate((gfeval,zero_infeasible3))
            first_stack = np.column_stack((Hfeval,zero_infeasible1))
            system_matrix = np.row_stack((first_stack, second_stack))
        else:            
            first_stack = np.column_stack((Hfeval, A.T, zero_infeasible1))
    
            system_matrix = np.row_stack((first_stack,second_stack, third_stack))            
            
        
            feasibility_primal = residual_primal(x)
            feasibility_dual = residual_dual(nu)
    
            rhs = -np.row_stack((feasibility_dual.reshape(n,1), 
                                 feasibility_primal.reshape(p,1),
                                 zero_infeasible3)).T[0]
        
        #Newton's direction and Newton's decrement
        dir_desc = np.linalg.solve(system_matrix, rhs)
        dir_Newton_primal = dir_desc[0:n]
        dec_Newton = -gfeval.dot(dir_Newton_primal)
        dir_Newton_dual = dir_desc[n:(n+p)]

        Err_x_ast = compute_error(x_ast,x)
        Err_p_ast = compute_error(p_ast,feval)
        norm_residual_eval = norm_residual(feasibility_primal,
                                           feasibility_dual)
        norm_residual_primal = np.linalg.norm(feasibility_primal)
        norm_residual_dual = np.linalg.norm(feasibility_dual)
        print('{}\t{:0.2e}\t{:0.2e}\t{:0.2e}\t{:0.2e}\t{:0.2e}\t{:0.2e}\t{:0.2e}'.format(iteration,norm_residual_primal,
                                                                                         norm_residual_dual,
                                                                                         dec_Newton,Err_x_ast,
                                                                                         Err_p_ast,t,
                                                                                         condHf))

        stopping_criteria = norm_residual_primal > tol
        if t<tol_backtracking: #if t is less than tol_backtracking then we need to check the reason
            iteration = maxiter - 1
        iteration+=1
    
    if iteration == maxiter and t < tol_backtracking:
        print("Backtracking value less than tol_backtracking, try other initial point")
        return [None,None,None,None]
    else:
        if iteration == maxiter:
            print("------------------------------------------------------------")
            print("------------------------------------------------------------")
            print("------------------------------------------------------------")
            print("Reached maximum of iterations, check primal feasibility")
            print("Continuing with Newtons method for feasible initial point")
            return Newtons_method_log_barrier_feasible_init_point(f,A, constraint_inequalities,
                                                                  t_path, x,tol, 
                                                                  tol_backtracking, x_ast, p_ast, 
                                                                  maxiter,gf_symbolic,Hf_symbolic)
        else:
            print("------------------------------------------------------------")
            print("------------------------------------------------------------")
            print("------------------------------------------------------------")
            print("Beginning Newtons method for feasible initial point")
            return Newtons_method_log_barrier_feasible_init_point(f,A, constraint_inequalities,
                                                                  t_path, x,tol, 
                                                                  tol_backtracking, x_ast, p_ast, 
                                                                  maxiter,gf_symbolic,Hf_symbolic)

def path_following_method_infeasible_init_point_2nd_version(f, A, b,
                                                            constraints_ineq,
                                                            x_0, nu_0,tol,
                                                            tol_backtracking, x_ast=None, p_ast=None, 
                                                            maxiter=30,
                                                            mu=None,
                                                            gf_symbolic=None, Hf_symbolic=None,
                                                            tol_outer_iter=1e-6,maxiter_path=30,
                                                            ):
    m = len(constraints_ineq.keys())
    if p_ast:
        t_0 = m/math.fabs(f(x_0)-p_ast) #other option: t_0 = mu*m/(f(x_0)-p_ast)
    else:
        print("p_ast must be defined")
    t = t_0
    x = x_0
    nu = nu_0
    const_ineq_funcs_eval = constraint_inequalities_funcs_eval(x,constraints_ineq)
    
    idx_positive_const_ineq = const_ineq_funcs_eval > np.nextafter(0,1)
    
    outer_iter = 1
    try:
        s = 10 + np.max(const_ineq_funcs_eval[idx_positive_const_ineq])
    except:
        print("call path_following_method_feasible_init_point")
    
    log_barrier_eval = logarithmic_barrier(f,x,t,constraints_ineq, infeasible = s)
    
    print("Outer iterations of path following infeasible method")
    print('{} {:0.2e}'.format("Mu value:", mu))
    print('LogBarrier \tt_log_barrier\t s_infeasible')
    print('{:0.2e}\t{:0.2e}\t{:0.2e}'.format(log_barrier_eval, t, s))
    print("----------------------------------------------------------------------------------------")
    [x,s,nu, iteration] = wrapper_log_barrier_infeasible_init_point(f, A, b,s,
                                                                    constraints_ineq, t,
                                                                    x, nu,tol, 
                                                                    tol_backtracking, x_ast, p_ast,
                                                                    maxiter,
                                                                    gf_symbolic, Hf_symbolic)        

    print("x")
    print(x)
    const_ineq_funcs_eval = constraint_inequalities_funcs_eval(x,constraints_ineq)
    
    if(sum(const_ineq_funcs_eval > np.nextafter(0,1)) >=1):
        print("Some constraint inequalities evaluated in x were positive, check approximations")
        iterate = True
    else:
        iterate = False
    
    print("s")
    print(s)
    log_barrier_eval = logarithmic_barrier(f,x,t,constraints_ineq, infeasible = s)
    print("----------------------------------------------------------------------------------------")
    print('LogBarrier')
    print('{:0.2e}'.format(log_barrier_eval))
    iter_barrier = 0
    while(iterate and outer_iter < maxiter_path):
        const_ineq_funcs_eval = constraint_inequalities_funcs_eval(x,constraints_ineq)
        
        idx_positive_const_ineq = const_ineq_funcs_eval > np.nextafter(0,1)
        
        try:
            s = 10 + np.max(const_ineq_funcs_eval[idx_positive_const_ineq])
        except:
            print("call path_following_method_feasible_init_point")   
            iterate = False
        print("Inner iterations")
        
        t = mu*t
        log_barrier_eval = logarithmic_barrier(f,x,t,constraints_ineq, infeasible = s)
        outer_iter+=1
        print('{} {:0.2e}'.format("Mu value:", mu))
        print('LogBarrier \tt_log_barrier\t s_infeasible')
        print('{:0.2e}\t{:0.2e}\t{:0.2e}'.format(log_barrier_eval, t, s))
        print("----------------------------------------------------------------------------------------")
        [x,s,nu, iteration] = wrapper_log_barrier_infeasible_init_point(f, A, b,s,
                                                                        constraints_ineq, t,
                                                                        x, nu,tol, 
                                                                        tol_backtracking, x_ast, p_ast,
                                                                        maxiter,
                                                                        gf_symbolic, Hf_symbolic)        
    
        print("x")
        print(x)
        const_ineq_funcs_eval = constraint_inequalities_funcs_eval(x,constraints_ineq)
        
        if(sum(const_ineq_funcs_eval > np.nextafter(0,1)) >=1):
            print("Some constraint inequalities evaluated in x were positive, check approximations")
            iterate = True
        else:
            iterate = False
        
        print("s")
        print(s)   
        iter_barrier+= iter_barrier + iteration
        
    #return [x,iter_barrier,t] 
    return x

def wrapper_log_barrier_infeasible_init_point(f, A, b, s,
                                              constraint_inequalities, t_path,
                                              x_0, nu_0, tol, 
                                              tol_backtracking, x_ast=None, p_ast=None, maxiter=30,
                                              gf_symbolic = None,
                                              Hf_symbolic = None):
    '''
    Newton's method for infeasible initial point to numerically approximate solution of min f subject to Ax = b.
    Calls Newton's method for feasible initial point when reach primal feasibility given by tol.
    Args:
        f (fun): definition of function f as lambda expression or function definition.
        A (numpy ndarray): 2d numpy array of shape (m,n) defines system of constraints Ax=b.
        b (numpy ndarray or float): array that defines system of constraints Ax=b (can be a single number
                                    if just one restriction is defined)
        s
        constraints_ineq
        
        t_path
        
        x_0 (numpy ndarray): initial point for Newton's method. 
        nu_0 (numpy ndarray or float): initial point for Newton's method.
        tol (float): tolerance that will halt method. Controls stopping criteria.
        tol_backtracking (float): tolerance that will halt method. Controls value of line search by backtracking.
        x_ast (numpy ndarray): solution of min f, now it's required that user knows the solution...
        p_ast (float): value of f(x_ast), now it's required that user knows the solution...
        maxiter (int): maximum number of iterations
        gf_symbolic (fun): definition of gradient of f. If given, no approximation is
                                     performed via finite differences.
        Hf_symbolic (fun): definition of Hessian of f. If given, no approximation is
                                     performed via finite differences.
    Returns:
        x (numpy ndarray): numpy array, approximation of x_ast.
        iteration (int): number of iterations.
        Err_plot (numpy ndarray): numpy array of absolute error between p_ast and f(x) with x approximation
                          of x_ast. Useful for plotting.
        x_plot (numpy ndarray): numpy array that containts in columns vector of approximations. Last column
                        contains x, approximation of solution. Useful for plotting.
    '''
    x = x_0
    n = x.size
    x = np.concatenate((x, np.array([s])))
    if (np.all(A < np.nextafter(0,1))): #A is zero matrix
        A = np.concatenate((np.zeros(n), np.array([1])))
        b = 0
        nu = 1.0*s #init nu with random vector?
    else:
        b = np.concatenate((b, np.array([0])))
        second_stack = np.concatenate((np.zeros(n),np.array([1])))
        if(A.ndim == 1):
            first_stack = np.concatenate((A, np.array([0])))
            A = np.row_stack((first_stack,second_stack))
            nu = np.array([s,s], dtype=float) #init nu with random vector?
        else:
            p,_ = A.shape
            first_stack = np.column_stack((A,np.zeros(p)))
            A = np.row_stack((first_stack,second_stack))
            nu = np.ones(p+1, dtype=float)*s    
    
    [x,nu, iteration] = Newtons_method_log_barrier_infeasible_init_point_ceco(f, A, b, 
                                                                              t_path, x, nu, s,
                                                                              constraint_inequalities,
                                                                              tol, tol_backtracking, 
                                                                              np.concatenate((x_ast,np.array([0]))), p_ast, maxiter,
                                                                              gf_symbolic,
                                                                              Hf_symbolic)
    s = x[n]
    x = x[0:n]
    
    return [x,s,nu, iteration]
    
    
def Newtons_method_log_barrier_infeasible_init_point_ceco(f, A, b, 
                                                          t_path, x_0, nu_0, s,
                                                          constraint_inequalities,
                                                          tol, tol_backtracking, 
                                                          x_ast=None, p_ast=None, maxiter=30,
                                                          gf_symbolic = None,
                                                          Hf_symbolic = None):
    '''
    Newton's method for infeasible initial point to numerically approximate solution of min f subject to Ax = b.
    Calls Newton's method for feasible initial point when reach primal feasibility given by tol.
    Args:
        f (fun): definition of function f as lambda expression or function definition.
        A (numpy ndarray): 2d numpy array of shape (m,n) defines system of constraints Ax=b.
        b (numpy ndarray or float): array that defines system of constraints Ax=b (can be a single number
                                    if just one restriction is defined)
        x_0 (numpy ndarray): initial point for Newton's method. 
        nu_0 (numpy ndarray or float): initial point for Newton's method.
        tol (float): tolerance that will halt method. Controls stopping criteria.
        tol_backtracking (float): tolerance that will halt method. Controls value of line search by backtracking.
        x_ast (numpy ndarray): solution of min f, now it's required that user knows the solution...
        p_ast (float): value of f(x_ast), now it's required that user knows the solution...
        maxiter (int): maximum number of iterations
        gf_symbolic (fun): definition of gradient of f. If given, no approximation is
                                     performed via finite differences.
        Hf_symbolic (fun): definition of Hessian of f. If given, no approximation is
                                     performed via finite differences.
    Returns:
        x (numpy ndarray): numpy array, approximation of x_ast.
        iteration (int): number of iterations.
        Err_plot (numpy ndarray): numpy array of absolute error between p_ast and f(x) with x approximation
                          of x_ast. Useful for plotting.
        x_plot (numpy ndarray): numpy array that containts in columns vector of approximations. Last column
                        contains x, approximation of solution. Useful for plotting.
    '''
    iteration = 0
    x = x_0
    nu = nu_0
    
    feval = f(x)
        
    if gf_symbolic and Hf_symbolic:
        gfeval = gf_symbolic(x)
        Hfeval = Hf_symbolic(x)
    else:
        grad_Hess_log_barrier_dict = numerical_differentiation_of_logarithmic_barrier(f,x,t_path,
                                                                                      constraint_inequalities,
                                                                                      infeasible = s)
        gfeval = grad_Hess_log_barrier_dict['gradient']
        Hfeval = grad_Hess_log_barrier_dict['Hessian']  
    
    print('gfeval')
    print(gfeval)
    
    print('Hfeval')
    print(Hfeval)
  
    normgf = np.linalg.norm(gfeval)
    condHf= np.linalg.cond(Hfeval)
    
    Err_x_ast = compute_error(x_ast,x)
    Err_p_ast = compute_error(p_ast,feval)
        
    if(A.ndim == 1):
        p = 1
        n = x.size
        zero_matrix = np.zeros(p)
        first_stack = np.column_stack((Hfeval, A.T))
        second_stack = np.row_stack((A.reshape(1,n).T,zero_matrix)).reshape(1,n+1)[0]
    else:
        p,n = A.shape
        zero_matrix = np.zeros((p,p))
        first_stack = np.column_stack((Hfeval, A.T))
        second_stack = np.column_stack((A,zero_matrix))

    system_matrix = np.row_stack((first_stack,second_stack))
    
    residual_primal = lambda x_fun: A@x_fun-b
    
    def residual_dual(nu_fun):
        if(A.ndim==1):
            return gfeval + A.T*nu_fun
        else:
            return gfeval + A.T@nu_fun
    
    feasibility_primal = residual_primal(x)
    feasibility_dual = residual_dual(nu)
    
    rhs = -np.row_stack((feasibility_dual.reshape(n,1), feasibility_primal.reshape(p,1))).T[0]


    #Newton's direction and Newton's decrement
    dir_desc = np.linalg.solve(system_matrix, rhs)
    dir_Newton_primal = dir_desc[0:n]
    dec_Newton = -gfeval.dot(dir_Newton_primal)
    dir_Newton_dual = dir_desc[n:(n+p)]

    norm_residual_eval = norm_residual(feasibility_primal,
                                       feasibility_dual)

    norm_residual_primal = np.linalg.norm(feasibility_primal)
    norm_residual_dual = np.linalg.norm(feasibility_dual)
    print('I\t||res_primal||\t||res_dual|| \tNewton Decrement\tError x_ast\tError p_ast\tline search\tCondHf')
    print('{}\t{:0.2e}\t{:0.2e}\t{:0.2e}\t{:0.2e}\t{:0.2e}\t{}\t\t{:0.2e}'.format(iteration,norm_residual_primal,
                                                                                  norm_residual_dual,
                                                                                  dec_Newton,Err_x_ast,
                                                                                  Err_p_ast,"---",
                                                                                  condHf))
    
    #stopping_criteria = norm_residual_primal
    #stopping_criteria = norm_residual_eval
    stopping_criteria = dec_Newton/2
    iteration+=1
    while(stopping_criteria>tol and iteration < maxiter):
        der_direct = -dec_Newton
        t = line_search_for_log_barrier_by_backtracking(f,dir_Newton_primal,x,t_path,
                                                        constraint_inequalities,
                                                        der_direct,
                                                        infeasible = s)
        #t = line_search_for_residual_by_backtracking(residual_primal, residual_dual,
        #                                             dir_Newton_primal, dir_Newton_dual,
        #                                             x, nu,
        #                                             norm_residual_eval
        #                                             )
        x = x + t*dir_Newton_primal
        nu = nu + t*dir_Newton_dual
        feval = f(x)
        
        s = x[p-1]
        if gf_symbolic and Hf_symbolic:
            gfeval = gf_symbolic(x)
            Hfeval = Hf_symbolic(x)
        else:
            grad_Hess_log_barrier_dict = numerical_differentiation_of_logarithmic_barrier(f,x,t_path,
                                                                                          constraint_inequalities,
                                                                                          infeasible = s)
            gfeval = grad_Hess_log_barrier_dict['gradient']
            Hfeval = grad_Hess_log_barrier_dict['Hessian']  
        
        if(A.ndim == 1):
            first_stack = np.column_stack((Hfeval, A.T))
        else:
            first_stack = np.column_stack((Hfeval, A.T))

        system_matrix = np.row_stack((first_stack,second_stack))
        
        feasibility_primal = residual_primal(x)
        feasibility_dual = residual_dual(nu)
        rhs = -np.row_stack((feasibility_dual.reshape(n,1), feasibility_primal.reshape(p,1))).T[0]
      
        #Newton's direction and Newton's decrement
        dir_desc = np.linalg.solve(system_matrix, rhs)
        dir_Newton_primal = dir_desc[0:n]
        dec_Newton = -gfeval.dot(dir_Newton_primal)
        dir_Newton_dual = dir_desc[n:(n+p)]

        Err_x_ast = compute_error(x_ast,x)
        Err_p_ast = compute_error(p_ast,feval)
        norm_residual_eval = norm_residual(feasibility_primal,
                                           feasibility_dual)
        norm_residual_primal = np.linalg.norm(feasibility_primal)
        norm_residual_dual = np.linalg.norm(feasibility_dual)
        print('{}\t{:0.2e}\t{:0.2e}\t{:0.2e}\t{:0.2e}\t{:0.2e}\t{:0.2e}\t{:0.2e}'.format(iteration,norm_residual_primal,
                                                                                         norm_residual_dual,
                                                                                         dec_Newton,Err_x_ast,
                                                                                         Err_p_ast,t,
                                                                                         condHf))

        #stopping_criteria = norm_residual_primal
        #stopping_criteria = norm_residual_eval
        stopping_criteria = dec_Newton/2
        if t<tol_backtracking: #if t is less than tol_backtracking then we need to check the reason
            iteration = maxiter - 1
        iteration+=1     
        
    if iteration == maxiter and t < tol_backtracking:
        print("Backtracking value less than tol_backtracking, try other initial point")
        return [x,None,None]
    else:      
        if iteration == maxiter:
            print("------------------------------------------------------------")
            print("------------------------------------------------------------")
            print("------------------------------------------------------------")
            print("Reached maximum of iterations, check primal feasibility")
            return [x, nu, iteration]
        else:
            print("------------------------------------------------------------")
            print("------------------------------------------------------------")
            print("------------------------------------------------------------")
            return [x, nu, iteration]
        