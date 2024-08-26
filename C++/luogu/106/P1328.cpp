#include <iostream>
using namespace std;
int matrix[5][5] = {
    {0, -1, 1, 1, -1},
    {1, 0, -1, 1, -1},
    {-1, 1, 0, -1, 1},
    {-1, -1, 1, 0, 1},
    {1, 1, -1, -1, 0}};

int main()
{
    int N, NA, NB;
    cin >> N >> NA >> NB;
    int A[NA], B[NB];
    for (int i = 0; i < NA; i++)
        cin >> A[i];
    for (int i = 0; i < NB; i++)
        cin >> B[i];
    int ScoreA = 0, ScoreB = 0;
    for (int i = 0; i < N; i++)
    {
        if (matrix[A[i % NA]][B[i % NB]] == 1)
            ScoreA++;
        else if (matrix[A[i % NA]][B[i % NB]] == -1)
            ScoreB++;
    }
    cout << ScoreA << " " << ScoreB;
    return 0;
}