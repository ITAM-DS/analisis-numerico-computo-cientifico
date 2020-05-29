import fix_yahoo_finance as yf

def extraer_datos_yahoo(stocks, start='2015-01-01', end='2020-04-30'):
  '''
  Funcion para extraer precios al cierre de las acciones mediante yahoo finance de 2015-01-01 a 2020-04-30

  params: stocks    lista de acciones de las cuales se desea obtener el precio
          start     fecha inicial
          end       fecha final

  return: base      Dataframe de precios por acción (columnas) y día (filas)
  '''
  df_c = yf.download(stocks, start=start, end=end).Close
  base = df_c['AAPL'].dropna().to_frame()
  for i in range(0,50):
      base = base.join(df_c.iloc[:,i].to_frame(), lsuffix='_caller', rsuffix='_other')
  base = base.drop(columns=['AAPL_caller'])
  base = base.rename(columns={"AAPL_other": "AAPL"})
  base = base.fillna(method='ffill')
  base = base.fillna(method='bfill')
  return base
