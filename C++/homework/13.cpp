#include <iostream>
using namespace std;
class Cuboid
{
private:
    int length;
    int width;
    int height;

public:
    Cuboid() {}
    Cuboid(float length, float width, float height)
    {
        this->length = length;
        this->width = width;
        this->height = height;
    }
    ~Cuboid() {}
    void setlength(float length);
    void setwidth(float width);
    void setheight(float height);
    float FindVolume();   // 体积
    float FindArea();     // 面积
    bool Same(Cuboid &C); // 判断两个长方体是否相同
};
void Cuboid::setlength(float length)
{
    this->length = length;
}
void Cuboid::setwidth(float width)
{
    this->width = width;
}
void Cuboid::setheight(float height)
{
    this->height = height;
}
float Cuboid::FindVolume()
{
    return length * width * height;
}
float Cuboid::FindArea()
{
    return length * width * 2 + length * height * 2 + width * height * 2;
}
bool Cuboid::Same(Cuboid &C)
{
    if (length == C.length && width == C.width && height == C.height)
        return true;
    else
        return false;
}
int main()
{
    Cuboid C1(4, 8, 9), C2;
    C2.setlength(3);
    C2.setwidth(7);
    C2.setheight(6);
    cout << "C1的面积：" << C1.FindArea() << endl;
    cout << "C1的体积：" << C1.FindVolume() << endl;
    cout << "C2的面积：" << C2.FindArea() << endl;
    cout << "C2的体积：" << C2.FindVolume() << endl;
    cout << "C1与C2";
    if (C1.Same(C2))
        cout << "相同" << endl;
    else
        cout << "不相同" << endl;
    system("pause");
    return 0;
}