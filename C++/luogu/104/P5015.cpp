#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    int size = 0;
    getline(cin, str);
    for (auto c : str)
    {
        if (c != ' ')
        {
            size++;
        }
    }
    cout << size;
}