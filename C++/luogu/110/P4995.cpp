#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
deque<int> D;

int main()
{
    cin >> n;
    D.resize(n);
    for (int i = 0; i < n; i++)
        cin >> D[i];
    sort(D.begin(), D.end());
    long long sum = 0;
    sum += pow(D.back(), 2);
    while (D.size() > 1)
    {
        sum += pow(D.back() - D.front(), 2);
        if ((n - D.size()) % 2 == 0)
            D.pop_back();
        else
            D.pop_front();
    }
    cout << sum;
    return 0;
}