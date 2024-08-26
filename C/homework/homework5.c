#include <stdio.h>
int main(void)
{
    int n,i,a,c=1;
    printf("《输出100以内的素数》\n");
    printf("*计科2306陈维桐*\n");
    printf("================\n");
    for (n=2;n<=100;n++)
    {
        a=0;
        for(i=2;i<n;i++)
        {
            if(n%i==0)
            {
                a=1;
                break;
            }
        }
        if(a==0)
        {
            printf("%3d",i);
            if(c%5==0)
            {
                printf("\n");
            }
            c++;
        }
    }
    printf("================\n");
    return 0;
}
