#include<stdio.h>
void butler(void);
int main(void)
{
    int i,j,sum;
    printf("                        《九九乘法表》\n");
    printf("                        计科2306陈维桐\n");
    butler();
    for(i=1;i<=9;i++) printf("%-7d",i);printf("\n");
    butler();
    for(i=1;i<=9;i++)
    {
        for(j=1;j<=i;j++)
        {
            sum=i*j;
            printf("%dx%d=%-3d",i,j,sum);
        }
        printf("\n");
    }
    butler();
    return 0;
}
void butler(void)
{
    int i;
    for(i=1;i<=9;i++) printf("=======");printf("\n");
}