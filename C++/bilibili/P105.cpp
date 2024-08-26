#include <iostream>
using namespace std;

class Point
{
public:
    void setPoint(int x, int y)
    {
        X = x;
        Y = y;
    }
    int getX()
    {
        return X;
    }
    int getY()
    {
        return Y;
    }

private:
    int X;
    int Y;
};

class Circle
{
public:
    void setR(int r)
    {
        R = r;
    }
    int getR()
    {
        return R;
    }
    void setCenter(Point c)
    {
        Center = c;
    }
    Point getCenter()
    {
        return Center;
    }

private:
    int R;
    Point Center;
};

void Judgment(Circle c, Point p)
{
    int x1, x2, y1, y2, r;
    Point C = c.getCenter();
    x1 = C.getX();
    y1 = C.getY();
    x2 = p.getX();
    y2 = p.getY();
    r = c.getR();
    if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) == r * r)
        cout << "点在圆上" << endl;
    if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) < r * r)
        cout << "点在圆内" << endl;
    if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) > r * r)
        cout << "点在园外" << endl;
}
int main()
{
    Circle c1;
    Point p1, Center;
    Center.setPoint(5, 5);
    c1.setCenter(Center);
    c1.setR(5);
    p1.setPoint(7, 7);
    Judgment(c1, p1);
    return 0;
}