#include <iostream>
using namespace std;
int main()
{
    int n, x, num = 0;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        int j = i;
        while (j)
        {
            if (j % 10 == x)
            {
                num++;
            }
            j /= 10;
        }
    }
    cout << num;
    return 0;
}