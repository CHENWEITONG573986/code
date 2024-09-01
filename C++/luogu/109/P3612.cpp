#include <iostream>
#include <string>
using namespace std;
long long N;
string S;

int main()
{
    cin >> S >> N;
    long long len = S.size();
    while (len < N)
        len *= 2;
    while (len != S.size() && N > S.size())
    {
        len /= 2;
        if (N < len)
            continue;
        N = N - len - 1;
        if (N == 0)
            N = len;
    }
    cout << S[N - 1];
    return 0;
}