from utils import norm_residual

def line_search_by_backtracking(f,dir_desc,x,
                                der_direct, alpha=.15, beta=.5):
    '''
    Line search that sufficiently decreases f restricted to a ray in the direction dir_desc.
    Args:
        alpha (float): parameter in line search with backtracking, tipically .15
        beta (float): parameter in line search with backtracking, tipically .5
        f (lambda expression): definition of function f.
        dir_desc (array): descent direction.
        x (array): numpy array that holds values where line search will be performed.
        der_direct (float): directional derivative of f.
    Returns:
        t (float): positive number for stepsize along dir_desc that sufficiently decreases f.
    '''
    t=1
    if alpha > 1/2:
        print('alpha must be less than or equal to 1/2')
        t=-1
    if beta>1:
        print('beta must be less than 1')
        t=-1;   
    if t!=-1:
        eval1 = f(x+t*dir_desc)
        eval2 = f(x) + alpha*t*der_direct
        while eval1 > eval2:
            t=beta*t
            eval1=f(x+t*dir_desc)
            eval2=f(x)+alpha*t*der_direct
    return t

def line_search_for_residual_by_backtracking(r_primal, r_dual,dir_desc_primal,dir_desc_dual,x, nu,
                                             norm_residual_eval,
                                             alpha=.15, beta=.5):
    '''
    Line search that sufficiently decreases residual for Newtons infeasible initial point method
    restricted to a ray in the direction dir_desc.
    Args:
        r_primal (fun): definition of primal residual as function definition or lambda expression.
        r_dual (fun): definition of dual residual as function definition or lambda expression.
        dir_desc_primal (array): descent direction for primal variable.
        dir_desc_dual (array): descent direction for dual variable.
        x (array): numpy array that holds values where line search will be performed.
        nu (array): numpy array that holds values where line search will be performed.
        norm_residual_eval (float): norm of residual that has both r_primal and r_dual evaluations in
                                    x and nu
        alpha (float): parameter in line search with backtracking, tipically .15
        beta (float): parameter in line search with backtracking, tipically .5
        
    Returns:
        t (float): positive number for stepsize along dir_desc that sufficiently decreases f.
    '''
    t=1
    if alpha > 1/2:
        print('alpha must be less than or equal to 1/2')
        t=-1
    if beta>1:
        print('beta must be less than 1')
        t=-1;   
    if t!=-1:
        feas_primal = r_primal(x + t*dir_desc_primal)
        feas_dual = r_dual(nu + t*dir_desc_dual )
        eval1 = norm_residual(feas_primal, feas_dual)
        eval2 = (1-alpha*t)*norm_residual_eval
        while eval1 > eval2:
            t=beta*t
            feas_primal = r_primal(x + t*dir_desc_primal)
            feas_dual = r_dual(nu + t*dir_desc_dual )
            eval1 = norm_residual(feas_primal, feas_dual)
            eval2 = (1-alpha*t)*norm_residual_eval
    return t