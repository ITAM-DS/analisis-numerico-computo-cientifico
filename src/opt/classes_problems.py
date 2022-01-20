import numpy as np

from opt.classes_functions import ObjectiveFunction, LogarithmicBarrier
from opt.logarithmic_barrier.logarithmic_barrier_methods import primal_dual_feasible_init_point_method
from opt.descent_methods import feasible_init_point_descent_method

class ProblemFeasibleInitPoint():
    """
    Class to define problems: UCO, CICO, CECO, CIECO.
    """
    def __init__(self, 
                 type_problem,
                 f,
                 constraints_ineq=None,
                 mu=None,
                 constraints_eq=None):
        """
        Args:
            type_problem (str): UCO, CICO, CECO or CIECO.
            f (fun): numpy definition of objective function.
            constraints_ineq (dict): dictionary of inequalities constraints
                in "<= 0" form.
            mu (float): parameter for logarithmic barrier if CICO, CIECO are
                selected.
            constraints_eq (dict): TBD.
            
        """
        if type_problem == "CICO" or type_problem == "CIECO":
            self.logarithmic_barrier = True
            if not mu:
                print("parameter mu is missing, must be defined")
            else:
                self.mu = mu
                if not constraints_ineq:
                    print("constraints of inequalities are missing, must be defined")
                else: #defined constraints_ineq
                    if type_problem == "CIECO" and not constraints_eq:
                        print("constraints of equalities are missing, must be defined")
                    else:
                        self.objective_function = LogarithmicBarrier(f,
                                                                     constraints_ineq)                    
                        self.well_defined_problem = True
                        if type_problem == "CIECO":
                            self.type_problem = "CIECO"
                            self.constraints_equalities = constraints_eq
                        else:
                            self.type_problem = "CICO"
        else: #UCO or CECO
            if type_problem == "UCO":
                self.type_problem = "UCO"
                self.logarithmic_barrier = False
                self.well_defined_problem = True
            else:
                if not type_problem == "CECO":
                    print("problems that will be solved: UCO, CICO, CECO, CIECO, select one of them")
                else: #CECO
                    if not constraints_eq:
                        print("constraints of equalities are missing, must be defined")
                    else: #CECO and constraints_eq defined
                        self.type_problem = "CECO"
                        self.well_defined_problem = True
                        self.constraints_equalities = constraints_eq
            if self.well_defined_problem:
                self.objective_function = ObjectiveFunction(f)
                
    def solve(self,
              x=None,
              t_B=None,
              x_ast=None, 
              p_ast=None,
              gf_B=None,
              Hf_B=None,
              plot=True,              
              tol_inner_iter=1e-8,
              tol_outer_iter=1e-6,
              tol_backtracking=1e-12,
              max_inner_iter=30,
              max_total_iterations=30,
              method=None):
        """
        Args:
            x (numpy ndarray): initial point for logarithmic barrier or descent method.
            
            t_B (float): initial point for parameter barrier in logarithmic barrier method.
            
            x_ast (numpy ndarray): solution of optimization problem.
            
            p_ast (float) value of original objective function.
            
            gf_B (opt function class): instance of class for gradient of objective function,
                could be of original or logarithmic barrier.
                
            Hf_B (opt function class): instance of class for Hessian of objective function,
                could be of original or logarithmic barrier.
                
            tol_inner_iter (float): tolerance that will halt method.
                Controls stopping criteria for inner iterations (iterations of descent method).
                
            tol_outer_iter (float): tolerance that will halt method.
                Controls stopping criteria.
                
            tol_backtracking (float): tolerance that will halt method.
                Controls value of line search by backtracking.
                
            max_inner_iter (int): maximum number of inner iterations
                (iterations of descent method).

            max_total_iter (int): maximum number of total iterations.
            
            method (str): type of method that will be used, gradient, Newton  
  
        Returns:
        
            Depends of problem to be solved. 
            See opt.logarithmic_barrier.logarithmic_barrier_methods.primal_dual_feasible_init_point_method
            and opt.descent_methods.feasible_init_point_descent_method
        
        """
        if self.type_problem == "CICO" or self.type_problem == "CIECO":
            call_method = "primal_dual_feasible_init_point_method"
        else:
            call_method = "feasible_init_point_descent_method"
            if not method:
                method = "Newton"
                print("will use %s method, if wants to use another select gradient or ..." % method)
        
        if isinstance(x_ast, np.ndarray) and p_ast and gf_B and Hf_B:
            if call_method == "primal_dual_feasible_init_point_method":
                #gf_B is gradient of logarithmic barrier funct
                #Hf_B is Hessian of logarithmic barrier funct
                if not t_B:
                    print("pass t_B as argument when calling solve")
                else:
                    return primal_dual_feasible_init_point_method(self.objective_function,
                                                                  x,
                                                                  t_B,
                                                                  self.mu,
                                                                  x_ast,
                                                                  p_ast,
                                                                  gf_B,
                                                                  Hf_B,
                                                                  plot,
                                                                  tol_inner_iter,
                                                                  tol_outer_iter,
                                                                  tol_backtracking,
                                                                  max_inner_iter,
                                                                  max_total_iterations)
            else:
                if not x:
                    print("pass x as argument when calling solve")
                else:
                    return feasible_init_point_descent_method(self.objective_function,
                                                              x,
                                                              tol_inner_iter,
                                                              tol_backtracking,
                                                              x_ast, 
                                                              p_ast,
                                                              max_inner_iter,
                                                              gf_B,
                                                              Hf_B,
                                                              plot,
                                                              method=method)        
                    
        else:
            if call_method == "primal_dual_feasible_init_point_method":
                print("x_ast as numpy array solution, \n \
                       p_ast as function value in x_ast, \n \
                       gf_B function evaluation of gradient of logarithmic barrier, \n \
                       Hf_B function evaluation of Hessian of logarithmic barrier must be defined")
            else:
                print("x_ast as numpy array solution, \n \
                       p_ast as function value in x_ast, \n \
                       gf_B function evaluation of gradient of objective function, \n \
                       Hf_B function evaluation of Hessian of objective function")            