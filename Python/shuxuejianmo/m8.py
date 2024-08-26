# 导入必要的库
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
from sklearn.metrics import mean_squared_error
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import StandardScaler
from matplotlib.font_manager import FontProperties
import matplotlib

# 设置支持中文的字体
zh_font = FontProperties(fname=r"C:\Windows\Fonts\simhei.ttf", size=14)
sns.set(font='SimHei')  # 设置Seaborn的字体

# 假设您已经将数据加载到名为 'df' 的数据框中
df = pd.read_csv('train.csv', encoding='GB2312')

# 选择特征和目标
X = df[['城市化', '人口得分', '湿地损失', '流域', '农业实践', '政策因素', '排水系统', '滑坡', '侵蚀', '气候变化']]
y = df['洪水概率']

# 如有必要，预处理数据（例如缩放）
scaler = StandardScaler()
X = scaler.fit_transform(X)

# 将数据分成训练集和测试集
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# 创建线性回归模型
lin_reg = LinearRegression()

# 将模型拟合到训练数据
lin_reg.fit(X_train, y_train)
print(X_test)
# 在测试集上进行预测
y_pred = lin_reg.predict(X_test)

# 现在您可以使用适当的回归指标评估模型的性能
mse = mean_squared_error(y_test, y_pred)
print("Mean Squared Error:", mse)

# 数据可视化
# 相关性热力图
corr_matrix = df[['城市化', '人口得分', '湿地损失', '流域', '农业实践', '政策因素', '排水系统', '滑坡', '侵蚀', '气候变化', '洪水概率']].corr()
sns.heatmap(corr_matrix, annot=True, cmap='coolwarm')
plt.title('相关性热力图', fontproperties=zh_font)
plt.show()
