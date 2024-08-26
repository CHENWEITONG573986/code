#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    int n;
    string S;
    cin >> n >> S;
    int pos = 0, count = 0;
    while ((pos = S.find("VK", pos)) != string::npos)
    {
        count++;
        pos += 2;
    }
    for (int i = 0; i < n; i++)
    {
        string temp = S;
        int count2 = 0;
        pos = 0;
        temp[i] = temp[i] == 'V' ? 'K' : 'V';
        while ((pos = temp.find("VK", pos)) != string::npos)
        {
            count2++;
            pos += 2;
        }
        count = max(count2, count);
    }
    cout << count;
    return 0;
}