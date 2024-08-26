#include <iostream>
#include <math.h>
using namespace std;

class Point
{
private:
    float x;
    float y;

public:
    Point(){};
    Point(float x, float y) : x(x), y(y){};
    float Distance(const Point &p);
    friend float Distance(const Point &P1, const Point &P2);
    ~Point(){};
};
float Point::Distance(const Point &p)
{
    return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
}
float Distance(const Point &P1, const Point &P2)
{
    return sqrt((P1.x - P2.x) * (P1.x - P2.x) + (P1.y - P2.y) * (P1.y - P2.y));
}
int main()
{
    Point P1(4, 7), P2(9, 10);
    cout << P1.Distance(P2) << endl;
    cout << Distance(P1, P2) << endl;
    system("pause");
    return 0;
}