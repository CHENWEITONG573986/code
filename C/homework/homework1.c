#include<stdio.h>
int main(void)
{
    int year,month,day,days,February;
    again:printf("请输入日期：");
    scanf("%d%d%d",&year,&month,&day);
    printf("=============open=============\n");
    if(year<0||(month<0||month>12)||(day<0||day>31))   //判断日期大致是否合规
    {
        printf("！！！输入的日期不符合规定！！！\n再");
        goto again;
    }
    February=(year%4==0&&year%100!=0||year%400==0)?29:28;  //判断该年2月有多少天
    if((month==2&&February==29&&day>29)||(month==2&&February==28&&day>28))  //判断2月日期是否合规
    {
        printf("！！！输入的日期不符合规定！！！\n再");
        goto again;
    }
    if((month==4||month==6||month==9||month==10)&&day>30)  //判断小月日期是否合规
    {
        printf("！！！输入的日期不符合规定！！！\n再");
        goto again;
    }
    switch (month)  //计算天数
    {
        case 1: days=day; printf("该日为该年的第%d天",days);break;
        case 2: days=31+day; printf("该日为该年的第%d天",days);break;
        case 3: days=31+February+day; printf("该日为该年的第%d天",days);break;
        case 4: days=62+February+day; printf("该日为该年的第%d天",days);break;
        case 5: days=92+February+day; printf("该日为该年的第%d天",days);break;
        case 6: days=123+February+day; printf("该日为该年的第%d天",days);break;
        case 7: days=153+February+day; printf("该日为该年的第%d天",days);break;
        case 8: days=184+February+day; printf("该日为该年的第%d天",days);break;
        case 9: days=215+February+day; printf("该日为该年的第%d天",days);break;
        case 10: days=245+February+day; printf("该日为该年的第%d天",days);break;
        case 11: days=276+February+day; printf("该日为该年的第%d天",days);break;
        case 12: days=306+February+day; printf("该日为该年的第%d天",days);break;
    }
    printf("\n========计科2306陈维桐========");
    return 0;
}