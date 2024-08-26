#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Student
{
public:
    double num;
    double Test_scores;
    double Quality_scores;
    double Overall_scores;
    double Sum_scores;
};

int main()
{
    int N;
    cin >> N;
    Student S[N];
    for (int i = 0; i < N; i++)
    {
        cin >> S[i].num >> S[i].Test_scores >> S[i].Quality_scores;
        S[i].Overall_scores = S[i].Test_scores * 0.7 + S[i].Quality_scores * 0.3;
        S[i].Sum_scores = S[i].Test_scores + S[i].Quality_scores;
        if (S[i].Sum_scores > 140 && S[i].Overall_scores >= 80)
            cout << "Excellent" << endl;
        else
            cout << "Not excellent" << endl;
    }
    return 0;
}