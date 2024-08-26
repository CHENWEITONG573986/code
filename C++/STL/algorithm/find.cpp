#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

void test01()
{
    vector<int> V;
    for (int i = 0; i < 10; i++)
    {
        V.push_back(i);
    }
    auto it = find(V.begin(), V.end(), 5);
    if (it == V.end())
    {
        cout << "没找到" << endl;
    }
    else
    {
        cout << *it << endl;
    }
}

class Person
{
public:
    string m_Name;
    int m_Age;

public:
    Person(string name, int age) : m_Name(name), m_Age(age) {}
    bool operator==(const Person& P)
    {
        if(this->m_Name==P.m_Name&&this->m_Age==P.m_Age)
            return true;
        else
            return false;
    }
};

void test02()
{
    vector<Person> V;
    Person p1("aaa", 11);
    Person p2("bbb", 12);
    Person p3("ccc", 13);
    Person p4("ddd", 14);
    Person p5("eee", 15);
    Person p6("fff", 16);
    Person p7("ggg", 17);
    V.push_back(p1);
    V.push_back(p2);
    V.push_back(p3);
    V.push_back(p4);
    V.push_back(p5);
    V.push_back(p6);
    V.push_back(p7);
    auto it = find(V.begin(), V.end(), p4);
    if (it == V.end())
    {
        cout << "没找到" << endl;
    }
    else
    {
        cout << it->m_Name << it->m_Age << endl;
    }
}

int main()
{
    test01();
    test02();
    return 0;
}