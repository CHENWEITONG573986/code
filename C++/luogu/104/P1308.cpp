#include <iostream>
#include <string>
#include <cctype>    // 包含tolower函数
#include <algorithm> // 包含transform函数
using namespace std;
int main()
{
    string sub, str;
    getline(cin, sub);
    getline(cin, str);
    // 全部转化为小写字母
    transform(sub.begin(), sub.end(), sub.begin(), ::tolower);
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    int pos = -1, count = 0;
    string temp;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != ' ')
        {
            temp.push_back(str[i]);
        }
        else
        {
            if (temp == sub)
            {
                count++;
                if (pos == -1)
                    pos = i - sub.size();
            }
            temp.clear();
        }
    }
    if (count)
    {
        cout << count << " " << pos << endl;
    }
    else
    {
        cout << pos << endl;
    }
    return 0;
}