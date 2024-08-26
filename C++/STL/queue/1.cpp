#include <iostream>
#include <queue>
using namespace std;
// queue容器-队列
void test01()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    while (!q.empty())
    {
        cout<<"队头："<<q.front()<<endl;
        cout<<"队尾："<< q.back()<<endl;
        q.pop();
    }
}


int main()
{
    test01();
    return 0;
}