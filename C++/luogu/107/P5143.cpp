#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Point
{
public:
    int m_X;
    int m_Y;
    int m_Z;
};

double getDistance(const Point &A, const Point &B)
{
    return sqrt(pow(A.m_X - B.m_X, 2) + pow(A.m_Y - B.m_Y, 2) + pow(A.m_Z - B.m_Z, 2));
}

class MySort
{
public:
    bool operator()(const Point &A, const Point &B)
    {
        return A.m_Z < B.m_Z;
    }
};

int main()
{
    int N;
    cin >> N;
    vector<Point> V;
    V.resize(N);
    for (int i = 0; i < N; i++)
        cin >> V[i].m_X >> V[i].m_Y >> V[i].m_Z;
    sort(V.begin(), V.end(), MySort());
    double sum = 0;
    for (int i = 1; i < N; i++)
        sum += getDistance(V[i], V[i - 1]);
    printf("%.3f", sum);
    return 0;
}