#include<iostream>
using namespace std;
int main()
{
    float n,N;
    cin >> n;
    int a,b,c,d;
    a=(int)(n*10)/1000;
    b=(int)(n*10)/100%10;
    c=(int)(n*10)/10%10;
    d=(int)(n*10)%10;
    N=d*100+c*10+b+(float)a/10;
    cout << N << endl;
    return 0;
}