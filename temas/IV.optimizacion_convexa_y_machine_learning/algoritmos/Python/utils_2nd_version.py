import numpy as np

def inc_index(vec,index,h):
    '''
    Auxiliary function for gradient and Hessian computation.
    Args:
        vec (array): numpy array.
        index (int): index.
        h (float):   quantity that vec[index] will be increased.
    Returns:
        vec (array): numpy array vec with vec[index] increased by h.
    '''
    vec[index] +=h
    return vec

def dec_index(vec,index,h=1):
    '''
    Auxiliary function for gradient and Hessian computation.
    Args:
        vec (array): numpy array.
        index (int): index.
        h (float):   quantity that vec[index] will be decreased.
    Returns:
        vec (array): numpy array vec with vec[index] decreased by h.
    '''
    vec[index] -=h
    return vec
def compute_error(x_obj,x_approx):
    '''
    Relative or absolute error between x_obj and x_approx.
    '''
    if np.linalg.norm(x_obj) > np.nextafter(0,1):
        Err=np.linalg.norm(x_obj-x_approx)/np.linalg.norm(x_obj)
    else:
        Err=np.linalg.norm(x_obj-x_approx)
    return Err
def norm_residual(feas_primal, feas_dual):
    '''
    Computes norm of residual for Newtons infeasible initial point method
    '''
    return np.sqrt(np.linalg.norm(feas_primal)**2 +\
                   np.linalg.norm(feas_dual)**2
                   )
def log_barrier_aux_eval_constraints(eval_f_const_inequality):
    '''
    Auxiliary function for evaluation of constraint inequalities in logarithmic barrier
    '''
    #get values that are nonnegative through indexes
    idx_zeros = np.logical_and(eval_f_const_inequality < np.nextafter(0,1),
                               eval_f_const_inequality > -np.nextafter(0,1))
    idx_positive = eval_f_const_inequality > 0 
    idx  = np.logical_or(idx_zeros, idx_positive) 
    #eval constraint inequality functions
    #next line produces warning if a value of constraint is nonnegative
    eval_f_const_inequality = np.log(-eval_f_const_inequality)                                                           
    #assign large value for values positive or equal to 0
    eval_f_const_inequality[idx] = 1e10     
    return eval_f_const_inequality
def constraint_inequalities_funcs_eval(x, constraint_inequalities):
    '''
    Auxiliary function for the evaluation of constraint inequalities in logarithmic barrier function
    '''
    const_ineq_funcs_eval = np.array([const(x) for const in \
                                      constraint_inequalities_funcs_generator(constraint_inequalities)])
    return const_ineq_funcs_eval
def logarithmic_barrier(f,x, t_path, constraint_inequalities, infeasible = None):
    '''
    Implementation of Logarithmic barrier function.
    '''
    if not infeasible: #then is a feasible point and satisfies less or equal than zero for all inequalities
        constraint_ineq_funcs_eval = constraint_inequalities_funcs_eval(x,constraint_inequalities)
    else: #infeasible needs to be a number greater than max fi(x)
        constraint_ineq_funcs_eval = infeasible - constraint_inequalities_funcs_eval(x,constraint_inequalities)
    log_barrier_const_eval = log_barrier_aux_eval_constraints(constraint_ineq_funcs_eval)
    return t_path*f(x) + np.sum(log_barrier_const_eval)
def constraint_inequalities_funcs_generator(constraint_inequalities):
    '''
    Generator for functional form of inequalities.
    For every example this function produces different fuctions.
    '''
    for k, v in constraint_inequalities.items():
        yield v