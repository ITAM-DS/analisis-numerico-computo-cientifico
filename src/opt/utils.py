import numpy as np
from IPython.display import display
import pandas as pd

def compute_error(x_obj,x_approx):
    """
    Relative or absolute error between x_obj and x_approx.
    """
    if np.linalg.norm(x_obj) > np.nextafter(0,1):
        Err=np.linalg.norm(x_obj-x_approx)/np.linalg.norm(x_obj)
    else:
        Err=np.linalg.norm(x_obj-x_approx)
    return Err
def print_iterations(data, columns):
    """
    Auxiliary function to print table with list of named columns
    and values in data dictionary.
    """
    pd.set_option('display.float_format', lambda x: "%.2e" % x)
    df = pd.DataFrame.from_dict(data, orient='index',
                                 columns=columns)
    display(df)
