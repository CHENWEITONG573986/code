#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Student
{
public:
    string name;
    int age;
    int score;
};

int main()
{
    int n;
    cin >> n;
    Student S[n];
    for (int i = 0; i < n; i++)
    {
        cin >> S[i].name >> S[i].age >> S[i].score;
        S[i].age++;
        S[i].score = (S[i].score * 1.2 <= 600) ? (S[i].score * 1.2) : 600;
        cout << S[i].name << " " << S[i].age << " " << S[i].score << endl;
    }
    return 0;
}