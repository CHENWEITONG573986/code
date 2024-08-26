#include<stdio.h>
int main(void)
{
    float g[5][4],s[4],a[4];
    int i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<4;j++)
            scanf("%f",&g[i][j]);
    }
    for(j=0;j<4;j++)
    {
        s[j]=0;
        for(i=0;i<5;i++)
            s[j]=s[j]+g[i][j];
        a[j]=s[j]/5;
        printf("%.2f",a[j]);
    }
    return 0;
}