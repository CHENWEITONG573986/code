#include <iostream>
using namespace std;
int max(int a, int b, int c)
{
    if (b > a)
        a = b;
    if (c > a)
        a = c;
    return a;
}

float max(float a, float b)
{
    if (b > a)
        a = b;
    return a;
}

long max(long a, long b, long c)
{
    if (b > a)
        a = b;
    if (c > a)
        a = c;
    return a;
}
int main()
{
    int a, b, c, d;
    float x, y, z;
    long m, n, p, q;
    cin >> a >> b >> c;
    cin >> x >> y;
    cin >> m >> n >> p;
    d = max(a, b, c);
    cout <<"int_d = "<< d << endl;
    z = max(x, y);
    cout <<"float_z = "<< z << endl;
    q = max(m, n, p);
    cout <<"long_q = "<< q << endl;
    return 0;
}
