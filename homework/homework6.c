#include<stdio.h>
int main(void)
{
    int n,i;
    double e=1.00,sn=0;
    printf("请输入n的值:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        sn+=i;
        e+=1/sn;
    }
    printf("计科2306陈维桐\n");
    printf("==============\n");
    printf("|***e=%.2f***|\n",e);
    printf("==============\n");
    return 0;
}