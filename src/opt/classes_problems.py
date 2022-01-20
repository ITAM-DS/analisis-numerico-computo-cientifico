import numpy as np

from opt.classes_functions import ObjectiveFunction, LogarithmicBarrier
from opt.logarithmic_barrier.logarithmic_barrier_methods import primal_dual_feasible_init_point_method
from opt.descent_methods import feasible_init_point_descent_method

class ProblemFeasibleInitPoint():
    def __init__(self, 
                 type_problem,
                 f,
                 constraints_ineq=None,
                 mu=None,
                 constraints_eq=None):
        if type_problem == "CICO" or type_problem == "CIECO":
            self.logarithmic_barrier = True
            if not mu:
                print("falta definir mu")
            else:
                self.mu = mu
                if not constraints_ineq:
                    print("falta definir restricciones de desigualdad")
                else: #defined constraints_ineq
                    if type_problem == "CIECO" and not constraints_eq:
                        print("falta definir restricciones de igualdad")
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
                    print("tipos de problemas a resolver: UCO, CICO, CECO, CIECO, elegir uno de ellos")
                else: #CECO
                    if not constraints_eq:
                        print("falta definir restricciones de igualdad")
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