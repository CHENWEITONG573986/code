#include <iostream>
#include <string>
using namespace std;
string S;
int n;

int main()
{
    cin >> n;
    int a = n;
    for (int i = 0; i < n; i++)
        S.push_back('o');
    for (int i = 0; i < n; i++)
        S.push_back('*');
    S += "--";
    cout << S << endl;
    while (n > 3)
    {
        S[2 * n + 1] = S[n];
        S[2 * n] = S[n - 1];
        S[n] = '-';
        S[n - 1] = '-';
        cout << S << endl;
        if (n == 4)
            break;
        S[n] = S[2 * n - 1];
        S[n - 1] = S[2 * n - 2];
        S[2 * n - 1] = '-';
        S[2 * n - 2] = '-';
        cout << S << endl;
        n--;
    }
    cout << "ooo*o**--*";
    for (int i = 0; i < a - 4; i++)
        cout << "o*";
    cout << endl;
    cout << "o--*o**oo*";
    for (int i = 0; i < a - 4; i++)
        cout << "o*";
    cout << endl;
    cout << "o*o*o*--o*";
    for (int i = 0; i < a - 4; i++)
        cout << "o*";
    cout << endl;
    cout << "--o*o*o*o*";
    for (int i = 0; i < a - 4; i++)
        cout << "o*";
    cout << endl;
    return 0;
}