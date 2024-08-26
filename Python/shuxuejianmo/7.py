import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense

# 假设你已经有了一个CSV文件，其中包含特征和目标变量
# 读取数据
data = pd.read_csv('train.csv', encoding='GB2312')

# 假设特征是'feature1', 'feature2', ... , 'featureN'
features = data.columns[:-1]

# 特征标准化
scaler = StandardScaler()
scaled_features = scaler.fit_transform(data[features])

# 假设目标变量是'flood_probability'
target = data['flood_probability']

# 分割数据集为训练集和测试集
X_train, X_test, y_train, y_test = train_test_split(scaled_features, target, test_size=0.2, random_state=42)

# 构建神经网络模型
model = Sequential([
    Dense(units=32, activation='relu', input_shape=(len(features),)),
    Dense(units=16, activation='relu'),
    Dense(units=1, activation='sigmoid')
])

# 编译模型
model.compile(optimizer='adam', loss='binary_crossentropy', metrics=['accuracy'])

# 训练模型
history = model.fit(X_train, y_train, epochs=50, batch_size=32, validation_split=0.2)

# 评估模型
loss, accuracy = model.evaluate(X_test, y_test)
print(f'Test Loss: {loss}, Test Accuracy: {accuracy}')

# 进行预测
predictions = model.predict(X_test)