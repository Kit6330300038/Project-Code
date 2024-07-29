import matplotlib.pyplot as plt
from sklearn import datasets
from sklearn.cluster import KMeans

iris = datasets.load_iris()

x = iris.data[:,2:]
y = iris.target
print(x[:15,:])

plt.scatter(x[:,0],x[:,1],cmap='Paired_r')
plt.xlabel(iris.feature_names[2])
plt.ylabel(iris.feature_names[3])
plt.show()

km = KMeans(n_clusters=10)
km.fit(x)
y_clustered = km.labels_

g=plt.scatter(x[:,0],x[:,1],c=y_clustered,cmap='tab10')
plt.scatter(km.cluster_centers_[:,0],km.cluster_centers_[:,1], s=100,c='red')
plt.xlabel(iris.feature_names[2])
plt.ylabel(iris.feature_names[3])
plt.show()