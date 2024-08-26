#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int a;
    cin >> a;
    int day = 2;
    if (a == 1)
    {
        cout << "1" << endl;
        return 0;
    }
    while (true)
    {
        a = floor(a / 2);
        if (a == 1)
        {
            break;
        }
        day++;
    }
    cout << day;
    return 0;
}