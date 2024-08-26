#include <iostream>
using namespace std;
int main()
{
    int n, a = 0, b = 0, x = 0, k = 0, sum;
    cin >> n;
    for (int i = 0; i < 52; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            a++;
            b += j;
        }
    }
    while (true)
    {
        k++;
        while (true)
        {
            if (a * x + b * k == n)
            {
                cout << x << endl;
                cout << k << endl;
                return 0;
            }
            x++;
        }
    }
}