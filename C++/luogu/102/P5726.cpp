#include <iostream>
#include <set>
using namespace std;
int main()
{
    int n, x;
    double sum = 0, Average;
    multiset<int> S;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        S.insert(x);
        sum += x;
    }
    sum = sum - *S.begin() - *S.rbegin();
    Average = sum / (S.size() - 2);
    printf("%.2f", Average);
    return 0;
}