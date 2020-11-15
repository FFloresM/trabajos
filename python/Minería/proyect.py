"""
Group code
"""
import pandas
import seaborn
import matplotlib

from sklearn.neighbors import LocalOutlierFactor
from sklearn.pipeline import make_pipeline
from sklearn.preprocessing import MinMaxScaler
from sklearn.feature_selection import RFE
from sklearn.linear_model import LogisticRegression

data = pandas.read_csv("proyectoData.csv")

#replace all N and Y with booleans
data.replace(to_replace="Y", value=True, inplace=True)
data.replace(to_replace="N", value=False, inplace=True)

#drop columns with over 1000 missing values
data.dropna(axis='columns', inplace=True, thresh=10000) 
#delete all entries with missing data
data.dropna(inplace=True)
#delete name
data.drop(inplace=True, axis="columns", labels="full_name")
#reset index so outlier detection can drop by id
data.reset_index(inplace=True, drop=True)

#Standarize, then select features through RFE, then find outliers
pipe = make_pipeline(
    MinMaxScaler(), 
    RFE(estimator=LogisticRegression(max_iter=1000), n_features_to_select=6), 
    LocalOutlierFactor())

pipe.fit(data.drop(labels="Danger", axis="columns"), data.Danger)

#Feature selection (RFE) ranking
ranking = pipe.steps[1][1].ranking_
#LoF outliers
outliers = pipe.steps[2][1].negative_outlier_factor_

#drop the worse features
columnsToDrop = []
for rank, i in zip(ranking, range(len(ranking))):
    #only keep the variables rank 1 (highest)
    if (rank != 1):
        columnsToDrop.append(i)
data.drop(data.columns[columnsToDrop], axis="columns", inplace=True)

#drop outlier rows chosen by LoF
for i in range(len(outliers)):
    #drop if factor is below -1.5
    if(outliers[i] < -1.5):
        data.drop(labels=i, inplace=True)

#seaborn.pairplot(data.drop(axis="columns", labels="Danger"), corner=True)
#matplotlib.pyplot.show()

data.to_csv('data.csv', index=False)