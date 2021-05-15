import numpy as np
from simplex_networks_c import create_matrix
from problem_definition_c import constrain, obj, minz

class Minimizer():
    """Minimize the objective function"""
    
    def __init__(self, n_variables, n_constraints):
        self.n_variables = n_variables
        self.n_constraints = n_constraints
        self.matrix = create_matrix(self.n_variables, self.n_constraints)
        self.min = None
        self.coeff = None

    def add_constraint(self, constraint):
        constrain(self.matrix, constraint)

    def add_objective(self, objective):
        obj(self.matrix, objective)

    def solve(self):
        solve = minz(self.matrix)
        self.min = solve['min']
        self.coeff = np.array(list(solve.values()))[:-1]

    def get_min(self):
        return self.min

    def get_coeff(self):
        return self.coeff
