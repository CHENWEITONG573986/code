#include <iostream>
using namespace std;


class Person
{
public:
    Person()
    {
        cout << "默认" << endl;
    }
    Person(int a,int b,int c,int d):a(a),b(b),c(c),d(d) //初始化列表
    {
        
        cout << "有参" << endl;
    }

    ~Person()
    {
        cout << "析构" << endl;
    }

    int a,b,c,d;

};

int main()
{
}