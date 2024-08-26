#include <iostream>
#include <vector>
using namespace std;

double getAverage(const vector<int> &V)
{
    double sum = 0;
    for (int c : V)
        sum += c;
    return sum / V.size();
}

int main()
{
    int N;
    cin >> N;
    int chocolate[2][N];
    double sum = 0, average;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> chocolate[i][j];
            sum += chocolate[i][j];
        }
    average = sum / (N * 2);
    int num = 0;
    vector<int> V;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            V.push_back(chocolate[j][i]);
            if (getAverage(V)==average)
                {
                    num++;
                    V.clear();
                }
        }
    }
    cout << num;
    return 0;
}