#include<stdio.h>
int main(void)
{
    int i=1,year=2000;
    printf("下列为2000年至3000年的闰年年份:\n");
    printf("============open============\n");
    while (year<=3000)  //当超过3000年循环结束
    {
        if(year%4==0&&year%100!=0||year%400==0)  //判断是否为闰年 
        {
        printf("%d",year);
        printf(" ");
        if(i%3==0) printf("\n");  //每输出三个年份就换行
        i++;
        }
        year++;
    }
    printf("========计科2306陈维桐========");
    return 0;
}