#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string S, rS;
    cin >> S;
    string A, B;
    string::iterator pos = S.end();
    for (string::iterator it = S.begin(); it != S.end(); it++)
    {
        if (*it < '0' || *it > '9')
        {
            pos = it;
            break;
        }
    }
    A.assign(S.begin(), pos);
    for (string::reverse_iterator it = A.rbegin(); it != A.rend(); it++)
    {
        if (*it == '0' && A.size() != 1)
            A.pop_back();
        else
            break;
    }
    reverse(A.begin(), A.end());
    if (pos != S.end())
    {
        B.assign(pos + 1, S.end());
        for (string::reverse_iterator it = B.rbegin(); it != B.rend(); it++)
        {
            if (*it == '0' && B.size() != 1)
                B.pop_back();
            else
                break;
        }
        reverse(B.begin(), B.end());
        for (string::reverse_iterator it = B.rbegin(); it != B.rend(); it++)
        {
            if (*it == '0' && B.size() != 1)
                B.pop_back();
            else
                break;
        }
    }
    rS = A + *pos + B;
    cout << rS;
    return 0;
}