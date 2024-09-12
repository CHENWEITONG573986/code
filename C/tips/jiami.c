#include<stdio.h>
int main(void)
{
    char a[10][4]={"零","壹","貮","叁","肆","伍","陆","柒","捌","玖"};
    int n,i=0,j=0,k,p;
    char acg[26],ACG[26],c;
    for(n='a';n<='z';n++)
    {
        acg[i]=n;
        i++;
    }
    for(n='A';n<='Z';n++)
    {
        ACG[j]=n;
        j++;
    }
    printf("加密程序\n");
    printf("/*计科2306陈维桐*/\n");
    printf("请输入原始密码(以*号开始#号结束):");
    while(c!='#')
    {
        if(c=='*') 
        {
            printf("加密后的密码如下\n");
            printf("***********************************\n");
        }
        scanf("%c",&c);
        if(c>='0'&&c<='9')
        {
            p=(int)c-48+3;
            if(p>9) p=p%10;
            printf("%s",a[p]);
        }
        if(c>='a'&&c<='z')
        {
            p=(int)c-97+3;
            if(p>25) p=p%26;
            printf("%c",ACG[p]);
        }
        if(c>='A'&&c<='Z')
        {
            p=(int)c-65+3;
            if(p>25) p=p%26;
            printf("%c",acg[p]);
        }
    }
    printf("\n***********************************");
    return 0;
}