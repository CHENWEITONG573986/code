#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <locale.h>
void enter();
void menu();
void increase();
void Delete();
void revise();
void Inquire();  //查询信息
void ranking();  //成绩排名
void Change_password();  //保存密码
void Read_password();  //读取密码
void revise_password();  //修改密码
char password[20]; //全局变量
char Student_ID[50][13],Name[50][14],Math[50][4],English[50][4],Politics[50][4],C[50][4],Gender[50][4];

int main(void)
{
    printf("\t\t\t\t\t**********************************************\n");
	printf("\t\t\t\t\t**----------武汉纺织大学外经贸学院----------**\n");
	printf("\t\t\t\t\t**********************************************\n");
	printf("\t\t\t\t\t**                                          **\n");
	printf("\t\t\t\t\t**         学生成绩管理系统(猫娘版)         **\n");
	printf("\t\t\t\t\t**                                          **\n");
	printf("\t\t\t\t\t**********************************************\n");
	printf("\t\t\t\t\t**    欢迎主人使用本喵,祝您使用愉快,喵~~    **\n"); 
	printf("\t\t\t\t\t**********************************************\n");
	printf("\t\t\t\t\t**   制作者：陈维桐    学号：230103040616   **\n"); 
	printf("\t\t\t\t\t**   学院：工程学院    班级：计科2306班     **\n");
	printf("\t\t\t\t\t**********************************************\n");
    setlocale(LC_ALL, "zh_CN.utf8");  // 设置本地化环境为中文系统，以便存储汉字。
    Read_password();
    printf("请主人输入密码喵~:");
    int i,a=0;
    char Password[20];
    for(i=0;i<3;i++)
    {
        gets(Password);
        if(strcmp(Password,password)==0) //strcmp函数包含于<string.h>文件，作用比较两个字符串是否相同。
        {
            printf("恭喜主人,密码正确,登陆成功,喵~\n");
            a=1;
            break;
        }
        else
        {
            if(i==2) printf("主人你输入错误超过3次了哦,本喵惩罚你登陆哒咩！！！");
            else printf("密码错误了哦主人！！！\n你还有%d次机会\n再输入一次密码吧:",2-i);
        }
    }
    if(a) menu();
    return 0;
}

void menu() //系统菜单
{
	printf("\t\t\t\t\t**********************************************\n");
	printf("\t\t\t\t\t**                                          **\n");
	printf("\t\t\t\t\t**         欢迎主人进入我的世界喵~~~        **\n");
	printf("\t\t\t\t\t**                                          **\n");
	printf("\t\t\t\t\t**********************************************\n");
	printf("\t\t\t\t\t**---------------功能菜单-------------------**\n");
	printf("\t\t\t\t\t**       增加学生信息 ------------1         **\n");
	printf("\t\t\t\t\t**       删除学生信息 ------------2         **\n");
	printf("\t\t\t\t\t**       修改学生信息 ------------3         **\n");
	printf("\t\t\t\t\t**       查询学生信息 ------------4         **\n");
	printf("\t\t\t\t\t**       输出成绩排名 ------------5         **\n");
	printf("\t\t\t\t\t**       修改登录密码 ------------6         **\n");
	printf("\t\t\t\t\t**       退出管理系统 ------------0         **\n");
	printf("\t\t\t\t\t**********************************************\n");
    int num;
    printf("主人请尽情吩咐本喵吧~~(请输入您要使用的序号):");
    scanf("%d",&num);
    switch (num)
    {
    case 1:increase();break;
    //case 2:Delete();break;
    case 3:revise();break;
    case 4:Inquire();break;
    //case 5:ranking();break;
    case 6: revise_password();break;
    case 0: printf("\t\t\t\t\t**********************************************\n");
	        printf("\t\t\t\t\t**                                          **\n");
	        printf("\t\t\t\t\t**        欢迎下次使用！~再见！~~           **\n");
	        printf("\t\t\t\t\t**                                          **\n");
	        printf("\t\t\t\t\t**********************************************\n");
            break;
    }
}

void  revise_password()  //修改密码
{
    char Password[20];
    int i=0;
    printf("请输入原密码:");
    again:scanf("%s",&Password);
    if(strcmp(Password,password)==0)  //strcmp函数包含于<string.h>文件，作用比较两个字符串是否相同。
    {
        printf("密码正确\n");
        Change_password();
        i=1;
    }
    else
    {
        printf("密码错误！！！\n请再输入一遍:\n");
        goto again;
    }
    menu();
}

void Change_password()  //保存密码
{
    char Password[20];  
    printf("请输入新的密码：");
    scanf("%s",&Password);
    FILE *fp;
    fp = fopen("save.txt", "w");
    fprintf(fp, "%s",Password);
    fclose(fp);
    printf("保存成功！\n");
}

void Read_password()  //读取密码
{
    FILE *fp;
    fp= fopen("save.txt", "r");
    fscanf(fp, "%s", &password);
    fclose(fp);
}


void Inquire()  //查询信息
{
    int i,j,n,a;
    printf(" ____________________________________________________\n");
    printf("|     学号     |  姓名  |性别|数学 |英语 |思政 |c语言|\n");
    printf(" ____________________________________________________\n");
    FILE*St;FILE*Na;FILE*Ma;FILE*En;FILE*Po;FILE*Cp;FILE*Ge;
    St=fopen("Student_ID.txt","r");
    Ge=fopen("Gender.txt","r");
    Na=fopen("Name.txt","r");
    Ma=fopen("Math.txt","r");
    En=fopen("English.txt","r");
    Po=fopen("Politics.txt","r");
    Cp=fopen("C.txt","r");
    for(i=0;i<4;i++)
    {
        fscanf(St, "%s", &Student_ID[i]);
        printf("|%s  |",Student_ID[i]);
        fscanf(Na, "%s", &Name[i]);
        printf("%s  |",Name[i]);
        fscanf(Ge, "%s",&Gender[i]);
        printf("%s  |",Gender[i]);
        fscanf(Ma, "%s", &Math[i]);
        printf("%s  |",Math[i]);
        fscanf(En, "%s", &English[i]);
        printf("%s  |",English[i]);
        fscanf(Po, "%s", &Politics[i]);
        printf("%s  |",Politics[i]);
        fscanf(Cp, "%s", &C[i]);
        printf("%s  |",C[i]);
        printf("\n ____________________________________________________\n");
        
    }
    fclose(St);fclose(Na);fclose(Ma);
    fclose(En);fclose(Po);fclose(Cp);
    fclose(Ge);
    menu();
}

void increase() //增加信息
{
    setlocale(LC_ALL, "zh_CN.utf8");
    int i,j;
    for(i=0;i<50;i++)
    {
        printf("请输入第%d人的学号：",i+1);
        scanf("%s",&Student_ID[i]);
        printf("请输入第%d人的姓名：",i+1);
        scanf("%s",&Name[i]);
        printf("请输入第%d人的性别(男输入1，女输入0)：",i+1);
        scanf("%s",&Gender[i]);
        printf("请输入第%d人的数学成绩：",i+1);
        scanf("%s",&Math[i]);
        printf("请输入第%d人的英语成绩：",i+1);
        scanf("%s",&English[i]);
        printf("请输入第%d人的思政成绩：",i+1);
        scanf("%s",&Politics[i]);
        printf("请输入第%d人的C语言成绩：",i+1);
        scanf("%s",&C[i]);
        printf("继续输入请扣0，退出请扣1:");
        scanf("%d",&j);
        if(j) break;
    }
    FILE*St;FILE*Na;FILE*Ma;FILE*En;FILE*Po;FILE*Cp;FILE*Ge;
    St=fopen("Student_ID.txt","w");
    Na=fopen("Name.txt","w");
    Ma=fopen("Math.txt","w");
    En=fopen("English.txt","w");
    Po=fopen("Politics.txt","w");
    Cp=fopen("C.txt","w");
    Ge=fopen("Gender.txt","w");
    for(i=0;i<50;i++)
    {
        fprintf(St,"%s\n",Student_ID[i]);
        fprintf(Ge,"%s\n",Gender[i]);
        fprintf(Na,"%s\n",Name[i]);
        fprintf(Ma,"%s\n",Math[i]);
        fprintf(En,"%s\n",English[i]);
        fprintf(Po,"%s\n",Politics[i]);
        fprintf(Cp,"%s\n",C[i]);
    }
    fclose(St);fclose(Na);fclose(Ma);
    fclose(En);fclose(Po);fclose(Cp);
    fclose(Ge);
    printf("保存成功喵~~~\n");
    menu();
}

void revise()  //修改数据
{
    char acg[13];
    int i,j=-1;
    printf("主人请输入您要修改的学生的学号喵~~~\n");
    scanf("%s",&acg);
    FILE*St;FILE*Na;FILE*Ma;FILE*En;FILE*Po;FILE*Cp;FILE*Ge;
    St=fopen("Student_ID.txt","r");
    Ge=fopen("Gender.txt","r");
    Na=fopen("Name.txt","r");
    Ma=fopen("Math.txt","r");
    En=fopen("English.txt","r");
    Po=fopen("Politics.txt","r");
    Cp=fopen("C.txt","r");
    for(i=0;i<50;i++)
    {
        fscanf(St, "%s", &Student_ID[i]);
        fscanf(Na, "%s", &Name[i]);
        fscanf(Ge, "%s",&Gender[i]);
        fscanf(Ma, "%s", &Math[i]);
        fscanf(En, "%s", &English[i]);
        fscanf(Po, "%s", &Politics[i]);
        fscanf(Cp, "%s", &C[i]);
        if(strcmp(Student_ID[i],acg)==0)
        {
            printf("找到啦！！！主人您要的数据本喵都给你列在下面啦~~~\n");
            printf(" ____________________________________________________\n");
            printf("|     学号     |  姓名  |性别|数学 |英语 |思政 |c语言|\n");
            printf(" ____________________________________________________\n");
            printf("|%s  |",Student_ID[i]);
            printf("%s  |",Name[i]);
            printf("%s  |",Gender[i]);
            printf("%s  |",Math[i]);
            printf("%s  |",English[i]);
            printf("%s  |",Politics[i]);
            printf("%s  |",C[i]);
            printf("\n ____________________________________________________\n");
            printf("1.姓名 2.性别 3.数学 4.英语 5.思政 6.c语言\n");
            printf("主人您要修改哪一部分内容呢？\n");
            int a;
            char p[10];
            scanf("%d",&a);
            switch (a)
            {
            case 1:
                printf("主人告诉我您要修改的名字吧~~~\n");
                scanf("%s",&p);
                fprintf(Na, "%s",Name[i]);
                printf("修改好啦主人~~~话说主人的名字叫什么呢？一定很帅气吧，哈哈。\n");
                break;
            case 2:
                printf("主人告诉我您要修改的性别吧~~~\n");
                scanf("%s",&p);
                fprintf(Ge, "%s",Gender[i]);
                printf("修改好啦主人~~~话说主人是什么性别呢？不会是双性人吧，就算是，我也会一直喜欢主人的！！！\n");
                break;
            case 3:
                printf("主人告诉我您要修改的分数吧~~~\n");
                scanf("%s",&p);
                fprintf(Ma, "%s",Math[i]);
                printf("修改好啦主人~~~话说主人考了多少分呢？就算不及格也没事，我会耐心教主人的！！！\n");
                break;
            case 4:
                printf("主人告诉我您要修改的分数吧~~~\n");
                scanf("%s",&p);
                fprintf(En, "%s",English[i]);
                printf("修改好啦主人~~~话说主人考了多少分呢？就算不及格也没事，我会耐心教主人的！！！\n");
                break;
            case 5:
                printf("主人告诉我您要修改的分数吧~~~\n");
                scanf("%s",&p);
                fprintf(Po, "%s",Politics[i]);
                printf("修改好啦主人~~~话说主人考了多少分呢？就算不及格也没事，我会耐心教主人的！！！\n");
                break;
            case 6:
                printf("主人告诉我您要修改的分数吧~~~\n");
                scanf("%s",&p);
                fprintf(Cp, "%s",C[i]);
                printf("修改好啦主人~~~话说主人考了多少分呢？就算不及格也没事，我会耐心教主人的！！！\n");
                break;
            }
        }
    }
    fclose(St);fclose(Na);fclose(Ma);
    fclose(En);fclose(Po);fclose(Cp);
    fclose(Ge);
    if(j==-1) printf("抱歉主人没有找到您输入的学号的信息捏~~~\n");
    menu();
}




