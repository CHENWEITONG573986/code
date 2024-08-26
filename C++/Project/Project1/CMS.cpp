#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#define MAX 1000
using namespace std;
struct Friends
{
    string name;
    string sex;
    int age;
    int num;
    string address;
};
Friends F[MAX];
int Num=0;
string password;

void Read()
{
    ifstream ifs;
    ifs.open("data.txt",ios::in);
    if(!ifs.is_open())
    {
        cout << "数据读取失败" << endl;
        return;
    }
    int i=0;
    while(ifs>>F[i].name && ifs>>F[i].sex && ifs>>F[i].age && ifs>>F[i].num && ifs>>F[i].address)
    {
        i++;
        Num++;
    }
    ifs.close();
    ifs.open("password.txt",ios::in);
    if(!ifs.is_open())
    {
        cout << "密码读取失败" << endl;
        return;
    }
    ifs >> password;
    ifs.close();
}

void Save()
{
    ofstream ofs;
    ofs.open("data.txt",ios::out);
    for(int i=0;i<Num;i++)
    {
        ofs << F[i].name << "\t";
        ofs << F[i].sex  << "\t";
        ofs << F[i].age  << "\t";
        ofs << F[i].num  << "\t";
        ofs << F[i].address;
        if(i!=Num-1) ofs << "\n";
    }
    ofs.close();
}

void Home()
{
    cout << "\t\t\t\t\t**********************************************" << endl;
	cout << "\t\t\t\t\t**----------武汉纺织大学外经贸学院----------**" << endl;
	cout << "\t\t\t\t\t**********************************************" << endl;
	cout << "\t\t\t\t\t**                                          **" << endl;
	cout << "\t\t\t\t\t**             联系人通讯录系统             **" << endl;
	cout << "\t\t\t\t\t**                                          **" << endl;
	cout << "\t\t\t\t\t**********************************************" << endl;
	cout << "\t\t\t\t\t**           欢迎使用,祝您使用愉快          **" << endl;
	cout << "\t\t\t\t\t**********************************************" << endl;
	cout << "\t\t\t\t\t**   制作者：陈维桐    学号：230103040616   **" << endl;
	cout << "\t\t\t\t\t**   学院：工程学院    班级：计科2306班     **" << endl;
	cout << "\t\t\t\t\t**********************************************\n" << endl;
}

int Login()
{   
    string A;
    for(int i=0;i<3;i++)
    {
        cout << "请输入密码(初始密码:2005):";
        cin >> A;
        if(A==password)
        {
            cout << "密码正确，登录成功" << endl;
            system("pause");
            system("cls");
            return 0;
        }
        else
        {
            if(i!=2)
                cout << "密码错误，你还有" << 2-i << "次机会" << endl;
            else
                cout << "密码错误，登录失败" << endl;
        }
    }
    return 1;
}

void menu()
{
    cout << "\t\t\t\t\t**********************************************" << endl;
	cout << "\t\t\t\t\t**                                          **" << endl;
	cout << "\t\t\t\t\t**              欢迎使用本系统              **" << endl;
	cout << "\t\t\t\t\t**                                          **" << endl;
	cout << "\t\t\t\t\t**********************************************" << endl;
	cout << "\t\t\t\t\t**-----------------功能菜单-----------------**" << endl;
	cout << "\t\t\t\t\t**         添加联系人 ------------1         **" << endl;
	cout << "\t\t\t\t\t**         显示联系人 ------------2         **" << endl;
	cout << "\t\t\t\t\t**         删除联系人 ------------3         **" << endl;
	cout << "\t\t\t\t\t**         查找联系人 ------------4         **" << endl;
	cout << "\t\t\t\t\t**         修改联系人 ------------5         **" << endl;
	cout << "\t\t\t\t\t**         清空联系人 ------------6         **" << endl;
    cout << "\t\t\t\t\t**         修改登录码 ------------7         **" << endl;
	cout << "\t\t\t\t\t**         退出通讯录 ------------0         **" << endl;
	cout << "\t\t\t\t\t**********************************************\n" << endl;
}

void AddFriends()
{
    cout << "请输入您要添加的联系人姓名：" << endl;
    string A;
    cin >> A;
    for(int i=0;i<Num;i++)
    {
        if(F[i].name==A)
        {
            cout << "添加重复" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
    F[Num].name=A;
    cout << "请输入性别：" << endl;
    cin >> F[Num].sex;
    cout << "亲输入年龄：" << endl;
    cin >> F[Num].age;
    cout << "亲输入电话号码：" << endl;
    cin >> F[Num].num;
    cout << "请输入住址：" << endl;
    cin >> F[Num].address;
    cout << "添加成功" << endl;
    Num++;
    Save();
    system("pause");
    system("cls");
}

void Display()
{
    for(int i=0;i<Num;i++)
    {
        cout<< F[i].name << "\t"
            << F[i].sex  << "\t"
            << F[i].age  << "\t"
            << F[i].num  << "\t"
            << F[i].address << endl;
    }
    system("pause");
    system("cls");
    return;
}

void Delete()
{
    string A;
    cout << "请输入你要删除的联系人：";
    cin >> A;
    for(int i=0;i<Num;i++)
    {
        if(F[i].name==A)
        {
            cout << "查询到的信息如下" << endl;
            cout<< F[i].name << "\t"
                << F[i].sex << "\t"
                << F[i].age << "\t"
                << F[i].num << "\t"
                << F[i].address << endl;
            cout << "确认要删除此数据(是1,否0):";
            int a;
            cin >> a;
            if(a)
            {
                for(int j=i;j<Num-1;j++)
                {
                    F[j].name=F[j+1].name;
                    F[j].sex=F[j+1].sex;
                    F[j].age=F[j+1].age;
                    F[j].num=F[j+1].num;
                    F[j].address=F[j+1].address;
                }
                Num--;
                cout << "删除成功" << endl;
                Save();
            }
            system("pause");
            system("cls");
            return;
        }
    }
    cout << "查无此人" << endl;
    system("pause");
    system("cls");
    return;
}

void Find()
{
    string A;
    cout << "请输入你要查找的联系人：";
    cin >> A;
    for(int i=0;i<Num;i++)
    {
        if(F[i].name==A)
        {
            cout << "查询到的信息如下" << endl;
            cout<< F[i].name << "\t"
                << F[i].sex << "\t"
                << F[i].age << "\t"
                << F[i].num << "\t"
                << F[i].address << endl;
            system("pause");
            system("cls");
            return;
        }
    }
    cout << "查无此人" << endl;
    system("pause");
    system("cls");
    return;
}

void Revise()
{
    string A;
    cout << "请输入你要修改的联系人：";
    cin >> A;
    for(int i=0;i<Num;i++)
    {
        if(F[i].name==A)
        {
            cout << "查询到的信息如下" << endl;
            cout<< F[i].name << "\t"
                << F[i].sex << "\t"
                << F[i].age << "\t"
                << F[i].num << "\t"
                << F[i].address << endl;
            cout << "请输入修改的数据" << endl;
            cout << "请输入性别：" << endl;
            cin >> F[i].sex;
            cout << "亲输入年龄：" << endl;
            cin >> F[i].age;
            cout << "亲输入电话号码：" << endl;
            cin >> F[i].num;
            cout << "请输入住址：" << endl;
            cin >> F[i].address;
            system("pause");
            system("cls");
            return;
        }
    }
    cout << "查无此人" << endl;
    system("pause");
    system("cls");
    return;
}

void Remove()
{
    cout << "是否要清空联系人(是1,否0)" << endl;
    int a;
    cin >>a;
    if(a)
    {
        ofstream ofs;
        ofs.open("data.txt",ios::trunc);
        ofs.close();
        cout << "清除成功" << endl;
    }
    system("pause");
    system("cls");
    return;
}

void Password()
{
    string A;
    for(int i=0;i<3;i++)
    {
        cout << "请输入原始密码:";
        cin >> A;
        if(A==password)
        {
            cout << "密码正确" << endl;
            cout << "请输入新的密码：";
            cin >> password;
            ofstream ofs;
            ofs.open("password.txt",ios::out);
            ofs << password;
            ofs.close();
            cout << "修改成功" << endl;
            system("pause");
            system("cls");
            return;
        }
        else
        {
            if(i!=2)
                cout << "密码错误，你还有" << 2-i << "次机会" << endl;
            else
                cout << "密码错误，修改失败" << endl;
        }
    }
    return;
}

void Out()
{
    cout << "\t\t\t\t\t**********************************************" << endl;
	cout << "\t\t\t\t\t**                                          **" << endl;
	cout << "\t\t\t\t\t**        欢迎下次使用！~再见！~~           **" << endl;
	cout << "\t\t\t\t\t**                                          **" << endl;
	cout << "\t\t\t\t\t**********************************************" << endl;
}

int main()
{
    Home();
    Read();
    int m;
    m=Login();
    if(m)
        return 0;
    while(1)
    {
        menu();
        cout << "请输入指令序号:";
        int a;
        cin >> a;
        switch(a)
        {
            case 1:AddFriends();break;
            case 2:Display();break;
            case 3:Delete();break;
            case 4:Find();break;
            case 5:Revise();break;;
            case 6:Remove();break;
            case 7:Password();break;
            case 0:Out();return 0;
        }
    }
}