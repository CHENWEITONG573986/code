#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, num = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (num < 10)
            {
                cout << "0" << num;
            }
            else
            {
                cout << num;
            }
            num++;
        }
        cout << endl;
    }
    cout << endl;
    num = 1;
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < 2*(n-i-1); k++)
        {
            cout << " ";
        }
        for (int j = 0; j <= i; j++)
        {
            if (num < 10)
            {
                cout << "0" << num;
            }
            else
            {
                cout << num;
            }
            num++;
        }
        cout << endl;
    }
}