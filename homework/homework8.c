#include<stdio.h>
#define n 5
int main(void)
{
    int a[n],i,j,t;
    printf("此程序将输入的数字由小到大排序\n");
    printf("/***计科2306陈维桐***/\n");
    printf("请输入%d个整数:",n);
    for(i=0;i<=n-1;i++)
        scanf("%d",&a[i]);
    for(i=0;i<=n-2;i++)
    {
        for(j=i+1;j<=n-1;j++)
        {
            if(a[i]<a[j])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    printf("***************************\n");
    printf("由小到大为:");
    for(i=4;i>=0;i--)
        printf("%d ",a[i]);
    printf("\n***************************\n");
    return 0;
}
