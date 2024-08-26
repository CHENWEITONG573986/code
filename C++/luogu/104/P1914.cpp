#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    string password;
    cin >> n >> password;
    for (int i = 0; i < password.size(); i++)
    {
        int x = password[i] - 'a';
        x += n;
        x %= 26;
        password[i] = 'a' + x;
    }
    cout << password;
    return 0;
}