#include <iostream>
#include <cmath>
#include <string>
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
    int max = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> S[i].Name >> S[i].Chinese >> S[i].Math >> S[i].English;
        S[i].Sum = S[i].Chinese + S[i].Math + S[i].English;
        if (S[i].Sum > S[max].Sum)
            max = i;
    }
    cout << S[max].Name << " " << S[max].Chinese << " " << S[max].Math << " " << S[max].English;
    return 0;
}