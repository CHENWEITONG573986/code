#include <iostream>
using namespace std;
int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if ((a + b) + c == d)
        cout << "yes";
    else if ((a + b) - c == d)
        cout << "yes";
    else if ((a + b) * c == d)
        cout << "yes";
    else if ((a - b) - c == d)
        cout << "yes";
    else if ((a - b) + c == d)
        cout << "yes";
    else if ((a - b) * c == d)
        cout << "yes";
    else if ((a * b) * c == d)
        cout << "yes";
    else if ((a * b) + c == d)
        cout << "yes";
    else if ((a * b) - c == d)
        cout << "yes";
    else
        cout << "No";
    return 0;
}