#include<stdio.h>
int main(void)
{
    float a[5][4],b[4],c[4];
    int i,j;
    b[0]=0;
    c[0]=0;
    printf("请输入5个学生4门课的成:\n");
    for(i=0;i<5;i++)
        for(j=0;j<4;j++)
            scanf("%f",&a[i][j]);
    for(j=0;j<4;j++)
    {
        b[j]=0;
        for(i=0;i<5;i++)
            b[j]=b[j]+a[i][j];
        c[j]=b[j]/5;
    }
    printf("每门课的平均分为:");
    for(j=0;j<4;j++)
        printf("%f ",c[j]);
    return 0;
}