import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.metrics import classification_report,confusion_matrix, r2_score, make_scorer, \
    mean_squared_error, mean_absolute_error,roc_curve,accuracy_score,roc_auc_score,brier_score_loss, \
    precision_score, recall_score,f1_score, log_loss
from scipy.stats import binom, beta, expon, mvn, shapiro, ttest_ind, bernoulli, binom_test, \
    pearsonr
import cvxpy as cp

def woe(data_in, target, variable, bins, binning):
    """
    Cómputo del Weight of Evidence (woe)
    input:
    - data_in(df): dataframe con las variables necesarias para el cálculo
    - target(str): variable target
    - variable(str): variable
    - bins(float): definición de intervalos de corte
    - binning(boolean): indicadora para calcular o no los intervalos de corte
    output:
    """

    df = data_in

    # Selección de variables y eliminar valores faltantes
    df2 = data_in[[target, variable]].rename(columns={target: 'Target', variable: 'Variable'}).dropna()

    # Cálculo de intervalos del tipo: "(a, b]"
    if binning:
        df2['key'] = pd.qcut(df2.Variable, bins, labels=False, duplicates='drop')
    else:
        df2['key'] = df2.Variable

    # Tabla cruzada para observaciones default y no default
    table = pd.crosstab(df2.key, df2.Target, margins= True)
    table = table.drop(['All'], axis=0)
    table = table.rename(columns={1: 'deft', 0: 'nondeft'}).reset_index(drop=False)

    # Agregar frecuencia relativa de default y no default
    table.loc[:, 'fracdeft'] = table.deft/np.sum(table.deft)
    table.loc[:, 'fracnondeft'] = table.nondeft/np.sum(table.nondeft)

    # Cálculo del WOE y del IV
    table.loc[:, 'WOE'] = np.log(table.fracdeft/table.fracnondeft)
    table.loc[:, 'IV'] = (table.fracdeft - table.fracnondeft)*table.WOE

    # Renombrar variables
    table.rename(columns={'WOE': variable}, inplace=True)
    table = table.add_suffix('_WOE')
    table.rename(columns={table.columns[0]: 'key' }, inplace = True)

    # Construcción de dataset WOE
    WOE = table.iloc[:, [0, -2]]
    df = pd.merge(df, df2.key, right_index=True, left_index=True)
    outputWOE = pd.merge(df, WOE, on='key').drop(['key'], axis=1)
    outputIV = pd.DataFrame(data={'name': [variable], 'IV': table.IV_WOE.sum()})

    return outputWOE, outputIV


def validation(fit, outcome, time, continuous=False):
    """
    Evaluación y validación del modelo de regresión logística
    input:
    - fit(array): predicción del modelo de regresión logística
    - outcome(array): variable dependiente original
    - time(array): periodo de tiempo (en trimestres)
    - continuos(boolean):
    output:
    - plot: conjunto de 4 gráficas para la evaluación y desempeño del modelo
    """

    # Configuración del plot: tamaño plot, tamaño de títulos
    plt.rcParams['figure.dpi'] = 300
    plt.rcParams['figure.figsize'] = (16, 9)
    plt.rcParams.update({'font.size': 16})

    # Selección en base a la clasificación en base al modelo
    fitP = pd.DataFrame(data=fit)

    # Selección en base a la clasificación en base a la variable dependiente
    outcomeP = pd.DataFrame(data=outcome)

    # Selección de tiempos (trimestres)
    timeP = pd.DataFrame(data=time)

    # Verificar que las observaciones a evaluar sean del correcto tipo
    if isinstance(fit, pd.Series):
        fit = fit.values
    if isinstance(outcome, pd.Series):
        outcome = outcome.values
    if isinstance(time, pd.Series):
        time = time.values

    # Juntar las observaciones
    data_in = pd.concat([fitP, outcomeP, timeP], axis=1)

    # Cambiar nombre de columnas
    data_in.columns = ['fit', 'outcome', 'time']

    # Media por grupo (tiempo)
    means = data_in.groupby('time')[['fit', 'outcome']].mean().reset_index(drop=False)

    # Variable auxiliar de la variable dependiente
    data_in['outcomeD'] = data_in.loc[:, 'outcome']

    # Clasificación en base a la media del grupo
    if continuous:
        data_in.loc[data_in['outcome'] >= data_in.outcome.mean(), 'outcomeD'] = 1
        data_in.loc[data_in['outcome'] < data_in.outcome.mean(), 'outcomeD'] = 0
    outcomeD = data_in.loc[:, 'outcomeD'].values

    # Inicialización de métricas de desempeño del modelo
    lr_log_loss = np.nan
    roc_auc = np.nan
    brier = np.nan
    binom_p = np.nan
    Jeffreys_p = np.nan

    max_outcome_fit = np.maximum(max(outcome), max(fit))
    min_outcome_fit = np.minimum(min(outcome), min(fit))

    # Cálculo de métricas de desempaño
    if min_outcome_fit >= 0 and max_outcome_fit <= 1:
        lr_log_loss = log_loss(outcomeD, fit).round(4)
        roc_auc = roc_auc_score(outcomeD, fit).round(4)
        binom_p = binom_test(sum(outcomeD), n=len(outcomeD), p=np.mean(fit), alternative='greater').round(decimals=4)
        Jeffreys_p = beta.cdf(np.mean(fit), sum(outcomeD) + 0.5, len(outcomeD) - sum(outcomeD) + 0.5).round(decimals=4)

    # Coeficiente de correlación lineal de Pearson
    corr, _ = pearsonr(fit, outcome)
    r2_OLS = corr ** 2

    # Tabla de métricas de desempeño
    the_table = [['Counts', len(outcome)],
                 ['Mean outcome', (sum(outcome) / len(outcome)).round(4)],
                 ['Mean fit', np.mean(fit).round(4)],
                 ['AUC ', roc_auc],
                 ['R-squared (OLS)', round(r2_OLS, 4)],
                 ['R-squared', r2_score(outcome, fit).round(decimals=4)],
                 ['RMSE/ SQR(Brier score)', round(np.sqrt(((outcome - fit).dot(outcome - fit)) / len(outcome)), 4)],
                 ['Log loss', lr_log_loss],
                 ['Binomial p-value', binom_p],
                 ['Jeffreys p-value', Jeffreys_p]]
    the_table = pd.DataFrame(data=the_table)
    the_table.columns = ['Metric', 'Value']

    # Graficar serie de tiempo con la predicción del modelo comparando con la variable dependiente real
    plt.subplot(222)
    plt.title('Time-Series Real-Fit')
    plt.plot(means['time'], means['outcome'])
    plt.plot(means['time'], means['fit'], color='red', ls='dashed')
    plt.xlabel('Time')
    plt.ylabel('Mean')
    plt.tick_params(axis='both')
    plt.legend(('Outcome', 'Fit'), loc='best')

    data_in['cat'] = pd.qcut(data_in.fit, 10, labels=False, duplicates='drop')
    real_fit = data_in.groupby('cat')[['fit', 'outcome']].mean()
    mpv = real_fit.fit.values
    fop = real_fit.outcome.values

    maximum = np.maximum(max(fop), max(mpv))
    maximum = np.ceil(maximum * 100) / 100
    minimum = np.minimum(min(fop), min(mpv))
    minimum = np.floor(minimum * 100) / 100

    # Relación de media de probalidad estimada y real
    plt.subplot(223)
    plt.title('Calibration Curve')
    plt.plot(mpv, fop, marker='.', linestyle='')
    plt.plot([minimum, maximum], [minimum, maximum], linestyle='--', color='gray')
    plt.xlim((minimum, maximum))
    plt.ylim((minimum, maximum))
    plt.xlabel('Mean fit')
    plt.ylabel('Mean outcome')
    plt.tick_params(axis='both')
    plt.show()


def corr_plot(data, variables):
    """
    Generar mapa de calor de correlación entre las variables seleccionadas
    :param data: pandas dataframe
    :param variables: list de strings
    :return: corrplot
    """
    corr = data[variables].corr()

    # Generate a mask for the upper triangle
    mask = np.triu(np.ones_like(corr, dtype=bool))

    # Set up the matplotlib figure
    f, ax = plt.subplots(figsize=(6, 5))

    # Generate a custom diverging colormap
    cmap = sns.diverging_palette(230, 20, as_cmap=True)

    # Draw the heatmap with the mask and correct aspect ratio
    sns.heatmap(corr, mask=mask, cmap=cmap, vmax=.3, center=0,
                square=True, linewidths=.5, cbar_kws={"shrink": .5})

def potencia(d, cor=True, MAX=150):
    """
    Método de la potencia para encontrar eigenvector de máximo módulo matrices cuadradas (simétricas) o no
    - input:
    - d(dataframe): matriz
    - cor(boolean): indica si la matriz input es de covarianza
    - MAX(int): máximas evaluaciones del método de la potencia
    - output(array):
    - eil(array): evolución hacia el eigenvalor de máximo módulo
    - v(vector): eigenvector asociado a eigenvalor máximo modulo asociado
    Pseudoalgoritmo obtenido de la nota 2.3
    """

    # Definimos los parámetros de entrada y las dimensiones de nuestro data set
    if not cor:
        X = np.cov(d)
    else:
        X = d
    n = X.shape[0]

    # Condiciones iniciales
    np.random.seed(2020)
    q_k = np.random.rand(n)
    lambda_k_iter = np.zeros(MAX)

    # Método de la potencia
    for k in range(MAX):
        # Paso de la potencia
        z_k = X @ q_k

        # Normalizamos el vector
        q_k = z_k / np.linalg.norm(z_k)

        # Calculamos eigenvalor de máximo módulo
        lambda_k = q_k.T @ X @ q_k
        lambda_k_iter[k] = lambda_k

    return lambda_k_iter, q_k


def deflacion(d, MAX=150):
    """
    Método de la potencia para encontrar eigenvector asociado al segundo eigenvalor de
    máximo módulo para matrices simétricas
    - input:
    - d(dataframe): matriz no cuadrada
    - MAX(int): máximas evaluaciones del método de la potencia
    - output(array):
    - v(vector): eigenvector asociado a eigenvalor máximo modulo asociado
    Pseudoalgoritmo obtenido de la nota 2.3
    """

    # Eliminamos el eigenvalor de máximo módulo
    eig_1, eiv_1 = potencia(d, True)

    # Definimos los parámetros de entrada y las dimensiones de nuestro data set
    #X = d @ d.T
    X = d

    # Calculamos matriz actualizada sin el eigenvalor de máximo módulo
    X = X - eig_1[-1] * np.outer(eiv_1, eiv_1)

    # Calculamos eigenvector de máximo módulo
    eig_2, eiv_2 = potencia(X, True)

    return eig_2, eiv_2


def logistic_model(data, variables, default = "default_time"):
    """
    Obtención del modelo de regresión logística resolviendo un problema de optimización (minimización) convexo
    :param data(dataframe): dataframe con variables a analizar
    :param variables(list): variables a incluir en el modelo de regresión logística, debe incluir variable dependiente
                      e independientes
    :param default(str): variable dependiente
    :return beta(array): vector de parámetros obtenidos del problema de optimización convexa
    """

    # Selección de features
    data = data[variables]

    # Selección de variable dependiente (para este proyecto siempre es default_time
    classes = data[default].copy()

    # Quitar variable dependiente al dataset
    data = data.drop([default], axis=1)
    m, n = data.shape
    print(m)

    # Agregamos columna de 1's para el intercepto (beta_0)
    data = np.column_stack((np.ones((m, 1)), data))

    # Número de variables (se agrega beta_0 o intercepto)
    n = n + 1

    # Variable de optimización
    beta = cp.Variable(n)

    # Planteamos y resolvemos problema de optimización convexo
    fo_cvxpy = 2 * cp.sum(cp.logistic(data @ beta) - cp.multiply(classes, data @ beta))
    obj = cp.Minimize(fo_cvxpy)
    prob = cp.Problem(obj)

    print('Evaluación de valor óptimo al resolver problema de optimización', prob.solve())

    return beta.value, data

def estim_prob(data, variables, default = 'default_time'):
    """
    Obtención de estimación de probabilidades utilizando un modelo de regresión logístico y metodología de
    optimización convexa
    :param data: dataframe con variables a analizar
    :param variables: variables a incluir en el modelo de regresión logística, debe incluir variable dependiente
                      e independientes
    :param default: variable dependiente
    :return fitted_values: estimación de probabilidadees
    """

    # Obtención de parámetros estimados
    model, data = logistic_model(data, variables)

    # Evaluación lineal del modelo
    linear_value = -data.dot(model)

    # Estimación de probabilidad
    fitted_values = 1 / (1 + np.exp(linear_value))

    return fitted_values, model

def grafica_medias(fit, outcome , time, continuous=False):
    """
    Grafica los valores  promedio de las PDś en el tiempo contra las del modelo
    :param fit: vector de observaciones estimadas
    :param outcome: vector de observaciones reales
    :param time: vector de tiempos en trimestres
    :param continuous: indicadora de caso continuio
    :return: plot
    """
    # Juntar la información en un DataFrame
    fitP=pd.DataFrame(data=fit)
    outcomeP=pd.DataFrame(data=outcome)
    timeP=pd.DataFrame(data=time)
    data_in = pd.concat([fitP, outcomeP, timeP], axis=1)
    data_in.columns = ['fit', 'outcome', 'time']
    means = data_in.groupby('time')[['fit', 'outcome']].mean().reset_index(drop=False)

    # Plot
    plt.title('Comparación de medias de las probabilidades de incumplimiento en el tiempo')
    plt.plot(means['time'],means['outcome'])
    plt.plot(means['time'],means['fit'], color='red', ls='dashed')
    plt.xlabel('Tiempos', fontsize=15)
    plt.ylabel('Media', fontsize=15)
    plt.tick_params(axis='both', labelsize=13)
    plt.legend(('Reales','Ajustadas'), loc='best', fontsize=15)


def grafica_ajuste(fit, outcome, time, continuous=False):
    """
    Grafica para revisar la calidad del ajuste
    :param fit:
    :param outcome:
    :param time:
    :param continuous:
    :return:
    """

    # Juntar la información en un DataFrame
    fitP = pd.DataFrame(data=fit)
    outcomeP = pd.DataFrame(data=outcome)
    timeP = pd.DataFrame(data=time)
    data_in = pd.concat([fitP, outcomeP, timeP], axis=1)
    data_in.columns = ['fit', 'outcome', 'time']
    data_in['cat'] = pd.qcut(data_in.fit, 10, labels=False, duplicates='drop')
    real_fit = data_in.groupby('cat')[['fit', 'outcome']].mean()
    mpv = real_fit.fit.values
    fop = real_fit.outcome.values

    # Obtener escalas de los ejes (maximo y minimo a mostrar)
    maximum = np.maximum(max(fop), max(mpv))
    maximum = np.ceil(maximum * 100) / 100
    minimum = np.minimum(min(fop), min(mpv))
    minimum = np.floor(minimum * 100) / 100

    # Graficar
    plt.title('Revisión de calibración')
    plt.plot(mpv, fop, marker='.', linestyle='', markersize=20)
    plt.plot([minimum, maximum], [minimum, maximum], linestyle='--', color='gray')
    plt.xlim((minimum, maximum))
    plt.ylim((minimum, maximum))
    plt.xlabel('Media de las pdś ajustadas', fontsize=15)
    plt.ylabel('Media da las pds reales', fontsize=15)
    plt.tick_params(axis='both', labelsize=13)
    plt.show()
