from sklearn.cluster import KMeans
import pandas as pd
from sklearn.metrics import silhouette_score

df_crime = pd.read_csv('crime_data.csv')

X = df_crime[['Murder', 'Assault', 'UrbanPop', 'Rape']]
y = df_crime.State

kmean = KMeans(n_clusters=3, random_state=0).fit(X)

targets = set(kmean.labels_)

print(silhouette_score(X, kmean.labels_))

clusters = {x:[] for x in targets}
for i,v in enumerate(kmean.labels_):
    clusters[v].append(y[i])

for i in clusters:
    print(f'Cluster {i}')
    print(f'Centroide: {kmean.cluster_centers_[i]}')
    print(clusters[i])
