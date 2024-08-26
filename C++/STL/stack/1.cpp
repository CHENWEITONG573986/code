#include <iostream>
#include <stack>
using namespace std;
/*
stack容器-栈
*/
void test01()
{
    stack<int> s;
    // 入栈
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    // 出栈
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop(); 
    }
}


int main()
{
    test01();
    return 0;
}