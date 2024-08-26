#include <iostream>
using namespace std;

int fn()
{
    static int n;
    n++;
    return n;
}

int main()
{
    int n;
    for (int i = 0; i < 10; i++)
    {
        n = fn();
    }
    cout << n << endl;
    system("pause");
    return 0;
}