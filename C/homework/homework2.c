#include<stdio.h>
int main(void)
{
    char ch;
    int class1=0,class2=0,class3=0;
    printf("请输入任意字符直到按#建停止:");
    while (ch!='#')  //当输出#时循环结束
    {
        scanf("%c",&ch);
        if(ch>='0'&&ch<='9') class1++;  //统计数字个数
        else if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')) class2++;  //统计字母个数
        else class3++;  //统计其他字符个数
    }
    printf("===========open===========\n");
    printf("数字字符有%d个\n字母字符有%d个\n其他字符有%d个\n",class1,class2,class3);
    printf("======计科2306陈维桐======");
    return 0;
}