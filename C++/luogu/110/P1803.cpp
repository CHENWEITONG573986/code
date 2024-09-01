#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Node
{
public:
    int m_L;
    int m_R;
};
int n;
vector<Node> V;

bool MySort(const Node &A, const Node &B)
{
    return A.m_R < B.m_R;
}
int main()
{
    cin >> n;
    V.resize(n);
    for (int i = 0; i < n; i++)
        cin >> V[i].m_L >> V[i].m_R;
    sort(V.begin(), V.end(), MySort);
    int mark = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (mark <= V[i].m_L)
        {
            count++;
            mark = V[i].m_R;
        }
    }
    cout << count;
    return 0;
}