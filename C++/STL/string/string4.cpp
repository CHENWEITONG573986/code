#include <iostream>
#include <string>
using namespace std;
// string的比较
void test01()
{
    string str1 = "hello";
    string str2 = "hello";
    if (str1 == str2)
    {
        cout << "st1 == st2" << endl;
    }
    if (str1.compare(str2) == 0)
    {
        cout << "st1 == st2" << endl;
    }
}

void test02()
{
    // string的单个字符存取
    string str = "hello";
    // 通过[]访问
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i] << " ";
    }
    cout << endl;
    // 通过at()访问
    for (int i = 0; i < str.size(); i++)
    {
        cout << str.at(i) << " ";
    }
    cout << endl;

    // 对单个字符的修改
    str[0] = 'x';
    cout << str << endl;
    str.at(1) = 'x';
    cout << str << endl;
}

void test03()
{
    string str = "hello";
    // 字符串插入
    str.insert(1, "111");
    cout << str << endl;
    // 字符串删除
    str.erase(5, 1);
    cout << str << endl;
}

void test04()
{
    // string求子串
    string str = "hello";
    string subStr = str.substr(1, 3);
    cout << subStr << endl;
}

void test05()
{
    string str = "qinkili@126.com";
    int pos = str.rfind('@');
    string str1;
    str1 = str.substr(0, pos);
    cout << str1 << endl;
}
int main()
{
    test01();
    test02();
    test03();
    test04();
    test05();
    return 0;
}