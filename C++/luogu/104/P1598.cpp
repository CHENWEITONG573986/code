#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;
int main()
{
    map<char, int> count;
    for (int i = 0; i < 4; i++)
    {
        string str;
        getline(cin, str);
        for (char c : str)
        {
            if (c >= 'A' && c <= 'Z')
                count[c]++;
        }
    }
    set<int> num;
    for (auto pair : count)
        num.insert(pair.second);
    for (int i = *num.rbegin(); i >= 1; i--)
    {
        for (char j = 'A'; j <= 'Z'; j++)
        {
            if (count[j] >= i)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
    for (char i = 'A'; i <= 'Z'; i++)
        cout << i << " ";
    return 0;
}