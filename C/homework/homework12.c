#include<stdio.h>
int main(void)
{
    char a[10][4]={"零","壹","貮","叁","肆","伍","陆","柒","捌","玖"};
    int i;
    printf("将阿拉伯数字转为汉字数字\n");
    printf("/*计科2306陈维桐*/\n");
    printf("请输入阿拉伯数字:");
    scanf("%d",&i);
    printf("汉字数字为:");
    puts(a[i]);
    return 0;
}