#include<iostream>
using namespace std;
int main()
{
    int a,i,j;
    for(i=1;i<10;i++)
    {
        for(j=1;j<=i;j++)
        {
            cout << j << "x" << i << "=" << i*j <<" ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}