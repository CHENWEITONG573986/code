#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Bag
{
public:
    double m_Weight;
    double m_Value;
    double m_Price;
};
int N, T;
vector<Bag> V;

bool MySort(const Bag &A, const Bag &B)
{
    return A.m_Price > B.m_Price;
}

int main()
{
    cin >> N >> T;
    V.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> V[i].m_Weight >> V[i].m_Value;
        V[i].m_Price = V[i].m_Value / V[i].m_Weight;
    }
    sort(V.begin(), V.end(), MySort);
    double TotalValue = 0;
    int pos = 0;
    while (T && pos < N)
    {
        if (V[pos].m_Weight <= T)
        {
            TotalValue += V[pos].m_Value;
            T -= V[pos].m_Weight;
        }
        else
        {
            TotalValue += T * V[pos].m_Price;
            T = 0;
        }
        pos++;
    }
    printf("%.2f", TotalValue);
    return 0;
}