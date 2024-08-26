#include <iostream>
using namespace std;
class Car;
class Boat
{
private:
    float weight;

public:
    Boat(){};
    Boat(float weight) : weight(weight){};
    friend float getTotalWeight(Boat &B, Car &C);
};

class Car
{
private:
    float weight;

public:
    Car(float weight) : weight(weight){};
    friend float getTotalWeight(Boat &B, Car &C);
};

float getTotalWeight(Boat &B, Car &C)
{
    return B.weight + C.weight;
}

int main()
{
    Boat B(239.34);
    Car C(29.34);
    cout << getTotalWeight(B, C) << endl;
    system("pause");
    return 0;
}