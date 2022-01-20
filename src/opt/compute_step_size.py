def line_search_by_backtracking(f,
                                dir_desc,
                                der_direct,
                                alpha=.15, 
                                beta=.5):
    """
    Line search that sufficiently decreases f restricted to a
    ray in the direction dir_desc.

    Args:
    
        f: instance of class for objective function.
        
        dir_desc (array): descent direction.
            
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
        x = f.x
        f.set_x(x + t*dir_desc)
        eval1 = f.evaluate()
        f.set_x(x)
        eval2 = f.evaluate() + alpha*t*der_direct
        while eval1 > eval2:
            t = beta*t
            f.set_x(x + t*dir_desc)
            eval1 = f.evaluate()
            f.set_x(x)
            eval2 = f.evaluate() + alpha*t*der_direct
    return t