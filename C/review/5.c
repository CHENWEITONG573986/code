#include<stdio.h>
int Prime(int n);
int main(void)
{
    int i,j=0,prime[200];
    for(i=2;i<200;i++)
    {
        if(Prime(i))
        {
            int a,b,c;
            a=i/100;
            b=(i/10)%10;
            c=i%10;
            if((a==3||a==7)||(b==3||b==7)||(c==3||c==7))
            {
                prime[j]=i;
                j++;
            }
        }
    }
    for(i=0;i<j;i++)
        printf("%d ",prime[i]);
}
int Prime(int n)
{
    int i,j,a;
    for(i=2;i<n;i++)
        if(n%i==0)
            return 0;
    return 1;
}