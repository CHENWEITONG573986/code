#include <iostream>
#include <set>
using namespace std;
class Person
{
public:
    string m_Name;
    int m_Age;
    int m_Height;

public:
    Person(string name, int age, int height)
        : m_Name(name), m_Age(age), m_Height(height){};
};

class MyCompare
{
public:
    bool operator()(Person a, Person b)
    {
        return a.m_Age < b.m_Age;
    }
};

void printSet(const set<Person, MyCompare> &S)
{
    for (set<Person, MyCompare>::const_iterator it = S.begin(); it != S.end(); it++)
    {
        cout << "姓名：" << it->m_Name << "\t年龄：" << it->m_Age << "\t身高：" << it->m_Height << endl;
    }
    cout << endl;
}

void test01()
{
    set<Person, MyCompare> S;
    Person p1("蔡徐坤", 25, 250);
    Person p2("马嘉祺", 21, 210);
    Person p3("丁真", 18, 180);
    Person p4("王源", 22, 220);
    S.insert(p1);
    S.insert(p2);
    S.insert(p3);
    S.insert(p4);
    printSet(S);
}

int main()
{
    test01();
    return 0;
}