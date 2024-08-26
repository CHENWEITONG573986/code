#include <iostream>
using namespace std;
const float PI = 3.14;
class Circle
{
private:
    int R;

public:
    Circle()
    {
    }
    Circle(int R)
    {
        this->R = R;
    }
    ~Circle()
    {
    }
    float FindArea();
    float FindPerimeter();
};
float Circle::FindArea()
{
    return R * R * PI;
}
float Circle::FindPerimeter()
{
    return 2*R*PI;
}
int main()
{
    Circle C1(5);
    cout<<"面积："<<C1.FindArea()<<endl;
    cout<<"周长："<<C1.FindPerimeter()<<endl;
    system("pause");
    return 0;
}