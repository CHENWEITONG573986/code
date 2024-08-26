#include <iostream>
#include <cmath>
using namespace std;

typedef struct Point
{
    double x;
    double y;
} Point;

double getdis(Point A, Point B)
{
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

int main()
{
    Point A, B, C;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
    double perimeter;
    perimeter = getdis(A, B) + getdis(B, C) + getdis(A, C);
    printf("%.2f",perimeter);
    return 0;
}