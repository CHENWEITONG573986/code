#include<stdio.h>
int main(void)
{
    char a[100];
    int i,j=0,n;
    printf("判断输入的字符串是否为回文串\n");
    printf("/*计科2306陈维桐*/\n");
    printf("请输入字符串:");
    gets(a);
    n=strlen(a);
    printf("=============\n");
    for(i=0;i<n;i++)
    {
        if(a[i]!=a[n-1-i])
        {
            printf("*****NO*****\n");
            j=1;
            break;
        }
    }
    if(j==0)
        printf("*****YES*****\n");
    printf("=============");
    return 0;
}