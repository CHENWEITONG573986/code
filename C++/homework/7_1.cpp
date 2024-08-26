#include <iostream>
using namespace std;
static int n = 0;
void fn()
{
    n++;
}
int main()
{
    for (int i = 0; i < 10; i++)
        fn();
    cout << n << endl;
}