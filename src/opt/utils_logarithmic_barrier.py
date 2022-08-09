import numpy as np
import matplotlib.pyplot as plt

def log_barrier_aux_eval_constraints(eval_f_const_inequality):
    """
    Auxiliary function for evaluation of constraint inequalities
    in logarithmic barrier
    """
    #get values that are nonpositive through indexes
    idx_zeros = np.logical_and(eval_f_const_inequality < np.nextafter(0,1),
                               eval_f_const_inequality > -np.nextafter(0,1))
    idx_negative = eval_f_const_inequality < 0
    idx  = np.logical_or(idx_zeros, idx_negative)
    #eval constraint inequality functions
    #next line produces warning if a value of constraint
    #is nonpositive
    eval_f_const_inequality = np.log(eval_f_const_inequality)
    #assign large negative value for constraints
    #that have values negative or equal to 0
    eval_f_const_inequality[idx] = -1e10
    return eval_f_const_inequality
def constraints_inequalities_funcs_generator(constraints_inequalities):
    """
    Generator for functional form of inequalities.
    For every example this function produces different functions.
    """
    for k, v in constraints_inequalities.items():
        yield v
def constraints_inequalities_funcs_eval(x,
                                        constraints_inequalities):
    """
    Auxiliary function that build a numpy array with constraints evaluated.
    Useful when calling log_barrier_aux_eval_constraints func. 
    """
    const_ineq_funcs_eval = np.array([const(x) for const in \
                                      constraints_inequalities_funcs_generator(constraints_inequalities)])
    return const_ineq_funcs_eval
def phi(x, constraints_inequalities):
    """
    Implementation of phi function for logarithmic barrier.
    """
    constraint_ineq_funcs_eval = -constraints_inequalities_funcs_eval(x,constraints_inequalities)
    log_barrier_const_eval = log_barrier_aux_eval_constraints(constraint_ineq_funcs_eval)
    return -np.sum(log_barrier_const_eval)
