from tensorflow import keras
import numpy as np
import scipy as sp

fashion_mnist = keras.datasets.fashion_mnist.load_data()
(X_train_full, y_train_full), (X_test, y_test) = fashion_mnist
X_test = X_test/255

class_names = np.array(["T-shirt/top", "Trouser", "Pullover", "Dress", "Coat",
               "Sandal", "Shirt", "Sneaker", "Bag", "Ankle boot"])
x_test90 = np.zeros([10000,28,28])
i=0
for pic in X_test:
    x_test90[i] = sp.ndimage.rotate(pic, 90)
    i+=1

model1 = keras.models.load_model("my_fashion_mnist_model")
model2 = keras.models.load_model("my_fashion_mnist_model_hokepip")
model3 = keras.models.load_model("fashion_model_hokepip_with_rotate")

loss1, accuracy1 = model1.evaluate(X_test, y_test)
loss2, accuracy2 = model2.evaluate(X_test, y_test)
loss3, accuracy3 = model3.evaluate(X_test, y_test)

loss4, accuracy4 = model1.evaluate(x_test90, y_test)
loss5, accuracy5 = model2.evaluate(x_test90, y_test)
loss6, accuracy6 = model3.evaluate(x_test90, y_test)

print("")
print("")
print("")
print("==============    Nomal    ==============")
print("")
print("my_fashion_mnist_model")
print("loss on test set: %.2f" % loss1)
print("accuracy on test set: %.2f" % accuracy1)
print("")
print("my_fashion_mnist_model_hokepip")
print("loss on test set: %.2f" % loss2)
print("accuracy on test set: %.2f" % accuracy2)
print("")
print("fashion_model_hokepip_with_rotate")
print("loss on test set: %.2f" % loss3)
print("accuracy on test set: %.2f" % accuracy3)
print("")

print("========  with 90 anticlockwise  ========")
print("")
print("my_fashion_mnist_model")
print("loss on test set: %.2f" % loss4)
print("accuracy on test set: %.2f" % accuracy4)
print("")
print("my_fashion_mnist_model_hokepip")
print("loss on test set: %.2f" % loss5)
print("accuracy on test set: %.2f" % accuracy5)
print("")
print("fashion_model_hokepip_with_rotate")
print("loss on test set: %.2f" % loss6)
print("accuracy on test set: %.2f" % accuracy6)
