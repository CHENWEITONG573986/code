#include <iostream>
#include <string>
using namespace std;
class Month
{
public:
    int a;
    char *p[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    void Translated();
};
void Month::Translated()
{
    int month;
    cout << "请输入数字月份" << endl;
    cin >> month;
    if (month > 0 && month < 13)
    {
        cout << "该月份的英文如下" << endl;
        cout << p[month - 1] << endl;
    }
    else
        cout << "输入月份不合法" << endl;
}
int main()
{
    Month m;
    m.Translated();
    system("pause");
    return 0;
}