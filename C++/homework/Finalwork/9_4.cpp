#include <iostream>
using namespace std;
const float PI = 3.14;
class SolidFigure
{
public:
    virtual float getSuperficialArea() = 0;
    virtual float getVolume() = 0;
    virtual void getshoeAll() = 0;
};
class Cuboid : public SolidFigure
{
private:
    float width;
    float length;
    float height;

public:
    Cuboid(){};
    Cuboid(float width, float length, float height)
        : width(width), length(length), height(height){};
    float getSuperficialArea() override;
    float getVolume() override;
    void getshoeAll() override;
};
class Sphere : public SolidFigure
{
private:
    float radius;

public:
    Sphere(){};
    Sphere(float radius) : radius(radius){};
    float getSuperficialArea() override;
    float getVolume() override;
    void getshoeAll() override;
};
class Cylinder : public SolidFigure
{
private:
    float radius;
    float high;

public:
    Cylinder(){};
    Cylinder(float radius, float high) : radius(radius), high(high){};
    float getSuperficialArea() override;
    float getVolume() override;
    void getshoeAll() override;
};
float Cuboid::getSuperficialArea()
{
    return 2 * length * width + 2 * length * height + 2 * width * height;
}
float Cuboid::getVolume()
{
    return length * width * height;
}
void Cuboid::getshoeAll()
{
    cout << "长方体表面积：" << getSuperficialArea() << endl;
    cout << "长方体体积：" << getVolume() << endl;
}
float Sphere::getSuperficialArea()
{
    return 4 * PI * radius * radius;
}
float Sphere::getVolume()
{
    return 4 / 3 * PI * radius * radius * radius;
}
void Sphere::getshoeAll()
{
    cout << "球体表面积：" << getSuperficialArea() << endl;
    cout << "球体体积：" << getVolume() << endl;
}
float Cylinder::getSuperficialArea()
{
    return 2*PI*radius*radius+2*PI*radius*high;
}
float Cylinder::getVolume()
{
    return PI*radius*radius*high;
}
void Cylinder::getshoeAll()
{
    cout << "圆柱体表面积：" << getSuperficialArea() << endl;
    cout << "圆柱体体积：" << getVolume() << endl;
}
int main()
{
    SolidFigure *S[3];
    S[0]=new Cuboid(10,10,10);
    S[1]=new Sphere(10);
    S[2]=new Cylinder(10,10);
    S[0]->getshoeAll();
    S[1]->getshoeAll();
    S[2]->getshoeAll();
    system("pause");
    return 0;
}