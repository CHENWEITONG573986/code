#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Person
{
public:
    int m_Num;
    double m_Time;
    double m_Wait;
};
vector<Person> V;
int n;

bool MySort(const Person &A, const Person &B)
{
    return A.m_Time < B.m_Time;
}

int main()
{
    cin >> n;
    V.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> V[i].m_Time;
        V[i].m_Num = i + 1;
    }
    sort(V.begin(), V.end(), MySort);
    double Time;
    for (int i = 0; i < n; i++)
    {
        cout << V[i].m_Num << " ";
        if (i > 0)
            V[i].m_Wait = V[i - 1].m_Wait + V[i - 1].m_Time;
        else
            V[i].m_Wait = 0;
        Time += V[i].m_Wait;
    }
    cout << endl;
    Time /= n;
    printf("%.2f", Time);
    return 0;
}