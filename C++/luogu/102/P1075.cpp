#include <iostream>
#include <cmath>
using namespace std;
// 函数用于找出两个质数中较大的那个
int findLargerPrime(int n)
{
    for (int i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            // 如果i是n的因子，那么n/i也应该是n的另一个因子
            // 由于i从2开始递增，n/i将比i大或等于i
            // 因为n是两个质数的乘积，所以n/i将比i大
            // 返回较大的因子，即n/i
            return n / i;
        }
    }
    return n; // 如果n是质数，返回n本身
}

int main()
{
    int n;
    cin >> n;
    cout << findLargerPrime(n) << endl;
    return 0;
}