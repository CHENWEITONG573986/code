import pandas as pd
import numpy as np

# 假设我们有一个DataFrame，其中包含季风强度和洪水概率的数据
df = pd.read_csv('train.csv', encoding='GB2312')  # 假设编码为UTF-8，如果没有特殊编码，可以省略encoding参数

# 计算每个季风强度级别的频率
df_freq = df['季风强度'].value_counts().reindex(df['季风强度'].unique(), fill_value=0)

# 计算每个季风强度级别的加权平均洪水概率
df_weighted = df.copy()  # 复制一份数据，避免修改原始数据
df_weighted['权重'] = df_weighted['季风强度'].map(df_freq)  # 为每个数据点分配权重
df_weighted_avg = df_weighted.groupby('季风强度').apply(lambda x: np.average(x['洪水概率'], weights=x['权重']))

# 重置索引，使其成为普通的DataFrame
df_weighted_avg = df_weighted_avg.reset_index()
df_weighted_avg.columns = ['季风强度', '加权平均洪水概率']

# 计算皮尔逊相关系数
correlation_coefficient = df_weighted_avg['季风强度'].corr(df_weighted_avg['加权平均洪水概率'])

print(f"季风强度与洪水概率的皮尔逊相关系数为: {correlation_coefficient}")