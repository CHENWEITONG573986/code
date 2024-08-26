#include <iostream>
using namespace std;
int main()
{
    int H[7][2], t = 0,A[7],L=0;
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 2; j++)
            cin >> H[i][j];
    for (int i = 0; i < 7; i++)
        A[i]=H[i][0]+H[i][1];
    for(int i=0;i<7;i++)
    {
        if(A[L]<A[i]&&A[i]>8)
        {
            L=i;
            t=(i+1);
        }
    }
    cout << t << endl;
    return 0;
}