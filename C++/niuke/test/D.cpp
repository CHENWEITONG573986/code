#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int n;
long long *num;
int COUNT = 0;
void jump(int id, int x)
{
    if (id == n)
    {
        COUNT = min(COUNT, x);
        }
    x++;
    jump(id + 1, x);
    for (int i = 2; i <= num[id]; i++)
    {
        if (num[id] % i == 0)
        {
            jump(id + i, x);
        }
    }
    return;
}

int main()
{
    cin >> n;
    COUNT = n;
    num = new long long[n];
    for (int i = 0; i < n; i++)
        cin >> num[i];
    jump(1, 1);
}