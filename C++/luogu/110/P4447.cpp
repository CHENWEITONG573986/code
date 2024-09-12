#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
int n;
vector<int> Data;
vector<deque<int>> V;

bool MySort(const deque<int> &A, const deque<int> &B)
{
    return A.size() < B.size();
}

int main()
{
    cin >> n;
    Data.resize(n);
    for (int i = 0; i < n; i++)
        cin >> Data[i];
    sort(Data.begin(), Data.end());
    for (int i = 0; i < n; i++)
    {
        int k = 1;
        for (int j = 0; j < V.size(); j++)
        {
            if (Data[i] == V[j].front() - 1)
            {
                V[j].push_front(Data[i]);
                k = 0;
                break;
            }
            else if (Data[i] == V[j].back() + 1)
            {
                V[j].push_back(Data[i]);
                k = 0;
                break;
            }
        }
        if (k)
        {
            deque<int> d;
            d.push_back(Data[i]);
            V.push_back(d);
        }
        sort(V.begin(), V.end(), MySort);
    }
    cout << V.front().size();
    return 0;
}