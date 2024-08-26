print("此程序求平均数")
total=0
count=0
user=input("请输入数字（输入q终止程序）：")
while user !="q":
    num=float(user)
    total+=num
    count+=1
    user=input("请输入数字（输入q终止程序）：")
if count==0:
    result=0
else:
    result=total/count
print("平均值为："+str(result))