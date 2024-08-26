#include <iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int n = 0, sum = 0;
    while (N > sum)
    {
        n++;
        sum += n;
    }
    if (n % 2 == 0)
        cout << n - sum + N << "/" << sum - N + 1 << endl;
    else
        cout << sum - N + 1 << "/" << n - sum + N << endl;
    return 0;
}