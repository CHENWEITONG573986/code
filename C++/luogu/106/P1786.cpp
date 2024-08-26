#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 人物
class Person
{
public:
    // 姓名
    string m_Name;
    // 职位
    string m_Position;
    // 帮贡
    int m_Contribute;
    // 等级
    int m_Level;
};
class MyLevel
{
public:
    bool operator()(const Person &A, const Person &B)
    {
        return A.m_Level > B.m_Level;
    }
};
class MyContribute
{
public:
    bool operator()(const Person &A, const Person &B)
    {
        return A.m_Contribute > B.m_Contribute;
    }
};
// 帮派
class Gang
{
public:
    // 人数
    int num;
    // 帮主
    multiset<Person, MyLevel> BangZhu;
    // 副帮主
    multiset<Person, MyLevel> FuBangZhu;
    // 护法
    multiset<Person, MyLevel> HuFa;
    // 长老
    multiset<Person, MyLevel> ZhangLao;
    // 堂主
    multiset<Person, MyLevel> TangZhu;
    // 精英
    multiset<Person, MyLevel> JingYing;
    // 帮众
    multiset<Person, MyLevel> BangZhong;

public:
    void print()
    {
        for (auto set : {BangZhu, FuBangZhu, HuFa, ZhangLao, TangZhu, JingYing, BangZhong})
            for (auto c : set)
                cout << c.m_Name << " " << c.m_Position << " " << c.m_Level << endl;
    }
};
int main()
{
    Gang G;
    cin >> G.num;
    multiset<Person, MyContribute> S;
    for (int i = 0; i < G.num; i++)
    {
        Person P;
        cin >> P.m_Name >> P.m_Position >> P.m_Contribute >> P.m_Level;
        if (P.m_Position == "BangZhu")
            G.BangZhu.insert(P);
        else if (P.m_Position == "FuBangZhu")
            G.FuBangZhu.insert(P);
        else
            S.insert(P);
    }
    for (auto c : S)
    {
        // cout << c.m_Name << " " << c.m_Position << " " << c.m_Contribute << endl;
        if (G.HuFa.size() < 2)
        {
            c.m_Position = "HuFa";
            G.HuFa.insert(c);
        }
        else if (G.ZhangLao.size() < 4)
        {
            c.m_Position = "ZhangLao";
            G.ZhangLao.insert(c);
        }
        else if (G.TangZhu.size() < 7)
        {
            c.m_Position = "TangZhu";
            G.TangZhu.insert(c);
        }
        else if (G.JingYing.size() < 25)
        {
            c.m_Position = "JingYing";
            G.JingYing.insert(c);
        }
        else
        {
            c.m_Position = "BangZhong";
            G.BangZhong.insert(c);
        }
    }
    G.print();
    return 0;
}