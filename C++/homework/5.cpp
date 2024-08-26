#include <iostream>
using namespace std;
class str
{
public:
    char a;
    int zm = 0;
    int sz = 0;
    int kg = 0;
    int qt = 0;
    void Recording();
};
void str::Recording()
{
    while (true)
    {
        a=getchar();
        if (a == '#')
            break;
        else if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
            zm++;
        else if (a >= '0' && a <= '9')
            sz++;
        else if (a == ' ')
            kg++;
        else
            qt++;
    }
    cout << "字母：" << zm << endl;
    cout << "数字：" << sz << endl;
    cout << "空格：" << kg << endl;
    cout << "其他：" << qt << endl;
}
int main()
{
    str s;
    s.Recording();
    system("pause");
    return 0;
}