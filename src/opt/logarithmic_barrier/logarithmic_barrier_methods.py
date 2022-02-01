import numpy as np

from opt.utils_logarithmic_barrier import constraints_inequalities_funcs_eval
from opt.utils import compute_error, print_iterations, plot_error_of_optimum_value, \
plot_sequence_of_approximations
from opt.descent_methods import feasible_init_point_descent_method

def primal_dual_feasible_init_point_method(f_B,
                                           x,
                                           t_B,
                                           mu,
                                           x_ast,
                                           p_ast,
                                           gf_B,
                                           Hf_B,
                                           plot=True,
                                           tol_inner_iter=1e-8,
                                           tol_outer_iter=1e-6,
                                           tol_backtracking=1e-12,
                                           max_inner_iter=30,
                                           max_total_iterations=30):
    """
    Outer iterations for logarithmic barrier method
    to numerically approximate solution of PL with only inequalities.

    Args:

        f_B (opt function class): instance of class for f_B (logarithmic barrier).
        
        x (numpy ndarray): initial point for logarithmic barrier method.
        
        t_B (float): initial point for parameter barrier.        

        mu (float): parameter that will multiply barrier parameter.
        
        x_ast (numpy ndarray): solution of min f_o subject to Ax <= b.
            It's required that user knows the solution...

        p_ast (float): value of f_B(x_ast).
        
        gf_B (opt function class): instance of class for gradient of f_B (logarithmic barrier).

        Hf_B (opt function class): instance of class for Hessian of f_B (logarithmic barrier).
        
        plot (bool): if true make plots of Err vs iterations and
            plot of central path.        

        tol_inner_iter (float): tolerance that will halt method.
            Controls stopping criteria for inner iterations (iterations of descent method).
            
        tol_outer_iter (float): tolerance that will halt method.
            Controls stopping criteria for outer iterations.            

        tol_backtracking (float): tolerance that will halt method.
            Controls value of line search by backtracking.

        max_inner_iter (int): maximum number of inner iterations
            (iterations of descent method).

        max_total_iter (int): maximum number of total iterations.

    Returns:

        x (numpy ndarray): numpy array, approximation of x_ast.

        total_iter (int): number of iterations regarding outer and
            inner iterations.

        t_B (float): updated barrier parameter.

        x_plot_total_iter (numpy ndarray): numpy array that containts
            in columns vector of approximations of all inner iterations.
            Last column contains x, approximation of solution. Useful
            for plotting.
    """
    f_B.set_x(x)
    f_B.set_t_B(t_B)
    t_B = f_B.t_B
    n   = x.size
    constraints_ineq = f_B.constraints_inequalities
    f_B.set_x(x)
    f_B.set_t_B(t_B)
    log_barrier_eval = f_B.evaluate()
    gf_B.set_t_B(t_B)
    Hf_B.set_t_B(t_B)
    m = len(constraints_ineq.keys())
    stopping_criteria = m/t_B
    outer_iter = 0
    total_iter = 0
    const_funcs_eval = -constraints_inequalities_funcs_eval(x, constraints_ineq)

    if(sum(const_funcs_eval < -np.nextafter(0,1)) >=1):
        print("Some constraint inequalities evaluated in x were nonpositive, change initial point")
    else:
        print("Outer iterations of primal-dual LB method")
        print('{} {:0.2e}'.format("Mu value:", mu))
        columns = ["Outer iter", "logbarrier", "t_log_barrier",
                   "duality gap"]
        list_values = [outer_iter, log_barrier_eval, t_B,
                       stopping_criteria]
        data = {"row" + str(outer_iter): list_values}
        print_iterations(data, columns)
        print("-"*65 + "\n" + "-"*65)
        error_between_iterations = 1

        while(stopping_criteria > tol_outer_iter \
              and error_between_iterations > tol_outer_iter \
              and total_iter < max_total_iterations):
            x_aux = x
            [x,
             inner_iterations,
             Err_plot,
             x_plot] = feasible_init_point_descent_method(f_B,
                                                          x,
                                                          tol_inner_iter,
                                                          tol_backtracking,
                                                          x_ast, 
                                                          p_ast,
                                                          max_inner_iter,
                                                          gf_B,
                                                          Hf_B,
                                                          plot=False,
                                                          method="logarithmic_barrier"
                                                          )
            if(outer_iter == 0):
                x_plot_total_iter = x_plot
            else:
                x_plot_total_iter = np.column_stack((x_plot_total_iter,
                                                     x_plot))
            error_between_iterations = compute_error(x, x_aux)
            if(error_between_iterations > tol_outer_iter):
                if plot and Err_plot.size >= 2:
                    plot_error_of_optimum_value(Err_plot)
                if plot and x_plot.size >= 2:
                    plot_sequence_of_approximations(x_plot,
                                                    title="Primal-dual BL method sequence of approximations")
                print("Inner iterations")
                print(x)
                const_ineq_funcs_eval = -constraints_inequalities_funcs_eval(x,
                                                                             constraints_ineq)
                t_B = mu*t_B                
                f_B.set_x(x)
                f_B.set_t_B(t_B)
                log_barrier_eval = f_B.evaluate()
                gf_B.set_t_B(t_B)
                Hf_B.set_t_B(t_B)

                if(sum(const_ineq_funcs_eval < -np.nextafter(0,1)) >=1):
                    print("Some constraint inequalities evaluated in x were nonpositive, check approximations")
                    total_iter = max_total_iterations
                    x = t_B = x_plot_total_iter = None
                else:
                    outer_iter += 1
                    stopping_criteria = m/t_B
                    total_iter+= total_iter + inner_iterations
                    #print
                    print("-"*65 + "\n" + "-"*65)
                    print("Outer iterations of primal-dual LB method")
                    print('{} {:0.2e}'.format("Mu value:", mu))
                    list_values = [outer_iter, log_barrier_eval, t_B,
                                   stopping_criteria]
                    data = {"row" + str(outer_iter): list_values}
                    print_iterations(data, columns)
                    print("-"*65 + "\n" + "-"*65)
    return [x,total_iter,t_B,x_plot_total_iter]