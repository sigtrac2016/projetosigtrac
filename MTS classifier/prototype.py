import pandas as pd
import numpy as np
from sklearn.linear_model import LinearRegression, SGDRegressor
from sklearn import svm
from sklearn.svm import SVR
from sklearn.ensemble import RandomForestRegressor, ExtraTreesRegressor, BaggingRegressor
from sklearn import cross_validation
from sklearn.metrics import mean_squared_error
from sklearn.metrics import accuracy_score
import matplotlib.pyplot as plt
from tqdm import tqdm, trange
import pickle
from sklearn.externals import joblib
from sklearn import preprocessing
import itertools

################################################### Loading Data ###################################################

df = pd.read_csv("dataset/pone.0083267.csv", sep=';')

df['Age'] = df['Age'].fillna(df['Age'].mean())
df['Respiratory rate'] = df['Respiratory rate'].fillna(df['Respiratory rate'].mean())
df['Heart rate'] = df['Heart rate'].fillna(df['Heart rate'].mean())
df['Temperature'] = df['Temperature'].fillna(df['Temperature'].mean())
df['Oxygen saturation'] = df['Oxygen saturation'].fillna(df['Oxygen saturation'].mean())

df.loc[df['Original MTS'] == 'Emergent', 'label'] = 4
df.loc[df['Original MTS'] == 'Very urgent', 'label'] = 3
df.loc[df['Original MTS'] == 'Urgent', 'label'] = 2
df.loc[df['Original MTS'] == 'Standard', 'label'] = 1
df.loc[df['Original MTS'] == 'Non urgent', 'label'] = 0

# print(df)

features = df[['Respiratory rate', 'Heart rate', 'Temperature', 'Oxygen saturation', 'label']]

train_size = int(0.8*features.shape[0])
X_train = features.as_matrix()[0:train_size, :-1]
X_train = preprocessing.scale(X_train)
y_train = features.as_matrix()[0:train_size, -1]

X_test = np.asarray(features)[train_size:, :-1]
X_test = preprocessing.scale(X_test)
y_test = np.asarray(features)[train_size:, -1]

# for i, j in itertools.product(range(4),range(4)): 
# 	if i != j:
# 		plt.scatter(X_train[:, i], X_train[:, j], c=y_train, cmap=plt.cm.Paired)
# 		plt.show()
# print(X_train)

################################################### Supervised Learning Techniques ###################################################

### Linear Regression ###

reg = LinearRegression()
reg.fit(X_train, y_train)
# joblib.dump(reg, 'models/linearRegressor.pkl') 
# reg = joblib.load('models/linearRegressor.pkl') 
y_pred = reg.predict(X_test)

# print([np.rint(y_pred), y_test])
print('Linear Regression')
print('> MSE: ' + str(mean_squared_error(np.rint(y_pred), y_test)))
print('> Accuracy: ' + str(accuracy_score(y_test, np.rint(y_pred))))

### Support Vector Machine (Classifier)
clf = svm.SVC()
# clf.fit(X_train, y_train)
# joblib.dump(clf, 'models/svmClassifier-scaled.pkl') 
clf = joblib.load('models/svmClassifier-scaled.pkl') 
# clf = joblib.load('models/linearSVM.pkl') 
y_pred = clf.predict(X_test)

print('Support Vector Machine (Classifier)')
print('> MSE: ' + str(mean_squared_error(np.rint(y_pred), y_test)))
print('> Accuracy: ' + str(accuracy_score(y_test, np.rint(y_pred))))

# ### Support Vector Regressor
# reg = SVR(kernel='rbf')

# for i in trange(0, X_train.shape[0]):
# 	y_pred[i] = reg.fit(X_train, y_train).predict(np.array(X_train[i]))

# y_pred = reg.predict(X_test)

# print('Support Vector Regressor')
# print('> MSE: ' + str(mean_squared_error(np.rint(y_pred), y_test)))
# print('> Accuracy: ' + str(accuracy_score(y_test, np.rint(y_pred))))

################################################### Unsupervised Learning Techniques ###################################################

### Random Forest Regressor
reg = RandomForestRegressor(5)
# reg = ExtraTreesRegressor(5)
reg.fit(X_train, y_train)
# joblib.dump(reg, 'models/randomForestRegressor.pkl') 
# reg = joblib.load('models/randomForestRegressor.pkl') 

# importances = reg.feature_importances_

# std = np.std([tree.feature_importances_ for tree in reg.estimators_], axis=0)
# indices = np.argsort(importances)[::-1]

# print("Feature ranking:")

# for f in range(X_train.shape[1]):
#     print("%d. feature %d (%f)" % (f + 1, indices[f], importances[indices[f]]))

# plt.figure()
# plt.title("Feature importances")
# plt.bar(range(X_train.shape[1]), importances[indices],
#        color="r", yerr=std[indices], align="center")
# plt.xticks(range(X_train.shape[1]), indices)
# plt.xlim([-1, X_train.shape[1]])
# plt.show()

y_pred = reg.predict(X_test)
print('Random Forest Regressor')
print('> MSE: ' + str(mean_squared_error(np.rint(y_pred), y_test)))
print('> Accuracy: ' + str(accuracy_score(y_test, np.rint(y_pred))))

