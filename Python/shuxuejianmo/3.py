'''分组计算相关系数'''
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.font_manager import FontProperties

# 设置中文字体
zh_font = FontProperties(fname=r"C:\Windows\Fonts\simhei.ttf", size=14)

df = pd.read_csv('train.csv', encoding='GB2312')
table_data = []
for col in df.columns[1:]:
    groupby_avg = df.groupby(col, as_index=False)['洪水概率'].mean()#apply(lambda x: np.average(x, weights=x.index))
    ans = groupby_avg[col].corr(groupby_avg['洪水概率'])
    table_data.append({'col': col, 'corr': ans})
table = pd.DataFrame(table_data)
print(table)