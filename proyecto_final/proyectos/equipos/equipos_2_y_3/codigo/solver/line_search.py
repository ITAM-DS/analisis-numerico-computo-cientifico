from solver.utils import norm_residual

def line_search_by_backtracking(f,dir_desc,x,
                                der_direct, alpha=.15, beta=.5):
    '''
    Busqueda de linea que disminuye suficientemente f restringida a un rayo en
    la dirección dir_desc.
    Args:
        alpha (float): parametro en busqueda de linea con backtracking, tipicamente .15
        beta (float): parametro en busqueda de linea con backtracking, tipicamente .5
        f (lambda expression): definicion de funcion f.
        dir_desc (array): direccion de descenso.
        x (array): array de cupy que contiene valores donde se realizara la busqueda de linea
        der_direct (float): derivada direccional de f.
    Returns:
        t (float): numero positivo para el tamano de pasos a lo largo de dir_desc que
                   disminuye suficientemente f.
    '''
    t=1
    if alpha > 1/2:
        print('alpha menor o igual que 1/2')
        t=-1
    if beta>1:
        print('beta debe ser menor a 1')
        t=-1;
    if t!=-1:
        eval1 = f(x+t*dir_desc)
        eval2 = f(x) + alpha*t*der_direct
        while eval1 > eval2:
            t=beta*t
            eval1=f(x+t*dir_desc)
            eval2=f(x)+alpha*t*der_direct
    else:
        t=-1
    return t

def line_search_for_residual_by_backtracking(r_primal, r_dual,dir_desc_primal,dir_desc_dual,x, nu,
                                             norm_residual_eval,
                                             alpha=.15, beta=.5):
    '''
    Busqueda de linea que disminuye suficientemente el residual para el metodo
    de punto inicial inviable de Newton restringido a un rayo en la direccion dir_desc.
    Args:
        r_primal (fun): definicion de residual primal como funcion definida o expresion lambda.
        r_dual (fun): definicion de residual dual como funcion definida o expresion lambda.
        dir_desc_primal (array): direccion de desceso para variable primal.
        dir_desc_dual (array): direccion de descenso para variable dual.
        x (array): array de cupy que contiene valores donde se realizara la busqueda de linea.
        nu (array): array de cupy que contiene valores donde se realizara la busqueda de linea.
        norm_residual_eval (float): norma de residuos que tiene evaluaciones r_primal y 
        r_dual en x y nu
        alpha (float): parametro de busqueda de linea con backtracking, tipicamente .15
        beta (float): parametro de busqueda de linea con backtracking, tipicamente .5

    Returns:
        t (float): numero positivo para el tamano de pasos a lo largo de dir_desc que 
        disminuye suficientemente f.
    '''
    t=1
    if alpha > 1/2:
        print('alpha debe ser menor o igual que 1/2')
        t=-1
    if beta>1:
        print('beta debe ser menor que uno 1')
        t=-1;
    if t!=-1:
        feas_primal = r_primal(x + t*dir_desc_primal)
        feas_dual = r_dual(nu + t*dir_desc_dual )
        eval1 = norm_residual(feas_primal, feas_dual)
        eval2 = (1-alpha*t)*norm_residual_eval
        while eval1 > eval2:
            t=beta*t
            feas_primal = r_primal(x + t*dir_desc_primal)
            feas_dual = r_dual(nu + t*dir_desc_dual )
            eval1 = norm_residual(feas_primal, feas_dual)
            eval2 = (1-alpha*t)*norm_residual_eval
    return t
