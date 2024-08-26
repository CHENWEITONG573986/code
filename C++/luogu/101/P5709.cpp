#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int m;
    double t, s;
    cin >> m >> t >> s;
    if (t != 0)
    {
        if (m - ceil(s / t) > 0)
            cout << m - ceil(s / t) << endl;
        else
            cout << "0" << endl;
    }
    else
        cout << "0" << endl;
    return 0;
}