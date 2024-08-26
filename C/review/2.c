#include<stdio.h>
int main(void)
{
    int m,w,c,i,z;
    printf("|男人\t|女人\t|孩子\n");
    for(m=1;m<29;m++)
    {
        for(w=1;w<(29-m);w++)
        {
            c=30-m-w;
            if((m*3)+(w*2)+c==50)
                printf("|%d\t|%d\t|%d\n",m,w,c);
        }
    }
    return 0;
}