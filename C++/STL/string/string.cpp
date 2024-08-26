#include <iostream>
#include <string>
using namespace std;

void test01()
{
    int n = 10;
    // string的构造函数的原型
    // string();
    // string(const string& str);
    // string(const char* s);
    // string(int n, char c);

    string s1;          // 空字符串
    string s2(s1);      // s2是s1的副本
    string s3("hello"); // s3是直接初始化的，内容是"hello"
    string s4(n, 'c');  // s4是直接初始化的，内容是n个字符'c'

    
}
void test02()
{
    // string的赋值函数的原型
    // string& operator=(const string& str);
    // string& operator=(const char* s);
    // string& operator=(char c);
    // string& assign(const string& str);
    // string& assign(const char* s);
    // string& assign(size_t n, char c);
    // string& assign(const char* s, size_t n);
    string s1;
    s1 = "hello world";
    cout << s1 << endl;

    string s2;
    s2 = s1;
    cout << s2 << endl;

    string s3;
    s3 = 'a';
    cout << s3 << endl;

    string s4;
    s4.assign("hello world");
    cout << s4 << endl;

    string s5;
    s5.assign("hello world", 5);
    cout << s5 << endl;

    string s6;
    s6.assign(10, 'a');
    cout << s6 << endl;

    string s7;
    s7.assign(s1);
    cout << s7 << endl;

    
}
int main()
{
    test01();
    test02();
    return 0;
}