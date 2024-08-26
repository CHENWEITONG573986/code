#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    int p1, p2, p3;
    string str;
    cin >> p1 >> p2 >> p3 >> str;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '-' && i != 0 && i != str.size() - 1)
        {
            if (str[i - 1] >= str[i + 1])
            {
                cout << "-";
            }
            else if (str[i - 1] == '-' || str[i + 1] == '-')
            {
                cout << "-";
            }
            else if (isdigit(str[i - 1]) && isalpha(str[i + 1]))
            {
                cout << "-";
            }
            else if (str[i - 1] + 1 < str[i + 1])
            {
                if (p3 == 1)
                {
                    for (char j = str[i - 1] + 1; j < str[i + 1]; j++)
                        for (int k = 0; k < p2; k++)
                        {
                            if (p1 == 1)                  // 小写
                                cout << (char)tolower(j); // 大写转小写
                            else if (p1 == 2)             // 大写
                                cout << (char)toupper(j); // 小写转大写
                            else if (p1 == 3)
                                cout << "*";
                        }
                }
                else
                {
                    for (char j = str[i + 1] - 1; j > str[i - 1]; j--)
                        for (int k = 0; k < p2; k++)
                        {
                            if (p1 == 1)                  // 小写
                                cout << (char)tolower(j); // 大写转小写
                            else if (p1 == 2)             // 大写
                                cout << (char)toupper(j); // 小写转大写
                            else if (p1 == 3)
                                cout << "*";
                        }
                }
            }
        }
        else
            cout << str[i];
    }
}