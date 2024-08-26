#include<iostream>
using namespace std;
int main()
{
    int a,i;
    for(i=1;i<=100;i++)
    {
        if((i%10==7)||(i/10==7)||(i%7==0))
            cout << "敲桌子" << endl;
        else
            cout << i << endl;
    }
    system("pause");
    return 0;
}