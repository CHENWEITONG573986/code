#include <iostream>
using namespace std;
const int N = 6;
class str
{
public:
    int a[N] = {1, 10, 100, 1000, 10000};//原始排序
    void Add(int A);
};
void str::Add(int A)
{
    if (a[0] < a[1])
    {
        for (int i = 0; i < N - 2; i++)
        {
            if (A < a[i])
            {
                for (int j = N - 1; j > i; j--)
                {
                    a[j] = a[j - 1];
                }
                a[i] = A;
                break;
            }
            if (A >= a[N - 2])
            {
                a[N - 1] = A;
                break;
            }
        }
    }
    if (a[0] > a[1])
    {
        for (int i = 0; i < N - 2; i++)
        {
            if (A > a[i])
            {
                for (int j = N - 1; j > i; j--)
                {
                    a[j] = a[j - 1];
                }
                a[i] = A;
                break;
            }
            if (A <= a[N - 2])
            {
                a[N - 1] = A;
                break;
            }
        }
    }
}
int main()
{
    str s;
    int A;
    cout << "请输入要插入的数字" << endl;
    cin >> A;
    s.Add(A);
    for (int i = 0; i < N; i++)
        cout << s.a[i] << " ";
    system("pause");
    return 0;
}