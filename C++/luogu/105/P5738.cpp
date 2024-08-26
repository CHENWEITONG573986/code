#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    set<double> Score;
    for (int i = 0; i < n; i++)
    {
        set<int> Num;
        double sum = 0;
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            Num.insert(x);
            sum += x;
        }
        sum -= *Num.begin();
        sum -= *Num.rbegin();
        Score.insert(sum / (m - 2));
    }
    printf("%.2f",*Score.rbegin());
    return 0;
}