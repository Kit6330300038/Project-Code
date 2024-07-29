import tensorflow as tf
from sklearn.datasets import fetch_california_housing
from sklearn.model_selection import train_test_split

tf.random.set_seed(42)

housing = fetch_california_housing()
x_train_full, x_test, y_train_full, y_test = train_test_split(
    housing.data, housing.target, random_state=42)
x_train, x_valid, y_train, y_valid = train_test_split(
    x_train_full, y_train_full, random_state=42 )

model = tf.keras.Sequential()
norm_layer = tf.keras.layers.Normalization(input_shape=x_train.shape[1:])
norm_layer.adapt(x_train)
model.add(norm_layer)
model.add(tf.keras.layers.Dense(64,activation='relu'))
model.add(tf.keras.layers.Dense(64,activation='relu'))
model.add(tf.keras.layers.Dense(64,activation='relu'))
model.add(tf.keras.layers.Dense(1))

model.summary()

model.compile(loss='mse',optimizer='sgd',metrics=['RootMeanSquaredError'])

history = model.fit(x_train,y_train,epochs=20,validation_data=(x_valid, y_valid))

mse_test,rmse_test = model.evaluate(x_test,y_test)
print("MSE on test set: %.2f"%mse_test)
print("RMSE on test set: %.2f"%rmse_test)

x_new= x_test[:3]
y_pred = model.predict(x_new)
for y,y_hat in zip(y_test[:3],y_pred):
    print("True price = %f,Prediction = %f"%(y,y_hat))