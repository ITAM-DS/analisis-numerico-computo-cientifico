import numpy as np
from mex.simplex.simplex_networks import create_matrix
from mex.simplex.problem_definition import constrain, obj, maxz
from mex.utils.general import generates_matrix, generate_tableau


class Maximizer():
    """
    Maximize the objective function

    Args:

        A (matrix):

        b (vector):

        c (vector):

    >>> A_max = [[1, 0], [0, 2], [3, 2]]
    >>> b_max = [[4], [12], [18]]
    >>> c_max = [[-3], [-5]]
    >>>
    >>> maxim = Maximizer(A_max, b_max, c_max)
    >>> maxim.solve()
    >>> max_approx = maxim.get_max()
    >>> coeff_approx = maxim.get_coeff()
    """
    def __init__(self, A, b, c):
        self.A_matrix = A
        self.b_vector = b
        self.c_vector = c
        self.matrix = generates_matrix(A, b, c)
        self.max = None
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
        Solve the maximization problem.
        """
        solve = maxz(self.matrix)
        self.max = solve['max']
        self.coeff = np.array(list(solve.values()))[:-1]

    def get_max(self):
        """
        Obtain the approximated maximum value.

        Returns:
            max (value): Maximum value of the problem
        """
        return self.max

    def get_coeff(self):
        """
        Obtain the approximated coefficients per variable

        Returns:
            coeff (dictionary): Dictionary of the approximated coefficients.
        """
        return self.coeff
