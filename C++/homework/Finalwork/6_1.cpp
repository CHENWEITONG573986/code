#include <iostream>
using namespace std;
const float PI = 3.14;
class Circle
{
private:
    int r;

public:
    Circle(){};
    Circle(int r) : r(r){};
    float getArea();
    float getCircumference();
    ~Circle(){};
};

float Circle::getArea()
{
    return PI*r*r;
}

float Circle::getCircumference()
{
    return 2*PI*r;
}
int main()
{
    Circle C(1);
    cout << C.getArea() << endl;
    cout << C.getCircumference() << endl;
    system("pause");
    return 0;
}