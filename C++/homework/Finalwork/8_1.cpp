#include <iostream>
using namespace std;
const float PI = 3.14;
class Circle
{
protected:
    float r;

public:
    Circle(){};
    Circle(float r) : r(r){};
};
class Ball : public Circle
{
public:
    Ball(){};
    Ball(float r) : Circle(r){};
    float getArea();
    float getVolume();
    void show();
};
class Cylinder : public Circle
{
private:
    float height;

public:
    Cylinder(){};
    Cylinder(float r, float height) : height(height), Circle(r){};
    float getArea();
    float getVolume();
    void show();
};
class Cone : public Circle
{
private:
    float height;

public:
    Cone(){};
    Cone(float r, float height) : height(height), Circle(r){};
    float getArea();
    float getVolume();
    void show();
};

float Ball::getArea()
{
    return 4 * PI * r * r;
}

float Ball::getVolume()
{
    return 4 / 3 * PI * r * r * r;
}

void Ball::show()
{
    cout << "球表面积：" << getArea() << endl;
    cout << "球体积：" << getVolume() << endl;
}

float Cylinder::getArea()
{
    return 2 * PI * r * r + 2 * PI * r * height;
}

float Cylinder::getVolume()
{
    return PI * r * r * height;
}

void Cylinder::show()
{
    cout << "圆柱表面积：" << getArea() << endl;
    cout << "圆柱体积：" << getVolume() << endl;
}

float Cone::getArea()
{
    return PI * r * r + PI * r * height;
}

float Cone::getVolume()
{
    return PI * r * r * height / 3;
}

void Cone::show()
{
    cout << "圆锥表面积：" << getArea() << endl;
    cout << "圆锥体积：" << getVolume() << endl;
}

int main()
{
    Ball Ba(5);
    Cylinder Cy(5,10);
    Cone Co(5,10);
    Ba.show();
    Cy.show();
    Co.show();
    system("pause");
    return 0;
}