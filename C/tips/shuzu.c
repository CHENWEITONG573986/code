#include<stdio.h>
int main(void)
{
    char a[26],n;
    int i=0;
    for(n='A';n<='Z';n++)
    {
        a[i]=n;
        printf("%c",a[i]);
        i++;
    }
    return 0;
}