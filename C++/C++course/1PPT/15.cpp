#include <iostream>
using namespace std;
void swap(int *p1, int *p2)
{
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
int main()
{
    int i = 3, j = 5;
    swap(&i, &j);
    cout << i << "," << j << endl;
    return 0;
}
