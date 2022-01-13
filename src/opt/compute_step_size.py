from opt.utils_logarithmic_barrier import logarithmic_barrier

def line_search_for_log_barrier_by_backtracking(f,dir_desc,
                                                x,t_B,
                                                constraint_inequalities,
                                                der_direct,
                                                alpha=.15, beta=.5):
    """
    Line search that sufficiently decreases f restricted to a
    ray in the direction dir_desc.

    Args:
    
        f (lambda expression): definition of function f.
        
        dir_desc (array): descent direction.
        
        x (array): numpy array that holds values where line search
            will be performed.
            
        t_B (float): barrier parameter.
        
        constraint_inequalities (dict): dictionary of inequalities constraints
            in "<= 0" form.
            
        der_direct (float): directional derivative of f.            

        alpha (float): parameter in line search with backtracking,
            tipically .15

        beta (float): parameter in line search with backtracking,
            tipically .5        

    Returns:

        t (float): positive number for stepsize along dir_desc that
            sufficiently decreases f.
    """
    t = 1
    if alpha > 1/2:
        print('alpha must be less than or equal to 1/2')
        t = -1
    if beta>1:
        print('beta must be less than 1')
        t = -1
    if t != -1:
        eval1 = logarithmic_barrier(f, x + t*dir_desc, t_B, constraint_inequalities)
        eval2 = logarithmic_barrier(f, x, t_B, constraint_inequalities) + alpha*t*der_direct
        while eval1 > eval2:
            t = beta*t
            eval1 = logarithmic_barrier(f, x + t*dir_desc, t_B, constraint_inequalities)
            eval2 = logarithmic_barrier(f, x, t_B, constraint_inequalities) + alpha*t*der_direct
    return t