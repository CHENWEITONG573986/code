import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.font_manager import FontProperties

# 读取CSV文件
df = pd.read_csv('train.csv', encoding='GB2312')

AA = '流域'
# 分组计算每个组的洪水概率平均值
avg_flood_probabilities = df.groupby(AA)['洪水概率'].mean().reset_index()
#avg_flood_probabilities = df.groupby('季风强度')['洪水概率'].apply(lambda x: np.average(x, weights=x.index)).reset_index()
print(avg_flood_probabilities)

# 提取X和Y坐标
x = avg_flood_probabilities[AA]
y = avg_flood_probabilities['洪水概率']

# 绘制散点图
plt.scatter(x, y)

# 设置中文字体
zh_font = FontProperties(fname=r"C:\Windows\Fonts\simhei.ttf", size=14)

# 添加标题和标签（可选）
plt.xlabel(AA, fontproperties=zh_font)
plt.ylabel('洪水概率', fontproperties=zh_font)

# 保存图片
plt.savefig('流域.png', dpi=300)

# 显示图形
plt.show()

correlation = avg_flood_probabilities['季风强度'].corr(avg_flood_probabilities['洪水概率'])
print(correlation)
