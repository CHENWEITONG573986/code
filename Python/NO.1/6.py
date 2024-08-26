# 键值对
jianzhidui={"我":"18",
            "你":"19",
            "他":"20"}
print(jianzhidui["我"])
ren=input("请输入你查询的人：")
if ren in jianzhidui:
    print(jianzhidui[ren])
else:
    print("查无此人")