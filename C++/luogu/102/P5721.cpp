#include <iostream>
using namespace std;
int main()
{
    int n, a = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i; j++)
        {
            if (a < 10)
            {
                cout << "0" << a;
            }
            else
            {
                cout << a;
            }
            a++;
        }
        cout << endl;
    }
}