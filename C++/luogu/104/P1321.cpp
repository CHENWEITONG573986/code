#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    string str;
    cin >> str;
    int numboy = 0, numgirl = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'b' || str[i + 1] == 'o' || str[i + 2] == 'y')
            numboy++;
        if (str[i] == 'g' || str[i + 1] == 'i' || str[i + 2] == 'r' || str[i+3] == 'l')
            numgirl++;
    }
    cout << numboy << endl;
    cout << numgirl << endl;
    return 0;
}