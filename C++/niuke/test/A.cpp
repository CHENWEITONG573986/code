#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string str;
    cin >> str;
    int num = count(str.begin(), str.end(), 'o');
    cout << num << endl;
    return 0;
}