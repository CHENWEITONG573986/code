#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Person
{
public:
    int m_ID;
    string m_Num;
};

class Mysort
{
public:
    bool operator()(const Person &A, const Person &B)
    {
        if (A.m_Num.size() > B.m_Num.size())
            return true;
        else if (A.m_Num.size() == B.m_Num.size())
        {
            for (int i = 0; i < A.m_Num.size(); i++)
                if (A.m_Num[i] > B.m_Num[i])
                    return true;
                else if (A.m_Num[i] < B.m_Num[i])
                    return false;
        }
        else
            return false;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<Person> V;
    V.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> V[i].m_Num;
        V[i].m_ID = i + 1;
    }
    sort(V.begin(), V.end(), Mysort());
    cout << V.front().m_ID << endl;
    cout << V.front().m_Num << endl;
    return 0;
}