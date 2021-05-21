import time
import optuna
from .aco_tsp_oo import colony, colony_multiw
from multiprocessing import cpu_count

def load_params(file):
    """Carga los mejores parámetros de un estudio previo.

    Args:
        file (db): Base de datos con el estudio previo, correspondiente 
        a best_hiper_params. 

    Returns:
        [lst]: Lista con los mejores hiperparámetros encontrados
    """
    sq_path = 'sqlite:///' + file
    study = optuna.load_study(study_name='optimize_aco', storage=sq_path)
    return study.best_trial.params

def optim_h_params(G, init_node, trials, save=False):
    """Genera estudio de optimización para buscar los mejores hiper-parámetros del algoritmo.

    Args:
        G (networkx graph): Grafo con relaciones asociadas entre nodos.
        init_node (int): Nodo inicial del recorrido.
        trials (int): Numero de intentos para hacer el muestreo. 
        save (bool, optional): Se especifica si se quiere guardar el estudio en disco. Default es False.

    Returns:
        [dict]: Diccionario con la información del estudio de optimización
    """
    objective = Objective_mp(G, init_node)
    if save:
        study = optuna.create_study(study_name='optimize_aco',
                                    direction="minimize", 
                                    storage='sqlite:///best_hiper_params.db', 
                                    load_if_exists=True)
        
    else:
        study = optuna.create_study(study_name='optimize_aco', direction="minimize")

    study.optimize(objective, n_trials=trials)

    if save:
        print(f'Hyper-parameters saved in ./best_hiper_params.db')

    return study.best_trial

def optim_h_params_mp(G, init_node, trials, save=False):
    """Genera estudio de optimización para buscar los mejores hiper-parámetros del algoritmo.

    Args:
        G (networkx graph): Grafo con relaciones asociadas entre nodos.
        init_node (int): Nodo inicial del recorrido.
        trials (int): Numero de intentos para hacer el muestreo. 
        save (bool, optional): Se especifica si se quiere guardar el estudio en disco. Default es False.

    Returns:
        [dict]: Diccionario con la información del estudio de optimización
    """
    objective = Objective(G, init_node)
    if save:
        study = optuna.create_study(study_name='optimize_aco',
                                    direction="minimize", 
                                    storage='sqlite:///best_hiper_params.db', 
                                    load_if_exists=True)
        
    else:
        study = optuna.create_study(study_name='optimize_aco', direction="minimize")

    study.optimize(objective, n_trials=trials)

    if save:
        print(f'Hyper-parameters saved in ./best_hiper_params.db')

    return study.best_trial

def sample_params(trial):
    """Define el modo en que se va a hacer el meustro de los hiper-parametros del algoritmo
    en optuna. No está disponible para los usuarios.

    Args:
        trial (optuna trial): Ninguno
    """
    return{
        'n_ants' : trial.suggest_int('n_ants', 2, 2048, log=True),
        'max_iter' : trial.suggest_categorical('max_iter', [1, 10, 100]),
        'rho' : trial.suggest_uniform('rho', 0.0, 1.0),
        'alpha' : trial.suggest_int('alpha', 0, 5),
        'beta' : trial.suggest_int('beta', 1, 5)
    }

class Objective(object):
    """Clase para definir la función objetivo a optimizar en la búsqueda de los mejores
        hiper-parámetros del algoritmo. Minimiza tiempo + (distancia)^2.

    Args:
        G (networkx graph): Grafo con relaciones asociadas entre nodos.
        init_node (int): Nodo inicial del recorrido.
    """
    def __init__(self, G, init_node):
        self.G = G
        self.init_node = init_node

    def __call__(self, trial):
        aco_params = sample_params(trial)
        colony_ = colony(self.G, self.init_node, **aco_params)
        
        # time algorithm
        start = time.time()
        colony_.solve_tsp()
        end = time.time() 
        # total time in minutes
        total_time = (end - start) / 60
        obj = total_time + (colony_.best_dist)**2
        
        return obj


class Objective_mp(object):
    """Clase para definir la función objetivo a optimizar en la búsqueda de los mejores
        hiper-parámetros del algoritmo. Minimiza tiempo + (distancia)^2.

    Args:
        G (networkx graph): Grafo con relaciones asociadas entre nodos.
        init_node (int): Nodo inicial del recorrido.
    """
    def __init__(self, G, init_node):
        self.G = G
        self.init_node = init_node
        self.n_workers = cpu_count()

    def __call__(self, trial):
        aco_params = sample_params(trial)
        colony_ = colony_multiw(self.G, self.init_node, self.n_workers, **aco_params)
        
        # time algorithm
        start = time.time()
        colony_.solve_tsp()
        end = time.time() 
        # total time in minutes
        total_time = (end - start) / 60
        obj = total_time + (colony_.best_dist)**2
        
        return obj