#include<stdio.h>
int main(void)
{
    int a[10]={87,78,69,79,98,86,91,75,71,95};
    int i,j,*p;
    for(i=0;i<10;i++)
        if(a[j]>a[i])
            j=i;
    printf("min=%d,下标=%d\n",a[j],j);
    *p=a[0];
    a[0]=a[j];
    a[j]=*p;
    for(i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }
}