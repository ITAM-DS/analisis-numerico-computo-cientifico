import pandas as pd
import pandas_datareader.data as wb
import numpy as np
import matplotlib.pyplot as plt
import scipy.optimize as optimize
import seaborn as sns

portafolio=['AAPL','CSCO','IBM','AMZN','DIS']
data = pd.DataFrame()
for t in portafolio:
    data[t]=wb.DataReader(t,'yahoo','2018-1-1')['Adj Close']
rendimientos =(data.pct_change())

def portafolio_stats(pesos, rendimientos):
    port_rendimientos=np.sum(pesos*rendimientos.mean())*252
    port_riesgos=np.sqrt(np.dot(pesos.T,np.dot(rendimientos.cov()*252,pesos)))
    sharpe = port_rendimientos/port_riesgos
    return {'Rendimiento':port_rendimientos, 'Volatilidad':port_riesgos, 'Sharpe':sharpe}

def sum_pesos(pesos):
    return pesos.sum()-1

def rend_esperado(pesos,E):
    return portafolio_stats(pesos,rendimientos)['Rendimiento']-E

def minimiza_sharpe(pesos, rendimientos):
    return -portafolio_stats(pesos, rendimientos)['Sharpe']

def minimiza_riesgo(pesos):
    return(portafolio_stats(pesos,rendimientos)['Volatilidad'])
  
port_rendimientos=[]
port_riesgos =[]

for i in range(8_000):
    num_acciones=len(portafolio)
    pesos = np.random.random(num_acciones)
    pesos /= np.sum(pesos)
    
    port_rendimientos.append(np.sum(pesos*rendimientos.mean())*252)
    port_riesgos.append(np.sqrt(np.dot(pesos.T,np.dot(rendimientos.cov()*252,pesos))))
    
port_rendimientos=np.array(port_rendimientos)
port_riesgos=np.array(port_riesgos)
sharpe =port_rendimientos/port_riesgos


plt.figure(figsize=(12,6))
plt.scatter(port_riesgos, port_rendimientos,c=(sharpe), s=20)
plt.colorbar(label='Sharpe Ratio')
plt.xlabel('Riesgo')
plt.ylabel('Rendimientos del portafolio')
plt.show()

#Punto de partida del % de cada activo
pesos_iniciales = num_acciones * [1/num_acciones,]

#rango de valor que puede tomar el peso de cada actuvo y restricciones
bounds=((0.0,1),)*(num_acciones)
constraints=[{"type":"eq","fun":sum_pesos}]

optimal_sharpe = optimize.minimize(minimiza_sharpe, pesos_iniciales, method='SLSQP', args=(rendimientos,),bounds=bounds,constraints=constraints)
optimal_sharpe_pesos =optimal_sharpe['x'].round(3)
optimal_stats=portafolio_stats(optimal_sharpe_pesos,rendimientos)

frontera_y=np.linspace(0.05,0.3,100)
frontera_x = []

for e in frontera_y:
    cons = ({'type':'eq', 'fun':sum_pesos},
           {'type':'eq', 'fun': lambda w:rend_esperado(w,e)})
    
    resultado = optimize.minimize(minimiza_riesgo,pesos_iniciales,method='SLSQP', bounds=bounds, constraints=cons)
    #optimize.minimize(minimiza_sharpe, pesos_iniciales, method='SLSQP', args=(rendimientos,),bounds=bounds,constraints=constraints)
    frontera_x.append(resultado['fun'])

plt.figure(figsize=(12,8))
plt.scatter(port_riesgos, port_rendimientos,c=(sharpe), cmap='viridis')
plt.colorbar(label='Sharpe Ratio')
plt.xlabel('Riesgos')
plt.ylabel('Rendimientos del portafolio')
plt.plot(frontera_x,frontera_y, 'r--', linewidth=3)
plt.show()


