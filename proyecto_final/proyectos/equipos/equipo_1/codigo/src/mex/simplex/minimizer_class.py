import numpy as np
from mex.simplex.simplex_networks import create_matrix
from mex.simplex.problem_definition import constrain, obj, minz
from mex.utils.general import generates_matrix, generate_tableau


class Minimizer():
    """
    Minimize the objective function

    Args:

        A (matrix):

        b (vector):

        c (vector):

    >>> A_min = [[1, 1], [-1, 2]]
    >>> b_min = [[6], [8]]
    >>> c_min = [[-1], [-3]]
    >>>
    >>> minim = Minimizer(A_min_obj, b_min_obj, c_min_obj)
    >>> minim.solve()
    >>> min_approx = minim.get_min()
    >>> coeff_approx = minim.get_coeff()
    """
    def __init__(self, A, b, c):
        self.A_matrix = A
        self.b_vector = b
        self.c_vector = c
        self.matrix = generates_matrix(A, b, [-1*x for x in c])
        self.min = None
        self.coeff = None

    def add_constraints(self, lowerbounds, upperbounds):
        """
        Add constraints to current matrix.

        Args:
              lowerbounds (vector): lower bounds of the problem.

              upperbounds (vector): upper bounds of the problem.
        """
        self.matrix = generate_tableau(self.A_matrix, self.b_vector, lowerbounds, upperbounds, self.c_vector, compr=False)

    def solve(self):
        """
        Solve the minimization problem.
        """
        solve = minz(self.matrix)
        self.min = solve['min']
        self.coeff = np.array(list(solve.values()))[:-1]

    def get_min(self):
        """
        Obtain the approximated minimum value.

        Returns:
            min (value): Minimum value of the problem
        """
        return self.min

    def get_coeff(self):
        """
        Obtain the approximated coefficients per variable

        Returns:
            coeff (dictionary): Dictionary of the approximated coefficients.
        """
        return self.coeff
