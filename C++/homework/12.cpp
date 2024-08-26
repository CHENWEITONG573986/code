#include <iostream>
#include <math.h>
using namespace std;
class Point
{
private:
    int x;
    int y;

public:
    Point()
    {
    }
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    ~Point()
    {
    }
    float Distance(Point &p);
};
float Point::Distance(Point &p)
{
    return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
}
int main()
{
    Point P1(4,5),P2(2,9);
    cout<<P1.Distance(P2)<<endl;
    system("pause");
    return 0;
}