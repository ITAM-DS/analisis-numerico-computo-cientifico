import numpy as np

def err_relativo(aprox, obj):
    return np.abs(aprox-obj)/np.abs(obj)