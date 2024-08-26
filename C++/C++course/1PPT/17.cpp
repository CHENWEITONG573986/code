#include <iostream>
using namespace std;
void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
int main()
{
    int i = 3, j = 5;
    swap(i, j);
    cout << i <<","<< j << endl;
    return 0;
}
