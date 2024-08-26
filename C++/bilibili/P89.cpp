#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    int &b = a;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    int c = 20;
    b = c;
    cout << "a=" << a << endl;
    system("pause");
    return 0;
}