#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
    //设置姓名
    void setName(string a)
    {
        name=a;
    }
    //读取姓名
    string getName()
    {
        return name;
    }
    //读取年龄
    int getAge()
    {
        return age;
    }
    //设置密码
    void setPassword(int a)
    {
        password=a;
    }
private:
    string name;  // 可读可写
    int age=18;      // 只读
    int password; // 只写
};

int main()
{
    //1.将所有成员设置私有，可以自己控制读写权限。
    //2.对于写权限我们可以检测数据有效性
    Person p1;
    p1.setName("MeatyBio");
    cout << p1.getName() << endl;
    cout << p1.getAge() << endl;
    p1.setPassword(12345);
    return 0;
}