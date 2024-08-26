#include <iostream>
using namespace std;
class Point
{
    friend ostream &operator<<(ostream &cout, Point &p);
    friend istream &operator>>(istream &cin, Point &P);

private:
    int x;
    int y;

public:
    Point(){};
    Point(int x, int y) : x(x), y(y){};
};
ostream &operator<<(ostream &cout, Point &p)
{
    cout << "x=" << p.x << endl;
    cout << "y=" << p.y << endl;
    return cout;
}
istream &operator>>(istream &cin, Point &P)
{
    cin >> P.x >> P.y;
    return cin;
}

int main()
{
    Point P;
    cin >> P;
    cout << P << endl;
    system("pause");
    return 0;
}