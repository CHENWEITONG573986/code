#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, B;
    cin >> N >> B;
    vector<int> V;
    V.resize(N);
    for (int i = 0; i < N; i++)
        cin >> V[i];
    sort(V.begin(), V.end());
    int sum = 0, count = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        sum += V[i];
        count++;
        if (sum >= B)
            break;
    }
    cout << count;
    return 0;
}
