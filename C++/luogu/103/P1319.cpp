#include <iostream>
using namespace std;
int main()
{
    int N, x = 1, sum = 0;
    cin >> N;
    int Matrix[N * N], Num = 0;
    while (sum != N * N)
    {
        int num;
        cin >> num;
        sum += num;
        if (x % 2 == 0)
        {
            for (int i = 0; i < num; i++)
            {
                Matrix[Num] = 1;
                Num++;
            }
        }
        else
        {
            for (int i = 0; i < num; i++)
            {
                Matrix[Num] = 0;
                Num++;
            }
        }
        x++;
    }
    for (int i = 0; i < N * N; i++)
    {
        cout << Matrix[i];
        if ((i + 1) % N == 0)
            cout << endl;
    }
    return 0;
}