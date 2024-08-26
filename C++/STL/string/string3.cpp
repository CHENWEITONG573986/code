#include <iostream>
#include <string>
using namespace std;

// string的查找和替换

// 查找
void test01()
{
    string str1 = "abcdefgde";
    string str2 = "de";
    // find从左往右查
    int pos = str1.find(str2);
    cout << pos << endl;
    // rfind从右往左查
    pos = str1.rfind(str2);
    cout << pos << endl;
}

// 替换
void test02()
{
    string str1 = "abcdefg";
    str1.replace(1, 3, "123");
    cout << str1 << endl;
    // 替换所有
    str1.replace(str1.begin(), str1.end(), "123");
    cout << str1 << endl;
    // 替换n个
    str1.replace(1, 3, "123", 2);
    cout << str1 << endl;
}

int main()
{
    test01();
    test02();
    return 0;
}