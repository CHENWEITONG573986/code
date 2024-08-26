#include <iostream>
#include <cmath>
using namespace std;

double Fn(int n)
{
    return (pow((1 + sqrt(5)) / 2, n) - pow((1 - sqrt(5)) / 2, n)) / sqrt(5);
}

int main()
{
    int n;
    cin >> n;
    printf("%.2f",Fn(n));
    return 0;
}