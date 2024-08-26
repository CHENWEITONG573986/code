#include <iostream>
#include <string>
using namespace std;
int main()
{
    int q;
    string str;
    cin >> q >> str;
    for (int i = 0; i < q; i++)
    {
        int num, pos, n;
        string S;
        cin >> num;
        switch (num)
        {
        case 1:
            cin >> S;
            str += S;
            cout << str << endl;
            break;
        case 2:
            cin >> pos >> n;
            str = str.substr(pos, n);
            cout << str << endl;
            break;
        case 3:
            cin >> pos >> S;
            str.insert(pos, S);
            cout << str << endl;
            break;
        case 4:
            cin >> S;
            pos = str.find(S);
            cout << pos << endl;
        }
    }
    return 0;
}