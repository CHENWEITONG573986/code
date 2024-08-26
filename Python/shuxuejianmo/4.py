import numpy as np
import pandas as pd
from sklearn.cluster import KMeans
from sklearn import metrics

# 读取CSV文件，假设编码为UTF-8
df = pd.read_csv('train.csv', encoding='GB2312')

# 检查是否有缺失值，如果有，可以选择填充或删除
if df['洪水概率'].isnull().any():
    print("发现缺失值")
    # 这里可以选择填充或删除缺失值
    # df.dropna(subset=['洪水概率'], inplace=True)
    # 或者填充缺失值
    # df['洪水概率'].fillna(df['洪水概率'].mean(), inplace=True)

# 提取洪水概率数据
flood_probabilities = df['洪水概率'].values

# 使用K-means算法进行聚类，这里我们设定聚类数为3
kmeans = KMeans(n_clusters=3, random_state=0).fit(flood_probabilities.reshape(-1, 1))

# 获取每个洪水概率所属的类别
labels = kmeans.labels_

# 将类别标签添加回数据框
df['类别'] = labels

# 获取每个类别的中心点
centroids = kmeans.cluster_centers_

# 定义类别名称
category_names = ['低', '中', '高']

# 将类别标签转换为对应的名称
df['类别名称'] = df['类别'].map({i: name for i, name in enumerate(category_names)})

# # 打印每个洪水概率及其所属的类别
# print(df[['洪水概率', '类别名称']])

# # 打印每个类别的中心点
# for i, centroid in enumerate(centroids):
#     print(f"类别: {category_names[i]}, 中心点: {centroid}")

# 评估聚类效果，这里使用轮廓系数
score = metrics.silhouette_score(flood_probabilities.reshape(-1, 1), labels)
print(f"轮廓系数: {score}")