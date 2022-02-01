import numpy as np
from IPython.display import display
import pandas as pd
import matplotlib.pyplot as plt

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
def plot_error_of_optimum_value(err):
    """
    Auxiliary function for plotting inner iterations error.
    """
    plt.yscale('log') #logarithmic scale for y axis
    plt.plot(np.arange(err.size),err,'.-')
    plt.title("Error of optimum value between $f_o(x^{(k)})$ and $p^*$")
    plt.ylabel("log error",size=12)
    plt.xlabel("Inner iterations",size=12)
    plt.grid()
    plt.show()
def plot_sequence_of_approximations(x_iterations,
                                   title="Descent method sequence of approximations"):
    """
    Auxiliar function for plotting sequence of approximations.
    """
    plt.plot(x_iterations[0,:],
             x_iterations[1,:],"-*")
    plt.ylabel("$x_2$")
    plt.xlabel("$x_1$")
    plt.annotate("$x^{(0)}$",(x_iterations[0,0],
                              x_iterations[1,0]),fontsize=12)
    plt.title(title)
    if title == "Primal-dual BL method sequence of approximations":
        plt.legend(["Central path"], bbox_to_anchor=(1,1))
    plt.grid()
    plt.show()