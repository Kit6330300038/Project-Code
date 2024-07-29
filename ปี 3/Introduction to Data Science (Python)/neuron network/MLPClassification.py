from sklearn.datasets import fetch_openml
from sklearn.neural_network import MLPClassifier
from sklearn.model_selection import train_test_split

x,y = fetch_openml("mnist_784",version=1,return_X_y=True,as_frame=False)
x = x/255.0

x_train, x_test, y_train, y_test = train_test_split(x,y,random_state=42)

mlp = MLPClassifier(hidden_layer_sizes=(36),
                    max_iter=200,
                    solver='sgd',
                    verbose=True,
                    random_state=42,
                    learning_rate_init=0.2)

mlp.fit(x_train,y_train)

print("Training set score: %.1f"% mlp.score(x_train, y_train))
print("Test set score: %.1f"% mlp.score(x_test, y_test))