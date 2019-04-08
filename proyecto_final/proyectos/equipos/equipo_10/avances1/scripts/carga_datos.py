
#%% carga
import numpy as np
import pandas as pd
from yahoofinancials import YahooFinancials as YF
from ctypes import cdll
from pathlib import Path
import os


def descargar_datos(stocks, 
                    inicio = '2008-01-01', 
                    fin = '2019-01-01',
                    intervalo = 'daily'):
    # descarga datos de acciones específicas de Yahoo finances
    # inicio y fin determinan el intervalo
    # intervalo puede ser ‘daily’, ‘weekly’, or ‘monthly’
    intervalo = 'daily'   #can be either . 
    acciones = YF(stocks)
    hr = (acciones.get_historical_price_data(inicio, fin, intervalo))
    h = pd.DataFrame(hr)
    h = h.T
    return h

def extraer_datos_cia(comp,pri): 
    # función interna para jalar los datos de acciones de cada compañía
    # usada por la función extraer_datos
    e = pd.DataFrame(pri)
    e = e.loc[:,('formatted_date','open', 'close', 'high', 'low')]
    e['cia'] = comp
    return e

def extraer_datos(df):
    # toma los datos de Yahoo finances y genera un dataframe adecuado
    for i in range(df.shape[0]):
        e = extraer_datos_cia(df.index[i],df.prices[i])
        datos = pd.concat([datos, e]) if i != 0 else e
    return datos


    
#%% carga de datos
tech_stocks = ['AAPL', 'MSFT', 'INTC', 'GOOG', 'GOOGL', 'FB', 'INTC']
bank_stocks = ['WFC', 'BAC', 'C']

# yahoo_financials_tech = YF(tech_stocks)
historia = descargar_datos(tech_stocks)

datos = extraer_datos(historia)

#%% metodos BS

matriz = np.array(datos.head().values[:,1:5])

#%% prueba con c++

# clases para usar la función de C++
# los comandos para compilar (en caso de cambios) son
# g++ -c -fPIC blackscholes.cpp -o bs.o
# g++ -shared -Wl,-soname,bs.so -o bs.so  bs.o

path = Path(__file__).parent.absolute()
os.chdir(path)

lib = cdll.LoadLibrary('./bs.so')
class BlackScholes(object):
    def __init__(self):
        self.obj = lib.BS_new()

    def bar(self):
        lib.BS_bar(self.obj)
        
bs = BlackScholes()
bs.bar() #and you will see "Hello" on the screen
