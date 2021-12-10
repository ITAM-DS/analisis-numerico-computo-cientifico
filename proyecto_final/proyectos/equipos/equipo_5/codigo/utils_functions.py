###########################
## Imports ##
###########################
import pandas as pd
import os
os.chdir("../")

"------------------------------------------------------------------------------"
###########################
## Function's parameters ##
###########################
#Vector de variables categóricas
cat_vars=["sex", "cp", "fbs", "restecg", "exang", "slope",	"ca", "thal" ]

#Vector de variables numéricas
num_vars=["age", "trestbps", "chol","thalach","oldpeak"]
"------------------------------------------------------------------------------"
def read_dataset(file="data/heart.csv"):
    """Fuction to read csv file
    Paramaters:
    Returns:Dataframe """

    X = pd.read_csv(file, sep=",", header=0)

    return X


def convert_object(dataframe, cat_vars):
    """
    Transform columns' names to categoric.
        args:
            dataframe (dataframe): df whose columns will be formatted.
        returns:
            dataframe (dataframe): df with transformed columns .
    """

    for i in cat_vars:
        dataframe[i] = dataframe[i].astype('category')

    return dataframe