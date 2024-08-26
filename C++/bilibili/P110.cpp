#include <iostream>
using namespace std;
// 深拷贝与浅拷贝
// 1.浅拷贝，默认生成的拷贝构造函数，直接值传递
class Person
{
public:
    Person()
    {
        cout << "默认" << endl;
    }
    Person(int a, int b)
    {
        age = a;
        height = new int(b); // 在堆区开辟内存，存放身高的值，并将此地址存入指针height
        cout << "有参" << endl;
    }
    Person(const Person &p) //深拷贝
    {
        age=p.age;
        //height=p.height; 系统生成 浅拷贝
        height= new int(*p.height); //深拷贝
    }
    ~Person()
    {
        if (height != NULL)
        {
            delete height; // 浅拷贝的问题就是堆区的内存重复释放
            height = NULL;
        }
        cout << "析构" << endl;
    }

    int age;
    int *height;
};

void test01()
{
    Person p1(18, 160);
    Person p2(p1);
    cout << p2.age << endl;
    cout << *p2.height << endl;
}
int main()
{
    test01();
}