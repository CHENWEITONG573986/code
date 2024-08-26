#include <iostream>
#include <list>
#include <string>
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
void printList(const list<Person> &L)
{
    for (list<Person>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout << "姓名：" << it->m_Name << "\t年龄：" << it->m_Age << "\t身高：" << it->m_Height << endl;
    }
}

// 排序规则
bool myCompare(Person a, Person b)
{
    if(a.m_Age = b.m_Age)
    {
        return a.m_Height < b.m_Height;
    }
    else
    {
        return a.m_Age < b.m_Age;
    }
}
void test01()
{
    list<Person> L;
    Person p1("蔡徐坤", 25, 250);
    Person p2("马嘉祺", 21, 210);
    Person p3("丁真", 18, 180);
    Person p4("王源", 22, 220);
    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);
    L.push_back(p4);
    printList(L);
    cout<<endl;
    L.sort(myCompare);
    printList(L);
}
int main()
{
    test01();
    return 0;
}