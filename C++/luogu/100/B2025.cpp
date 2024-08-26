#include<iostream>
#define N 3
using namespace std;
int main()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N-i;j++)
        {
            cout << " ";
        }
        for(int j=0;j<2*(1+i)-1;j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for(int i=N-2;i>=0;i--)
    {
        for(int j=0;j<N-i;j++)
        {
            cout << " ";
        }
        for(int j=0;j<2*(1+i)-1;j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}