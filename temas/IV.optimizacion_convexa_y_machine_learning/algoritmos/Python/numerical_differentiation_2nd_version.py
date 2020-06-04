import numpy as np

from utils_2nd_version import inc_index, dec_index, \
                              constraint_inequalities_funcs_generator

def gradient_approximation(f,x,h=1e-8):
    '''
    Numerical approximation of gradient for function f using forward differences.
    Args:
        f (lambda expression): definition of function f.
        x (array): numpy array that holds values where gradient will be computed.
        h (float): step size for forward differences, tipically h=1e-8
    Returns:
        gf (array): numerical approximation to gradient of f.
    '''
    n = x.size
    gf = np.zeros(n)
    f_x = f(x)
    for i in np.arange(n):
        inc_index(x,i,h)
        gf[i] = f(x) - f_x
        dec_index(x,i,h)
    return gf/h
def Hessian_approximation(f,x,h=1e-6):
    '''
    Numerical approximation of Hessian for function f using forward differences.
    Args:
        f (lambda expression): definition of function f.
        x (array): numpy array that holds values where Hessian will be computed.
        h (float): step size for forward differences, tipically h=1e-6
    Returns:
        Hf (array): numerical approximation to Hessian of f.
    '''
    n = x.size
    Hf = np.zeros((n,n))
    f_x = f(x)
    for i in np.arange(n):
        inc_index(x,i,h)
        f_x_inc_in_i = f(x)
        for j in np.arange(i,n):
            inc_index(x,j,h)
            f_x_inc_in_i_j = f(x)
            dec_index(x,i,h)
            f_x_inc_in_j = f(x)
            dif = f_x_inc_in_i_j-f_x_inc_in_i-f_x_inc_in_j+f_x
            Hf[i,j] = dif
            if j != i:
                Hf[j,i] = dif
            dec_index(x,j,h)
            inc_index(x,i,h)
        dec_index(x,i,h)
    return Hf/h**2
def numerical_differentiation_of_logarithmic_barrier(f, x, t_path, constraint_inequalities,
                                                     infeasible = None):
    '''
    First and second derivative of logarithmic barrier function approximation
    via finite differences
    '''
    sum_gf_const = 0
    sum_Hf_const = 0
    for const in constraint_inequalities_funcs_generator(constraint_inequalities):
        const_eval = const(x)
        gf_const_eval = gradient_approximation(const, x)
        Hf_const_eval = Hessian_approximation(const, x)
        sum_gf_const += gf_const_eval/(-const_eval) if not infeasible else \
                        gf_const_eval/(infeasible - const_eval)
        if not infeasible:
            sum_Hf_const += np.outer(gf_const_eval,gf_const_eval)/const_eval**2 - Hf_const_eval/const_eval
        else:
            sum_Hf_const += np.outer(gf_const_eval,gf_const_eval)/(infeasible - const_eval)**2 + \
                            Hf_const_eval/(infeasible - const_eval)
    gf_eval = gradient_approximation(f,x)
    Hf_eval = Hessian_approximation(f,x)
    return {'gradient': t_path*gf_eval + sum_gf_const,
            'Hessian': t_path*Hf_eval + sum_Hf_const
           }