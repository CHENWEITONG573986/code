'''
计算相关系数
'''
import pandas as pd

df = pd.read_csv('train.csv', encoding='GB2312')

# 分组计算每个组的洪水概率平均值
avg_flood_probabilities = df.groupby('季风强度')['洪水概率'].mean().reset_index()

print(avg_flood_probabilities)

x = avg_flood_probabilities['季风强度']
y = avg_flood_probabilities['洪水概率']
# 平均值
x_average = x.mean()
y_average = y.mean()

#协方差
Sxy=0
for i in range(len(x)):
    Sxy += (x[i] - x_average) * (y[i] - y_average)

#计算标准差
Sx=0
Sy=0
for i in range(len(x)):
    Sx += (x[i] - x_average) ** 2
    Sy += (y[i] - y_average) ** 2

#计算相关系数
r = Sxy / (Sx * Sy) ** 0.5

print(r)