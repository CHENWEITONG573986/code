#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void ReadFromFile();  //��ʼ������
int SaveFromFile(int l);  //��������
void WriteToFile();   //����Ϣд���ض��ļ�
void Display();       //��ʾ������Ϣ
void InputRecord();   //¼�������Ϣ
void DeleteRecord();  //ɾ��������Ϣ
void Query();         //��ѯָ����Ż�����Ϣ
void ChangRecord();   //�޸��ض���Ż�����Ϣ
void Out();           //�˳�ϵͳ
void menu();          //�˵�
void ReadPassword();  //��ȡ����
int VerifyPassword(); //��֤����
void ChangPassword(); //�޸�����

struct goods
{
	char num[20];     //���
	char name[20];    //������
	int weight;  //����
	char length[10];  //����
	char width[20];   //���
	char height[10];  //�߶�
};
struct goods G[100];
int L=0;
char Password[20];    //����

int main() 
{
	ReadFromFile();
    ReadPassword();
    printf("\t\t\t\t\t**********************************************\n");
	printf("\t\t\t\t\t**----------�人��֯��ѧ�⾭óѧԺ----------**\n");
	printf("\t\t\t\t\t**********************************************\n");
	printf("\t\t\t\t\t**                                          **\n");
	printf("\t\t\t\t\t**             �ֿ�������ϵͳ             **\n");
	printf("\t\t\t\t\t**                                          **\n");
	printf("\t\t\t\t\t**********************************************\n");
	printf("\t\t\t\t\t**           ��ӭʹ��,ף��ʹ�����          **\n"); 
	printf("\t\t\t\t\t**********************************************\n");
	printf("\t\t\t\t\t**   �����ߣ���άͩ    ѧ�ţ�230103040616   **\n"); 
	printf("\t\t\t\t\t**   ѧԺ������ѧԺ    �༶���ƿ�2306��     **\n");
	printf("\t\t\t\t\t**********************************************\n\n");
    int a;
    a=VerifyPassword();
    if(a)
    {
        flag:menu();
        int num;
        printf("\t\t\t\t\t��������Ҫʹ�õ����:");
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
void Out() //�˳�ϵͳ
{
    printf("\t\t\t\t\t**********************************************\n");
	printf("\t\t\t\t\t**                                          **\n");
	printf("\t\t\t\t\t**        ��ӭ�´�ʹ�ã�~�ټ���~~           **\n");
	printf("\t\t\t\t\t**                                          **\n");
	printf("\t\t\t\t\t**********************************************\n");
}

void menu() //�˵�
{
    printf("\t\t\t\t\t**********************************************\n");
	printf("\t\t\t\t\t**                                          **\n");
	printf("\t\t\t\t\t**              ��ӭʹ�ñ�ϵͳ              **\n");
	printf("\t\t\t\t\t**                                          **\n");
	printf("\t\t\t\t\t**********************************************\n");
	printf("\t\t\t\t\t**-----------------���ܲ˵�-----------------**\n");
	printf("\t\t\t\t\t**        ��ʾ������Ϣ ------------1        **\n");
	printf("\t\t\t\t\t**        ���ӻ�����Ϣ ------------2        **\n");
	printf("\t\t\t\t\t**        ɾ��������Ϣ ------------3        **\n");
	printf("\t\t\t\t\t**        ��ѯ������Ϣ ------------4        **\n");
	printf("\t\t\t\t\t**        �޸Ļ�����Ϣ ------------5        **\n");
	printf("\t\t\t\t\t**        �޸ĵ�¼���� ------------6        **\n");
	printf("\t\t\t\t\t**        �˳�����ϵͳ ------------0        **\n");
	printf("\t\t\t\t\t**********************************************\n\n");
}

int VerifyPassword() //��֤����
{
    char password[20];
    int i,a=0;
    printf("\t\t\t\t\t����������:");
    for(i=0;i<3;i++)
    {
        gets(password);
        if(strcmp(password,Password)==0)
        {
            system("cls");
            printf("\n\t\t\t\t\t*********************\n");
            printf("\t\t\t\t\t**������ȷ,��½�ɹ�**\n");
            printf("\t\t\t\t\t*********************\n\n");
            a=1;
            break;
        }
        else
        {
            if(i==2) printf("\t\t\t\t\t������󳬹�3��,��ֹ��½������");
            else printf("\t\t\t\t\t������󣡣���\n\t\t\t\t\t������%d�λ���\n\t\t\t\t\t������������:",2-i);
        }
    }
    return a;
}

void  ChangPassword()  //�޸�����
{
    char password[20];
    int i;
    printf("\n\t\t\t\t\t****************\n");
    printf("\t\t\t\t\t**�����޸ķ���**\n");
    printf("\t\t\t\t\t****************\n");
    printf("\n\t\t\t\t\t������ԭ����:");
    for(i=0;i<3;i++)
    {
        scanf("%s",&password);
        if(strcmp(password,Password)==0)
        {
            printf("\n\t\t\t\t\t************");
            printf("\n\t\t\t\t\t**������ȷ**\n");
            printf("\t\t\t\t\t************");
            printf("\n\n\t\t\t\t\t�������µ����룺");
            scanf("%s",&password);
            FILE *fp;
            fp = fopen("save.txt", "w");
            fprintf(fp, "%s",password);
            fclose(fp);
            printf("\n\t\t\t\t\t*****************");
            printf("\n\t\t\t\t\t****����ɹ�*****\n");
            printf("\t\t\t\t\t*****************\n\n");
            break;
        }
        else
        {
            if(i==2) printf("������󳬹�3��,��ֹ�޸ģ�����\n");
            else printf("������󣡣���\n�㻹��%d�λ���\n��������ԭ����:",2-i);
        }
    }
}

void ReadPassword()  //��ȡ����
{
    FILE *fp;
    fp= fopen("save.txt", "r");
    fscanf(fp, "%s", &Password);
    fclose(fp);
}

void ReadFromFile() //��ʼ������
{
	FILE*fp;
	int i=0;
	fp=fopen("goods.txt","r");
	if(fp==NULL)
	{
		printf("\t\t\t\t\t**********************************************\n");
	    printf("\t\t\t\t\t**                                          **\n");
	    printf("\t\t\t\t\t**           �����ʼ��ʧ�ܣ�����           **\n");
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

void Display() //��ʾ������Ϣ
{
    printf("\t\t\t\t\t\t\t�����ݿ�������\n");
    printf("\t\t\t\t\t _______________________________________________\n");
    printf("\t\t\t\t\t|���\t|����\t|����\t|����\t|���\t|�߶�\t|\n");
    printf("\t\t\t\t\t _______________________________________________\n");
    int i;
    for(i=0;i<L;i++)
    {
        printf("\t\t\t\t\t|%s\t|%s\t|%d\t|%s\t|%s\t|%s\t|\n",G[i].num,G[i].name,G[i].weight,G[i].length,G[i].width,G[i].height);
        printf("\t\t\t\t\t _______________________________________________\n");
    }
    printf("\n");
}

void InputRecord()  //�������
{
    int i,n=1;
    printf("\n\t\t\t\t\t****************\n");
    printf("\t\t\t\t\t**¼��������**\n");
    printf("\t\t\t\t\t****************\n\n");
    while(n)
    {
        again:printf("\t\t\t\t\t��������ӻ���ı��:");
        scanf("%s",G[L].num);
        for(i=0;i<L;i++)
		{
			if(strcmp(G[i].num,G[L].num)==0)
			{
				printf("\t\t\t\t\t����ظ�������\n");
				printf("\t\t\t\t\t����������\n");
				goto again;
			}
		}
        printf("\t\t\t\t\t�������������");
        scanf("%s",G[L].name);
        printf("\t\t\t\t\t���������������");
        scanf("%d",&G[L].weight);
        printf("\t\t\t\t\t��������ﳤ�ȣ�");
        scanf("%s",G[L].length);
        printf("\t\t\t\t\t����������ȣ�");
        scanf("%s",G[L].width);
        printf("\t\t\t\t\t���������߶ȣ�");
        scanf("%s",G[L].height);
		SaveFromFile(L+1);
        ReadFromFile();
        printf("\n\t\t\t\t\t************\n");
        printf("\t\t\t\t\t**¼�����**\n");
        printf("\t\t\t\t\t***********+\n");
        printf("\n\t\t\t\t\t�Ƿ������ӣ�(��������1����������0):");
        scanf("%d",&n);
        printf("\n");
	}
}

void Query()  //��ѯ�ض���Ϣ
{
    char a[10];
    int i,j=1;
    printf("\n\t\t\t\t\t****************\n");
    printf("\t\t\t\t\t**��Ϣ��ѯ����**\n");
    printf("\t\t\t\t\t****************\n\n");
    printf("\t\t\t\t\t������Ҫ��ѯ�Ļ���ı�ţ�");
    scanf("%s",a);
    for(i=0;i<L;i++)
    {
        if(strcmp(a,G[i].num)==0)
        {
            printf("\t\t\t\t\t��ѯ����Ϣ����\n");
            printf("\t\t\t\t\t _______________________________________________\n");
            printf("\t\t\t\t\t|���\t|����\t|����\t|����\t|���\t|�߶�\t|\n");
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
        printf("\t\t\t\t\t**���޴˺�**\n");
        printf("\t\t\t\t\t************\n\n");
    }
}

void DeleteRecord()  //ɾ������
{
    char a[20];
    int i,j,n,p=1;
    printf("\n\t\t\t\t\t****************\n");
    printf("\t\t\t\t\t**����ɾ������**\n");
    printf("\t\t\t\t\t****************\n\n");
    printf("\t\t\t\t\t������Ҫɾ���Ļ���ı�ţ�");
    scanf("%s",a);
    for(i=0;i<L;i++)
    {
        if(strcmp(a,G[i].num)==0)
        {
            printf("\t\t\t\t\t��ѯ����������\n");
            printf("\t\t\t\t\t _______________________________________________\n");
            printf("\t\t\t\t\t|���\t|����\t|����\t|����\t|���\t|�߶�\t|\n");
            printf("\t\t\t\t\t _______________________________________________\n");
            printf("\t\t\t\t\t|%s\t|%s\t|%d\t|%s\t|%s\t|%s\t|\n",G[i].num,G[i].name,G[i].weight,G[i].length,G[i].width,G[i].height);
            printf("\t\t\t\t\t _______________________________________________\n");
            printf("\t\t\t\t\t�Ƿ�Ҫɾ�������ݣ�(��������1����������0):");
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
                printf("\t\t\t\t\t**ɾ���ɹ�**\n");
                printf("\t\t\t\t\t************\n");
                break;
            }
        }
    }
    if(p)
    {
        printf("\n\t\t\t\t\t************\n");
        printf("\t\t\t\t\t**���޴˺�**\n");
        printf("\t\t\t\t\t************\n");
    }
    printf("\n");
}

void ChangRecord()  //�޸Ļ�����Ϣ
{
    char a[20];
    int i,j=1,n,p;
    printf("\n\t\t\t\t\t****************\n");
    printf("\t\t\t\t\t**�����޸ķ���**\n");
    printf("\t\t\t\t\t****************\n\n");
    printf("\t\t\t\t\t������Ҫ�޸ĵĻ���ı�ţ�");
    scanf("%s",a);
    for(i=0;i<L;i++)
    {
        if(strcmp(a,G[i].num)==0)
        {
            printf("\t\t\t\t\t��ѯ����Ϣ����\n");
            printf("\t\t\t\t\t _______________________________________________\n");
            printf("\t\t\t\t\t|���\t|����\t|����\t|����\t|���\t|�߶�\t|\n");
            printf("\t\t\t\t\t _______________________________________________\n");
            printf("\t\t\t\t\t|%s\t|%s\t|%d\t|%s\t|%s\t|%s\t|\n",G[i].num,G[i].name,G[i].weight,G[i].length,G[i].width,G[i].height);
            printf("\t\t\t\t\t _______________________________________________\n");
            again:printf("\t\t\t\t\t��ѡ����Ҫ�޸ĵ�����\n");
            printf("\t\t\t\t\t ____________________________________\n");
            printf("\t\t\t\t\t|1.����|2.����|3.����|4.���|5.�߶�|\n");
            printf("\t\t\t\t\t ____________________________________\n");
            printf("\t\t\t\t\t������Ҫ�޸ĵ���ţ�");
            scanf("%d",&n);
            switch(n)
            {
            case 1:
                printf("\t\t\t\t\t�������޸ĺ�Ļ���:");
                scanf("%s",G[i].name);
                break;
            case 2:
                printf("\t\t\t\t\t�������޸ĺ������:");
                scanf("%d",&G[i].weight);
                break;
            case 3:
                printf("\t\t\t\t\t�������޸ĺ�ĳ���:");
                scanf("%s",G[i].length);
                break;
            case 4:
                printf("\t\t\t\t\t�������޸ĺ�Ŀ��:");
                scanf("%s",G[i].width);
                break;
            case 5:
                printf("\t\t\t\t\t�������޸ĺ�ĸ߶�:");
                scanf("%s",G[i].height);
                break;
            default:
                printf("\t\t\t\t\t��������ȷ�����:");
                break;
            }
            printf("\t\t\t\t\t�����޸�������1���˳�������0:");
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
        printf("\t\t\t\t\t**���޴˺�**\n");
        printf("\t\t\t\t\t************\n\n");
    } 
}

int SaveFromFile(int l)  //��������
{
    FILE*fp;
	int i=0;
	fp=fopen("goods.txt","w");
	if(fp==NULL)
	{
		printf("\t\t\t\t\t**********************************************\n");
	    printf("\t\t\t\t\t**                                          **\n");
	    printf("\t\t\t\t\t**            ���ݱ���ʧ�ܣ�����           **\n");
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