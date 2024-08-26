#include<stdio.h>
int Prime(int p);  //函数声明
int main(void)
{
    int n,i,j,a=0;
    printf("输出小于n的所有素数\n");
    printf("/*计科2306陈维桐*/\n");
    printf("请输入n的值:");
    scanf("%d",&n);
    printf("======================\n");
    for(i=2;i<n;i++)  //提取[2,n-1]的数
    {
        j=Prime(i);  //调用Prime函数并复制给j
        if(j==1)  //i为素数执行
        {
            printf("%4d",i);  //输出i
            a++;  //给输出的数计数
            if(a%5==0)  //每5个数换行
                printf("\n");
        }
    }
    printf("======================");
    return 0;
}
int Prime(int p)  //定义Prime函数，用来判断p是否为素数
{
    int i,n,a=1;
    for(i=2;i<p;i++)  //提取[2,p-1]的数
    {
        if(p%i==0)  //用p取余[2,p-1]来判断是否为素数
            a=0;  //是素数赋值给a赋值0
    }
    return a;  //返回a的值
} 