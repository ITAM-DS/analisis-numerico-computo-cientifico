import numpy as np
from simplex_networks_c import create_matrix
from problem_definition_c import constrain, obj, maxz

class Maximizer():
    """Maximize the objective function"""
    
    def __init__(self, n_variables, n_constraints):
        self.n_variables = n_variables
        self.n_constraints = n_constraints
        self.matrix = create_matrix(self.n_variables, self.n_constraints)
        self.max = None
        self.coeff = None

    def add_constraint(self, constraint):
        constrain(self.matrix, constraint)

    def add_objective(self, objective):
        obj(self.matrix, objective)

    def solve(self):
        solve = maxz(self.matrix)
        self.max = solve['max']
        self.coeff = np.array(list(solve.values()))[:-1]

    def get_max(self):
        return self.max

    def get_coeff(self):
        return self.coeff
