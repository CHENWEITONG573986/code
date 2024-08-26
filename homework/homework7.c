#include<stdio.h>
int main(void)
{
    int a,i=0,n,v=25;
    char acg[26];
    printf("/*计科2306陈维桐*/\n");
    printf("*********\n");
    for(n='A';n<='Z';n++)
    {
        acg[i]=n;
        i++;
    }
    for(n=1;n<=5;n++)
    {
        for(i=1;i<=5-n;i++)
            printf(" ");
        printf("%c",acg[v]);v--;
        if(n!=1)
        {
            for(i=1;i<=2*(n-1)-1;i++)
                printf(" ");
            printf("%c",acg[v]);v--;
        }
        printf("\n");
    }
    for(n=4;n>0;n--)
    {
        for(i=1;i<=5-n;i++)
            printf(" ");
        printf("%c",acg[v]);v--;
        if(n!=1)
        {
            for(i=1;i<=2*(n-1)-1;i++)
                printf(" ");
            printf("%c",acg[v]);v--;
        }
        printf("\n");
    }
    printf("*********\n");
    return 0;
}