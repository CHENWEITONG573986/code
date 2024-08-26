#include <iostream>
using namespace std;
inline int isnumber(char);
int main()
{
    char c;
    while (cin >> c && c != '\n')
    {
        if (isnumber(c))
            cout << "you entered a digit\n";
        else
            cout << "you entered a non-digit\n";
    }
    return 0;
}
int isnumber(char ch) // inline int isnumber(char ch)
{
    return (ch >= '0' && ch <= '9') ? 1 : 0;
}
