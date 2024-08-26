#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s1, s2, s3, temp;
    cin >> s1 >> s2 >> s3;
    if (s2 > s3)
    {
        temp = s2;
        s2 = s3;
        s3 = temp;
    }
    if (s1 > s2)
    {
        temp = s1;
        s1 = s2;
        s2 = temp;
    }
    if (s2 > s3)
    {
        temp = s2;
        s2 = s3;
        s3 = temp;
    }
    cout << s1 << "->" << s2 << "->" << s3 << endl;
    return 0;
}
