#include<stdio.h>
char Student_ID[50][13],Name[50][14],Math[50][4],English[50][4],Politics[50][4],C[50][4],Gender[50][4];
int main (void)
{
    int j;
    FILE*St;FILE*Na;FILE*Ma;FILE*En;FILE*Po;FILE*Cp;FILE*Ge;
        St=fopen("Student_ID.txt","r");
        Ge=fopen("Gender.txt","r");
        Na=fopen("Name.txt","r");
        Ma=fopen("Math.txt","r");
        En=fopen("English.txt","r");
        Po=fopen("Politics.txt","r");
        Cp=fopen("C.txt","r");
        printf("找到啦！！！主人您要的数据本喵都给你列在下面啦~~~\n");
        j=1;
        printf("%d\n",j);
        printf(" ____________________________________________________\n");
        printf("|     学号     |  姓名  |性别|数学 |英语 |思政 |c语言|\n");
        printf(" ____________________________________________________\n");
        fscanf(St, "%s", &Student_ID[j]);
        printf("|%s  |",Student_ID[j]);
        fscanf(Na, "%s", &Name[j]);
        printf("%s  |",Name[j]);
        fscanf(Ge, "%s",&Gender[j]);
        printf("%s  |",Gender[j]);
        fscanf(Ma, "%s", &Math[j]);
        printf("%s  |",Math[j]);
        fscanf(En, "%s", &English[j]);
        printf("%s  |",English[j]);
        fscanf(Po, "%s", &Politics[j]);
        printf("%s  |",Politics[j]);
    fscanf(Cp, "%s", &C[j]);
    printf("%s  |",C[j]);
    printf("\n ____________________________________________________\n");
}