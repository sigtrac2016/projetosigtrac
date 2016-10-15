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
from sklearn.decomposition import TruncatedSVD

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

features = df[['Respiratory rate', 'Heart rate', 'Temperature', 'Oxygen saturation', 'label']]

train_size = int(0.8*features.shape[0])
X_train = features.as_matrix()[0:train_size, :-1]
y_train = features.as_matrix()[0:train_size, -1]

X_test = np.asarray(features)[train_size:, :-1]
y_test = np.asarray(features)[train_size:, -1]

################################################### Unsupervised Learning Techniques ###################################################

### Random Forest Regressor
reg = joblib.load('models/randomForestRegressor.pkl') 

importances = reg.feature_importances_

std = np.std([tree.feature_importances_ for tree in reg.estimators_], axis=0)
indices = np.argsort(importances)[::-1]

print("Feature ranking:" + str(indices))

print("Feature importances of the forest:")
for f in range(X_train.shape[1]):
    print("%d. feature %d (%f)" % (f + 1, indices[f], importances[indices[f]]))

plt.figure()
plt.title("Feature importances")
plt.bar(range(X_train.shape[1]), importances[indices],
       color="r", yerr=std[indices], align="center")
plt.xticks(range(X_train.shape[1]), indices)
plt.xlim([-1, X_train.shape[1]])
plt.show()

y_pred = reg.predict(X_test)
print('Random Forest Regressor')
print('> MSE: ' + str(mean_squared_error(np.rint(y_pred), y_test)))
print('> Accuracy: ' + str(accuracy_score(y_test, np.rint(y_pred))))

################################################### Supervised Learning Techniques ###################################################

### Support Vector Machine (Classifier)

# To visualize the actual data in top 2 dimensions
x = X_train
y = y_train

model = joblib.load('models/svmClassifier-scaled.pkl') 
predicted=model.predict(x)

svd=TruncatedSVD().fit_transform(x)

from matplotlib import pyplot as plt
plt.figure(figsize=(16,6))
plt.subplot(1,2,1)
plt.title('Actual data, with errors highlighted')
colors=['r','g','b']
for t in [0,1,2]:
    plt.plot(svd[y==t][:,0],svd[y==t][:,1],colors[t]+'+')

errX,errY=svd[predicted!=y],y[predicted!=y]
for t in [0,1,2]:
    plt.plot(errX[errY==t][:,0],errX[errY==t][:,1],colors[t]+'o')


# To visualize the SVM classifier across
import numpy as np
density=15
domain=[np.linspace(min(x[:,i]),max(x[:,i]),num=density*4 if i==2 else density) for i in range(4)]

from itertools import product
allxs=list(product(*domain))
allys=model.predict(allxs)

allxs_svd=TruncatedSVD().fit_transform(allxs)

plt.subplot(1,2,1)
plt.title('Prediction space reduced to top two SVD\'s')
plt.ylim(-3,3)
for t in [0,1,2]:
    plt.scatter(allxs_svd[allys==t][:,0],allxs_svd[allys==t][:,1],color=colors[t],alpha=0.2/density,edgecolor='None')
