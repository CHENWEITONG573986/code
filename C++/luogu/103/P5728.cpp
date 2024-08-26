#include <iostream>
#include <vector>
using namespace std;
class Student
{
public:
    int Chinese;
    int Math;
    int English;
    int Sum;
};
int main()
{
    int N, num = 0;
    cin >> N;
    vector<Student> V;
    V.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> V[i].Chinese >> V[i].Math >> V[i].English;
        V[i].Sum = V[i].Chinese + V[i].Math + V[i].English;
    }
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (V[i].Chinese - V[j].Chinese <= 5 && V[i].Chinese - V[j].Chinese >= -5)
                if (V[i].Math - V[j].Math <= 5 && V[i].Math - V[j].Math >= -5)
                    if (V[i].English - V[j].English <= 5 && V[i].English - V[j].English >= -5)
                        if (V[i].Sum - V[j].Sum <= 10 && V[i].Sum - V[j].Sum >= -10)
                        {
                            num++;
                        }
        }
    }
    cout << num;
    return 0;
}