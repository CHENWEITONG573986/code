#include <iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int New = 0;
    while (N)
    {
        New = New * 10 + N % 10;
        N /= 10;
    }
    cout << New;
}