#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int h,r;
    double t;
    cin >> h >> r;
    t=ceil(20000/(3.14*r*r*h));
    cout << t << endl;
    return 0;
}