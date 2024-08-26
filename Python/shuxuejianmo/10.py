import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
from sklearn.metrics import mean_squared_error
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import StandardScaler
from matplotlib.font_manager import FontProperties
from scipy.stats import norm

# 设置支持中文的字体
zh_font = FontProperties(fname=r"C:\Windows\Fonts\simhei.ttf", size=14)
sns.set(font='SimHei')  # 设置Seaborn的字体

# 假设您已经将数据加载到名为 'df' 的数据框中
df = pd.read_csv('train.csv', encoding='GB2312')
df2 = pd.read_csv('test.csv', encoding='GB2312')

# 选择特征和目标
X = df[['城市化', '人口得分', '湿地损失', '流域', '农业实践', '政策因素', '排水系统', '滑坡', '侵蚀', '气候变化']]
y = df['洪水概率']

# 如有必要，预处理数据（例如缩放）
scaler = StandardScaler()
X = scaler.fit_transform(X)

# 创建线性回归模型
lin_reg = LinearRegression()

# 将模型拟合到训练数据
lin_reg.fit(X, y)

# 加载测试数据集并进行预处理
test_data = df2[['城市化', '人口得分', '湿地损失', '流域', '农业实践', '政策因素', '排水系统', '滑坡', '侵蚀', '气候变化']]
test_data = scaler.transform(test_data)

# 在测试集上进行预测
y_pred = lin_reg.predict(test_data)

# 将预测结果保存到 CSV 文件
# 假设 'id' 列存在于 df2 中，您需要从 df2 中获取 'id' 列并添加到包含预测结果的新数据框中
submission = pd.DataFrame({'id': df2['id'], '洪水概率': y_pred})
submission.to_csv('submit.csv', index=False)

# 绘制直方图
plt.figure(figsize=(10, 6))
sns.histplot(y_pred, bins=50, kde=True)
plt.title('洪水概率直方图')
plt.xlabel('洪水概率')
plt.ylabel('频次')
plt.show()

# 绘制折线图
plt.figure(figsize=(10, 6))
plt.plot(range(len(y_pred)), y_pred, marker='o')
plt.title('洪水概率折线图')
plt.xlabel('事件序号')
plt.ylabel('洪水概率')
plt.show()

# 分析分布是否服从正态分布
mu, std = norm.fit(y_pred)
plt.figure(figsize=(10, 6))
sns.histplot(y_pred, bins=50, kde=True, stat='density', alpha=0.6, color='b')
xmin, xmax = plt.xlim()
x = np.linspace(xmin, xmax, 100)
p = norm.pdf(x, mu, std)
plt.plot(x, p, 'k', linewidth=2)
plt.title('Fit results: mu={:.2f},  std={:.2f}'.format(mu, std))
plt.show()

# 计算偏度和峰度来检验正态性
skewness = y_pred.skew()
kurtosis = y_pred.kurt()
print(f'偏度: {skewness}')
print(f'峰度: {kurtosis}')