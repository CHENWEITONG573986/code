#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    string num1 = "adgjmptw ";
    string num2 = "behknqux";
    string num3 = "cfilorvy";
    string num4 = "sz";
    int sum = 0;
    for (char c : str)
    {
        if (num1.find(c)!=string::npos)
        {
            sum++;
        }
        else if (num2.find(c) != string::npos)
        {
            sum += 2;
        }
        else if (num3.find(c) != string::npos)
        {
            sum += 3;
        }
        else if (num4.find(c) != string::npos)
        {
            sum += 4;
        }
    }
    cout << sum;
    return 0;
}