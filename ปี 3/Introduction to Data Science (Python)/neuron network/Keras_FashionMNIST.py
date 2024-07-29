import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import tensorflow as tf

tf.random.set_seed(42)

fashion_mnist = tf.keras.datasets.fashion_mnist.load_data()


(x_train_full, y_train_full), (x_test, y_test) = fashion_mnist
x_train, y_train = x_train_full[:-5000], y_train_full[:-5000]
x_valid, y_valid =x_train_full[-5000:], y_train_full[-5000:]

x_train, x_valid, x_test = x_train/255.0, x_valid/255.0, x_test/255.0

class_names = np.array(["T-shirt/top","Trouser","Pullover","Dress","Coat",
                        "Sandal","Shirt","Sneaker","Bag","Ancle boot"])

model = tf.keras.Sequential()
model.add(tf.keras.layers.Input(shape=[28,28]))
model.add(tf.keras.layers.Flatten())
model.add(tf.keras.layers.Dense(300,activation='relu'))
model.add(tf.keras.layers.Dense(100,activation='relu'))
model.add(tf.keras.layers.Dense(10,activation='softmax'))

model.summary()

model.compile(loss='sparse_categorical_crossentropy',
              optimizer='sgd',
              metrics=['accuracy'])

history = model.fit(x_train, y_train, epochs=30, validation_data=(x_valid, y_valid))

pd.DataFrame(history.history).plot(
    figsize=(8,5), xlim=[0,29], ylim=[0,1], grid=True,
    xlabel='EPoch', ylabel='Loss', style=['r--','r--','b-','b-*'])


plt.savefig('fashion_mnist_learning_curve.png')
plt.show()

loss, accuracy = model.evaluate(x_test, y_test)
print("loss on test set: %.2f"% loss)
print("accuracy on test set: %.2f"% accuracy)

x_new = x_test[:3]
y_proba = model.predict(x_new)
y_pred = y_proba.argmax(axis=-1)

y_test_classnames = class_names[y_test[:3]]
y_pred_classnames = class_names[y_pred]
for y,y_hat in zip(y_test_classnames,y_pred_classnames):
    print("True class = %s,Prediction = %s"%(y, y_hat))
