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

void get3(int a, int b)
{
    int d1, d2, palindrome;
    for (d1 = 1; d1 <= 9; d1 += 2)
    {
        for (d2 = 0; d2 <= 9; d2++)
        {
            palindrome = 100 * d1 + 10 * d2 + d1;
            if (isPrime(palindrome) && palindrome >= a && palindrome <= b)
            {
                cout << palindrome << endl;
            }
        }
    }
}
void get4(int a, int b)
{
    int d1, d2, palindrome;
    for (d1 = 1; d1 <= 9; d1 += 2)
    {
        for (d2 = 0; d2 <= 9; d2++)
        {
            palindrome = 1000 * d1 + 100 * d2 + 10 * d2 + d1;
            if (isPrime(palindrome) && palindrome >= a && palindrome <= b)
            {
                cout << palindrome << endl;
            }
        }
    }
}
void get5(int a, int b)
{
    int d1, d2, d3, palindrome;
    for (d1 = 1; d1 <= 9; d1 += 2)
    { // 只有奇数才会是素数
        for (d2 = 0; d2 <= 9; d2++)
        {
            for (d3 = 0; d3 <= 9; d3++)
            {
                palindrome = 10000 * d1 + 1000 * d2 + 100 * d3 + 10 * d2 + d1; //(处理回文数...)
                if (isPrime(palindrome) && palindrome >= a && palindrome <= b)
                {
                    cout << palindrome << endl;
                }
            }
        }
    }
}
void get6(int a, int b)
{
    int d1, d2, d3, palindrome;
    for (d1 = 1; d1 <= 9; d1 += 2)
    { // 只有奇数才会是素数
        for (d2 = 0; d2 <= 9; d2++)
        {
            for (d3 = 0; d3 <= 9; d3++)
            {
                palindrome = 100000 * d1 + 10000 * d2 + 1000 * d3 + 100 * d3 + 10 * d2 + d1; //(处理回文数...)
                if (isPrime(palindrome) && palindrome >= a && palindrome <= b)
                {
                    cout << palindrome << endl;
                }
            }
        }
    }
}

void get7(int a, int b)
{
    int d1, d2, d3, d4, palindrome;
    for (d1 = 1; d1 <= 9; d1 += 2)
    { // 只有奇数才会是素数
        for (d2 = 0; d2 <= 9; d2++)
        {
            for (d3 = 0; d3 <= 9; d3++)
            {
                for (d4 = 0; d4 <= 9; d4++)
                {
                    palindrome = 1000000 * d1 + 100000 * d2 + 10000 * d3 + 1000 * d4 + 100 * d3 + 10 * d2 + d1; //(处理回文数...)
                    if (isPrime(palindrome) && palindrome >= a && palindrome <= b)
                    {
                        cout << palindrome << endl;
                    }
                }
            }
        }
    }
}

void get8(int a, int b)
{
    int d1, d2, d3, d4, palindrome;
    for (d1 = 1; d1 <= 9; d1 += 2)
    { // 只有奇数才会是素数
        for (d2 = 0; d2 <= 9; d2++)
        {
            for (d3 = 0; d3 <= 9; d3++)
            {
                for (d4 = 0; d4 <= 9; d4++)
                {
                    palindrome = 10000000 * d1 + 1000000 * d2 + 100000 * d3 + 10000 * d4 + 1000 * d4 + 100 * d3 + 10 * d2 + d1; //(处理回文数...)
                    if (isPrime(palindrome) && palindrome >= a && palindrome <= b)
                    {
                        cout << palindrome << endl;
                    }
                }
            }
        }
    }
}
int weishu(int n)
{
    int i = 1;
    while (true)
    {
        if (n / 10)
        {
            n /= 10;
            i++;
        }
        else
        {
            break;
        }
    }
    return i;
}

int main()
{
    int a, b;
    cin >> a >> b;
    int min = weishu(a);
    int max = weishu(b);
    if (min < 3)
    {
        if (5 >= a && 5 <= b)
        {
            cout << "5" << endl;
        }
        if (7 >= a && 7 <= b)
        {
            cout << "7" << endl;
        }
        if (11 >= a && 11 <= b)
        {
            cout << "11" << endl;
        }
    }
    if (max>=3)
    {
        switch (min)
        {
        case 1:
        case 2:
        case 3:
            get3(a, b);
            if (max == 3)
                break;
        case 4:
            get4(a, b);
            if (max == 4)
                break;
        case 5:
            get5(a, b);
            if (max == 5)
                break;
        case 6:
            get6(a, b);
            if (max == 6)
                break;
        case 7:
            get7(a, b);
            if (max == 7)
                break;
        case 8:
            get8(a, b);
            break;
        }
    }
}