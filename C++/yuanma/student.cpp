#include<iostream>
#include<string>
using namespace std;

struct student
{
    string name;
    int scores;
};

struct teacher
{
    string name;
    student s[5];
};

void scf(teacher *t)
{
    for(int i=0;i<3;i++)
    {
        cout << "请输入第" << i << "个老师的名字" << endl;
        cin >> t[i].name;
        for(int j=0;j<5;j++)
        {
            cout << "请输入第" << j << "个学生的名字" << endl;
            cin >> t[i].s[j].name;
            cout << "亲输入该学生的分数：";
            cin >> t[i].s[j].scores;
        }
    }
}

void print(teacher t[])
{
    for(int i=0;i<3;i++)
    {
        cout << t[i].name << endl;
        for(int j=0;j<5;j++)
        {
            cout << t[i].s[j].name << " ";
            cout << t[i].s[j].scores << endl;
        }
    }
}

int main()
{
    teacher t[3];
    scf(t);
    print(t);
}