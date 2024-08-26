#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    int N;
    cin >> N;
    for (int i = 4; i <= N; i += 2)
    {
        for (int j = 2; j <= N / 2; j++)
        {
            if (isPrime(j))
            {
                if (isPrime(i - j))
                {
                    cout << i << "=" << j << "+" << i - j << endl;
                    break;
                }
            }
        }
    }
    return 0;
}