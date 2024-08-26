#include <iostream>
using namespace std;
class Point
{
    friend ostream &operator<<(ostream &cout, Point p);

private:
    int x;
    int y;

public:
    Point(){};
    Point(int x, int y) : x(x), y(y){};
    Point operator++();
    Point operator++(int);
    Point operator--();
    Point operator--(int);
};
ostream &operator<<(ostream &cout, Point p)
{
    cout << "x=" << p.x << endl;
    cout << "y=" << p.y << endl;
    return cout;
}
Point Point::operator++()
{
    x++;
    y++;
    return *this;
}
Point Point::operator++(int)
{
    Point temp = *this;
    x++;
    y++;
    return temp;
}
Point Point::operator--()
{
    x--;
    y--;
    return *this;
}
Point Point::operator--(int)
{
    Point temp = *this;
    x--;
    y--;
    return temp;
}
int main()
{
    Point P(1, 1);
    cout<<P++<<endl;
    cout<<++P<<endl;
    cout<<P--<<endl;
    cout<<--P<<endl;
    system("pause");
    return 0;
}