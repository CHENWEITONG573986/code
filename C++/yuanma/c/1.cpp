#include <iostream>
using namespace std;
class A
{
public:
    int a=1;
};
class B : public A
{
public:
    int a=2;
};
int main()
{
    B b;
    cout<<b.a;
}
