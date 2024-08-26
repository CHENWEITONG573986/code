#include<stdio.h>
int main(void)
{
    int i,n;
    float a=1,s=1;
    printf("请输入n的值：");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        if(i>1)
        {
        a=(float)((i-1)*2-1)/(float)(i*2-1);
        if(i%2==0)
            s-=a;
        else
            s+=a;
        }
    }
    printf("%f ",s);
    return 0;
}