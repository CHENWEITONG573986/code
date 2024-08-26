#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Student
{
public:
    string Name;
    int Chinese;
    int Math;
    int English;
    int Sum;
};

int main()
{
    int N;
    cin >> N;
    Student S[N];
    for (int i = 0; i < N; i++)
    {
        cin >> S[i].Name >> S[i].Chinese >> S[i].Math >> S[i].English;
        S[i].Sum = S[i].Chinese + S[i].Math + S[i].English;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (S[i].Chinese - S[j].Chinese <= 5 && S[i].Chinese - S[j].Chinese >= -5 &&
                S[i].Math - S[j].Math <= 5 && S[i].Math - S[j].Math >= -5 &&
                S[i].English - S[j].English <= 5 && S[i].English - S[j].English >= -5 &&
                S[i].Sum - S[j].Sum <= 10 && S[i].Sum - S[j].Sum >= -10)
            {
                cout << S[i].Name << " " << S[j].Name << endl;
            }
        }
    }
    return 0;
}