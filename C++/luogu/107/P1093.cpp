#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Student
{
public:
    int m_ID;
    int m_Chinese;
    int m_Math;
    int m_English;
    int m_Score;
};

class MySort
{
public:
    bool operator()(const Student &A, const Student &B)
    {
        if (A.m_Score > B.m_Score)
            return true;
        else if (A.m_Score == B.m_Score)
            if (A.m_Chinese > B.m_Chinese)
                return true;
            else if (A.m_Chinese == B.m_Chinese)
                return A.m_ID < B.m_ID;
            else
                return false;
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
        V[i].m_ID = i + 1;
        cin >> V[i].m_Chinese >> V[i].m_Math >> V[i].m_English;
        V[i].m_Score = V[i].m_Chinese + V[i].m_Math + V[i].m_English;
    }
    sort(V.begin(), V.end(), MySort());
    for (int i = 0; i < 5; i++)
        cout << V[i].m_ID << " " << V[i].m_Score << endl;
    return 0;
}