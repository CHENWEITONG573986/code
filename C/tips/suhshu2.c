#include<stdio.h>
int main(void)
{
    int n,i,a;
    printf("输入要判断的数：");
    scanf("%d",&n);
    for(;n>1;n--)
    {
        a=0;
        for(i=2;i<n;i++)
        {
            if(n%i==0)
            {
                a=1;
                break;
            }
        }printf("a=%d",a);
        if(a==0)
        {
            printf("最大素数为%d",n);
            break;
        }
    }
    return 0;
}