#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

vector<int> HPM(vector<int> V1, vector<int> V2)
{
    vector<int> Mul;
    Mul.resize(V1.size() + V2.size());
    int A = min((int)V1.size(), 500);
    int B = min((int)V2.size(), 500);
    for (int i = 0; i < A; i++)
    {
        for (int j = 0; j < B; j++)
        {
            Mul[i + j] += V1[i] * V2[j];
            Mul[i + j + 1] += Mul[i + j] / 10;
            Mul[i + j] %= 10;
        }
    }
    while (!Mul.back() && Mul.size() > 1)
        Mul.pop_back();
    return Mul;
}

vector<int> MySen(int P)
{
    vector<int> a;
    a.push_back(2);
    vector<int> result;
    result.push_back(1);
    while (P != 0)
    {
        if (P % 2 == 1)
        {
            result = HPM(result, a);
        }
        a = HPM(a, a);
        P /= 2;
    }
    reverse(result.begin(), result.end());
    result.back()--;
    return result;
}

int getNum(int P)
{
    return log10(2) * P + 1;
}

int main()
{
    int P;
    cin >> P;
    int num = getNum(P);
    cout << num << endl;
    if (num < 500)
    {
        vector<int> V = MySen(P);
        int count = 0;
        for (int i = V.size(); i < 500; i++)
        {
            cout << "0";
            count++;
            if (count % 50 == 0)
                cout << endl;
        }
        for (int c : V)
        {
            cout << c;
            count++;
            if (count % 50 == 0)
                cout << endl;
        }
    }
    else
    {
        int count = 0;
        vector<int> V = MySen(P);
        while (V.size() > 500)
            V.erase(V.begin());
        for (int c : V)
        {
            cout << c;
            count++;
            if (count % 50 == 0)
                cout << endl;
        }
    }
    return 0;
}