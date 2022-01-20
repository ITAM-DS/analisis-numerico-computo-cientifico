from opt.utils_logarithmic_barrier import phi

class ObjectiveFunction():
    """
    Class to define objective function of optimization problem.
    """
    def __init__(self, f):
        """
        Constructor for class.
        """
        self.f = f
    def set_x(self, x):
        """
        Define x for function.
        """
        self.x = x
    def evaluate(self):
        """
        Evaluate function once it's arguments are defined.
        """
        try:
            x = self.x
            self.f_eval = self.f(x)
            return self.f_eval            
        except Exception as e:
            print(e)
            print("first define x before evaluation, call set_x to define it")
class GradientObjectiveFunction():
    """
    Class to define gradient of objective function of optimization problem.
    """    
    def __init__(self, 
                 gf):
        """
        Constructor for class.
        """        
        self.gf = gf
    def set_x(self, x):
        """
        Define x for function.
        """    
        self.x = x
    def evaluate(self):
        """
        Evaluate function once it's arguments are defined.
        """        
        try:
            x = self.x
            self.gf_eval = self.gf(x)
            return self.gf_eval
        except Exception as e:
            print(e)
            print("first define x before evaluation, call set_x to define it")
class HessianObjectiveFunction():
    """
    Class to define Hessian of objective function of optimization problem.
    """        
    def __init__(self, 
                 Hf):
        """
        Constructor for class.
        """        
        self.Hf = Hf
    def set_x(self, x):
        """
        Define x for function.
        """        
        self.x = x
    def evaluate(self):
        """
        Evaluate function once it's arguments are defined.
        """        
        try:
            x = self.x
            self.Hf_eval = self.Hf(x)
            return self.Hf_eval
        except Exception as e:
            print(e)
            print("first define x before evaluation, call set_x to define it")
class LogarithmicBarrier():
    """
    Class to define objective function of logarithmic barrier optimization problem.
    """        
    def __init__(self, 
                 f,
                 constraints_inequalities):
        """
        Constructor for class.
        """        
        self.f = f
        self.constraints_inequalities = constraints_inequalities
    def set_x(self, x):
        """
        Define x for function.
        """        
        self.x = x
    def set_t_B(self, t_B):
        """
        Define parameter t_B for function.
        """          
        self.t_B = t_B
    def evaluate(self):
        """
        Evaluate function once it's arguments are defined.
        """        
        try:
            x = self.x
            t_B = self.t_B
            self.f_eval = self.f(x)
            self.logarithmic_barrier_eval = t_B*self.f_eval + phi(x, 
                                                                  self.constraints_inequalities)
            return self.logarithmic_barrier_eval 
        except Exception as e:
            print(e)
            print("first define x and t_B before evaluation, call set_x, set_t_B to define them")
class GradientLogarithmicBarrier():
    """
    Class to define gradient objective function of logarithmic barrier 
    optimization problem.
    """       
    def __init__(self, 
                 gf,
                 gphi):
        """
        Constructor for class.
        """        
        self.gf = gf
        self.gphi = gphi
    def set_x(self, x):
        """
        Define x for function.
        """        
        self.x = x
    def set_t_B(self, t_B):
        """
        Define parameter t_B for function.
        """          
        self.t_B = t_B
    def evaluate(self):
        """
        Evaluate function once it's arguments are defined.
        """        
        try:
            x = self.x
            t_B = self.t_B
            self.gf_eval = self.gf(x)
            self.glogarithimic_barrier_eval = t_B*self.gf_eval + self.gphi(x)
            return self.glogarithimic_barrier_eval
        except Exception as e:
            print(e)
            print("first define x and t_B before evaluation, call set_x, set_t_B to define them")
class HessianLogarithmicBarrier():
    """
    Class to define Hessian objective function of logarithmic barrier 
    optimization problem.
    """     
    def __init__(self, 
                 Hf,
                 Hphi):
        """
        Constructor for class.
        """        
        self.Hf = Hf
        self.Hphi = Hphi
    def set_x(self, x):
        """
        Define x for function.
        """        
        self.x = x
    def set_t_B(self, t_B):
        """
        Define parameter t_B for function.
        """        
        self.t_B = t_B
    def evaluate(self):
        """
        Evaluate function once it's arguments are defined.
        """        
        try:
            x = self.x
            t_B = self.t_B
            self.Hf_eval = self.Hf(x)
            self.Hlogarithimic_barrier_eval = t_B*self.Hf_eval + self.Hphi(x)
            return self.Hlogarithimic_barrier_eval
        except Exception as e:
            print(e)
            print("first define x and t_B before evaluation, call set_x, set_t_B to define them")
