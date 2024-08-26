#include<stdio.h>
int main(void)
{
    char a[10];
    int i=0,m=0;
    printf("将16进制转变为10进制\n");
    printf("/*计科2306陈维桐*/\n");
    printf("亲输入字符串:");
    while (a[i-1]!='#')
    {
        scanf("%c",&a[i]);
        i++;
    }
    for(i=0;i<10;i++)
    {
        if(a[i]>='0'&&a[i]<='9')
            m=m*16+(a[i]-'0');
        if(a[i]>='a'&&a[i]<='f')
            m=m*16+(a[i]-'a')+10;
        if(a[i]>='A'&&a[i]<='F')
            m=m*16+(a[i]-'A')+10;
    }
    printf("转为10进制如下:\n");
    printf("*******************\n");
    printf("%d\n",m);
    printf("*******************\n");
    return 0;
}