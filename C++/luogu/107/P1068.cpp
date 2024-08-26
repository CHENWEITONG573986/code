#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Person
{
public:
    int m_ID;
    int m_Score;
};

class MySort
{
public:
    bool operator()(const Person &A, const Person &B)
    {
        if (A.m_Score > B.m_Score)
            return true;
        else if (A.m_Score == B.m_Score)
            return A.m_ID < B.m_ID;
        else
            return false;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<Person> V;
    V.resize(n);
    for (int i = 0; i < n; i++)
        cin >> V[i].m_ID >> V[i].m_Score;
    sort(V.begin(), V.end(), MySort());
    int num = 1.5 * m;
    int count = 0;
    for (int i = num; i < n; i++)
    {
        if (V[i].m_Score == V[num - 1].m_Score)
            count++;
        else
            break;
    }
    num += count;
    cout << V[num - 1].m_Score << " " << num << endl;
    for (int i = 0; i < num; i++)
        cout << V[i].m_ID << " " << V[i].m_Score << endl;
    return 0;
}