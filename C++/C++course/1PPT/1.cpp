#include <iostream>
using namespace std;
#define PI 3.1415926
class Circle
{
private:
    double point_x, point_y, radius;

public:
    Circle(double initial_x = 0.0, double initial_y = 0.0, double initial_r = 1.0)
    {
        point_x = initial_x;
        point_y = initial_y;
        radius = initial_r;
    }
    ~Circle() {}
    double Getarea()
    {
        return (PI * radius * radius);
    }
    double Getperimeter()
    {
        return (2 * PI * radius);
    }
};
int main()
{
    Circle myCircle = Circle(0, 0, 10);
    cout << "面积=" << myCircle.Getarea() << endl;
    cout << "周长=" << myCircle.Getperimeter() << endl;
    return 0;
}
