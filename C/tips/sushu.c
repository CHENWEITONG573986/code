#include<stdio.h>
int main(void)
{
    int n,i;
    printf("输入要判断的数：");
    scanf("%d",&n);
    for(i=2;i<n;i++)
    {
        if(n%i==0) 
        {
            printf("%d不是素数",n); 
            goto flag;
        }
    }
    printf("%d是素数",n);
    flag: return 0;
}