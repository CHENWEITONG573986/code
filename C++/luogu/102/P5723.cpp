#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
    {
        return false; // 排除小于等于1的数，它们不是质数
    }
    if (n <= 3)
    {
        return true; // 2和3是最小的两个质数
    }
    if (n % 2 == 0 || n % 3 == 0)
    {
        return false; // 排除能被2或3整除的数
    }
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false; // 检查i和i+2是否为n的因数
        }
    }
    return true; // 如果没有找到其他因数，n是质数
}

int main()
{
    int L;
    cin >> L;
    int sum = 0, i = 0, n = 0;
    while (true)
    {
        while (!isPrime(i))
        {
            i++;
        }
        sum += i;
        n++;
        if (sum <= L)
        {
            cout << i << endl;
        }
        else
        {
            break;
        }
        i++;
    }
    cout << --n << endl;
}