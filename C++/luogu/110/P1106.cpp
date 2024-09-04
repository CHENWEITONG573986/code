#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int k;
string S, Min;

int main()
{
    cin >> S >> k;
    int begin = 0;
    int end = k + 1;
    while (Min.size() != S.size() - k)
    {
        vector<pair<char, int>> V;
        for (int j = begin; j < end; j++)
            V.push_back(make_pair(S[j], j));
        sort(V.begin(), V.end());
        Min.push_back(V.front().first);
        begin = V.front().second + 1;
        end++;
    }
    while (Min.front() == '0' && Min.size() > 1)
        Min.erase(Min.begin());
    cout << Min;
    return 0;
}