#include <iostream>
#include <map>
#include <cmath>
using namespace std;
int main()
{
    int S1, S2, S3;
    cin >> S1 >> S2 >> S3;
    map<int, int> M;
    for (int i = 1; i <= S1; i++)
    {
        for (int j = 1; j <= S2; j++)
        {
            for (int k = 1; k <= S3; k++)
            {
                auto pos = M.find(i + j + k);
                if (pos == M.end())
                {
                    M.insert(pair<int, int>(i + j + k, 1));
                }
                else
                {
                    pos->second++;
                }
            }
        }
    }
    map<int, int>::iterator MAX = M.begin();
    for (map<int, int>::iterator it = M.begin(); it != M.end(); it++)
    {
        if (it->second > MAX->second)
        {
            MAX = it;
        }
    }
    cout << MAX->first;
    return 0;
}