#include<stdio.h>
int main (void)
{
    int i,n;
    printf("《输出一个菱形》\n");
    printf("/*计科2306陈维桐*/\n");
    for(i=1;i<=9;i++)
    {
        for(n=1;n<=9-i;n++)
            printf(" ");
        for(n=1;n<=2*i-1;n++)
            printf("*");
        printf("\n");
    }
    for(i=8;i>0;i--)
    {
        for(n=1;n<=9-i;n++)
            printf(" ");
        for(n=1;n<=2*i-1;n++)
            printf("*");
        printf("\n");
    }
    return 0;
}