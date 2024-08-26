#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            cout << char(str[i] - 32);
        }
        else
        {
            cout << str[i];
        }
    }
    return 0;
}