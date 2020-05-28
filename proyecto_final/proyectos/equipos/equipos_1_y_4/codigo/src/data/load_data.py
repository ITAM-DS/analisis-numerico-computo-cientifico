from io import StringIO
import psycopg2
import pandas as pd

import sys
sys.path.append('../')
import Utileria as Ut

def save_rds(df,table_name):

    # Copy to postgres
    connection = Ut.CrearConexionRDS()
    cursor = connection.cursor()

    records = df.values.tolist()
    buffer = StringIO()
    for line in records:
        buffer.write('~'.join([str(x) for x in line]) + '\n')

    buffer.seek(0)

    cursor.copy_from(buffer, table_name, null='NaN', sep ='~' )
    connection.commit()
    cursor.close()
    connection.close()

def execute_sql(file_dir):
    """ Sirve para ejecutar archivos .sql """
    try:
        connection = Ut.CrearConexionRDS()
        cursor = connection.cursor()

        print(file_dir)
        cursor.execute(open(file_dir, "r").read())
        connection.commit()
        cursor.close()
        connection.close()
    except (Exception, psycopg2.Error) as error :
        print ("Error while executing sql file", error)


def main(par_TipoEjec):

    # file_dir = "./../sql/create_db.sql"
    # execute_sql(file_dir)

    file_dir = "./sql/create_schemas.sql"
    execute_sql(file_dir)

    file_dir = "./sql/create_tables.sql"
    execute_sql(file_dir)

    file_dir = "./sql/create_views.sql"
    execute_sql(file_dir)

    if par_TipoEjec == 'DEMO':
        file_name = "./../data/raw/raw_demo.csv"
    elif par_TipoEjec == 'REAL':
        file_name = "./../data/raw/raw.csv"

    df = pd.read_csv(file_name, encoding="latin-1")
    save_rds(df, "raw.fuerza_ventas")

    file_name = "./../data/raw/base_nodos.csv"
    df = pd.read_csv(file_name)
    save_rds(df, "raw.nodos_aux")

    file_dir = "./sql/clean_tables.sql"
    execute_sql(file_dir)

# main()
