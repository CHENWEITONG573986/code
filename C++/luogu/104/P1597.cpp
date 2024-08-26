#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    cin >> str;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i + 1] == ':' && str[i + 2] == '=' && str[i + 4] == ';')
        {
            if (str[i] == 'a')
            {
                if (str[i + 3] == 'a')
                {
                    a = a;
                }
                else if (str[i + 3] == 'b')
                {
                    a = b;
                }
                else if (str[i + 3] == 'c')
                {
                    a = c;
                }
                else
                {
                    a = str[i + 3] - '0';
                }
            }
            if (str[i] == 'b')
            {
                if (str[i + 3] == 'b')
                {
                    b = b;
                }
                else if (str[i + 3] == 'a')
                {
                    b = a;
                }
                else if (str[i + 3] == 'c')
                {
                    b = c;
                }
                else
                {
                    b = str[i + 3] - '0';
                }
            }
            if (str[i] == 'c')
            {
                if (str[i + 3] == 'c')
                {
                    c = c;
                }
                else if (str[i + 3] == 'a')
                {
                    c = a;
                }
                else if (str[i + 3] == 'b')
                {
                    c = b;
                }
                else
                {
                    c = str[i + 3] - '0';
                }
            }
        }
    }
    cout << a << " " << b << " " << c << endl;
    return 0;
}