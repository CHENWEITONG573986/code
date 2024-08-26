#include <iostream>
using namespace std;
class number
{
public:
    int count(int x);
};
int number::count(int x)
{
    int a = 0;
    while (x != 0)
    {
        a += x % 10;
        x = x / 10;
    }
    return a;
}
int main()
{
    number n;
    int x;
    cout << "请输入整数" << endl;
    cin >> x;
    cout << n.count(x) << endl;
    system("pause");
    return 0;
}