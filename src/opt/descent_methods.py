import numpy as np

from opt.compute_step_size import line_search_by_backtracking
from opt.utils import compute_error, print_iterations, plot_error_of_optimum_value, \
plot_sequence_of_approximations


def set_values_and_solve_linear_system_for_Newton_method(x, rhs, Hf):
    """
    Helper function to evaluate Hessian, compute Newton's direction.
    """
    Hf.set_x(x)
    Hf_eval = Hf.evaluate()
    condHf = np.linalg.cond(Hf_eval)
    system_matrix = Hf_eval
    descent_dir = np.linalg.solve(system_matrix, rhs)
    return (Hf_eval, condHf, system_matrix, descent_dir)

def feasible_init_point_descent_method(f,
                                       x,
                                       tol,
                                       tol_backtracking, 
                                       x_ast=None,
                                       p_ast=None, 
                                       maxiter=30,
                                       gf=None,
                                       Hf=None,
                                       plot=True,
                                       method="Newton"):
    """
    Descent method to approximate minimum of function f: Rn -> R.
    Gradient, coordinate descent or Newton's method (default) can be used.
    Gradient and Hessian of function must be provided as instances of classes,
    see classes.functions of opt pkg for more info.

    Args:

        f (opt function class): instance of class for objective function.

        x (numpy ndarray): initial point for descent method.

        tol (float): tolerance that will halt method.
            Controls stopping criteria.

        tol_backtracking (float): tolerance that will halt method.
            Controls value of line search by backtracking.

        x_ast (numpy ndarray): solution of min f_o subject to Ax <= b.
            It's required that user knows the solution...

        p_ast (float): value of f_o(x_ast).

        maxiter (int): maximum number of iterations.

        gf (opt function class): instance of class for gradient of f.

        Hf (opt function class): instance of class for Hessian of f.
        
        method (str): type of method that will be used, gradient, Newton        
        
    Returns:

        x (numpy ndarray): numpy array, approximation solution of
            inner iterations problem.

        iteration (int): number of iterations.

        Err_plot (numpy ndarray): numpy array of absolute error
            between p_ast and f(x) with x approximation of x_ast.
            Useful for plotting.

        x_plot (numpy ndarray): numpy array that containts in columns
            vector of approximations. Last column contains x, approximation
            of solution. Useful for plotting.
    """
    iteration = 0
    f.set_x(x)    
    x = f.x
    n = x.size
    f.evaluate()
    f_eval = f.f_eval #or f_eval = f.evaluate() ?
    gf.set_x(x)
    gf_eval = gf.evaluate()
    normgf = np.linalg.norm(gf_eval)
    rhs = -gf_eval
    
    if method == "Newton" or method == "logarithmic_barrier":
        (Hf_eval, 
         condHf, 
         system_matrix, 
         descent_dir) = set_values_and_solve_linear_system_for_Newton_method(x, 
                                                                             rhs, 
                                                                             Hf)
    else:
        if method == "gradient":            
            descent_dir = rhs
        else:
            if method == "coordinate descent":
                idx_max_absolute_value = np.argmax(np.abs(rhs))
                descent_dir = np.zeros(n)
                descent_dir[idx_max_absolute_value] = rhs[idx_max_absolute_value]

    dec_Newton_squared = rhs.dot(descent_dir)
    
    Err_plot_aux = np.zeros(maxiter)
    Err_plot_aux[iteration]=compute_error(p_ast,f_eval)
    Err = compute_error(x_ast,x)

    x_plot = np.zeros((n,maxiter))
    x_plot[:,iteration] = x

    if method == "Newton":
        columns = ["Iter", "Normgf", "Newtons decrement",
                   "Err x ast", "Err p ast",
                   "line search", "CondHf"]
    else:
        if method == "logarithmic_barrier":
            columns = ["Iter", "Normgf_B", "Newtons decrement",
                       "Err x ast", "Err p ast",
                       "line search", "CondHf_B"]
        else:
            if method == "gradient" or method == "coordinate descent":
                columns = ["Iter", "Normgf", "Newtons decrement",
                           "Err x ast", "Err p ast",
                           "line search"]            

    if method == "Newton" or method == "logarithmic_barrier":
        list_values = [iteration, normgf, dec_Newton_squared,
                       Err, Err_plot_aux[iteration], "---", condHf]
    else:
        list_values = [iteration, normgf, dec_Newton_squared,
                       Err, Err_plot_aux[iteration], "---"]        

    data = {"row" + str(iteration): list_values}

    #print
    print_iterations(data, columns)

    #stopping criteria
    stopping_criteria = dec_Newton_squared/2
    iteration+=1

    while(stopping_criteria>tol and iteration < maxiter):
        der_direct = -dec_Newton_squared
        t = line_search_by_backtracking(f,
                                        descent_dir,
                                        der_direct)
        x = x + t*descent_dir
        f.set_x(x)
        f.evaluate()
        f_eval  = f.f_eval #or f_eval = f.evaluate() ?
        gf.set_x(x)
        gf_eval = gf.evaluate()
        rhs = -gf_eval
        normgf = np.linalg.norm(gf_eval)
        
        if method == "Newton" or method == "logarithmic_barrier":        
            (Hf_eval,
             condHf,
             system_matrix,
             descent_dir) = set_values_and_solve_linear_system_for_Newton_method(x, 
                                                                                 rhs, 
                                                                                 Hf)
        else:
            if method == "gradient":            
                descent_dir = rhs
            else:
                if method == "coordinate descent":
                    idx_max_absolute_value = np.argmax(np.abs(rhs))
                    descent_dir = np.zeros(n)
                    descent_dir[idx_max_absolute_value] = rhs[idx_max_absolute_value]

        dec_Newton_squared = rhs.dot(descent_dir)
        
        Err_plot_aux[iteration]=compute_error(p_ast,f_eval)
        x_plot[:,iteration] = x
        Err = compute_error(x_ast,x)
        stopping_criteria = dec_Newton_squared/2
        
        if method == "Newton" or method == "logarithmic_barrier":
            list_values = [iteration, normgf, dec_Newton_squared,
                           Err, Err_plot_aux[iteration], t, condHf]
        else:
            list_values = [iteration, normgf, dec_Newton_squared,
                           Err, Err_plot_aux[iteration], t]
            
        data = {"row" + str(iteration): list_values}
        print_iterations(data, columns)

        if t<tol_backtracking: #if t is less than tol_backtracking
                               #then we need to check the reason
            iter_salida=iteration
            iteration = maxiter - 1
        iteration+=1
    print('{} {:0.2e}'.format("Error of x with respect to x_ast:",Err))
    print('{} {}'.format("Approximate solution:", x))
    idx_columns_for_plot = Err_plot_aux > np.finfo(float).eps*10**(-2)
    Err_plot = Err_plot_aux[idx_columns_for_plot]

    if iteration == maxiter and t < tol_backtracking:
        print("Backtracking value less than tol_backtracking, check approximation")
        iteration=iter_salida
    else:
        if iteration == maxiter:
            print("Reached maximum of iterations, check approximation")
    x_plot = x_plot[:,:iteration]
    if plot and Err_plot.size >= 2:
        plot_error_of_optimum_value(Err_plot)
    if plot and x_plot.size >= 2:
        plot_sequence_of_approximations(x_plot)
    return [x,iteration,Err_plot,x_plot]