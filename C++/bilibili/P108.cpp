#include <iostream>
using namespace std;
// 拷贝构造函数的调用时机


class Person
{
public:
    Person()
    {
        cout << "无参" << endl;
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
        cout << "解析" << endl;
    }
    int geyAge()
    {
        return age;
    }

private:
    int age;
};
// 1.用一个已经创建完毕的对象来初始化一个新的对象
void test01()
{
    Person p1(10);
    Person p2(p1);
    cout << "p2=" << p2.geyAge() << endl;
}
// 2.值传递的方式给函数参数传值
void sss(Person p)
{

}
void test02()
{
    Person p1;
    sss(p1);
}
// 3.值方式返回局部对象
Person qqq()
{
    Person p1(10);
    cout<<(int*)&p1<<endl;
    return p1;
}
void test03()
{
    Person p=qqq();
    cout<<p.geyAge()<<endl;
    cout<<(int*)&p<<endl;
}
int main()
{
    //test01();
    //test02();
    test03();
}