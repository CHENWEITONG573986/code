#include <iostream>
#include <string>
using namespace std;

// string的追加函数原型
// string& operator+=(const string& str);
// string& operator+=(const char* str);
// string& operator+=(char c);
// string& append(const char* s);
// string& append(const char* s, int n);
// string& append(const string& s);
// string& append(const string& s, int pos, int n);

void test01()
{
    string str1 = "我";
    str1 += "爱中国";
    cout << str1 << endl;

    str1 += ',';
    cout << str1 << endl;

    string str2 = "我爱中国";
    str1 += str2;
    cout << str1 << endl;

    str1.append(",我爱中国");
    cout << str1 << endl;

    str1.append(", 我爱中国", 1);
    cout << str1 << endl;

    str1.append(str2);
    cout << str1 << endl;

    str1.append(str2, 2, 2);
    cout << str1 << endl;
}

int main()
{
    test01();
    return 0;
}