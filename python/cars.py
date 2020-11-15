import pandas as pd
from sklearn.svm import SVC, SVR
from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import train_test_split
from sklearn.metrics import explained_variance_score, silhouette_score
import numpy as np

df = pd.read_csv('auto.csv')

X = df[['cylinders', 'displacement', 'horsepower', 'weight', 'acceleration', 'model_year', 'origin']]
y = df['mpg']

le = LabelEncoder()
for i in X.columns:
    X[i] = le.fit_transform(X[i])

y = le.fit_transform(y)

X_train, X_test, y_train, y_test = train_test_split(X,y, test_size=0.2, random_state=42)

clf= SVR(kernel='rbf')
clf.fit(X_train,y_train)

y_pred = clf.predict(X_test)

print(explained_variance_score(y_test, y_pred))