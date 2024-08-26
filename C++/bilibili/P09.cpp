#include <iostream>
using namespace std;

// 构造函数的调用规则
// 1.创建一个类，c++编译器都会给每个类添加至少3个函数
// 默认构造（空）
// 析构函数（空）
// 拷贝构造（拷贝值）

class Person
{
public:
    Person()
    {
        cout << "默认" << endl;
    }
    Person(int a)
    {
        age = a;
        cout << "有参" << endl;
    }
    Person(const Person &p)
    {
        age = p.age;
        cout << "拷贝" << endl;
    }
    ~Person()
    {
        cout << "析构" << endl;
    }
    int getAge()
    {
        return age;
    }

private:
    int age;
};

int main()
{
}