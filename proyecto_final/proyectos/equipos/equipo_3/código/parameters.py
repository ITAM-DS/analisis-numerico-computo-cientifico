## MODULE WITH RELEVANT PARAMETERS FOR THE CLUSTERING ANALYSIS





"------------------------------------------------------------------------------"
########################
## General parameters ##
########################


## Dictionary to rename marginalization classifications.
gm_rename = { "Muy bajo": "0_muy_bajo",
    "Bajo": "1_bajo",
    "Medio": "2_medio",
    "Alto": "3_alto",
    "Muy alto": "4_muy_alto"
}

## Year processed
yr = 2015

## Number of clusters
n_clusters = 5





"------------------------------------------------------------------------------"
####################################################
## Dictionary with features to perform clustering ##
####################################################


original_features = {
    "CVE_ENT": {
        "feature": False,
        "selected": True
    },
    "NOM_ENT": {
        "feature": False,
        "selected": True
    },
    "POB_TOT": {
        "feature": False,
        "selected": True
    },
    "ANALF": {
        "feature": True,
        "selected": True
    },
    "SPRIM": {
        "feature": True,
        "selected": True
    },
    "OVSDE": {
        "feature": True,
        "selected": True
    },
    "OVSEE": {
        "feature": True,
        "selected": True
    },
    "OVSAE": {
        "feature": True,
        "selected": True
    },
    "VHAC": {
        "feature": True,
        "selected": True
    },
    "OVPT": {
        "feature": True,
        "selected": True
    },
    "PL.5000": {
        "feature": True,
        "selected": True
    },
    "PO2SM": {
        "feature": True,
        "selected": True
    },
    "IM": {
        "feature": False,
        "selected": False
    },
    "GM": {
        "feature": False,
        "selected": False,
        "classif": True
    },
    "LUGAR": {
        "feature": False,
        "selected": False
    },
    "A.O": {
        "feature": False,
        "selected": False,
        "year_id": True
    }
}


pca_features = {
    "PC1": {
        "feature": True,
        "selected": True
    },
    "PC2": {
        "feature": True,
        "selected": True
    },
    "PC3": {
        "feature": True,
        "selected": True
    },
    "PC4": {
        "feature": True,
        "selected": True
    },
    "PC5": {
        "feature": True,
        "selected": True
    },
    "PC6": {
        "feature": True,
        "selected": False
    },
    "PC7": {
        "feature": True,
        "selected": False
    },
    "PC8": {
        "feature": True,
        "selected": False
    },
    "PC9": {
        "feature": True,
        "selected": False
    },
    "GM": {
        "feature": False,
        "selected": False,
        "classif": True
    },
    "IM": {
        "feature": False,
        "selected": False
    },
    "A.O": {
        "feature": False,
        "selected": False,
        "year_id": True
    }
}
