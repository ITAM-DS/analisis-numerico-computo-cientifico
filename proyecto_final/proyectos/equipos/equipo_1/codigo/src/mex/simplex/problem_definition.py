import numpy as np

from mex.utils.general import gen_var, convert_min, convert
from mex.simplex.simplex_networks import pivots_col, find_pivot_col, pivots_row, pivot, find_pivot_row


def add_cons(matrix):
    """
    Checks if 1 extra constraint can be added to the matrix, this means that there are at least two rows of all
    0 elements. If this condition is not satisfied, our program will not allow the user to add additional constraints.
    
    Args:
    
        matrix (numpy array): matrix to be reviewed.
    
    Returns:
    
        Flag (bool): True or False indicating whether 1+ constraints can be added.
    """
    add = True
    lr = matrix.shape[0]

    for i in range(lr):
        total = sum(matrix[i, :] * matrix[i, :])
        if total == 0:
            if i != (lr - 1):
                break
            else:
                add = False

    return add


def constrain(matrix, eq, memory_prof=False):
    """
    Adds constraints to the problem.
    
    Args:
        matrix (numpy array): matrix defined with :mod:`create_matrix`.
        eq (string): coefficients of constraints expressions. Use **L** for *less than*, **G** for *greater than*,
        **E** for *equal to*.
    
    >>> problem_matrix = create_matrix(2,3)   # 2 variables and 3 constraints
    >>> constrain(problem_matrix,'1,L,4')     # x_1 <= 4
    >>> constrain(problem_matrix,'0,2,L,12')  # 2x_2 <= 12
    >>> constrain(problem_matrix,'3,2,G,18')  # 3x_1 + 2x_2 >= 18
    """

    if 'E' in eq:
        if add_cons(matrix):
            #lc = len(matrix[0, :])
            lr = len(matrix[:, 0])
            #var = lc - lr - 1
            j = 0

            while j < lr:
                row_check = matrix[j,:]
                total = 0
                for i in row_check:
                    total += float(i*i) #i**2
                if total == 0:
                    row = row_check
                    break
                j += 1
                
            eq = convert(eq)
            i = 0
            
            while i<len(eq)-1:
                row[i] = eq[i]
                i += 1
            
            row[-1] = eq[-1]
            #row[var+j] = 1
        
        else:
            print('Cannot add another constraint.')
        
    else:
        if add_cons(matrix):
            lc = len(matrix[0, :])
            lr = len(matrix[:, 0])
            var = lc - lr - 1
            j = 0
            
            while j < lr:
                row_check = matrix[j, :]
                total = 0
                for i in row_check:
                    total += float(i*i) #i**2
                if total == 0:
                    row = row_check
                    break
                j += 1
                
            eq = convert(eq)
            i = 0
            
            while i < len(eq)-1:
                row[i] = eq[i]
                i += 1
            
            row[-1] = eq[-1]
            row[var+j] = 1
            
        else:
            print('Cannot add another constraint.')
    if memory_prof:
        return matrix


def add_obj(matrix):
    """
    Verifies if the objective function can be added.
    
    Args:
    
        matrix (numpy array): matrix to be reviewed.
    
    Returns:
    
        Flag (bool): True or False indicating whether objective function can be added.
    """

    add = False
    lr = matrix.shape[0]

    for i in range(lr):
        total = sum(matrix[i, :] * matrix[i, :])
        if total == 0:
            if i != (lr - 1):
                break
            else:
                add = True

    return add


def obj(matrix,eq,memory_prof=False):
    """
    Adds the objective function to the problem matrix.
    
    .. note::
        Objective function must be added **after** constraints have been input.
    
    Args:
    
        matrix (numpy array): matrix defined with :mod:`create_matrix`.
        
        eq (string): coefficients of objective function.
    
    >>> problem_matrix = create_matrix(2,3)   # 2 variables and 3 constraints
    >>> constrain(problem_matrix,'1,L,4')     # x_1 <= 4
    >>> constrain(problem_matrix,'0,2,L,12')  # 2x_2 <= 12
    >>> constrain(problem_matrix,'4,2,G,18')  # 4x_1 + 2x_2 >= 18
    >>> obj(problem_matrix,'3,5,0')           # 3x_1 + 5x_2
    """
    
    if add_obj(matrix):
        eq = [float(i) for i in eq.split(',')]
        lr = matrix.shape[0]  # len(matrix[:,0])
        row = matrix[lr-1, :]
        i = 0
        while i<len(eq)-1:
            row[i] = eq[i]*-1
            i += 1
        row[-2] = 1
        row[-1] = eq[-1]
    else:
        print('You must finish adding constraints before the objective function can be added.')

    if memory_prof:
        return matrix


def maxz(matrix, aux=True):
    """
    Creates maximization function. Determines if 1 extra pivot is required, locates the pivot element,
    pivots about it and continues the process until all negative elements have been removed from
    the last column and row.
    
    Args:
    
        matrix (numpy array): problem matrix with constraints and objective function added.
    
    Returns:
    
        *(dict)* A dictionary with Max and variables.
        
    >>> problem_matrix = create_matrix(2,3)   # 2 variables and 3 constraints
    >>> constrain(problem_matrix,'1,L,4')     # x_1 <= 4
    >>> constrain(problem_matrix,'0,2,L,12')  # 2x_2 <= 12
    >>> constrain(problem_matrix,'4,2,G,18')  # 4x_1 + 2x_2 >= 18
    >>> obj(problem_matrix,'3,5,0')           # 3x_1 + 5x_2
    >>> maxz(problem_matrix)
    {'x1': 4.0, 'x2': 6.0, 'max': 42.0}
    """
    
    while pivots_col(matrix):
        tmp_pivot_col = find_pivot_col(matrix)
        matrix = pivot(tmp_pivot_col[0], tmp_pivot_col[1], matrix)
    while pivots_row(matrix):
        tmp_pivot_row = find_pivot_row(matrix)
        matrix = pivot(tmp_pivot_row[0], tmp_pivot_row[1], matrix)
    
    lc = len(matrix[0, :])
    lr = len(matrix[:, 0])
    var = lc - lr - 1
    i = 0
    val = {}
    
    gen_variables = gen_var(lc, lr)
    for i in range(var):
        col = matrix[:, i]
        s = sum(col)
        m = max(col)
        if float(s) == float(m):
            loc = np.where(col == m)[0][0]
            val[gen_variables[i]] = matrix[loc, -1]
        else:
            val[gen_variables[i]] = 0
    val['max'] = matrix[-1, -1]
    
    return val


def minz(matrix, aux=True):
    """
    Creates minimization function. Determines if 1 extra pivot is required, locates the pivot element,
    pivots about it and continues the process until all negative elements have been removed from 
    the last column and row.
    
    Args:
    
        matrix (numpy array): problem matrix with constraints and objective function added.
    
    Returns:
    
        (dict) A dictionary with Min and variables.
        
    >>> problem_matrix = create_matrix(2,4)   # 2 variables and 4 constraints
    >>> constrain(problem_matrix,'1,1,L,6')   # x_1 + x_2 <= 6
    >>> constrain(problem_matrix,'-1,2,L,8')  # -x_1 + 2x_2 <= 8
    >>> constrain(problem_matrix,'1,G,0')     # x_1 >= 0
    >>> constrain(problem_matrix,'0,1,G,0')   # x_2 >= 0
    >>> obj(problem_matrix,'-1,-3,0')         # -x_1 - 3x_2
    >>> minz(problem_matrix)
    {'x1': 1.3333333333333333, 'x2': 4.666666666666667}
    """

    matrix = convert_min(matrix)
    while pivots_col(matrix):
        pivot_col = find_pivot_col(matrix)
        matrix = pivot(pivot_col[0], pivot_col[1], matrix)

    while pivots_row(matrix):
        pivot_row = find_pivot_row(matrix)
        matrix = pivot(pivot_row[0], pivot_row[1], matrix)

    lc = matrix.shape[1]
    lr = matrix.shape[0]
    var = lc - lr - 1
    i = 0
    val = {}
    gen_variables = gen_var(lc, lr)

    for i in range(var):
        col = matrix[:, i]
        s = sum(col)
        m = max(col)
        if float(s) == float(m):
            loc = np.where(col == m)[0][0]
            val[gen_variables[i]] = matrix[loc, -1]
        else:
            val[gen_variables[i]] = 0
    val['min'] = matrix[-1, -1]*-1

    if aux:
        return val
