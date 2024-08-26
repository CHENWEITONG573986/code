#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double s,v,t;
    int h,m;
    cin >> s >> v;
    t=ceil(s/v)+10;
    t=24*60+8*60-(int)t;
    h=t/60;
    m=t-h*60;
    if(h>23)
    {
        if(m<10)
            cout << "0" << h-24 << ":" << "0" << m;
        else
            cout << "0" << h-24 << ":" << m;
    }
    if(9<h&&h<24)
    {
        if(m<10)
            cout << h << ":" << "0" << m;
        else
            cout << h << ":" << m;
    }
    if(h<10)
    {
        if(m<10)
            cout << "0" << h << ":" << "0" << m;
        else
            cout << "0" << h << ":" << m;
    }
    return 0;
}