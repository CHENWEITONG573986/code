#include <iostream>
using namespace std;
const int N = 3;
class Fraction
{
private:
    int numerator;   // 分子
    int denominator; // 分母
public:
    Fraction(){};
    Fraction(int numerator, int denominator)
        : numerator(numerator), denominator(denominator) { Approximation(); };
    void Approximation();
    void show();
    ~Fraction(){};
};
// 排序
void Sort(int abc[])
{
    int max, temp;
    for (int i = 0; i < N - 1; i++)
    {
        max = i;
        for (int j = i + 1; j < N; j++)
        {
            if (abc[max] < abc[j])
            {
                max = j;
            }
        }
        temp = abc[i];
        abc[i] = abc[max];
        abc[max] = temp;
    }
}
// 求最大共因数
int FindMaxFactor(int a, int b)
{
    int temp;
    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
// 约分
void Fraction::Approximation()
{
    int factor = FindMaxFactor(numerator, denominator);
    numerator = numerator / factor;
    denominator = denominator / factor;
}
// 输出
void Fraction::show()
{
    cout << numerator << "/" << denominator << endl;
}
int main()
{
    // 输入
    int abc[N];
    cin >> abc[0] >> abc[1] >> abc[2];
    // 将abc从大到小排序
    Sort(abc);
    // 求正弦值
    Fraction sin(abc[2], abc[0]);
    // 输出结果
    sin.show();
    return 0;
}