#include<iostream>
#include<string>
using namespace std;

class Person
{
public: // 公共权限 类内可以访问，类外可以访问
    string name;
protected: // 保护权限 类内可以访问，类外不可以访问（特殊情况可以访问）
    string car;
private: // 私有权限 类内可以访问，类外不可以访问
    int password;
};

int main()
{
    Person p1;
    p1.name="MertyBio";
    //p1.car="benchi";
    //p1.password=123;
    return 0;
}