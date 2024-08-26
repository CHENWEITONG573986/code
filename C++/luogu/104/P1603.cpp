#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
    string str;
    multimap<int, string> M = {
        {0, "zero"},
        {1, "one"},
        {2, "two"},
        {3, "three"},
        {4, "four"},
        {5, "five"},
        {6, "six"},
        {7, "seven"},
        {8, "eight"},
        {9, "nine"},
        {11, "eleven"},
        {12, "twelve"},
        {13, "thirteen"},
        {14, "fourteen"},
        {15, "fifteen"},
        {16, "sixteen"},
        {17, "seventeen"},
        {18, "eighteen"},
        {19, "nineteen"},
        {20, "twenty"},
        {1, "a"},
        {2, "both"},
        {1, "another"},
        {1, "first"},
        {2, "second"},
        {3, "third"},
    };
    vector<string> V;
    while (cin >> str)
    {
        if (str == ".")
            break;
        for (auto pair : M)
        {
            if (str == pair.second)
            {
                int num = (pair.first * pair.first) % 100;
                if (num >= 10)
                    V.push_back(to_string(num));
                else
                    V.push_back("0" + to_string(num));
            }
        }
    }
    sort(V.begin(), V.end());
    str.clear();
    for (auto c : V)
        str += c;
    if (!str.empty())
    {
        while (str[0] == '0')
            str.erase(str.begin());
        cout << str;
    }
    else
        cout << '0';
    return 0;
}