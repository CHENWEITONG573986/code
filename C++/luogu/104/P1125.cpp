#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

bool isPrime(int n)
{
    if (n < 2)
    {
        return false;
    }
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string word;
    cin >> word;
    map<char, int> count;
    for (char c : word)
    {
        count[c]++;
    }
    set<int> num;
    for (auto pair : count)
    {
        num.insert(pair.second);
    }
    int maxn = *num.rbegin();
    int minn = *num.begin();
    if (isPrime(maxn - minn))
    {
        cout << "Lucky Word" << endl;
        cout << maxn - minn << endl;
    }
    else
    {
        cout << "No Answer" << endl;
        cout << "0" << endl;
    }
    return 0;
}