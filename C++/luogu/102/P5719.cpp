#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>
using namespace std;
int main()
{
    int n, k, sum_A, sum_B;
    vector<int> A, B;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        if (i % k == 0)
        {
            A.push_back(i);
        }
        else
        {
            B.push_back(i);
        }
    }
    sum_A = accumulate(A.begin(), A.end(), 0);
    sum_B = accumulate(B.begin(), B.end(), 0);
    cout << fixed << setprecision(1) << (float)sum_A / A.size() << " ";
    cout << fixed << setprecision(1) << (float)sum_B / B.size() << endl;
}