## MODULE WITH FUNCTIONS USED FOR THE PROJECT





"------------------------------------------------------------------------------"
#############
## Imports ##
#############

## Python libraries

import json

import pandas as pd

from sklearn.cluster import KMeans
from sklearn.metrics import confusion_matrix

import matplotlib.pyplot as plt

import seaborn as sns

import numpy as np

import six


## Ancillary modules

from utils.parameters import (
    gm_rename,
    yr,
    n_clusters,
    original_features,
    pca_features
)





"------------------------------------------------------------------------------"
#################################
## General ancillary functions ##
#################################


## Pretty print a dictionary and preserving special characters
def json_dump_dict(dictionary):
    """
    Pretty print a dictionary and preserving special characters
        args:
            dictionary (dictionary): dict that will be pretty printed
        returns:
            -
    """

    print(json.dumps(dictionary, indent=4, ensure_ascii=False).encode("utf8").decode())

    return



##
def finding_clusters_match(c_dict, gm_dict):
    """
    """

    orig_c_key = [c_key for c_key in c_dict]
    for c_key in orig_c_key:

        match_num = 1
        best_match = "not_found"
        for gm_key in gm_dict:
            delta_check = len(set(gm_dict[gm_key]) - set(c_dict[c_key]))/len(set(gm_dict[gm_key]))

            if delta_check < match_num:
                match_num = delta_check
                best_match = gm_key

        c_dict[best_match] = c_dict.pop(c_key)

    return c_dict



## Coupling the cluster dictionary with the data original classification.
def finding_clusters_match(c_dict, gm_dict):
    """
    """

    match_map = {}
    matches_used = []
    orig_c_key = [c_key for c_key in c_dict]
    for c_key in orig_c_key:

        match_num = 1
        best_match = "not_found"
        for gm_key in gm_dict:
            delta_check = len(set(gm_dict[gm_key]) - set(c_dict[c_key]))/len(set(gm_dict[gm_key]))

            if (delta_check < match_num) & (gm_key not in matches_used):
                match_num = delta_check
                best_match = gm_key

        c_dict[best_match] = c_dict.pop(c_key)
        matches_used.append(best_match)
        match_map[int(c_key)] = best_match

    return c_dict, match_map



##
def cluster_metrics(c_dict, gm_dict):
    """
    """

    c_dict_res = {}
    for key in c_dict:
        c_dict_res[key] = {
            "-"*10: "-"*10,
            "Correct": len(set(gm_dict[key])) - len((set(gm_dict[key]) - set(c_dict[key]))),
            "Incorrect": len(set(c_dict[key]) - set(gm_dict[key])),
            "Missing": len(set(gm_dict[key]) - set(c_dict[key]))
        }

    return c_dict_res



##
def display_confusion_matrix(df_sel):
    """
    """

    ## Labels that will be compared
    labs = list(df_sel["GM"].unique())
    labs.sort()

    ## Dataframe that will be converted into a heatmap
    conf_mtrx = pd.DataFrame(confusion_matrix(df_sel["GM"], df_sel["cluster"]), labs)
    conf_mtrx.columns = labs

    ## Converting dataframe into heatmap
    f, ax = plt.subplots(figsize=(9, 6))

    ax.set_title("Confusion Matrix")

    sns.heatmap(
        conf_mtrx,
        annot=True,
        fmt="d",
        linewidths=0.1,
        ax=ax
    )

    plt.yticks(rotation=0)

    plt.show()



def render_mpl_table(data, col_width=3.0, row_height=0.625, font_size=14,
                     header_color='#40466e', row_colors=['#f1f1f2', 'w'], edge_color='w',
                     bbox=[0, 0, 1, 1], header_columns=0,
                     ax=None, **kwargs):
    if ax is None:
        size = (np.array(data.shape[::-1]) + np.array([0, 1])) * np.array([col_width, row_height])
        fig, ax = plt.subplots(figsize=size)
        ax.axis('off')

    mpl_table = ax.table(cellText=data.values, bbox=bbox, colLabels=data.columns, **kwargs)

    mpl_table.auto_set_font_size(False)
    mpl_table.set_fontsize(font_size)

    for k, cell in  six.iteritems(mpl_table._cells):
        cell.set_edgecolor(edge_color)
        if k[0] == 0 or k[1] < header_columns:
            cell.set_text_props(weight='bold', color='w')
            cell.set_facecolor(header_color)
        else:
            cell.set_facecolor(row_colors[k[0]%len(row_colors) ])
    return ax





"------------------------------------------------------------------------------"
################################
## Problem specific functions ##
################################


##
def adding_cluster_feature(df_sel, df_type):
    """
    """

    ## Selecting the correct data dict according to the df processed.
    if df_type == "orig":
        features = original_features
    elif df_type == "pca":
        features = pca_features
    else:
        print("Invalid 'df_type' parameter specified.")
        raise

    ## List of features that will be used of the clustering process.
    feats = [feat for feat in features if
            (features[feat]["feature"] == True) &
            (features[feat]["selected"] == True)
            ]
    print("Features fed for clustering analysis ({}):".format(len(feats)))
    i = 1
    for f in feats:
        print("{}. {}".format(i, f))
        i += 1

    ## Determining clusters using k-means and attaching column
    kmeans = KMeans(n_clusters=5)
    df_sel["cluster"] = kmeans.fit_predict(df_sel.loc[:, feats])


    return df_sel



##
def cluster_dictionary(df_sel):
    """
    """

    ## Creating dictionaries of clusters and states
    gm_dict = {gm_v: list(df_sel.loc[df_sel["GM"] == gm_v, "NOM_ENT"]) for gm_v in df_sel["GM"].unique()}
    c_dict = {str(c_v): list(df_sel.loc[df_sel["cluster"] == c_v, "NOM_ENT"]) for c_v in df_sel["cluster"].unique()}
    # json_dump_dict(c_dict)

    ## Updating c_dict and df_sel keys based on match with gm_dict
    c_dict, match_map = finding_clusters_match(c_dict, gm_dict)
    df_sel["cluster"] = df_sel["cluster"].map(match_map)

    return gm_dict, c_dict, df_sel



##
def clustering_dataframes(gm_dict, c_dict):
    """
    """

    ## Reference clustering
    gm_df = pd.DataFrame.from_dict(gm_dict, orient="index").transpose().fillna("-")
    gm_df.sort_index(axis=1, inplace=True)
    gm_df.index = pd.MultiIndex.from_tuples([(yr, i) for i in gm_df.index])

    ## Resulting clustering
    c_df = pd.DataFrame.from_dict(c_dict, orient="index").transpose().fillna("-")
    c_df.sort_index(axis=1, inplace=True)
    c_df = c_df.append(pd.DataFrame.from_dict(cluster_metrics(c_dict, gm_dict)))
    c_df.index = pd.MultiIndex.from_tuples([(yr, i) for i in c_df.index])

    return gm_df, c_df
