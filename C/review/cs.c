#include<stdio.h>
int main(void)
{
    int i,j,a,b=1;
    for(i=2;i<=200;i++)
    {
        a=1;
        for(j=2;j<i;j++)
        {
            if(i%j==0)
            {
                a=0;
            }
        }
        if(a)
        {
            printf("%d ",i);
            if(b%3==0)
                printf("\n");
            b++;
        }
    }
    return 0;
}