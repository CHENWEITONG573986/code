#include <iostream>
using namespace std;
template <typename T1, typename T2>
int max(T1 a, T2 b)
{
    if (a > b)
        return a;
    else
        return b;
}
int main()
{
    int a = 4.5, c;
    float b = 3.5;
    c = max(a, b);
    cout << "max is " << c << endl;
    return 0;
}
