#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    float t;
    int n;
    cin >> t >> n;
    cout << fixed << setprecision(3) << t/n << endl;//保留3位小数
    cout << n*2 << endl;
    return 0;
}