#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = n; i >= 0; i--)
    {
        cin >> a[i];
        if (a[i])
        {
            if (i != n && a[i] > 0)
                cout << "+";
            if (a[i] != 1 && a[i] != -1 || i == 0)
                cout << a[i];
            if (a[i] == -1 && i)
                cout << "-";
            if (i > 1)
                cout << "x^" << i;
            if (i == 1)
                cout << "x";
        }
    }
    return 0;
}