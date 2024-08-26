#include<stdio.h>
void guest(int n);
int main(void)
{
    int i;
    for(i=6;i<=50;i+=2)
    {
        guest(i);
        printf("\n");
    }
    return 0;
}
void guest(int n)
{
    
    int i,j,a,b,c=1;
    for(i=2;i<n;i++)
    {
        a=1;
        for(j=2;j<i;j++)
        {
            if(i%j==0)
            {
                a=0;
                break;
            }
        }
        if(a)
        {
            b=n-i;
            for(j=2;j<b;j++)
            {
                if(b%j==0)
                {
                    a=0;
                    break;
                }
            }
            if(a)
            {
            printf("%d=%d+%d ",n,i,b);
            if(c%3==0)
                printf("\n");
            c++;
            }
        }
    }
    printf("\n");
}