import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.font_manager import FontProperties

df = pd.read_csv('train.csv', encoding='GB2312')


# 提取X和Y坐标
x = df['季风强度']
y = df['洪水概率']

# 绘制散点图
plt.scatter(x, y)

# 设置中文字体
zh_font = FontProperties(fname=r"C:\Windows\Fonts\simhei.ttf", size=14)

# 添加标题和标签（可选）
plt.xlabel('季风强度', fontproperties=zh_font)
plt.ylabel('洪水概率', fontproperties=zh_font)

# 保存图片
plt.savefig('季风强度.png', dpi=300)

# 显示图形
plt.show()