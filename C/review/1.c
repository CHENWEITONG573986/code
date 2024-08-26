#include<stdio.h>
int main(void)
{
    int a,n,i,m=0,s;
    printf("请输入a和n的值：");
    scanf("%d%d",&a,&n);
    for(i=0;i<n;i++)
    {
        m=m*10+a;
        s+=m;
    }
    printf("%d",s);
    return 0;
}