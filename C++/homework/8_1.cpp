#include <iostream>
using namespace std;
const float PI = 3.14;
class Circle // 圆
{
protected:
    float R;
};
//***********************************************
class Ball : public Circle // 球
{
public:
    Ball(float R);
    float getArea();
    float getVolume();
    void Show();
};
//***********************************************
class Cylindrical : public Circle // 圆柱
{
private:
    float height;

public:
    Cylindrical(float R, float height);
    float getArea();
    float getVolume();
    void Show();
};
//***********************************************
class Cone : public Circle // 圆锥
{
private:
    float height;

public:
    Cone(float R, float height);
    float getArea();
    float getVolume();
    void Show();
};
//***********************************************
Ball::Ball(float R)
{
    this->R = R;
}
Cylindrical::Cylindrical(float R, float height)
{
    this->R = R;
    this->height = height;
}
Cone::Cone(float R, float height)
{
    this->R = R;
    this->height = height;
}
//***********************************************
float Ball::getArea()
{
    return 4 * PI * R * R;
}
float Ball::getVolume()
{
    return 4 / 3 * PI * R * R * R;
}
void Ball::Show()
{
    cout << "此球体的面积为：" << this->getArea() << endl;
    cout << "此球体的体积为：" << this->getVolume() << endl;
}
//***********************************************
float Cylindrical::getArea()
{
    return 2 * PI * R * height + 2 * PI * R * R;
}
float Cylindrical::getVolume()
{
    return PI * R * R * height;
}
void Cylindrical::Show()
{
    cout << "此圆柱的面积为：" << this->getArea() << endl;
    cout << "此圆柱的体积为：" << this->getVolume() << endl;
}
//***********************************************
float Cone::getArea()
{
    return PI * R * R + PI * R * height;
}
float Cone::getVolume()
{
    return PI * R * R * height / 3;
}
void Cone::Show()
{
    cout << "此圆锥的面积为：" << this->getArea() << endl;
    cout << "此圆锥的体积为：" << this->getVolume() << endl;
}
//***********************************************
int main()
{
    Ball B(5);
    Cylindrical C(6, 6);
    Cone cone(5, 5);
    B.Show();
    C.Show();
    cone.Show();
    return 0;
}