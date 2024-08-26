#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    vector<int> V, N;
    string a;
    cin >> a;
    for (int j = 0; j < a.size(); j++)
    {
        V.push_back(a[j] - '0');
    }
    for (int i = 1; i < a.size(); i++)
    {
        cin >> a;
        for (int j = 0; j < a.size(); j++)
        {
            V.push_back(a[j] - '0');
        }
    }
    N.push_back(sqrt(V.size()));
    int temp = 0, num = 0;
    for (int i = 0; i < V.size(); i++)
    {
        if (V[i] == temp)
        {
            num++;
            if (i == V.size() - 1)
            {
                N.push_back(num);
            }
        }
        else
        {
            N.push_back(num);
            num = 1;
            if (temp)
                temp = 0;
            else
                temp = 1;
        }
    }
    for (int i = 0; i < N.size(); i++)
    {
        cout << N[i] << " ";
    }
    return 0;
}