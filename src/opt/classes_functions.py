from opt.utils_logarithmic_barrier import phi

class ObjectiveFunction():
    def __init__(self, f):
        self.f = f
    def set_x(self, x):
        self.x = x
    def evaluate(self):
        try:
            x = self.x
            self.f_eval = self.f(x)
            return self.f_eval            
        except Exception as e:
            print(e)
            print("first define x before evaluation, call set_x to define it")
class GradientObjectiveFunction():
    def __init__(self, 
                 gf):
        self.gf = gf
    def set_x(self, x):
        self.x = x
    def evaluate(self):
        try:
            x = self.x
            self.gf_eval = self.gf(x)
            return self.gf_eval
        except Exception as e:
            print(e)
            print("first define x before evaluation, call set_x to define it")
class HessianObjectiveFunction():
    def __init__(self, 
                 Hf):
        self.Hf = Hf
    def set_x(self, x):
        self.x = x
    def evaluate(self):
        try:
            x = self.x
            self.Hf_eval = self.Hf(x)
            return self.Hf_eval
        except Exception as e:
            print(e)
            print("first define x before evaluation, call set_x to define it")
class LogarithmicBarrier():
    def __init__(self, 
                 f,
                 constraints_inequalities):
        self.f = f
        self.constraints_inequalities = constraints_inequalities
    def set_x(self, x):
        self.x = x
    def set_t_B(self, t_B):
        self.t_B = t_B
    def evaluate(self):
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
    def __init__(self, 
                 gf,
                 gphi):
        self.gf = gf
        self.gphi = gphi
    def set_x(self, x):
        self.x = x
    def set_t_B(self, t_B):
        self.t_B = t_B
    def evaluate(self):
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
    def __init__(self, 
                 Hf,
                 Hphi):
        self.Hf = Hf
        self.Hphi = Hphi
    def set_x(self, x):
        self.x = x
    def set_t_B(self, t_B):
        self.t_B = t_B
    def evaluate(self):
        try:
            x = self.x
            t_B = self.t_B
            self.Hf_eval = self.Hf(x)
            self.Hlogarithimic_barrier_eval = t_B*self.Hf_eval + self.Hphi(x)
            return self.Hlogarithimic_barrier_eval
        except Exception as e:
            print(e)
            print("first define x and t_B before evaluation, call set_x, set_t_B to define them")
