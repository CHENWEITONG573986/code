#include<iostream>
using namespace std;
int main()
{
    int x,n,H=0;
    cin >> x >> n;
    for(int i=0;i<n;i++)
    {
        if(x!=6&&x!=7)
            H+=250;
        if(x==7)
            x=1;
        else
            x++;
    }
    cout << H << endl;
    return 0;
}