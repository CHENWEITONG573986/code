#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Person
{
public:
    string m_Name;
    int m_Age;

public:
    Person(){};
    Person(string name, int age) : m_Name(name), m_Age(age){};
};

void test01()
{
    vector<Person> v;
    v.push_back(Person("Tom", 10));
    v.push_back(Person("Jerry", 20));
    v.push_back(Person("Mike", 30));
    v.push_back(Person("Jack", 40));
    v.push_back(Person("Tom", 50));
    v.push_back(Person("Jerry", 60));

    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "Name: " << it->m_Name << " Age: " << it->m_Age << endl;
    }
}

void test02()
{
    vector<Person *> v;
    Person p1("Tom", 10);
    Person p2("Jerry", 20);
    Person p3("Mike", 30);
    Person p4("Jack", 40);
    Person p5("Tom", 50);
    Person p6("Jerry", 60);
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);
    v.push_back(&p6);

    for (vector<Person *>::iterator it = v.begin(); it != v.end(); it++)
    {
        // cout << "Name: " << (*it)->m_Name << " Age: " << (*it)->m_Age << endl;
        cout << "Name: " << (*(*it)).m_Name << " Age: " << (*(*it)).m_Age << endl;
    }
}

int main()
{
    // test01();
    test02();
    return 0;
}