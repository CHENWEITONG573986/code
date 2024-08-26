#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Student
{
public:
    string m_Name;
    int m_Year;
    int m_Month;
    int m_Day;
    int m_Num;
};

class MySort
{
public:
    bool operator()(const Student &A, const Student &B)
    {
        if (A.m_Year < B.m_Year)
            return true;
        else if (A.m_Year == B.m_Year)
        {
            if (A.m_Month < B.m_Month)
                return true;
            else if (A.m_Month == B.m_Month)
            {
                if (A.m_Day < B.m_Day)
                    return true;
                else if (A.m_Day == B.m_Day)
                    return A.m_Num > B.m_Num;
                else
                    return false;
            }
            else
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
    vector<Student> V;
    V.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> V[i].m_Name >> V[i].m_Year >> V[i].m_Month >> V[i].m_Day;
        V[i].m_Num = i;
    }
    sort(V.begin(), V.end(), MySort());
    for (auto c : V)
        cout << c.m_Name << endl;
    return 0;
}