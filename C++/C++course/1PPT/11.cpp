#include <iostream>
using namespace std;
void fun(int a = 1, int b = 3, int c = 5)
{
    cout << "a=" << a << ","
         << "b=" << b << ","
         << "c=" << c << endl;
}
int main()
{
    fun();
    fun(7);
    fun(7, 9);
    fun(7, 9, 11);
    cout << "OK";
    return 0;
}
