#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int A, B;
    string str, S, SS;
    for (int i = 0; i < n; i++)
    {
        cin >> S;
        if (S == "a")
        {
            cin >> A >> B;
            str = to_string(A) + "+" + to_string(B) + "=" + to_string(A + B);
            cout << str << endl;
            cout << str.size() << endl;
        }
        else if (S == "b")
        {
            cin >> A >> B;
            str = to_string(A) + "-" + to_string(B) + "=" + to_string(A - B);
            cout << str << endl;
            cout << str.size() << endl;
        }
        else if (S == "c")
        {
            cin >> A >> B;
            str = to_string(A) + "*" + to_string(B) + "=" + to_string(A * B);
            cout << str << endl;
            cout << str.size() << endl;
        }
        else
        {
            A = stoi(S);
            cin >> B;
            if (SS == "a")
            {
                str = to_string(A) + "+" + to_string(B) + "=" + to_string(A + B);
                cout << str << endl;
                cout << str.size() << endl;
            }
            else if (SS == "b")
            {
                str = to_string(A) + "-" + to_string(B) + "=" + to_string(A - B);
                cout << str << endl;
                cout << str.size() << endl;
            }
            else if (SS == "c")
            {
                str = to_string(A) + "*" + to_string(B) + "=" + to_string(A * B);
                cout << str << endl;
                cout << str.size() << endl;
            }
            continue;
        }
        SS = S;
    }
    return 0;
}