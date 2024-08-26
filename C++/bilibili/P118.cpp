#include<iostream>
#include<string>
using namespace std;

class Person
{
    friend void sss(Person &p); //友元声明
private:
    string name="MeatyBio";
};

void sss(Person &p)
{
    cout << p.name << endl;
}

int main()
{
    Person p1;
    sss(p1);
}