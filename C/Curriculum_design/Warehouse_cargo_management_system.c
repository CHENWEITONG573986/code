#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void ReadFromFile();  //初始化数据
int SaveFromFile(int l);  //保存数据
void WriteToFile();   //将信息写入特定文件
void Display();       //显示所有信息
void InputRecord();   //录入货物信息
void DeleteRecord();  //删除货物信息
void Query();         //查询指定编号货物信息
void ChangRecord();   //修改特定编号货物信息
void Out();           //退出系统
void menu();          //菜单
void ReadPassword();  //读取密码
int VerifyPassword(); //验证密码
void ChangPassword(); //修改密码

struct goods
{
	char num[20];     //编号
	char name[20];    //货物名
	int weight;  //重量
	char length[10];  //长度
	char width[20];   //宽度
	char height[10];  //高度
};
struct goods G[100];
int L=0;
char Password[20];    //密码

int main() 
{
	ReadFromFile();
    ReadPassword();
    printf("\t\t\t\t\t**********************************************\n");
	printf("\t\t\t\t\t**----------武汉纺织大学外经贸学院----------**\n");
	printf("\t\t\t\t\t**********************************************\n");
	printf("\t\t\t\t\t**                                          **\n");
	printf("\t\t\t\t\t**             仓库货物管理系统             **\n");
	printf("\t\t\t\t\t**                                          **\n");
	printf("\t\t\t\t\t**********************************************\n");
	printf("\t\t\t\t\t**           欢迎使用,祝您使用愉快          **\n"); 
	printf("\t\t\t\t\t**********************************************\n");
	printf("\t\t\t\t\t**   制作者：陈维桐    学号：230103040616   **\n"); 
	printf("\t\t\t\t\t**   学院：工程学院    班级：计科2306班     **\n");
	printf("\t\t\t\t\t**********************************************\n\n");
    int a;
    a=VerifyPassword();
    if(a)
    {
        flag:menu();
        int num;
        printf("\t\t\t\t\t请输入您要使用的序号:");
        scanf("%d",&num);
        switch (num)
        {
            case 1:system("cls");goto flag;
            case 2:system("cls");InputRecord();goto flag;
            case 3:system("cls");DeleteRecord();goto flag;
            case 4:system("cls");Query();goto flag;
            case 5:system("cls");ChangRecord();goto flag;
            case 6:system("cls");ChangPassword();goto flag;
            case 0:system("cls");Out();return 0;
            break;
        }
    }
    else return 0;
	return 0;
}
void Out() //退出系统
{
    printf("\t\t\t\t\t**********************************************\n");
	printf("\t\t\t\t\t**                                          **\n");
	printf("\t\t\t\t\t**        欢迎下次使用！~再见！~~           **\n");
	printf("\t\t\t\t\t**                                          **\n");
	printf("\t\t\t\t\t**********************************************\n");
}

void menu() //菜单
{
    printf("\t\t\t\t\t**********************************************\n");
	printf("\t\t\t\t\t**                                          **\n");
	printf("\t\t\t\t\t**              欢迎使用本系统              **\n");
	printf("\t\t\t\t\t**                                          **\n");
	printf("\t\t\t\t\t**********************************************\n");
	printf("\t\t\t\t\t**-----------------功能菜单-----------------**\n");
	printf("\t\t\t\t\t**        显示所有信息 ------------1        **\n");
	printf("\t\t\t\t\t**        增加货物信息 ------------2        **\n");
	printf("\t\t\t\t\t**        删除货物信息 ------------3        **\n");
	printf("\t\t\t\t\t**        查询货物信息 ------------4        **\n");
	printf("\t\t\t\t\t**        修改货物信息 ------------5        **\n");
	printf("\t\t\t\t\t**        修改登录密码 ------------6        **\n");
	printf("\t\t\t\t\t**        退出管理系统 ------------0        **\n");
	printf("\t\t\t\t\t**********************************************\n\n");
}

int VerifyPassword() //验证密码
{
    char password[20];
    int i,a=0;
    printf("\t\t\t\t\t请输入密码:");
    for(i=0;i<3;i++)
    {
        gets(password);
        if(strcmp(password,Password)==0)
        {
            system("cls");
            printf("\n\t\t\t\t\t*********************\n");
            printf("\t\t\t\t\t**密码正确,登陆成功**\n");
            printf("\t\t\t\t\t*********************\n\n");
            a=1;
            break;
        }
        else
        {
            if(i==2) printf("\t\t\t\t\t输入错误超过3次,禁止登陆！！！");
            else printf("\t\t\t\t\t密码错误！！！\n\t\t\t\t\t您还有%d次机会\n\t\t\t\t\t请再输入密码:",2-i);
        }
    }
    return a;
}

void  ChangPassword()  //修改密码
{
    char password[20];
    int i;
    printf("\n\t\t\t\t\t****************\n");
    printf("\t\t\t\t\t**密码修改服务**\n");
    printf("\t\t\t\t\t****************\n");
    printf("\n\t\t\t\t\t请输入原密码:");
    for(i=0;i<3;i++)
    {
        scanf("%s",&password);
        if(strcmp(password,Password)==0)
        {
            printf("\n\t\t\t\t\t************");
            printf("\n\t\t\t\t\t**密码正确**\n");
            printf("\t\t\t\t\t************");
            printf("\n\n\t\t\t\t\t请输入新的密码：");
            scanf("%s",&password);
            FILE *fp;
            fp = fopen("save.txt", "w");
            fprintf(fp, "%s",password);
            fclose(fp);
            printf("\n\t\t\t\t\t*****************");
            printf("\n\t\t\t\t\t****保存成功*****\n");
            printf("\t\t\t\t\t*****************\n\n");
            break;
        }
        else
        {
            if(i==2) printf("输入错误超过3次,禁止修改！！！\n");
            else printf("密码错误！！！\n你还有%d次机会\n请再输入原密码:",2-i);
        }
    }
}

void ReadPassword()  //读取密码
{
    FILE *fp;
    fp= fopen("save.txt", "r");
    fscanf(fp, "%s", &Password);
    fclose(fp);
}

void ReadFromFile() //初始化函数
{
	FILE*fp;
	int i=0;
	fp=fopen("goods.txt","r");
	if(fp==NULL)
	{
		printf("\t\t\t\t\t**********************************************\n");
	    printf("\t\t\t\t\t**                                          **\n");
	    printf("\t\t\t\t\t**           程序初始化失败！！！           **\n");
	    printf("\t\t\t\t\t**                                          **\n");
	    printf("\t\t\t\t\t**********************************************\n");
		return;
	}
	while(!feof(fp))
	{
		fscanf(fp,"%s",G[i].num);
		fscanf(fp,"%s",G[i].name);
		fscanf(fp,"%d",&G[i].weight);
		fscanf(fp,"%s",G[i].length);
		fscanf(fp,"%s",G[i].width);
		fscanf(fp,"%s",G[i].height);
		i++;
	}
	fclose(fp);
	L=i;
}

void Display() //显示所有信息
{
    printf("\t\t\t\t\t\t\t《数据库总览》\n");
    printf("\t\t\t\t\t _______________________________________________\n");
    printf("\t\t\t\t\t|编号\t|货物\t|重量\t|长度\t|宽度\t|高度\t|\n");
    printf("\t\t\t\t\t _______________________________________________\n");
    int i;
    for(i=0;i<L;i++)
    {
        printf("\t\t\t\t\t|%s\t|%s\t|%d\t|%s\t|%s\t|%s\t|\n",G[i].num,G[i].name,G[i].weight,G[i].length,G[i].width,G[i].height);
        printf("\t\t\t\t\t _______________________________________________\n");
    }
    printf("\n");
}

void InputRecord()  //添加数据
{
    int i,n=1;
    printf("\n\t\t\t\t\t****************\n");
    printf("\t\t\t\t\t**录入货物服务**\n");
    printf("\t\t\t\t\t****************\n\n");
    while(n)
    {
        again:printf("\t\t\t\t\t请输入添加货物的编号:");
        scanf("%s",G[L].num);
        for(i=0;i<L;i++)
		{
			if(strcmp(G[i].num,G[L].num)==0)
			{
				printf("\t\t\t\t\t编号重复！！！\n");
				printf("\t\t\t\t\t请重新输入\n");
				goto again;
			}
		}
        printf("\t\t\t\t\t请输入货物名：");
        scanf("%s",G[L].name);
        printf("\t\t\t\t\t请输入货物重量：");
        scanf("%d",&G[L].weight);
        printf("\t\t\t\t\t请输入货物长度：");
        scanf("%s",G[L].length);
        printf("\t\t\t\t\t请输入货物宽度：");
        scanf("%s",G[L].width);
        printf("\t\t\t\t\t请输入货物高度：");
        scanf("%s",G[L].height);
		SaveFromFile(L+1);
        ReadFromFile();
        printf("\n\t\t\t\t\t************\n");
        printf("\t\t\t\t\t**录入完成**\n");
        printf("\t\t\t\t\t***********+\n");
        printf("\n\t\t\t\t\t是否继续添加？(是请输入1，否请输入0):");
        scanf("%d",&n);
        printf("\n");
	}
}

void Query()  //查询特定信息
{
    char a[10];
    int i,j=1;
    printf("\n\t\t\t\t\t****************\n");
    printf("\t\t\t\t\t**信息查询服务**\n");
    printf("\t\t\t\t\t****************\n\n");
    printf("\t\t\t\t\t请输入要查询的货物的编号：");
    scanf("%s",a);
    for(i=0;i<L;i++)
    {
        if(strcmp(a,G[i].num)==0)
        {
            printf("\t\t\t\t\t查询的信息如下\n");
            printf("\t\t\t\t\t _______________________________________________\n");
            printf("\t\t\t\t\t|编号\t|货物\t|重量\t|长度\t|宽度\t|高度\t|\n");
            printf("\t\t\t\t\t _______________________________________________\n");
            printf("\t\t\t\t\t|%s\t|%s\t|%d\t|%s\t|%s\t|%s\t|\n",G[i].num,G[i].name,G[i].weight,G[i].length,G[i].width,G[i].height);
            printf("\t\t\t\t\t _______________________________________________\n\n");
            j=0;
            break;
        }
    }
    if(j)
    {
        printf("\n\t\t\t\t\t************\n");
        printf("\t\t\t\t\t**查无此号**\n");
        printf("\t\t\t\t\t************\n\n");
    }
}

void DeleteRecord()  //删除数据
{
    char a[20];
    int i,j,n,p=1;
    printf("\n\t\t\t\t\t****************\n");
    printf("\t\t\t\t\t**数据删除服务**\n");
    printf("\t\t\t\t\t****************\n\n");
    printf("\t\t\t\t\t请输入要删除的货物的编号：");
    scanf("%s",a);
    for(i=0;i<L;i++)
    {
        if(strcmp(a,G[i].num)==0)
        {
            printf("\t\t\t\t\t查询的数据如下\n");
            printf("\t\t\t\t\t _______________________________________________\n");
            printf("\t\t\t\t\t|编号\t|货物\t|重量\t|长度\t|宽度\t|高度\t|\n");
            printf("\t\t\t\t\t _______________________________________________\n");
            printf("\t\t\t\t\t|%s\t|%s\t|%d\t|%s\t|%s\t|%s\t|\n",G[i].num,G[i].name,G[i].weight,G[i].length,G[i].width,G[i].height);
            printf("\t\t\t\t\t _______________________________________________\n");
            printf("\t\t\t\t\t是否要删除该数据？(是请输入1，否请输入0):");
            scanf("%d",&n);
            if(n)
            {
                for(i;i<L;i++)
                {
                    strcpy(G[i].num,G[i+1].num);
                    strcpy(G[i].name,G[i+1].name);
                    G[i].weight=G[i+1].weight;
                    strcpy(G[i].length,G[i+1].length);
                    strcpy(G[i].width,G[i+1].width);
                    strcpy(G[i].height,G[i+1].height);
                }
                SaveFromFile(L-1);
                ReadFromFile();
                p=0;
                printf("\t\t\t\t\t************\n");
                printf("\t\t\t\t\t**删除成功**\n");
                printf("\t\t\t\t\t************\n");
                break;
            }
        }
    }
    if(p)
    {
        printf("\n\t\t\t\t\t************\n");
        printf("\t\t\t\t\t**查无此号**\n");
        printf("\t\t\t\t\t************\n");
    }
    printf("\n");
}

void ChangRecord()  //修改货物信息
{
    char a[20];
    int i,j=1,n,p;
    printf("\n\t\t\t\t\t****************\n");
    printf("\t\t\t\t\t**数据修改服务**\n");
    printf("\t\t\t\t\t****************\n\n");
    printf("\t\t\t\t\t请输入要修改的货物的编号：");
    scanf("%s",a);
    for(i=0;i<L;i++)
    {
        if(strcmp(a,G[i].num)==0)
        {
            printf("\t\t\t\t\t查询的信息如下\n");
            printf("\t\t\t\t\t _______________________________________________\n");
            printf("\t\t\t\t\t|编号\t|货物\t|重量\t|长度\t|宽度\t|高度\t|\n");
            printf("\t\t\t\t\t _______________________________________________\n");
            printf("\t\t\t\t\t|%s\t|%s\t|%d\t|%s\t|%s\t|%s\t|\n",G[i].num,G[i].name,G[i].weight,G[i].length,G[i].width,G[i].height);
            printf("\t\t\t\t\t _______________________________________________\n");
            again:printf("\t\t\t\t\t请选择您要修改的数据\n");
            printf("\t\t\t\t\t ____________________________________\n");
            printf("\t\t\t\t\t|1.货物|2.重量|3.长度|4.宽度|5.高度|\n");
            printf("\t\t\t\t\t ____________________________________\n");
            printf("\t\t\t\t\t请输入要修改的序号；");
            scanf("%d",&n);
            switch(n)
            {
            case 1:
                printf("\t\t\t\t\t请输入修改后的货物:");
                scanf("%s",G[i].name);
                break;
            case 2:
                printf("\t\t\t\t\t请输入修改后的重量:");
                scanf("%d",&G[i].weight);
                break;
            case 3:
                printf("\t\t\t\t\t请输入修改后的长度:");
                scanf("%s",G[i].length);
                break;
            case 4:
                printf("\t\t\t\t\t请输入修改后的宽度:");
                scanf("%s",G[i].width);
                break;
            case 5:
                printf("\t\t\t\t\t请输入修改后的高度:");
                scanf("%s",G[i].height);
                break;
            default:
                printf("\t\t\t\t\t请输入正确的序号:");
                break;
            }
            printf("\t\t\t\t\t继续修改请输入1，退出请输入0:");
            scanf("%d",&p);
            if(p) goto again;
            SaveFromFile(L);
            ReadFromFile();
            j=0;
            break;
        }
    }
    if(j)
    {
        printf("\n\t\t\t\t\t************\n");
        printf("\t\t\t\t\t**查无此号**\n");
        printf("\t\t\t\t\t************\n\n");
    } 
}

int SaveFromFile(int l)  //保存数据
{
    FILE*fp;
	int i=0;
	fp=fopen("goods.txt","w");
	if(fp==NULL)
	{
		printf("\t\t\t\t\t**********************************************\n");
	    printf("\t\t\t\t\t**                                          **\n");
	    printf("\t\t\t\t\t**            数据保存失败！！！           **\n");
	    printf("\t\t\t\t\t**                                          **\n");
	    printf("\t\t\t\t\t**********************************************\n");
		return 0;
	}
	for(i;i<l;i++)
    {
        fprintf(fp,"%s\t",G[i].num);
        fprintf(fp,"%s\t",G[i].name);
        fprintf(fp,"%d\t",G[i].weight);
        fprintf(fp,"%s\t",G[i].length);
        fprintf(fp,"%s\t",G[i].width);
        fprintf(fp,"%s",G[i].height);
        if(i!=l-1)fprintf(fp,"\n");
    }
	fclose(fp);
    return 0;
}