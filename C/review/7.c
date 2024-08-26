#include<stdio.h>
int main(void)
{
    int i,n;
    float a=1,s=1;
    for(i=1;1;i++)
    {
        if(i>1)
        {
        a=(float)((i-1)*2-1)/(float)(i*2-1);
        if(i%2==0)
            s-=a;
        else
            s+=a;
        }
        if(a<0.0001)
            break;
    }
    printf("%f",s);
    return 0;
}